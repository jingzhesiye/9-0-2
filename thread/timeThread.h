#ifndef TIMETHREAD_H
#define TIMETHREAD_H
#include <QThread>
#include "QTableWidget"
#include "xl618.h"
#include "QTime"
#include "QMenu"
#include "QAction"
#include "QInternal"
#include "QDebug"

class timeThread : public QThread
{
    Q_OBJECT

public:
    timeThread();
    void  RRF_setArg(const bool, const UINT32 channelTemp,const  UINT32 H1Temp, const UINT32 H2Temp);
    void  Serial_getFD(const int fdSerial);


    INT32  search_maxIntValue( INT32 *,INT32 );
    double  search_maxDoubleValue( double *Temp,INT32 len);

    int     timerNum;
    bool    m_waitStart;
    void    run(int timerNum = 0);
    void    run();
    double   KL_axesY[6][260];
    //double  gwave_Yval_Cur[3][260];
    double   KL_arrayTemp[40];

    UINT32  RSMV_waveall_sampleCnt  ;//采样点数目
    UINT32  RSMV_waveall_chlIndex  ;//索引通道
    UINT32  RSMV_waveall_chlCount  ;//通道数目

    INT32   IntFrame[2000];

    void setTbwFullTest(QTableWidget *tbw)
     {
         m_Tbw_FullTest = tbw;
     }

    void dealFullData(QString elapsedTime, int *targetRow, int *realLen, QTextStream *textStream);    //完整性表格数据填充
    void close_timer(int);

    bool setSP_part(QStringList);
    UINT8 transmitsSimply (UINT8 *data);//串口快速发送

   bool getSP(pSPTYPE);
   bool setSP(pSPTYPE );
   QStringList getRCR();
   QStringList getRVR();
public slots:
    void  stop();
    void slt_battery_timeDone();
protected:

signals:
    void sig_RS_Item_update(QIntList targetRow, QStringList strSerial, QStringList eventType, QStringList strLast, QStringList strCurrent, QStringList elasedTime); //更新表格数据
    void signal_FullTbw_RemoveRows(int start, int end);

    void sig_SSMV_rms_update(pMETYPE) ;

    void sig_battery_update(QString str);
    void sig_ME_update(pMETYPE) ;
    void sig_ES_update(pESTYPE) ;
    void sig_ESTD_update(pESTDTYPE);
    void sig_ENERGY_PUL_update(pPULSEPOW);
    void sig_ENERGY_STD_update(pPULSEPOW);
    void sig_wave_update() ;
    void sig_RSMV_waveall_update();
    void sig_RSMV_phasor_update(pMETYPE) ;

    void sig_RRF_update(pRRFTYPE);
    void sig_RD_update(pRDTYPE);
    void sig_RS_update(pRSTYPE);


    void sig_RFT3_wave_update(float);
    void sig_RMSG_FrameList_update(QStringList );
private slots:
    void slt_SSMV_rms_timeDone();
    void slt_ME_timeDone();
    void slt_RSMV_waveall_timeDone();
    void slt_KL_timeDone();
    void slt_RSMV_phasor_timeDone();
    void slt_RS_timeDone();
    void slt_RRF_timeDone();
    void slt_RD_timeDone();
    void slt_RFT3_timeDone();

    void slt_ES_timeDone();
    void slt_ESTD_timeDone();

    void slt_ENERGY_PUL_timeDone();
    void slt_ENERGY_STD_timeDone();

    void enableItem(int page);

    void set_SSMV_RMS_Arg()
   {
        enableItem(SSMV_RMS);
   }
   void set_ME_Arg()
   {
        enableItem(ME);
   }
   void set_KL_Arg()
   {
        enableItem(KL);
   }

   void set_RSMV_WAVEALL_Arg()
   {
        enableItem(RSMV_WAVEALL);
   }
   void set_RSMV_PHASOR_Arg()
   {
        enableItem(RSMV_PHASOR);
   }
   void set_RS_Arg()
   {
        enableItem(RS);
   }
   void set_RRF_Arg()
   {
        enableItem(RRF);
   }
   void set_RD_Arg()
   {
        enableItem(RD);
   }
   void set_RFT3_timeDone()
   {
        enableItem(RFT3_WAVE);
   }

   void set_ES_Arg()
   {
        enableItem(ES);
   }
   void set_ESTD_Arg()
   {
     enableItem(ESTD);
   }

   void set_ENERGY_PUL_Arg()
   {
        enableItem(ENERGY_PUL);
   }
   void set_ENERGY_STD_Arg()
   {
        enableItem(ENERGY_STD);
   }

   public:
    xl618      *driver_619;

    QTimer     *SSMV_RMS_Timer;
    QTimer     *ME_Timer;
    QTimer     *KL_Timer;
    QTimer     *RSMV_Waveall_Timer;
    QTimer     *RSMV_Phasor_Timer ;

    QTimer     *RRF_Timer ;
    QTimer     *RD_Timer ;
    QTimer     *RFT3_Timer;
    QTimer     *RS_Timer ;

    QTimer     *ENERGY_PUL_Timer;
    QTimer     *ENERGY_STD_Timer;
    QTimer     *ES_Timer;
    QTimer     *ESTD_Timer;
    QTimer     *get_battery_Timer;

    QIntList strUpRow;
    QStringList strUpSerial;
    QStringList strUpEventType;
    QStringList strUpLast;
    QStringList strUpCurrent;
    QStringList strUpElapsedTime;

    int delayCount;                 //延时
    int simpleRate;                 //采样率
    QTableWidget *m_Tbw_FullTest;   //完整性测试表格
    int serialNum;                  //行号
    int page3_3_DRowCount;          //有数据的行   指向下一个装载数据的行
    int page3_3_Time_Elapsed;       //运行的时间
    int lastFraE;                   //上一次的帧尾,初始为3999
    int currentFraS;                //这一次的帧头

    //goose
private:


    bool IsSSMV_RMS;
    bool IsME;
    bool IsKL;
    bool IsRSMV_WAVEALL;
    bool IsRSMV_PHASOR;
    bool IsRS;
    bool IsRRF;
    bool IsRD;
    bool IsRFT3;
    bool IsES;
    bool IsESTD;
    bool IsENERGY_PUL;
    bool IsENERGY_STD;
    UINT32 SMV_harmonic_ChlNum;
    UINT32 SMV_harmonic_H1;
    UINT32 SMV_harmonic_H2;
    bool   SMV_harmonic_mode;

    int runType;

public:
     QMutex     mutexUpdate;
     char       wave_chlNum;     //通道号
     short int  wave_sampleCnt;  //采样点
};
#endif // SYSTHREAD_H
