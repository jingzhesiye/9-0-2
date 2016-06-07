#include "mainwidget.h"
#include "QDebug"
#include "QFileDialog"
#include "QDesktopServices"


//获取原始记录模板地址
QString MainWidget::getTemplatePath()
{
    QDir    dirTemp;
    QString strPath=dirTemp.currentPath();//当前路径
    //qDebug()<<"asd"<<strPath;
    strPath.append("/templet/DC_template_verifiedRecord.doc");
    return strPath;
}

// list:待装载的列表 sourceStr：搜索项 replaceStr：替代项
void MainWidget::fillReplaceDocStructList(replaceDocTypeList *list, QString searchStr, QString replaceStr)
{
    replaceDocType replaceDocType_Data;
    replaceDocType_Data.searchStr = searchStr;
    replaceDocType_Data.replaceStr = replaceStr;
    list->append(replaceDocType_Data);
}



//替换数据列表的内容
void MainWidget::fill_formInfo( QTableWidget *from_information_TbWidget, replaceDocTypeList *replaceDocTypeList_Data)
{
    QString cUserName           = from_information_TbWidget->item(0, 1)->text(); //送检单位
    QString cUserAddr           = from_information_TbWidget->item(0, 3)->text(); //送检单位地址
    QString cMeterTypeName      = from_information_TbWidget->item(1, 1)->text(); //仪器名称
    QString manufactoryName     = from_information_TbWidget->item(1, 3)->text(); //制造厂名
    QString cMeterTypeNum       = from_information_TbWidget->item(2, 1)->text(); //型号
    QString cMeterTypeDate      = from_information_TbWidget->item(2, 3)->text(); //生产日期
    QString manufactoryNum      = from_information_TbWidget->item(3, 1)->text(); //出厂编号
    QString cClassGrade         = from_information_TbWidget->item(3, 3)->text(); //精度等级
    QString voltageView         = from_information_TbWidget->item(4, 1)->text(); //额定电压
    QString currentView         = from_information_TbWidget->item(4, 3)->text(); //额定电流
    QString constView           = from_information_TbWidget->item(5, 1)->text(); //额定常数
    QString cCheckCase          = from_information_TbWidget->item(5, 3)->text(); //检定依据
    QString checkDate           = from_information_TbWidget->item(5, 1)->text(); //检定日期
    QString nextCheckDate       = from_information_TbWidget->item(5, 3)->text(); //有 效 期
    QString fTemperature        = from_information_TbWidget->item(6, 1)->text(); //温度
    QString fHumidity           = from_information_TbWidget->item(6, 3)->text(); //湿度

    QString checkAddr          = from_information_TbWidget->item(8, 1)->text(); //检定地点

    QString checker           = from_information_TbWidget->item(12,1)->text(); //检定员
    QString auditer           = from_information_TbWidget->item(12,3)->text(); //核验员


    fillReplaceDocStructList(replaceDocTypeList_Data, "{cUserName}"        ,cUserName);            //送检单位
    fillReplaceDocStructList(replaceDocTypeList_Data, "{cUserAddr}"        ,cUserAddr);            //送检单位地址
    fillReplaceDocStructList(replaceDocTypeList_Data, "{cMeterTypeName}"   ,cMeterTypeName);       //仪器名称
    fillReplaceDocStructList(replaceDocTypeList_Data, "{manufactoryName}"  ,manufactoryName);      //制造厂名
    fillReplaceDocStructList(replaceDocTypeList_Data, "{cMeterTypeNum}"    ,cMeterTypeNum);        //型号

    fillReplaceDocStructList(replaceDocTypeList_Data, "{manufactoryNum}"   ,manufactoryNum);       //出厂编号
    fillReplaceDocStructList(replaceDocTypeList_Data, "{cMeterTypeDate}"   ,cMeterTypeDate);       //生产日期
    fillReplaceDocStructList(replaceDocTypeList_Data, "{cClassGrade}"      ,cClassGrade);          //精度等级
    fillReplaceDocStructList(replaceDocTypeList_Data, "{voltageView}"      ,voltageView);          //额定电压
    fillReplaceDocStructList(replaceDocTypeList_Data, "{currentView}"      ,currentView);          //额定电流
    fillReplaceDocStructList(replaceDocTypeList_Data, "{constView}"        ,constView);            //额定常数

    fillReplaceDocStructList(replaceDocTypeList_Data, "{cCheckCase}"      ,cCheckCase);            //检定依据
    fillReplaceDocStructList(replaceDocTypeList_Data, "{checkDate}"        ,checkDate);            //检定日期
    fillReplaceDocStructList(replaceDocTypeList_Data, "{nextCheckDate}"    ,nextCheckDate);        //有效期
    fillReplaceDocStructList(replaceDocTypeList_Data, "{fTemperature}"     ,fTemperature);         //温度
    fillReplaceDocStructList(replaceDocTypeList_Data, "{fHumidity}"        ,fHumidity);            //湿度

    fillReplaceDocStructList(replaceDocTypeList_Data, "{checker}"        ,checker);            //检定员
    fillReplaceDocStructList(replaceDocTypeList_Data, "{auditer}"        ,auditer);            //核验员
    fillReplaceDocStructList(replaceDocTypeList_Data, "{checkAddr}"     ,checkAddr);            //核验员


}




