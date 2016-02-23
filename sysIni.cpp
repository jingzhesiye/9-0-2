/******************************************************************************
*dec:软件配置信息
*******************************************************************************/
#include "mainwidget.h"
#include "QSettings"

void MainWidget::read_ini()
{
    QString strTemp;
    QSettings *configIniRead = new QSettings("Sys.ini", QSettings::IniFormat);

    strTemp =configIniRead->value("serPort/portName").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("0");
       write_ini("serPort/portName",strTemp);
    }
    ui->serPort_portName_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("serPort/baudRate").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("9");
       write_ini("serPort/baudRate",strTemp);
    }
    ui->serPort_baudRate_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("serPort/dataBit").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("3");
       write_ini("serPort/dataBit",strTemp);
    }
    ui->serPort_dataBit_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("serPort/parity").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("0");
       write_ini("serPort/parity",strTemp);
    }
    ui->serPort_parity_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("serPort/stopBit").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1");
       write_ini("serPort/stopBit",strTemp);
    }
    ui->serPort_stopBit_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("serPort/flowCtl").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("0");
       write_ini("serPort/flowCtl",strTemp);
    }
    ui->serPort_flowCtl_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("SP/METERCONST").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("20000");
       write_ini("SP/METERCONST",strTemp);
    }
    ui->serPort_METERCONST_LnEdit->setText(strTemp);


    strTemp =configIniRead->value("SP/CONST").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("20000");
       write_ini("SP/CONST",strTemp);
    }
    ui->serPort_CONST_LnEdit->setText(strTemp);

    strTemp =configIniRead->value("SP/CHECKNUM").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("5");
       write_ini("SP/CHECKNUM",strTemp);
    }
    ui->serPort_CHECKNUM_LnEdit->setText(strTemp);

    strTemp =configIniRead->value("SP/CHECKTYPE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("0");
       write_ini("SP/CHECKTYPE",strTemp);
    }
    ui->serPort_CHECKTYPE_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("RANGE/VR").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1");
       write_ini("RANGE/VR",strTemp);
    }
    ui->serPort_VR_CbBox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("RANGE/CR").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1");
       write_ini("RANGE/CR",strTemp);
    }
    ui->serPort_CR_CbBox->setCurrentIndex(strTemp.toInt(0,10));
}


void MainWidget::on_serPort_portName_CbBox_activated(int index)
{
    write_ini("serPort/portName",QString::number(index));
}

void MainWidget::on_serPort_dataBit_CbBox_activated(int index)
{
    write_ini("serPort/dataBit",QString::number(index));
}

void MainWidget::on_serPort_baudRate_CbBox_activated(int index)
{
    write_ini("serPort/baudRate",QString::number(index));
}

void MainWidget::on_serPort_stopBit_CbBox_activated(int index)
{
    write_ini("serPort/stopBit",QString::number(index));
}

void MainWidget::on_serPort_parity_CbBox_activated(int index)
{
    write_ini("serPort/parity",QString::number(index));
}

void MainWidget::on_serPort_flowCtl_CbBox_activated(int index)
{
   write_ini("serPort/flowCtl",QString::number(index));
}

void MainWidget::on_serPort_METERCONST_LnEdit_textChanged(const QString &arg1)
{
    write_ini("SP/METERCONST",arg1);
}

void MainWidget::on_serPort_CONST_LnEdit_textChanged(const QString &arg1)
{
    write_ini("SP/CONST",arg1);
}

void MainWidget::on_serPort_CHECKNUM_LnEdit_textChanged(const QString &arg1)
{
      write_ini("SP/CHECKNUM",arg1);
}

void MainWidget::on_serPort_CHECKTYPE_CbBox_activated(int index)
{
     write_ini("SP/CHECKTYPE",QString::number(index));
}

void MainWidget::on_serPort_VR_CbBox_activated(int index)
{
     write_ini("RANGE/VR",QString::number(index));
}

void MainWidget::on_serPort_CR_CbBox_activated(int index)
{
     write_ini("RANGE/CR",QString::number(index));
}

void MainWidget:: write_ini(QString path,QString arg)
{
    QSettings *configIniWrite = new QSettings("Sys.ini", QSettings::IniFormat);
    configIniWrite->setValue(path, arg);
    delete configIniWrite;
}






