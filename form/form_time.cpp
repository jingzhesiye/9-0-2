#include "mainwidget.h"

void MainWidget::insert_form_time()
{
    remove_TblWdiget_Row(ui->time_TblWidget);

    int rowCount = ui->time_TblWidget->rowCount();

    //    if(rowCount>1)
    //    {
    //        return;
    //    }

    ui->time_TblWidget->insertRow(rowCount); //BMS_RD_TblWidget

    //    ui->from_error_TbWidget->setItem(rowCount,0,new QTableWidgetItem(ui->ES_PE_LnEdit->text()));
    //    ui->from_error_TbWidget->setItem(rowCount,1,new QTableWidgetItem(ui->ES_TE_LnEdit->text()));
    ui->time_TblWidget->setItem(rowCount,0,new QTableWidgetItem(ui->BMS_RD_TblWidget->item(2,3)->text()));//被检时钟
    ui->time_TblWidget->setItem(rowCount,1,new QTableWidgetItem(ui->ES_standard_TblWidget->item(1,3)->text()));
    ui->time_TblWidget->setItem(rowCount,2,new QTableWidgetItem(ui->ES_TE_LnEdit->text()));

    if(ui->ES_TE_LnEdit->text().toFloat(0)<0.05)
    {
        ui->time_TblWidget->setItem(rowCount,3,new QTableWidgetItem(QString::fromUtf8("合格")));
    }
    else
    {
        ui->time_TblWidget->setItem(rowCount,3,new QTableWidgetItem(QString::fromUtf8("不合格")));
    }
}

void MainWidget::fill_form_time( QTableWidget *temp_TbWidget, replaceDocTypeList *replaceDocTypeList_Data)
{
    QString chargerTime,standardTime,errTime,timeClu;

    if(temp_TbWidget->rowCount()<1)
    {
        return ;
    }

    chargerTime = temp_TbWidget->item(0,0)->text();
    standardTime = temp_TbWidget->item(0,1)->text();
    errTime = temp_TbWidget->item(0,2)->text();
    timeClu = temp_TbWidget->item(0,3)->text();

    fillReplaceDocStructList(replaceDocTypeList_Data, "{chargerTime}"        ,chargerTime);
    fillReplaceDocStructList(replaceDocTypeList_Data, "{standardTime}"       ,standardTime);
    fillReplaceDocStructList(replaceDocTypeList_Data, "{errTime}"            ,errTime);
    fillReplaceDocStructList(replaceDocTypeList_Data, "{timeClu}"            ,timeClu);

    overAll_conc.time = timeClu;
}
