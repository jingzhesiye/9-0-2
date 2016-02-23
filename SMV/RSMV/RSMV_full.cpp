/******************************************************************************
*界面:  完整性
*功能 : 9-1，9-2 接收数据
*时间 : 2013.9.25
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

void MainWidget::slt_RSMV_full_mode()
{
    hideAllControls();
    MainMenuBar.titleLable ->setText(QString::fromUtf8("完整性"));

    ui->ToolBar_PsBtn_1->show();
    ui->ToolBar_PsBtn_1->setText(QString::fromUtf8("功能切换"));
    ui->ToolBar_PsBtn_3->show();
    ui->ToolBar_PsBtn_3->setText(QString::fromUtf8("控制"));
    ui->stackedWidget->setCurrentIndex(6);

    if (this->timeThreadTimer.RSMV_Full_Timer->isActive())
    {
        ui->RSMV_Full_Connect_Lable->setStyleSheet("border-image: url(:/pic/greenCircle.png);");
    }
    else
    {
        ui->RSMV_Full_Connect_Lable->setStyleSheet("border-image: url(:/pic/redCircle.png);");
    }
    ui->RSMV_Full_StkWidget->setCurrentIndex(0);
    strList_FullTest_History.clear();
    slt_RSMV_full_updateList();
}

void MainWidget::slt_RSMV_full_start(void)
{
    QStringList RSMV_chlItem = ptlOptionsFun->RSMV_SCL_chlItem( );
    QString strTemp;
#if 1
    //屏蔽历史数据打开功能，在完整性测试结束后恢复
    strFullTest_History.clear();
    strList_FullTest_History.clear();
    ui->RSMV_Full_Open_PsBtn ->setEnabled(false);
    ui->RSMV_Full_Delete_PsBtn->setEnabled(false);

    this->slt_RSMV_full_return();

    timeThreadTimer.page3_3_DRowCount = 0;
    timeThreadTimer.page3_3_Time_Elapsed = 0;

    //保存开始前的通道设置
    strTemp =RSMV_chlItem.at(0);
    CHCFGTYPE_Data_Full.IMA = strTemp.toInt(0,10);
    strTemp =RSMV_chlItem.at(1);
    CHCFGTYPE_Data_Full.IMB = strTemp.toInt(0,10);
    strTemp =RSMV_chlItem.at(2);
    CHCFGTYPE_Data_Full.IMC = strTemp.toInt(0,10);

    strTemp =RSMV_chlItem.at(3);
    CHCFGTYPE_Data_Full.UA = strTemp.toInt(0,10);
    strTemp =RSMV_chlItem.at(4);
    CHCFGTYPE_Data_Full.UB = strTemp.toInt(0,10);
    strTemp =RSMV_chlItem.at(5);
    CHCFGTYPE_Data_Full.UC = strTemp.toInt(0,10);

    ui->RSMV_Full_Connect_Lable->setStyleSheet("border-image: url(:/pic/greenCircle.png);");

    ui->RSMV_Full_RuningTime_LnEdit->setText(QString::number(0));

    /********************
        删除完整性数据源文件再新建
    *********************/
    QFile file("/sdcard/XL_FullTest_Source.txt");
    if (file.exists())
    {
        file.remove();
    }
    file.open(QIODevice::ReadWrite);
    QTextStream textStream(&file);

    textStream<<tr("%1").arg(QString::fromUtf8("行序号,事件,上一帧序号,当前点序号,时间\r\n"));
    file.close();

    int simpleRate = ui->RSMV_Full_SampleFre_LnEdit->text().toInt();

    transmitsSimply ((UINT8*)"SMDIGITALTRANSFORMERS\r\n");//切换工作模式

    transmitsSimply ((UINT8 *)"FRAM_INTEGRALITY_START");//启动完整性测试

    for (int row = 0; row < ui->RSMV_Full_RealTime_TblWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->RSMV_Full_RealTime_TblWidget->columnCount(); column++)
        {
            ui->RSMV_Full_RealTime_TblWidget->item(row, column)->setText("");
        }
    }
    systemTimer->setInterval(1000);    //运行时间1s1次
    systemTimer->start();
    systemTimeCal=0;

    //timeThreadTimer-> gfull_FraS;
    timeThreadTimer.serialNum = 0;  //序列号
    timeThreadTimer.delayCount = 0; //延时系数
    timeThreadTimer.simpleRate = simpleRate;    //采样率
    timeThreadTimer.lastFraE = simpleRate - 1;

     timeThreadTimer.IsLanOn(true);
    showInformationBox("正在接收");
    timeThreadTimer.run(RSMV_FULL);
    MainMenuBar.set_TitleStatus("SMV正在接收",2);
    lock_MainMenubar(8);
