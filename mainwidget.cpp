#include "mainwidget.h"
#include "xl618.h"
#include "QMessageBox"
#include  "QTimer"
#include "QWheelEvent"
#include <qwt_plot_canvas.h>
#include "QProcess"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    init_sideBar();
    init_serPort();
    read_ini();
    slot_serPort_open();//打开串口

    init_timeThreadTimer_connect();

    init_ES_wave();       //波形图
    init_ripple_wave();    //纹波
    init_ESTD_wave();    //标准偏差波形图
    init_elapseTime();   //运行时间

}

MainWidget::~MainWidget()
{
    delete ui;
}

bool MainWidget::eventFilter(QObject *target,QEvent *event)
{
#if 0
    if(event->type() == QEvent::HoverEnter)
    {
        qDebug()<<"eventFilter11";
        ui->sideBar_TlBtn_1->setStyleSheet(QString::fromUtf8(
"    border-right: 3px solid rgb(170, 170, 170);\n"
"    border-left: 3px solid rgb(170, 170, 170);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(100, 100, 100, 255),\n"
"        stop:1 rgba(250, 250, 250, 255));\n"
"}"));

        ui->sideBar_TlBtn_1->update();

        ui->sideBar_TlBtn_1->setIconSize(QSize(90,90));

   }
    if(event->type() == QEvent::HoverLeave)
    {
        qDebug()<<"eventFilter11";
        ui->sideBar_TlBtn_1->setIconSize(QSize(80,80));

   }
#endif
    return QWidget::eventFilter(target, event);
}



void MainWidget::init_timeThreadTimer_connect()
{

    connect(&timeThreadTimer, SIGNAL(sig_RD_update(pRDTYPE)),    this, SLOT(slt_RD_update(pRDTYPE)),Qt::DirectConnection);
    qRegisterMetaType<pRDTYPE>("pRDTYPE");

    connect(&timeThreadTimer, SIGNAL(sig_RS_update(pRSTYPE)),    this, SLOT(slt_RS_update(pRSTYPE)),Qt::DirectConnection);
    qRegisterMetaType<pRSTYPE>("pRSTYPE");

    connect(&timeThreadTimer, SIGNAL(sig_ES_update(pESTYPE)),     this, SLOT(slt_ES_update(pESTYPE)));
    qRegisterMetaType<pESTYPE>("pESTYPE");

    connect(&timeThreadTimer, SIGNAL(sig_ME_update(pMETYPE)),    this, SLOT(slt_ME_update(pMETYPE)),Qt::DirectConnection);
    qRegisterMetaType<pMETYPE>("pMETYPE");
    qRegisterMetaType<QTextCursor>("QTextCursor");

    connect(&timeThreadTimer, SIGNAL(sig_RRF_update(pRRFTYPE)),   this, SLOT(slt_RRF_update(pRRFTYPE)),Qt::DirectConnection);
    qRegisterMetaType<pRRFTYPE>("pRRFTYPE");

    connect(&timeThreadTimer, SIGNAL(sig_wave_update()),          this, SLOT(slt_wave_update()));


    connect(&timeThreadTimer, SIGNAL(sig_battery_update(QString )),  this, SLOT(slt_battery_update(QString )));
    qRegisterMetaType<QString>("QString");

    timeThreadTimer.slt_battery_timeDone();//开机读取一次

    ui->RS_charger_TblWidget->setColumnWidth(0,110);
    ui->RS_charger_TblWidget->setColumnWidth(1,110);
    ui->RS_charger_TblWidget->setColumnWidth(2,130);
    ui->RS_charger_TblWidget->setColumnWidth(3,120);
    ui->RS_charger_TblWidget->setColumnWidth(4,130);
    ui->RS_charger_TblWidget->setColumnWidth(5,120);

    ui->ES_standard_TblWidget->setColumnWidth(0,80);
    ui->ES_standard_TblWidget->setColumnWidth(1,80);
    ui->ES_standard_TblWidget->setColumnWidth(2,110);
    ui->ES_standard_TblWidget->setColumnWidth(3,80);
    ui->ES_standard_TblWidget->setColumnWidth(4,110);
    ui->ES_standard_TblWidget->setColumnWidth(5,80);


    ui->BMS_RD_TblWidget->setColumnWidth(0,160);
    ui->BMS_RD_TblWidget->setColumnWidth(1,100);
    ui->BMS_RD_TblWidget->setColumnWidth(2,130);
    ui->BMS_RD_TblWidget->setColumnWidth(3,100);
    ui->BMS_RD_TblWidget->setColumnWidth(4,130);
    ui->BMS_RD_TblWidget->setColumnWidth(5,100);

//    ui->intuit_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->time_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->operating_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->load_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->payment_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Interactive);
//    ui->conclusion_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
}

