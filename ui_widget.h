/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Mon Oct 26 10:23:27 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *RSMV_Wave_Page;
    QGridLayout *gridLayout_3;
    QTableWidget *RSMV_Wave_Cur_TblWidget;
    QwtPlot *RSMV_Wave_Vol_QwtPlot;
    QTableWidget *RSMV_Wave_Vol_TblWidget;
    QwtPlot *RSMV_Wave_Cur_QwtPlot;
    QWidget *SetCom_Page;
    QGridLayout *gridLayout_4;
    QFrame *SetCom_Frame_1;
    QLabel *SetCom_Label_1;
    QTextBrowser *SetCom_Send_TxBrowser;
    QPushButton *SetCom_Send_PsBtn;
    QPushButton *SetCom_CleanS_PsBtn;
    QPushButton *SetCom_CleanR_PsBtn;
    QFrame *SetCom_Frame_2;
    QLabel *SetCom_Label_2;
    QTextBrowser *SetCom_Receive_TxBrowser;
    QGroupBox *SetCom_SetArg_GpBox;
    QPushButton *SetCom_IEC61850_PsBtn;
    QPushButton *SetCom_RP_PsBtn;
    QPushButton *SetCom_VER_PsBtn;
    QPushButton *SetCom_RSM_PsBtn;
    QPushButton *SetCom_ME_PsBtn;
    QPushButton *SetCom_RESETCPU_PsBtn;
    QPushButton *SetCom_RUP_PsBtn;
    QWidget *sideBar;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_1;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(780, 630);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/logo_xinglong.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidget->setWindowIcon(icon);
        MainWidget->setStyleSheet(QString::fromUtf8("QWidget.SideBar {\n"
"    border-right: 1px solid rgb(170, 170, 170);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(50, 50, 50, 255),\n"
"        stop:1 rgba(150, 150, 150, 255));\n"
"}\n"
"\n"
"QWidget.SideBar QToolButton {\n"
"    font-size: 13px;\n"
"    font-weight: normal;\n"
"    border: none;\n"
"    color: rgb(100,240,240);\n"
"\n"
"    padding-left:12px;\n"
"    padding-right: 12px;\n"
"    padding-top: 5px;\n"
"\n"
"    border-top: 1px dashed rgba(0,0,0,0);\n"
"    border-bottom: 1px dashed rgba(0,0,0,0);\n"
"    border-right: 1px dashed rgba(0,0,0,0);\n"
"}\n"
"\n"
"QWidget.SideBar QToolButton:hover {\n"
"    color: rgb(200, 200, 200);\n"
"}\n"
"\n"
"QWidget.SideBar QToolButton[current=\"true\"] {\n"
"    border-top: 1px solid rgb(90,90,90);\n"
"    border-right: 1px solid rgb(200, 200, 200, 200);\n"
"    border-bottom: 1px solid rgb(90,90,90);\n"
"    color: black;\n"
"    background: qlineargradient(spread:pad,\n"
"        x1:0, y1:"
                        "0, x2:1, y2:0,\n"
"        stop:0 rgba(130, 130, 130, 255),\n"
"        stop:1 rgba(230, 230, 230, 255));\n"
"}\n"
"\n"
"QWidget.SideBar QToolButton[first=\"true\"] {\n"
"    border-top: 1px dashed rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QWidget.SideBar .Separator {\n"
"    border: none;\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(10, 10, 10, 255),\n"
"        stop:1 rgba(220, 220, 220, 255));\n"
"}\n"
"\n"
"#content {\n"
"	border: none;\n"
"	border-left: 1px solid gray;\n"
"	background: rgba(0, 255, 0, 100);\n"
"}"));
        gridLayout = new QGridLayout(MainWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        RSMV_Wave_Page = new QWidget();
        RSMV_Wave_Page->setObjectName(QString::fromUtf8("RSMV_Wave_Page"));
        gridLayout_3 = new QGridLayout(RSMV_Wave_Page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        RSMV_Wave_Cur_TblWidget = new QTableWidget(RSMV_Wave_Page);
        if (RSMV_Wave_Cur_TblWidget->columnCount() < 4)
            RSMV_Wave_Cur_TblWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        RSMV_Wave_Cur_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        RSMV_Wave_Cur_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        RSMV_Wave_Cur_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        RSMV_Wave_Cur_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (RSMV_Wave_Cur_TblWidget->rowCount() < 3)
            RSMV_Wave_Cur_TblWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        RSMV_Wave_Cur_TblWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        RSMV_Wave_Cur_TblWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        RSMV_Wave_Cur_TblWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(250, 240, 160, 255));
        brush1.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem7->setBackground(brush1);
        __qtablewidgetitem7->setForeground(brush);
        __qtablewidgetitem7->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(0, 0, __qtablewidgetitem7);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem8->setBackground(brush1);
        __qtablewidgetitem8->setForeground(brush2);
        __qtablewidgetitem8->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(0, 1, __qtablewidgetitem8);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem9->setBackground(brush1);
        __qtablewidgetitem9->setForeground(brush3);
        __qtablewidgetitem9->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(0, 2, __qtablewidgetitem9);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem10->setBackground(brush1);
        __qtablewidgetitem10->setForeground(brush4);
        __qtablewidgetitem10->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(0, 3, __qtablewidgetitem10);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::NoBrush);
        QBrush brush6(QColor(150, 230, 140, 255));
        brush6.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem11->setBackground(brush6);
        __qtablewidgetitem11->setForeground(brush5);
        __qtablewidgetitem11->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(1, 0, __qtablewidgetitem11);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem12->setBackground(brush6);
        __qtablewidgetitem12->setForeground(brush7);
        __qtablewidgetitem12->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(1, 1, __qtablewidgetitem12);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem13->setBackground(brush6);
        __qtablewidgetitem13->setForeground(brush8);
        __qtablewidgetitem13->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(1, 2, __qtablewidgetitem13);
        QBrush brush9(QColor(0, 0, 0, 255));
        brush9.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem14->setBackground(brush6);
        __qtablewidgetitem14->setForeground(brush9);
        __qtablewidgetitem14->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(1, 3, __qtablewidgetitem14);
        QBrush brush10(QColor(0, 0, 0, 255));
        brush10.setStyle(Qt::NoBrush);
        QBrush brush11(QColor(255, 150, 150, 255));
        brush11.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem15->setBackground(brush11);
        __qtablewidgetitem15->setForeground(brush10);
        __qtablewidgetitem15->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(2, 0, __qtablewidgetitem15);
        QBrush brush12(QColor(0, 0, 0, 255));
        brush12.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem16->setBackground(brush11);
        __qtablewidgetitem16->setForeground(brush12);
        __qtablewidgetitem16->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(2, 1, __qtablewidgetitem16);
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem17->setBackground(brush11);
        __qtablewidgetitem17->setForeground(brush13);
        __qtablewidgetitem17->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(2, 2, __qtablewidgetitem17);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem18->setBackground(brush11);
        __qtablewidgetitem18->setForeground(brush14);
        __qtablewidgetitem18->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Cur_TblWidget->setItem(2, 3, __qtablewidgetitem18);
        RSMV_Wave_Cur_TblWidget->setObjectName(QString::fromUtf8("RSMV_Wave_Cur_TblWidget"));
        RSMV_Wave_Cur_TblWidget->setStyleSheet(QString::fromUtf8(""));
        RSMV_Wave_Cur_TblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RSMV_Wave_Cur_TblWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        RSMV_Wave_Cur_TblWidget->horizontalHeader()->setVisible(false);
        RSMV_Wave_Cur_TblWidget->horizontalHeader()->setDefaultSectionSize(157);
        RSMV_Wave_Cur_TblWidget->horizontalHeader()->setHighlightSections(true);
        RSMV_Wave_Cur_TblWidget->verticalHeader()->setVisible(false);
        RSMV_Wave_Cur_TblWidget->verticalHeader()->setDefaultSectionSize(35);

        gridLayout_3->addWidget(RSMV_Wave_Cur_TblWidget, 4, 0, 1, 1);

        RSMV_Wave_Vol_QwtPlot = new QwtPlot(RSMV_Wave_Page);
        RSMV_Wave_Vol_QwtPlot->setObjectName(QString::fromUtf8("RSMV_Wave_Vol_QwtPlot"));
        RSMV_Wave_Vol_QwtPlot->setMinimumSize(QSize(0, 180));
        RSMV_Wave_Vol_QwtPlot->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(RSMV_Wave_Vol_QwtPlot, 1, 0, 1, 1);

        RSMV_Wave_Vol_TblWidget = new QTableWidget(RSMV_Wave_Page);
        if (RSMV_Wave_Vol_TblWidget->columnCount() < 4)
            RSMV_Wave_Vol_TblWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        RSMV_Wave_Vol_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        RSMV_Wave_Vol_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        RSMV_Wave_Vol_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        RSMV_Wave_Vol_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        if (RSMV_Wave_Vol_TblWidget->rowCount() < 3)
            RSMV_Wave_Vol_TblWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        RSMV_Wave_Vol_TblWidget->setVerticalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        RSMV_Wave_Vol_TblWidget->setVerticalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        RSMV_Wave_Vol_TblWidget->setVerticalHeaderItem(2, __qtablewidgetitem25);
        QBrush brush15(QColor(0, 0, 0, 255));
        brush15.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem26->setBackground(brush1);
        __qtablewidgetitem26->setForeground(brush15);
        __qtablewidgetitem26->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(0, 0, __qtablewidgetitem26);
        QBrush brush16(QColor(0, 0, 0, 255));
        brush16.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem27->setBackground(brush1);
        __qtablewidgetitem27->setForeground(brush16);
        __qtablewidgetitem27->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(0, 1, __qtablewidgetitem27);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem28->setBackground(brush1);
        __qtablewidgetitem28->setForeground(brush17);
        __qtablewidgetitem28->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(0, 2, __qtablewidgetitem28);
        QBrush brush18(QColor(0, 0, 0, 255));
        brush18.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem29->setBackground(brush1);
        __qtablewidgetitem29->setForeground(brush18);
        __qtablewidgetitem29->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(0, 3, __qtablewidgetitem29);
        QBrush brush19(QColor(0, 0, 0, 255));
        brush19.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem30->setBackground(brush6);
        __qtablewidgetitem30->setForeground(brush19);
        __qtablewidgetitem30->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(1, 0, __qtablewidgetitem30);
        QBrush brush20(QColor(0, 0, 0, 255));
        brush20.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem31->setBackground(brush6);
        __qtablewidgetitem31->setForeground(brush20);
        __qtablewidgetitem31->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(1, 1, __qtablewidgetitem31);
        QBrush brush21(QColor(0, 0, 0, 255));
        brush21.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem32->setBackground(brush6);
        __qtablewidgetitem32->setForeground(brush21);
        __qtablewidgetitem32->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(1, 2, __qtablewidgetitem32);
        QBrush brush22(QColor(0, 0, 0, 255));
        brush22.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem33->setBackground(brush6);
        __qtablewidgetitem33->setForeground(brush22);
        __qtablewidgetitem33->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(1, 3, __qtablewidgetitem33);
        QBrush brush23(QColor(0, 0, 0, 255));
        brush23.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem34->setBackground(brush11);
        __qtablewidgetitem34->setForeground(brush23);
        __qtablewidgetitem34->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(2, 0, __qtablewidgetitem34);
        QBrush brush24(QColor(0, 0, 0, 255));
        brush24.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem35->setBackground(brush11);
        __qtablewidgetitem35->setForeground(brush24);
        __qtablewidgetitem35->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(2, 1, __qtablewidgetitem35);
        QBrush brush25(QColor(0, 0, 0, 255));
        brush25.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem36->setBackground(brush11);
        __qtablewidgetitem36->setForeground(brush25);
        __qtablewidgetitem36->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(2, 2, __qtablewidgetitem36);
        QBrush brush26(QColor(0, 0, 0, 255));
        brush26.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem37->setBackground(brush11);
        __qtablewidgetitem37->setForeground(brush26);
        __qtablewidgetitem37->setFlags(Qt::NoItemFlags);
        RSMV_Wave_Vol_TblWidget->setItem(2, 3, __qtablewidgetitem37);
        RSMV_Wave_Vol_TblWidget->setObjectName(QString::fromUtf8("RSMV_Wave_Vol_TblWidget"));
        RSMV_Wave_Vol_TblWidget->setStyleSheet(QString::fromUtf8(""));
        RSMV_Wave_Vol_TblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RSMV_Wave_Vol_TblWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        RSMV_Wave_Vol_TblWidget->horizontalHeader()->setVisible(false);
        RSMV_Wave_Vol_TblWidget->horizontalHeader()->setDefaultSectionSize(157);
        RSMV_Wave_Vol_TblWidget->horizontalHeader()->setHighlightSections(true);
        RSMV_Wave_Vol_TblWidget->verticalHeader()->setVisible(false);
        RSMV_Wave_Vol_TblWidget->verticalHeader()->setDefaultSectionSize(35);

        gridLayout_3->addWidget(RSMV_Wave_Vol_TblWidget, 2, 0, 1, 1);

        RSMV_Wave_Cur_QwtPlot = new QwtPlot(RSMV_Wave_Page);
        RSMV_Wave_Cur_QwtPlot->setObjectName(QString::fromUtf8("RSMV_Wave_Cur_QwtPlot"));
        RSMV_Wave_Cur_QwtPlot->setMinimumSize(QSize(0, 180));
        RSMV_Wave_Cur_QwtPlot->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        RSMV_Wave_Cur_QwtPlot->setLineWidth(1);

        gridLayout_3->addWidget(RSMV_Wave_Cur_QwtPlot, 3, 0, 1, 1);

        stackedWidget->addWidget(RSMV_Wave_Page);
        SetCom_Page = new QWidget();
        SetCom_Page->setObjectName(QString::fromUtf8("SetCom_Page"));
        gridLayout_4 = new QGridLayout(SetCom_Page);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        SetCom_Frame_1 = new QFrame(SetCom_Page);
        SetCom_Frame_1->setObjectName(QString::fromUtf8("SetCom_Frame_1"));
        SetCom_Frame_1->setMinimumSize(QSize(0, 40));
        SetCom_Frame_1->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/menu_2.png);"));
        SetCom_Frame_1->setFrameShape(QFrame::StyledPanel);
        SetCom_Frame_1->setFrameShadow(QFrame::Raised);
        SetCom_Label_1 = new QLabel(SetCom_Frame_1);
        SetCom_Label_1->setObjectName(QString::fromUtf8("SetCom_Label_1"));
        SetCom_Label_1->setGeometry(QRect(20, 10, 121, 21));
        SetCom_Label_1->setStyleSheet(QString::fromUtf8("background-image: url(:);\n"
"background-color: rgb(0, 0, 0,0);\n"
"color:rgb(255, 255, 255);\n"
"MainWindow * { \n"
"background-image: url();\n"
"}"));

        gridLayout_4->addWidget(SetCom_Frame_1, 0, 0, 1, 3);

        SetCom_Send_TxBrowser = new QTextBrowser(SetCom_Page);
        SetCom_Send_TxBrowser->setObjectName(QString::fromUtf8("SetCom_Send_TxBrowser"));
        SetCom_Send_TxBrowser->setEnabled(true);

        gridLayout_4->addWidget(SetCom_Send_TxBrowser, 1, 0, 2, 1);

        SetCom_Send_PsBtn = new QPushButton(SetCom_Page);
        SetCom_Send_PsBtn->setObjectName(QString::fromUtf8("SetCom_Send_PsBtn"));

        gridLayout_4->addWidget(SetCom_Send_PsBtn, 1, 1, 2, 1);

        SetCom_CleanS_PsBtn = new QPushButton(SetCom_Page);
        SetCom_CleanS_PsBtn->setObjectName(QString::fromUtf8("SetCom_CleanS_PsBtn"));

        gridLayout_4->addWidget(SetCom_CleanS_PsBtn, 1, 2, 1, 1);

        SetCom_CleanR_PsBtn = new QPushButton(SetCom_Page);
        SetCom_CleanR_PsBtn->setObjectName(QString::fromUtf8("SetCom_CleanR_PsBtn"));

        gridLayout_4->addWidget(SetCom_CleanR_PsBtn, 2, 2, 1, 1);

        SetCom_Frame_2 = new QFrame(SetCom_Page);
        SetCom_Frame_2->setObjectName(QString::fromUtf8("SetCom_Frame_2"));
        SetCom_Frame_2->setMinimumSize(QSize(0, 40));
        SetCom_Frame_2->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/menu_2.png);"));
        SetCom_Frame_2->setFrameShape(QFrame::StyledPanel);
        SetCom_Frame_2->setFrameShadow(QFrame::Raised);
        SetCom_Label_2 = new QLabel(SetCom_Frame_2);
        SetCom_Label_2->setObjectName(QString::fromUtf8("SetCom_Label_2"));
        SetCom_Label_2->setGeometry(QRect(20, 10, 121, 21));
        SetCom_Label_2->setStyleSheet(QString::fromUtf8("background-image: url(:);\n"
"background-color: rgb(0, 0, 0,0);\n"
"color:rgb(255, 255, 255);\n"
"MainWindow * { \n"
"background-image: url();\n"
"}"));

        gridLayout_4->addWidget(SetCom_Frame_2, 3, 0, 1, 3);

        SetCom_Receive_TxBrowser = new QTextBrowser(SetCom_Page);
        SetCom_Receive_TxBrowser->setObjectName(QString::fromUtf8("SetCom_Receive_TxBrowser"));

        gridLayout_4->addWidget(SetCom_Receive_TxBrowser, 4, 0, 1, 3);

        SetCom_SetArg_GpBox = new QGroupBox(SetCom_Page);
        SetCom_SetArg_GpBox->setObjectName(QString::fromUtf8("SetCom_SetArg_GpBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SetCom_SetArg_GpBox->sizePolicy().hasHeightForWidth());
        SetCom_SetArg_GpBox->setSizePolicy(sizePolicy);
        SetCom_SetArg_GpBox->setMinimumSize(QSize(0, 100));
        SetCom_IEC61850_PsBtn = new QPushButton(SetCom_SetArg_GpBox);
        SetCom_IEC61850_PsBtn->setObjectName(QString::fromUtf8("SetCom_IEC61850_PsBtn"));
        SetCom_IEC61850_PsBtn->setGeometry(QRect(10, 30, 101, 40));
        SetCom_RP_PsBtn = new QPushButton(SetCom_SetArg_GpBox);
        SetCom_RP_PsBtn->setObjectName(QString::fromUtf8("SetCom_RP_PsBtn"));
        SetCom_RP_PsBtn->setGeometry(QRect(130, 30, 101, 40));
        SetCom_VER_PsBtn = new QPushButton(SetCom_SetArg_GpBox);
        SetCom_VER_PsBtn->setObjectName(QString::fromUtf8("SetCom_VER_PsBtn"));
        SetCom_VER_PsBtn->setGeometry(QRect(250, 30, 101, 40));
        SetCom_RSM_PsBtn = new QPushButton(SetCom_SetArg_GpBox);
        SetCom_RSM_PsBtn->setObjectName(QString::fromUtf8("SetCom_RSM_PsBtn"));
        SetCom_RSM_PsBtn->setGeometry(QRect(370, 30, 101, 40));
        SetCom_ME_PsBtn = new QPushButton(SetCom_SetArg_GpBox);
        SetCom_ME_PsBtn->setObjectName(QString::fromUtf8("SetCom_ME_PsBtn"));
        SetCom_ME_PsBtn->setGeometry(QRect(10, 80, 101, 40));
        SetCom_RESETCPU_PsBtn = new QPushButton(SetCom_SetArg_GpBox);
        SetCom_RESETCPU_PsBtn->setObjectName(QString::fromUtf8("SetCom_RESETCPU_PsBtn"));
        SetCom_RESETCPU_PsBtn->setGeometry(QRect(250, 80, 221, 40));
        SetCom_RUP_PsBtn = new QPushButton(SetCom_SetArg_GpBox);
        SetCom_RUP_PsBtn->setObjectName(QString::fromUtf8("SetCom_RUP_PsBtn"));
        SetCom_RUP_PsBtn->setGeometry(QRect(130, 80, 101, 40));

        gridLayout_4->addWidget(SetCom_SetArg_GpBox, 5, 0, 1, 3);

        stackedWidget->addWidget(SetCom_Page);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        sideBar = new QWidget(MainWidget);
        sideBar->setObjectName(QString::fromUtf8("sideBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sideBar->sizePolicy().hasHeightForWidth());
        sideBar->setSizePolicy(sizePolicy1);
        sideBar->setMinimumSize(QSize(90, 0));
        sideBar->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(sideBar);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        toolButton_1 = new QToolButton(sideBar);
        toolButton_1->setObjectName(QString::fromUtf8("toolButton_1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton_1->sizePolicy().hasHeightForWidth());
        toolButton_1->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/smv.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_1->setIcon(icon1);
        toolButton_1->setIconSize(QSize(64, 64));
        toolButton_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolButton_1, 1, 0, 1, 1);

        toolButton_3 = new QToolButton(sideBar);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/netMessage.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(64, 64));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolButton_3, 4, 0, 1, 1);

        toolButton_2 = new QToolButton(sideBar);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/s_goose.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon3);
        toolButton_2->setIconSize(QSize(64, 64));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolButton_2, 2, 0, 1, 1);

        toolButton_4 = new QToolButton(sideBar);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        sizePolicy2.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pic/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(64, 64));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolButton_4, 5, 0, 1, 1);


        gridLayout->addWidget(sideBar, 0, 1, 1, 1);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Widget", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = RSMV_Wave_Cur_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWidget", "\351\200\232\351\201\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = RSMV_Wave_Cur_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWidget", "\350\256\276\347\275\256\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = RSMV_Wave_Cur_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWidget", "\351\200\232\351\201\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = RSMV_Wave_Cur_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWidget", "\350\256\276\347\275\256\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = RSMV_Wave_Cur_TblWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = RSMV_Wave_Cur_TblWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = RSMV_Wave_Cur_TblWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = RSMV_Wave_Cur_TblWidget->isSortingEnabled();
        RSMV_Wave_Cur_TblWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = RSMV_Wave_Cur_TblWidget->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWidget", "Ia(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = RSMV_Wave_Cur_TblWidget->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = RSMV_Wave_Cur_TblWidget->item(0, 2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWidget", "Iaph(\345\272\246)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = RSMV_Wave_Cur_TblWidget->item(0, 3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = RSMV_Wave_Cur_TblWidget->item(1, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWidget", "Ib(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = RSMV_Wave_Cur_TblWidget->item(1, 1);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = RSMV_Wave_Cur_TblWidget->item(1, 2);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWidget", "Ibph(\345\272\246)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = RSMV_Wave_Cur_TblWidget->item(1, 3);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = RSMV_Wave_Cur_TblWidget->item(2, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWidget", "Ic(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = RSMV_Wave_Cur_TblWidget->item(2, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = RSMV_Wave_Cur_TblWidget->item(2, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWidget", "Icph(\345\272\246)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = RSMV_Wave_Cur_TblWidget->item(2, 3);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        RSMV_Wave_Cur_TblWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem19 = RSMV_Wave_Vol_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWidget", "\351\200\232\351\201\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = RSMV_Wave_Vol_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWidget", "\350\256\276\347\275\256\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = RSMV_Wave_Vol_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWidget", "\351\200\232\351\201\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = RSMV_Wave_Vol_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWidget", "\350\256\276\347\275\256\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = RSMV_Wave_Vol_TblWidget->verticalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = RSMV_Wave_Vol_TblWidget->verticalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = RSMV_Wave_Vol_TblWidget->verticalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = RSMV_Wave_Vol_TblWidget->isSortingEnabled();
        RSMV_Wave_Vol_TblWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem26 = RSMV_Wave_Vol_TblWidget->item(0, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWidget", "Ua(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = RSMV_Wave_Vol_TblWidget->item(0, 1);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = RSMV_Wave_Vol_TblWidget->item(0, 2);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWidget", "Uaph(\345\272\246)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = RSMV_Wave_Vol_TblWidget->item(0, 3);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = RSMV_Wave_Vol_TblWidget->item(1, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWidget", "Ub(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = RSMV_Wave_Vol_TblWidget->item(1, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = RSMV_Wave_Vol_TblWidget->item(1, 2);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWidget", "Ubph(\345\272\246)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = RSMV_Wave_Vol_TblWidget->item(1, 3);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = RSMV_Wave_Vol_TblWidget->item(2, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWidget", "Uc(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = RSMV_Wave_Vol_TblWidget->item(2, 1);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = RSMV_Wave_Vol_TblWidget->item(2, 2);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWidget", "Ucph(\345\272\246)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = RSMV_Wave_Vol_TblWidget->item(2, 3);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        RSMV_Wave_Vol_TblWidget->setSortingEnabled(__sortingEnabled1);

        SetCom_Label_1->setText(QApplication::translate("MainWidget", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        SetCom_Send_PsBtn->setText(QApplication::translate("MainWidget", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        SetCom_CleanS_PsBtn->setText(QApplication::translate("MainWidget", "\346\270\205\347\251\272\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        SetCom_CleanR_PsBtn->setText(QApplication::translate("MainWidget", "\346\270\205\347\251\272\346\216\245\346\224\266", 0, QApplication::UnicodeUTF8));
        SetCom_Label_2->setText(QApplication::translate("MainWidget", "\346\216\245\346\224\266", 0, QApplication::UnicodeUTF8));
        SetCom_SetArg_GpBox->setTitle(QApplication::translate("MainWidget", "\345\277\253\351\200\237\345\221\275\344\273\244\345\214\272", 0, QApplication::UnicodeUTF8));
        SetCom_IEC61850_PsBtn->setText(QApplication::translate("MainWidget", "IEC61850", 0, QApplication::UnicodeUTF8));
        SetCom_RP_PsBtn->setText(QApplication::translate("MainWidget", "RP", 0, QApplication::UnicodeUTF8));
        SetCom_VER_PsBtn->setText(QApplication::translate("MainWidget", "\347\211\210\346\234\254", 0, QApplication::UnicodeUTF8));
        SetCom_RSM_PsBtn->setText(QApplication::translate("MainWidget", "\345\267\245\344\275\234\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        SetCom_ME_PsBtn->setText(QApplication::translate("MainWidget", "RGP", 0, QApplication::UnicodeUTF8));
        SetCom_RESETCPU_PsBtn->setText(QApplication::translate("MainWidget", "RESETCPU", 0, QApplication::UnicodeUTF8));
        SetCom_RUP_PsBtn->setText(QApplication::translate("MainWidget", "RUP", 0, QApplication::UnicodeUTF8));
        sideBar->setProperty("class", QVariant(QApplication::translate("MainWidget", "SideBar", 0, QApplication::UnicodeUTF8)));
        toolButton_1->setText(QString());
        toolButton_3->setText(QString());
        toolButton_2->setText(QString());
        toolButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
