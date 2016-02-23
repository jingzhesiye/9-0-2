/******************************************************************************
*Function : 9-1，9-2 协议设置,通道设置
*人员 : jingzhesiye@163.com
*时间 : 2014.3.10
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"
#define NETPORT_Num 1            //光口选择

SendSMV::SendSMV()
{
    init_option();
}

void SendSMV::init_option()     //选项菜单初始化
{
    rms_harmonic_action= new QAction(QString::fromUtf8("    谐    波    "), this);
    rms_rms_action= new QAction(QString::fromUtf8("    有效值   "), this);
    rms_mode_menu = new QMenu(this);
    rms_mode_menu->addAction( rms_rms_action);
    rms_mode_menu->addAction( rms_harmonic_action);

    rms_loss_action   = new QAction(QString::fromUtf8("  丢帧设置  "), this);
    rms_timeSyn_action= new QAction(QString::fromUtf8("  同步输出  "), this);
    rms_set_menu = new QMenu(this);
    rms_set_menu->addAction( rms_loss_action);
    rms_set_menu->addAction( rms_timeSyn_action);

    rms_wave_action   = new QAction(QString::fromUtf8("    波形图    "), this);
    rms_phasor_action = new QAction(QString::fromUtf8("    相量图    "), this);
    rms_show_menu   = new QMenu(this);
    rms_show_menu->addAction( rms_wave_action);
    rms_show_menu->addAction( rms_phasor_action);
}

void MainWidget::init_SSMV()
{
    SSMV.rms_mode_menu->setStyleSheet(MenuStyleSheet());
    SSMV.rms_show_menu->setStyleSheet(MenuStyleSheet());
    SSMV.rms_set_menu->setStyleSheet(MenuStyleSheet());

    ui->SSMV_RMS_TblWidget->setColumnWidth(0,85);
    ui->SSMV_RMS_TblWidget->setColumnWidth(1,153);
    ui->SSMV_RMS_TblWidget->setColumnWidth(2,85);
    ui->SSMV_RMS_TblWidget->setColumnWidth(3,153);

    ui->SSMV_Harmonic_TblWidget->setColumnWidth(0,75);
    ui->SSMV_Harmonic_TblWidget->setColumnWidth(1,50);
    ui->SSMV_Harmonic_TblWidget->setColumnWidth(2,125);
    ui->SSMV_Harmonic_TblWidget->setStyleSheet( VHscrollBarStyleSheet() );
    ui->SSMV_Harmonic_TblWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);     //一直显示垂直滚动条

    connect( SSMV.rms_rms_action,            SIGNAL(triggered()), this, SLOT(on_homePage_SSMV_PsBtn_clicked()));
    connect( SSMV.rms_harmonic_action,       SIGNAL(triggered()), this, SLOT(slt_SSMV_harmonic_mode()));
    connect( SSMV.rms_wave_action,           SIGNAL(triggered()), this, SLOT(slt_SSMV_wave_mode()));
    connect( SSMV.rms_phasor_action,         SIGNAL(triggered()), this, SLOT(slt_SSMV_phasor_mode()));
    connect( SSMV.rms_loss_action,           SIGNAL(triggered()), this, SLOT(slt_SSMV_loss_mode()));
    connect( SSMV.rms_timeSyn_action,        SIGNAL(triggered()), this, SLOT(slt_SSMV_timeSyn_mode()));
}

/*******************************************************************************************************
*Function:   获取参数
*QString 0:PRODUCT,1:IEC61850,2:macDst,3:SAMNUM,4:ASDUNUM,5:VOLTAGERANGE,6:CURRENTRANGE,7:APPID,8:SVID,9:FT3OUT;
*******************************************************************************************************/
void MainWidget::SSMV_ptl_StringListToItem(QStringList strList)
{
    QString strTemp_1,strTemp_2;
    int i = 0;
    int j = 0;

    strTemp_1=strList.at(0);
    pSPTYPE_Data->PRODUCT        = strTemp_1.toInt(0,10);                             //电表厂家

    strTemp_1=strList.at(1);
    pSPTYPE_Data->IEC61850       = strTemp_1.toInt(0,10);                             //协议类型

    strTemp_1=strList.at(2);                                                          //MAC转换成数组形式
    for(i=0;i<strTemp_1.length();i++)                                                 //碰到 "-" 时存放
    {
        if((strTemp_1.at(i)=='-')||(strTemp_1.at(i)==',')||(strTemp_1.at(i)=='.'))
        {
            pSPTYPE_Data->DADDR[j]=strTemp_2.toUInt(0,16);
            strTemp_2="0";
            j++;
        }
        else
        {
             strTemp_2=strTemp_2+strTemp_1.at(i);
        }

         pSPTYPE_Data->DADDR[5]=strTemp_2.toUInt(0,16);
    }

    strTemp_1=strList.at(3);
    pSPTYPE_Data->SAMNUM         = strTemp_1.toInt(0,10);                               //采样数目

    strTemp_1=strList.at(4);
    pSPTYPE_Data->ASDUNUM        = strTemp_1.toInt(0,10);                               //ASDU个数

    strTemp_1=strList.at(5);
    pSPTYPE_Data->VOLTAGERANGE   = strTemp_1.toFloat(0)*1000;                           //电压量程

    strTemp_1=strList.at(6);
    pSPTYPE_Data->CURRENTRANGE   = strTemp_1.toUInt(0,10);                              //电流量程

    pSPTYPE_Data->VOLTAGERANGE_2N =57.735025;

     strTemp_1=strList.at(9);

    if(3 == pSPTYPE_Data->IEC61850)                                                       //FT3 参数  100001000;
    {
        pSPTYPE_Data->FT3OUT=strTemp_1.toInt(0,10);
        pSPTYPE_Data->IEC61850       = 0;                         //手持式FT3发送必须设置 IEC61850=0

    }
    else
    {
         pSPTYPE_Data->FT3OUT= 0;
    }

    pSPTYPE_Data->NETPORT=1;            //使能
    pSPTYPE_Data->NETTYPE=1;
    pISABLE_SP_Data->PRODUCT=1;
    pISABLE_SP_Data->IEC61850=1;
    pISABLE_SP_Data->DADDR=1;
    pISABLE_SP_Data->SAMNUM=1;
    pISABLE_SP_Data->ASDUNUM=1;
    pISABLE_SP_Data->VOLTAGERANGE=1;
    pISABLE_SP_Data->VOLTAGERANGE_2N=1;
    pISABLE_SP_Data->CURRENTRANGE=1;
    pISABLE_SP_Data->TRANMODETYPE=1;
    pISABLE_SP_Data->NETPORT=1;
    pISABLE_SP_Data->NETTYPE=1;
    pISABLE_SP_Data->FT3OUT=1;
}

