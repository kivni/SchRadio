#ifndef MAINWINDOWSCHOOLRADIO_H
#define MAINWINDOWSCHOOLRADIO_H

#include <QMainWindow>
#include <QProcess>
#include <QAudioRecorder>
#include <QUrl>
#include <QFile>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>
#include <QThread>
#include <QTimer>

bool ProcessStart(const QString &Command, QString *pResult, int msecs);

class WorkerThread : public QThread
{
    Q_OBJECT

    void run() override;

public:
    void ProcessStart(const QString &Command, int msecs);

private:
    QString m_Command;
    int m_msecs;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowSchoolRadio; }
QT_END_NAMESPACE

class MainWindowSchoolRadio : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowSchoolRadio(QWidget *parent = nullptr);
    ~MainWindowSchoolRadio();

private:
    Ui::MainWindowSchoolRadio *m_ui;

    int m_intModuleNullSink = -1;
    int m_intModuleRtpSend = -1;
    int m_intModuleLoopback = -1;
    QAudioRecorder *m_pAudioRecorder = nullptr;
    WorkerThread *m_pWorkerThread = nullptr;
    QTimer *m_pTimer = nullptr;

    bool LoadModule(const QString &module, int *num);
    void UnloadModule(int num);
    bool TranslationOn();
    void TranslationOff();
    bool MicrophoneOn();
    void MicrophoneOff();
    bool RecordingOn();
    void RecordingOff();
    void ProcessStartAsync(const QString &Command, int msecs);

private slots:
    void updateTime();
    void on_DurationChanged(qint64 duration);
    void on_pushButtonRecording_clicked();
    void on_horizontalSliderRecording_valueChanged(int value);
    void on_pushButtonPlay_clicked();
    void on_pushButtonPlayList_clicked();
    void on_pushButtonTranslation_clicked();
    void on_checkBoxMicrophone_stateChanged(int arg1);
};
#endif // MAINWINDOWSCHOOLRADIO_H
