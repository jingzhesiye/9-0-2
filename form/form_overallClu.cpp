#include "mainwidget.h"

void MainWidget::fill_form_overallClu( QString str, replaceDocTypeList *replaceDocTypeList_Data)
{
    if(overAll_conc.time.startsWith(QString::fromUtf8("不"))||overAll_conc.operating.startsWith(QString::fromUtf8("不"))
       ||overAll_conc.time.startsWith(QString::fromUtf8("不")))
    {
       fillReplaceDocStructList(replaceDocTypeList_Data, "{overallClu}" ,QString::fromUtf8("不合格"));
       ui->intuit_CkBox->setText(QString::fromUtf8("不合格"));
    }
    else
    {
      fillReplaceDocStructList(replaceDocTypeList_Data, "{overallClu}" ,QString::fromUtf8("合格"));
      ui->intuit_CkBox->setText(QString::fromUtf8("合格"));
    }
}

void MainWidget::on_overallClu_CkBox_clicked(bool checked)
{
    if(checked)
    ui->intuit_CkBox->setText(QString::fromUtf8("不合格"));
    else
    ui->intuit_CkBox->setText(QString::fromUtf8("合格"));
}

