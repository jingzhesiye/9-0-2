#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QtGui>
#include <QStringList>
#include "QByteArray"
#include <Windows.h>


void MainWidget::init_serPort()
{
    ui->serPort_portName_CbBox->addItem("com1", QVariant::fromValue(QString("com1")));
    ui->serPort_portName_CbBox->addItem("com2", QVariant::fromValue(QString("com2")));
    ui->serPort_portName_CbBox->addItem("com3", QVariant::fromValue(QString("com3")));
    ui->serPort_portName_CbBox->addItem("com4", QVariant::fromValue(QString("com4")));
    ui->serPort_portName_CbBox->addItem("com5", QVariant::fromValue(QString("com5")));
    ui->serPort_portName_CbBox->addItem("com6", QVariant::fromValue(QString("com6")));
    ui->serPort_portName_CbBox->addItem("com7", QVariant::fromValue(QString("com7")));
    ui->serPort_portName_CbBox->addItem("com8", QVariant::fromValue(QString("com8")));
   // ui->serPort_portName_CbBox->setCurrentIndex(0); //COM1

    ui->serPort_baudRate_CbBox->addItem("110", QVariant::fromValue(BAUD110));
    ui->serPort_baudRate_CbBox->addItem("300", QVariant::fromValue(BAUD300));
    ui->serPort_baudRate_CbBox->addItem("600", QVariant::fromValue(BAUD600));
    ui->serPort_baudRate_CbBox->addItem("1200", QVariant::fromValue(BAUD1200));
    ui->serPort_baudRate_CbBox->addItem("2400", QVariant::fromValue(BAUD2400));
    ui->serPort_baudRate_CbBox->addItem("4800", QVariant::fromValue(BAUD4800));
    ui->serPort_baudRate_CbBox->addItem("9600", QVariant::fromValue(BAUD9600));
    ui->serPort_baudRate_CbBox->addItem("19200", QVariant::fromValue(BAUD19200));
    ui->serPort_baudRate_CbBox->addItem("38400", QVariant::fromValue(BAUD38400));
    ui->serPort_baudRate_CbBox->addItem("57600", QVariant::fromValue(BAUD57600));
    ui->serPort_baudRate_CbBox->addItem("115200", QVariant::fromValue(BAUD115200));
   // ui->serPort_baudRate_CbBox->setCurrentIndex(9); //57600 bauds

    ui->serPort_dataBit_CbBox->addItem("5", QVariant::fromValue(DATA_5));
    ui->serPort_dataBit_CbBox->addItem("6", QVariant::fromValue(DATA_6));
    ui->serPort_dataBit_CbBox->addItem("7", QVariant::fromValue(DATA_7));
    ui->serPort_dataBit_CbBox->addItem("8", QVariant::fromValue(DATA_8));
    ui->serPort_dataBit_CbBox->setCurrentIndex(3); //8 bit

    ui->serPort_parity_CbBox->addItem("None", QVariant::fromValue(PAR_NONE));
    ui->serPort_parity_CbBox->addItem("Even", QVariant::fromValue(PAR_EVEN)); //pair
    ui->serPort_parity_CbBox->addItem("Odd", QVariant::fromValue(PAR_ODD)); //impair
    ui->serPort_parity_CbBox->addItem("Space", QVariant::fromValue(PAR_SPACE));
    //ui->serPort_parity_CbBox->setCurrentIndex(0); //Parity none

    ui->serPort_stopBit_CbBox->addItem("1", QVariant::fromValue(STOP_1));
    ui->serPort_stopBit_CbBox->addItem("2", QVariant::fromValue(STOP_2));
    //ui->serPort_stopBit_CbBox->setCurrentIndex(2); //2 stop bit

    ui->serPort_flowCtl_CbBox->addItem("None", QVariant::fromValue(FLOW_OFF));
    ui->serPort_flowCtl_CbBox->addItem("Xon/Xoff", QVariant::fromValue(FLOW_XONXOFF));
    ui->serPort_flowCtl_CbBox->addItem("Hardware", QVariant::fromValue(FLOW_HARDWARE));
    ui->serPort_flowCtl_CbBox->setCurrentIndex(0); //Flow control none


    serPort_shorCut_list.append(ui->serPort_RP_PsBtn);
    serPort_shorCut_list.append(ui->serPort_AV_PsBtn);
    serPort_shorCut_list.append(ui->serPort_RSM_PsBtn);
    serPort_shorCut_list.append(ui->serPort_ME_PsBtn);
    serPort_shorCut_list.append(ui->serPort_RS_PsBtn);
    serPort_shorCut_list.append(ui->serPort_RD_PsBtn);

    foreach (QPushButton *serPort_shorCut_PsBtn, serPort_shorCut_list) {
        connect(serPort_shorCut_PsBtn, SIGNAL(clicked()), this, SLOT(slot_serPort_shorCut_PsBtn()));
    }

    connect(timeThreadTimer.driver_619, SIGNAL(sig_serPort_RecDataToUI(const QByteArray &,int)), this, SLOT(slt_serPort_RecDataToUI(const QByteArray &,int)),Qt::DirectConnection);
    connect(ui->serPort_Open_PsBtn, SIGNAL(clicked()),  this, SLOT(slot_serPort_open()));
    connect(ui->serPort_Close_PsBtn, SIGNAL(clicked()), this, SLOT(slot_serPort_close()));
    timeThreadTimer.driver_619->isToUI =false;

    SP_chargeType_cbbox = new QComboBox;
    SP_chargeType_cbbox->addItem(QString::fromUtf8("直流"));
    SP_chargeType_cbbox->addItem(QString::fromUtf8("交流"));
    SP_chargeType_cbbox->setCurrentIndex(0);

    SP_loadType_cbbox = new QComboBox;
    SP_loadType_cbbox->addItem(QString::fromUtf8("电动汽车"));
    SP_loadType_cbbox->addItem(QString::fromUtf8("负载箱"));
    SP_loadType_cbbox->setCurrentIndex(0);

    SP_measureType_cbbox = new QComboBox;
    SP_measureType_cbbox->addItem(QString::fromUtf8("手动"));
    SP_measureType_cbbox->addItem(QString::fromUtf8("自动"));
    SP_measureType_cbbox->addItem(QString::fromUtf8("半自动"));
    SP_measureType_cbbox->setCurrentIndex(0);


    ui->serPort_SP_TabWidget->setCellWidget(1,1,SP_chargeType_cbbox);
    ui->serPort_SP_TabWidget->setCellWidget(1,3,SP_loadType_cbbox);
  ui->serPort_SP_TabWidget->setCellWidget(4,3,SP_measureType_cbbox);

}


