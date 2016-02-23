/******************************************************************************
*界面 : 有效值
*功能 : 9-1，9-2 发送数据
*人员 : jingzhesiye@163.com
*时间 : 2014.3.10
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget::on_homePage_SSMV_PsBtn_clicked()  // SSMV  IEC61850 -1 /-2 /604488
{
   hideAllControls();
   MainMenuBar.set_TitleStatus("有效值",0);
   set_TblWdiget_Header( ui->SSMV_RMS_TblWidget ,false,false);

   ui->ToolBar_PsBtn_1->show();
   ui->ToolBar_PsBtn_1->setText(QString::fromUtf8("功能切换"));
   ui->ToolBar_PsBtn_2->show();
   ui->ToolBar_PsBtn_2->setText(QString::fromUtf8("设置"));
   ui->ToolBar_PsBtn_3->show();
   ui->ToolBar_PsBtn_3->setCheckable(true);
   ui->ToolBar_PsBtn_3->setText(QString::fromUtf8("发送"));
   ui->ToolBar_PsBtn_4->show();
   ui->ToolBar_PsBtn_4->setText(QString::fromUtf8("显示切换"));
   stackcurrentIndex = 1;
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWidget::on_SSMV_SetPF_PsBtn_clicked()
{
     float  floatTemp_1,floatTemp_2,floatTemp_3;     //量程／根号三 * %
     for(int i =0;i<6;i++)
     {
         if(i<3)
         {
           floatTemp_1=pSPTYPE_Data->VOLTAGERANGE / 1.73205;   //电压量程*1000(v)/根号3
         }
         else
         {
             floatTemp_1=pSPTYPE_Data->CURRENTRANGE;   //电流量程
         }
         floatTemp_2=ui->SSMV_SetPF_TblWidget->item(i,1)->text().toFloat(0)*0.01;     //校验百分数
         floatTemp_3=floatTemp_1*floatTemp_2;
         ui->SSMV_RMS_TblWidget->item(i,1)->setText(QString("%1").arg(floatTemp_3)); //6通道值加载
    }
}
/*******************************************************************************************************
*Function:     发送有效值
*Description:  设置发送的数据值，同时关闭控件按钮操作，打开线程回读
*******************************************************************************************************/
void MainWidget::slt_SSMV_rms_start()
{
    float VOLTAGERANGE ,CURRENTRANGE,METYPE_Temp[35];
    char MEable_Temp[35];
    VOLTAGERANGE   = pSPTYPE_Data->VOLTAGERANGE;            //电压量程
    CURRENTRANGE   = pSPTYPE_Data->CURRENTRANGE;            //电流量程

    METYPE_Temp[0]=QString::number((ui->SSMV_RMS_TblWidget->item(0,1)->text().toFloat(0)* 100) / VOLTAGERANGE ,'d',4).toFloat(0);//保留小数点两位有效 5.77 :100
    METYPE_Temp[1]=QString::number((ui->SSMV_RMS_TblWidget->item(1,1)->text().toFloat(0)* 100) / VOLTAGERANGE ,'d',4).toFloat(0);
    METYPE_Temp[2]=QString::number((ui->SSMV_RMS_TblWidget->item(2,1)->text().toFloat(0)* 100) / VOLTAGERANGE ,'d',4).toFloat(0);

    METYPE_Temp[3]=(ui->SSMV_RMS_TblWidget->item(3,1)->text().toFloat(0) / CURRENTRANGE ) * 5;//IL1
    METYPE_Temp[4]=(ui->SSMV_RMS_TblWidget->item(4,1)->text().toFloat(0) / CURRENTRANGE ) * 5;
    METYPE_Temp[5]=(ui->SSMV_RMS_TblWidget->item(5,1)->text().toFloat(0) / CURRENTRANGE ) * 5;

    METYPE_Temp[6]=ui->SSMV_SetPF_TblWidget->item(0,3)->text().toFloat(0);  //Phi1                    //角度
    METYPE_Temp[7]=ui->SSMV_SetPF_TblWidget->item(1,3)->text().toFloat(0);
    METYPE_Temp[8]=ui->SSMV_SetPF_TblWidget->item(2,3)->text().toFloat(0);

    METYPE_Temp[9]=ui->SSMV_SetPF_TblWidget->item(3,3)->text().toFloat(0);  //Ph4
    METYPE_Temp[10]=ui->SSMV_SetPF_TblWidget->item(4,3)->text().toFloat(0);
    METYPE_Temp[11]=ui->SSMV_SetPF_TblWidget->item(5,3)->text().toFloat(0);
    METYPE_Temp[27]=ui->SSMV_RMS_TblWidget->item(8,3)->text().toFloat(0);      //Freq                      //HZ

    MEable_Temp[0]=1;
    MEable_Temp[1]=1;
    MEable_Temp[2]=1;
    MEable_Temp[3]=1;
    MEable_Temp[4]=1;
    MEable_Temp[5]=1;
    MEable_Temp[6]=1;
    MEable_Temp[7]=1;
    MEable_Temp[8]=1;
    MEable_Temp[9]=1;
    MEable_Temp[10]=1;
    MEable_Temp[11]=1;
    MEable_Temp[27]=1;

   if( set_smv_MPE( METYPE_Temp, MEable_Temp))
   {
       MainMenuBar.set_TitleStatus("SMV正在发送",1);
       showInformationBox("正在发送");
       timeThreadTimer.run(SSMV_RMS);
       lock_MainMenubar(8);
       ui->SSMV_SetPF_PsBtn->setDisabled(true);
   }
   else
   {
       showInformationBox("通信异常");
   }

   if(pSPTYPE_Data->IEC61850 !=3)  // if FT3  off
   {
#if XL_619
        timeThreadTimer.IsLanOn(true);
#endif
   }
}

