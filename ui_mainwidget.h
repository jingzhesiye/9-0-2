/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout_13;
    QFrame *sideBar_up_Frame;
    QGridLayout *gridLayout_14;
    QSpacerItem *sideBar_up_HlSpacer_3;
    QLabel *battery_Label;
    QLabel *BMS_chargeMode_tag_Label;
    QLabel *BMS_chargeMode_Label;
    QSpacerItem *sideBar_up_HlSpacer_1;
    QPushButton *keyBoard_PsBtn;
    QLineEdit *runTime_LnEdit;
    QLabel *runTime_Label;
    QLabel *BMS_cntState_tag_Label;
    QLabel *BMS_cntState_Label;
    QSpacerItem *sideBar_up_HlSpacer;
    QStackedWidget *main_SkWidget;
    QWidget *test_power_Page;
    QGridLayout *gridLayout_12;
    QFrame *RS_charger_Frame;
    QGridLayout *gridLayout_22;
    QLabel *RS_charger_Lable;
    QSpacerItem *RS_charger_HlSpacer;
    QFrame *RD_BMS_Frame;
    QGridLayout *gridLayout_27;
    QLabel *RD_BMS_Label;
    QSpacerItem *RD_BMS_HlSpacer;
    QTableWidget *ES_standard_TblWidget;
    QTableWidget *RS_charger_TblWidget;
    QGroupBox *ES_GpBox;
    QGridLayout *gridLayout;
    QGroupBox *ES_value_GpBox;
    QGridLayout *gridLayout_23;
    QLabel *ES_PE_Label;
    QLineEdit *ES_TE_LnEdit;
    QLabel *ES_TE_Label;
    QLineEdit *ES_PE_LnEdit;
    QSpacerItem *ES_HlSpacer;
    QPushButton *ES_insertForm_PsBtn;
    QTabWidget *ES_TbWidget;
    QWidget *ES_PE_tab;
    QGridLayout *gridLayout_18;
    QFrame *ES_PE_Frame;
    QGridLayout *gridLayout_3;
    QSpacerItem *ES_PE_HlSpacer;
    QPushButton *ES_PE_zoomIn_PsBtn;
    QPushButton *ES_PE_zoomOut_PsBtn;
    QwtPlot *ES_PE_QwtPlot;
    QWidget *ES_wave_tab;
    QGridLayout *gridLayout_20;
    QwtPlot *ES_wave_QwtPlot;
    QFrame *ES_standard_Frame;
    QGridLayout *gridLayout_28;
    QSpacerItem *ES_standard_HlSpacer;
    QLabel *ES_standard_Label;
    QTableWidget *BMS_RD_TblWidget;
    QWidget *test_ripple_Page;
    QGridLayout *gridLayout_11;
    QwtPlot *ripple_wave_QwtPlot;
    QFrame *RRF_ripple_Frame;
    QGridLayout *gridLayout_10;
    QSpacerItem *RRF_ripple_HlSpacer;
    QComboBox *RRF_ripple_chl_CbBox;
    QLabel *RRF_ripple_chl_Label;
    QTableWidget *RRF_ripple_TblWidget;
    QWidget *form_Page;
    QGridLayout *gridLayout_26;
    QTableWidget *from_information_TbWidget;
    QFrame *from_information_Frame;
    QGridLayout *gridLayout_21;
    QPushButton *from_clearFrom_PsBtn;
    QLabel *from_information_Label;
    QSpacerItem *from_information_HlSpacer;
    QPushButton *from_buildForm_PsBtn;
    QFrame *from_error_Frame;
    QGridLayout *gridLayout_25;
    QLabel *from_error_Label;
    QSpacerItem *from_error_HlSpacer;
    QTabWidget *form_error_TbWidget;
    QWidget *intuit_tab;
    QGridLayout *gridLayout_15;
    QSpacerItem *intuit_HlSpacer;
    QLabel *intuit_Label;
    QCheckBox *intuit_CkBox;
    QWidget *operating_tab;
    QGridLayout *gridLayout_19;
    QTableWidget *operating_TblWidget;
    QWidget *load_tab;
    QGridLayout *gridLayout_24;
    QTableWidget *load_TblWidget;
    QWidget *payment;
    QGridLayout *gridLayout_29;
    QTableWidget *payment_TblWidget;
    QWidget *time_tab;
    QGridLayout *gridLayout_16;
    QTableWidget *time_TblWidget;
    QWidget *overallClu_tab;
    QGridLayout *gridLayout_30;
    QLabel *overallClu_Label;
    QCheckBox *overallClu_CkBox;
    QSpacerItem *overallClu_HlSpacer;
    QWidget *serPort_Page;
    QGridLayout *gridLayout_6;
    QGroupBox *serPort_Rec_GbBox;
    QGridLayout *gridLayout_7;
    QTextEdit *serPort_Rec_TxEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *serPort_CleanRec_PsBtn;
    QGroupBox *serPort_send_GpBox;
    QGridLayout *gridLayout_8;
    QGroupBox *serPort_SP_GpBox;
    QGridLayout *gridLayout_17;
    QPushButton *serPort_read_SP_PsBtn;
    QPushButton *serPort_write_SP_PsBtn;
    QSpacerItem *serPort_SP_HlSpacer;
    QTableWidget *serPort_SP_TabWidget;
    QTextEdit *serPort_Send_TxEdit;
    QGroupBox *serPort_shortcut_GpBox;
    QGridLayout *gridLayout_4;
    QPushButton *serPort_EB_PsBtn;
    QPushButton *serPort_ME_PsBtn;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *serPort_RS_PsBtn;
    QPushButton *serPort_AV_PsBtn;
    QPushButton *serPort_RP_PsBtn;
    QPushButton *serPort_RSM_PsBtn;
    QPushButton *serPort_RBAT_PsBtn;
    QPushButton *serPort_RD_PsBtn;
    QPushButton *serPort_RRF_PsBtn;
    QPushButton *serPort_Send_PsBtn;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *serPort_CR_CkBox;
    QPushButton *serPort_CleanSend_PsBtn;
    QCheckBox *serPort_LF_CkBox;
    QGroupBox *serPort_Settings_GpBox;
    QGridLayout *gridLayout_5;
    QLabel *serPort_portName_Label;
    QComboBox *serPort_portName_CbBox;
    QLabel *serPort_parity_Label;
    QComboBox *serPort_parity_CbBox;
    QLabel *serPort_baudRate_Label;
    QComboBox *serPort_baudRate_CbBox;
    QLabel *serPort_dataBit_Label;
    QComboBox *serPort_dataBit_CbBox;
    QLabel *serPort_stopBit_Label;
    QComboBox *serPort_stopBit_CbBox;
    QLabel *serPort_flowCtl_Label;
    QComboBox *serPort_flowCtl_CbBox;
    QGroupBox *serPort_ctl_GpBox;
    QGridLayout *gridLayout_9;
    QPushButton *serPort_Open_PsBtn;
    QPushButton *serPort_Close_PsBtn;
    QWidget *sideBar_right_Page;
    QGridLayout *gridLayout_2;
    QToolButton *sideBar_TlBtn_3;
    QToolButton *sideBar_TlBtn_2;
    QToolButton *sideBar_TlBtn_4;
    QToolButton *sideBar_TlBtn_1;
    QPushButton *start_PsBtn;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(800, 540);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWidget->sizePolicy().hasHeightForWidth());
        MainWidget->setSizePolicy(sizePolicy);
        MainWidget->setMinimumSize(QSize(800, 540));
        MainWidget->setMaximumSize(QSize(800, 540));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/logo_xinglong.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidget->setWindowIcon(icon);
        MainWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_13 = new QGridLayout(MainWidget);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        sideBar_up_Frame = new QFrame(MainWidget);
        sideBar_up_Frame->setObjectName(QString::fromUtf8("sideBar_up_Frame"));
        sizePolicy.setHeightForWidth(sideBar_up_Frame->sizePolicy().hasHeightForWidth());
        sideBar_up_Frame->setSizePolicy(sizePolicy);
        sideBar_up_Frame->setMinimumSize(QSize(800, 30));
        sideBar_up_Frame->setMaximumSize(QSize(800, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Narrow"));
        font.setPointSize(12);
        sideBar_up_Frame->setFont(font);
        sideBar_up_Frame->setStyleSheet(QString::fromUtf8("#sideBar_up_Frame{\n"
" border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"}\n"
""));
        sideBar_up_Frame->setFrameShape(QFrame::StyledPanel);
        sideBar_up_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(sideBar_up_Frame);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        sideBar_up_HlSpacer_3 = new QSpacerItem(26, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(sideBar_up_HlSpacer_3, 0, 11, 1, 1);

        battery_Label = new QLabel(sideBar_up_Frame);
        battery_Label->setObjectName(QString::fromUtf8("battery_Label"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(battery_Label->sizePolicy().hasHeightForWidth());
        battery_Label->setSizePolicy(sizePolicy1);
        battery_Label->setMinimumSize(QSize(45, 29));
        battery_Label->setMaximumSize(QSize(25, 33));
        battery_Label->setFont(font);
        battery_Label->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/battery_1.png);"));

        gridLayout_14->addWidget(battery_Label, 0, 14, 1, 1);

        BMS_chargeMode_tag_Label = new QLabel(sideBar_up_Frame);
        BMS_chargeMode_tag_Label->setObjectName(QString::fromUtf8("BMS_chargeMode_tag_Label"));
        sizePolicy.setHeightForWidth(BMS_chargeMode_tag_Label->sizePolicy().hasHeightForWidth());
        BMS_chargeMode_tag_Label->setSizePolicy(sizePolicy);
        BMS_chargeMode_tag_Label->setFont(font);
        BMS_chargeMode_tag_Label->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color: beige;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(12, 153, 134, 255);\n"
"\n"
""));

        gridLayout_14->addWidget(BMS_chargeMode_tag_Label, 0, 5, 1, 1);

        BMS_chargeMode_Label = new QLabel(sideBar_up_Frame);
        BMS_chargeMode_Label->setObjectName(QString::fromUtf8("BMS_chargeMode_Label"));
        BMS_chargeMode_Label->setFont(font);
        BMS_chargeMode_Label->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(255, 87, 104);;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(12, 153, 134, 255);"));

        gridLayout_14->addWidget(BMS_chargeMode_Label, 0, 6, 1, 1);

        sideBar_up_HlSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_14->addItem(sideBar_up_HlSpacer_1, 0, 1, 1, 1);

        keyBoard_PsBtn = new QPushButton(sideBar_up_Frame);
        keyBoard_PsBtn->setObjectName(QString::fromUtf8("keyBoard_PsBtn"));
        QFont font1;
        font1.setPointSize(12);
        keyBoard_PsBtn->setFont(font1);
        keyBoard_PsBtn->setStyleSheet(QString::fromUtf8("QPushButton#keyBoard_PsBtn \n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"	min-width:2em;	\n"
"	padding:4px;\n"
"	border-image: url(:/pic/toolBtn2.png);\n"
"}\n"
"\n"
"QPushButton#keyBoard_PsBtn:pressed\n"
"{\n"
"	border-style: inset;\n"
"	border-image: url(:/pic/MessBtn1.png);\n"
"}"));

        gridLayout_14->addWidget(keyBoard_PsBtn, 0, 0, 1, 1);

        runTime_LnEdit = new QLineEdit(sideBar_up_Frame);
        runTime_LnEdit->setObjectName(QString::fromUtf8("runTime_LnEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(runTime_LnEdit->sizePolicy().hasHeightForWidth());
        runTime_LnEdit->setSizePolicy(sizePolicy2);
        runTime_LnEdit->setMinimumSize(QSize(80, 0));
        runTime_LnEdit->setMaximumSize(QSize(80, 16777215));
        runTime_LnEdit->setFont(font);
        runTime_LnEdit->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(255, 87, 104);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(12, 153, 134, 255);"));
        runTime_LnEdit->setReadOnly(true);

        gridLayout_14->addWidget(runTime_LnEdit, 0, 13, 1, 1);

        runTime_Label = new QLabel(sideBar_up_Frame);
        runTime_Label->setObjectName(QString::fromUtf8("runTime_Label"));
        runTime_Label->setFont(font);
        runTime_Label->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color: beige;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(12, 153, 134, 255);\n"
"\n"
""));

        gridLayout_14->addWidget(runTime_Label, 0, 12, 1, 1);

        BMS_cntState_tag_Label = new QLabel(sideBar_up_Frame);
        BMS_cntState_tag_Label->setObjectName(QString::fromUtf8("BMS_cntState_tag_Label"));
        sizePolicy.setHeightForWidth(BMS_cntState_tag_Label->sizePolicy().hasHeightForWidth());
        BMS_cntState_tag_Label->setSizePolicy(sizePolicy);
        BMS_cntState_tag_Label->setFont(font);
        BMS_cntState_tag_Label->setContextMenuPolicy(Qt::NoContextMenu);
        BMS_cntState_tag_Label->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color: beige;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(12, 153, 134, 255);\n"
"\n"
""));

        gridLayout_14->addWidget(BMS_cntState_tag_Label, 0, 2, 1, 1);

        BMS_cntState_Label = new QLabel(sideBar_up_Frame);
        BMS_cntState_Label->setObjectName(QString::fromUtf8("BMS_cntState_Label"));
        BMS_cntState_Label->setMinimumSize(QSize(20, 20));
        BMS_cntState_Label->setFont(font);
        BMS_cntState_Label->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(255, 87, 104);;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(12, 153, 134, 255);"));

        gridLayout_14->addWidget(BMS_cntState_Label, 0, 3, 1, 1);

        sideBar_up_HlSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_14->addItem(sideBar_up_HlSpacer, 0, 4, 1, 1);


        gridLayout_13->addWidget(sideBar_up_Frame, 0, 0, 1, 2);

        main_SkWidget = new QStackedWidget(MainWidget);
        main_SkWidget->setObjectName(QString::fromUtf8("main_SkWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(main_SkWidget->sizePolicy().hasHeightForWidth());
        main_SkWidget->setSizePolicy(sizePolicy3);
        main_SkWidget->setMaximumSize(QSize(16777215, 531));
        main_SkWidget->setFont(font);
        main_SkWidget->setLineWidth(0);
        test_power_Page = new QWidget();
        test_power_Page->setObjectName(QString::fromUtf8("test_power_Page"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(test_power_Page->sizePolicy().hasHeightForWidth());
        test_power_Page->setSizePolicy(sizePolicy4);
        gridLayout_12 = new QGridLayout(test_power_Page);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        RS_charger_Frame = new QFrame(test_power_Page);
        RS_charger_Frame->setObjectName(QString::fromUtf8("RS_charger_Frame"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(RS_charger_Frame->sizePolicy().hasHeightForWidth());
        RS_charger_Frame->setSizePolicy(sizePolicy5);
        RS_charger_Frame->setMinimumSize(QSize(0, 25));
        RS_charger_Frame->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Kalinga"));
        font2.setPointSize(9);
        RS_charger_Frame->setFont(font2);
        RS_charger_Frame->setStyleSheet(QString::fromUtf8("#RS_charger_Frame\n"
"{\n"
" border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"}\n"
"\n"
"\n"
"\n"
""));
        RS_charger_Frame->setFrameShape(QFrame::StyledPanel);
        RS_charger_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_22 = new QGridLayout(RS_charger_Frame);
        gridLayout_22->setSpacing(0);
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        RS_charger_Lable = new QLabel(RS_charger_Frame);
        RS_charger_Lable->setObjectName(QString::fromUtf8("RS_charger_Lable"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(RS_charger_Lable->sizePolicy().hasHeightForWidth());
        RS_charger_Lable->setSizePolicy(sizePolicy6);
        RS_charger_Lable->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_22->addWidget(RS_charger_Lable, 0, 0, 1, 1);

        RS_charger_HlSpacer = new QSpacerItem(40, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_22->addItem(RS_charger_HlSpacer, 0, 1, 1, 1);


        gridLayout_12->addWidget(RS_charger_Frame, 1, 0, 1, 3);

        RD_BMS_Frame = new QFrame(test_power_Page);
        RD_BMS_Frame->setObjectName(QString::fromUtf8("RD_BMS_Frame"));
        sizePolicy3.setHeightForWidth(RD_BMS_Frame->sizePolicy().hasHeightForWidth());
        RD_BMS_Frame->setSizePolicy(sizePolicy3);
        RD_BMS_Frame->setMinimumSize(QSize(0, 25));
        RD_BMS_Frame->setMaximumSize(QSize(16777215, 25));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Kalinga"));
        font3.setPointSize(12);
        RD_BMS_Frame->setFont(font3);
        RD_BMS_Frame->setStyleSheet(QString::fromUtf8("#RD_BMS_Frame\n"
"{\n"
" border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"}\n"
"\n"
"\n"
"\n"
""));
        RD_BMS_Frame->setFrameShape(QFrame::StyledPanel);
        RD_BMS_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_27 = new QGridLayout(RD_BMS_Frame);
        gridLayout_27->setSpacing(0);
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        RD_BMS_Label = new QLabel(RD_BMS_Frame);
        RD_BMS_Label->setObjectName(QString::fromUtf8("RD_BMS_Label"));
        sizePolicy6.setHeightForWidth(RD_BMS_Label->sizePolicy().hasHeightForWidth());
        RD_BMS_Label->setSizePolicy(sizePolicy6);
        RD_BMS_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RD_BMS_Label->setIndent(0);

        gridLayout_27->addWidget(RD_BMS_Label, 0, 0, 1, 1);

        RD_BMS_HlSpacer = new QSpacerItem(34, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_27->addItem(RD_BMS_HlSpacer, 0, 1, 1, 1);


        gridLayout_12->addWidget(RD_BMS_Frame, 6, 0, 1, 1);

        ES_standard_TblWidget = new QTableWidget(test_power_Page);
        if (ES_standard_TblWidget->columnCount() < 8)
            ES_standard_TblWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        ES_standard_TblWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (ES_standard_TblWidget->rowCount() < 2)
            ES_standard_TblWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        ES_standard_TblWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        ES_standard_TblWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ES_standard_TblWidget->setItem(0, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(0, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem12->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ES_standard_TblWidget->setItem(0, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(0, 3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem14->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ES_standard_TblWidget->setItem(0, 4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(0, 5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ES_standard_TblWidget->setItem(0, 6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(0, 7, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(1, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(1, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(1, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(1, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(1, 4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        ES_standard_TblWidget->setItem(1, 5, __qtablewidgetitem23);
        ES_standard_TblWidget->setObjectName(QString::fromUtf8("ES_standard_TblWidget"));
        sizePolicy3.setHeightForWidth(ES_standard_TblWidget->sizePolicy().hasHeightForWidth());
        ES_standard_TblWidget->setSizePolicy(sizePolicy3);
        ES_standard_TblWidget->setMinimumSize(QSize(0, 29));
        ES_standard_TblWidget->setMaximumSize(QSize(16777215, 69));
        ES_standard_TblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ES_standard_TblWidget->horizontalHeader()->setVisible(false);
        ES_standard_TblWidget->horizontalHeader()->setDefaultSectionSize(90);
        ES_standard_TblWidget->horizontalHeader()->setMinimumSectionSize(21);
        ES_standard_TblWidget->verticalHeader()->setVisible(false);
        ES_standard_TblWidget->verticalHeader()->setDefaultSectionSize(32);

        gridLayout_12->addWidget(ES_standard_TblWidget, 10, 0, 1, 3);

        RS_charger_TblWidget = new QTableWidget(test_power_Page);
        if (RS_charger_TblWidget->columnCount() < 6)
            RS_charger_TblWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        RS_charger_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        RS_charger_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        RS_charger_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        RS_charger_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        RS_charger_TblWidget->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        RS_charger_TblWidget->setHorizontalHeaderItem(5, __qtablewidgetitem29);
        if (RS_charger_TblWidget->rowCount() < 2)
            RS_charger_TblWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        RS_charger_TblWidget->setVerticalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        RS_charger_TblWidget->setVerticalHeaderItem(1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem32->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        RS_charger_TblWidget->setItem(0, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RS_charger_TblWidget->setItem(0, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem34->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        RS_charger_TblWidget->setItem(0, 2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RS_charger_TblWidget->setItem(0, 3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem36->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        RS_charger_TblWidget->setItem(0, 4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RS_charger_TblWidget->setItem(0, 5, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RS_charger_TblWidget->setItem(1, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RS_charger_TblWidget->setItem(1, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        RS_charger_TblWidget->setItem(1, 2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RS_charger_TblWidget->setItem(1, 3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem42->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        RS_charger_TblWidget->setItem(1, 4, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RS_charger_TblWidget->setItem(1, 5, __qtablewidgetitem43);
        RS_charger_TblWidget->setObjectName(QString::fromUtf8("RS_charger_TblWidget"));
        sizePolicy5.setHeightForWidth(RS_charger_TblWidget->sizePolicy().hasHeightForWidth());
        RS_charger_TblWidget->setSizePolicy(sizePolicy5);
        RS_charger_TblWidget->setMinimumSize(QSize(0, 31));
        RS_charger_TblWidget->setMaximumSize(QSize(16777215, 60));
        RS_charger_TblWidget->setStyleSheet(QString::fromUtf8(""));
        RS_charger_TblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RS_charger_TblWidget->setTabKeyNavigation(true);
        RS_charger_TblWidget->setProperty("showDropIndicator", QVariant(true));
        RS_charger_TblWidget->horizontalHeader()->setVisible(false);
        RS_charger_TblWidget->horizontalHeader()->setDefaultSectionSize(120);
        RS_charger_TblWidget->verticalHeader()->setVisible(false);
        RS_charger_TblWidget->verticalHeader()->setDefaultSectionSize(29);
        RS_charger_TblWidget->verticalHeader()->setHighlightSections(true);

        gridLayout_12->addWidget(RS_charger_TblWidget, 2, 0, 1, 1);

        ES_GpBox = new QGroupBox(test_power_Page);
        ES_GpBox->setObjectName(QString::fromUtf8("ES_GpBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(ES_GpBox->sizePolicy().hasHeightForWidth());
        ES_GpBox->setSizePolicy(sizePolicy7);
        ES_GpBox->setMinimumSize(QSize(0, 180));
        ES_GpBox->setMaximumSize(QSize(16777215, 180));
        ES_GpBox->setFont(font);
        gridLayout = new QGridLayout(ES_GpBox);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ES_value_GpBox = new QGroupBox(ES_GpBox);
        ES_value_GpBox->setObjectName(QString::fromUtf8("ES_value_GpBox"));
        sizePolicy.setHeightForWidth(ES_value_GpBox->sizePolicy().hasHeightForWidth());
        ES_value_GpBox->setSizePolicy(sizePolicy);
        ES_value_GpBox->setMinimumSize(QSize(0, 73));
        ES_value_GpBox->setMaximumSize(QSize(165, 216));
        ES_value_GpBox->setFont(font);
        ES_value_GpBox->setStyleSheet(QString::fromUtf8(" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     padding: 0 3px;\n"
"	 color: rgb(255, 255, 255);\n"
" }\n"
"\n"
" QGroupBox {\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    border-radius: 5px;\n"
"    margin-top: 0ex; /* leave space at the top for the title */\n"
"   background-color: rgba(12, 153, 134, 255);\n"
"\n"
" }\n"
""));
        ES_value_GpBox->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        gridLayout_23 = new QGridLayout(ES_value_GpBox);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setHorizontalSpacing(10);
        gridLayout_23->setVerticalSpacing(0);
        gridLayout_23->setContentsMargins(0, 10, 2, 0);
        ES_PE_Label = new QLabel(ES_value_GpBox);
        ES_PE_Label->setObjectName(QString::fromUtf8("ES_PE_Label"));
        ES_PE_Label->setFont(font);
        ES_PE_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_23->addWidget(ES_PE_Label, 0, 0, 1, 1);

        ES_TE_LnEdit = new QLineEdit(ES_value_GpBox);
        ES_TE_LnEdit->setObjectName(QString::fromUtf8("ES_TE_LnEdit"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial Narrow"));
        font4.setPointSize(10);
        ES_TE_LnEdit->setFont(font4);

        gridLayout_23->addWidget(ES_TE_LnEdit, 2, 1, 1, 1);

        ES_TE_Label = new QLabel(ES_value_GpBox);
        ES_TE_Label->setObjectName(QString::fromUtf8("ES_TE_Label"));
        ES_TE_Label->setFont(font);
        ES_TE_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_23->addWidget(ES_TE_Label, 2, 0, 1, 1);

        ES_PE_LnEdit = new QLineEdit(ES_value_GpBox);
        ES_PE_LnEdit->setObjectName(QString::fromUtf8("ES_PE_LnEdit"));
        ES_PE_LnEdit->setFont(font4);

        gridLayout_23->addWidget(ES_PE_LnEdit, 0, 1, 1, 1);

        ES_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_23->addItem(ES_HlSpacer, 0, 2, 1, 1);

        ES_insertForm_PsBtn = new QPushButton(ES_value_GpBox);
        ES_insertForm_PsBtn->setObjectName(QString::fromUtf8("ES_insertForm_PsBtn"));
        ES_insertForm_PsBtn->setFont(font1);

        gridLayout_23->addWidget(ES_insertForm_PsBtn, 3, 1, 1, 1);


        gridLayout->addWidget(ES_value_GpBox, 0, 3, 1, 1);

        ES_TbWidget = new QTabWidget(ES_GpBox);
        ES_TbWidget->setObjectName(QString::fromUtf8("ES_TbWidget"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(ES_TbWidget->sizePolicy().hasHeightForWidth());
        ES_TbWidget->setSizePolicy(sizePolicy8);
        ES_TbWidget->setMinimumSize(QSize(369, 180));
        ES_TbWidget->setMaximumSize(QSize(16777215, 225));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial Narrow"));
        font5.setPointSize(11);
        ES_TbWidget->setFont(font5);
        ES_TbWidget->setLayoutDirection(Qt::LeftToRight);
        ES_TbWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab \n"
"{\n"
"/*\n"
"   width: 151px;\n"
"	border:1px solid;\n"
"	border-color:rgb(0, 65, 100);  \n"
"	background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #eeeeee, stop: 1 gray);\n"
"	border-top-left-radius:10px;\n"
"	border-top-right-radius:10px;\n"
"    padding:3px;\n"
"*/\n"
"    width:270px;\n"
"	border-top-left-radius:10px;\n"
"	border-top-right-radius:10px;\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    background-color: rgba(12, 153, 134, 255);\n"
"\n"
"      padding:2px;\n"
"}\n"
"\n"
"\n"
"QTabBar::tab:!selected\n"
"{   \n"
"	margin-top: 5px;\n"
"}"));
        ES_TbWidget->setTabPosition(QTabWidget::North);
        ES_TbWidget->setTabShape(QTabWidget::Rounded);
        ES_TbWidget->setIconSize(QSize(16, 16));
        ES_PE_tab = new QWidget();
        ES_PE_tab->setObjectName(QString::fromUtf8("ES_PE_tab"));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(ES_PE_tab->sizePolicy().hasHeightForWidth());
        ES_PE_tab->setSizePolicy(sizePolicy9);
        ES_PE_tab->setLayoutDirection(Qt::LeftToRight);
        gridLayout_18 = new QGridLayout(ES_PE_tab);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        ES_PE_Frame = new QFrame(ES_PE_tab);
        ES_PE_Frame->setObjectName(QString::fromUtf8("ES_PE_Frame"));
        sizePolicy3.setHeightForWidth(ES_PE_Frame->sizePolicy().hasHeightForWidth());
        ES_PE_Frame->setSizePolicy(sizePolicy3);
        ES_PE_Frame->setMinimumSize(QSize(0, 5));
        ES_PE_Frame->setMaximumSize(QSize(16777215, 25));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial Narrow"));
        ES_PE_Frame->setFont(font6);
        ES_PE_Frame->setStyleSheet(QString::fromUtf8("#ES_PE_Frame\n"
"{\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
""));
        ES_PE_Frame->setFrameShape(QFrame::StyledPanel);
        ES_PE_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(ES_PE_Frame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ES_PE_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(ES_PE_HlSpacer, 0, 0, 1, 1);

        ES_PE_zoomIn_PsBtn = new QPushButton(ES_PE_Frame);
        ES_PE_zoomIn_PsBtn->setObjectName(QString::fromUtf8("ES_PE_zoomIn_PsBtn"));
        ES_PE_zoomIn_PsBtn->setFont(font6);

        gridLayout_3->addWidget(ES_PE_zoomIn_PsBtn, 0, 3, 1, 1);

        ES_PE_zoomOut_PsBtn = new QPushButton(ES_PE_Frame);
        ES_PE_zoomOut_PsBtn->setObjectName(QString::fromUtf8("ES_PE_zoomOut_PsBtn"));
        ES_PE_zoomOut_PsBtn->setFont(font6);

        gridLayout_3->addWidget(ES_PE_zoomOut_PsBtn, 0, 1, 1, 1);


        gridLayout_18->addWidget(ES_PE_Frame, 0, 0, 1, 1);

        ES_PE_QwtPlot = new QwtPlot(ES_PE_tab);
        ES_PE_QwtPlot->setObjectName(QString::fromUtf8("ES_PE_QwtPlot"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(ES_PE_QwtPlot->sizePolicy().hasHeightForWidth());
        ES_PE_QwtPlot->setSizePolicy(sizePolicy10);
        ES_PE_QwtPlot->setMinimumSize(QSize(0, 120));
        ES_PE_QwtPlot->setMaximumSize(QSize(16777215, 120));
        ES_PE_QwtPlot->setFont(font6);
        ES_PE_QwtPlot->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(0, 0, 0);"));

        gridLayout_18->addWidget(ES_PE_QwtPlot, 1, 0, 1, 1);

        ES_TbWidget->addTab(ES_PE_tab, QString());
        ES_wave_tab = new QWidget();
        ES_wave_tab->setObjectName(QString::fromUtf8("ES_wave_tab"));
        gridLayout_20 = new QGridLayout(ES_wave_tab);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        ES_wave_QwtPlot = new QwtPlot(ES_wave_tab);
        ES_wave_QwtPlot->setObjectName(QString::fromUtf8("ES_wave_QwtPlot"));
        sizePolicy10.setHeightForWidth(ES_wave_QwtPlot->sizePolicy().hasHeightForWidth());
        ES_wave_QwtPlot->setSizePolicy(sizePolicy10);
        ES_wave_QwtPlot->setMinimumSize(QSize(0, 0));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Kalinga"));
        ES_wave_QwtPlot->setFont(font7);
        ES_wave_QwtPlot->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(0, 0, 0);"));

        gridLayout_20->addWidget(ES_wave_QwtPlot, 0, 0, 1, 1);

        ES_TbWidget->addTab(ES_wave_tab, QString());

        gridLayout->addWidget(ES_TbWidget, 0, 2, 1, 1);


        gridLayout_12->addWidget(ES_GpBox, 0, 0, 1, 3);

        ES_standard_Frame = new QFrame(test_power_Page);
        ES_standard_Frame->setObjectName(QString::fromUtf8("ES_standard_Frame"));
        sizePolicy3.setHeightForWidth(ES_standard_Frame->sizePolicy().hasHeightForWidth());
        ES_standard_Frame->setSizePolicy(sizePolicy3);
        ES_standard_Frame->setMinimumSize(QSize(0, 25));
        ES_standard_Frame->setMaximumSize(QSize(16777215, 30));
        ES_standard_Frame->setFont(font3);
        ES_standard_Frame->setStyleSheet(QString::fromUtf8("#ES_standard_Frame\n"
"{\n"
" border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"}\n"
"\n"
"\n"
"\n"
""));
        ES_standard_Frame->setFrameShape(QFrame::StyledPanel);
        ES_standard_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_28 = new QGridLayout(ES_standard_Frame);
        gridLayout_28->setSpacing(0);
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        ES_standard_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_28->addItem(ES_standard_HlSpacer, 0, 1, 1, 1);

        ES_standard_Label = new QLabel(ES_standard_Frame);
        ES_standard_Label->setObjectName(QString::fromUtf8("ES_standard_Label"));
        QSizePolicy sizePolicy11(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(ES_standard_Label->sizePolicy().hasHeightForWidth());
        ES_standard_Label->setSizePolicy(sizePolicy11);
        ES_standard_Label->setMaximumSize(QSize(16777215, 25));
        ES_standard_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_28->addWidget(ES_standard_Label, 0, 0, 1, 1);


        gridLayout_12->addWidget(ES_standard_Frame, 9, 0, 1, 3);

        BMS_RD_TblWidget = new QTableWidget(test_power_Page);
        if (BMS_RD_TblWidget->columnCount() < 6)
            BMS_RD_TblWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        BMS_RD_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        BMS_RD_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        BMS_RD_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        BMS_RD_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        BMS_RD_TblWidget->setHorizontalHeaderItem(4, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        BMS_RD_TblWidget->setHorizontalHeaderItem(5, __qtablewidgetitem49);
        if (BMS_RD_TblWidget->rowCount() < 4)
            BMS_RD_TblWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        BMS_RD_TblWidget->setVerticalHeaderItem(0, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        BMS_RD_TblWidget->setVerticalHeaderItem(1, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        BMS_RD_TblWidget->setVerticalHeaderItem(2, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        BMS_RD_TblWidget->setVerticalHeaderItem(3, __qtablewidgetitem53);
        QFont font8;
        font8.setBold(false);
        font8.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem54->setFont(font8);
        __qtablewidgetitem54->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(0, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem55->setFont(font8);
        __qtablewidgetitem55->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(0, 1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem56->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(0, 2, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem57->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(0, 3, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem58->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(0, 4, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem59->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(0, 5, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem60->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(1, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem61->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(1, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem62->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(1, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem63->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(1, 3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem64->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(1, 4, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem65->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(1, 5, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem66->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(2, 0, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem67->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(2, 1, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem68->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(2, 2, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem69->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(2, 3, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem70->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(2, 4, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem71->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(2, 5, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem72->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(3, 0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem73->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(3, 1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem74->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BMS_RD_TblWidget->setItem(3, 2, __qtablewidgetitem74);
        BMS_RD_TblWidget->setObjectName(QString::fromUtf8("BMS_RD_TblWidget"));
        QSizePolicy sizePolicy12(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(BMS_RD_TblWidget->sizePolicy().hasHeightForWidth());
        BMS_RD_TblWidget->setSizePolicy(sizePolicy12);
        BMS_RD_TblWidget->setMinimumSize(QSize(0, 125));
        BMS_RD_TblWidget->setMaximumSize(QSize(16777215, 127));
        BMS_RD_TblWidget->setStyleSheet(QString::fromUtf8(""));
        BMS_RD_TblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        BMS_RD_TblWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        BMS_RD_TblWidget->horizontalHeader()->setVisible(false);
        BMS_RD_TblWidget->horizontalHeader()->setDefaultSectionSize(120);
        BMS_RD_TblWidget->horizontalHeader()->setHighlightSections(true);
        BMS_RD_TblWidget->horizontalHeader()->setMinimumSectionSize(5);
        BMS_RD_TblWidget->verticalHeader()->setVisible(false);
        BMS_RD_TblWidget->verticalHeader()->setDefaultSectionSize(31);

        gridLayout_12->addWidget(BMS_RD_TblWidget, 8, 0, 1, 1);

        main_SkWidget->addWidget(test_power_Page);
        test_ripple_Page = new QWidget();
        test_ripple_Page->setObjectName(QString::fromUtf8("test_ripple_Page"));
        gridLayout_11 = new QGridLayout(test_ripple_Page);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        ripple_wave_QwtPlot = new QwtPlot(test_ripple_Page);
        ripple_wave_QwtPlot->setObjectName(QString::fromUtf8("ripple_wave_QwtPlot"));
        sizePolicy10.setHeightForWidth(ripple_wave_QwtPlot->sizePolicy().hasHeightForWidth());
        ripple_wave_QwtPlot->setSizePolicy(sizePolicy10);
        ripple_wave_QwtPlot->setMinimumSize(QSize(0, 0));
        ripple_wave_QwtPlot->setFont(font7);
        ripple_wave_QwtPlot->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(0, 0, 0);"));

        gridLayout_11->addWidget(ripple_wave_QwtPlot, 0, 0, 1, 1);

        RRF_ripple_Frame = new QFrame(test_ripple_Page);
        RRF_ripple_Frame->setObjectName(QString::fromUtf8("RRF_ripple_Frame"));
        sizePolicy3.setHeightForWidth(RRF_ripple_Frame->sizePolicy().hasHeightForWidth());
        RRF_ripple_Frame->setSizePolicy(sizePolicy3);
        RRF_ripple_Frame->setMinimumSize(QSize(0, 40));
        RRF_ripple_Frame->setMaximumSize(QSize(16777215, 40));
        RRF_ripple_Frame->setStyleSheet(QString::fromUtf8("#RRF_ripple_Frame{\n"
" border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"}"));
        RRF_ripple_Frame->setFrameShape(QFrame::StyledPanel);
        RRF_ripple_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(RRF_ripple_Frame);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        RRF_ripple_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(RRF_ripple_HlSpacer, 0, 2, 1, 1);

        RRF_ripple_chl_CbBox = new QComboBox(RRF_ripple_Frame);
        RRF_ripple_chl_CbBox->setObjectName(QString::fromUtf8("RRF_ripple_chl_CbBox"));
        RRF_ripple_chl_CbBox->setMinimumSize(QSize(60, 30));
        RRF_ripple_chl_CbBox->setFont(font3);
        RRF_ripple_chl_CbBox->setStyleSheet(QString::fromUtf8("\n"
"QScrollBar:vertical\n"
"{\n"
"	width:26px;\n"
"	background:rgba(0,0,0,10%);\n"
"    border-radius:4px;\n"
"}\n"
""));

        gridLayout_10->addWidget(RRF_ripple_chl_CbBox, 0, 4, 1, 1);

        RRF_ripple_chl_Label = new QLabel(RRF_ripple_Frame);
        RRF_ripple_chl_Label->setObjectName(QString::fromUtf8("RRF_ripple_chl_Label"));
        RRF_ripple_chl_Label->setFont(font3);
        RRF_ripple_chl_Label->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color: beige;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(12, 153, 134, 255);\n"
"\n"
""));

        gridLayout_10->addWidget(RRF_ripple_chl_Label, 0, 3, 1, 1);


        gridLayout_11->addWidget(RRF_ripple_Frame, 1, 0, 1, 1);

        RRF_ripple_TblWidget = new QTableWidget(test_ripple_Page);
        if (RRF_ripple_TblWidget->columnCount() < 3)
            RRF_ripple_TblWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        RRF_ripple_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        RRF_ripple_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        RRF_ripple_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem77);
        if (RRF_ripple_TblWidget->rowCount() < 2)
            RRF_ripple_TblWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        RRF_ripple_TblWidget->setVerticalHeaderItem(0, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        RRF_ripple_TblWidget->setVerticalHeaderItem(1, __qtablewidgetitem79);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem80->setFont(font8);
        __qtablewidgetitem80->setForeground(brush);
        __qtablewidgetitem80->setFlags(Qt::NoItemFlags);
        RRF_ripple_TblWidget->setItem(0, 0, __qtablewidgetitem80);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem81->setFont(font8);
        __qtablewidgetitem81->setForeground(brush1);
        __qtablewidgetitem81->setFlags(Qt::NoItemFlags);
        RRF_ripple_TblWidget->setItem(0, 1, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        __qtablewidgetitem82->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RRF_ripple_TblWidget->setItem(0, 2, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        __qtablewidgetitem83->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RRF_ripple_TblWidget->setItem(1, 0, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RRF_ripple_TblWidget->setItem(1, 1, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        RRF_ripple_TblWidget->setItem(1, 2, __qtablewidgetitem85);
        RRF_ripple_TblWidget->setObjectName(QString::fromUtf8("RRF_ripple_TblWidget"));
        sizePolicy3.setHeightForWidth(RRF_ripple_TblWidget->sizePolicy().hasHeightForWidth());
        RRF_ripple_TblWidget->setSizePolicy(sizePolicy3);
        RRF_ripple_TblWidget->setMinimumSize(QSize(455, 0));
        RRF_ripple_TblWidget->setStyleSheet(QString::fromUtf8(""));
        RRF_ripple_TblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RRF_ripple_TblWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        RRF_ripple_TblWidget->horizontalHeader()->setVisible(false);
        RRF_ripple_TblWidget->horizontalHeader()->setDefaultSectionSize(220);
        RRF_ripple_TblWidget->horizontalHeader()->setHighlightSections(true);
        RRF_ripple_TblWidget->verticalHeader()->setVisible(false);
        RRF_ripple_TblWidget->verticalHeader()->setDefaultSectionSize(43);

        gridLayout_11->addWidget(RRF_ripple_TblWidget, 2, 0, 1, 1);

        main_SkWidget->addWidget(test_ripple_Page);
        form_Page = new QWidget();
        form_Page->setObjectName(QString::fromUtf8("form_Page"));
        gridLayout_26 = new QGridLayout(form_Page);
        gridLayout_26->setSpacing(0);
        gridLayout_26->setContentsMargins(0, 0, 0, 0);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        from_information_TbWidget = new QTableWidget(form_Page);
        if (from_information_TbWidget->columnCount() < 4)
            from_information_TbWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        from_information_TbWidget->setHorizontalHeaderItem(0, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        from_information_TbWidget->setHorizontalHeaderItem(1, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        from_information_TbWidget->setHorizontalHeaderItem(2, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        from_information_TbWidget->setHorizontalHeaderItem(3, __qtablewidgetitem89);
        if (from_information_TbWidget->rowCount() < 13)
            from_information_TbWidget->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(0, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(1, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(2, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(3, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(4, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(5, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(6, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(7, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(8, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(9, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(10, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(11, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        from_information_TbWidget->setVerticalHeaderItem(12, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        from_information_TbWidget->setItem(0, 0, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        from_information_TbWidget->setItem(0, 1, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        from_information_TbWidget->setItem(0, 2, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        from_information_TbWidget->setItem(0, 3, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        from_information_TbWidget->setItem(1, 0, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        from_information_TbWidget->setItem(1, 1, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        from_information_TbWidget->setItem(1, 2, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        from_information_TbWidget->setItem(1, 3, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        from_information_TbWidget->setItem(2, 0, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        from_information_TbWidget->setItem(2, 1, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        from_information_TbWidget->setItem(2, 2, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        from_information_TbWidget->setItem(2, 3, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        from_information_TbWidget->setItem(3, 0, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        from_information_TbWidget->setItem(3, 1, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        from_information_TbWidget->setItem(3, 2, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        from_information_TbWidget->setItem(3, 3, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        from_information_TbWidget->setItem(4, 0, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        from_information_TbWidget->setItem(4, 1, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        from_information_TbWidget->setItem(4, 2, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        from_information_TbWidget->setItem(4, 3, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        from_information_TbWidget->setItem(5, 0, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        from_information_TbWidget->setItem(5, 1, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        from_information_TbWidget->setItem(5, 2, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        from_information_TbWidget->setItem(5, 3, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        from_information_TbWidget->setItem(6, 0, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        from_information_TbWidget->setItem(6, 1, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        from_information_TbWidget->setItem(6, 2, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        from_information_TbWidget->setItem(6, 3, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        from_information_TbWidget->setItem(7, 0, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        from_information_TbWidget->setItem(7, 1, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        from_information_TbWidget->setItem(7, 2, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        from_information_TbWidget->setItem(7, 3, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        from_information_TbWidget->setItem(8, 0, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        from_information_TbWidget->setItem(8, 1, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        from_information_TbWidget->setItem(9, 0, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        from_information_TbWidget->setItem(9, 1, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        from_information_TbWidget->setItem(9, 2, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        from_information_TbWidget->setItem(9, 3, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        from_information_TbWidget->setItem(10, 0, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        from_information_TbWidget->setItem(10, 1, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        from_information_TbWidget->setItem(10, 2, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        from_information_TbWidget->setItem(11, 0, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        from_information_TbWidget->setItem(11, 1, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        from_information_TbWidget->setItem(11, 2, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        __qtablewidgetitem147->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        from_information_TbWidget->setItem(12, 0, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        from_information_TbWidget->setItem(12, 1, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        __qtablewidgetitem149->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        from_information_TbWidget->setItem(12, 2, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        from_information_TbWidget->setItem(12, 3, __qtablewidgetitem150);
        from_information_TbWidget->setObjectName(QString::fromUtf8("from_information_TbWidget"));
        from_information_TbWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        from_information_TbWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        from_information_TbWidget->horizontalHeader()->setVisible(false);
        from_information_TbWidget->horizontalHeader()->setDefaultSectionSize(176);
        from_information_TbWidget->verticalHeader()->setVisible(false);

        gridLayout_26->addWidget(from_information_TbWidget, 5, 0, 1, 1);

        from_information_Frame = new QFrame(form_Page);
        from_information_Frame->setObjectName(QString::fromUtf8("from_information_Frame"));
        sizePolicy3.setHeightForWidth(from_information_Frame->sizePolicy().hasHeightForWidth());
        from_information_Frame->setSizePolicy(sizePolicy3);
        from_information_Frame->setMinimumSize(QSize(0, 30));
        from_information_Frame->setMaximumSize(QSize(16777215, 30));
        from_information_Frame->setFont(font3);
        from_information_Frame->setStyleSheet(QString::fromUtf8("#from_information_Frame\n"
"{\n"
" border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"}\n"
"\n"
"\n"
"\n"
""));
        from_information_Frame->setFrameShape(QFrame::StyledPanel);
        from_information_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_21 = new QGridLayout(from_information_Frame);
        gridLayout_21->setSpacing(0);
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        from_clearFrom_PsBtn = new QPushButton(from_information_Frame);
        from_clearFrom_PsBtn->setObjectName(QString::fromUtf8("from_clearFrom_PsBtn"));

        gridLayout_21->addWidget(from_clearFrom_PsBtn, 0, 3, 1, 1);

        from_information_Label = new QLabel(from_information_Frame);
        from_information_Label->setObjectName(QString::fromUtf8("from_information_Label"));
        from_information_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_21->addWidget(from_information_Label, 0, 0, 1, 1);

        from_information_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(from_information_HlSpacer, 0, 1, 1, 1);

        from_buildForm_PsBtn = new QPushButton(from_information_Frame);
        from_buildForm_PsBtn->setObjectName(QString::fromUtf8("from_buildForm_PsBtn"));

        gridLayout_21->addWidget(from_buildForm_PsBtn, 0, 2, 1, 1);


        gridLayout_26->addWidget(from_information_Frame, 4, 0, 1, 3);

        from_error_Frame = new QFrame(form_Page);
        from_error_Frame->setObjectName(QString::fromUtf8("from_error_Frame"));
        sizePolicy3.setHeightForWidth(from_error_Frame->sizePolicy().hasHeightForWidth());
        from_error_Frame->setSizePolicy(sizePolicy3);
        from_error_Frame->setMinimumSize(QSize(0, 30));
        from_error_Frame->setMaximumSize(QSize(16777215, 30));
        from_error_Frame->setFont(font3);
        from_error_Frame->setStyleSheet(QString::fromUtf8("#from_error_Frame\n"
"{\n"
" border: 1px solid rgb(18, 220, 200);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"}\n"
"\n"
"\n"
"\n"
""));
        from_error_Frame->setFrameShape(QFrame::StyledPanel);
        from_error_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_25 = new QGridLayout(from_error_Frame);
        gridLayout_25->setSpacing(0);
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        from_error_Label = new QLabel(from_error_Frame);
        from_error_Label->setObjectName(QString::fromUtf8("from_error_Label"));
        from_error_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_25->addWidget(from_error_Label, 0, 0, 1, 1);

        from_error_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_25->addItem(from_error_HlSpacer, 0, 1, 1, 1);


        gridLayout_26->addWidget(from_error_Frame, 0, 0, 1, 2);

        form_error_TbWidget = new QTabWidget(form_Page);
        form_error_TbWidget->setObjectName(QString::fromUtf8("form_error_TbWidget"));
        sizePolicy3.setHeightForWidth(form_error_TbWidget->sizePolicy().hasHeightForWidth());
        form_error_TbWidget->setSizePolicy(sizePolicy3);
        form_error_TbWidget->setMinimumSize(QSize(0, 200));
        form_error_TbWidget->setMaximumSize(QSize(16777215, 200));
        form_error_TbWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab \n"
"{\n"
"    width:112px;\n"
"	border-top-left-radius:10px;\n"
"	border-top-right-radius:10px;\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"  background-color: rgba(12, 153, 134, 255);\n"
"\n"
"      padding:2px;\n"
"}\n"
"\n"
"\n"
"QTabBar::tab:!selected\n"
"{   \n"
"	margin-top: 5px;\n"
"}"));
        intuit_tab = new QWidget();
        intuit_tab->setObjectName(QString::fromUtf8("intuit_tab"));
        gridLayout_15 = new QGridLayout(intuit_tab);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        intuit_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(intuit_HlSpacer, 0, 2, 1, 1);

        intuit_Label = new QLabel(intuit_tab);
        intuit_Label->setObjectName(QString::fromUtf8("intuit_Label"));

        gridLayout_15->addWidget(intuit_Label, 0, 0, 1, 1);

        intuit_CkBox = new QCheckBox(intuit_tab);
        intuit_CkBox->setObjectName(QString::fromUtf8("intuit_CkBox"));

        gridLayout_15->addWidget(intuit_CkBox, 0, 1, 1, 1);

        form_error_TbWidget->addTab(intuit_tab, QString());
        operating_tab = new QWidget();
        operating_tab->setObjectName(QString::fromUtf8("operating_tab"));
        gridLayout_19 = new QGridLayout(operating_tab);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        operating_TblWidget = new QTableWidget(operating_tab);
        if (operating_TblWidget->columnCount() < 6)
            operating_TblWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        operating_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        operating_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        operating_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        operating_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        operating_TblWidget->setHorizontalHeaderItem(4, __qtablewidgetitem155);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        operating_TblWidget->setHorizontalHeaderItem(5, __qtablewidgetitem156);
        operating_TblWidget->setObjectName(QString::fromUtf8("operating_TblWidget"));
        operating_TblWidget->horizontalHeader()->setDefaultSectionSize(117);

        gridLayout_19->addWidget(operating_TblWidget, 0, 0, 1, 1);

        form_error_TbWidget->addTab(operating_tab, QString());
        load_tab = new QWidget();
        load_tab->setObjectName(QString::fromUtf8("load_tab"));
        gridLayout_24 = new QGridLayout(load_tab);
        gridLayout_24->setSpacing(0);
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        load_TblWidget = new QTableWidget(load_tab);
        if (load_TblWidget->columnCount() < 6)
            load_TblWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        load_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        load_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        load_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        load_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        load_TblWidget->setHorizontalHeaderItem(4, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        load_TblWidget->setHorizontalHeaderItem(5, __qtablewidgetitem162);
        load_TblWidget->setObjectName(QString::fromUtf8("load_TblWidget"));
        load_TblWidget->horizontalHeader()->setDefaultSectionSize(116);

        gridLayout_24->addWidget(load_TblWidget, 0, 0, 1, 1);

        form_error_TbWidget->addTab(load_tab, QString());
        payment = new QWidget();
        payment->setObjectName(QString::fromUtf8("payment"));
        gridLayout_29 = new QGridLayout(payment);
        gridLayout_29->setSpacing(0);
        gridLayout_29->setContentsMargins(0, 0, 0, 0);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        payment_TblWidget = new QTableWidget(payment);
        if (payment_TblWidget->columnCount() < 6)
            payment_TblWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        payment_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem163);
        QTableWidgetItem *__qtablewidgetitem164 = new QTableWidgetItem();
        payment_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem164);
        QTableWidgetItem *__qtablewidgetitem165 = new QTableWidgetItem();
        payment_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem165);
        QTableWidgetItem *__qtablewidgetitem166 = new QTableWidgetItem();
        payment_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem166);
        QTableWidgetItem *__qtablewidgetitem167 = new QTableWidgetItem();
        payment_TblWidget->setHorizontalHeaderItem(4, __qtablewidgetitem167);
        QTableWidgetItem *__qtablewidgetitem168 = new QTableWidgetItem();
        payment_TblWidget->setHorizontalHeaderItem(5, __qtablewidgetitem168);
        payment_TblWidget->setObjectName(QString::fromUtf8("payment_TblWidget"));
        payment_TblWidget->horizontalHeader()->setDefaultSectionSize(118);

        gridLayout_29->addWidget(payment_TblWidget, 0, 0, 1, 1);

        form_error_TbWidget->addTab(payment, QString());
        time_tab = new QWidget();
        time_tab->setObjectName(QString::fromUtf8("time_tab"));
        gridLayout_16 = new QGridLayout(time_tab);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        time_TblWidget = new QTableWidget(time_tab);
        if (time_TblWidget->columnCount() < 4)
            time_TblWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem169 = new QTableWidgetItem();
        time_TblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem169);
        QTableWidgetItem *__qtablewidgetitem170 = new QTableWidgetItem();
        time_TblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem170);
        QTableWidgetItem *__qtablewidgetitem171 = new QTableWidgetItem();
        time_TblWidget->setHorizontalHeaderItem(2, __qtablewidgetitem171);
        QTableWidgetItem *__qtablewidgetitem172 = new QTableWidgetItem();
        time_TblWidget->setHorizontalHeaderItem(3, __qtablewidgetitem172);
        time_TblWidget->setObjectName(QString::fromUtf8("time_TblWidget"));
        sizePolicy3.setHeightForWidth(time_TblWidget->sizePolicy().hasHeightForWidth());
        time_TblWidget->setSizePolicy(sizePolicy3);
        time_TblWidget->setMinimumSize(QSize(0, 170));
        time_TblWidget->setMaximumSize(QSize(16777215, 170));

        gridLayout_16->addWidget(time_TblWidget, 0, 0, 1, 1);

        form_error_TbWidget->addTab(time_tab, QString());
        overallClu_tab = new QWidget();
        overallClu_tab->setObjectName(QString::fromUtf8("overallClu_tab"));
        gridLayout_30 = new QGridLayout(overallClu_tab);
        gridLayout_30->setSpacing(6);
        gridLayout_30->setContentsMargins(11, 11, 11, 11);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        overallClu_Label = new QLabel(overallClu_tab);
        overallClu_Label->setObjectName(QString::fromUtf8("overallClu_Label"));

        gridLayout_30->addWidget(overallClu_Label, 0, 0, 1, 1);

        overallClu_CkBox = new QCheckBox(overallClu_tab);
        overallClu_CkBox->setObjectName(QString::fromUtf8("overallClu_CkBox"));

        gridLayout_30->addWidget(overallClu_CkBox, 0, 1, 1, 1);

        overallClu_HlSpacer = new QSpacerItem(585, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_30->addItem(overallClu_HlSpacer, 0, 2, 1, 1);

        form_error_TbWidget->addTab(overallClu_tab, QString());

        gridLayout_26->addWidget(form_error_TbWidget, 2, 0, 1, 1);

        main_SkWidget->addWidget(form_Page);
        serPort_Page = new QWidget();
        serPort_Page->setObjectName(QString::fromUtf8("serPort_Page"));
        gridLayout_6 = new QGridLayout(serPort_Page);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        serPort_Rec_GbBox = new QGroupBox(serPort_Page);
        serPort_Rec_GbBox->setObjectName(QString::fromUtf8("serPort_Rec_GbBox"));
        sizePolicy9.setHeightForWidth(serPort_Rec_GbBox->sizePolicy().hasHeightForWidth());
        serPort_Rec_GbBox->setSizePolicy(sizePolicy9);
        serPort_Rec_GbBox->setStyleSheet(QString::fromUtf8(" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color: rgb(255, 255, 255);\n"
"\n"
"\n"
" }\n"
"\n"
" QGroupBox {\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    border-radius: 5px;\n"
"    margin-top: 0ex; /* leave space at the top for the title */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                     stop:0 rgba(7, 85, 75, 255),\n"
"                     stop:1 rgba(10, 100, 75, 255));\n"
" }\n"
""));
        gridLayout_7 = new QGridLayout(serPort_Rec_GbBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(5, 5, 5, 5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        serPort_Rec_TxEdit = new QTextEdit(serPort_Rec_GbBox);
        serPort_Rec_TxEdit->setObjectName(QString::fromUtf8("serPort_Rec_TxEdit"));
        sizePolicy8.setHeightForWidth(serPort_Rec_TxEdit->sizePolicy().hasHeightForWidth());
        serPort_Rec_TxEdit->setSizePolicy(sizePolicy8);
        serPort_Rec_TxEdit->setReadOnly(true);

        gridLayout_7->addWidget(serPort_Rec_TxEdit, 1, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(200, 36, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        serPort_CleanRec_PsBtn = new QPushButton(serPort_Rec_GbBox);
        serPort_CleanRec_PsBtn->setObjectName(QString::fromUtf8("serPort_CleanRec_PsBtn"));

        gridLayout_7->addWidget(serPort_CleanRec_PsBtn, 0, 0, 1, 1);


        gridLayout_6->addWidget(serPort_Rec_GbBox, 1, 0, 1, 1);

        serPort_send_GpBox = new QGroupBox(serPort_Page);
        serPort_send_GpBox->setObjectName(QString::fromUtf8("serPort_send_GpBox"));
        sizePolicy9.setHeightForWidth(serPort_send_GpBox->sizePolicy().hasHeightForWidth());
        serPort_send_GpBox->setSizePolicy(sizePolicy9);
        serPort_send_GpBox->setMinimumSize(QSize(420, 0));
        serPort_send_GpBox->setMaximumSize(QSize(420, 16777215));
        serPort_send_GpBox->setStyleSheet(QString::fromUtf8(" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color: rgb(255, 255, 255);\n"
"\n"
"\n"
" }\n"
"\n"
" QGroupBox {\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    border-radius: 5px;\n"
"    margin-top: 0ex; /* leave space at the top for the title */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                     stop:0 rgba(7, 85, 75, 255),\n"
"                     stop:1 rgba(10, 100, 75, 255));\n"
" }\n"
""));
        gridLayout_8 = new QGridLayout(serPort_send_GpBox);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(5, 5, 5, 0);
        serPort_SP_GpBox = new QGroupBox(serPort_send_GpBox);
        serPort_SP_GpBox->setObjectName(QString::fromUtf8("serPort_SP_GpBox"));
        sizePolicy10.setHeightForWidth(serPort_SP_GpBox->sizePolicy().hasHeightForWidth());
        serPort_SP_GpBox->setSizePolicy(sizePolicy10);
        serPort_SP_GpBox->setMinimumSize(QSize(0, 215));
        serPort_SP_GpBox->setMaximumSize(QSize(16777215, 220));
        serPort_SP_GpBox->setStyleSheet(QString::fromUtf8(" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color: rgb(255, 255, 255);\n"
"\n"
"\n"
" }\n"
"\n"
" QGroupBox {\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                     stop:0 rgba(7, 85, 75, 255),\n"
"                     stop:1 rgba(10, 100, 75, 255));\n"
" }\n"
""));
        gridLayout_17 = new QGridLayout(serPort_SP_GpBox);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 12, 0, 0);
        serPort_read_SP_PsBtn = new QPushButton(serPort_SP_GpBox);
        serPort_read_SP_PsBtn->setObjectName(QString::fromUtf8("serPort_read_SP_PsBtn"));

        gridLayout_17->addWidget(serPort_read_SP_PsBtn, 2, 2, 1, 1);

        serPort_write_SP_PsBtn = new QPushButton(serPort_SP_GpBox);
        serPort_write_SP_PsBtn->setObjectName(QString::fromUtf8("serPort_write_SP_PsBtn"));

        gridLayout_17->addWidget(serPort_write_SP_PsBtn, 2, 1, 1, 1);

        serPort_SP_HlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(serPort_SP_HlSpacer, 2, 0, 1, 1);

        serPort_SP_TabWidget = new QTableWidget(serPort_SP_GpBox);
        if (serPort_SP_TabWidget->columnCount() < 4)
            serPort_SP_TabWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem173 = new QTableWidgetItem();
        serPort_SP_TabWidget->setHorizontalHeaderItem(0, __qtablewidgetitem173);
        QTableWidgetItem *__qtablewidgetitem174 = new QTableWidgetItem();
        serPort_SP_TabWidget->setHorizontalHeaderItem(1, __qtablewidgetitem174);
        QTableWidgetItem *__qtablewidgetitem175 = new QTableWidgetItem();
        serPort_SP_TabWidget->setHorizontalHeaderItem(2, __qtablewidgetitem175);
        QTableWidgetItem *__qtablewidgetitem176 = new QTableWidgetItem();
        serPort_SP_TabWidget->setHorizontalHeaderItem(3, __qtablewidgetitem176);
        if (serPort_SP_TabWidget->rowCount() < 5)
            serPort_SP_TabWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem177 = new QTableWidgetItem();
        serPort_SP_TabWidget->setVerticalHeaderItem(0, __qtablewidgetitem177);
        QTableWidgetItem *__qtablewidgetitem178 = new QTableWidgetItem();
        serPort_SP_TabWidget->setVerticalHeaderItem(1, __qtablewidgetitem178);
        QTableWidgetItem *__qtablewidgetitem179 = new QTableWidgetItem();
        serPort_SP_TabWidget->setVerticalHeaderItem(2, __qtablewidgetitem179);
        QTableWidgetItem *__qtablewidgetitem180 = new QTableWidgetItem();
        serPort_SP_TabWidget->setVerticalHeaderItem(3, __qtablewidgetitem180);
        QTableWidgetItem *__qtablewidgetitem181 = new QTableWidgetItem();
        serPort_SP_TabWidget->setVerticalHeaderItem(4, __qtablewidgetitem181);
        QTableWidgetItem *__qtablewidgetitem182 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(0, 0, __qtablewidgetitem182);
        QTableWidgetItem *__qtablewidgetitem183 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(0, 1, __qtablewidgetitem183);
        QTableWidgetItem *__qtablewidgetitem184 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(0, 2, __qtablewidgetitem184);
        QTableWidgetItem *__qtablewidgetitem185 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(0, 3, __qtablewidgetitem185);
        QTableWidgetItem *__qtablewidgetitem186 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(1, 0, __qtablewidgetitem186);
        QTableWidgetItem *__qtablewidgetitem187 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(1, 1, __qtablewidgetitem187);
        QTableWidgetItem *__qtablewidgetitem188 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(1, 2, __qtablewidgetitem188);
        QTableWidgetItem *__qtablewidgetitem189 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(1, 3, __qtablewidgetitem189);
        QTableWidgetItem *__qtablewidgetitem190 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(2, 0, __qtablewidgetitem190);
        QTableWidgetItem *__qtablewidgetitem191 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(2, 1, __qtablewidgetitem191);
        QTableWidgetItem *__qtablewidgetitem192 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(2, 2, __qtablewidgetitem192);
        QTableWidgetItem *__qtablewidgetitem193 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(2, 3, __qtablewidgetitem193);
        QTableWidgetItem *__qtablewidgetitem194 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(3, 0, __qtablewidgetitem194);
        QTableWidgetItem *__qtablewidgetitem195 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(3, 1, __qtablewidgetitem195);
        QTableWidgetItem *__qtablewidgetitem196 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(3, 2, __qtablewidgetitem196);
        QTableWidgetItem *__qtablewidgetitem197 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(3, 3, __qtablewidgetitem197);
        QTableWidgetItem *__qtablewidgetitem198 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(4, 0, __qtablewidgetitem198);
        QTableWidgetItem *__qtablewidgetitem199 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(4, 1, __qtablewidgetitem199);
        QTableWidgetItem *__qtablewidgetitem200 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(4, 2, __qtablewidgetitem200);
        QTableWidgetItem *__qtablewidgetitem201 = new QTableWidgetItem();
        serPort_SP_TabWidget->setItem(4, 3, __qtablewidgetitem201);
        serPort_SP_TabWidget->setObjectName(QString::fromUtf8("serPort_SP_TabWidget"));
        sizePolicy3.setHeightForWidth(serPort_SP_TabWidget->sizePolicy().hasHeightForWidth());
        serPort_SP_TabWidget->setSizePolicy(sizePolicy3);
        serPort_SP_TabWidget->setMinimumSize(QSize(0, 157));
        serPort_SP_TabWidget->setMaximumSize(QSize(16777215, 157));
        serPort_SP_TabWidget->horizontalHeader()->setVisible(false);
        serPort_SP_TabWidget->horizontalHeader()->setDefaultSectionSize(101);
        serPort_SP_TabWidget->horizontalHeader()->setMinimumSectionSize(19);
        serPort_SP_TabWidget->verticalHeader()->setVisible(false);
        serPort_SP_TabWidget->verticalHeader()->setDefaultSectionSize(31);

        gridLayout_17->addWidget(serPort_SP_TabWidget, 1, 0, 1, 5);


        gridLayout_8->addWidget(serPort_SP_GpBox, 5, 0, 1, 11);

        serPort_Send_TxEdit = new QTextEdit(serPort_send_GpBox);
        serPort_Send_TxEdit->setObjectName(QString::fromUtf8("serPort_Send_TxEdit"));
        sizePolicy.setHeightForWidth(serPort_Send_TxEdit->sizePolicy().hasHeightForWidth());
        serPort_Send_TxEdit->setSizePolicy(sizePolicy);
        serPort_Send_TxEdit->setMinimumSize(QSize(200, 160));
        serPort_Send_TxEdit->setMaximumSize(QSize(200, 155));
        serPort_Send_TxEdit->setReadOnly(false);

        gridLayout_8->addWidget(serPort_Send_TxEdit, 3, 0, 1, 1);

        serPort_shortcut_GpBox = new QGroupBox(serPort_send_GpBox);
        serPort_shortcut_GpBox->setObjectName(QString::fromUtf8("serPort_shortcut_GpBox"));
        sizePolicy.setHeightForWidth(serPort_shortcut_GpBox->sizePolicy().hasHeightForWidth());
        serPort_shortcut_GpBox->setSizePolicy(sizePolicy);
        serPort_shortcut_GpBox->setMinimumSize(QSize(202, 170));
        serPort_shortcut_GpBox->setMaximumSize(QSize(210, 170));
        serPort_shortcut_GpBox->setStyleSheet(QString::fromUtf8(" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color: rgb(255, 255, 255);\n"
"\n"
"\n"
" }\n"
"\n"
"\n"
" QGroupBox {\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    border-radius: 5px;\n"
"    margin-top: 3ex; /* leave space at the top for the title */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                     stop:0 rgba(7, 85, 75, 255),\n"
"                     stop:1 rgba(10, 100, 75, 255));\n"
" }\n"
""));
        gridLayout_4 = new QGridLayout(serPort_shortcut_GpBox);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 18, 0, 0);
        serPort_EB_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_EB_PsBtn->setObjectName(QString::fromUtf8("serPort_EB_PsBtn"));

        gridLayout_4->addWidget(serPort_EB_PsBtn, 4, 4, 1, 1);

        serPort_ME_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_ME_PsBtn->setObjectName(QString::fromUtf8("serPort_ME_PsBtn"));

        gridLayout_4->addWidget(serPort_ME_PsBtn, 2, 2, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_17, 1, 7, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_16, 1, 0, 1, 1);

        serPort_RS_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_RS_PsBtn->setObjectName(QString::fromUtf8("serPort_RS_PsBtn"));

        gridLayout_4->addWidget(serPort_RS_PsBtn, 2, 4, 1, 1);

        serPort_AV_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_AV_PsBtn->setObjectName(QString::fromUtf8("serPort_AV_PsBtn"));
        serPort_AV_PsBtn->setEnabled(false);

        gridLayout_4->addWidget(serPort_AV_PsBtn, 4, 2, 1, 1);

        serPort_RP_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_RP_PsBtn->setObjectName(QString::fromUtf8("serPort_RP_PsBtn"));

        gridLayout_4->addWidget(serPort_RP_PsBtn, 1, 2, 1, 1);

        serPort_RSM_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_RSM_PsBtn->setObjectName(QString::fromUtf8("serPort_RSM_PsBtn"));

        gridLayout_4->addWidget(serPort_RSM_PsBtn, 1, 4, 1, 1);

        serPort_RBAT_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_RBAT_PsBtn->setObjectName(QString::fromUtf8("serPort_RBAT_PsBtn"));

        gridLayout_4->addWidget(serPort_RBAT_PsBtn, 3, 2, 1, 1);

        serPort_RD_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_RD_PsBtn->setObjectName(QString::fromUtf8("serPort_RD_PsBtn"));

        gridLayout_4->addWidget(serPort_RD_PsBtn, 3, 4, 1, 1);

        serPort_RRF_PsBtn = new QPushButton(serPort_shortcut_GpBox);
        serPort_RRF_PsBtn->setObjectName(QString::fromUtf8("serPort_RRF_PsBtn"));

        gridLayout_4->addWidget(serPort_RRF_PsBtn, 5, 2, 1, 1);


        gridLayout_8->addWidget(serPort_shortcut_GpBox, 3, 7, 1, 4);

        serPort_Send_PsBtn = new QPushButton(serPort_send_GpBox);
        serPort_Send_PsBtn->setObjectName(QString::fromUtf8("serPort_Send_PsBtn"));
        serPort_Send_PsBtn->setEnabled(false);
        sizePolicy2.setHeightForWidth(serPort_Send_PsBtn->sizePolicy().hasHeightForWidth());
        serPort_Send_PsBtn->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(serPort_Send_PsBtn, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        serPort_CR_CkBox = new QCheckBox(serPort_send_GpBox);
        serPort_CR_CkBox->setObjectName(QString::fromUtf8("serPort_CR_CkBox"));
        serPort_CR_CkBox->setMaximumSize(QSize(40, 24));
        serPort_CR_CkBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_8->addWidget(serPort_CR_CkBox, 0, 9, 1, 1);

        serPort_CleanSend_PsBtn = new QPushButton(serPort_send_GpBox);
        serPort_CleanSend_PsBtn->setObjectName(QString::fromUtf8("serPort_CleanSend_PsBtn"));
        sizePolicy2.setHeightForWidth(serPort_CleanSend_PsBtn->sizePolicy().hasHeightForWidth());
        serPort_CleanSend_PsBtn->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(serPort_CleanSend_PsBtn, 0, 1, 1, 1);

        serPort_LF_CkBox = new QCheckBox(serPort_send_GpBox);
        serPort_LF_CkBox->setObjectName(QString::fromUtf8("serPort_LF_CkBox"));
        serPort_LF_CkBox->setMaximumSize(QSize(35, 20));
        serPort_LF_CkBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_8->addWidget(serPort_LF_CkBox, 0, 10, 1, 1);


        gridLayout_6->addWidget(serPort_send_GpBox, 1, 1, 1, 2);

        serPort_Settings_GpBox = new QGroupBox(serPort_Page);
        serPort_Settings_GpBox->setObjectName(QString::fromUtf8("serPort_Settings_GpBox"));
        serPort_Settings_GpBox->setStyleSheet(QString::fromUtf8(" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color: rgb(255, 255, 255);\n"
"\n"
"\n"
" }\n"
"\n"
" QGroupBox {\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    border-radius: 5px;\n"
"    margin-top: 0ex; /* leave space at the top for the title */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                     stop:0 rgba(7, 85, 75, 255),\n"
"                     stop:1 rgba(10, 100, 75, 255));\n"
" }\n"
""));
        gridLayout_5 = new QGridLayout(serPort_Settings_GpBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        serPort_portName_Label = new QLabel(serPort_Settings_GpBox);
        serPort_portName_Label->setObjectName(QString::fromUtf8("serPort_portName_Label"));
        QSizePolicy sizePolicy13(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(serPort_portName_Label->sizePolicy().hasHeightForWidth());
        serPort_portName_Label->setSizePolicy(sizePolicy13);
        serPort_portName_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(serPort_portName_Label, 0, 0, 1, 1);

        serPort_portName_CbBox = new QComboBox(serPort_Settings_GpBox);
        serPort_portName_CbBox->setObjectName(QString::fromUtf8("serPort_portName_CbBox"));

        gridLayout_5->addWidget(serPort_portName_CbBox, 0, 1, 1, 1);

        serPort_parity_Label = new QLabel(serPort_Settings_GpBox);
        serPort_parity_Label->setObjectName(QString::fromUtf8("serPort_parity_Label"));
        sizePolicy13.setHeightForWidth(serPort_parity_Label->sizePolicy().hasHeightForWidth());
        serPort_parity_Label->setSizePolicy(sizePolicy13);
        serPort_parity_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(serPort_parity_Label, 0, 4, 1, 1);

        serPort_parity_CbBox = new QComboBox(serPort_Settings_GpBox);
        serPort_parity_CbBox->setObjectName(QString::fromUtf8("serPort_parity_CbBox"));

        gridLayout_5->addWidget(serPort_parity_CbBox, 0, 5, 1, 1);

        serPort_baudRate_Label = new QLabel(serPort_Settings_GpBox);
        serPort_baudRate_Label->setObjectName(QString::fromUtf8("serPort_baudRate_Label"));
        sizePolicy13.setHeightForWidth(serPort_baudRate_Label->sizePolicy().hasHeightForWidth());
        serPort_baudRate_Label->setSizePolicy(sizePolicy13);
        serPort_baudRate_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(serPort_baudRate_Label, 0, 2, 1, 1);

        serPort_baudRate_CbBox = new QComboBox(serPort_Settings_GpBox);
        serPort_baudRate_CbBox->setObjectName(QString::fromUtf8("serPort_baudRate_CbBox"));

        gridLayout_5->addWidget(serPort_baudRate_CbBox, 0, 3, 1, 1);

        serPort_dataBit_Label = new QLabel(serPort_Settings_GpBox);
        serPort_dataBit_Label->setObjectName(QString::fromUtf8("serPort_dataBit_Label"));
        sizePolicy13.setHeightForWidth(serPort_dataBit_Label->sizePolicy().hasHeightForWidth());
        serPort_dataBit_Label->setSizePolicy(sizePolicy13);
        serPort_dataBit_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(serPort_dataBit_Label, 1, 0, 1, 1);

        serPort_dataBit_CbBox = new QComboBox(serPort_Settings_GpBox);
        serPort_dataBit_CbBox->setObjectName(QString::fromUtf8("serPort_dataBit_CbBox"));

        gridLayout_5->addWidget(serPort_dataBit_CbBox, 1, 1, 1, 1);

        serPort_stopBit_Label = new QLabel(serPort_Settings_GpBox);
        serPort_stopBit_Label->setObjectName(QString::fromUtf8("serPort_stopBit_Label"));
        sizePolicy13.setHeightForWidth(serPort_stopBit_Label->sizePolicy().hasHeightForWidth());
        serPort_stopBit_Label->setSizePolicy(sizePolicy13);
        serPort_stopBit_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(serPort_stopBit_Label, 1, 2, 1, 1);

        serPort_stopBit_CbBox = new QComboBox(serPort_Settings_GpBox);
        serPort_stopBit_CbBox->setObjectName(QString::fromUtf8("serPort_stopBit_CbBox"));

        gridLayout_5->addWidget(serPort_stopBit_CbBox, 1, 3, 1, 1);

        serPort_flowCtl_Label = new QLabel(serPort_Settings_GpBox);
        serPort_flowCtl_Label->setObjectName(QString::fromUtf8("serPort_flowCtl_Label"));
        sizePolicy13.setHeightForWidth(serPort_flowCtl_Label->sizePolicy().hasHeightForWidth());
        serPort_flowCtl_Label->setSizePolicy(sizePolicy13);
        serPort_flowCtl_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(serPort_flowCtl_Label, 1, 4, 1, 1);

        serPort_flowCtl_CbBox = new QComboBox(serPort_Settings_GpBox);
        serPort_flowCtl_CbBox->setObjectName(QString::fromUtf8("serPort_flowCtl_CbBox"));

        gridLayout_5->addWidget(serPort_flowCtl_CbBox, 1, 5, 1, 1);


        gridLayout_6->addWidget(serPort_Settings_GpBox, 0, 0, 1, 2);

        serPort_ctl_GpBox = new QGroupBox(serPort_Page);
        serPort_ctl_GpBox->setObjectName(QString::fromUtf8("serPort_ctl_GpBox"));
        serPort_ctl_GpBox->setStyleSheet(QString::fromUtf8(" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color: rgb(255, 255, 255);\n"
"\n"
"\n"
" }\n"
"\n"
" QGroupBox {\n"
"    border: 1px solid rgb(18, 220, 200);\n"
"    border-radius: 5px;\n"
"    margin-top: 0ex; /* leave space at the top for the title */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                     stop:0 rgba(7, 85, 75, 255),\n"
"                     stop:1 rgba(10, 100, 75, 255));\n"
" }\n"
""));
        gridLayout_9 = new QGridLayout(serPort_ctl_GpBox);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        serPort_Open_PsBtn = new QPushButton(serPort_ctl_GpBox);
        serPort_Open_PsBtn->setObjectName(QString::fromUtf8("serPort_Open_PsBtn"));

        gridLayout_9->addWidget(serPort_Open_PsBtn, 0, 0, 1, 1);

        serPort_Close_PsBtn = new QPushButton(serPort_ctl_GpBox);
        serPort_Close_PsBtn->setObjectName(QString::fromUtf8("serPort_Close_PsBtn"));
        serPort_Close_PsBtn->setEnabled(false);

        gridLayout_9->addWidget(serPort_Close_PsBtn, 0, 1, 1, 1);


        gridLayout_6->addWidget(serPort_ctl_GpBox, 0, 2, 1, 1);

        main_SkWidget->addWidget(serPort_Page);

        gridLayout_13->addWidget(main_SkWidget, 1, 0, 2, 1);

        sideBar_right_Page = new QWidget(MainWidget);
        sideBar_right_Page->setObjectName(QString::fromUtf8("sideBar_right_Page"));
        sizePolicy.setHeightForWidth(sideBar_right_Page->sizePolicy().hasHeightForWidth());
        sideBar_right_Page->setSizePolicy(sizePolicy);
        sideBar_right_Page->setMinimumSize(QSize(73, 0));
        sideBar_right_Page->setMaximumSize(QSize(75, 480));
        sideBar_right_Page->setFont(font);
        sideBar_right_Page->setStyleSheet(QString::fromUtf8("#sideBar_right_Page {\n"
"    border: 1px solid rgb(18, 220, 200);;\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(7, 85, 75, 255),\n"
"        stop:1 rgba(18, 220, 200, 255));\n"
"\n"
"\n"
"}\n"
"\n"
"#sideBar_right_Page QToolButton {\n"
"    padding-top: 30px;\n"
"    padding-bottom: 25px;\n"
"    border-top:3px solid qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(10, 10, 10, 255),\n"
"        stop:1 rgba(220, 220, 220, 255));\n"
"}\n"
"\n"
"\n"
"\n"
"#sideBar_right_Page QToolButton[current=\"true\"] {\n"
"    border-right: 3px solid rgb(170, 170, 170);\n"
"    border-left: 3px solid rgb(170, 170, 170);\n"
"    background: qlineargradient(spread:pad,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(1, 240, 220, 255),\n"
"        stop:1 rgba(17, 219, 195, 255));\n"
"}\n"
""));
        gridLayout_2 = new QGridLayout(sideBar_right_Page);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sideBar_TlBtn_3 = new QToolButton(sideBar_right_Page);
        sideBar_TlBtn_3->setObjectName(QString::fromUtf8("sideBar_TlBtn_3"));
        sizePolicy5.setHeightForWidth(sideBar_TlBtn_3->sizePolicy().hasHeightForWidth());
        sideBar_TlBtn_3->setSizePolicy(sizePolicy5);
        sideBar_TlBtn_3->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/from.png"), QSize(), QIcon::Normal, QIcon::Off);
        sideBar_TlBtn_3->setIcon(icon1);
        sideBar_TlBtn_3->setIconSize(QSize(71, 70));
        sideBar_TlBtn_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(sideBar_TlBtn_3, 4, 0, 1, 1);

        sideBar_TlBtn_2 = new QToolButton(sideBar_right_Page);
        sideBar_TlBtn_2->setObjectName(QString::fromUtf8("sideBar_TlBtn_2"));
        sizePolicy5.setHeightForWidth(sideBar_TlBtn_2->sizePolicy().hasHeightForWidth());
        sideBar_TlBtn_2->setSizePolicy(sizePolicy5);
        sideBar_TlBtn_2->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/ripple.png"), QSize(), QIcon::Normal, QIcon::Off);
        sideBar_TlBtn_2->setIcon(icon2);
        sideBar_TlBtn_2->setIconSize(QSize(70, 70));
        sideBar_TlBtn_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(sideBar_TlBtn_2, 2, 0, 1, 1);

        sideBar_TlBtn_4 = new QToolButton(sideBar_right_Page);
        sideBar_TlBtn_4->setObjectName(QString::fromUtf8("sideBar_TlBtn_4"));
        sizePolicy5.setHeightForWidth(sideBar_TlBtn_4->sizePolicy().hasHeightForWidth());
        sideBar_TlBtn_4->setSizePolicy(sizePolicy5);
        sideBar_TlBtn_4->setFont(font);
        sideBar_TlBtn_4->setStyleSheet(QString::fromUtf8("#sideBar_TlBtn_4 {\n"
"\n"
"    border-top:3px solid qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(10, 10, 10, 255),\n"
"        stop:1 rgba(220, 220, 220, 255));\n"
"   border-bottom:3px solid qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(10, 10, 10, 255),\n"
"        stop:1 rgba(220, 220, 220, 255));\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/settting.png"), QSize(), QIcon::Normal, QIcon::Off);
        sideBar_TlBtn_4->setIcon(icon3);
        sideBar_TlBtn_4->setIconSize(QSize(70, 70));
        sideBar_TlBtn_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(sideBar_TlBtn_4, 5, 0, 1, 1);

        sideBar_TlBtn_1 = new QToolButton(sideBar_right_Page);
        sideBar_TlBtn_1->setObjectName(QString::fromUtf8("sideBar_TlBtn_1"));
        sideBar_TlBtn_1->setEnabled(true);
        sizePolicy5.setHeightForWidth(sideBar_TlBtn_1->sizePolicy().hasHeightForWidth());
        sideBar_TlBtn_1->setSizePolicy(sizePolicy5);
        sideBar_TlBtn_1->setMaximumSize(QSize(16777214, 16777215));
        sideBar_TlBtn_1->setFont(font);
        sideBar_TlBtn_1->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pic/measuredValue.png"), QSize(), QIcon::Normal, QIcon::Off);
        sideBar_TlBtn_1->setIcon(icon4);
        sideBar_TlBtn_1->setIconSize(QSize(80, 80));
        sideBar_TlBtn_1->setAutoRepeatDelay(300);
        sideBar_TlBtn_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(sideBar_TlBtn_1, 0, 0, 1, 1);


        gridLayout_13->addWidget(sideBar_right_Page, 1, 1, 1, 1);

        start_PsBtn = new QPushButton(MainWidget);
        start_PsBtn->setObjectName(QString::fromUtf8("start_PsBtn"));
        sizePolicy.setHeightForWidth(start_PsBtn->sizePolicy().hasHeightForWidth());
        start_PsBtn->setSizePolicy(sizePolicy);
        start_PsBtn->setMinimumSize(QSize(0, 80));
        start_PsBtn->setMaximumSize(QSize(80, 80));
        start_PsBtn->setFont(font);
        start_PsBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image: url(:/pic/Btn_ON.png);\n"
"	color:black;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/pic/Btn_OFF.png);\n"
"	color:beige;\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	border-image: url(:/pic/Btn_OFF.png);\n"
"	color:black;\n"
"}\n"
"\n"
"QPushButton:pressed:checked\n"
"{\n"
"	border-image: url(:/pic/Btn_ON.png);\n"
"	color:beige;\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"     border: none;\n"
"}"));
        start_PsBtn->setCheckable(true);

        gridLayout_13->addWidget(start_PsBtn, 2, 1, 1, 1);


        retranslateUi(MainWidget);

        main_SkWidget->setCurrentIndex(2);
        ES_TbWidget->setCurrentIndex(0);
        form_error_TbWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "XL-902.\347\233\264\346\265\201\345\205\205\347\224\265\346\234\272\347\216\260\345\234\272\346\243\200\346\265\213\344\273\252", 0, QApplication::UnicodeUTF8));
        battery_Label->setText(QString());
        BMS_chargeMode_tag_Label->setText(QApplication::translate("MainWidget", "   \345\205\205\347\224\265\346\250\241\345\274\217: ", 0, QApplication::UnicodeUTF8));
        BMS_chargeMode_Label->setText(QApplication::translate("MainWidget", "\346\201\222\346\265\201", 0, QApplication::UnicodeUTF8));
        keyBoard_PsBtn->setText(QApplication::translate("MainWidget", "\351\224\256\347\233\230", 0, QApplication::UnicodeUTF8));
        runTime_LnEdit->setText(QApplication::translate("MainWidget", "00:00:00", 0, QApplication::UnicodeUTF8));
        runTime_Label->setText(QApplication::translate("MainWidget", "\350\277\220\350\241\214\346\227\266\351\227\264:  ", 0, QApplication::UnicodeUTF8));
        BMS_cntState_tag_Label->setText(QApplication::translate("MainWidget", "\351\223\276\346\216\245\347\212\266\346\200\201: ", 0, QApplication::UnicodeUTF8));
        BMS_cntState_Label->setText(QApplication::translate("MainWidget", "\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
        RS_charger_Lable->setText(QApplication::translate("MainWidget", "\345\205\205\347\224\265\346\234\272:", 0, QApplication::UnicodeUTF8));
        RD_BMS_Label->setText(QApplication::translate("MainWidget", "\347\224\265\345\212\250\350\275\246:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = ES_standard_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = ES_standard_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = ES_standard_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = ES_standard_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWidget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = ES_standard_TblWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWidget", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = ES_standard_TblWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWidget", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = ES_standard_TblWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWidget", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = ES_standard_TblWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWidget", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = ES_standard_TblWidget->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = ES_standard_TblWidget->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = ES_standard_TblWidget->isSortingEnabled();
        ES_standard_TblWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem10 = ES_standard_TblWidget->item(0, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWidget", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = ES_standard_TblWidget->item(0, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = ES_standard_TblWidget->item(0, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWidget", "\345\212\237\347\216\207(W)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = ES_standard_TblWidget->item(0, 3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = ES_standard_TblWidget->item(0, 4);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWidget", "\346\240\207\345\207\206\347\224\265\350\203\275(W\302\267h)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = ES_standard_TblWidget->item(0, 5);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = ES_standard_TblWidget->item(1, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWidget", "\347\224\265\346\265\201(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = ES_standard_TblWidget->item(1, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = ES_standard_TblWidget->item(1, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWidget", "\347\264\257\350\256\241\346\227\266\351\227\264(m)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = ES_standard_TblWidget->item(1, 3);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = ES_standard_TblWidget->item(1, 4);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWidget", "\350\242\253\346\243\200\347\224\265\350\203\275(W\302\267h)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = ES_standard_TblWidget->item(1, 5);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        ES_standard_TblWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem22 = RS_charger_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = RS_charger_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = RS_charger_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = RS_charger_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWidget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = RS_charger_TblWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWidget", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = RS_charger_TblWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWidget", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = RS_charger_TblWidget->verticalHeaderItem(0);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWidget", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = RS_charger_TblWidget->verticalHeaderItem(1);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWidget", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = RS_charger_TblWidget->isSortingEnabled();
        RS_charger_TblWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem30 = RS_charger_TblWidget->item(0, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWidget", "\347\224\265\345\216\213\350\276\223\345\207\272(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = RS_charger_TblWidget->item(0, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = RS_charger_TblWidget->item(0, 2);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWidget", "\346\234\200\351\253\230\350\276\223\345\207\272\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = RS_charger_TblWidget->item(0, 3);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = RS_charger_TblWidget->item(0, 4);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWidget", "\346\234\200\344\275\216\350\276\223\345\207\272\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = RS_charger_TblWidget->item(0, 5);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = RS_charger_TblWidget->item(1, 0);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWidget", "\347\224\265\346\265\201\350\276\223\345\207\272(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = RS_charger_TblWidget->item(1, 1);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = RS_charger_TblWidget->item(1, 2);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWidget", "\346\234\200\351\253\230\350\276\223\345\207\272\347\224\265\346\265\201(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = RS_charger_TblWidget->item(1, 3);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = RS_charger_TblWidget->item(1, 4);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWidget", "\350\276\223\345\207\272\346\200\273\347\224\265\350\203\275(kW\302\267h)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = RS_charger_TblWidget->item(1, 5);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        RS_charger_TblWidget->setSortingEnabled(__sortingEnabled1);

        ES_GpBox->setTitle(QString());
        ES_value_GpBox->setTitle(QApplication::translate("MainWidget", "\350\257\257\345\267\256\350\256\241\347\256\227(%)", 0, QApplication::UnicodeUTF8));
        ES_PE_Label->setText(QApplication::translate("MainWidget", "\347\224\265\350\203\275\350\257\257\345\267\256: ", 0, QApplication::UnicodeUTF8));
        ES_TE_LnEdit->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        ES_TE_Label->setText(QApplication::translate("MainWidget", "\346\227\266\351\222\237\350\257\257\345\267\256: ", 0, QApplication::UnicodeUTF8));
        ES_PE_LnEdit->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        ES_insertForm_PsBtn->setText(QApplication::translate("MainWidget", "\350\256\260\345\205\245\346\212\245\350\241\250", 0, QApplication::UnicodeUTF8));
        ES_PE_zoomIn_PsBtn->setText(QApplication::translate("MainWidget", "\347\274\251\345\260\217", 0, QApplication::UnicodeUTF8));
        ES_PE_zoomOut_PsBtn->setText(QApplication::translate("MainWidget", "\346\224\276\345\244\247", 0, QApplication::UnicodeUTF8));
        ES_TbWidget->setTabText(ES_TbWidget->indexOf(ES_PE_tab), QApplication::translate("MainWidget", "\347\224\265\350\203\275\350\257\257\345\267\256", 0, QApplication::UnicodeUTF8));
        ES_TbWidget->setTabText(ES_TbWidget->indexOf(ES_wave_tab), QApplication::translate("MainWidget", "\350\276\223\345\205\245\346\263\242\345\275\242", 0, QApplication::UnicodeUTF8));
        ES_standard_Label->setText(QApplication::translate("MainWidget", "\346\240\207\345\207\206\350\241\250:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = BMS_RD_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWidget", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = BMS_RD_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWidget", "\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = BMS_RD_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWidget", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = BMS_RD_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWidget", "\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = BMS_RD_TblWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWidget", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = BMS_RD_TblWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWidget", "\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = BMS_RD_TblWidget->verticalHeaderItem(0);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = BMS_RD_TblWidget->verticalHeaderItem(1);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = BMS_RD_TblWidget->verticalHeaderItem(2);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = BMS_RD_TblWidget->verticalHeaderItem(3);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWidget", "4", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled2 = BMS_RD_TblWidget->isSortingEnabled();
        BMS_RD_TblWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem52 = BMS_RD_TblWidget->item(0, 0);
        ___qtablewidgetitem52->setText(QApplication::translate("MainWidget", "\346\234\200\345\244\247\345\205\201\350\256\270\350\276\223\345\205\245\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = BMS_RD_TblWidget->item(0, 1);
        ___qtablewidgetitem53->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem54 = BMS_RD_TblWidget->item(0, 2);
        ___qtablewidgetitem54->setText(QApplication::translate("MainWidget", "\347\224\265\345\216\213\350\276\223\345\205\245(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem55 = BMS_RD_TblWidget->item(0, 3);
        ___qtablewidgetitem55->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem56 = BMS_RD_TblWidget->item(0, 4);
        ___qtablewidgetitem56->setText(QApplication::translate("MainWidget", "\347\224\265\346\261\240\346\200\273\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem57 = BMS_RD_TblWidget->item(0, 5);
        ___qtablewidgetitem57->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem58 = BMS_RD_TblWidget->item(1, 0);
        ___qtablewidgetitem58->setText(QApplication::translate("MainWidget", "\346\234\200\345\244\247\345\205\201\350\256\270\350\276\223\345\205\245\347\224\265\346\265\201(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem59 = BMS_RD_TblWidget->item(1, 1);
        ___qtablewidgetitem59->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem60 = BMS_RD_TblWidget->item(1, 2);
        ___qtablewidgetitem60->setText(QApplication::translate("MainWidget", "\347\224\265\346\265\201\350\276\223\345\205\245(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem61 = BMS_RD_TblWidget->item(1, 3);
        ___qtablewidgetitem61->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem62 = BMS_RD_TblWidget->item(1, 4);
        ___qtablewidgetitem62->setText(QApplication::translate("MainWidget", "\345\275\223\345\211\215\350\215\267\347\224\265\347\212\266\346\200\201(%)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem63 = BMS_RD_TblWidget->item(1, 5);
        ___qtablewidgetitem63->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem64 = BMS_RD_TblWidget->item(2, 0);
        ___qtablewidgetitem64->setText(QApplication::translate("MainWidget", "\345\205\205\347\224\265\347\224\265\345\216\213\351\234\200\346\261\202(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem65 = BMS_RD_TblWidget->item(2, 1);
        ___qtablewidgetitem65->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem66 = BMS_RD_TblWidget->item(2, 2);
        ___qtablewidgetitem66->setText(QApplication::translate("MainWidget", "\347\264\257\350\256\241\345\205\205\347\224\265\346\227\266\351\227\264(m)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem67 = BMS_RD_TblWidget->item(2, 3);
        ___qtablewidgetitem67->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem68 = BMS_RD_TblWidget->item(2, 4);
        ___qtablewidgetitem68->setText(QApplication::translate("MainWidget", "\345\211\251\344\275\231\345\205\205\347\224\265\346\227\266\351\227\264(m)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem69 = BMS_RD_TblWidget->item(2, 5);
        ___qtablewidgetitem69->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem70 = BMS_RD_TblWidget->item(3, 0);
        ___qtablewidgetitem70->setText(QApplication::translate("MainWidget", "\345\205\205\347\224\265\347\224\265\346\265\201\351\234\200\346\261\202(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem71 = BMS_RD_TblWidget->item(3, 1);
        ___qtablewidgetitem71->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        BMS_RD_TblWidget->setSortingEnabled(__sortingEnabled2);

        RRF_ripple_chl_CbBox->clear();
        RRF_ripple_chl_CbBox->insertItems(0, QStringList()
         << QApplication::translate("MainWidget", "\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWidget", "\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8)
        );
        RRF_ripple_chl_Label->setText(QApplication::translate("MainWidget", "\346\265\213\350\257\225\351\241\271:  ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem72 = RRF_ripple_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem72->setText(QApplication::translate("MainWidget", "\347\272\271\346\263\242\347\263\273\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem73 = RRF_ripple_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem73->setText(QApplication::translate("MainWidget", "\347\272\271\346\263\242\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem74 = RRF_ripple_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem74->setText(QApplication::translate("MainWidget", "\347\272\271\346\263\242\345\237\272\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem75 = RRF_ripple_TblWidget->verticalHeaderItem(0);
        ___qtablewidgetitem75->setText(QApplication::translate("MainWidget", "\347\224\265\345\216\213(v)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem76 = RRF_ripple_TblWidget->verticalHeaderItem(1);
        ___qtablewidgetitem76->setText(QApplication::translate("MainWidget", "\347\224\265\346\265\201(A)", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled3 = RRF_ripple_TblWidget->isSortingEnabled();
        RRF_ripple_TblWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem77 = RRF_ripple_TblWidget->item(0, 0);
        ___qtablewidgetitem77->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem78 = RRF_ripple_TblWidget->item(0, 1);
        ___qtablewidgetitem78->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem79 = RRF_ripple_TblWidget->item(0, 2);
        ___qtablewidgetitem79->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem80 = RRF_ripple_TblWidget->item(1, 0);
        ___qtablewidgetitem80->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem81 = RRF_ripple_TblWidget->item(1, 1);
        ___qtablewidgetitem81->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem82 = RRF_ripple_TblWidget->item(1, 2);
        ___qtablewidgetitem82->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        RRF_ripple_TblWidget->setSortingEnabled(__sortingEnabled3);

        QTableWidgetItem *___qtablewidgetitem83 = from_information_TbWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem83->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem84 = from_information_TbWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem84->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem85 = from_information_TbWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem85->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem86 = from_information_TbWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem86->setText(QApplication::translate("MainWidget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem87 = from_information_TbWidget->verticalHeaderItem(0);
        ___qtablewidgetitem87->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem88 = from_information_TbWidget->verticalHeaderItem(1);
        ___qtablewidgetitem88->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem89 = from_information_TbWidget->verticalHeaderItem(2);
        ___qtablewidgetitem89->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem90 = from_information_TbWidget->verticalHeaderItem(3);
        ___qtablewidgetitem90->setText(QApplication::translate("MainWidget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem91 = from_information_TbWidget->verticalHeaderItem(4);
        ___qtablewidgetitem91->setText(QApplication::translate("MainWidget", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem92 = from_information_TbWidget->verticalHeaderItem(5);
        ___qtablewidgetitem92->setText(QApplication::translate("MainWidget", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem93 = from_information_TbWidget->verticalHeaderItem(6);
        ___qtablewidgetitem93->setText(QApplication::translate("MainWidget", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem94 = from_information_TbWidget->verticalHeaderItem(7);
        ___qtablewidgetitem94->setText(QApplication::translate("MainWidget", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem95 = from_information_TbWidget->verticalHeaderItem(8);
        ___qtablewidgetitem95->setText(QApplication::translate("MainWidget", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem96 = from_information_TbWidget->verticalHeaderItem(9);
        ___qtablewidgetitem96->setText(QApplication::translate("MainWidget", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem97 = from_information_TbWidget->verticalHeaderItem(10);
        ___qtablewidgetitem97->setText(QApplication::translate("MainWidget", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem98 = from_information_TbWidget->verticalHeaderItem(11);
        ___qtablewidgetitem98->setText(QApplication::translate("MainWidget", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem99 = from_information_TbWidget->verticalHeaderItem(12);
        ___qtablewidgetitem99->setText(QApplication::translate("MainWidget", "13", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled4 = from_information_TbWidget->isSortingEnabled();
        from_information_TbWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem100 = from_information_TbWidget->item(0, 0);
        ___qtablewidgetitem100->setText(QApplication::translate("MainWidget", "\345\247\224\346\211\230\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem101 = from_information_TbWidget->item(0, 1);
        ___qtablewidgetitem101->setText(QApplication::translate("MainWidget", "\346\267\261\345\234\263\346\230\237\351\276\231\347\247\221\346\212\200\350\202\241\344\273\275\346\234\211\351\231\220\345\205\254\345\217\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem102 = from_information_TbWidget->item(0, 2);
        ___qtablewidgetitem102->setText(QApplication::translate("MainWidget", "\345\215\225\344\275\215\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem103 = from_information_TbWidget->item(0, 3);
        ___qtablewidgetitem103->setText(QApplication::translate("MainWidget", "\346\267\261\345\234\263\345\215\227\345\261\261\346\231\272\346\201\222\346\210\230\347\225\245\346\200\247\346\226\260\345\205\264\344\272\247\344\270\232\345\233\25515\346\240\2136\346\245\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem104 = from_information_TbWidget->item(1, 0);
        ___qtablewidgetitem104->setText(QApplication::translate("MainWidget", "\344\273\252\345\231\250\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem105 = from_information_TbWidget->item(1, 1);
        ___qtablewidgetitem105->setText(QApplication::translate("MainWidget", "XL-903\347\233\264\346\265\201\345\205\205\347\224\265\346\234\272\347\216\260\345\234\272\346\240\241\351\252\214\344\273\252", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem106 = from_information_TbWidget->item(1, 2);
        ___qtablewidgetitem106->setText(QApplication::translate("MainWidget", "\345\210\266\351\200\240\345\216\202\345\220\215 ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem107 = from_information_TbWidget->item(1, 3);
        ___qtablewidgetitem107->setText(QApplication::translate("MainWidget", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem108 = from_information_TbWidget->item(2, 0);
        ___qtablewidgetitem108->setText(QApplication::translate("MainWidget", "\345\236\213      \345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem109 = from_information_TbWidget->item(2, 1);
        ___qtablewidgetitem109->setText(QApplication::translate("MainWidget", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem110 = from_information_TbWidget->item(2, 2);
        ___qtablewidgetitem110->setText(QApplication::translate("MainWidget", "\347\224\237\344\272\247\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem111 = from_information_TbWidget->item(2, 3);
        ___qtablewidgetitem111->setText(QApplication::translate("MainWidget", "2016-06-01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem112 = from_information_TbWidget->item(3, 0);
        ___qtablewidgetitem112->setText(QApplication::translate("MainWidget", "\345\207\272\345\216\202\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem113 = from_information_TbWidget->item(3, 1);
        ___qtablewidgetitem113->setText(QApplication::translate("MainWidget", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem114 = from_information_TbWidget->item(3, 2);
        ___qtablewidgetitem114->setText(QApplication::translate("MainWidget", "\345\207\206\347\241\256\345\272\246\347\255\211\347\272\247", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem115 = from_information_TbWidget->item(3, 3);
        ___qtablewidgetitem115->setText(QApplication::translate("MainWidget", "0.05", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem116 = from_information_TbWidget->item(4, 0);
        ___qtablewidgetitem116->setText(QApplication::translate("MainWidget", "\351\242\235\345\256\232\350\276\223\345\207\272\347\224\265\345\216\213\350\214\203\345\233\264(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem117 = from_information_TbWidget->item(4, 1);
        ___qtablewidgetitem117->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem118 = from_information_TbWidget->item(4, 2);
        ___qtablewidgetitem118->setText(QApplication::translate("MainWidget", "\351\242\235\345\256\232\350\276\223\345\207\272\347\224\265\346\265\201\350\214\203\345\233\264(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem119 = from_information_TbWidget->item(4, 3);
        ___qtablewidgetitem119->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem120 = from_information_TbWidget->item(5, 0);
        ___qtablewidgetitem120->setText(QApplication::translate("MainWidget", "\351\242\235\345\256\232\350\276\223\345\207\272\345\270\270\346\225\260\350\214\203\345\233\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem121 = from_information_TbWidget->item(5, 1);
        ___qtablewidgetitem121->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem122 = from_information_TbWidget->item(5, 2);
        ___qtablewidgetitem122->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\344\276\235\346\215\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem123 = from_information_TbWidget->item(5, 3);
        ___qtablewidgetitem123->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem124 = from_information_TbWidget->item(6, 0);
        ___qtablewidgetitem124->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem125 = from_information_TbWidget->item(6, 1);
        ___qtablewidgetitem125->setText(QApplication::translate("MainWidget", "2016-06-01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem126 = from_information_TbWidget->item(6, 2);
        ___qtablewidgetitem126->setText(QApplication::translate("MainWidget", "\346\234\211 \346\225\210 \346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem127 = from_information_TbWidget->item(6, 3);
        ___qtablewidgetitem127->setText(QApplication::translate("MainWidget", "2016-06-01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem128 = from_information_TbWidget->item(7, 0);
        ___qtablewidgetitem128->setText(QApplication::translate("MainWidget", "\346\270\251    \345\272\246(\342\204\203)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem129 = from_information_TbWidget->item(7, 1);
        ___qtablewidgetitem129->setText(QApplication::translate("MainWidget", "30", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem130 = from_information_TbWidget->item(7, 2);
        ___qtablewidgetitem130->setText(QApplication::translate("MainWidget", "\347\233\270\345\257\271\346\271\277\345\272\246(%)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem131 = from_information_TbWidget->item(7, 3);
        ___qtablewidgetitem131->setText(QApplication::translate("MainWidget", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem132 = from_information_TbWidget->item(8, 0);
        ___qtablewidgetitem132->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\345\234\260\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem133 = from_information_TbWidget->item(8, 1);
        ___qtablewidgetitem133->setText(QApplication::translate("MainWidget", "\346\267\261\345\234\263\345\270\202\345\215\227\345\261\261\345\214\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem134 = from_information_TbWidget->item(9, 0);
        ___qtablewidgetitem134->setText(QApplication::translate("MainWidget", "\346\240\207\345\207\206\345\231\250\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem135 = from_information_TbWidget->item(9, 1);
        ___qtablewidgetitem135->setText(QApplication::translate("MainWidget", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem136 = from_information_TbWidget->item(9, 2);
        ___qtablewidgetitem136->setText(QApplication::translate("MainWidget", "\347\211\271     \345\276\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem137 = from_information_TbWidget->item(10, 0);
        ___qtablewidgetitem137->setText(QApplication::translate("MainWidget", "\350\256\276\345\244\207\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem138 = from_information_TbWidget->item(10, 1);
        ___qtablewidgetitem138->setText(QApplication::translate("MainWidget", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem139 = from_information_TbWidget->item(10, 2);
        ___qtablewidgetitem139->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232/\346\240\241\345\207\206\350\257\201\344\271\246\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem140 = from_information_TbWidget->item(11, 0);
        ___qtablewidgetitem140->setText(QApplication::translate("MainWidget", "\346\234\211\346\225\210\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem141 = from_information_TbWidget->item(11, 1);
        ___qtablewidgetitem141->setText(QApplication::translate("MainWidget", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem142 = from_information_TbWidget->item(11, 2);
        ___qtablewidgetitem142->setText(QApplication::translate("MainWidget", "\344\275\277\347\224\250\345\211\215\345\220\216\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem143 = from_information_TbWidget->item(12, 0);
        ___qtablewidgetitem143->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\345\221\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem144 = from_information_TbWidget->item(12, 1);
        ___qtablewidgetitem144->setText(QApplication::translate("MainWidget", "jing1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem145 = from_information_TbWidget->item(12, 2);
        ___qtablewidgetitem145->setText(QApplication::translate("MainWidget", "\346\240\270\351\252\214\345\221\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem146 = from_information_TbWidget->item(12, 3);
        ___qtablewidgetitem146->setText(QApplication::translate("MainWidget", "jing2", 0, QApplication::UnicodeUTF8));
        from_information_TbWidget->setSortingEnabled(__sortingEnabled4);

        from_clearFrom_PsBtn->setText(QApplication::translate("MainWidget", "\346\270\205\347\251\272\346\212\245\350\241\250", 0, QApplication::UnicodeUTF8));
        from_information_Label->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        from_buildForm_PsBtn->setText(QApplication::translate("MainWidget", "\347\224\237\346\210\220\346\212\245\350\241\250", 0, QApplication::UnicodeUTF8));
        from_error_Label->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\347\273\223\350\256\272", 0, QApplication::UnicodeUTF8));
        intuit_Label->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\347\273\223\346\236\234:", 0, QApplication::UnicodeUTF8));
        intuit_CkBox->setText(QApplication::translate("MainWidget", "\345\220\210\346\240\274", 0, QApplication::UnicodeUTF8));
        form_error_TbWidget->setTabText(form_error_TbWidget->indexOf(intuit_tab), QApplication::translate("MainWidget", "\345\244\226\350\247\202\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem147 = operating_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem147->setText(QApplication::translate("MainWidget", "\350\276\223\345\207\272\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem148 = operating_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem148->setText(QApplication::translate("MainWidget", "\350\276\223\345\207\272\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem149 = operating_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem149->setText(QApplication::translate("MainWidget", "\350\257\257\345\267\256 1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem150 = operating_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem150->setText(QApplication::translate("MainWidget", "\350\257\257\345\267\256 2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem151 = operating_TblWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem151->setText(QApplication::translate("MainWidget", "\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem152 = operating_TblWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem152->setText(QApplication::translate("MainWidget", "\347\273\223\350\256\272", 0, QApplication::UnicodeUTF8));
        form_error_TbWidget->setTabText(form_error_TbWidget->indexOf(operating_tab), QApplication::translate("MainWidget", "\345\267\245\344\275\234\350\257\257\345\267\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem153 = load_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem153->setText(QApplication::translate("MainWidget", "W' \345\211\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem154 = load_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem154->setText(QApplication::translate("MainWidget", "W' \345\220\216", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem155 = load_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem155->setText(QApplication::translate("MainWidget", "W' ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem156 = load_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem156->setText(QApplication::translate("MainWidget", "\346\240\207\345\207\206\347\244\272\345\200\274 W(kW\302\267h)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem157 = load_TblWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem157->setText(QApplication::translate("MainWidget", "\350\257\257\345\267\256(%)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem158 = load_TblWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem158->setText(QApplication::translate("MainWidget", "\347\273\223\350\256\272", 0, QApplication::UnicodeUTF8));
        form_error_TbWidget->setTabText(form_error_TbWidget->indexOf(load_tab), QApplication::translate("MainWidget", "\345\205\205\347\224\265\351\207\217\346\230\276\347\244\272\350\257\257\345\267\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem159 = payment_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem159->setText(QApplication::translate("MainWidget", "\346\241\251\344\273\230\350\264\271\351\207\221\351\242\235(\345\205\203)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem160 = payment_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem160->setText(QApplication::translate("MainWidget", "\345\205\205\347\224\265\347\224\265\350\203\275(kW\302\267h)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem161 = payment_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem161->setText(QApplication::translate("MainWidget", "\345\215\225\344\275\215\347\224\265\344\273\267(\345\205\203/kW\302\267h)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem162 = payment_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem162->setText(QApplication::translate("MainWidget", "\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem163 = payment_TblWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem163->setText(QApplication::translate("MainWidget", "\350\257\257\345\267\256(\345\205\203)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem164 = payment_TblWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem164->setText(QApplication::translate("MainWidget", "\347\273\223\350\256\272", 0, QApplication::UnicodeUTF8));
        form_error_TbWidget->setTabText(form_error_TbWidget->indexOf(payment), QApplication::translate("MainWidget", "\344\273\230\350\264\271\351\207\221\351\242\235\350\257\257\345\267\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem165 = time_TblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem165->setText(QApplication::translate("MainWidget", "\350\242\253\346\243\200\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem166 = time_TblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem166->setText(QApplication::translate("MainWidget", "\346\240\207\345\207\206\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem167 = time_TblWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem167->setText(QApplication::translate("MainWidget", "\346\227\266\351\222\237\350\257\257\345\267\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem168 = time_TblWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem168->setText(QApplication::translate("MainWidget", "\347\273\223\350\256\272", 0, QApplication::UnicodeUTF8));
        form_error_TbWidget->setTabText(form_error_TbWidget->indexOf(time_tab), QApplication::translate("MainWidget", "\346\227\266\351\222\237\347\244\272\345\200\274\350\257\257\345\267\256", 0, QApplication::UnicodeUTF8));
        overallClu_Label->setText(QApplication::translate("MainWidget", "\346\243\200\345\256\232\347\273\223\346\236\234:", 0, QApplication::UnicodeUTF8));
        overallClu_CkBox->setText(QApplication::translate("MainWidget", "\345\220\210\346\240\274", 0, QApplication::UnicodeUTF8));
        form_error_TbWidget->setTabText(form_error_TbWidget->indexOf(overallClu_tab), QApplication::translate("MainWidget", "\346\243\200\345\256\232\346\200\273\347\273\223\350\256\272", 0, QApplication::UnicodeUTF8));
        serPort_Rec_GbBox->setTitle(QString());
        serPort_CleanRec_PsBtn->setText(QApplication::translate("MainWidget", "\346\270\205\347\251\272\346\216\245\346\224\266", 0, QApplication::UnicodeUTF8));
        serPort_send_GpBox->setTitle(QString());
        serPort_SP_GpBox->setTitle(QApplication::translate("MainWidget", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        serPort_read_SP_PsBtn->setText(QApplication::translate("MainWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        serPort_write_SP_PsBtn->setText(QApplication::translate("MainWidget", "\345\206\231\345\205\245", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem169 = serPort_SP_TabWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem169->setText(QApplication::translate("MainWidget", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem170 = serPort_SP_TabWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem170->setText(QApplication::translate("MainWidget", "\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem171 = serPort_SP_TabWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem171->setText(QApplication::translate("MainWidget", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem172 = serPort_SP_TabWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem172->setText(QApplication::translate("MainWidget", "\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem173 = serPort_SP_TabWidget->verticalHeaderItem(0);
        ___qtablewidgetitem173->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem174 = serPort_SP_TabWidget->verticalHeaderItem(1);
        ___qtablewidgetitem174->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem175 = serPort_SP_TabWidget->verticalHeaderItem(2);
        ___qtablewidgetitem175->setText(QApplication::translate("MainWidget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem176 = serPort_SP_TabWidget->verticalHeaderItem(3);
        ___qtablewidgetitem176->setText(QApplication::translate("MainWidget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem177 = serPort_SP_TabWidget->verticalHeaderItem(4);
        ___qtablewidgetitem177->setText(QApplication::translate("MainWidget", "5", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled5 = serPort_SP_TabWidget->isSortingEnabled();
        serPort_SP_TabWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem178 = serPort_SP_TabWidget->item(0, 0);
        ___qtablewidgetitem178->setText(QApplication::translate("MainWidget", "\351\207\207\346\240\267\351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem179 = serPort_SP_TabWidget->item(0, 1);
        ___qtablewidgetitem179->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem180 = serPort_SP_TabWidget->item(0, 2);
        ___qtablewidgetitem180->setText(QApplication::translate("MainWidget", "\345\216\202\345\256\266", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem181 = serPort_SP_TabWidget->item(0, 3);
        ___qtablewidgetitem181->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem182 = serPort_SP_TabWidget->item(1, 0);
        ___qtablewidgetitem182->setText(QApplication::translate("MainWidget", "\345\205\205\347\224\265\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem183 = serPort_SP_TabWidget->item(1, 1);
        ___qtablewidgetitem183->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem184 = serPort_SP_TabWidget->item(1, 2);
        ___qtablewidgetitem184->setText(QApplication::translate("MainWidget", "\350\264\237\350\275\275\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem185 = serPort_SP_TabWidget->item(1, 3);
        ___qtablewidgetitem185->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem186 = serPort_SP_TabWidget->item(2, 0);
        ___qtablewidgetitem186->setText(QApplication::translate("MainWidget", "\347\224\265\345\216\213\351\207\217\347\250\213.V", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem187 = serPort_SP_TabWidget->item(2, 1);
        ___qtablewidgetitem187->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem188 = serPort_SP_TabWidget->item(2, 2);
        ___qtablewidgetitem188->setText(QApplication::translate("MainWidget", "\347\224\265\346\265\201\351\207\217\347\250\213.A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem189 = serPort_SP_TabWidget->item(2, 3);
        ___qtablewidgetitem189->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem190 = serPort_SP_TabWidget->item(3, 0);
        ___qtablewidgetitem190->setText(QApplication::translate("MainWidget", "\350\204\211\345\206\262\345\270\270\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem191 = serPort_SP_TabWidget->item(3, 1);
        ___qtablewidgetitem191->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem192 = serPort_SP_TabWidget->item(3, 2);
        ___qtablewidgetitem192->setText(QApplication::translate("MainWidget", "\347\224\265\350\241\250\345\270\270\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem193 = serPort_SP_TabWidget->item(3, 3);
        ___qtablewidgetitem193->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem194 = serPort_SP_TabWidget->item(4, 0);
        ___qtablewidgetitem194->setText(QApplication::translate("MainWidget", "\347\224\265\350\264\271\345\215\225\344\273\267.\302\245", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem195 = serPort_SP_TabWidget->item(4, 1);
        ___qtablewidgetitem195->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem196 = serPort_SP_TabWidget->item(4, 2);
        ___qtablewidgetitem196->setText(QApplication::translate("MainWidget", "\346\265\213\351\207\217\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem197 = serPort_SP_TabWidget->item(4, 3);
        ___qtablewidgetitem197->setText(QApplication::translate("MainWidget", "0", 0, QApplication::UnicodeUTF8));
        serPort_SP_TabWidget->setSortingEnabled(__sortingEnabled5);

        serPort_shortcut_GpBox->setTitle(QApplication::translate("MainWidget", "\345\277\253\351\200\237\346\214\207\344\273\244", 0, QApplication::UnicodeUTF8));
        serPort_EB_PsBtn->setText(QApplication::translate("MainWidget", "EB", 0, QApplication::UnicodeUTF8));
        serPort_ME_PsBtn->setText(QApplication::translate("MainWidget", "ME", 0, QApplication::UnicodeUTF8));
        serPort_RS_PsBtn->setText(QApplication::translate("MainWidget", "RS", 0, QApplication::UnicodeUTF8));
        serPort_AV_PsBtn->setText(QApplication::translate("MainWidget", "\347\211\210\346\234\254", 0, QApplication::UnicodeUTF8));
        serPort_RP_PsBtn->setText(QApplication::translate("MainWidget", "RP", 0, QApplication::UnicodeUTF8));
        serPort_RSM_PsBtn->setText(QApplication::translate("MainWidget", "RSM", 0, QApplication::UnicodeUTF8));
        serPort_RBAT_PsBtn->setText(QApplication::translate("MainWidget", "RBAT", 0, QApplication::UnicodeUTF8));
        serPort_RD_PsBtn->setText(QApplication::translate("MainWidget", "RD", 0, QApplication::UnicodeUTF8));
        serPort_RRF_PsBtn->setText(QApplication::translate("MainWidget", "RRF", 0, QApplication::UnicodeUTF8));
        serPort_Send_PsBtn->setText(QApplication::translate("MainWidget", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        serPort_CR_CkBox->setText(QApplication::translate("MainWidget", "CR", 0, QApplication::UnicodeUTF8));
        serPort_CleanSend_PsBtn->setText(QApplication::translate("MainWidget", "\346\270\205\347\251\272\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        serPort_LF_CkBox->setText(QApplication::translate("MainWidget", "LF", 0, QApplication::UnicodeUTF8));
        serPort_Settings_GpBox->setTitle(QString());
        serPort_portName_Label->setText(QApplication::translate("MainWidget", "\347\253\257\345\217\243 :", 0, QApplication::UnicodeUTF8));
        serPort_parity_Label->setText(QApplication::translate("MainWidget", "\346\240\241\351\252\214\344\275\215 :", 0, QApplication::UnicodeUTF8));
        serPort_baudRate_Label->setText(QApplication::translate("MainWidget", "\346\263\242\347\211\271\347\216\207 :", 0, QApplication::UnicodeUTF8));
        serPort_dataBit_Label->setText(QApplication::translate("MainWidget", "\346\225\260\346\215\256\344\275\215 :", 0, QApplication::UnicodeUTF8));
        serPort_stopBit_Label->setText(QApplication::translate("MainWidget", "\345\201\234\346\255\242\344\275\215 :", 0, QApplication::UnicodeUTF8));
        serPort_flowCtl_Label->setText(QApplication::translate("MainWidget", "\346\265\201\346\216\247\345\210\266 :", 0, QApplication::UnicodeUTF8));
        serPort_ctl_GpBox->setTitle(QString());
        serPort_Open_PsBtn->setText(QApplication::translate("MainWidget", "\346\211\223\345\274\200\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        serPort_Close_PsBtn->setText(QApplication::translate("MainWidget", "\345\205\263\351\227\255\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        sideBar_right_Page->setProperty("class", QVariant(QApplication::translate("MainWidget", "SideBar", 0, QApplication::UnicodeUTF8)));
        sideBar_TlBtn_3->setText(QString());
        sideBar_TlBtn_2->setText(QString());
        sideBar_TlBtn_4->setText(QString());
        sideBar_TlBtn_1->setText(QString());
        start_PsBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
