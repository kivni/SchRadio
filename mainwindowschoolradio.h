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

    bool ProcessStart(const QString &Command, QString *pResult, int msecs);
    bool LoadModule(const QString &module, int *num);
    void UnloadModule(int num);
    bool TranslationOn();
    void TranslationOff();
    bool MicrophoneOn();
    void MicrophoneOff();
    bool RecordingOn();
    void RecordingOff();
    void gui_update();

private slots:
    void on_DurationChanged(qint64 duration);
    void on_pushButtonRecording_clicked();
    void on_horizontalSliderRecording_valueChanged(int value);
    void on_pushButtonPlay_clicked();
    void on_pushButtonPlayList_clicked();
    void on_pushButtonTranslation_clicked();
    void on_checkBoxMicrophone_stateChanged(int arg1);
};
#endif // MAINWINDOWSCHOOLRADIO_H
