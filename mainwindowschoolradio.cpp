#include "mainwindowschoolradio.h"
#include "ui_mainwindowschoolradio.h"

const QString c_SchRadioFolder = "//home/sa/Desktop/SchoolRadio/";
const QString c_SchRadioFile = "02-объявление.wav";

QString GetRecordingFileName()
{
    return c_SchRadioFolder + c_SchRadioFile;
}


MainWindowSchoolRadio::MainWindowSchoolRadio(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindowSchoolRadio)
{
    qDebug() << "MainWindowSchoolRadio::MainWindowSchoolRadio(QWidget *parent)";

    m_ui->setupUi(this);

    QWidget* pMainWindowWidget = (QWidget*) this;
    pMainWindowWidget ->setMaximumSize(pMainWindowWidget ->minimumSize());
    pMainWindowWidget->setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint);

    QSettings configIniWrite("SchoolRadio.ini", QSettings::IniFormat);
    m_ui->horizontalSliderRecording->setValue(configIniWrite.value("horizontalSliderRecording", 25).toInt());

    m_ui->TextLabelRecordingDuration->setText("");
    on_horizontalSliderRecording_valueChanged(m_ui->horizontalSliderRecording->value());
}

MainWindowSchoolRadio::~MainWindowSchoolRadio()
{
    TranslationOff();

    RecordingOff();

    if (m_pAudioRecorder != nullptr)
    {
        delete m_pAudioRecorder;

        m_pAudioRecorder = nullptr;
    }

    QSettings configIniWrite("SchoolRadio.ini", QSettings::IniFormat);
    configIniWrite.setValue("horizontalSliderRecording", m_ui->horizontalSliderRecording->value());

    delete m_ui;
}

bool MainWindowSchoolRadio::ProcessStart(const QString &Command, QString *pResult, int msecs)
{
    qDebug() << "MainWindowSchoolRadio::ProcessStart(const QString &Command, QString *pResult)";
    qDebug() << "Command = " << Command;

    QProcess Process;

    Process.start(Command);

    if (Process.waitForFinished(msecs))
    {
        QString Result = Process.readAllStandardOutput();

        if (Result.length() > 0)
        {
            Result = Result.trimmed();

            if (pResult != nullptr)
            {
                *pResult = Result;

                qDebug() << "Result = " << Result;
            }
        }

        return true;
    }

    return false;
}

bool MainWindowSchoolRadio::LoadModule(const QString &Module, int *pNum)
{
    qDebug() << "MainWindowSchoolRadio::LoadModule(const QString &Module, int *pNum)";

    QString Result;

    if (ProcessStart("pactl load-module " + Module, &Result, 3000))
    {
        QRegExp re("\\d*");

        if (pNum != nullptr && re.exactMatch(Result))
        {
            *pNum = Result.toInt();

            return true;
        }
    }

    return false;
}

void MainWindowSchoolRadio::UnloadModule(int Num)
{
    qDebug() << "MainWindowSchoolRadio::UnloadModule(int Num)";

    QString Result;

    ProcessStart("pactl unload-module " + QString::number(Num), &Result, 3000);
}

bool MainWindowSchoolRadio::TranslationOn()
{
    qDebug() << "MainWindowSchoolRadio::TranslationOn()";

    return
        LoadModule(QString("module-null-sink sink_name=rtp sink_properties=\"device.description='SchoolRadio'\""), &m_intModuleNullSink) &&
        LoadModule(QString("module-rtp-send source=rtp.monitor"), &m_intModuleRtpSend);
}

void MainWindowSchoolRadio::TranslationOff()
{
    qDebug() << "MainWindowSchoolRadio::TranslationOff()";

    MicrophoneOff();

    if (m_intModuleRtpSend > 0)
    {
        UnloadModule(m_intModuleRtpSend);

        m_intModuleRtpSend = -1;
    }

    if (m_intModuleNullSink > 0)
    {
        UnloadModule(m_intModuleNullSink);

        m_intModuleNullSink = -1;
    }
}

bool MainWindowSchoolRadio::MicrophoneOn()
{
    qDebug() << "MainWindowSchoolRadio::MicrophoneOn()";

    return
        LoadModule(QString("module-loopback"), &m_intModuleLoopback);
}

void MainWindowSchoolRadio::MicrophoneOff()
{
    qDebug() << "MainWindowSchoolRadio::MicrophoneOff()";

    if (m_intModuleLoopback > 0)
    {
        UnloadModule(m_intModuleLoopback);

        m_intModuleLoopback = -1;
    }
}

