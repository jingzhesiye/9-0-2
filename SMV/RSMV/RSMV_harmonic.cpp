/******************************************************************************
*界面:谐波显示
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"


void MainWidget::startHR()
{
    UINT8 channel=ui->RSMV_Harmonic_Phase_CbBox->currentIndex()+1;
    UINT32 H1=2;
    UINT32 H2=ui->RSMV_Harmonic_Times_CbBox->currentText().toInt(0,10);

    for(int i =0;i<4;i++)
    {
        ui->RSMV_harmonic_rms_TblWidget->item(i,1)->setText("0");
        ui->RSMV_harmonic_rms_TblWidget->item(i,3)->setText("0");

    }
    set_RSMV_harmonic_histogram(0,0);
    timeThreadTimer.RSMV_harmonic_setArg(0,channel,H1,H2);//参数初始化
    timeThreadTimer.run(RSMV_HARMONIC);
}


void MainWidget::slt_RSMV_harmonic_update( )
{
    QString  strTemp;
    FLOAT64  totalRatio =0;//含有率
    FLOAT64  Values[40]={0};
    INT32    rowCount;
    INT32    H2=ui->RSMV_Harmonic_Times_CbBox->currentText().toInt(0,10);
    remove_TblWdiget_Row(ui->RSMV_Harmonic_TblWidget);

    //qDebug()<<"remove_TblWdiget_Row";
#if 1
    for( int i=0,j=0;i<H2;i++)
    {
        if(timeThreadTimer.RSMV_arrayTemp[i]  > (ui->RSMV_Harmonic_LnEdit_Range->text().toFloat(0)))//判断是否大于阀值
        {
            rowCount=ui->RSMV_Harmonic_TblWidget->rowCount();
            ui->RSMV_Harmonic_TblWidget->insertRow(rowCount);
            strTemp =QString ::number(i);
            ui->RSMV_Harmonic_TblWidget->setItem(j,0,new QTableWidgetItem(strTemp));//QString ::number(i+2)

            strTemp =QString ::number(timeThreadTimer.RSMV_arrayTemp[i]);
            ui->RSMV_Harmonic_TblWidget->setItem(j,1,new QTableWidgetItem(strTemp));//含有率

            strTemp =QString ::number(timeThreadTimer.RSMV_arrayTemp[i]);

            ui->RSMV_Harmonic_TblWidget->setItem(j,2,new QTableWidgetItem(strTemp));//含有率

            Values[i+2]=timeThreadTimer.RSMV_arrayTemp[i];
            j++;//行数
        }
        totalRatio=totalRatio+ timeThreadTimer.RSMV_arrayTemp[i+2] * timeThreadTimer.RSMV_arrayTemp[i+2];//总含有率
    }
     //ui->RSMV_Harmonic_Ratio_Label->setText();
     ui->RSMV_harmonic_rms_TblWidget->item(3,3)->setText(QString ::number(sqrt(totalRatio),'d',3));

     set_RSMV_harmonic_histogram( H2,timeThreadTimer.RSMV_arrayTemp);
//     timeThreadTimer.mutexUpdate.unlock();
#endif
}

void MainWidget::on_RSMV_Harmonic_Phase_CbBox_activated(int index)   //测试项
{
    index=1;
    UINT8 channel=ui->RSMV_Harmonic_Phase_CbBox->currentIndex()+1;
    UINT32 H1=2;
    UINT32 H2=ui->RSMV_Harmonic_Times_CbBox->currentText().toInt(0,10);
    timeThreadTimer.RSMV_harmonic_setArg(0,channel,H1,H2);//参数初始化
}

void MainWidget::on_RSMV_Harmonic_Times_CbBox_activated(int index)  //谐波次数
{
    index=1;
    UINT8 channel=ui->RSMV_Harmonic_Phase_CbBox->currentIndex()+1;
    UINT32 H1=2;
    UINT32 H2=ui->RSMV_Harmonic_Times_CbBox->currentText().toInt(0,10);
    timeThreadTimer.RSMV_harmonic_setArg(0,channel,H1,H2);
}

void MainWidget::on_RSMV_Harmonic_Range_HSlider_valueChanged(int value)
{
    ui->RSMV_Harmonic_LnEdit_Range->setText(QString ::number(float (value*0.01)));
}