void MainWidget::slot_serPort_open()
{
    ui->serPort_Settings_GpBox->setEnabled(false);
    ui->serPort_Open_PsBtn->setEnabled(false);
    ui->serPort_Close_PsBtn->setEnabled(true);
    ui->serPort_Send_PsBtn->setEnabled(true);

    if (timeThreadTimer.driver_619->MagSerPort->isOpen())
        timeThreadTimer.driver_619->MagSerPort->close();
#if 1
    //Settings parameters
    QVariant temp;

    temp = ui->serPort_portName_CbBox->itemData(ui->serPort_portName_CbBox->currentIndex());
    timeThreadTimer.driver_619->MagSerPort->setPort(temp.value<QString>()); //Port

    temp = ui->serPort_baudRate_CbBox->itemData(ui->serPort_baudRate_CbBox->currentIndex());
    timeThreadTimer.driver_619->MagSerPort->setBaudRate(temp.value<BaudRateType>()); //BaudRate

    temp = ui->serPort_dataBit_CbBox->itemData(ui->serPort_dataBit_CbBox->currentIndex());
    timeThreadTimer.driver_619->MagSerPort->setDataBits(temp.value<DataBitsType>()); //DataBits

    temp = ui->serPort_parity_CbBox->itemData(ui->serPort_parity_CbBox->currentIndex());
    timeThreadTimer.driver_619->MagSerPort->setParity(temp.value<ParityType>()); //Parity

    temp = ui->serPort_stopBit_CbBox->itemData(ui->serPort_stopBit_CbBox->currentIndex());
    timeThreadTimer.driver_619->MagSerPort->setStopBits(temp.value<StopBitsType>()); //StopBits

    temp = ui->serPort_flowCtl_CbBox->itemData(ui->serPort_flowCtl_CbBox->currentIndex());
    timeThreadTimer.driver_619->MagSerPort->setFlowControl(temp.value<FlowType>()); //FlowControl

    timeThreadTimer.driver_619->MagSerPort->setTimeout(0, 100);
    timeThreadTimer.driver_619->MagSerPort->enableSending();
    timeThreadTimer.driver_619->MagSerPort->enableReceiving();

    if(!timeThreadTimer.driver_619->MagSerPort->open())
    {
        show_MsBox(QString::fromUtf8("串口打开失败"),5000);
        slot_serPort_close();
        return;
    }

    timeThreadTimer.driver_619->MagSerPort->receiveData();
#endif
}


