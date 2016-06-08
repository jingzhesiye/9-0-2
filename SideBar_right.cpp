/******************************************************************************
*dec:右侧栏功能实现
*******************************************************************************/
#include "mainwidget.h"
#include "xl618.h"
#include "QMessageBox"
#include "QTimer"

 //将按钮放在一个list
void MainWidget::init_sideBar()
{
    sideBar_BtnList.append(ui->sideBar_TlBtn_1);
    sideBar_BtnList.append(ui->sideBar_TlBtn_2);
    sideBar_BtnList.append(ui->sideBar_TlBtn_3);
    sideBar_BtnList.append(ui->sideBar_TlBtn_4);

    foreach (QToolButton *b, sideBar_BtnList)
    {
        connect(b, SIGNAL(clicked()), this, SLOT(changeButtonStatus()));
    }

    ui->sideBar_TlBtn_1->click();
}


void MainWidget::on_start_PsBtn_clicked(bool checked)
{
    if(!checked)
    {
      ui->sideBar_right_Page->setDisabled(false);
      timeThreadTimer.stop();
      runTimer->stop();
      return;
    }
    switch(ui->main_SkWidget->currentIndex())
    {

        case 0:
                clean_main_SkWidget_1();//清除界面1的数据
//              startES();//电能误差.这个自己算也行

                start_RD();
                start_RS(); //BMS?
                start_ME(); //测量值
                start_runTime();
        break;

        case 1:
                clean_main_SkWidget_2();
                start_RRF();         //纹波系数
                start_runTime();
                start_rippleWave();  //纹波波形
        break;
        default:
        break;
    }
     ui->sideBar_right_Page->setDisabled(true);
}
/**************************************************************
// 用按钮的current属性来控制被按下按钮的外观.
// 当按钮被按下时, 设置其current属性为true,
// 其他按钮的current属性为false, 为了更新按钮的外观.
*****************************************************************/

void MainWidget::changeButtonStatus() {

    foreach (QToolButton *b, sideBar_BtnList)
    {
        b->setProperty("current", "false");
        b->setStyleSheet(""); // 刷新按钮的样式
    }

    QToolButton *source = qobject_cast<QToolButton *>(sender());
    source->setProperty("current", "true");
    source->setStyleSheet("");

    if(source==ui->sideBar_TlBtn_1)
    {
        set_TblWdiget_Header( ui->BMS_RD_TblWidget ,false,false);
        ui->main_SkWidget->setCurrentIndex(0);
        ui->start_PsBtn->setDisabled(false);
    }
    if(source==ui->sideBar_TlBtn_2)
    {
        ui->start_PsBtn->setDisabled(false);
        set_TblWdiget_Header( ui->RRF_ripple_TblWidget ,true,true);
        ui->main_SkWidget->setCurrentIndex(1);
    }
    if(source==ui->sideBar_TlBtn_3)
    {
        ui->start_PsBtn->setDisabled(true);
        set_TblWdiget_Header( ui->time_TblWidget ,true,true);
        set_TblWdiget_Header( ui->operating_TblWidget ,true,false);
        set_TblWdiget_Header( ui->load_TblWidget ,true,false);
        set_TblWdiget_Header( ui->payment_TblWidget ,true,false);//

        ui->main_SkWidget->setCurrentIndex(2);
    }
    if(source==ui->sideBar_TlBtn_4)
    {
        ui->start_PsBtn->setDisabled(true);
        ui->main_SkWidget->setCurrentIndex(3);
        //ui->serPort_read_SP_PsBtn->click();
    }
}
