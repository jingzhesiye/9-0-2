#include <mainwidget.h>
#include <QTimer>
#include <QDebug>

/******************************************************************************
*dec:行程定时器刷新读取数据
*******************************************************************************/

timeThread::timeThread()
{
    driver_619= new xl618();
    SSMV_RMS_Timer =new QTimer(this);
    connect(SSMV_RMS_Timer, SIGNAL(timeout()), this, SLOT(set_SSMV_RMS_Arg()));     //定时接收数据

    ME_Timer =new QTimer(this);
    connect(ME_Timer, SIGNAL(timeout()), this, SLOT(set_ME_Arg()) );

    KL_Timer =new QTimer(this);
    connect(KL_Timer, SIGNAL(timeout()), this, SLOT(set_KL_Arg()) );

    RSMV_Waveall_Timer =new QTimer(this);
    connect(RSMV_Waveall_Timer, SIGNAL(timeout()), this, SLOT(set_RSMV_WAVEALL_Arg()) );

    RSMV_Phasor_Timer =new QTimer(this);
    connect(RSMV_Phasor_Timer, SIGNAL(timeout()), this, SLOT(set_RSMV_PHASOR_Arg()) );

    RS_Timer =new QTimer(this);
    connect(RS_Timer, SIGNAL(timeout()), this, SLOT(set_RS_Arg()) );

    RRF_Timer =new QTimer(this);
    connect(RRF_Timer, SIGNAL(timeout()), this, SLOT(set_RRF_Arg()) );

    RD_Timer =new QTimer(this);
    connect(RD_Timer, SIGNAL(timeout()), this, SLOT(set_RD_Arg()) );

    RFT3_Timer =new QTimer(this);
    connect(RFT3_Timer, SIGNAL(timeout()), this, SLOT(set_RFT3_timeDone()) );

    ES_Timer =new QTimer(this);
    connect(ES_Timer, SIGNAL(timeout()), this, SLOT(set_ES_Arg()) );

    ESTD_Timer =new QTimer(this);
    connect(ESTD_Timer, SIGNAL(timeout()), this, SLOT(set_ESTD_Arg()) );

    ENERGY_PUL_Timer =new QTimer(this);
    connect(ENERGY_PUL_Timer, SIGNAL(timeout()), this, SLOT(set_ENERGY_PUL_Arg()) );

    ENERGY_STD_Timer =new QTimer(this);
    connect(ENERGY_STD_Timer, SIGNAL(timeout()), this, SLOT(set_ENERGY_STD_Arg()) );

    get_battery_Timer=new QTimer(this);
    connect(get_battery_Timer, SIGNAL(timeout()), this, SLOT(slt_battery_timeDone()) );     //定时接收数据
    get_battery_Timer->setInterval(1*60*1000);//5分钟读一次
    get_battery_Timer->start();

    runType = 0;

    IsSSMV_RMS                = false;
    IsME                = false;
    IsKL               = false;
    IsRSMV_WAVEALL            = false;
    IsRSMV_PHASOR             = false;
    IsRS               = false;
    IsRRF           = false;
    IsRD                      = false;

    IsENERGY_STD              = false;
    IsENERGY_PUL              = false;
    m_waitStart               = false;
    IsRFT3                    = false;
    IsES                 = false;
    IsESTD                = false;
}

void timeThread::Serial_getFD(const int fdSerial)  //每次发送需要知道串口的id
{
    driver_619->fdSerial= fdSerial;
}


/*******************************************************************************************************
*Function:     线程谐波参数设置,收发公用
*Description:  type 模式，channelTemp，第几通道；H1Temp：开始；结束：H2Temp；
*******************************************************************************************************/
void timeThread::RRF_setArg( const bool mode,const UINT32 chlNum,const  UINT32 H1, const UINT32 H2)
{
     SMV_harmonic_mode=mode;
     SMV_harmonic_ChlNum=chlNum;
     SMV_harmonic_H1=H1;
     SMV_harmonic_H2=H2;
}

void timeThread::enableItem(int Item)
{
    switch (Item)
    {
        case SSMV_RMS:                  this->IsSSMV_RMS        = true; break;
        case ME:                  this->IsME        = true; break;
        case KL:                  this->IsKL       = true; break;
        case RSMV_WAVEALL:              this->IsRSMV_WAVEALL           = true; break;
        case RSMV_PHASOR:               this->IsRSMV_PHASOR                     = true; break;
        case RS:                 this->IsRS                       = true; break;
        case RRF:             this->IsRRF                   = true; break;
        case RD:                        this->IsRD              = true; break;
        case RFT3_WAVE:                this->IsRFT3                        = true; break;
        case ES:                   this->IsES             = true; break;
        case ESTD:            this->IsESTD             = true; break;
        case ENERGY_PUL:        this->IsENERGY_PUL     = true; break;
        case ENERGY_STD:            this->IsENERGY_STD = true; break;
        default:break;
    }
}