bool MainWindowSchoolRadio::RecordingOn()
{
    qDebug() << "MainWindowSchoolRadio::RecordingOn()";

    if (QFile::exists(GetRecordingFileName()) && !QFile::remove(GetRecordingFileName()))
    {
        QMessageBox msgBox;
        msgBox.setText(QString("Невозможно удалить файл: ") + GetRecordingFileName());
        msgBox.setInformativeText("Попробуйте закрыть все приложения и удалить файл вручную.");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setDefaultButton(QMessageBox::Close);
        msgBox.exec();

        return false;
    }

    if (m_pAudioRecorder == nullptr)
    {
        m_pAudioRecorder = new QAudioRecorder();

        connect(m_pAudioRecorder,&QAudioRecorder::durationChanged, this, &MainWindowSchoolRadio::on_DurationChanged);

        QAudioEncoderSettings AudioEncoderSettings;

        AudioEncoderSettings.setQuality(QMultimedia::NormalQuality);
        AudioEncoderSettings.setSampleRate(44100);
        AudioEncoderSettings.setChannelCount(2);

        m_pAudioRecorder->setAudioSettings(AudioEncoderSettings);
        m_pAudioRecorder->setContainerFormat("audio/x-wav");

        m_pAudioRecorder->setAudioInput(m_pAudioRecorder->defaultAudioInput());
        m_pAudioRecorder->setOutputLocation(QUrl::fromLocalFile(GetRecordingFileName()));
    }

    ProcessStart("pactl set-source-volume @DEFAULT_SOURCE@ " + QString::number((65536 / 100) * m_ui->horizontalSliderRecording->value()), nullptr, 100);

    m_pAudioRecorder->record();

    return true;
}

void MainWindowSchoolRadio::RecordingOff()
{
    qDebug() << "MainWindowSchoolRadio::RecordingOff()";

    if (m_pAudioRecorder != nullptr)
    {
        m_pAudioRecorder->stop();
    }
}

void MainWindowSchoolRadio::on_DurationChanged(qint64 duration)
{
    qDebug() << "MainWindowSchoolRadio::on_DurationChanged(qint64 duration)";

    if(m_pAudioRecorder->error() == QMediaRecorder::NoError && duration > 1000)
    {
        m_ui->TextLabelRecordingDuration->setText(tr("%1сек.").arg(duration / 1000));
    }
}

void MainWindowSchoolRadio::on_pushButtonRecording_clicked()
{
    qDebug() << "MainWindowSchoolRadio::on_pushButtonRecording_clicked()";

    if (m_ui->pushButtonRecording->isChecked())
    {
        if (RecordingOn())
        {
            m_ui->pushButtonRecording->setStyleSheet("background-color: rgba(255, 0, 0, 128)");
            m_ui->pushButtonRecording->setText("Выключить запись");

            m_ui->horizontalSliderRecording->setEnabled(false);
            m_ui->pushButtonTranslation->setEnabled(false);
            m_ui->pushButtonPlay->setEnabled(false);
            m_ui->pushButtonPlayList->setEnabled(false);
        }
    }
    else
    {
        RecordingOff();

        m_ui->pushButtonRecording->setStyleSheet(QString("background-color: ") + QString::number(QWidget::palette().color(QWidget::backgroundRole()).value()));
        m_ui->pushButtonRecording->setText("Включить запись");

        m_ui->horizontalSliderRecording->setEnabled(true);
        m_ui->pushButtonTranslation->setEnabled(true);
        m_ui->pushButtonPlay->setEnabled(true);
        m_ui->pushButtonPlayList->setEnabled(true);
    }
}

void MainWindowSchoolRadio::on_horizontalSliderRecording_valueChanged(int value)
{
    qDebug() << "MainWindowSchoolRadio::on_horizontalSliderRecording_valueChanged(int value)";

    m_ui->TextLabelRecordingLevel->setText(QString::number(value) + "%");
}

void MainWindowSchoolRadio::on_pushButtonPlay_clicked()
{
    qDebug() << "MainWindowSchoolRadio::on_pushButtonPlay_clicked()";

    ProcessStart(QString("vlc --play-and-exit ") + GetRecordingFileName(), nullptr, -1);
}

void MainWindowSchoolRadio::on_pushButtonPlayList_clicked()
{
    qDebug() << "MainWindowSchoolRadio::on_pushButtonPlayList_clicked()";

    ProcessStart(QString("vlc ") + "--play-and-exit " + c_SchRadioFolder + "SchoolRadio.xspf", nullptr, -1);
}

void MainWindowSchoolRadio::on_pushButtonTranslation_clicked()
{
    qDebug() << "MainWindowSchoolRadio::on_pushButtonTranslation_clicked()";

    if (m_ui->pushButtonTranslation->isChecked())
    {
        if (TranslationOn())
        {
            m_ui->pushButtonTranslation->setStyleSheet("background-color: rgba(0, 255, 0, 128)");
            m_ui->pushButtonTranslation->setText("Выключить трансляцию");

            m_ui->pushButtonRecording->setEnabled(false);
            m_ui->checkBoxMicrophone->setEnabled(true);
        }
    }
    else
    {
        TranslationOff();

        m_ui->pushButtonTranslation->setStyleSheet(QString("background-color: ") + QString::number(QWidget::palette().color(QWidget::backgroundRole()).value()));
        m_ui->pushButtonTranslation->setText("Включить трансляцию");

        m_ui->pushButtonRecording->setEnabled(true);
        m_ui->checkBoxMicrophone->setEnabled(false);
        m_ui->checkBoxMicrophone->setChecked(false);
    }
}

void MainWindowSchoolRadio::on_checkBoxMicrophone_stateChanged(int arg1)
{
    qDebug() << "MainWindowSchoolRadio::on_checkBoxMicrophone_stateChanged(int arg1)";

    if (arg1 == Qt::Checked)
    {
        MicrophoneOn();
    }
    else
    {
        MicrophoneOff();
    }
}
