/******************************************************************************
*界面 : 有效值
*功能 : 9-1，9-2 接收数据
*人员 : jingzhesiye@163.com
*时间 : 2013.9.25
*******************************************************************************/

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "testPower/RSMV_option.h"

void MainWidget:: start_ME()
{
    //ui->serPort_RRF_PsBtn->click();
    qwtOption.PE_polygonF.clear();
    qwtOption.TE_polygonF.clear();
    timeThreadTimer.run(ME);
}


//从线程源，接收报文同时刷性界面 这个地方数值保留有效位6
void MainWidget::slt_ME_update(pMETYPE  pMETYPE_Temp)
{
    ui->ES_standard_TblWidget->item(0,1)->setText(Qt_f_to_string_6(pMETYPE_Temp->U1));
    ui->ES_standard_TblWidget->item(0,3)->setText(Qt_f_to_string_6(pMETYPE_Temp->P1));
    ui->ES_standard_TblWidget->item(0,5)->setText(Qt_f_to_string_6(pMETYPE_Temp->W1));//标准

    ui->ES_standard_TblWidget->item(1,1)->setText(Qt_f_to_string_6(pMETYPE_Temp->I1));
    ui->ES_standard_TblWidget->item(1,3)->setText(Qt_f_to_string_6(pMETYPE_Temp->Time/60));
    ui->ES_standard_TblWidget->item(1,5)->setText(Qt_f_to_string_6(pMETYPE_Temp->W1C));//被检

    ui->ES_TE_LnEdit->setText(QString::number(( ui->BMS_RD_TblWidget->item(2,3)->text().toFloat()- ui->ES_standard_TblWidget->item(1,3)->text().toFloat())/(ui->ES_standard_TblWidget->item(1,3)->text().toFloat()*0.01)));
    qwtOption.TE_polygonF<< QPointF(runTimeCal,ui->ES_TE_LnEdit->text().toFloat(0) );

   if(SP_measureType_cbbox->currentIndex() == 0)
    {
        ui->ES_PE_LnEdit->setText(QString::number(( ui->ES_standard_TblWidget->item(1,5)->text().toFloat()- ui->ES_standard_TblWidget->item(0,5)->text().toFloat())/(ui->ES_standard_TblWidget->item(0,5)->text().toFloat()*0.01)));
        qwtOption.PE_polygonF<< QPointF(runTimeCal, ui->ES_PE_LnEdit->text().toFloat(0) );
    }

    emit   sig_PE_wave_update();

   qwtOption.vol_polygonF<< QPointF(runTimeCal,pMETYPE_Temp->U1);
   qwtOption.cur_polygonF<< QPointF(runTimeCal,pMETYPE_Temp->I1);
   emit   sig_charging_wave_update();
}

void MainWidget::on_ES_standard_TblWidget_cellChanged(int row, int column)
{
    if(( row ==1 )&&( column == 5))
    {
        ui->ES_PE_LnEdit->setText(QString::number(( ui->ES_standard_TblWidget->item(1,5)->text().toFloat()- ui->ES_standard_TblWidget->item(0,5)->text().toFloat())/(ui->ES_standard_TblWidget->item(1,5)->text().toFloat()*0.01)));
        qwtOption.PE_polygonF<< QPointF(runTimeCal, ui->ES_PE_LnEdit->text().toFloat(0) );
      //qDebug()<<"asfs";
    }

}




