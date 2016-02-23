/******************************************************************************
*界面 : 离散度
*功能 : 9-1，9-2 接收数据
*人员 : jingzhesiye@163.com
*时间 : 2013.9.25
*******************************************************************************/

#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget::slt_RSMV_straggling_mode()
{
    hideAllControls();
    MainMenuBar.set_TitleStatus("离散度",0);
    set_TblWdiget_Header( ui->RSMV_Straggling_Event_TblWidget ,true,false);

    ui->ToolBar_PsBtn_1->show();
    ui->ToolBar_PsBtn_1->setText(QString::fromUtf8("功能切换"));
    ui->ToolBar_PsBtn_3->show();
    ui->ToolBar_PsBtn_3->setText(QString::fromUtf8("接收"));
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWidget::slt_RSMV_straggling_start()
{
    timeThreadTimer.IsLanOn(true);
    transmitsSimply ((UINT8*)"SMDIGITALTRANSFORMERS\r\n");
    transmitsSimply ((UINT8 *)"FRAM_TRAN_START");
    transmitsSimply ((UINT8 *)"FRAM_DISPERSE_START");
    ui->RSMV_Straggling_Curdispersion_LnEdit->clear();
    ui->RSMV_Straggling_MaxDispersion_LnEdit->clear();
    ui->RSMV_Straggling_Mindispersion_LnEdit->clear();
    ui->RSMV_Straggling_RunningTime_LnEdit->clear();

    remove_TblWdiget_Row(ui->RSMV_Straggling_Event_TblWidget);

    systemTimer->setInterval(1000);
    systemTimer->start();
    systemTimeCal=0;

    showInformationBox("正在接收");
    timeThreadTimer.run(RSMV_STRAGGLING);

}

void MainWidget::slt_RSMV_straggling_stop()
{
     timeThreadTimer.IsLanOn(false);
    transmitsSimply ((UINT8*)"FRAM_DISPERSE_END");
    MainMenuBar.titleLable ->setText(QString::fromUtf8("接收SMV"));
    showInformationBox("停止接收");
    timeThreadTimer.stop();
    systemTimer->stop();
}

void MainWidget::slt_RSMV_straggling_save()
{
    int rowCount=ui->RSMV_Straggling_Event_TblWidget->rowCount();
    QTime temp_time = QTime::currentTime();
    QString str_time = temp_time.toString("hh_mm_ss");//文件保存不能出现：冒号
    str_time ="/sdcard/XLlf _" +str_time + ".txt"; //root
    QFile fileTemp(str_time);
    if (!fileTemp.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        showInformationBox("保存失败");
        return;
    }
    else
    {
       showInformationBox("保存成功");
    }

    QTextStream streamTemp(&fileTemp);
    for(int i=0;i<rowCount;i++)
    {
       streamTemp<<ui->RSMV_Straggling_Event_TblWidget->item(i,0)->text()<<" ";
       streamTemp<<ui->RSMV_Straggling_Event_TblWidget->item(i,1)->text()<<"\n ";
    }

    fileTemp.close();

}

void MainWidget::slt_RSMV_straggling_update(pMUTYPE pMUTYPE_Temp)
{
    QTime timeTemp(0, 0, 0);
    QString getTemp="";
    QString getTime="";
    FLOAT32 currentDelayshake=0;
    UINT32 timeLimit=ui->RSMV_Straggling_TestTime_LnEdit->text().toInt(0,10)*60;//second
    MainMenuBar.titleLable ->setText(QString::fromUtf8("接收SMV(离散度)"));
    UINT8 *syn=(UINT8 *)malloc(sizeof(UINT8));

    currentDelayshake=pMUTYPE_Temp->delayshake;
    getTemp=QString ::number(pMUTYPE_Temp->delayshake);
    getTime= timeTemp.addSecs(systemTimeCal).toString("hh-mm-ss");//

    if(systemTimeCal<2)//过滤前期不准确数据
    {
      return;
    }
    else  if(systemTimeCal<4)
    {
        ui->RSMV_Straggling_Curdispersion_LnEdit->setText(getTemp);
        ui->RSMV_Straggling_Mindispersion_LnEdit->setText(QString ::number(currentDelayshake));
    }
    else  if(systemTimeCal>timeLimit)
    {
        timeThreadTimer.stop();
        informationBox->setText(QString::fromUtf8("时间到，测试停止"));
        informationBox->show();
        return;
    }

    if( (theDevice->getSyn(syn) == ERR_RIGHT) )
    {
        if (*syn)
        {
            ui->RSMV_Straggling_Connect_Label_1->setStyleSheet(QString::fromUtf8("image: url(:/pic/redCircle.png);"));
            ui->RSMV_Straggling_Connect_Label_2->setText(QString::fromUtf8("连接"));

            if(currentDelayshake < ui->RSMV_Straggling_Mindispersion_LnEdit->text().toFloat(0))   //min
              {
                    ui->RSMV_Straggling_Mindispersion_LnEdit->setText(QString ::number(currentDelayshake));
              }

            if(currentDelayshake > ui->RSMV_Straggling_MaxDispersion_LnEdit->text().toFloat(0))                       //最大值保留
            {
                ui->RSMV_Straggling_MaxDispersion_LnEdit->setText(QString ::number(currentDelayshake));
            }
            ui->RSMV_Straggling_Event_TblWidget->insertRow(0);
            ui->RSMV_Straggling_Event_TblWidget->setItem(0,0,new QTableWidgetItem(getTemp));//序号
            ui->RSMV_Straggling_Event_TblWidget->setItem(0,1,new QTableWidgetItem(getTime));//时间

            ui->RSMV_Straggling_Curdispersion_LnEdit->setText(getTemp);
            ui->RSMV_Straggling_RunningTime_LnEdit->setText(getTime);//time

            free(syn);
            syn=NULL;
        }
        else
        {
            ui->RSMV_Straggling_Connect_Label_1->setStyleSheet(QString::fromUtf8("image: url(:/pic/greenCircle.png);"));
            ui->RSMV_Straggling_Connect_Label_2->setText(QString::fromUtf8("断开"));
            free(syn);
            syn=NULL;
            return ;
        }
     }
 }

