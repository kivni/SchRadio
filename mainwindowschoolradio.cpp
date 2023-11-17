#include "mainwindowschoolradio.h"
#include "ui_mainwindowschoolradio.h"


// Global

const QString c_SchRadioFile = "02-объявление.wav";

bool ProcessStart(const QString &Command, QString *pResult, int msecs)
{
    qDebug() << "ProcessStart(const QString &Command, QString *pResult)";
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

bool LoadModule(const QString &Module, int *pNum)
{
    qDebug() << "LoadModule(const QString &Module, int *pNum)";

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

void UnloadModule(int Num)
{
    qDebug() << "UnloadModule(int Num)";

    QString Result;

    ProcessStart("pactl unload-module " + QString::number(Num), &Result, 3000);
}


// ProcessStartThread

void ProcessStartThread::ProcessStart(const QString &Command, int msecs)
{
    qDebug() << "WorkerThread::ProcessStart(const QString &Command, int msecs)";
    qDebug() << "Command = " << Command;

    m_Command = Command;
    m_msecs = msecs;

    start();
}

void ProcessStartThread::run()
{
    qDebug() << "WorkerThread::run()";

    ::ProcessStart(m_Command, nullptr, m_msecs);
}


// MainWindowSchoolRadio

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
    move(configIniWrite.value("pos", QPoint(200, 200)).toPoint());
    m_ui->horizontalSliderRecording->setValue(configIniWrite.value("horizontalSliderRecording", 25).toInt());
    m_ui->lineEditDir->setText(configIniWrite.value("lineEditDir", "").toString());

    m_ui->TextLabelRecordingDuration->setText("");
    on_horizontalSliderRecording_valueChanged(m_ui->horizontalSliderRecording->value());

    if (GetRecordingDir() == "")
    {
        on_toolButtonDir_clicked();
    }
}

MainWindowSchoolRadio::~MainWindowSchoolRadio()
{
    TranslationOff();
    RecordingOff();

    QSettings configIniWrite("SchoolRadio.ini", QSettings::IniFormat);
    configIniWrite.setValue("pos", pos());
    configIniWrite.setValue("horizontalSliderRecording", m_ui->horizontalSliderRecording->value());
    configIniWrite.setValue("lineEditDir", GetRecordingDir());

    if (m_pAudioRecorder != nullptr)
    {
        delete m_pAudioRecorder;

        m_pAudioRecorder = nullptr;
    }

    if (m_pTimer != nullptr)
    {
        delete m_pTimer;

        m_pTimer = nullptr;
    }

    if (m_pWorkerThread != nullptr)
    {
        if (m_pWorkerThread->isRunning())
        {
            m_pWorkerThread->terminate();
            m_pWorkerThread->wait();
        }

        delete  m_pWorkerThread;
        m_pWorkerThread = nullptr;
    }

    delete m_ui;
}

QString MainWindowSchoolRadio::GetRecordingDir()
{
    return m_ui->lineEditDir->text();
}

QString MainWindowSchoolRadio::GetRecordingFileName()
{
    return GetRecordingDir() + "/" + c_SchRadioFile;
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

void MainWindowSchoolRadio::WidgetEnabled(bool b)
{
    for(auto *widget : this->findChildren<QWidget *>())
    {
        widget->setEnabled(b);
    }
}

void MainWindowSchoolRadio::ProcessStartAsync(const QString &Command, int msecs)
{
    qDebug() << "MainWindowSchoolRadio::ProcessStartAsync(const QString &Command, int msecs)";

    QObjectList widgetList = children();

    if (m_pWorkerThread == nullptr)
    {
        m_pWorkerThread = new ProcessStartThread();
    }

    m_pWorkerThread->ProcessStart(Command, msecs);

    if (m_pTimer == nullptr)
    {
        m_pTimer = new QTimer(this);

        connect(m_pTimer, &QTimer::timeout, this, &MainWindowSchoolRadio::updateTime);
    }

    m_pTimer->start(300);
}

void MainWindowSchoolRadio::updateTime()
{
    qDebug() << "MainWindowSchoolRadio::updateTime()";

    if (m_pWorkerThread != nullptr && !m_pWorkerThread->isRunning())
    {
        m_pTimer->stop();

        WidgetEnabled(true);
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
            m_ui->pushButtonPlayDir->setEnabled(false);
        }
    }
    else
    {
        RecordingOff();

        m_ui->pushButtonRecording->setStyleSheet(QString("background-color: ") + QString::number(QWidget::palette().color(QWidget::backgroundRole()).value()));
        m_ui->pushButtonRecording->setText("Записать объявление");

        m_ui->horizontalSliderRecording->setEnabled(true);
        m_ui->pushButtonTranslation->setEnabled(true);
        m_ui->pushButtonPlay->setEnabled(true);
        m_ui->pushButtonPlayDir->setEnabled(true);
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

    if (!QFile::exists(GetRecordingFileName()))
    {
        QMessageBox::warning(this, "Внимание", "Нет файла объявления:\n" + GetRecordingFileName());

        return;
    }

    WidgetEnabled(false);

    ProcessStartAsync(QString("vlc --play-and-exit \"") + GetRecordingFileName() + "\"", -1);
}

void MainWindowSchoolRadio::on_pushButtonPlayDir_clicked()
{
    qDebug() << "MainWindowSchoolRadio::on_pushButtonPlayList_clicked()";

    if(QDir(GetRecordingDir()).entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count() == 0)
    {
        QMessageBox::warning(this, "Внимание", "Нет файлов в папке:\n" + GetRecordingDir());

        return;
    }

    WidgetEnabled(false);

    ProcessStartAsync(QString("vlc ") + "--play-and-exit \"" + GetRecordingDir() + "\"", -1);
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

void MainWindowSchoolRadio::on_toolButtonDir_clicked()
{
    QString filename= QFileDialog::getExistingDirectory(this, "Выберете папку с аудиофайлами");

    if (filename == "")
    {
        filename = QDir::currentPath();
    }

    m_ui->lineEditDir->setText(filename);
}
