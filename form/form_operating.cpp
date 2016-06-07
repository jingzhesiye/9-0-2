#include "mainwidget.h"

void MainWidget::insert_form_operating()
{
    float f_Std,f_obj,f_error;

    int rowCount = ui->operating_TblWidget->rowCount();

    if(rowCount>1)
    {
        return;
    }

    ui->operating_TblWidget->insertRow(rowCount);

    ui->operating_TblWidget->setItem(rowCount,0,new QTableWidgetItem(ui->ES_standard_TblWidget->item(0,1)->text()));//被检时钟
    ui->operating_TblWidget->setItem(rowCount,1,new QTableWidgetItem(ui->ES_standard_TblWidget->item(1,1)->text()));

    f_Std = ui->ES_standard_TblWidget->item(0,1)->text().toFloat(0);
    f_obj = ui->RS_charger_TblWidget->item(1,3)->text().toFloat(0);


    if(f_Std ==0 )
    {
        f_error =0;
    }
    else
    {
        f_error = (f_obj - f_Std)/(f_Std*0.01);
    }

    ui->operating_TblWidget->setItem(rowCount,2,new QTableWidgetItem(QString::number(f_error)));
    ui->operating_TblWidget->setItem(rowCount,3,new QTableWidgetItem(QString::number(f_error)));
    ui->operating_TblWidget->setItem(rowCount,4,new QTableWidgetItem(QString::number(f_error)));

    if(f_error<0.05)
    {
        ui->operating_TblWidget->setItem(rowCount,5,new QTableWidgetItem(QString::fromUtf8("合格")));
    }
    else
    {
        ui->operating_TblWidget->setItem(rowCount,5,new QTableWidgetItem(QString::fromUtf8("不合格")));
    }
}

void MainWidget::fill_form_operating( QTableWidget *temp_TbWidget, replaceDocTypeList *replaceDocTypeList_Data)
{
    QString outVol,outCur,outErr,outAVG,outClu,overAll_outClu;


    if(temp_TbWidget->rowCount()<1)
    {
        return ;
    }

    overAll_outClu = QString::fromUtf8("合格");

    for(int i =0;i<2;i++)
    {
       outVol = temp_TbWidget->item(i,0)->text();
       fillReplaceDocStructList(replaceDocTypeList_Data,QString("{outVol_%1}").arg(QString::number(i))        ,outVol);

       outCur = temp_TbWidget->item(i,1)->text();
       fillReplaceDocStructList(replaceDocTypeList_Data,QString("{outCur_%1}").arg(QString::number(i))        ,outCur);

       outErr = temp_TbWidget->item(i,2)->text();
       fillReplaceDocStructList(replaceDocTypeList_Data,QString("{outErr_0_%1}").arg(QString::number(i))        ,outErr);

       outAVG = temp_TbWidget->item(i,3)->text();
       fillReplaceDocStructList(replaceDocTypeList_Data,QString("{outErr_1_%1}").arg(QString::number(i))        ,outAVG);

       outAVG = temp_TbWidget->item(i,4)->text();
       fillReplaceDocStructList(replaceDocTypeList_Data,QString("{outAVG_%1}").arg(QString::number(i))        ,outAVG);


       outClu = temp_TbWidget->item(i,5)->text();
       fillReplaceDocStructList(replaceDocTypeList_Data,QString("{outClu_%1}").arg(QString::number(i))        ,outClu);

       if( outClu == QString::fromUtf8("不合格"))
       {
          overAll_outClu = QString::fromUtf8("不合格");
       }
    }

    fillReplaceDocStructList(replaceDocTypeList_Data,"{overAll_outClu}"      ,outClu);
    overAll_conc.operating = outClu;
}