void timeThread::run()
{
    while (1)
    {

        if (IsSSMV_RMS == true)
        {
            IsSSMV_RMS = false;
            slt_SSMV_rms_timeDone();

        }
        if (IsME == true)
        {
            IsME = false;
            slt_ME_timeDone();
        }
        if (IsKL == true)
        {
            IsKL = false;
            slt_KL_timeDone();

        }
        if (IsRSMV_WAVEALL == true)
        {
            IsRSMV_WAVEALL = false;
            slt_RSMV_waveall_timeDone();

        }
        if (IsRSMV_PHASOR == true)
        {
            IsRSMV_PHASOR = false;
            slt_RSMV_phasor_timeDone();
        }
        if (IsRS == true)
        {
            IsRS = false;
            slt_RS_timeDone();
        }
        if (IsRRF == true)
        {
            IsRRF = false;
            slt_RRF_timeDone();
        }
        if (IsRD == true)
        {
            IsRD = false;
            slt_RD_timeDone();
        }
        if (IsRFT3 == true)
        {
            IsRFT3 = false;
            slt_RFT3_timeDone();
        }
        if (IsES == true)
        {
            IsES = false;
            slt_ES_timeDone();
        }
        if (IsESTD == true)
        {
            IsESTD = false;
            slt_ESTD_timeDone();
        }
        if (IsENERGY_PUL == true)
        {
            IsENERGY_PUL = false;
            slt_ENERGY_PUL_timeDone();
        }
        if (IsENERGY_STD == true)
        {
            IsENERGY_STD = false;
            slt_ENERGY_STD_timeDone();
        }
    }

}

void timeThread::run(int timerNum)//定时器不能放在run（）函数里面
{
    this->timerNum = timerNum;

    switch(timerNum)
    {
        case SSMV_RMS:
            {
                timerNum = 0;
                SSMV_RMS_Timer->setInterval(1500);
                SSMV_RMS_Timer->start();

            }
        break;
        case ME:
            {
                timerNum = 0;
                ME_Timer->setInterval(1500);
                ME_Timer->start();

            }
        break;
        case KL:
            {
                timerNum = 0;
                KL_Timer->setInterval(4000);
                KL_Timer->start();
            }
        break;

        case RSMV_WAVEALL:
            {
                timerNum = 0;
                RSMV_Waveall_Timer->setInterval(3000);
                RSMV_Waveall_Timer->start();
            }
        break;

        case RSMV_PHASOR:
            {
                timerNum = 0;
                RSMV_Phasor_Timer->setInterval(1000);
                RSMV_Phasor_Timer->start();

            }
        break;
        case RS:
            {
                timerNum = 0;
                RS_Timer->setInterval(1000);
                RS_Timer->start();

            }
        break;
        case RRF:
            {
                timerNum = 0;
                RRF_Timer->setInterval(1500);
                RRF_Timer->start();

            }
        break;
        case RD:
            {
                timerNum = 0;
                RD_Timer->setInterval(5000);
                RD_Timer->start();
            }
        break;
        case RFT3_WAVE:
            {
                timerNum = 0;
                RFT3_Timer->setInterval(1000);
                RFT3_Timer->start();

            }
         break;

        case ES:
            {
                timerNum = 0;
                ES_Timer->setInterval(3000);
                ES_Timer->start();

            }
         break;

        case ESTD:
            {
                timerNum = 0;
                ESTD_Timer->setInterval(2000);
                ESTD_Timer->start();

            }
         break;

        case ENERGY_PUL:
            {
                timerNum = 0;
                ENERGY_PUL_Timer->setInterval(1000);
                ENERGY_PUL_Timer->start();
            }
         break;

        case ENERGY_STD:
            {
                timerNum = 0;
                ENERGY_STD_Timer->setInterval(500);
                ENERGY_STD_Timer->start();
            }
         break;
        default:break;
    }

    start();
}

void timeThread::close_timer(int timerNum)
{
   switch(timerNum)
  {
     case SSMV_RMS:
                        SSMV_RMS_Timer->stop();
                        IsSSMV_RMS = false;
                       //
     break;


    case ME:
                        ME_Timer->stop();
                        IsME = false;

    break;

    case KL:
                        KL_Timer->stop();
                        IsKL = false;
     break;

     case RSMV_WAVEALL:
                          RSMV_Waveall_Timer->stop();
                          IsRSMV_WAVEALL = false;
     break;


     case RSMV_PHASOR:

                        RSMV_Phasor_Timer->stop();
                        IsRSMV_PHASOR = false;
     break;

      case RS:
                        RS_Timer->stop();
                        IsRS = false;
                       //
     break;

     case RRF:
                        RRF_Timer->stop();
                        IsRRF= false;
                       //
     break;

     case RD:
                        RD_Timer->stop();
                        IsRD= false;
                       //
     case RFT3_WAVE:
                        RFT3_Timer->stop();
                        IsRFT3 = false;
                       //
      break;

     case ES:
                        ES_Timer->stop();
                        IsES = false;
                       //
      break;

      case ESTD:
                         ESTD_Timer->stop();
                         IsESTD = false;
                        //
       break;

     default:break;
    }
   timerNum = 0;
 }


 void timeThread::stop()
{
    SSMV_RMS_Timer->stop();
    ME_Timer->stop();
    KL_Timer->stop();
    RSMV_Waveall_Timer->stop();
    RSMV_Phasor_Timer->stop();
    RS_Timer->stop();
    RRF_Timer->stop();
    RD_Timer->stop();
    RFT3_Timer->stop();
    ES_Timer->stop();
    ESTD_Timer->stop();
    ENERGY_PUL_Timer->stop();
    ENERGY_STD_Timer->stop();


    IsSSMV_RMS        = false;
    IsME        = false;
    IsKL       = false;
    IsRSMV_PHASOR     = false;
    IsRS       = false;
    IsRRF   = false;
    IsRD = false;
    IsRFT3            = false;
    IsES    = false;
    IsESTD  = false;
    IsENERGY_PUL= false;
    IsENERGY_STD= false;
}



