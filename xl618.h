#ifndef XL618_H
#define XL618_H
#include <stdafx.h>
#include <QMutex>
#include "SerialPort/ManageSerialPort.h"
#include <QThread>

class xl618: public QThread
{
    Q_OBJECT
public:
    xl618();
    ~xl618();//加入Q_OBJECT 需要类的析构函数

    int fdSerial;

    pMETYPE              pMETYPE_Data;

    UINT8 *recvBuf;
    UINT8 *sendBuf;
    INT32 sendBufSize;
    INT32 recvBufSize;
    int dataSize;

    UINT8 sendOther(UINT8 *writeBuf,UINT32 writeSize,UINT8 *readBuf,UINT32 *readSize);                    //串口直接发送
    UINT8 readOneFrame(UINT32 sendToBufSize,char *frameHead,char *errorHead,char *frameTail,int readTime);//解析底层的信息

    UINT8 getRBAT(QString &str);
    UINT8 getRD(pRDTYPE data);                                                                            //读取数据
    UINT8 getRS(pRSTYPE data);

    UINT8 getRRF(pRRFTYPE data);
    UINT8 getES(pESTYPE data);

    UINT8 getESTD(pESTDTYPE data);
    UINT8 getEnergyPul(pPULSEPOW pulse);
    UINT8 getMeterenrgy(pPULSEPOW pulse);
    UINT8 setSM(UINT8 smMode);                                                                            //设置工作模式
    UINT8 getRSM(UINT8 *smMode);                                                                          //读取工作模式
    UINT8 setSP(pSPTYPE data);                                                                            //设置发送数据
    UINT8 setSP_part(pSPTYPE data,pISABLE_SP isAble);
    UINT8 getSP(pSPTYPE data);                                                                            //获取参数
    UINT8 getRCR(pVRCRTYPE CRtype);
    UINT8 getRVR(pVRCRTYPE CRtype);
    UINT8 startPowTest();                                                                                 //电能测试开始
    UINT8 stopPowTest();                                                                                  //电能测试终止
    UINT8 readCh(pCHCFGTYPE ch);                                                                          //通道配置读
    UINT8 writeCh(pCHCFGTYPE ch);                                                                         //通道配置写
    UINT8 setMPE(pMETYPE data,pMEable able);                                                              //设置输入测量值
    UINT8 getME(pMETYPE data);
    UINT8 setSEDSP(UINT8 enable,UINT8 *addr,UINT16 appid,UINT8 *svid,pCHTYPE ch);
    UINT8 readSEDSP(UINT8 *enable,UINT8 *addr,UINT16 *appid,UINT8 *svid,pCHTYPE ch);

    UINT8 getLKL(UINT8 type,pLKLTYPE data);                                                               //整形波读取
    pLKLTYPE newLKLBuf(UINT8 type,UINT16 cnt);
    void  deleteLKLBuf(pLKLTYPE lkl);

    UINT8 getKL(UINT8 type,pRKLTYPE data);  //type:0~5位分别表示通道1~6，位置1表示读取该通道
    pKLTYPE newKLBuf(UINT8 type,UINT16 cnt); //type:0~5位分别表示通道1~6，cnt：采样点数
    void  deleteKLBuf(pKLTYPE lkl);

    UINT8 IEC61850Frame(pIECTYPE data);//OK
    UINT8 getAppid(UINT16 *appid);
    UINT8 getSvID(char* svID);
    UINT8 setHRVirtual(SET_HARMONIC_TYPE *harmonic);//谐波设置
    UINT8 setFramerr(pSETFRAMERR_TYPE data);//丢帧

    UINT8 getHRN(UINT8 channel,pHARMONIC_TYPE data,UINT32 H1,UINT32 H2); //谐波读取
    pHARMONIC_TYPE newHRNBuf(UINT16 cnt) ;
    void deleteHRNBuf(pHARMONIC_TYPE lkl);
    UINT8 muTest(pMUTYPE mu);

    UINT8  getSyn(UINT8 *syn);
    UINT8  setCR(FLOAT32 type);  //设置电流量程
    UINT8  setSGP_part(pGSE_SPTYPE data,pISABLE_GSE_SP isAble);
    UINT8  setUPG(GSE_UPGTYPE data[],int rowCount);
    UINT8  scanGSE(pGSE_SCANTYPE data);
    UINT8  setGSE_RGDATA(pGSE_RGDATATYPE data);
    UINT8  GSEFrame(pGSE_FRAMETYPE data);
    UINT8  RWAVEALL(UINT32 *samnum,UINT32 *chnum,INT32 *data,UINT32 dataSize);

signals:
    void sig_serPort_RecDataToUI(const QByteArray &dataReceived,int intReturn); //将串口数据传到界面
public:
    ManageSerialPort      *MagSerPort;
    //QByteArray             serRecAllBtArray;
    bool                   isToUI;  //串口到界面
    int                    intSerRecReturn;
    bool                   isSerRecAll;
private slots:
    void slt_serPort_RecDataToUI(const QByteArray &,int intReturn);
};

#endif // XL618_H
