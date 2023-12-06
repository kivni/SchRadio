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
    QPushButton *pushButtonPlayDir;
    QLineEdit *lineEditDir;
    QLabel *labelAudio;
    QToolButton *toolButtonDir;

    void setupUi(QMainWindow *MainWindowSchoolRadio)
    {
        if (MainWindowSchoolRadio->objectName().isEmpty())
            MainWindowSchoolRadio->setObjectName(QStringLiteral("MainWindowSchoolRadio"));
        MainWindowSchoolRadio->resize(481, 453);
        MainWindowSchoolRadio->setMinimumSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindowSchoolRadio);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frameTranslattion = new QFrame(centralwidget);
        frameTranslattion->setObjectName(QStringLiteral("frameTranslattion"));
        frameTranslattion->setGeometry(QRect(10, 320, 461, 121));
        QFont font;
        font.setPointSize(10);
        frameTranslattion->setFont(font);
        frameTranslattion->setFrameShape(QFrame::Panel);
        frameTranslattion->setFrameShadow(QFrame::Sunken);
        checkBoxMicrophone = new QCheckBox(frameTranslattion);
        checkBoxMicrophone->setObjectName(QStringLiteral("checkBoxMicrophone"));
        checkBoxMicrophone->setEnabled(true);
        checkBoxMicrophone->setGeometry(QRect(10, 80, 231, 30));
        checkBoxMicrophone->setFont(font);
        pushButtonTranslation = new QPushButton(frameTranslattion);
        pushButtonTranslation->setObjectName(QStringLiteral("pushButtonTranslation"));
        pushButtonTranslation->setGeometry(QRect(10, 10, 441, 61));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButtonTranslation->setFont(font1);
        pushButtonTranslation->setCheckable(true);
        frameRecording = new QFrame(centralwidget);
        frameRecording->setObjectName(QStringLiteral("frameRecording"));
        frameRecording->setGeometry(QRect(10, 70, 461, 151));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        frameRecording->setFont(font2);
        frameRecording->setAutoFillBackground(false);
        frameRecording->setFrameShape(QFrame::Panel);
        frameRecording->setFrameShadow(QFrame::Sunken);
        pushButtonRecording = new QPushButton(frameRecording);
        pushButtonRecording->setObjectName(QStringLiteral("pushButtonRecording"));
        pushButtonRecording->setGeometry(QRect(10, 40, 441, 61));
        pushButtonRecording->setFont(font1);
        pushButtonRecording->setAutoFillBackground(false);
        pushButtonRecording->setCheckable(true);
        pushButtonRecording->setFlat(false);
        label = new QLabel(frameRecording);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 171, 21));
        label->setFont(font);
        TextLabelRecordingLevel = new QLabel(frameRecording);
        TextLabelRecordingLevel->setObjectName(QStringLiteral("TextLabelRecordingLevel"));
        TextLabelRecordingLevel->setGeometry(QRect(400, 10, 51, 20));
        TextLabelRecordingLevel->setFont(font);
        TextLabelRecording = new QLabel(frameRecording);
        TextLabelRecording->setObjectName(QStringLiteral("TextLabelRecording"));
        TextLabelRecording->setGeometry(QRect(10, 120, 141, 20));
        TextLabelRecording->setFont(font);
        horizontalSliderRecording = new QSlider(frameRecording);
        horizontalSliderRecording->setObjectName(QStringLiteral("horizontalSliderRecording"));
        horizontalSliderRecording->setGeometry(QRect(180, 11, 211, 20));
        horizontalSliderRecording->setFont(font);
        horizontalSliderRecording->setMaximum(100);
        horizontalSliderRecording->setValue(0);
        horizontalSliderRecording->setOrientation(Qt::Horizontal);
        TextLabelRecordingDuration = new QLabel(frameRecording);
        TextLabelRecordingDuration->setObjectName(QStringLiteral("TextLabelRecordingDuration"));
        TextLabelRecordingDuration->setGeometry(QRect(160, 120, 101, 20));
        TextLabelRecordingDuration->setFont(font);
        frameListen = new QFrame(centralwidget);
        frameListen->setObjectName(QStringLiteral("frameListen"));
        frameListen->setGeometry(QRect(10, 230, 461, 81));
        frameListen->setFont(font);
        frameListen->setFrameShape(QFrame::Panel);
        frameListen->setFrameShadow(QFrame::Sunken);
        pushButtonPlay = new QPushButton(frameListen);
        pushButtonPlay->setObjectName(QStringLiteral("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(10, 10, 161, 61));
        pushButtonPlay->setFont(font1);
        pushButtonPlayDir = new QPushButton(frameListen);
        pushButtonPlayDir->setObjectName(QStringLiteral("pushButtonPlayDir"));
        pushButtonPlayDir->setGeometry(QRect(180, 10, 271, 61));
        pushButtonPlayDir->setFont(font1);
        lineEditDir = new QLineEdit(centralwidget);
        lineEditDir->setObjectName(QStringLiteral("lineEditDir"));
        lineEditDir->setGeometry(QRect(92, 10, 321, 40));
        lineEditDir->setFont(font);
        lineEditDir->setAcceptDrops(false);
        lineEditDir->setReadOnly(true);
        labelAudio = new QLabel(centralwidget);
        labelAudio->setObjectName(QStringLiteral("labelAudio"));
        labelAudio->setGeometry(QRect(20, 10, 71, 40));
        labelAudio->setFont(font);
        toolButtonDir = new QToolButton(centralwidget);
        toolButtonDir->setObjectName(QStringLiteral("toolButtonDir"));
        toolButtonDir->setGeometry(QRect(420, 10, 41, 42));
        toolButtonDir->setFont(font);
        toolButtonDir->setFocusPolicy(Qt::StrongFocus);
        MainWindowSchoolRadio->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEditDir, toolButtonDir);
        QWidget::setTabOrder(toolButtonDir, horizontalSliderRecording);
        QWidget::setTabOrder(horizontalSliderRecording, pushButtonRecording);
        QWidget::setTabOrder(pushButtonRecording, pushButtonPlay);
        QWidget::setTabOrder(pushButtonPlay, pushButtonPlayDir);
        QWidget::setTabOrder(pushButtonPlayDir, pushButtonTranslation);
        QWidget::setTabOrder(pushButtonTranslation, checkBoxMicrophone);

        retranslateUi(MainWindowSchoolRadio);

        QMetaObject::connectSlotsByName(MainWindowSchoolRadio);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowSchoolRadio)
    {
        MainWindowSchoolRadio->setWindowTitle(QApplication::translate("MainWindowSchoolRadio", "\320\250\320\272\320\276\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\320\264\320\270\320\276", nullptr));
        checkBoxMicrophone->setText(QApplication::translate("MainWindowSchoolRadio", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\274\320\270\320\272\321\200\320\276\321\204\320\276\320\275", nullptr));
        pushButtonTranslation->setText(QApplication::translate("MainWindowSchoolRadio", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\202\321\200\320\260\320\275\321\201\320\273\321\217\321\206\320\270\321\216", nullptr));
        pushButtonRecording->setText(QApplication::translate("MainWindowSchoolRadio", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QApplication::translate("MainWindowSchoolRadio", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\267\320\260\320\277\320\270\321\201\320\270:", nullptr));
        TextLabelRecordingLevel->setText(QApplication::translate("MainWindowSchoolRadio", "100%", nullptr));
        TextLabelRecording->setText(QApplication::translate("MainWindowSchoolRadio", "\320\222\321\200\320\265\320\274\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:", nullptr));
        TextLabelRecordingDuration->setText(QApplication::translate("MainWindowSchoolRadio", "123", nullptr));
        pushButtonPlay->setText(QApplication::translate("MainWindowSchoolRadio", "\320\237\321\200\320\276\321\201\320\273\321\203\321\210\320\260\321\202\321\214\n"
"\320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButtonPlayDir->setText(QApplication::translate("MainWindowSchoolRadio", "\320\237\321\200\320\276\321\201\320\273\321\203\321\210\320\260\321\202\321\214\n"
"\320\277\320\260\320\277\320\272\321\203", nullptr));
        labelAudio->setText(QApplication::translate("MainWindowSchoolRadio", "\320\237\320\260\320\277\320\272\320\260:", nullptr));
        toolButtonDir->setText(QApplication::translate("MainWindowSchoolRadio", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowSchoolRadio: public Ui_MainWindowSchoolRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWSCHOOLRADIO_H
