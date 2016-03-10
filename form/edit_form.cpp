/******************************************************************************
*dec:生成报表
*******************************************************************************/
#include "mainwidget.h"
#include "QFileDialog"
#include "QTextCodec"
#include <QAxWidget>
#include <QAxObject>
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>

void MainWidget::on_RSMV_clearFrom_PsBtn_clicked()
{
    ui->from_error_TxEdit->clear();
}

void MainWidget::on_RSMV_saveFormMsg_PsBtn_clicked()
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
        streamTemp<<ui->from_error_TxEdit->toPlainText();
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
       ui->from_error_TxEdit->setText(floStream.readAll());
       file.close();
    }
    else
    {
       show_MsBox(QString::fromUtf8("没有数据"),3000);
    }
    return ;
}

void MainWidget::on_RSMV_buildFrom_PsBtn_clicked()
{
    QString strPath=getTemplatePath();
    QFile   file(strPath);

   //qDebug()<<strPath;

    if (!file.exists())
    {
        show_MsBox(QString::fromUtf8("找不到报表模板路径"),3000);
    }

#if 1
    QAxWidget* temp_AxWidget = new QAxWidget("Word.Application");
    temp_AxWidget->setProperty("Visible", true);                       //新建一个word应用程序,并设置为可见

    QAxObject* documents = temp_AxWidget->querySubObject("Documents");  //获取所有的工作文档
    documents->dynamicCall("Open(QVariant)",strPath );                  //路径不对打开奔溃

    QAxObject *selection = temp_AxWidget->querySubObject("Selection");
    QAxObject *find = selection->querySubObject("Find");


    QList<QVariant> list2;                                               //*****Find Word http://technet.microsoft.com/zh-cn/library/ff193977
    list2.append("{cUserName}");                                         //find text
    list2.append(QVariant());//2
    list2.append(QVariant());//3
    list2.append(QVariant());//4
    list2.append(QVariant());//5
    list2.append(QVariant());//6
    list2.append(QVariant());//7
    list2.append(QVariant());//8
    list2.append(QVariant());//9
    list2.append(QString::fromUtf8("深圳市星龙科技"));                     //replace text
    list2.append(2);//replace all：2
    list2.append(QVariant());//12
    list2.append(QVariant());//13
    list2.append(QVariant());//14
    list2.append(QVariant());//15

    replaceDocTypeList replaceDocTypeList_Data;                            //装载搜索内容和替换内容的列表
    fillReplaceDocTypeList(ui->from_information_TbWidget,&replaceDocTypeList_Data);

    for (int i = 0; i < replaceDocTypeList_Data.count(); i++)
    {
        list2.replace(0, replaceDocTypeList_Data.at(i).searchStr);
        list2.replace(9, replaceDocTypeList_Data.at(i).replaceStr);
        find->dynamicCall("Execute (QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant& ,QVariant& ,QVariant& , QVariant&, QVariant&, QVariant&, QVariant&)", list2);
      //qDebug()<<replaceDocTypeList_Data.at(i).replaceStr;
    }
#endif
//  documents->dynamicCall("Save()");//保存
//  documents->dynamicCall("Close(boolean)", true);//关闭文本窗口
//  temp_AxWidget->dynamicCall("Quit(void)");//退出word
}


#if 0
//AC.template.verifiedRecord
void  MainWidget::init_word()
{
    QAxWidget word("Word.Application");
    word.setProperty("Visible", false);//隐式的打开一个word应用程序

    QAxObject * documents = word.querySubObject("Documents"); //获取所有工作文档
    documents->dynamicCall("Add (void)");//创建一个word文档
    QAxObject * document = word.querySubObject("ActiveDocument"); //获取当前激活的文档
    QAxObject *selection = word.querySubObject("Selection"); //写入文件内容

    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString    str = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    selection->dynamicCall("TypeText(const QString&)","hello"+str);

    //设置保存
    QVariant newFileName("e:/test.doc"); //存放位置和名称
    QVariant fileFormat(1); //文件格式
    QVariant LockComments(false);
    QVariant Password("");     //设置打开密码
    QVariant recent(true);
    QVariant writePassword("");
    QVariant ReadOnlyRecommended(false);

    document->querySubObject("SaveAs(const QVariant&, const QVariant&,const QVariant&, const QVariant&, const QVariant&, const QVariant&,const QVariant&)",    newFileName, fileFormat, LockComments, Password, recent, writePassword, ReadOnlyRecommended);
    document->dynamicCall("Close (boolean)", true);   //关闭文档
    word.dynamicCall("Quit (void)");//退出
}
#endif
