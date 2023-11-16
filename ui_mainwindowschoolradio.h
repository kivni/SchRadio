/********************************************************************************
** Form generated from reading UI file 'mainwindowschoolradio.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWSCHOOLRADIO_H
#define UI_MAINWINDOWSCHOOLRADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowSchoolRadio
{
public:
    QWidget *centralwidget;
    QFrame *frameTranslattion;
    QCheckBox *checkBoxMicrophone;
    QPushButton *pushButtonTranslation;
    QFrame *frameRecording;
    QPushButton *pushButtonRecording;
    QLabel *label;
    QLabel *TextLabelRecordingLevel;
    QLabel *TextLabelRecording;
    QSlider *horizontalSliderRecording;
    QLabel *TextLabelRecordingDuration;
    QFrame *frameListen;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonPlayList;
    QLineEdit *lineEditDir;
    QLabel *labelAudio;
    QToolButton *toolButtonDir;

    void setupUi(QMainWindow *MainWindowSchoolRadio)
    {
        if (MainWindowSchoolRadio->objectName().isEmpty())
            MainWindowSchoolRadio->setObjectName(QStringLiteral("MainWindowSchoolRadio"));
        MainWindowSchoolRadio->resize(640, 670);
        MainWindowSchoolRadio->setMinimumSize(QSize(640, 670));
        centralwidget = new QWidget(MainWindowSchoolRadio);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frameTranslattion = new QFrame(centralwidget);
        frameTranslattion->setObjectName(QStringLiteral("frameTranslattion"));
        frameTranslattion->setGeometry(QRect(10, 470, 621, 180));
        frameTranslattion->setFrameShape(QFrame::Panel);
        frameTranslattion->setFrameShadow(QFrame::Sunken);
        checkBoxMicrophone = new QCheckBox(frameTranslattion);
        checkBoxMicrophone->setObjectName(QStringLiteral("checkBoxMicrophone"));
        checkBoxMicrophone->setEnabled(false);
        checkBoxMicrophone->setGeometry(QRect(20, 140, 251, 30));
        QFont font;
        font.setPointSize(10);
        checkBoxMicrophone->setFont(font);
        pushButtonTranslation = new QPushButton(frameTranslattion);
        pushButtonTranslation->setObjectName(QStringLiteral("pushButtonTranslation"));
        pushButtonTranslation->setGeometry(QRect(20, 30, 581, 100));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        pushButtonTranslation->setFont(font1);
        pushButtonTranslation->setFocusPolicy(Qt::NoFocus);
        pushButtonTranslation->setCheckable(true);
        frameRecording = new QFrame(centralwidget);
        frameRecording->setObjectName(QStringLiteral("frameRecording"));
        frameRecording->setGeometry(QRect(10, 80, 621, 211));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        frameRecording->setFont(font2);
        frameRecording->setAutoFillBackground(false);
        frameRecording->setFrameShape(QFrame::Panel);
        frameRecording->setFrameShadow(QFrame::Sunken);
        pushButtonRecording = new QPushButton(frameRecording);
        pushButtonRecording->setObjectName(QStringLiteral("pushButtonRecording"));
        pushButtonRecording->setGeometry(QRect(20, 20, 581, 100));
        pushButtonRecording->setFont(font1);
        pushButtonRecording->setFocusPolicy(Qt::NoFocus);
        pushButtonRecording->setAutoFillBackground(false);
        pushButtonRecording->setCheckable(true);
        pushButtonRecording->setFlat(false);
        label = new QLabel(frameRecording);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 140, 171, 20));
        TextLabelRecordingLevel = new QLabel(frameRecording);
        TextLabelRecordingLevel->setObjectName(QStringLiteral("TextLabelRecordingLevel"));
        TextLabelRecordingLevel->setGeometry(QRect(540, 140, 51, 20));
        TextLabelRecording = new QLabel(frameRecording);
        TextLabelRecording->setObjectName(QStringLiteral("TextLabelRecording"));
        TextLabelRecording->setGeometry(QRect(40, 170, 141, 20));
        horizontalSliderRecording = new QSlider(frameRecording);
        horizontalSliderRecording->setObjectName(QStringLiteral("horizontalSliderRecording"));
        horizontalSliderRecording->setGeometry(QRect(190, 142, 341, 20));
        horizontalSliderRecording->setMaximum(100);
        horizontalSliderRecording->setValue(0);
        horizontalSliderRecording->setOrientation(Qt::Horizontal);
        TextLabelRecordingDuration = new QLabel(frameRecording);
        TextLabelRecordingDuration->setObjectName(QStringLiteral("TextLabelRecordingDuration"));
        TextLabelRecordingDuration->setGeometry(QRect(190, 170, 101, 20));
        frameListen = new QFrame(centralwidget);
        frameListen->setObjectName(QStringLiteral("frameListen"));
        frameListen->setGeometry(QRect(10, 310, 621, 141));
        frameListen->setFrameShape(QFrame::Panel);
        frameListen->setFrameShadow(QFrame::Sunken);
        pushButtonPlay = new QPushButton(frameListen);
        pushButtonPlay->setObjectName(QStringLiteral("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(20, 20, 221, 101));
        pushButtonPlay->setFont(font1);
        pushButtonPlay->setFocusPolicy(Qt::NoFocus);
        pushButtonPlayList = new QPushButton(frameListen);
        pushButtonPlayList->setObjectName(QStringLiteral("pushButtonPlayList"));
        pushButtonPlayList->setGeometry(QRect(260, 20, 341, 101));
        pushButtonPlayList->setFont(font1);
        pushButtonPlayList->setFocusPolicy(Qt::NoFocus);
        lineEditDir = new QLineEdit(centralwidget);
        lineEditDir->setObjectName(QStringLiteral("lineEditDir"));
        lineEditDir->setGeometry(QRect(92, 20, 481, 40));
        lineEditDir->setReadOnly(true);
        labelAudio = new QLabel(centralwidget);
        labelAudio->setObjectName(QStringLiteral("labelAudio"));
        labelAudio->setGeometry(QRect(20, 20, 71, 40));
        toolButtonDir = new QToolButton(centralwidget);
        toolButtonDir->setObjectName(QStringLiteral("toolButtonDir"));
        toolButtonDir->setGeometry(QRect(580, 20, 41, 42));
        MainWindowSchoolRadio->setCentralWidget(centralwidget);

        retranslateUi(MainWindowSchoolRadio);

        QMetaObject::connectSlotsByName(MainWindowSchoolRadio);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowSchoolRadio)
    {
        MainWindowSchoolRadio->setWindowTitle(QApplication::translate("MainWindowSchoolRadio", "\320\250\320\272\320\276\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\320\264\320\270\320\276", nullptr));
        checkBoxMicrophone->setText(QApplication::translate("MainWindowSchoolRadio", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\274\320\270\320\272\321\200\320\276\321\204\320\276\320\275", nullptr));
        pushButtonTranslation->setText(QApplication::translate("MainWindowSchoolRadio", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\202\321\200\320\260\320\275\321\201\320\273\321\217\321\206\320\270\321\216", nullptr));
        pushButtonRecording->setText(QApplication::translate("MainWindowSchoolRadio", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        label->setText(QApplication::translate("MainWindowSchoolRadio", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\267\320\260\320\277\320\270\321\201\320\270:", nullptr));
        TextLabelRecordingLevel->setText(QApplication::translate("MainWindowSchoolRadio", "100%", nullptr));
        TextLabelRecording->setText(QApplication::translate("MainWindowSchoolRadio", "\320\222\321\200\320\265\320\274\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:", nullptr));
        TextLabelRecordingDuration->setText(QApplication::translate("MainWindowSchoolRadio", "123", nullptr));
        pushButtonPlay->setText(QApplication::translate("MainWindowSchoolRadio", "\320\237\321\200\320\276\321\201\320\273\321\203\321\210\320\260\321\202\321\214\n"
"\320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButtonPlayList->setText(QApplication::translate("MainWindowSchoolRadio", "\320\237\321\200\320\276\321\201\320\273\321\203\321\210\320\260\321\202\321\214\n"
"\321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        labelAudio->setText(QApplication::translate("MainWindowSchoolRadio", "\320\237\320\260\320\277\320\272\320\260:", nullptr));
        toolButtonDir->setText(QApplication::translate("MainWindowSchoolRadio", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowSchoolRadio: public Ui_MainWindowSchoolRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWSCHOOLRADIO_H
