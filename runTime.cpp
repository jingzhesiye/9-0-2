/******************************************************************************
*dec:用于计算运行时间
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

//初始化运行时间
void MainWidget:: init_runTime()
{
    runTimer =new QTimer(this);
    connect(runTimer, SIGNAL(timeout()), this, SLOT(slt_runTimer_timeout()));     //定时关闭屏幕
    runTimer->setInterval(1000);
}

//开始计时
void MainWidget:: start_runTime()
{
    runTimer->start();
    runTime.restart();
    runTimeCal =0;
}

//时间累计
void MainWidget:: slt_runTimer_timeout()
{
    QTime timeTmp;
    QString strTime = timeTmp.addMSecs(runTime.elapsed()).toString("hh:mm:ss");
    ui->runTime_LnEdit->setText(strTime);
    runTimeCal++;
}
