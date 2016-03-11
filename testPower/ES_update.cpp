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
    //timeThreadTimer.runTimeCal =  0;
    ESTD_PolygonF.clear();
    timeThreadTimer.run(ESTD);
}

//PE;1.0E-3<CR>	有功误差
//QE;1.0E-3<CR> 无功误差
//FE;1.0E-3<CR> 比值误差
//AE;1.0E-3<CR>	角度误差
//PULNUM;1<CR>	检定的剩余脉冲数
//CE;1<CR>	    复合误差

void MainWidget::slt_ES_update(pESTYPE pESTYPE_Temp)//电能测试误差状态
{
    ui->ES_PE_LnEdit->setText(QString::number(pESTYPE_Temp->PE,'d',3));
    ui->ES_TE_LnEdit->setText(QString::number(pESTYPE_Temp->TE,'d',3));
    //qDebug()<<"slt_ES_update"<<QString::number(pESTYPE_Temp->PE);
}

//S;1.0E-3<CR>	S值
//VALID;1<CR> 	1:有效 0:无效
//B1;1.0E-3<CR> 	备用
//B2;1.0E-3<CR>	备用
//ESTDACK


void MainWidget:: startENERGY_PUL()//电能脉冲
{
    timeThreadTimer.run(ENERGY_PUL);
}

//FLOAT64	WP;		//有功电能
//FLOAT64	WQ;		//无功电能
//UINT32	NP;		//有功脉冲累积个数
//UINT32	NQ;		//有功脉冲累积个数
//FLOAT64	P;		//有功功率
//FLOAT64	Q;		//无功功率
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
#if 0
//将误差记录保存到报表
void MainWidget::on_RSMV_energy_from_PsBtn_clicked()
{
//   QString strESTD,strPE;

//   strESTD  = QString::fromUtf8("电能误差记录(%): ")+ui->RSMV_energy_ESTD_LnEdit->text()+"\n\r";
//   strPE   = QString::fromUtf8("标准偏差记录(%): ")+ui->RSMV_energy_ES_PE_LnEdit->text()+"\n\r";

//    ui->from_error_TxEdit->append(strESTD+strPE);
}
#endif
