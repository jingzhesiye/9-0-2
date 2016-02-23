#include "mainwidget.h"
#include "ui_mainwidget.h"

/*******************************************************************************************************
*Function:     发送有效值
*Description:  设置发送的数据值，同时关闭控件按钮操作，打开线程回读
*******************************************************************************************************/
void MainWidget::slt_SSMV_phasor_mode()
{
    hideAllControls();

    MainMenuBar.set_TitleStatus("相量图",0);
    ui->ToolBar_PsBtn_4->show();
    ui->ToolBar_PsBtn_4->setText(QString::fromUtf8("返回"));

    if(ui->ToolBar_PsBtn_3->text() == QString::fromUtf8("停止"))  //不是停止则刷新
    {
        for(int i =0;i<6;i++)
        {
          ui->RSMV_Phasor_TblWidget->item(i,1)->setText("");
          ui->RSMV_Phasor_TblWidget->item(i,3)->setText("");
        }
        timeThreadTimer.run(RSMV_PHASOR);
        RSMV_phasorPaint->updatePhasor_bool=true;//刷新  界面
        RSMV_phasorPaint->update();
        MainMenuBar.set_TitleStatus("SMV正在发送",1);
    }
   stackcurrentIndex = 2; //判断是否在SSMV_rms，由于这个界面第四个按钮已经占用，所以第二个界面作为判断
    ui->stackedWidget->setCurrentIndex(5);
}



