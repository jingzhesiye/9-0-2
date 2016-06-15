#include "mainwidget.h"
#include "xl618.h"
#include "QMessageBox"
#include  "QTimer"

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
    setColumnWidth();

    init_charging_wave();
    init_ripple_wave();    //纹波
    init_PE_wave();
    init_runTime();     //运行时间
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::init_timeThreadTimer_connect()
{
    connect(this, SIGNAL(sig_charging_wave_update()),this, SLOT(slt_charging_wave_update()));
    connect(this, SIGNAL(sig_PE_wave_update()),this, SLOT(slt_PE_wave_update()));

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

   // timeThreadTimer.slt_battery_timeDone();//开机读取一次
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

//行列显示
void MainWidget::set_TblWdiget_Header(QTableWidget *TblWiget,bool H,bool V)
{
   TblWiget->horizontalHeader()->setVisible(H);
   TblWiget->verticalHeader()->setVisible(V);
}

//信息框
void MainWidget::show_MsBox(QString strMessages,int msec)
{
    QMessageBox     *temp_MsBox;
    temp_MsBox= new QMessageBox(QMessageBox::Information,QString::fromUtf8("提醒"),QString::fromUtf8(""));  //
    temp_MsBox->addButton(new QPushButton(QString::fromUtf8("确定")),QMessageBox::AcceptRole);
    temp_MsBox->setText(strMessages);
    temp_MsBox->show();
    QTimer::singleShot(msec,temp_MsBox,SLOT(hide()));
}

//键盘
void MainWidget::on_keyBoard_PsBtn_clicked()
{
    QProcess *myProcess = new QProcess();
     myProcess->start("./ScreenKeyboard.exe");//ScreenKeyboard
}

//电池
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

//延时
void MainWidget:: Qt_delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

//保存6位有效值左边开始计算
QString MainWidget:: Qt_f_to_string_6(float a )
{
    QString str = QString::number(a,'d',6);
    int index = str.indexOf(".",0);
    int length = 6-index;
    //qDebug()<<str<<QString::number(index)<<QString::number(length);
    if(length >= 0)
    {
       return QString::number(a,'d',length);
    }
       return QString::number(a,'d',0);
}



