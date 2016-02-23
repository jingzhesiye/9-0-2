#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget:: slt_RS_update(pRSTYPE pRSTYPE_Temp)
{
   // qDebug()<<"11111111111slt_RS_update";
    ui->charger_RS_TblWidget->item(0,1)->setText(QString::number(pRSTYPE_Temp->VOLTAGEOUT,'d',1));
    ui->charger_RS_TblWidget->item(1,1)->setText(QString::number(pRSTYPE_Temp->CURRENCEOUT,'d',1));//实时电流输出.A

    ui->RSMV_phasor_TblWidget->item(2,1)->setText(QString::number(pRSTYPE_Temp->VOLTAGENEED,'d',1));//充电电压需求.v
    ui->RSMV_phasor_TblWidget->item(3,1)->setText(QString::number(pRSTYPE_Temp->CURRENCENEED,'d',1));//充电电流需求.A

    ui->RSMV_phasor_TblWidget->item(2,3)->setText(QString::number(pRSTYPE_Temp->CHARGETIME,'d',1));//累计充电时间


    if(pRSTYPE_Temp->STATE==0)
    {
           ui->BMS_cntState_Label->setText(QString::fromUtf8("断开"));
    }
    else
    {
           ui->BMS_cntState_Label->setText(QString::fromUtf8("链接"));
    }

    if(pRSTYPE_Temp->CHARGEMODE==0)
    {
        ui->BMS_chargeMode_Label->setText(QString::fromUtf8("恒流"));
    }
    else
    {
        ui->BMS_chargeMode_Label->setText(QString::fromUtf8("恒压"));
    }
}
