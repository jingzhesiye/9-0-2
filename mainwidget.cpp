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

    init_RSMV_wave();   //波形图
    init_RSMV_harmonic();//柱状图
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

    #if 0

    connect(&timeThreadTimer, SIGNAL(sig_RSMV_ESTD_update(pESTDTYPE)),   this, SLOT(slt_RSMV_ESTD_update(pESTDTYPE)));
    connect(&timeThreadTimer, SIGNAL(sig_ENERGY_PUL_update(pPULSEPOW)),   this, SLOT(slt_ENERGY_PUL_update(pPULSEPOW)),Qt::DirectConnection);
    connect(&timeThreadTimer, SIGNAL(sig_ENERGY_STD_update(pPULSEPOW)),   this, SLOT(slt_ENERGY_STD_update(pPULSEPOW)),Qt::DirectConnection);

    connect(&timeThreadTimer, SIGNAL(sig_RSMV_wave_update()),          this, SLOT(slt_RSMV_wave_update()));
    connect(&timeThreadTimer, SIGNAL(sig_RSMV_harmonic_update()),      this, SLOT(slt_RSMV_harmonic_update()));


    qRegisterMetaType<pESTDTYPE>("pESTDTYPE");

    qRegisterMetaType<pPULSEPOW>("pPULSEPOW");
    #endif
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





void MainWidget::on_RSMV_zoomOut_PsBtn_clicked()
{
    QWheelEvent event(QPoint(150, 80),-120, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent( ui->RSMV_energyError_QwtPlot->canvas(), &event);

}

void MainWidget::on_RSMV_zoomIn_PsBtn_clicked()
{
    QWheelEvent event(QPoint(150, 80),120, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent( ui->RSMV_energyError_QwtPlot->canvas(), &event);
}

void MainWidget::on_RSMV_keyBoard_PsBtn_clicked()
{
    QProcess *myProcess = new QProcess();
     myProcess->start("./ScreenKeyboard.exe");//ScreenKeyboard
}