/*******************************************************************************************************
*Function:     停止发送
*Description:  由于底层关闭不了发送，所以只能将参数设置为0
*******************************************************************************************************/
void MainWidget::slt_SSMV_rms_stop()
{
    float METYPE_Temp[35]={0};
    char MEable_Temp[35]={0};
    MEable_Temp[0]=1;
    MEable_Temp[1]=1;
    MEable_Temp[2]=1;
    MEable_Temp[3]=1;
    MEable_Temp[4]=1;
    MEable_Temp[5]=1;
    MEable_Temp[6]=1;
    MEable_Temp[7]=1;
    MEable_Temp[8]=1;
    MEable_Temp[9]=1;
    MEable_Temp[10]=1;
    MEable_Temp[11]=1;
    MEable_Temp[27]=1;

    if( set_smv_MPE( METYPE_Temp, MEable_Temp))
    {
#if XL_619
        timeThreadTimer.IsLanOn(false);
#endif
        timeThreadTimer.stop();
        showInformationBox("发送停止");
        MainMenuBar.set_TitleStatus("有效值",0);
        unlock_MainMenubar();
        ui->SSMV_SetPF_PsBtn->setDisabled(false);
    }
    else
    {
        showInformationBox("通信异常");
    }
}

/*******************************************************************************************************
*Function:     刷新界面
*Description:  数据来自于线程，由线程控制刷新
*******************************************************************************************************/
void MainWidget::slt_SSMV_rms_update(pMETYPE  pMETYPE_Temp)                                                   //接受报文，更新界面参数
{
    ui->SSMV_RMS_TblWidget->item(0,1)->setText(QString::number(pMETYPE_Temp->UL1,'d',4));
    ui->SSMV_RMS_TblWidget->item(1,1)->setText(QString::number(pMETYPE_Temp->UL2,'d',4));
    ui->SSMV_RMS_TblWidget->item(2,1)->setText(QString::number(pMETYPE_Temp->UL3,'d',4));
    ui->SSMV_RMS_TblWidget->item(3,1)->setText(QString::number(pMETYPE_Temp->IL1,'d',4));
    ui->SSMV_RMS_TblWidget->item(4,1)->setText(QString::number(pMETYPE_Temp->IL2,'d',4));
    ui->SSMV_RMS_TblWidget->item(5,1)->setText(QString::number(pMETYPE_Temp->IL3,'d',4));
    ui->SSMV_RMS_TblWidget->item(6,1)->setText(QString::number(pMETYPE_Temp->P1,'d',4));
    ui->SSMV_RMS_TblWidget->item(7,1)->setText(QString::number(pMETYPE_Temp->P2,'d',4));
    ui->SSMV_RMS_TblWidget->item(8,1)->setText(QString::number(pMETYPE_Temp->P3,'d',4));

    ui->SSMV_RMS_TblWidget->item(0,3)->setText(QString::number(pMETYPE_Temp->Q1,'d',4));
    ui->SSMV_RMS_TblWidget->item(1,3)->setText(QString::number(pMETYPE_Temp->Q2,'d',4));
    ui->SSMV_RMS_TblWidget->item(2,3)->setText(QString::number(pMETYPE_Temp->Q3,'d',4));
    ui->SSMV_RMS_TblWidget->item(3,3)->setText(QString::number(pMETYPE_Temp->cos1,'d',4));
    ui->SSMV_RMS_TblWidget->item(4,3)->setText(QString::number(pMETYPE_Temp->cos2,'d',4));
    ui->SSMV_RMS_TblWidget->item(5,3)->setText(QString::number(pMETYPE_Temp->cos3,'d',4));
    ui->SSMV_RMS_TblWidget->item(6,3)->setText(QString::number(pMETYPE_Temp->SP,'d',4));
    ui->SSMV_RMS_TblWidget->item(7,3)->setText(QString::number(pMETYPE_Temp->SQ,'d',4));
    ui->SSMV_RMS_TblWidget->item(8,3)->setText(QString::number(pMETYPE_Temp->Freq,'d',4));
}


