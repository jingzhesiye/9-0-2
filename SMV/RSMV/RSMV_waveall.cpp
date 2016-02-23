/******************************************************************************
*界面 : 全帧波形解析
*功能 : 9-1，9-2 接收数据
*人员 : jingzhesiye@163.com
*时间 : 2013.9.25
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget::slt_RSMV_waveall_mode()
 {
     hideAllControls();
     MainMenuBar.set_TitleStatus("全帧解析",0);
     ui->ToolBar_PsBtn_1->show();
     ui->ToolBar_PsBtn_1->setText(QString::fromUtf8("功能切换"));
     ui->ToolBar_PsBtn_3->show();
     ui->ToolBar_PsBtn_3->setCheckable(true);
     ui->ToolBar_PsBtn_3->setText(QString::fromUtf8("接收"));
     ui->stackedWidget->setCurrentIndex(7);
 }

void MainWidget::slt_RSMV_waveall_start()
 {
    int noEnd = 0;
     ui->RSMV_WaveAll_Channelcount_LnEdit->setText("");
     ui->RSMV_WaveAll_Samplecount_LnEdit->setText("");
     for(UINT16 i = 0; i < 80; i++ )                                    //X坐标的值
     {
         xval[i] = FLOAT64( i ) * 3.0 / FLOAT64( 80 - 1 );
     }

     transmitsSimply ((UINT8*)"SMDIGITALTRANSFORMERS\r\n");//切换工作模式

     do{
         if(  theDevice->setSP_part(pSPTYPE_Data,pISABLE_SP_Data) == ERR_RIGHT)
         {
             showInformationBox("映射成功");
             noEnd=0;
         }
         else
         {
             noEnd ++;
             if(noEnd==5)
             {
                showInformationBox("通信异常");
                 return;
             }
         }
       }  while(noEnd);

     showInformationBox("正在接收");
     timeThreadTimer.IsLanOn(true);
     timeThreadTimer.run(RSMV_WAVEALL);
     MainMenuBar.set_TitleStatus("SMV正在接收",2);
     lock_MainMenubar(8);
     RSMV.waveall_curve_1 ->setRawSamples( 0,0,0);
     RSMV.waveall_curve_1 ->setRawSamples( 0,0,0);
     RSMV.waveall_curve_3 ->setRawSamples( 0,0,0);

     ui->RSMV_WaveAll_QwtPlot_1->replot();
     ui->RSMV_WaveAll_QwtPlot_2->replot();
     ui->RSMV_WaveAll_QwtPlot_3->replot();
 }

void MainWidget::slt_RSMV_waveall_stop()
 {
     UINT16 CHCFGTYPE_Temp[15];
     transmitsSimply ((UINT8*)"SMACTUALLOAD\r\n");//返回实负荷

     CHCFGTYPE_Temp[0] =22; //CHNUM
     CHCFGTYPE_Temp[5]  =5; //IMA
     CHCFGTYPE_Temp[6]  =6;
     CHCFGTYPE_Temp[7]  =7;
     CHCFGTYPE_Temp[8]  =8; //UA
     CHCFGTYPE_Temp[9]  =9;
     CHCFGTYPE_Temp[10] =10;

     if( set_smv_writeCh(CHCFGTYPE_Temp))
     {
          timeThreadTimer.IsLanOn(false);
         MainMenuBar.set_TitleStatus("SMV接收",0);
         showInformationBox("停止接收");
         timeThreadTimer.stop();
         unlock_MainMenubar();
     }
 }

void MainWidget::slt_RSMV_waveall_update()
{
    UINT16 sampleCnt = timeThreadTimer.RSMV_waveall_sampleCnt ;

    for(UINT16 i = 0; i < sampleCnt; i++ )                                    //X坐标的值
    {
        xval[i] = FLOAT64( i ) * 3.0 / FLOAT64( 80 - 1 );
    }
    ui->RSMV_WaveAll_QwtPlot_1->setAxisScale(QwtPlot::yLeft  ,-timeThreadTimer.RSMV_arrayTemp[0],timeThreadTimer.RSMV_arrayTemp[0],timeThreadTimer.RSMV_arrayTemp[0]);
    ui->RSMV_WaveAll_QwtPlot_2->setAxisScale(QwtPlot::yLeft  ,-timeThreadTimer.RSMV_arrayTemp[1],timeThreadTimer.RSMV_arrayTemp[1],timeThreadTimer.RSMV_arrayTemp[1]);
    ui->RSMV_WaveAll_QwtPlot_3->setAxisScale(QwtPlot::yLeft  ,-timeThreadTimer.RSMV_arrayTemp[2],timeThreadTimer.RSMV_arrayTemp[2],timeThreadTimer.RSMV_arrayTemp[2]);

    RSMV.waveall_curve_1 ->setRawSamples( xval,timeThreadTimer.RSMV_wave_axesY[0], sampleCnt);
    RSMV.waveall_curve_2 ->setRawSamples( xval,timeThreadTimer.RSMV_wave_axesY[1], sampleCnt);
    RSMV.waveall_curve_3 ->setRawSamples( xval,timeThreadTimer.RSMV_wave_axesY[2], sampleCnt);

    ui->RSMV_WaveAll_QwtPlot_1->replot();
    ui->RSMV_WaveAll_QwtPlot_2->replot();
    ui->RSMV_WaveAll_QwtPlot_3->replot();

    ui->RSMV_WaveAll_Value_Label_1->setText(QString::number(timeThreadTimer.RSMV_arrayTemp[0]/2,'d',3));
    ui->RSMV_WaveAll_Value_Label_2->setText(QString::number(timeThreadTimer.RSMV_arrayTemp[1]/2,'d',3));
    ui->RSMV_WaveAll_Value_Label_3->setText(QString::number(timeThreadTimer.RSMV_arrayTemp[2]/2,'d',3));

    ui->RSMV_WaveAll_Channelcount_LnEdit->setText(QString ::number(timeThreadTimer.RSMV_waveall_chlCount));
    ui->RSMV_WaveAll_Samplecount_LnEdit->setText(QString ::number(timeThreadTimer.RSMV_waveall_sampleCnt));

}

void MainWidget::on_RSMV_WaveAll_SelectChl_CbBox_activated(int index)
{
    timeThreadTimer.RSMV_waveall_chlIndex =index*3;
    QString strTemp;
    strTemp =  QObject::trUtf8("通道%1:").arg(QString::number(3*index+1));
    ui->RSMV_WaveAll_Tag_Label_1->setText(strTemp);

    strTemp =  QObject::trUtf8("通道%1:").arg(QString::number(3*index+2));
    ui->RSMV_WaveAll_Tag_Label_2->setText(strTemp);

    strTemp =  QObject::trUtf8("通道%1:").arg(QString::number(3*index+3));
    ui->RSMV_WaveAll_Tag_Label_3->setText(strTemp);

#if 1
    if(index == 7)
    {
       ui->RSMV_WaveAll_QwtPlot_2->setHidden(true);
       ui->RSMV_WaveAll_QwtPlot_3->setHidden(true);
       ui->RSMV_WaveAll_Value_Label_2->setHidden(true);
       ui->RSMV_WaveAll_Value_Label_3->setHidden(true);
       ui->RSMV_WaveAll_Tag_Label_2->setHidden(true);
       ui->RSMV_WaveAll_Tag_Label_3->setHidden(true);
    }
    else
    {
        ui->RSMV_WaveAll_QwtPlot_2->setHidden(false);
        ui->RSMV_WaveAll_QwtPlot_3->setHidden(false);
        ui->RSMV_WaveAll_Value_Label_2->setHidden(false);
        ui->RSMV_WaveAll_Value_Label_3->setHidden(false);
        ui->RSMV_WaveAll_Tag_Label_2->setHidden(false);
        ui->RSMV_WaveAll_Tag_Label_3->setHidden(false);
    }
#endif

}

