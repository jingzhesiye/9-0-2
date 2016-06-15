#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget:: start_RD()
{
    timeThreadTimer.run(RD);
}

//读取数据
void MainWidget:: slt_RD_update(pRDTYPE pRDTYPE_Temp)
{

    ui->BMS_RD_TblWidget->item(0,1)->setText(QString::number(pRDTYPE_Temp->VOLTAGEINMAX,'d',1));
    ui->BMS_RD_TblWidget->item(1,1)->setText(QString::number(pRDTYPE_Temp->CURRENCEINMAX,'d',1));

    ui->BMS_RD_TblWidget->item(0,3)->setText(QString::number(pRDTYPE_Temp->VOLTAGEMEASURE,'d',1));
    ui->BMS_RD_TblWidget->item(1,3)->setText(QString::number(pRDTYPE_Temp->CURRENCEMEASURE,'d',1));
    //ui->BMS_RD_TblWidget->item(2,3)->setText(QString::number(pRDTYPE_Temp->TIMECHARGE,'d',1));//计充电时间

    ui->BMS_RD_TblWidget->item(0,5)->setText(QString::number(pRDTYPE_Temp->VOLTAGEBAT,'d',1)); //电池总电压:
    ui->BMS_RD_TblWidget->item(1,5)->setText(QString::number(pRDTYPE_Temp->SOC,'d',1));
    ui->BMS_RD_TblWidget->item(2,5)->setText(QString::number(pRDTYPE_Temp->TIMEREMAIN,'d',1)); //剩余充电时间

    ui->RS_charger_TblWidget->item(0,3)->setText(QString::number(pRDTYPE_Temp->VOLTAGEOUTMAX,'d',1)); //最高输出电压
    ui->RS_charger_TblWidget->item(0,5)->setText(QString::number(pRDTYPE_Temp->VOLTAGEOUTMIN,'d',1)); //最低输出电压

    ui->RS_charger_TblWidget->item(1,3)->setText(QString::number(pRDTYPE_Temp->CURRENCEOUTMAX,'d',1)); //最高输出电流：
    ui->RS_charger_TblWidget->item(1,5)->setText(QString::number(pRDTYPE_Temp->POWER,'d',1));          //输出总电能
}
