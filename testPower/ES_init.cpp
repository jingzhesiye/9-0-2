#include "mainwidget.h"
#include "ui_mainwidget.h"

/******************************************************************************
*界面:计算电能误差
*******************************************************************************/

void MainWidget:: startES()
{
    timeThreadTimer.run(ES);
}

void MainWidget:: startESTD()//标准方差s值
{
    ESTD_PolygonF.clear();
    timeThreadTimer.run(ESTD);
}

void MainWidget::slt_ES_update(pESTYPE pESTYPE_Temp)//电能测试误差状态
{
    ui->ES_PE_LnEdit->setText(QString::number(pESTYPE_Temp->PE,'d',3));
    ui->ES_TE_LnEdit->setText(QString::number(pESTYPE_Temp->TE,'d',3));
    //qDebug()<<"slt_ES_update"<<QString::number(pESTYPE_Temp->PE);
}

void MainWidget:: startENERGY_PUL()//电能脉冲
{
    timeThreadTimer.run(ENERGY_PUL);
}

void MainWidget::slt_ENERGY_PUL_update(pPULSEPOW pPULSEPOW_Temp)
{
   // ui->RSMV_energy_pul_LnEdit->setText(QString::number(pPULSEPOW_Temp->WP,'d',5));
}

void MainWidget:: startENERGY_STD()//电能脉冲
{
    timeThreadTimer.run(ENERGY_STD);
}

//A表示测量值,
//E表示正常值,
//公式:(A-E)/(E/100)=百分之？超出为正，过少为负
void MainWidget::slt_ENERGY_STD_update(pPULSEPOW pPULSEPOW_Temp)
{
     float  stdFloat,pulFloat;
     // ui->RSMV_energy_error_LnEdit->setText(QString::(pulFloat - stdFloat)/stdFloat * 100);
    //ui->RSMV_energy_error_LnEdit->setText(QString::number((pulFloat - stdFloat)/stdFloat * 100,'d',5));
}

