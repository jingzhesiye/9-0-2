#include "mainwidget.h"
#include "ui_mainwidget.h"

/*******************************************************************************************************
*Function:     发送有效值
*Description:  设置发送的数据值，同时关闭控件按钮操作，打开线程回读
*******************************************************************************************************/
void MainWidget::slt_SSMV_wave_mode()
{
    hideAllControls();

    MainMenuBar.set_TitleStatus("波形图",0);
    ui->ToolBar_PsBtn_4->show();
    ui->ToolBar_PsBtn_4->setText(QString::fromUtf8("返回"));

    if(ui->ToolBar_PsBtn_3->text() == QString::fromUtf8("停止"))  //不是停止则刷新
    {
        slt_RSMV_wave_isSend(true);
        ui->ToolBar_PsBtn_3->setChecked(true);
    }

    set_TblWdiget_Header(ui->RSMV_Wave_Cur_TblWidget,false,false);
    set_TblWdiget_Header(ui->RSMV_Wave_Vol_TblWidget,false,false);

    stackcurrentIndex = 2;
    ui->stackedWidget->setCurrentIndex(4);

}

