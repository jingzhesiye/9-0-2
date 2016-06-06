#include "mainwidget.h"
#include "ui_mainwidget.h"

//设置参数
void MainWidget::on_serPort_write_SP_PsBtn_clicked()
{

    pSPTYPE   pSPTYPE_Temp =NULL;
    if((pSPTYPE_Temp=(pSPTYPE)calloc(1,sizeof(SPTYPE)))==NULL)
    {
        free(pSPTYPE_Temp);
        pSPTYPE_Temp=NULL;
        return ;
    }

    pSPTYPE_Temp->SAMRATE = atof(ui->serPort_SP_TabWidget->item(0,1)->text().toLatin1().data());
    strcpy((char *)pSPTYPE_Temp->PRODUCT, ui->serPort_SP_TabWidget->item(0,3)->text().toStdString().c_str());
    //qDebug("dddd%s",pSPTYPE_Temp->PRODUCT);
    pSPTYPE_Temp->VOLTAGERANGE = atof(ui->serPort_SP_TabWidget->item(2,1)->text().toLatin1().data());
    pSPTYPE_Temp->CURRENTRANGE = atof(ui->serPort_SP_TabWidget->item(2,3)->text().toLatin1().data());

    pSPTYPE_Temp->METERCONST  = atof(ui->serPort_SP_TabWidget->item(3,1)->text().toLatin1().data());
    pSPTYPE_Temp->CONST1      = atof(ui->serPort_SP_TabWidget->item(3,3)->text().toLatin1().data());
    pSPTYPE_Temp->PRICE       = ui->serPort_SP_TabWidget->item(4,1)->text().toFloat(0);

    //qDebug("xxx=%f",pSPTYPE_Temp->PRICE);
    pSPTYPE_Temp->CHARGETYPE  =  SP_chargeType_cbbox->currentIndex();
    pSPTYPE_Temp->LOADTYPE    =  SP_loadType_cbbox->currentIndex();
    pSPTYPE_Temp->MEASURETYPE =  SP_measureType_cbbox->currentIndex();


    if(timeThreadTimer.setSP(pSPTYPE_Temp)==false )
    {
        show_MsBox(QString::fromUtf8("设置失败"),3000);
        return ;
    }

    show_MsBox(QString::fromUtf8("设置成功"),3000);

    write_ini("SP/SAMRATE",ui->serPort_SP_TabWidget->item(0,1)->text());
    write_ini("SP/PRODUCT",ui->serPort_SP_TabWidget->item(0,3)->text());

    write_ini("SP/VOLTAGERANGE",ui->serPort_SP_TabWidget->item(2,1)->text());
    write_ini("SP/CURRENTRANGE",ui->serPort_SP_TabWidget->item(2,3)->text());

    write_ini("SP/METERCONST",ui->serPort_SP_TabWidget->item(3,1)->text());
    write_ini("SP/CONST",ui->serPort_SP_TabWidget->item(3,3)->text());
    write_ini("SP/PRICE",ui->serPort_SP_TabWidget->item(4,1)->text());

    write_ini("SP/CHARGETYPE",QString::number(SP_chargeType_cbbox->currentIndex()));
    write_ini("SP/LOADTYPE",QString::number(SP_loadType_cbbox->currentIndex()));
    write_ini("SP/MEASURETYPE",QString::number(SP_measureType_cbbox->currentIndex()));

}

void MainWidget::on_serPort_read_SP_PsBtn_clicked()
{

    pSPTYPE   pSPTYPE_Temp =NULL;
    if((pSPTYPE_Temp=(pSPTYPE)calloc(1,sizeof(SPTYPE)))==NULL)
    {
        free(pSPTYPE_Temp);
        pSPTYPE_Temp=NULL;
        return ;
    }

    if(timeThreadTimer.getSP(pSPTYPE_Temp)==false )
    {
        show_MsBox(QString::fromUtf8("读取失败"),3000);
        return ;
    }

    ui->serPort_SP_TabWidget->item(0,1)->setText(QString::number(pSPTYPE_Temp->SAMRATE,'d',1));
    ui->serPort_SP_TabWidget->item(0,3)->setText(QString::fromUtf8((char*)pSPTYPE_Temp->PRODUCT));

    ui->serPort_SP_TabWidget->item(2,1)->setText(QString::number(pSPTYPE_Temp->VOLTAGERANGE,'d',1));
    ui->serPort_SP_TabWidget->item(2,3)->setText(QString::number(pSPTYPE_Temp->CURRENTRANGE,'d',1));

    ui->serPort_SP_TabWidget->item(3,1)->setText(QString::number(pSPTYPE_Temp->METERCONST,'d',1));
    ui->serPort_SP_TabWidget->item(3,3)->setText(QString::number(pSPTYPE_Temp->CONST1,'d',1));

    ui->serPort_SP_TabWidget->item(4,1)->setText(QString::number(pSPTYPE_Temp->PRICE,'d',1));

    SP_chargeType_cbbox->setCurrentIndex(pSPTYPE_Temp->CHARGETYPE);
    SP_loadType_cbbox->setCurrentIndex(pSPTYPE_Temp->LOADTYPE);
    SP_measureType_cbbox->setCurrentIndex(pSPTYPE_Temp->MEASURETYPE);

    free(pSPTYPE_Temp);
    pSPTYPE_Temp=NULL;

    show_MsBox(QString::fromUtf8("读取成功"),3000);
}
