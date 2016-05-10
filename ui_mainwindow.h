/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textOutput;
    QPushButton *btnClearOutput;
    QPushButton *btnSend;
    QFrame *line;
    QTextEdit *textInput;
    QLabel *labelCon;
    QSlider *sliderCOM;
    QLabel *labelCOM1;
    QLabel *labelCOM2;
    QLabel *labelCOM3;
    QLabel *labelCOM4;
    QPushButton *btnConnect;
    QPushButton *btnDisconnect;
    QSlider *sliderBaud;
    QLabel *labelBaud1;
    QLabel *labelBaud2;
    QLabel *labelBaud3;
    QLabel *labelBaud4;
    QLabel *labelBaud5;
    QLabel *labelBaud6;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(780, 622);
        MainWindow->setMinimumSize(QSize(780, 622));
        MainWindow->setMaximumSize(QSize(780, 622));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textOutput = new QTextEdit(centralWidget);
        textOutput->setObjectName(QStringLiteral("textOutput"));
        textOutput->setGeometry(QRect(10, 10, 601, 491));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush1(QColor(227, 227, 227, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        textOutput->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        textOutput->setFont(font);
        textOutput->setReadOnly(true);
        btnClearOutput = new QPushButton(centralWidget);
        btnClearOutput->setObjectName(QStringLiteral("btnClearOutput"));
        btnClearOutput->setGeometry(QRect(620, 10, 151, 51));
        btnSend = new QPushButton(centralWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(540, 530, 75, 51));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 500, 761, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        textInput = new QTextEdit(centralWidget);
        textInput->setObjectName(QStringLiteral("textInput"));
        textInput->setGeometry(QRect(10, 530, 521, 51));
        labelCon = new QLabel(centralWidget);
        labelCon->setObjectName(QStringLiteral("labelCon"));
        labelCon->setGeometry(QRect(630, 440, 121, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        labelCon->setFont(font1);
        sliderCOM = new QSlider(centralWidget);
        sliderCOM->setObjectName(QStringLiteral("sliderCOM"));
        sliderCOM->setGeometry(QRect(630, 90, 22, 71));
        sliderCOM->setMinimum(0);
        sliderCOM->setMaximum(3);
        sliderCOM->setValue(0);
        sliderCOM->setSliderPosition(0);
        sliderCOM->setOrientation(Qt::Vertical);
        sliderCOM->setInvertedAppearance(true);
        sliderCOM->setTickPosition(QSlider::TicksBothSides);
        labelCOM1 = new QLabel(centralWidget);
        labelCOM1->setObjectName(QStringLiteral("labelCOM1"));
        labelCOM1->setGeometry(QRect(660, 90, 47, 13));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(9);
        labelCOM1->setFont(font2);
        labelCOM2 = new QLabel(centralWidget);
        labelCOM2->setObjectName(QStringLiteral("labelCOM2"));
        labelCOM2->setGeometry(QRect(660, 110, 47, 13));
        labelCOM2->setFont(font2);
        labelCOM3 = new QLabel(centralWidget);
        labelCOM3->setObjectName(QStringLiteral("labelCOM3"));
        labelCOM3->setGeometry(QRect(660, 130, 47, 13));
        labelCOM3->setFont(font2);
        labelCOM4 = new QLabel(centralWidget);
        labelCOM4->setObjectName(QStringLiteral("labelCOM4"));
        labelCOM4->setGeometry(QRect(660, 150, 47, 13));
        labelCOM4->setFont(font2);
        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(630, 360, 131, 23));
        btnDisconnect = new QPushButton(centralWidget);
        btnDisconnect->setObjectName(QStringLiteral("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(630, 390, 131, 23));
        sliderBaud = new QSlider(centralWidget);
        sliderBaud->setObjectName(QStringLiteral("sliderBaud"));
        sliderBaud->setGeometry(QRect(630, 180, 22, 122));
        sliderBaud->setMaximum(5);
        sliderBaud->setValue(3);
        sliderBaud->setOrientation(Qt::Vertical);
        sliderBaud->setInvertedAppearance(true);
        sliderBaud->setTickPosition(QSlider::TicksBothSides);
        labelBaud1 = new QLabel(centralWidget);
        labelBaud1->setObjectName(QStringLiteral("labelBaud1"));
        labelBaud1->setGeometry(QRect(660, 178, 71, 16));
        labelBaud1->setFont(font2);
        labelBaud2 = new QLabel(centralWidget);
        labelBaud2->setObjectName(QStringLiteral("labelBaud2"));
        labelBaud2->setGeometry(QRect(660, 200, 71, 16));
        labelBaud2->setFont(font2);
        labelBaud3 = new QLabel(centralWidget);
        labelBaud3->setObjectName(QStringLiteral("labelBaud3"));
        labelBaud3->setGeometry(QRect(660, 222, 71, 16));
        labelBaud3->setFont(font2);
        labelBaud4 = new QLabel(centralWidget);
        labelBaud4->setObjectName(QStringLiteral("labelBaud4"));
        labelBaud4->setGeometry(QRect(660, 244, 71, 16));
        labelBaud4->setFont(font2);
        labelBaud5 = new QLabel(centralWidget);
        labelBaud5->setObjectName(QStringLiteral("labelBaud5"));
        labelBaud5->setGeometry(QRect(660, 266, 71, 16));
        labelBaud5->setFont(font2);
        labelBaud6 = new QLabel(centralWidget);
        labelBaud6->setObjectName(QStringLiteral("labelBaud6"));
        labelBaud6->setGeometry(QRect(660, 288, 71, 16));
        labelBaud6->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 780, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ModCom", 0));
        textOutput->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400;\"><br /></p></body></html>", 0));
        btnClearOutput->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207", 0));
        btnSend->setText(QApplication::translate("MainWindow", "Wy\305\233lij", 0));
        btnSend->setShortcut(QApplication::translate("MainWindow", "Return", 0));
        labelCon->setText(QApplication::translate("MainWindow", "1", 0));
        labelCOM1->setText(QApplication::translate("MainWindow", "COM1", 0));
        labelCOM2->setText(QApplication::translate("MainWindow", "COM2", 0));
        labelCOM3->setText(QApplication::translate("MainWindow", "COM3", 0));
        labelCOM4->setText(QApplication::translate("MainWindow", "COM4", 0));
        btnConnect->setText(QApplication::translate("MainWindow", "Po\305\202\304\205cz", 0));
        btnDisconnect->setText(QApplication::translate("MainWindow", "Roz\305\202\304\205cz", 0));
        labelBaud1->setText(QApplication::translate("MainWindow", "Baud 1200", 0));
        labelBaud2->setText(QApplication::translate("MainWindow", "Baud 2400", 0));
        labelBaud3->setText(QApplication::translate("MainWindow", "Baud 4800", 0));
        labelBaud4->setText(QApplication::translate("MainWindow", "Baud 9600", 0));
        labelBaud5->setText(QApplication::translate("MainWindow", "Baud 19200", 0));
        labelBaud6->setText(QApplication::translate("MainWindow", "Baud 38400", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
