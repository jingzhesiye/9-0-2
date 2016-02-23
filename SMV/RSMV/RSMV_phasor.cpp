/******************************************************************************
*界面: 相量图
*实现:  9-1，9-2 接收数据
*人员: jingzhesiye@163.com
*时间: 2013.9.25
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget::slt_RSMV_phasor_mode(void)
{
    hideAllControls();
    MainMenuBar.set_TitleStatus("相量图",0);

    set_TblWdiget_Header( ui->RSMV_Phasor_TblWidget ,false,false);

    ui->ToolBar_PsBtn_1->show();
    ui->ToolBar_PsBtn_1->setText(QString::fromUtf8("功能切换"));
    ui->ToolBar_PsBtn_3->show();
    ui->ToolBar_PsBtn_3->setCheckable(true);
    ui->ToolBar_PsBtn_3->setText(QString::fromUtf8("接收"));
    ui->stackedWidget->setCurrentIndex(5);

    RSMV_phasorPaint->updatePhasor_bool=true;//刷新  界面
    RSMV_phasorPaint->update();
}

void MainWidget::slt_RSMV_phasor_start(void)
{
    char columnItem[2]={1,3};
    set_TblWdiget_Data(ui->RSMV_RMS_TblWidget, columnItem,2, 6);

     timeThreadTimer.IsLanOn(true);
    timeThreadTimer.run(RSMV_PHASOR);
    MainMenuBar.set_TitleStatus("SMV正在接收",2);
    lock_MainMenubar(8);
}

void MainWidget::slt_RSMV_phasor_stop(void)
{
     timeThreadTimer.IsLanOn(false);
    MainMenuBar.set_TitleStatus("SMV接收",0);
    showInformationBox("停止接收");
    timeThreadTimer.stop();
    unlock_MainMenubar();
}

void MainWidget::slt_RSMV_phasor_update(pMETYPE  pMETYPE_Temp)
{
    RSMV_phasorPaint->UaRotate=0;                              //1  公式参考XL806 测试窗口含义
    RSMV_phasorPaint->IaRotate=0-pMETYPE_Temp->Phi1;           //2
    RSMV_phasorPaint->IbRotate=RSMV_phasorPaint->IaRotate-pMETYPE_Temp->Phi4;//3
    RSMV_phasorPaint->IcRotate=RSMV_phasorPaint->IaRotate-pMETYPE_Temp->Phi6;//4

    RSMV_phasorPaint->UbRotate=RSMV_phasorPaint->IbRotate+pMETYPE_Temp->Phi2;//5
    RSMV_phasorPaint->UcRotate=RSMV_phasorPaint->IcRotate+pMETYPE_Temp->Phi3;//6


    ui->RSMV_Phasor_TblWidget->item(0,1)->setText(QString::number(pMETYPE_Temp->UL1,'d',4));//保留4位
    ui->RSMV_Phasor_TblWidget->item(1,1)->setText(QString::number(pMETYPE_Temp->IL1,'d',4));

    ui->RSMV_Phasor_TblWidget->item(2,1)->setText(QString::number(pMETYPE_Temp->UL2,'d',4));
    ui->RSMV_Phasor_TblWidget->item(3,1)->setText(QString::number(pMETYPE_Temp->IL2,'d',4));

    ui->RSMV_Phasor_TblWidget->item(4,1)->setText(QString::number(pMETYPE_Temp->UL3,'d',4));
    ui->RSMV_Phasor_TblWidget->item(5,1)->setText(QString::number(pMETYPE_Temp->IL3,'d',4));

    ui->RSMV_Phasor_TblWidget->item(0,3)->setText(QString::number(RSMV_phasorPaint->UaRotate,'d',4));
    ui->RSMV_Phasor_TblWidget->item(1,3)->setText(QString::number(RSMV_phasorPaint->IaRotate,'d',4));

    ui->RSMV_Phasor_TblWidget->item(2,3)->setText(QString::number(RSMV_phasorPaint->UbRotate,'d',4));
    ui->RSMV_Phasor_TblWidget->item(3,3)->setText(QString::number(RSMV_phasorPaint->IbRotate,'d',4));

    ui->RSMV_Phasor_TblWidget->item(4,3)->setText(QString::number(RSMV_phasorPaint->UcRotate,'d',4));
    ui->RSMV_Phasor_TblWidget->item(5,3)->setText(QString::number(RSMV_phasorPaint->IcRotate,'d',4));

     RSMV_phasorPaint->update();
}


