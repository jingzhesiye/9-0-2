#include "mainwidget.h"

void MainWidget::setColumnWidth()
{
    ui->RS_charger_TblWidget->setColumnWidth(0,110);
    ui->RS_charger_TblWidget->setColumnWidth(1,110);
    ui->RS_charger_TblWidget->setColumnWidth(2,130);
    ui->RS_charger_TblWidget->setColumnWidth(3,120);
    ui->RS_charger_TblWidget->setColumnWidth(4,130);
    ui->RS_charger_TblWidget->setColumnWidth(5,120);

    ui->ES_standard_TblWidget->setColumnWidth(0,80);
    ui->ES_standard_TblWidget->setColumnWidth(1,140);
    ui->ES_standard_TblWidget->setColumnWidth(2,110);
    ui->ES_standard_TblWidget->setColumnWidth(3,140);
    ui->ES_standard_TblWidget->setColumnWidth(4,110);
    ui->ES_standard_TblWidget->setColumnWidth(5,140);


    ui->BMS_RD_TblWidget->setColumnWidth(0,160);
    ui->BMS_RD_TblWidget->setColumnWidth(1,100);
    ui->BMS_RD_TblWidget->setColumnWidth(2,130);
    ui->BMS_RD_TblWidget->setColumnWidth(3,100);
    ui->BMS_RD_TblWidget->setColumnWidth(4,130);
    ui->BMS_RD_TblWidget->setColumnWidth(5,100);

//    ui->intuit_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->time_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->operating_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->load_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);
//    ui->payment_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Interactive);
//    ui->conclusion_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::Stretch);

    ui->load_TblWidget->setColumnWidth(0,110);
    ui->load_TblWidget->setColumnWidth(1,110);
    ui->load_TblWidget->setColumnWidth(2,110);
    ui->load_TblWidget->setColumnWidth(3,150);

    ui->payment_TblWidget->setColumnWidth(0,140);
    ui->payment_TblWidget->setColumnWidth(1,140);
    ui->payment_TblWidget->setColumnWidth(2,170);
    ui->payment_TblWidget->setColumnWidth(3,80);
    ui->payment_TblWidget->setColumnWidth(4,80);
    ui->payment_TblWidget->setColumnWidth(5,80);
}