void MainWidget::slot_serPort_close()
{
    timeThreadTimer.driver_619->MagSerPort->close();
    ui->serPort_Settings_GpBox->setEnabled(true);
    ui->serPort_Open_PsBtn->setEnabled(true);
    ui->serPort_Close_PsBtn->setEnabled(false);
    ui->serPort_Send_PsBtn->setEnabled(false);
}


void MainWidget::on_serPort_Send_PsBtn_clicked()
{
    QString Message;

    Message = ui->serPort_Send_TxEdit->toPlainText() ;

    if (ui->serPort_CR_CkBox->checkState() == Qt::Checked) //Retour a la ligne
        Message += "\x0D";


    if (ui->serPort_LF_CkBox->checkState() == Qt::Checked)//Saut de ligne
        Message += "\x0A";

    QByteArray temp(Message.toUtf8());
    timeThreadTimer.driver_619->isToUI=true;
    timeThreadTimer.driver_619->MagSerPort->sendData(temp);
}

#if 1
void  MainWidget::slt_serPort_RecDataToUI(const QByteArray &dataReceived,int intReturn)
{
    //qDebug()<<"slot_serPort_RecData";
    //timeThreadTimer.driver_619->serRecAllBtArray += dataReceived;
    ui->serPort_Rec_TxEdit->moveCursor(QTextCursor::End,  QTextCursor::MoveAnchor);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextStream in(dataReceived);
    in.setAutoDetectUnicode(false);
    in.setCodec(codec);
    QString decodedStr = in.readAll();

    ui->serPort_Rec_TxEdit->insertPlainText(decodedStr);
}
#endif

void MainWidget::on_serPort_CleanRec_PsBtn_clicked()//清空接收
{
     ui->serPort_Rec_TxEdit->clear();
}

void MainWidget::on_serPort_CleanSend_PsBtn_clicked()//清空发送
{
    ui->serPort_Send_TxEdit->clear();
}


void MainWidget::slot_serPort_shorCut_PsBtn()
{
    QString strTemp ;
    QPushButton *serPort_shorCut_PsBtn = qobject_cast<QPushButton *>(sender());

    if(serPort_shorCut_PsBtn==ui->serPort_RP_PsBtn)
    {
        strTemp  = "RP";
    }
    else if(serPort_shorCut_PsBtn==ui->serPort_AV_PsBtn)
    {
        strTemp  = "AV";
    }
    else if(serPort_shorCut_PsBtn==ui->serPort_RSM_PsBtn)
    {
        strTemp  = "RSM";
    }
    else if(serPort_shorCut_PsBtn==ui->serPort_ME_PsBtn)
    {
        strTemp  = "ME";
    }
    else if(serPort_shorCut_PsBtn==ui->serPort_RS_PsBtn)
    {
        strTemp  = "RS";
    }
    else if(serPort_shorCut_PsBtn==ui->serPort_RD_PsBtn)
    {
        strTemp  = "RD";
    }

    ui->serPort_Send_TxEdit->setText(strTemp);
    on_serPort_Send_PsBtn_clicked();
}
