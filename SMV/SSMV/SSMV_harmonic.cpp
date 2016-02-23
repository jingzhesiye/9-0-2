/******************************************************************************
*界面 : 谐波
*功能 : 9-1，9-2 发送数据
*人员 : jingzhesiye@163.com
*时间 : 2014.3.10
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget::slt_SSMV_harmonic_mode()
{
    hideAllControls();
    MainMenuBar.set_TitleStatus("谐波",0);

   set_TblWdiget_Header(ui->SSMV_Harmonic_TblWidget,true,false);

    ui->ToolBar_PsBtn_1->show();
    ui->ToolBar_PsBtn_1->setText(QString::fromUtf8("功能切换"));
    ui->ToolBar_PsBtn_3->show();
    ui->ToolBar_PsBtn_3->setCheckable(true);
    ui->ToolBar_PsBtn_3->setText(QString::fromUtf8("发送"));
    ui->stackedWidget->setCurrentIndex(2);
    stackcurrentIndex = 2;

     double  cleanValue[40]={0};          //clean data
     set_rms_harmonic( 40,cleanValue);
     ui->SSMV_Harmonic_QwtPlot->replot();
}

/*******************************************************************************************************
*Function:     叠加谐波设置
*Description:  在发送基波的基础上叠加谐波，其中基波会随着量程比例改变
*******************************************************************************************************/
void MainWidget:: SSMV_harmonic_add()         //
 {
     int introwCount=ui->SSMV_Harmonic_TblWidget->rowCount();               //总行数
     int numTemp;
     pSET_HARMONIC_TYPE   pSET_HARMONIC_TYPE_Temp =NULL;

     if((pSET_HARMONIC_TYPE_Temp=(pSET_HARMONIC_TYPE)calloc(1,sizeof(SET_HARMONIC_TYPE)))==NULL)
     {
           free(pSET_HARMONIC_TYPE_Temp);
           pSET_HARMONIC_TYPE_Temp=NULL;
           return ;
     }
     else
     {
         pSET_HARMONIC_TYPE_Temp->Ia[1].f=100;                     //当n=0时:代表直流 (57.7*0.01+57.7) 当n=1时:代表基波默认为100%；
         pSET_HARMONIC_TYPE_Temp->Ia[1].q=0;

         pSET_HARMONIC_TYPE_Temp->Ib[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ib[1].q=240;

         pSET_HARMONIC_TYPE_Temp->Ic[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ic[1].q=120;

         pSET_HARMONIC_TYPE_Temp->Ua[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ua[1].q=0;

         pSET_HARMONIC_TYPE_Temp->Ub[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ub[1].q=240;

         pSET_HARMONIC_TYPE_Temp->Uc[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Uc[1].q=120;

         for(int i=0;i<introwCount;i++)                                     //从0－开始全部依次保存参数最大为40
         {
             numTemp=ui->SSMV_Harmonic_TblWidget->item(i,1)->text().toInt(0,10);//次数

             if(ui->SSMV_Harmonic_TblWidget->item(i,0)->text()=="Ia")
                pSET_HARMONIC_TYPE_Temp->Ia[numTemp].f=ui->SSMV_Harmonic_TblWidget->item(i,2)->text().toFloat(0);

             if(ui->SSMV_Harmonic_TblWidget->item(i,0)->text()=="Ib")
                pSET_HARMONIC_TYPE_Temp->Ib[numTemp].f=ui->SSMV_Harmonic_TblWidget->item(i,2)->text().toFloat(0);


             if(ui->SSMV_Harmonic_TblWidget->item(i,0)->text()=="Ic")
                pSET_HARMONIC_TYPE_Temp->Ic[numTemp].f=ui->SSMV_Harmonic_TblWidget->item(i,2)->text().toFloat(0);

             if(ui->SSMV_Harmonic_TblWidget->item(i,0)->text()=="Ua")
                pSET_HARMONIC_TYPE_Temp->Ua[numTemp].f=ui->SSMV_Harmonic_TblWidget->item(i,2)->text().toFloat(0);    //8th channel

             if(ui->SSMV_Harmonic_TblWidget->item(i,0)->text()=="Ub")
                pSET_HARMONIC_TYPE_Temp->Ub[numTemp].f=ui->SSMV_Harmonic_TblWidget->item(i,2)->text().toFloat(0);

             if(ui->SSMV_Harmonic_TblWidget->item(i,0)->text()=="Uc")
                pSET_HARMONIC_TYPE_Temp->Uc[numTemp].f=ui->SSMV_Harmonic_TblWidget->item(i,2)->text().toFloat(0);
         }

        pSET_HARMONIC_TYPE_Temp->RMSUa1 =57.7; //基波:发送的值
        pSET_HARMONIC_TYPE_Temp->RMSUb1 =57.7;
        pSET_HARMONIC_TYPE_Temp->RMSUc1 =57.7;
        pSET_HARMONIC_TYPE_Temp->RMSIa1 =5;
        pSET_HARMONIC_TYPE_Temp->RMSIb1 =5;
        pSET_HARMONIC_TYPE_Temp->RMSIc1 =5;

        if( set_smv_HRVirtual(pSET_HARMONIC_TYPE_Temp))
        {
            UINT8 channel=ui->SSMV_Harmonic_SelsctPhase_CbBox->currentIndex()+1;                  //read
            timeThreadTimer.RSMV_harmonic_setArg(1,channel,2,40);//参数初始化
            timeThreadTimer.run(RSMV_HARMONIC);
            MainMenuBar.set_TitleStatus("谐波正在发送",1);

        }
        else
        {
            showInformationBox("通信异常");
        }
     }

        free(pSET_HARMONIC_TYPE_Temp);
        pSET_HARMONIC_TYPE_Temp=NULL;
        ui->SSMV_Harmonic_IsInsert_RdBtn->setDisabled(true);//锁住
        lock_MainMenubar(8);
 }

 void MainWidget::SSMV_harmonic_remove()      //发送基波
 {
    double  cleanValue[40]={0};          //clean data
    set_rms_harmonic( 40,cleanValue);
    ui->SSMV_Harmonic_QwtPlot->replot();

    pSET_HARMONIC_TYPE   pSET_HARMONIC_TYPE_Temp =NULL;

    if((pSET_HARMONIC_TYPE_Temp=(pSET_HARMONIC_TYPE)calloc(1,sizeof(SET_HARMONIC_TYPE)))==NULL)
    {
          free(pSET_HARMONIC_TYPE_Temp);
          pSET_HARMONIC_TYPE_Temp=NULL;
          return ;
    }
      else
   {
         pSET_HARMONIC_TYPE_Temp->Ia[1].f=100;                     //当n=0时:代表直流 (57.7*0.01+57.7) 当n=1时:代表基波默认为100%；
         pSET_HARMONIC_TYPE_Temp->Ia[1].q=0;

         pSET_HARMONIC_TYPE_Temp->Ib[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ib[1].q=240;

         pSET_HARMONIC_TYPE_Temp->Ic[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ic[1].q=124;

         pSET_HARMONIC_TYPE_Temp->Ua[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ua[1].q=0;

         pSET_HARMONIC_TYPE_Temp->Ub[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Ub[1].q=240;

         pSET_HARMONIC_TYPE_Temp->Uc[1].f=100;
         pSET_HARMONIC_TYPE_Temp->Uc[1].q=120;

         pSET_HARMONIC_TYPE_Temp->RMSUa1 =ui->SSMV_RMS_TblWidget->item(0,1)->text().toFloat(0); //基波:发送的值
         pSET_HARMONIC_TYPE_Temp->RMSUb1 =ui->SSMV_RMS_TblWidget->item(1,1)->text().toFloat(0);
         pSET_HARMONIC_TYPE_Temp->RMSUc1 =ui->SSMV_RMS_TblWidget->item(2,1)->text().toFloat(0);

         pSET_HARMONIC_TYPE_Temp->RMSIa1 =ui->SSMV_RMS_TblWidget->item(3,1)->text().toFloat(0)/2;
         pSET_HARMONIC_TYPE_Temp->RMSIb1 =ui->SSMV_RMS_TblWidget->item(4,1)->text().toFloat(0)/2;
         pSET_HARMONIC_TYPE_Temp->RMSIc1 =ui->SSMV_RMS_TblWidget->item(5,1)->text().toFloat(0)/2;

         if( set_smv_HRVirtual(pSET_HARMONIC_TYPE_Temp))
         {

             MainMenuBar.set_TitleStatus("基波正在发送",1);
             ui->SSMV_Harmonic_IsInsert_RdBtn->setDisabled(true);//锁住
             lock_MainMenubar(8);
         }
         else
         {
             showInformationBox("通信异常");
         }
         free(pSET_HARMONIC_TYPE_Temp);
         pSET_HARMONIC_TYPE_Temp=NULL;
      }
 }

 void MainWidget::slt_SSMV_harmonic_start()    //先设置发送，再循环读取
{
      timeThreadTimer.IsLanOn(true);
    if(ui->SSMV_Harmonic_IsInsert_RdBtn->isChecked())
    {
       SSMV_harmonic_add();
    }
    else
    {
        SSMV_harmonic_remove();
    }
}

void MainWidget::slt_SSMV_harmonic_stop()
{
    float METYPE_Temp[35];
    char MEable_Temp[35];
    MEable_Temp[0] =1;
    MEable_Temp[1] =1;
    MEable_Temp[2] =1;
    MEable_Temp[3] =1;
    MEable_Temp[4] =1;
    MEable_Temp[5] =1;

    if( set_smv_MPE( METYPE_Temp, MEable_Temp))
    {
        timeThreadTimer.IsLanOn(false);
        MainMenuBar.set_TitleStatus("谐波",0);
        showInformationBox("停止发送");
        timeThreadTimer.stop();
        double  cleanValue[40]={0};          //clean data
        set_rms_harmonic( 40,cleanValue);
        ui->SSMV_Harmonic_QwtPlot->replot();
        ui->SSMV_Harmonic_IsInsert_RdBtn->setDisabled(false);
        unlock_MainMenubar();
    }
    else
    {
        showInformationBox("通信异常");
    }
}

void MainWidget::slt_SSMV_harmonic_update()
{
     set_rms_harmonic( 40,timeThreadTimer.RSMV_arrayTemp );
     ui->SSMV_Harmonic_QwtPlot->replot();
}

void MainWidget::on_SSMV_Harmonic_SelsctPhase_CbBox_activated(int index)
{
    index=1;
    UINT8 channel=ui->SSMV_Harmonic_SelsctPhase_CbBox->currentIndex()+1;
    timeThreadTimer.RSMV_harmonic_setArg(1,channel,2,40);//参数初始化
    timeThreadTimer.run(RSMV_HARMONIC);
}

void MainWidget::on_SSMV_Harmonic_Insert_PsBtn_clicked()
{
    int numTemp=ui->SSMV_Harmonic_TblWidget->rowCount();
    if (ui->SSMV_Harmonic_Times_LnEdit->text().toInt(0,10)<23)
    {
        ui->SSMV_Harmonic_TblWidget->insertRow(numTemp);
        ui->SSMV_Harmonic_TblWidget->scrollToBottom();
        ui->SSMV_Harmonic_TblWidget->setItem(numTemp,0,new QTableWidgetItem(ui->SSMV_Harmonic_Phase_CbBox->currentText()));//输出相
        ui->SSMV_Harmonic_TblWidget->item(numTemp,0)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->SSMV_Harmonic_TblWidget->item(numTemp,0)->setForeground(Qt::SolidPattern);

        ui->SSMV_Harmonic_TblWidget->setItem(numTemp,1,new QTableWidgetItem(ui->SSMV_Harmonic_Times_LnEdit->text()));//次数
        ui->SSMV_Harmonic_TblWidget->item(numTemp,1)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->SSMV_Harmonic_TblWidget->item(numTemp,1)->setForeground(Qt::SolidPattern);

        ui->SSMV_Harmonic_TblWidget->setItem(numTemp,2,new QTableWidgetItem(ui->SSMV_Harmonic_Ration_LnEdit->text()));//含有率
        ui->SSMV_Harmonic_TblWidget->item(numTemp,2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->SSMV_Harmonic_TblWidget->item(numTemp,2)->setForeground(Qt::SolidPattern);

        if((ui->SSMV_Harmonic_Phase_CbBox->currentIndex()%3) ==0)
        {

            ui->SSMV_Harmonic_TblWidget->item(numTemp,0)->setBackgroundColor(QColor(250, 240, 160));
            ui->SSMV_Harmonic_TblWidget->item(numTemp,1)->setBackgroundColor(QColor(250, 240, 160));
            ui->SSMV_Harmonic_TblWidget->item(numTemp,2)->setBackgroundColor(QColor(250, 240, 160));
        }
        else if((ui->SSMV_Harmonic_Phase_CbBox->currentIndex()%3) ==1)
        {
            ui->SSMV_Harmonic_TblWidget->item(numTemp,0)->setBackgroundColor(QColor(150, 230, 140));
            ui->SSMV_Harmonic_TblWidget->item(numTemp,1)->setBackgroundColor(QColor(150, 230, 140));
            ui->SSMV_Harmonic_TblWidget->item(numTemp,2)->setBackgroundColor(QColor(150, 230, 140));
        }
        else if((ui->SSMV_Harmonic_Phase_CbBox->currentIndex()%3) ==2)
        {
            ui->SSMV_Harmonic_TblWidget->item(numTemp,0)->setBackgroundColor(QColor(255, 205, 255));
            ui->SSMV_Harmonic_TblWidget->item(numTemp,1)->setBackgroundColor(QColor(255, 205, 255));
            ui->SSMV_Harmonic_TblWidget->item(numTemp,2)->setBackgroundColor(QColor(255, 205, 255));
        }
    }
    else
    {
        informationBox->setText(QString::fromUtf8("最多只能输出22次"));
        informationBox->show();
    }

}

void MainWidget::on_SSMV_Harmonic_Delete_PsBtn_clicked()
{
     int numTemp=ui->SSMV_Harmonic_TblWidget->currentRow();
     ui->SSMV_Harmonic_TblWidget->removeRow(numTemp);

}

void MainWidget::on_SSMV_Harmonic_Clean_PsBtn_clicked()
{
    int numTemp=ui->SSMV_Harmonic_TblWidget->rowCount();
    for(int i=numTemp;i>=0;i--)
    {
        ui->SSMV_Harmonic_TblWidget->removeRow(i);
    }
}