void timeThread::slt_SSMV_rms_timeDone()
{



}


double timeThread:: search_maxDoubleValue( double *Temp,INT32 len)
{
    INT32 i ,j ;
    for ( i =0,j=0;i<len;i++)
    {
        if ( Temp[i] > Temp[j] )
        {
            j=i;
        }
    }
    return Temp[j];
}

INT32 timeThread:: search_maxIntValue( INT32 *Temp,INT32 len)
{
    INT32 i ,j ;

    for ( i =0,j=0;i<len;i++)
    {
        if ( Temp[i] > Temp[j] )
        {
            j=i;
        }
    }
    return Temp[j];
}


void timeThread:: slt_RSMV_waveall_timeDone()
{
#if 0
    memset(IntFrame,0,8000);
   //qDebug()<<QString ::number( RSMV_wave_axesY[0][i]);
    if( (driver_619->RWAVEALL(&RSMV_waveall_sampleCnt,&RSMV_waveall_chlCount,IntFrame,8000) == ERR_RIGHT) )
    {
        for(UINT32 i = 0; i < RSMV_waveall_sampleCnt; i++ )
        {

            KL_axesY[0][i]=IntFrame[i+RSMV_waveall_chlIndex*RSMV_waveall_sampleCnt];
            RSMV_wave_axesY[1][i]=IntFrame[i+(RSMV_waveall_chlIndex+1)*RSMV_waveall_sampleCnt];
            RSMV_wave_axesY[2][i]=IntFrame[i+(RSMV_waveall_chlIndex+2)*RSMV_waveall_sampleCnt];
           // qDebug()<<QString ::number( RSMV_wave_axesY[0][i]);
        }

        RSMV_arrayTemp[0] = search_maxIntValue(&IntFrame[RSMV_waveall_chlIndex*RSMV_waveall_sampleCnt],RSMV_waveall_sampleCnt)*1.414; //查找量程
        RSMV_arrayTemp[1] = search_maxIntValue(&IntFrame[(RSMV_waveall_chlIndex+1)*RSMV_waveall_sampleCnt],RSMV_waveall_sampleCnt)*1.414;
        RSMV_arrayTemp[2] = search_maxIntValue(&IntFrame[(RSMV_waveall_chlIndex+2)*RSMV_waveall_sampleCnt],RSMV_waveall_sampleCnt)*1.414;

        //qDebug()<<"RSMV_waveall_num"<<QString ::number( RSMV_waveall_sampleCnt);
        //qDebug()<<"RSMV_waveall_chlIndex"<<QString ::number( RSMV_waveall_chlIndex);
        emit sig_RSMV_waveall_update();
    }
    #endif
}

void timeThread::slt_RSMV_phasor_timeDone()
{

}

void timeThread::dealFullData(QString elapsedTime, int *targetRow, int *realLen, QTextStream *textStream)    //完整性表格数据填充
{
       QString strSerial;  //行序列号
       QString srtLast;    //上一帧序号
       QString strCurrent; //当前点序号
       QString eventType;  //事件
       strSerial   = QString::number(serialNum);    //行序列号
       srtLast     = QString::number(lastFraE);     //上一帧序号
       strCurrent  = QString::number(currentFraS);  //当前点序号

       if (currentFraS > lastFraE)
       {
           eventType = QString::fromUtf8("丢帧:%1").arg(QString::number(currentFraS - lastFraE - 1));
       }
       else if (currentFraS == lastFraE)
       {
           eventType = QString::fromUtf8("重复");
       }
       else if (currentFraS < lastFraE)
       {
           eventType = QString::fromUtf8("错序");
       }
       *textStream<<tr("%1,%2,%3,%4,%5\r\n").arg(strSerial,eventType,srtLast,strCurrent,elapsedTime);

       *targetRow = *realLen + page3_3_DRowCount;

       strUpRow.append(*targetRow);
       strUpSerial.append(strSerial);
       strUpEventType.append(eventType);
       strUpLast.append(srtLast);
       strUpCurrent.append(strCurrent);
       strUpElapsedTime.append(elapsedTime);

       serialNum++;
       *realLen = *realLen + 1;

}


void timeThread::slt_RFT3_timeDone()
{

}