/*******************************************************************************************************
*Function:     检定点设置
*Description:  用于快捷计算输入
*******************************************************************************************************/
void MainWidget::on_SSMV_SetPF_CbBox_currentIndexChanged(QString strTemp1)
{
    int intTemp1  ;
    if(strTemp1.endsWith("C")||strTemp1.endsWith("c"))
     {
        strTemp1.replace(QString("C"), QString("0"));
        strTemp1.replace(QString("c"), QString("0"));
        intTemp1 = acos(strTemp1.toFloat(0))*180/3.1415926;
        ui->SSMV_SetPF_TblWidget->item(3,3)->setText(QString::number(intTemp1));
        ui->SSMV_SetPF_TblWidget->item(4,3)->setText(QString::number((240+intTemp1)%360));
        ui->SSMV_SetPF_TblWidget->item(5,3)->setText(QString::number(120+intTemp1));
    }
    else
    {
        strTemp1.replace(QString("L"), QString("0"));
        strTemp1.replace(QString("L"), QString("0"));
        intTemp1 = acos(strTemp1.toFloat(0))*180/3.1415926;
        ui->SSMV_SetPF_TblWidget->item(3,3)->setText(QString::number((360-intTemp1)%360));
        ui->SSMV_SetPF_TblWidget->item(4,3)->setText(QString::number((240-intTemp1)%360));
        ui->SSMV_SetPF_TblWidget->item(5,3)->setText(QString::number((120-intTemp1+360)%360));

    }
    ui->SSMV_SetPF_TblWidget->item(0,3)->setText("0");
    ui->SSMV_SetPF_TblWidget->item(1,3)->setText("240");
    ui->SSMV_SetPF_TblWidget->item(2,3)->setText("120");
   // ui->SSMV_LEdit_setPF->setText(strTemp);
}

void MainWidget::on_SSMV_SetUn_CbBox_editTextChanged(QString strTemp)
{
    ui->SSMV_SetPF_TblWidget->item(0,1)->setText(strTemp);
    ui->SSMV_SetPF_TblWidget->item(1,1)->setText(strTemp);
    ui->SSMV_SetPF_TblWidget->item(2,1)->setText(strTemp);
}

void MainWidget::on_SSMV_SetIn_CbBox_editTextChanged(QString strTemp)
{
    ui->SSMV_SetPF_TblWidget->item(3,1)->setText(strTemp);
    ui->SSMV_SetPF_TblWidget->item(4,1)->setText(strTemp);
    ui->SSMV_SetPF_TblWidget->item(5,1)->setText(strTemp);
}


void MainWidget:: slt_SSMV_loss_mode()
{
    auxiliaryFun->set_auxiliary_stackedWidget(0);
    auxiliaryFun->show();

}
void MainWidget:: slt_SSMV_timeSyn_mode()
{
    auxiliaryFun->set_auxiliary_stackedWidget(3);
    auxiliaryFun->show();
}



