/******************************************************************************
*dec:右侧栏功能实现
*******************************************************************************/
#include "mainwidget.h"
#include "xl618.h"
#include "QMessageBox"
#include "QTimer"


//初始化
void MainWidget::init_sideBar()
{
    // 把按钮放在一个list里为了方便管理
    sideBar_BtnList.append(ui->sideBar_TlBtn_1);
    sideBar_BtnList.append(ui->sideBar_TlBtn_2);
    sideBar_BtnList.append(ui->sideBar_TlBtn_3);
    sideBar_BtnList.append(ui->sideBar_TlBtn_4);

    foreach (QToolButton *b, sideBar_BtnList) {
        connect(b, SIGNAL(clicked()), this, SLOT(changeButtonStatus()));
    }

    ui->sideBar_TlBtn_1->click();
}


void MainWidget::on_start_PsBtn_clicked(bool checked)
{
    if(!checked)
    {
      ui->sideBarRight_Page->setDisabled(false);
      timeThreadTimer.stop();
      elapseTimer->stop();
      return;
    }

     //startELAPSETIME();//计算运行时间

    switch(ui->stackedWidget->currentIndex())
    {

        case 0:
                clean_stackedWidgetIndex1();
                startRD();
                startRS();

//                startME();   //√
//                startWAVE(); //√
//                startES();//电能测试误差状态
//                startENERGY_PUL();//脉冲//√
//                startENERGY_STD();//标准//√
//                startESTD();//读取电能表标准方差值s值//√
        break;

        case 1:
                startME();
                startHR();//谐波
        break;
        default:
        break;
    }
     ui->sideBarRight_Page->setDisabled(true);
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
        set_TblWdiget_Header( ui->RSMV_phasor_TblWidget ,false,false);
        ui->RSMV_phasor_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
        ui->charger_RS_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(source==ui->sideBar_TlBtn_2)
    {
        set_TblWdiget_Header( ui->RSMV_Harmonic_TblWidget ,true,true);
        ui->stackedWidget->setCurrentIndex(1);
    }
    if(source==ui->sideBar_TlBtn_3)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    if(source==ui->sideBar_TlBtn_4)
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
}
