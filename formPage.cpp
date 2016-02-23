/******************************************************************************
*dec:生成报表
*******************************************************************************/
#include "mainwidget.h"
#include "QFileDialog"
#include "QTextCodec"

void MainWidget::on_RSMV_clearFrom_PsBtn_clicked()
{
    ui->RSMV_from_TxEdit->clear();
}

void MainWidget::on_RSMV_buildFrom_PsBtn_clicked()
{
    QString style;
    switch(0)
    {
       case 0: style ="XL";break;
       case 1: style ="XL_SMV"     ;break;
       case 2: style ="XL_GSE"     ;break;
       default: style ="XL_Frame";break;
    }

#if 1
        QTime temp_time = QTime::currentTime();
        QString strTime = temp_time.toString("hh_mm_ss");//文件保存不能出现：冒号
        strTime ="./"+style + "_" +strTime + ".txt"; //root

        QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),strTime, tr("Files (*.txt)"));

        if (fileName.isNull())
        {
            return;
        }

        QFile fileTemp(fileName);
        if (!fileTemp.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            show_MsBox(QString::fromUtf8("保存失败"),3000);
            return;
        }

        QTextStream streamTemp(&fileTemp);
        streamTemp<<ui->RSMV_from_TxEdit->toPlainText();
        fileTemp.close();
        show_MsBox(QString::fromUtf8("保存成功"),3000);
#endif
}

void MainWidget::on_RSMV_readFrom_PsBtn_clicked()
{
    QString strPath;

    strPath = QFileDialog::getOpenFileName(this,tr("打开文件"),"./","Files(*.txt *.TXT)",0);

    if (strPath.isEmpty())
    {
       return ;
    }

    QFile file(strPath);
    if (file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       QTextStream floStream(&file);
       ui->RSMV_from_TxEdit->setText(floStream.readAll());
       file.close();
    }
    else
    {
       show_MsBox(QString::fromUtf8("没有数据"),3000);
    }
    return ;
}