/*******************************************************************************************************
*Function:    协议参数设置
*Description: 1.SETAPPID;用在数字电能表校验的虚负荷/虚拟检定时为帧输出填写设置的APPID
              2.SETAPPID;用在实负荷检定和电子式互感器校验时候，用来APPID过滤。
 *warning :   1.工作模式必须提前设置 因为设置后，各类参数恢复默认
              2. pSPTYPE_Data->IEC61850=0; FT3手持式必须这样设置 手持是和工控机的不同
 QString 0:PRODUCT,1:IEC61850,2:macDst,3:SAMNUM,4:ASDUNUM,5:VOLTAGERANGE,6:CURRENTRANGE,7:APPID,8:SVID,9:FT3OUT;
*******************************************************************************************************/
void MainWidget::slt_SSMV_ptl_write(QStringList strList)
{
    int noEnd=0;
    QString strTemp_1,strTemp_2,APPID;

    SSMV_ptl_StringListToItem( strList );

    if(ERR_RIGHT!=transmitsSimply ((UINT8*)"SMVIRTUALTEST\r\n"))    //处于虚拟检定模式 可以发送－1 －2 FT3
    {
         showInformationBox("通信异常");
         return;
    }
     strTemp_1  = strList.at(1);
    if( strTemp_1.toInt(0,10) != 3  )   //ft3
    {
        APPID = strList.at(7);
        strTemp_1="SETAPPIDAPPID;0X4000\r\n";
        strTemp_2 =QString::number(APPID.toInt(0,16),16);
        strTemp_1=strTemp_1.replace(16,4,strTemp_2) ;
        transmitsSimply((UINT8 *)strTemp_1.toLatin1().data());

        strTemp_1="SETSVIDSVID;XJPA_MU0001\r\n";
        strTemp_2 =strList.at(8);;
        strTemp_2.remove(QChar(' '), Qt::CaseInsensitive);
        strTemp_1=strTemp_1.replace(12,11,strTemp_2) ;
        transmitsSimply((UINT8 *)strTemp_1.toLatin1().data());
    }

    do{
        if(  theDevice->setSP_part(pSPTYPE_Data,pISABLE_SP_Data) == ERR_RIGHT)
        {
            showInformationBox("映射成功");
            noEnd=0;
        }
        else
        {
            noEnd ++;
            if(noEnd==5)
            {
               showInformationBox("通信异常");
                return;
            }
        }
      }  while(noEnd);
}

