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

    strTemp =configIniRead->value("SP/SAMRATE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("2");
       write_ini("SP/SAMRATE",strTemp);
    }
    ui->serPort_SP_TabWidget->item(0,1)->setText(strTemp);


    strTemp =configIniRead->value("SP/PRODUCT").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("AOTEXUN");
       write_ini("SP/PRODUCT",strTemp);
    }
    ui->serPort_SP_TabWidget->item(0,3)->setText(strTemp);


    strTemp =configIniRead->value("SP/VOLTAGERANGE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("750.0");
       write_ini("SP/VOLTAGERANGE",strTemp);
    }
     ui->serPort_SP_TabWidget->item(2,1)->setText(strTemp);

    strTemp =configIniRead->value("SP/CURRENTRANGE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("500.0");
       write_ini("SP/CURRENTRANGE",strTemp);
    }

    ui->serPort_SP_TabWidget->item(2,3)->setText(strTemp);

    strTemp =configIniRead->value("SP/2000.0").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1");
       write_ini("SP/METERCONST",strTemp);
    }
    ui->serPort_SP_TabWidget->item(3,1)->setText(strTemp);

    strTemp =configIniRead->value("SP/CONST1").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("3600.0");
       write_ini("SP/CONST1",strTemp);
    }
    ui->serPort_SP_TabWidget->item(3,3)->setText(strTemp);

    strTemp =configIniRead->value("SP/PRICE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1.0");
       write_ini("SP/PRICE",strTemp);
    }
    ui->serPort_SP_TabWidget->item(4,1)->setText(strTemp);

    strTemp =configIniRead->value("SP/CHARGETYPE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1");
       write_ini("SP/CHARGETYPE",strTemp);
    }
    SP_chargeType_cbbox->setCurrentIndex(strTemp.toInt(0,10));

    strTemp =configIniRead->value("SP/LOADTYPE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1");
       write_ini("SP/LOADTYPE",strTemp);
    }
    SP_loadType_cbbox->setCurrentIndex(strTemp.toInt(0,10));


    strTemp =configIniRead->value("SP/MEASURETYPE").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1");
       write_ini("SP/MEASURETYPE",strTemp);
    }
    SP_measureType_cbbox->setCurrentIndex(strTemp.toInt(0,10));

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

void MainWidget:: write_ini(QString path,QString arg)
{
    QSettings *configIniWrite = new QSettings("Sys.ini", QSettings::IniFormat);
    configIniWrite->setValue(path, arg);
    delete configIniWrite;
}