#endif
}

void MainWidget::slt_RSMV_Full_Item_update(QIntList targetRow, QStringList strSerial,  QStringList eventType, QStringList strLast, QStringList strCurrent, QStringList elasedTime)//更新表格信息
{
    //qDebug()<<"slot_Update_Page3_3_TableWidget";
#if 1
    for (int i = 0; i < targetRow.count(); i++)
    {
        ui->RSMV_Full_RealTime_TblWidget->item(targetRow.at(i), 0)->setText(strSerial.at(i));
        ui->RSMV_Full_RealTime_TblWidget->item(targetRow.at(i), 1)->setText(eventType.at(i));
        ui->RSMV_Full_RealTime_TblWidget->item(targetRow.at(i), 2)->setText(strLast.at(i));
        ui->RSMV_Full_RealTime_TblWidget->item(targetRow.at(i), 3)->setText(strCurrent.at(i));
        ui->RSMV_Full_RealTime_TblWidget->item(targetRow.at(i), 4)->setText(elasedTime.at(i));
    }
    if (!targetRow.isEmpty())
    {
        ui->RSMV_Full_RealTime_TblWidget->setCurrentCell(targetRow.last(), 0);
    }
#endif
}

void MainWidget::slot_FullTbw_RemoveRows(int start, int end)
{


    for (int row = start; row < ui->RSMV_Full_RealTime_TblWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->RSMV_Full_RealTime_TblWidget->columnCount(); column++)
        {
            ui->RSMV_Full_RealTime_TblWidget->item(row, column)->setText("");
        }
    }

}

void MainWidget::slt_RSMV_full_stop(void)
{
    UINT16  CHCFGTYPE_Temp[15];
    ui->RSMV_Full_Connect_Lable->setStyleSheet("border-image: url(:/pic/redCircle.png);");
    ui->RSMV_Full_Open_PsBtn ->setEnabled(true);    //屏蔽历史数据打开功能，在完整性测试结束后恢复
    ui->RSMV_Full_Delete_PsBtn->setEnabled(true);

    transmitsSimply ((UINT8 *)"FRAM_INTEGRALITY_END");//关闭
    transmitsSimply ((UINT8*)"SMACTUALLOAD\r\n");//返回实负荷

    CHCFGTYPE_Temp[0] =22;

    CHCFGTYPE_Temp[5]  =5; //IMA
    CHCFGTYPE_Temp[6]  =6;
    CHCFGTYPE_Temp[7]  =7;

    CHCFGTYPE_Temp[8]  =8; //UA
    CHCFGTYPE_Temp[9]  =9;
    CHCFGTYPE_Temp[10] =10;


    if( set_smv_writeCh(CHCFGTYPE_Temp))
    {
         timeThreadTimer.IsLanOn(false);
        showInformationBox("停止接收");
        MainMenuBar.set_TitleStatus("完整性",0);
        timeThreadTimer.stop();
        systemTimer->stop();
        unlock_MainMenubar();
    }
}

void MainWidget::slt_RSMV_full_save()
{
    if( MainMenuBar.SDLabel ->isHidden())
    {
        showInformationBox("请插入SD卡");
        return;
    }

    QTime time = QTime::currentTime();
    QString strTime = time.toString("hh_mm_ss");
    strTime = "/sdcard/XL_SMV_FULL" + strTime + ".txt";
    QFile file("/sdcard/XL_FullTest_Source.txt");
    if (!file.exists())
    {
        QMessageBox::warning(this, QString::fromUtf8("完整性"), QString::fromUtf8("保存失败"));
        return;
    }
    file.open(QIODevice::ReadWrite);
    if (!file.copy(strTime))
    {
        QMessageBox::warning(this, QString::fromUtf8("完整性"), QString::fromUtf8("保存失败"));
        return;
    }

    this->showInformationBox("保存成功");

    file.close();
}

