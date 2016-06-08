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
    timeThreadTimer.run(ME);
}


//从线程源，接收报文同时刷性界面
void MainWidget::slt_ME_update(pMETYPE  pMETYPE_Temp)
{
      //qDebug()<<QString::number(pMETYPE_Temp->Price);
    ui->ES_standard_TblWidget->item(0,1)->setText(QString::number(pMETYPE_Temp->U1,'d',1));
    ui->ES_standard_TblWidget->item(0,3)->setText(QString::number(pMETYPE_Temp->P1,'d',1));
    ui->ES_standard_TblWidget->item(0,5)->setText(QString::number(pMETYPE_Temp->W1,'d',1));

    ui->ES_standard_TblWidget->item(1,1)->setText(QString::number(pMETYPE_Temp->I1,'d',1));
    ui->ES_standard_TblWidget->item(1,3)->setText(QString::number(pMETYPE_Temp->Time,'d',1));
    ui->ES_standard_TblWidget->item(1,5)->setText(QString::number(pMETYPE_Temp->W1C,'d',1));


    //ui->ES_PE_LnEdit->setText();
    ui->ES_PE_LnEdit->setText(QString::number((pMETYPE_Temp->W1C - pMETYPE_Temp->W1)/(pMETYPE_Temp->W1*0.01)));

}

//清空数据
void MainWidget::clean_main_SkWidget_1()
{
      for(int i =0;i<3;i++)
      {
          ui->BMS_RD_TblWidget->item(i,1)->setText("0");
          ui->BMS_RD_TblWidget->item(i,3)->setText("0");
          ui->BMS_RD_TblWidget->item(i,5)->setText("0");
      }
      ui->BMS_RD_TblWidget->item(3,1)->setText("0");

      for(int i =0;i<2;i++)
      {
          ui->RS_charger_TblWidget->item(i,1)->setText("0");
          ui->RS_charger_TblWidget->item(i,3)->setText("0");
          ui->RS_charger_TblWidget->item(i,5)->setText("0");
      }

      for(int i =0;i<2;i++)
      {
        ui->ES_standard_TblWidget->item(i,1)->setText("0");
        ui->ES_standard_TblWidget->item(i,3)->setText("0");
        ui->ES_standard_TblWidget->item(i,5)->setText("0");

      }

    ui->ES_PE_LnEdit->setText("0");
    ui->ES_TE_LnEdit->setText("0");
    ui->charging_wave_QwtPlot->replot();

    ESTD_PolygonF.clear();
    RSMV.wave_ESTD_curve->setSamples( ESTD_PolygonF );
    ui->ES_PE_QwtPlot->replot();

}

void MainWidget::clean_main_SkWidget_2()
{
    for(int i =0;i<2;i++)
    {
      ui->RRF_ripple_TblWidget->item(i,0)->setText("0");
      ui->RRF_ripple_TblWidget->item(i,1)->setText("0");
      ui->RRF_ripple_TblWidget->item(i,2)->setText("0");
   }
}


