#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "testPower/RSMV_option.h"

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
