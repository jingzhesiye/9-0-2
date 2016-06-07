#include "mainwidget.h"

void MainWidget::fill_form_intuit( QString str, replaceDocTypeList *replaceDocTypeList_Data)
{
    fillReplaceDocStructList(replaceDocTypeList_Data, "{intuitClu}" ,str);

    overAll_conc.intuit = str;

}

void MainWidget::on_intuit_CkBox_clicked(bool checked)
{
    if(checked)
    ui->intuit_CkBox->setText(QString::fromUtf8("不合格"));
    else
    ui->intuit_CkBox->setText(QString::fromUtf8("合格"));
}