void MainWidget::slt_RSMV_ptl_write(QStringList strList)
{
        int noEnd=0;
        QString strTemp_1 ;

        SSMV_ptl_StringListToItem( strList );


        strTemp_1  = strList.at(1);
       if( strTemp_1.toInt(0,10) == 3  )   //切换RFT3
       {
           transmitsSimply ((UINT8*)"SMDIGITALTRANSFORMERS\r\n");
           pSPTYPE_Data->IEC61850=0;
           pSPTYPE_Data->FT3OUT= 0;
       }
        else
       {
            pSPTYPE_Data->FT3OUT= 0;
            if(ERR_RIGHT!=transmitsSimply ((UINT8*)"SMACTUALLOAD\r\n"))
            {
                 showInformationBox("通信异常");
                 return;
            }

            strTemp_1="SETAPPIDAPPID;0\r\n";//过滤
            transmitsSimply((UINT8 *)strTemp_1.toLatin1().data());
        }

        do{
            if(  theDevice->setSP_part(pSPTYPE_Data,pISABLE_SP_Data) == ERR_RIGHT)
            {
                showInformationBox("映射成功");
                noEnd=0;
            }
            else
            {
                noEnd ++;
                if(noEnd==5)
                {
                   showInformationBox("通信异常");
                    return;
                }
            }
          }  while(noEnd);
}

void MainWidget::slt_SSMV_ptl_read()
{
    QString PRODUCT,IEC61850,macDst,SAMNUM,ASDUNUM,VOLTAGERANGE,CURRENTRANGE,APPID,SVID,strTemp;
    QStringList strList;
    int noEnd = 0;
    int intTemp=0;

    UINT16 appid;
    char *PtrTemp = (char *)malloc(20 * sizeof(char));
    do{
        if(theDevice->getAppid(&appid) == ERR_RIGHT)
        {
            APPID =QString::number(appid,16);
            noEnd =0;
        }
        else
        {
            usleep(500);
            noEnd ++;
            if(noEnd==5)
            {
                showInformationBox("通信异常");
                free(PtrTemp);
                PtrTemp = NULL;
                return;
            }
        }
      }  while(noEnd);

    do{
        if(theDevice->getSvID(PtrTemp) == ERR_RIGHT)
        {
            QString str(PtrTemp);
            SVID =str;//SETSVID
            noEnd =0;
        }
        else
        {
            usleep(500);
            noEnd ++;
            if(noEnd==5)
            {
                showInformationBox("通信异常");
                free(PtrTemp);
                PtrTemp = NULL;
                return;
            }
        }
      }  while(noEnd);

    do{
        if( theDevice->getSP(pSPTYPE_Data) == ERR_RIGHT)
        {
            showInformationBox("成功读取");
            noEnd=0;
        }
        else
        {
            usleep(500);
            noEnd ++;
            if(noEnd==5)
            {
                showInformationBox("通信异常");
                free(PtrTemp);
                PtrTemp = NULL;
                return;
            }
        }
      }  while(noEnd);

    PRODUCT =QString::number(pSPTYPE_Data->PRODUCT);        //电表厂家
    IEC61850=QString::number(pSPTYPE_Data->IEC61850);

    strTemp=QString::number(pSPTYPE_Data->DADDR[0] & 0xff, 16);                   //macAdd

    for(int i = 1 ; i < 6 ; i++ )
    {
        strTemp = strTemp + "-" + QString::number(pSPTYPE_Data->DADDR[i] & 0xff, 16);
    }

    macDst = strTemp;

    switch(pSPTYPE_Data->SAMNUM)                                                 //采样数目
    {
        case  10 : intTemp=0 ; break ;
        case  20 : intTemp=1 ; break ;
        case  40 : intTemp=2 ; break ;
        case  48 : intTemp=3 ; break ;
        case  80 : intTemp=4 ; break ;
        case  96 : intTemp=5 ; break ;
        case 128 : intTemp=6 ; break ;
        case 192 : intTemp=7 ; break ;
        case 200 : intTemp=8 ; break ;
        case 256 : intTemp=9 ; break ;
        default: break;
    }

    SAMNUM       = QString ::number(intTemp);
    ASDUNUM      = QString ::number(pSPTYPE_Data->ASDUNUM -1);
    VOLTAGERANGE = QString("%1").arg(pSPTYPE_Data->VOLTAGERANGE / 1000);//电压量程
    CURRENTRANGE = QString("%1").arg(pSPTYPE_Data->CURRENTRANGE);//电流量程
    strList<<PRODUCT<<IEC61850<<macDst<<SAMNUM<<ASDUNUM<<VOLTAGERANGE<<CURRENTRANGE<<APPID<<SVID;

    emit   sig_SSMV_SCL_ptl_readArg( strList);

    free(PtrTemp);
    PtrTemp = NULL;

}

