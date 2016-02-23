/******************************************************************************
*界面 : 有效值
*功能 : 9-1，9-2 接收数据
*人员 : jingzhesiye@163.com
*时间 : 2013.9.25
*******************************************************************************/

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "SMV/RSMV/RSMV_option.h"

//从线程源，接收报文同时刷性界面
void MainWidget::slt_RSMV_rms_update(pMETYPE  pMETYPE_Temp)
{
    char updateTypeME = ui->stackedWidget->currentIndex();

    if(updateTypeME==0)
    {
        if(pMETYPE_Temp->UL1>0.01)
        {
            RSMV_phasorPaint->UaRotate=pMETYPE_Temp->Phi1;
        }
        if(pMETYPE_Temp->UL2>0.01)
        {
            RSMV_phasorPaint->UbRotate=pMETYPE_Temp->Phi2;
        }
        if(pMETYPE_Temp->UL3>0.01)
        {
            RSMV_phasorPaint->UcRotate=pMETYPE_Temp->Phi3;
        }
        if(pMETYPE_Temp->IL1>0.01)
        {
            RSMV_phasorPaint->IaRotate=pMETYPE_Temp->Phi4;
        }
        if(pMETYPE_Temp->IL2>0.01)
        {
            RSMV_phasorPaint->IbRotate=pMETYPE_Temp->Phi5;
        }
        if(pMETYPE_Temp->IL3>0.01)
        {
            RSMV_phasorPaint->IcRotate=pMETYPE_Temp->Phi6;
        }

        ui->RSMV_phasor_TblWidget->item(0,1)->setText(QString::number(pMETYPE_Temp->UL1,'d',4));//保留4位
        ui->RSMV_phasor_TblWidget->item(0,3)->setText(QString::number(RSMV_phasorPaint->UaRotate,'d',4));

        ui->RSMV_phasor_TblWidget->item(0,5)->setText(QString::number(pMETYPE_Temp->IL1,'d',4));
        ui->RSMV_phasor_TblWidget->item(0,7)->setText(QString::number(RSMV_phasorPaint->IaRotate,'d',4));

        ui->RSMV_phasor_TblWidget->item(0,9)->setText(QString::number(pMETYPE_Temp->P1,'d',4));

        ui->RSMV_phasor_TblWidget->item(1,1)->setText(QString::number(pMETYPE_Temp->UL2,'d',4));
        ui->RSMV_phasor_TblWidget->item(1,3)->setText(QString::number(RSMV_phasorPaint->UbRotate,'d',4));

        ui->RSMV_phasor_TblWidget->item(1,5)->setText(QString::number(pMETYPE_Temp->IL2,'d',4));
        ui->RSMV_phasor_TblWidget->item(1,7)->setText(QString::number(RSMV_phasorPaint->IbRotate,'d',4));
        ui->RSMV_phasor_TblWidget->item(1,9)->setText(QString::number(pMETYPE_Temp->P2,'d',4));


        ui->RSMV_phasor_TblWidget->item(2,1)->setText(QString::number(pMETYPE_Temp->UL3,'d',4));
        ui->RSMV_phasor_TblWidget->item(2,3)->setText(QString::number(RSMV_phasorPaint->UcRotate,'d',4));

        ui->RSMV_phasor_TblWidget->item(2,5)->setText(QString::number(pMETYPE_Temp->IL3,'d',4));
        ui->RSMV_phasor_TblWidget->item(2,7)->setText(QString::number(RSMV_phasorPaint->IcRotate,'d',4));
        ui->RSMV_phasor_TblWidget->item(2,9)->setText(QString::number(pMETYPE_Temp->P3,'d',4));

        ui->RSMV_phasor_TblWidget->item(3,1)->setText(QString::number(pMETYPE_Temp->SP,'d',4));//有功功率
        ui->RSMV_phasor_TblWidget->item(3,3)->setText(QString::number(pMETYPE_Temp->Freq,'d',4));




        RSMV_phasorPaint->update();
      }
     else if(updateTypeME==1)
     {
        ui->RSMV_harmonic_rms_TblWidget->item(0,1)->setText(QString::number(pMETYPE_Temp->UL1,'d',4));//保留4位
        ui->RSMV_harmonic_rms_TblWidget->item(0,3)->setText(QString::number(pMETYPE_Temp->IL1,'d',4));

        ui->RSMV_harmonic_rms_TblWidget->item(1,1)->setText(QString::number(pMETYPE_Temp->UL2,'d',4));
        ui->RSMV_harmonic_rms_TblWidget->item(1,3)->setText(QString::number(pMETYPE_Temp->IL2,'d',4));

        ui->RSMV_harmonic_rms_TblWidget->item(2,1)->setText(QString::number(pMETYPE_Temp->UL3,'d',4));
        ui->RSMV_harmonic_rms_TblWidget->item(2,3)->setText(QString::number(pMETYPE_Temp->IL3,'d',4));

        ui->RSMV_harmonic_rms_TblWidget->item(3,1)->setText(QString::number(pMETYPE_Temp->Freq,'d',4));
     }

      //timeThreadTimer.mutexUpdate.unlock();
}

//清空数据
void MainWidget::clean_stackedWidgetIndex1()
{
      for(int i =0;i<3;i++)
      {
          ui->RSMV_phasor_TblWidget->item(i,1)->setText("0");
          ui->RSMV_phasor_TblWidget->item(i,3)->setText("0");
          ui->RSMV_phasor_TblWidget->item(i,5)->setText("0");
      }

    ui->RSMV_energy_ESTD_LnEdit->setText("0");
    ui->RSMV_energy_error_LnEdit->setText("0");
    ui->RSMV_energy_ES_PE_LnEdit->setText("0");
    ui->RSMV_wave_vol_QwtPlot->replot();

    RSMV_ESTD_PolygonF.clear();
    RSMV.wave_ESTD_curve->setSamples( RSMV_ESTD_PolygonF );
    ui->RSMV_energyError_QwtPlot->replot();

}
