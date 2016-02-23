/******************************************************************************
*界面 : 数据解析
*功能 : 9-1，9-2 数据解析
*人员 : jingzhesiye@163.com
*时间 : 2013.9.25
*******************************************************************************/

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "SMV/receiveSMV/RSMV_option.h"

void MainWidget::slt_RSMV_analysis_expression()   //展开
{
    int i;
    QString strTemp_1;
    QString strTemp_2;
    BooleanParser parser;
    //strTemp_1 = ui->RSMV_Analysis_Source_TxEdit->toPlainText();
    strTemp_2 =strTemp_1.at(0);
    for(i=1;i<strTemp_1.length();i++)                      //碰到 " " 时存放
    {
        if(strTemp_1.at(i)!=' ')
        {
            strTemp_2=strTemp_2+strTemp_1.at(i);
        }

    }
    Node *rootNode = parser.parse(strTemp_2);
    booleanModel->setRootNode(rootNode);
   // ui->RSMV_Analysis_Analyse_TView->expandAll();
    //ui->RSMV_Analysis_Analyse_TView->resizeColumnToContents(0);
    //ui->RSMV_Analysis_Analyse_TView->expand();
}

void MainWidget::slt_RSMV_analysis_frameStructClicked ( const QModelIndex & current, const QModelIndex & previous )
{
    BooleanModel *typModel = (BooleanModel *)current.model();
    quint16 start,length;
    typModel->getStartLength(current,start,length);

    int start_position = start * 2;
    int end_position = length * 2 + start_position;

    start_position = start_position * 3 / 2;
    end_position = end_position * 3 / 2 - 1;

   // QString sourStr =  ui->RSMV_Analysis_Source_TxEdit->toPlainText();
    ///QString selectStr = sourStr.mid(start_position,end_position - start_position);
    //selectStr = QString("<font color=blue><B>%1</B></font>").arg(selectStr);
    //QString str =  ui->RSMV_Analysis_Source_TxEdit->toPlainText().replace(start_position,end_position - start_position,selectStr);
    //ui->RSMV_Analysis_Source_TxEdit->setText(str);
}