//fun:用于清除表格
void MainWidget::remove_TblWdiget_Row(QTableWidget *TblWiget)
{
    int numTemp=TblWiget->rowCount();

    for(int i=numTemp;i>=0;i--)
    {
       TblWiget->removeRow(i);
    }
}



void MainWidget::set_TblWdiget_Header(QTableWidget *TblWiget,bool H,bool V)
{
   TblWiget->horizontalHeader()->setVisible(H);
   TblWiget->verticalHeader()->setVisible(V);
}
void MainWidget::show_MsBox(QString strMessages,int msec)
{
    QMessageBox     *temp_MsBox;
    temp_MsBox= new QMessageBox(QMessageBox::Information,QString::fromUtf8("提醒"),QString::fromUtf8(""));  //
    temp_MsBox->addButton(new QPushButton(QString::fromUtf8("确定")),QMessageBox::AcceptRole);
    temp_MsBox->setText(strMessages);
    temp_MsBox->show();
    QTimer::singleShot(msec,temp_MsBox,SLOT(hide()));
}

void MainWidget::on_ES_PE_zoomOut_PsBtn_clicked()
{
    QWheelEvent event(QPoint(150, 80),-120, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent( ui->ES_PE_QwtPlot->canvas(), &event);

}

void MainWidget::on_ES_PE_zoomIn_PsBtn_clicked()
{
    QWheelEvent event(QPoint(150, 80),120, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent( ui->ES_PE_QwtPlot->canvas(), &event);
}

void MainWidget::on_keyBoard_PsBtn_clicked()
{
    QProcess *myProcess = new QProcess();
     myProcess->start("./ScreenKeyboard.exe");//ScreenKeyboard
}

void MainWidget::slt_battery_update(QString str)
{
    int value =str.toInt();
   //qDebug("%d",value);
     if(value>80)
     {
       ui->battery_Label->setStyleSheet(QString::fromUtf8("background-image: url(:);\n"
       "image: url(:/pic/battery_1.png);background-color:rgb(0, 0, 0, 0)"));
     }
     else if((value>45) && (value<80))//10反抖动
     {
        // qDebug("fasdf");
       ui->battery_Label->setStyleSheet(QString::fromUtf8("background-image: url(:);\n"
       "image: url(:/pic/battery_2.png);background-color:rgb(0, 0, 0, 0)"));
     }
     else if((value>10) && (value<45))
     {
       ui->battery_Label->setStyleSheet(QString::fromUtf8("background-image: url(:);\n"
       "image: url(:/pic/battery_3.png);background-color:rgb(0, 0, 0, 0)"));
     }

    if(value<10 )
    {
      ui->battery_Label->setStyleSheet(QString::fromUtf8("background-image: url(:);\n"
       "image: url(:/pic/battery_4.png);background-color:rgb(0, 0, 0, 0)"));
      show_MsBox(QString::fromUtf8("电池即将没电,请及时充电"),3000);
    }

     ui->battery_Label->update();
     qDebug()<<str;
}