void MainWidget::slt_RSMV_full_update()
{
    //qDebug()<<"systemTimeCal"<<QString ::number(systemTimeCal);
    QTime timeTmp;
    QString elapsedTime = timeTmp.addSecs(systemTimeCal).toString("hh:mm:ss");
    ui->RSMV_Full_RuningTime_LnEdit->setText(elapsedTime);
    if( systemTimeCal >= ( unsigned int )ui->RSMV_Full_TimelLimit_LnEdit->text().toInt(0,10)*60)
    {
        slt_RSMV_full_stop();
    }
}

void MainWidget::slt_RSMV_full_open()      //打开文件
{
    QFile file;
    QString fileName;
    QString prefix = QString("/sdcard/");
    if (ui->RSMV_Full_LstWidget->currentIndex().row() != -1)
    {
        fileName = ui->RSMV_Full_LstWidget->currentItem()->text();
        file.setFileName(prefix+fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, QString::fromUtf8("完整性历史文件"), QString::fromUtf8("打开失败"));
            return;
        }
        strFullTest_History = file.readAll();
        strList_FullTest_History = strFullTest_History.split("\r\n");
        strFullTest_History.clear();
        strList_FullTest_History.removeFirst();
        if (QString(strList_FullTest_History.last()).isEmpty())
        {
            strList_FullTest_History.removeLast();
        }

        if (strList_FullTest_History.count() == 0)
        {
            this->showInformationBox("文件是空的");
            return;
        }

        ui->RSMV_Full_StkWidget->setCurrentIndex(1);

        //根据每页最多显示X行，更新当前页码为第一页
        int maxDisplay = ui->RSMV_Full_MaxPage_CbBox->currentText().toInt();  //每页最多显示行数
        int pageCount;  //最大页码
        int remainder;  //余数
        remainder = strList_FullTest_History.count() % maxDisplay;
        if (remainder != 0)
        {
            pageCount = (strList_FullTest_History.count() / maxDisplay) + 1;
        }
        else
        {
            pageCount = (strList_FullTest_History.count() / maxDisplay);
        }
        ui->RSMV_Full_CurrentPage_CbBox->clear();
        for (int row = 0; row < pageCount; row++)
        {
            ui->RSMV_Full_CurrentPage_CbBox->addItem(QString::number(row));
        }
        ui->RSMV_Full_CurrentPage_CbBox->setCurrentIndex(0);

        int currentPage = 0;
        int lastPage = ui->RSMV_Full_CurrentPage_CbBox->count() -1 ;

        int start = maxDisplay * currentPage;
        int end = 0;
        int rowCount = 0;
        if (currentPage == lastPage)
        {
            end = strList_FullTest_History.count() -1;
        }
        else
        {
            end = maxDisplay - 1;
        }
        rowCount = end - start + 1;

        slt_RSMV_full_pageDisplay();
    }
    else
    {
        QMessageBox::warning(this, QString::fromUtf8("提醒"), QString::fromUtf8("请选择目标"));
    }
}

void MainWidget::slt_RSMV_full_delete()    //删除文件
{
    if (ui->RSMV_Full_LstWidget->currentIndex().row() == -1)
    {
        this->showInformationBox("请选择目标");
        return;
    }
    QString fileName;
    QString prefix = QString("/sdcard/");

    QMessageBox box;
    QPushButton *btn_Ok;
    QPushButton *btn_Canel;

    box.setText(QString::fromUtf8("确定删除此文件？"));
    btn_Ok = box.addButton(QString::fromUtf8("确定"), QMessageBox::AcceptRole);
    btn_Canel = box.addButton(QString::fromUtf8("取消"), QMessageBox::RejectRole);
    box.exec();
    if (box.clickedButton() == btn_Ok)
    {
        if (ui->RSMV_Full_LstWidget->currentIndex().row() != -1)
        {
            fileName = ui->RSMV_Full_LstWidget->currentItem()->text();
            if (!QFile::remove(prefix + fileName))
            {
                QMessageBox::warning(this, QString::fromUtf8("历史数据"), QString::fromUtf8("删除失败"));
            }
        }
        slt_RSMV_full_updateList();
    }
    if (ui->RSMV_Full_LstWidget->count() != 0)
    {
        ui->RSMV_Full_LstWidget->setCurrentRow(0);
    }
}

void MainWidget::slt_RSMV_full_return()    //返回
{
    ui->RSMV_Full_StkWidget->setCurrentIndex(0);
    strList_FullTest_History.clear();
}