/*******************************************************************************************************
*Function:    协议参数设置
//CNT;IL1,IL2,IL3,UL1,UL2,UL3
//QString MU_mode,Mu2_cnt,Mu2_MAC,MU2_APPID,MU2_SVID;
*******************************************************************************************************/
void MainWidget::slt_SSMV_chl_write( QStringList MU1_list,QStringList MU2_list)
{
    QString strTemp;
    UINT8  CHTYPE_Temp[15]={0};    // 双通道参数
    UINT16 CHCFGTYPE_Temp[16]={0};  //单通道参数

    strTemp =MU1_list.at(0);
    CHCFGTYPE_Temp[0] = strTemp.toUInt(0,10); //MU1 通道数目

    strTemp =MU2_list.at(1);
    CHTYPE_Temp[0] = strTemp.toUInt(0,10);    //MU2 通道数目

    for(int i =1;i<7;i++)      //通道顺序  单通道参数
    {
        strTemp =MU1_list.at(i);
        CHTYPE_Temp[i] = CHCFGTYPE_Temp[i+4]=strTemp.toInt(0,10);
    }

     strTemp =MU2_list.at(0);

    if(1==strTemp.toInt(0,10))//第二个MU使能 0:代表不启用。上电后默认为01:单光口双MU2:双光口双MU
    {
        if(false == set_smv_SEDSP( CHTYPE_Temp,false,MU2_list))
        {
            showInformationBox("通信异常");
            return;
        }
    }

    if(false == set_smv_writeCh(CHCFGTYPE_Temp))  //单MU
    {
        showInformationBox("通信异常");
        return;
    }

       showInformationBox("映射成功");

}

void MainWidget::slt_SSMV_chl_read()
{
    QStringList MU1_list,MU2_list;
    QString MU_mode,Mu2_cnt,Mu2_MAC,MU2_APPID,MU2_SVID;
    int noEnd=0;
    UINT8   enable;
    UINT8   *addr= (UINT8 *)malloc(30*sizeof(UINT8));
    UINT16   appid=0;
    UINT8   *svid= (UINT8 *)malloc(30*sizeof(UINT8));

    pCHTYPE  pCHTYPE_Temp =NULL;

    if((pCHTYPE_Temp=(pCHTYPE)calloc(1,sizeof(CHTYPE2)))==NULL)
    {
        free(pCHTYPE_Temp);
        pCHTYPE_Temp=NULL;
        return ;
    }

    pCHCFGTYPE  pCHCFGTYPE_Temp =NULL;

    if((pCHCFGTYPE_Temp=(pCHCFGTYPE)calloc(1,sizeof(CHCFGTYPE)))==NULL)
    {
        free(addr);
        addr =NULL;

        free(svid);
        svid =NULL;

        free(pCHCFGTYPE_Temp);
        pCHCFGTYPE_Temp=NULL;

        free(pCHTYPE_Temp);
        pCHTYPE_Temp=NULL;
        return ;
    }


    do{
        if(  theDevice->readCh(pCHCFGTYPE_Temp) == ERR_RIGHT)
        {
            noEnd=0;
        }
        else
        {
            noEnd ++;
            if(noEnd==5)
            {
                free(addr);
                addr =NULL;

                free(svid);
                svid =NULL;

                free(pCHCFGTYPE_Temp);
                pCHCFGTYPE_Temp=NULL;
                free(pCHTYPE_Temp);
                pCHTYPE_Temp=NULL;
                return;
            }
        }
      }  while(noEnd);


            MU1_list <<  QString::number(pCHCFGTYPE_Temp->CHNUM-6);                             //通道数目 双通道参数
            MU1_list <<  QString::number(pCHCFGTYPE_Temp->IMA);
            MU1_list <<  QString::number(pCHCFGTYPE_Temp->IMB );
            MU1_list <<  QString::number(pCHCFGTYPE_Temp->IMC);

            MU1_list <<  QString::number(pCHCFGTYPE_Temp->UA);
            MU1_list <<  QString::number(pCHCFGTYPE_Temp->UB);
            MU1_list <<  QString::number(pCHCFGTYPE_Temp->UC);

        do{
            if(  theDevice->readSEDSP(&enable,addr,&appid,svid,pCHTYPE_Temp) == ERR_RIGHT)                    //double channel
            {
                noEnd=0;
            }
            else
            {
                noEnd ++;
                if(noEnd==5)
                {
                    free(addr);
                    addr =NULL;

                    free(svid);
                    svid =NULL;

                    free(pCHCFGTYPE_Temp);
                    pCHCFGTYPE_Temp=NULL;

                    free(pCHTYPE_Temp);
                    pCHTYPE_Temp=NULL;
                    return;
                }
            }
        }  while(noEnd);

        MU_mode  = QString ::number(enable);
        Mu2_cnt  = QString::number(pCHTYPE_Temp->chnum-6);
        Mu2_MAC  = MAC_DecToHex(QString::fromUtf8((const char *)addr));
        MU2_APPID = QString::number(appid);                          //appid
        MU2_SVID  = QString::fromUtf8((const char *)svid);          //svid

        MU2_list << MU_mode<<Mu2_cnt<<Mu2_MAC<<MU2_APPID<<MU2_SVID;

        emit   sig_SSMV_SCL_chl_readArg( MU1_list ,MU2_list);

        showInformationBox("成功读取");


        free(addr);
        addr =NULL;

        free(svid);
        svid =NULL;

        free(pCHCFGTYPE_Temp);
        pCHCFGTYPE_Temp=NULL;

        free(pCHTYPE_Temp);
        pCHTYPE_Temp=NULL;

}

