/******************************************************************************
*dec:用于计算运行时间
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

//初始化运行时间
void MainWidget:: init_elapseTime()
{
    elapseTimer =new QTimer(this);
    connect(elapseTimer, SIGNAL(timeout()), this, SLOT(slt_elapseTimer_timeout()));     //定时关闭屏幕
    elapseTimer->setInterval(1000);
}

//开始计时
void MainWidget:: startELAPSETIME()
{
    elapseTimer->start();
    elapseTime.restart();
    elapseTimeCal =0;
}

//时间累计
void MainWidget:: slt_elapseTimer_timeout()
{
    QTime timeTmp;
    QString elapsedTime = timeTmp.addMSecs(elapseTime.elapsed()).toString("hh:mm:ss");
    ui->runTime_LnEdit->setText(elapsedTime);
    elapseTimeCal++;
}