void MainWidget::slt_RSMV_full_updateList()//更新列表
{
    QDir dir("/sdcard");
    QFileInfoList infoList = dir.entryInfoList();
    QString fileName;
    ui->RSMV_Full_LstWidget->clear();
    for (int i = 0; i < infoList.count(); i++)
    {
        fileName = infoList.at(i).fileName();
        if ((fileName.right(3).localeAwareCompare("txt") == 0) && (fileName.contains("XL_SMV_FULL")))
        {
            if (!fileName.contains("Source"))
            {
                ui->RSMV_Full_LstWidget->addItem(fileName);
            }
        }
    }
}

void MainWidget::slt_RSMV_full_page()     //当前页码改变
{
    int maxDisplay = ui->RSMV_Full_MaxPage_CbBox->currentText().toInt();  //每页最多显示行数
    int currentPage = ui->RSMV_Full_CurrentPage_CbBox->currentText().toInt();
    int start = currentPage * maxDisplay;
    int end = start + maxDisplay - 1;


        int lasePage = ui->RSMV_Full_CurrentPage_CbBox->count() - 1;
        if (currentPage == lasePage)
        {
            end = this->strList_FullTest_History.count() - 1;
        }
        int rowCount = end - start + 1;
        for (int row = rowCount; row < ui->RSMV_Full_HstrData_TblWidget->rowCount(); row++)
        {
            for (int column = 0; column < ui->RSMV_Full_HstrData_TblWidget->columnCount(); column++)
            {
                ui->RSMV_Full_HstrData_TblWidget->item(row, column)->setText("");
            }
        }

        for (int row = start; row < end + 1; row++)
        {
            QStringList dataList = QString(strList_FullTest_History.at(row)).split(",");

            for (int column = 0; column < ui->RSMV_Full_HstrData_TblWidget->columnCount(); column++)
            {
                ui->RSMV_Full_HstrData_TblWidget->item(row - start, column)->setText(dataList.at(column));
            }
        }
}

void MainWidget::slt_RSMV_full_pageDisplay() //每页最多显示X行
{
    //根据每页最多显示X行，更新当前页码为第一页
    int maxDisplay = ui->RSMV_Full_MaxPage_CbBox->currentText().toInt();  //每页最多显示行数
    int pageCount;    //最大页码

    if ((strList_FullTest_History.count() % maxDisplay) != 0)
    {
        pageCount = (strList_FullTest_History.count() / maxDisplay) + 1;
    }
    else
    {
        pageCount = (strList_FullTest_History.count() / maxDisplay);
    }

    ui->RSMV_Full_CurrentPage_CbBox->clear();

    for (int row = 0; row < pageCount; row++)
    {
        ui->RSMV_Full_CurrentPage_CbBox->addItem(QString::number(row));
    }
    ui->RSMV_Full_CurrentPage_CbBox->setCurrentIndex(0);


    while (ui->RSMV_Full_HstrData_TblWidget->rowCount() > maxDisplay)
    {
        ui->RSMV_Full_HstrData_TblWidget->removeRow(0);
    }
    while (ui->RSMV_Full_HstrData_TblWidget->rowCount() < maxDisplay)
    {
        ui->RSMV_Full_HstrData_TblWidget->insertRow(0);
        for (int column = 0; column < ui->RSMV_Full_HstrData_TblWidget->columnCount(); column++)
        {
            ui->RSMV_Full_HstrData_TblWidget->setItem(0, column, new QTableWidgetItem(""));
        }
    }

    for (int row = 0; row < ui->RSMV_Full_HstrData_TblWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->RSMV_Full_HstrData_TblWidget->columnCount(); column++)
        {
            switch (row % 3)
            {
            case 0:
                ui->RSMV_Full_HstrData_TblWidget->item(row, column)->setBackgroundColor(QColor(255, 255, 204)); //蓝色
                break;
            case 1:
                ui->RSMV_Full_HstrData_TblWidget->item(row, column)->setBackgroundColor(QColor(204, 255, 255)); //绿色
                break;
            case 2:
                ui->RSMV_Full_HstrData_TblWidget->item(row, column)->setBackgroundColor(QColor(255, 204, 204)); //红色
                break;
            default:
                break;
            }
        }
    }


    slt_RSMV_full_page();
}


