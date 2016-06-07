#include "mainwidget.h"

void MainWidget::insert_form_load()
{
    float f_Std,f_obj,f_error;

    remove_TblWdiget_Row(ui->load_TblWidget);

    int rowCount = ui->load_TblWidget->rowCount();


    ui->load_TblWidget->insertRow(rowCount);

    ui->load_TblWidget->setItem(rowCount,0,new QTableWidgetItem(ui->ES_standard_TblWidget->item(1,5)->text()));//被检
    ui->load_TblWidget->setItem(rowCount,3,new QTableWidgetItem(ui->ES_standard_TblWidget->item(0,5)->text()));//标准

    f_Std = ui->ES_standard_TblWidget->item(0,5)->text().toFloat(0);
    f_obj = ui->ES_standard_TblWidget->item(1,5)->text().toFloat(0);


    if(f_Std ==0 )
    {
        f_error =0;
    }
    else
    {
        f_error = (f_obj - f_Std)/(f_Std*0.01);
    }

    ui->load_TblWidget->setItem(rowCount,4,new QTableWidgetItem(QString::number(f_error)));


    if(f_error<0.05)
    {
        ui->load_TblWidget->setItem(rowCount,5,new QTableWidgetItem(QString::fromUtf8("合格")));
    }
    else
    {
        ui->load_TblWidget->setItem(rowCount,5,new QTableWidgetItem(QString::fromUtf8("不合格")));
    }
}

void MainWidget::fill_form_load( QTableWidget *temp_TbWidget, replaceDocTypeList *replaceDocTypeList_Data)
{
    QString  obj_power_b,std_power,powerErr,powerClu;

    if(temp_TbWidget->rowCount()<1)
    {
        return ;
    }

    obj_power_b = temp_TbWidget->item(0,0)->text();
    std_power = temp_TbWidget->item(0,3)->text();
    powerErr = temp_TbWidget->item(0,4)->text();
    powerClu = temp_TbWidget->item(0,5)->text();


    fillReplaceDocStructList(replaceDocTypeList_Data, "{obj_power_b}"        ,obj_power_b);
    fillReplaceDocStructList(replaceDocTypeList_Data, "{std_power}"          ,std_power);
    fillReplaceDocStructList(replaceDocTypeList_Data, "{powerErr}"          ,powerErr);
    fillReplaceDocStructList(replaceDocTypeList_Data, "{powerClu}"           ,powerClu);

    overAll_conc.power = powerClu;
}

