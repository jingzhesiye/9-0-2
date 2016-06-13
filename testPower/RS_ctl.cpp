#include "mainwidget.h"

void MainWidget:: start_RS()
{
     qwtOption.vol_polygonF.clear();
     qwtOption.cur_polygonF.clear();
     timeThreadTimer.run(RS);
}

//数据为交换频繁的BMS协议报文，更新频率高
void MainWidget:: slt_RS_update(pRSTYPE pRSTYPE_Temp)
{
    QStringList strList;
    ui->RS_charger_TblWidget->item(0,1)->setText(QString::number(pRSTYPE_Temp->VOLTAGEOUT*0.1,'d',1));
    ui->RS_charger_TblWidget->item(1,1)->setText(QString::number(pRSTYPE_Temp->CURRENCEOUT*0.1,'d',1));//实时电流输出.A

    ui->BMS_RD_TblWidget->item(2,1)->setText(QString::number(pRSTYPE_Temp->VOLTAGENEED*0.1,'d',1));//充电电压需求.v
    ui->BMS_RD_TblWidget->item(3,1)->setText(QString::number(pRSTYPE_Temp->CURRENCENEED*0.1,'d',1));//充电电流需求.A
    ui->BMS_RD_TblWidget->item(2,3)->setText(QString::number(pRSTYPE_Temp->CHARGETIME,'d',1));//累计充电时间

    float f_Std;
    f_Std = ui->ES_standard_TblWidget->item(1,3)->text().toFloat(0);
    ui->ES_TE_LnEdit->setText(QString::number((pRSTYPE_Temp->CHARGETIME - f_Std)/(f_Std*0.01)));

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