QString MainWidget::MAC_HexToDec (QString lastMAC)                                   //将地址 ff-ff-ff-ff-ff-ff 转成 255，255，...
{
    QString filter, currentMAC;
    for(int i=0;i<lastMAC.length();i++)                                               //碰到 "-" 时存放
    {
        if((lastMAC.at(i)=='-')||(lastMAC.at(i)==',')||(lastMAC.at(i)=='.'))
        {
            currentMAC=currentMAC+","+QString::number(filter.toInt(0,16));               //16进制转10
            filter="";
        }
        else
        {
          filter=filter+lastMAC.at(i);
        }

    }
    currentMAC.remove(0,1);
    currentMAC=currentMAC+","+QString::number(filter.toUInt(0,16));
    return currentMAC;
}

QString MainWidget::MAC_DecToHex(QString lastMAC)                                      //将地址255，255，... 转成  ff-ff-ff-ff-ff-ff
{
    QString filter, currentMAC;
    for(int i=0;i<lastMAC.length();i++)                                               //碰到 "," 时存放
    {
        if((lastMAC.at(i)=='-')||(lastMAC.at(i)==',')||(lastMAC.at(i)=='.'))
        {
            currentMAC=currentMAC+"-"+QString::number(filter.toInt(0,10),16);         //16进制转10
            filter="";
        }
        else
        {
          filter=filter+lastMAC.at(i);
        }

    }
    currentMAC.remove(0,1);
    currentMAC=currentMAC+"-"+QString::number(filter.toInt(0,10),16);
    return currentMAC;
}

void MainWidget:: slt_SSMV_filter( QStringList strlist)  //APPID MAC 过滤
{
    int noEnd = 0;
    memset(pISABLE_SP_Data, 0 , sizeof(ISABLE_SP));
    pISABLE_SP_Data->DADDR = 1;

    QString getappid="SETAPPID\r\nAPPID;"+strlist.at(0)+"\r\n";    //过滤地址
    if(!transmitsSimply ((UINT8 *)getappid.toLatin1().data()))
    {
       return ;
    }

    QString getmac="SETMAC\r\nMAC;"+MAC_HexToDec(strlist.at(1))+"\r\n";    //过滤地址
   // qDebug()<<strlist.at(1);


     if(strlist.at(1) == "")
     {
         do{
             if(  theDevice->setSP_part(pSPTYPE_Data,pISABLE_SP_Data) == ERR_RIGHT)  //设置过滤只能用这个指令恢复
             {
                 noEnd=0;
             }
             else
             {
                 noEnd ++;
                 if(noEnd==5)
                 {
                     return;
                 }
             }
           }  while(noEnd);
     }
     else
     {
         if(!transmitsSimply ((UINT8 *)getmac.toLatin1().data()))
         {
            return ;
         }
     }
        showInformationBox("设置成功");

}
