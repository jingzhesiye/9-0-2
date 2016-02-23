/********************************************************************************
** Form generated from reading UI file 'toolcircle.ui'
**
** Created: Mon Nov 16 13:46:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLCIRCLE_H
#define UI_TOOLCIRCLE_H

#include <./SpecialUI/sizetbtn.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolCircle
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stkWidget_Main;
    QWidget *toolPage1;
    SizeTBtn *tbtn_Tool;
    SizeTBtn *tbtn_Set;
    SizeTBtn *tbtn_Home;
    SizeTBtn *tbtn_Return;
    SizeTBtn *tbtn_KeyBoard;
    QWidget *toolPage2;
    SizeTBtn *tbtn_PrintScreen;
    SizeTBtn *tbtn_Return_2;
    SizeTBtn *tbtn_Sys;
    SizeTBtn *tbtn_Help;

    void setupUi(QFrame *ToolCircle)
    {
        if (ToolCircle->objectName().isEmpty())
            ToolCircle->setObjectName(QString::fromUtf8("ToolCircle"));
        ToolCircle->resize(210, 210);
        ToolCircle->setStyleSheet(QString::fromUtf8("#ToolCircle\n"
"{\n"
"	background-color: rgba(62, 62, 62, 60%);\n"
"	border-radius:20px;\n"
"}\n"
""));
        ToolCircle->setFrameShape(QFrame::StyledPanel);
        ToolCircle->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(ToolCircle);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stkWidget_Main = new QStackedWidget(ToolCircle);
        stkWidget_Main->setObjectName(QString::fromUtf8("stkWidget_Main"));
        stkWidget_Main->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));
        toolPage1 = new QWidget();
        toolPage1->setObjectName(QString::fromUtf8("toolPage1"));
        toolPage1->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.711864 rgba(255, 255, 255, 255), stop:1 rgba(180, 180, 180, 255));\n"
"\n"
"border-radius:35px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.711864 rgba(170, 170, 170, 255), stop:1 rgba(100, 100, 100, 255));\n"
"}"));
        tbtn_Tool = new SizeTBtn(toolPage1);
        tbtn_Tool->setObjectName(QString::fromUtf8("tbtn_Tool"));
        tbtn_Tool->setGeometry(QRect(70, 10, 70, 70));
        tbtn_Tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/logo_btn_Tool_Off.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_Tool->setIcon(icon);
        tbtn_Tool->setIconSize(QSize(40, 40));
        tbtn_Set = new SizeTBtn(toolPage1);
        tbtn_Set->setObjectName(QString::fromUtf8("tbtn_Set"));
        tbtn_Set->setGeometry(QRect(10, 70, 70, 70));
        tbtn_Set->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/btn_Options_Enable.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_Set->setIcon(icon1);
        tbtn_Set->setIconSize(QSize(40, 40));
        tbtn_Home = new SizeTBtn(toolPage1);
        tbtn_Home->setObjectName(QString::fromUtf8("tbtn_Home"));
        tbtn_Home->setGeometry(QRect(70, 130, 70, 70));
        tbtn_Home->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/black_Home_Ori.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_Home->setIcon(icon2);
        tbtn_Home->setIconSize(QSize(40, 40));
        tbtn_Return = new SizeTBtn(toolPage1);
        tbtn_Return->setObjectName(QString::fromUtf8("tbtn_Return"));
        tbtn_Return->setGeometry(QRect(140, 0, 70, 70));
        tbtn_Return->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/btn_Undo2_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_Return->setIcon(icon3);
        tbtn_Return->setIconSize(QSize(40, 40));
        tbtn_KeyBoard = new SizeTBtn(toolPage1);
        tbtn_KeyBoard->setObjectName(QString::fromUtf8("tbtn_KeyBoard"));
        tbtn_KeyBoard->setGeometry(QRect(130, 70, 70, 70));
        tbtn_KeyBoard->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.711864 rgba(255, 255, 255, 255), stop:1 rgba(180, 180, 180, 255));\n"
"\n"
"border-radius:35px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.711864 rgba(170, 170, 170, 255), stop:1 rgba(100, 100, 100, 255));\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pic/keyboard_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_KeyBoard->setIcon(icon4);
        tbtn_KeyBoard->setIconSize(QSize(40, 40));
        stkWidget_Main->addWidget(toolPage1);
        toolPage2 = new QWidget();
        toolPage2->setObjectName(QString::fromUtf8("toolPage2"));
        toolPage2->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.711864 rgba(255, 255, 255, 255), stop:1 rgba(180, 180, 180, 255));\n"
"\n"
"border-radius:35px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.711864 rgba(170, 170, 170, 255), stop:1 rgba(100, 100, 100, 255));\n"
"}"));
        tbtn_PrintScreen = new SizeTBtn(toolPage2);
        tbtn_PrintScreen->setObjectName(QString::fromUtf8("tbtn_PrintScreen"));
        tbtn_PrintScreen->setGeometry(QRect(10, 70, 70, 70));
        tbtn_PrintScreen->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/pic/screenshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_PrintScreen->setIcon(icon5);
        tbtn_PrintScreen->setIconSize(QSize(40, 40));
        tbtn_Return_2 = new SizeTBtn(toolPage2);
        tbtn_Return_2->setObjectName(QString::fromUtf8("tbtn_Return_2"));
        tbtn_Return_2->setGeometry(QRect(130, 70, 70, 70));
        tbtn_Return_2->setStyleSheet(QString::fromUtf8(""));
        tbtn_Return_2->setIcon(icon3);
        tbtn_Return_2->setIconSize(QSize(40, 40));
        tbtn_Sys = new SizeTBtn(toolPage2);
        tbtn_Sys->setObjectName(QString::fromUtf8("tbtn_Sys"));
        tbtn_Sys->setGeometry(QRect(70, 130, 70, 70));
        tbtn_Sys->setStyleSheet(QString::fromUtf8(""));
        tbtn_Sys->setIconSize(QSize(40, 40));
        tbtn_Help = new SizeTBtn(toolPage2);
        tbtn_Help->setObjectName(QString::fromUtf8("tbtn_Help"));
        tbtn_Help->setGeometry(QRect(70, 10, 70, 70));
        tbtn_Help->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/pic/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_Help->setIcon(icon6);
        tbtn_Help->setIconSize(QSize(40, 40));
        stkWidget_Main->addWidget(toolPage2);

        gridLayout->addWidget(stkWidget_Main, 0, 0, 1, 1);


        retranslateUi(ToolCircle);

        stkWidget_Main->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ToolCircle);
    } // setupUi

    void retranslateUi(QFrame *ToolCircle)
    {
        ToolCircle->setWindowTitle(QApplication::translate("ToolCircle", "Frame", 0, QApplication::UnicodeUTF8));
        tbtn_Tool->setText(QString());
        tbtn_Set->setText(QApplication::translate("ToolCircle", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tbtn_Home->setText(QApplication::translate("ToolCircle", "\344\270\273\351\241\265", 0, QApplication::UnicodeUTF8));
        tbtn_Return->setText(QApplication::translate("ToolCircle", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        tbtn_KeyBoard->setText(QApplication::translate("ToolCircle", "\351\224\256\347\233\230", 0, QApplication::UnicodeUTF8));
        tbtn_PrintScreen->setText(QApplication::translate("ToolCircle", "\346\210\252\345\233\276", 0, QApplication::UnicodeUTF8));
        tbtn_Return_2->setText(QApplication::translate("ToolCircle", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        tbtn_Sys->setText(QApplication::translate("ToolCircle", "\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        tbtn_Help->setText(QApplication::translate("ToolCircle", "\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ToolCircle: public Ui_ToolCircle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLCIRCLE_H
