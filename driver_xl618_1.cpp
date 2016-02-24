
#include "xl618.h"
#include <stdio.h>
#include <fcntl.h> //O_RDWR
#include <unistd.h>
#include <QDebug>

/******************************************************************************
*dec:与底层通信数据处理,沿用手持618协议
*******************************************************************************/

xl618::xl618()
{
    recvBufSize = 0x1FFFF;                                   //常用
    sendBufSize = 0xFFFF;
    recvBuf = new UINT8[recvBufSize];
    sendBuf = new UINT8[sendBufSize];

    pMETYPE_Data=(pMETYPE)calloc(1,sizeof(METYPE));

    MagSerPort = new ManageSerialPort;
    connect(MagSerPort, SIGNAL(newDataReceived(const QByteArray &,int )), this, SLOT(slt_serPort_RecDataToUI(const QByteArray &,int) ),Qt::DirectConnection);

}

xl618::~xl618()
{
}

//接收线程收到的串口数据
void  xl618::slt_serPort_RecDataToUI(const QByteArray &serRecAllBtArray,int intReturn)
{
     const char *dataTemp=NULL;

      if(isToUI)//判断是否直接显示到串口通信界面上
      {
          emit sig_serPort_RecDataToUI(serRecAllBtArray, intReturn);
          isToUI =false;
          return ;
      }

      intSerRecReturn =  intReturn;

      dataTemp =serRecAllBtArray.data();

      memcpy (recvBuf,(UINT8*)dataTemp,serRecAllBtArray.length());
      isSerRecAll =true;
}


#if 1
UINT8 xl618::readOneFrame(UINT32 sendToBufSize,char *frameHead,char *errorHead,char *frameTail ,int msecond)
{
    frameTail=NULL;
    QByteArray sendBtArray((char*) sendBuf) ;
    int readTimes=0;

    //QByteArray sendBtArray="KL123";//ME";
    memset(recvBuf,0,recvBufSize);
    isSerRecAll =false;
    intSerRecReturn =0;
    MagSerPort->sendData(sendBtArray);
    qDebug()<<"sendBtArray---"<<sendBtArray;
    do
    {
        if( isSerRecAll==false)
        {
            readTimes ++;
        }
        else
        {
            readTimes = 4;
        }

        usleep(msecond*1000);

    }while(readTimes<3);

    //qDebug()<<"readTimes"<<QString::number(readTimes)<<isSerRecAll;
    //qDebug("recvBuf==%s\n",recvBuf);
//    qDebug("intSerRecReturn==%d\n",intSerRecReturn);
   return intSerRecReturn;
}

#endif


UINT8 xl618::sendOther(UINT8 *writeBuf,UINT32 writeSize,UINT8 *readBuf,UINT32 *readSize)
{
    memcpy(sendBuf,writeBuf,writeSize);
    return readOneFrame(writeSize,NULL,NULL,NULL,300);
}


UINT8 xl618::getRS(pRSTYPE data)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_RS CR);
    pSend += strlen(STR_RS CR);
    UINT16 frameSize = pSend - (char*)sendBuf;

    if((retValue = readOneFrame(frameSize,(char*)"RS",NULL,(char*)"RSACK",400)) == ERR_RIGHT)
    {//解析帧

        char *temp;
        temp = strstr((char*)recvBuf,(char*)"STATE;");
        if(temp)
            data->STATE = (UINT8)atof(&temp[sizeof("STATE;")-1]);
#if 1
        temp = strstr(temp,(char*)"CHARGEMODE;");
        if(temp)
            data->CHARGEMODE = (UINT8)atof(&temp[sizeof("CHARGEMODE;")-1]);

        temp = strstr(temp,(char*)"VOLTAGENEED;");
        if(temp)
            data->VOLTAGENEED = (FLOAT32)atof(&temp[sizeof("VOLTAGENEED;")-1]);

        temp = strstr(temp,(char*)"CURRENCENEED;");
        if(temp)
            data->CURRENCENEED = (FLOAT32)atof(&temp[sizeof("CURRENCENEED;")-1]);

        temp = strstr(temp,(char*)"VOLTAGEOUT;");
        if(temp)
            data->VOLTAGEOUT = (FLOAT32)atof(&temp[sizeof("VOLTAGEOUT;")-1]);

        temp = strstr(temp,(char*)"CURRENCEOUT;");
        if(temp)
            data->CURRENCEOUT = (FLOAT32)atof(&temp[sizeof("CURRENCEOUT;")-1]);

        temp = strstr(temp,(char*)"CHARGETIME;");
        if(temp)
            data->CHARGETIME = (FLOAT32)atof(&temp[sizeof("CHARGETIME;")-1]);
#endif

    }
    return retValue;
}

#if 1
UINT8 xl618::getRD(pRDTYPE data)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_RD CR);
    pSend += strlen(STR_RD CR);
    UINT16 frameSize = pSend - (char*)sendBuf;

    if((retValue = readOneFrame(frameSize,(char*)"RD",NULL,(char*)"RSACK",400)) == ERR_RIGHT)
    {//解析帧

        char *temp;
        temp = strstr((char*)recvBuf,(char*)"CURRENCEINMAX;");
        if(temp)
            data->CURRENCEINMAX = (FLOAT32)atof(&temp[sizeof("CURRENCEINMAX;")-1]);

        temp = strstr(temp,(char*)"VOLTAGEINMAX;");
        if(temp)
            data->VOLTAGEINMAX = (FLOAT32)atof(&temp[sizeof("VOLTAGEINMAX;")-1]);

        temp = strstr(temp,(char*)"VOLTAGEBAT;");
        if(temp)
            data->VOLTAGEBAT = (FLOAT32)atof(&temp[sizeof("VOLTAGEBAT;")-1]);

        temp = strstr(temp,(char*)"VOLTAGEOUTMAX;");
        if(temp)
            data->VOLTAGEOUTMAX = (FLOAT32)atof(&temp[sizeof("VOLTAGEOUTMAX;")-1]);

        temp = strstr(temp,(char*)"VOLTAGEOUTMIN;");
        if(temp)
            data->VOLTAGEOUTMIN = (FLOAT32)atof(&temp[sizeof("VOLTAGEOUTMIN;")-1]);

        temp = strstr(temp,(char*)"CURRENCEOUTMAX;");
        if(temp)
            data->CURRENCEOUTMAX = (FLOAT32)atof(&temp[sizeof("CURRENCEOUTMAX;")-1]);

        temp = strstr(temp,(char*)"VOLTAGEMEASURE;");
        if(temp)
            data->VOLTAGEMEASURE = (FLOAT32)atof(&temp[sizeof("VOLTAGEMEASURE;")-1]);

        temp = strstr(temp,(char*)"CURRENCEMEASURE;");
        if(temp)
            data->CURRENCEMEASURE = (FLOAT32)atof(&temp[sizeof("CURRENCEMEASURE;")-1]);

        temp = strstr(temp,(char*)"SOC;");
        if(temp)
            data->SOC = (FLOAT32)atof(&temp[sizeof("SOC;")-1]);

        temp = strstr(temp,(char*)"TIMEREMAIN;");
        if(temp)
            data->TIMEREMAIN = (FLOAT32)atof(&temp[sizeof("TIMEREMAIN;")-1]);

        temp = strstr(temp,(char*)"TIMECHARGE;");
        if(temp)
            data->TIMECHARGE = (FLOAT32)atof(&temp[sizeof("TIMECHARGE;")-1]);

        temp = strstr(temp,(char*)"POWER;");
        if(temp)
            data->POWER = (FLOAT32)atof(&temp[sizeof("POWER;")-1]);

    }
    return retValue;
}
#endif


UINT8 xl618::getRVR(pVRCRTYPE VRtype)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_RVR CR);
    pSend += strlen(STR_RVR CR);


    UINT16 frameSize = pSend - (char*)sendBuf;

    if((retValue = readOneFrame(frameSize,(char*)"RVR",NULL,(char*)"RVRACK",300)) == ERR_RIGHT)
    {//解析帧
//        unpackRVR(VRtype);
        char *temp;
        temp = strstr((char*)recvBuf,(char*)"L1;");
        if(temp)
            VRtype->L1 = (FLOAT32)atof(&temp[3]);

        temp = strstr(temp,(char*)"L2;");
        if(temp)
            VRtype->L2 = (FLOAT32)atof(&temp[3]);

        temp = strstr(temp,(char*)"L3;");
        if(temp)
            VRtype->L3 = (FLOAT32)atof(&temp[3]);
    }

    return retValue;
}

UINT8 xl618::getRCR(pVRCRTYPE CRtype)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_RCR CR);
    pSend += strlen(STR_RCR CR);

    UINT16 frameSize = pSend - (char*)sendBuf;

    if((retValue = readOneFrame(frameSize,(char*)"RCR",NULL,(char*)"RCRACK",300)) == ERR_RIGHT)
    {//解析帧
        //unpackRCR(CRtype);
        char *temp;
        temp = strstr((char*)recvBuf,(char*)"L1;");
        if(temp)
            CRtype->L1 = (FLOAT32)atof(&temp[3]);

        temp = strstr(temp,(char*)"L2;");
        if(temp)
            CRtype->L2 = (FLOAT32)atof(&temp[3]);

        temp = strstr(temp,(char*)"L3;");
        if(temp)
            CRtype->L3 = (FLOAT32)atof(&temp[3]);
    }

    return retValue;
}


UINT8 xl618::getES(pESTYPE data)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_ES CR);
    pSend += strlen(STR_ES CR);
    char *temp;

    UINT16 frameSize = pSend - (char*)sendBuf;

    if((retValue = readOneFrame(frameSize,(char*)"ES",NULL,(char*)"ESACK",500)) == ERR_RIGHT)
    {//解析帧
        temp = strstr((char *)recvBuf,"PE;");
        if(temp)
            data->PE = (FLOAT32)atof(&temp[sizeof("PE;")-1]);

        temp = strstr((char *)recvBuf,"TE;");
        if(temp)
            data->TE = atof(&temp[sizeof("TE;")-1]);
    }
    return retValue;
}

UINT8 xl618::getESTD(pESTDTYPE data)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;

    if(data)
    {
        strcpy(pSend,STR_ESTD CR);
        pSend += strlen(STR_ESTD CR);
        char *temp;

        UINT16 frameSize = pSend - (char*)sendBuf;

        if((retValue = readOneFrame(frameSize,(char*)"ESTD",NULL,(char*)"ESTDACK",500)) == ERR_RIGHT)
        {//解析帧
            temp = strstr((char*)recvBuf,"S;");
            if(temp)
                data->s = (FLOAT32)atof(&temp[2]);
            temp = strstr((char*)recvBuf,"VALID;");
            if(temp)
                data->valid = atoi(&temp[6]);
            temp = (char*)&recvBuf[6];//"ESTD"CR
        }

    }else
        retValue = ERR_BUFFER;
    return retValue;
}
UINT8 xl618::setSM(UINT8 smMode)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_SM CR);
    pSend += strlen(STR_SM CR);
    char *temp=NULL;

switch(smMode)
{
    case PAR_PRICISIONTRANSFER:
        temp = (char*)STR_PRICISIONTRANSFER;
    break;
    case PAR_VIRTUALLOAD:
        temp = (char*)STR_VIRTUALLOAD;
    break;
    case PAR_ACTUALLOAD:
        temp = (char*)STR_ACTUALLOAD;
    break;
    case PAR_MULTIMETER:
        temp = (char*)STR_MULTIMETER;
    break;
    case PAR_DIGITALTRANSFORMERS:
        temp = (char*)STR_DIGITALTRANSFORMERS;
    break;
    case PAR_SMALLSIGNALTRANSFORMERS:
        temp = (char*)STR_SMALLSIGNALTRANSFORMERS;
    break;
    case PAR_DIGITALTRANSFORMERSTRANSFER:
        temp = (char*)STR_DIGITALTRANSFORMERSTRANSFER;
    break;
    case PAR_VIRTUALTEST:
        temp = (char*)STR_VIRTUALTEST;
    break;
    case PAR_NOSYNTRAN:
        temp = (char*)STR_NOSYNTRAN;
    break;
    case PAR_COLLECTOR:
        temp = (char*)STR_COLLECTOR;
    break;
    case PAR_DIGITALTRANS:
        temp = (char*)STR_DIGITALTRANS;
    break;
    case PAR_BAOHUNOSYNTRAN:
        temp = (char*)STR_BAOHUNOSYNTRAN;
    break;
    case PAR_FT3TEST:
        temp = (char*)STR_FT3TEST;
    break;
    case PAR_MUTEST:
        temp = (char*)STR_MUTEST;
    break;
    case PAR_TRADITIONAL:
        temp = (char*)STR_TRADITIONAL;
    break;
    default:
    break;
    }

    strcpy(pSend,temp);
    pSend += strlen(temp);
    strcpy(pSend,CR);
    pSend += strlen(CR);

    UINT16 frameSize = pSend - (char*)sendBuf;
    retValue = readOneFrame(frameSize,(char*)"SM",NULL,(char*)"SMACK",1);

    return retValue;
}


UINT8 xl618::getEnergyPul(pPULSEPOW pulse)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_GETENERGYPUL CR);
    pSend += strlen(STR_GETENERGYPUL CR);

    UINT16 frameSize = pSend - (char*)sendBuf;
    if((retValue = readOneFrame(frameSize,(char*)"GETENERGYPUL",NULL,(char*)"GETENERGYPULACK",300)) == ERR_RIGHT)
    {//解析帧
        char *temp = 0;

        temp = strstr((char*)recvBuf,"WP;");
        if(temp)
            pulse->WP = atof(&temp[strlen("WP;")]);

        temp = strstr((char*)recvBuf,"WQ;");
        if(temp)
            pulse->WQ = atof(&temp[strlen("WQ;")]);

        temp = strstr((char*)recvBuf,"NP;");
        if(temp)
            pulse->NP = (UINT32)atoi(&temp[strlen("NP;")]);

        temp = strstr((char*)recvBuf,"NQ;");
        if(temp)
            pulse->NQ = (UINT32)atoi(&temp[strlen("NQ;")]);

        temp = strstr((char*)recvBuf,"P;");
        if(temp)
            pulse->P = atof(&temp[strlen("P;")]);

        temp = strstr((char*)recvBuf,"Q;");
        if(temp)
            pulse->Q = atof(&temp[strlen("Q;")]);
    }
    return retValue;
}
UINT8 xl618::getMeterenrgy(pPULSEPOW pulse)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_GETMETERENERGY CR);
    pSend += strlen(STR_GETMETERENERGY CR);

    UINT16 frameSize = pSend - (char*)sendBuf;

    if((retValue = readOneFrame(frameSize,(char*)"GETMETERENERGY",NULL,(char*)"GETMETERENERGYACK",300)) == ERR_RIGHT)
    {//解析帧
        char *temp = 0;

        temp = strstr((char*)recvBuf,"WP;");
        if(temp)
            pulse->WP = atof(&temp[strlen("WP;")]);

        temp = strstr((char*)recvBuf,"WQ;");
        if(temp)
            pulse->WQ = atof(&temp[strlen("WQ;")]);

        temp = strstr((char*)recvBuf,"NP;");
        if(temp)
            pulse->NP = (UINT32)atoi(&temp[strlen("NP;")]);

        temp = strstr((char*)recvBuf,"NQ;");
        if(temp)
            pulse->NQ = (UINT32)atoi(&temp[strlen("NQ;")]);

        temp = strstr((char*)recvBuf,"P;");
        if(temp)
            pulse->P = atof(&temp[strlen("P;")]);

        temp = strstr((char*)recvBuf,"Q;");
        if(temp)
            pulse->Q = atof(&temp[strlen("Q;")]);
    }
    return retValue;
}
UINT8 xl618::getRSM(UINT8 *smMode)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_RSM CR);
    pSend += strlen(STR_RSM CR);
    char *temp;

    UINT16 frameSize = pSend - (char*)sendBuf;
    if((retValue = readOneFrame(frameSize,(char*)"RSM",NULL,(char*)"RSMACK",0)) == ERR_RIGHT)
    {
        temp = (char*)&recvBuf[5]; //RSM CR
        if(memcmp(STR_PRICISIONTRANSFER,temp,strlen(STR_PRICISIONTRANSFER)) == 0)
        {
                *smMode = PAR_PRICISIONTRANSFER;
        }else if(memcmp(STR_VIRTUALLOAD,temp,strlen(STR_VIRTUALLOAD)) == 0)
        {
                *smMode = PAR_VIRTUALLOAD;
        }else if(memcmp(STR_ACTUALLOAD,temp,strlen(STR_ACTUALLOAD)) == 0)
        {
                *smMode = PAR_ACTUALLOAD;
        }else if(memcmp(STR_MULTIMETER,temp,strlen(STR_MULTIMETER)) == 0)
        {
                *smMode = PAR_MULTIMETER;
        }else if(memcmp(STR_DIGITALTRANSFORMERS,temp,strlen(STR_DIGITALTRANSFORMERS)) == 0)
        {
                *smMode = PAR_DIGITALTRANSFORMERS;
        }else if(memcmp(STR_SMALLSIGNALTRANSFORMERS,temp,strlen(STR_SMALLSIGNALTRANSFORMERS)) == 0)
        {
                *smMode = PAR_SMALLSIGNALTRANSFORMERS;
        }else if(memcmp(STR_DIGITALTRANSFORMERSTRANSFER,temp,strlen(STR_DIGITALTRANSFORMERSTRANSFER)) == 0)
        {
                *smMode = PAR_DIGITALTRANSFORMERSTRANSFER;
        }else if(memcmp(STR_VIRTUALTEST,temp,strlen(STR_VIRTUALTEST)) == 0)
        {
                *smMode = PAR_VIRTUALTEST;
        }else if(memcmp(STR_NOSYNTRAN,temp,strlen(STR_NOSYNTRAN)) == 0)
        {
                *smMode = PAR_NOSYNTRAN;
        }else if(memcmp(STR_COLLECTOR,temp,strlen(STR_COLLECTOR)) == 0)
        {
                *smMode = PAR_COLLECTOR;
        }else if(memcmp(STR_MUTEST,temp,strlen(STR_MUTEST)) == 0)
        {
                *smMode = PAR_MUTEST;
        }else if(memcmp(STR_TRADITIONAL,temp,strlen(STR_TRADITIONAL)) == 0)
        {
                *smMode = PAR_TRADITIONAL;
        }else
        {
                retValue = ERR_PARA;
        }

    }

    return retValue;
}

UINT8 xl618::setSP(pSPTYPE data)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_SP CR);
    pSend += strlen(STR_SP CR);
        if(data)
        {
                pSPTYPE p = data;
                pSend += sprintf(pSend,"SAMNUM;%d"CR,p->SAMNUM);
                pSend += sprintf(pSend,"DADDR;%d,%d,%d,%d,%d,%d"CR,p->DADDR[0],p->DADDR[1],p->DADDR[2],p->DADDR[3],p->DADDR[4],p->DADDR[5]);
                if(p->PRODUCT == 1)
                        pSend += sprintf(pSend,"PRODUCT;%s"CR,"XINGNING");
                else if(p->PRODUCT == 2)
                        pSend += sprintf(pSend,"PRODUCT;%s"CR,"XUJI");
                else
                        pSend += sprintf(pSend,"PRODUCT;%s"CR,"WEISHENG");

                pSend += sprintf(pSend,"ASDUNUM;%d"CR,p->ASDUNUM);
                pSend += sprintf(pSend,"RATEDDELAY;%d"CR,p->RATEDDELAY);
                pSend += sprintf(pSend,"ANALOGRATE_V;%f"CR,p->ANALOGRATE_V);
                pSend += sprintf(pSend,"ANALOGRATE_I;%f"CR,p->ANALOGRATE_I);
                pSend += sprintf(pSend,"VOLTAGERANGE;%f"CR,p->VOLTAGERANGE);
                pSend += sprintf(pSend,"CURRENTRANGE;%f"CR,p->CURRENTRANGE);
                pSend += sprintf(pSend,"NETPORT;%d"CR,p->NETPORT);
                pSend += sprintf(pSend,"NETTYPE;%d"CR,p->NETTYPE);
                pSend += sprintf(pSend,"METERCONST;%f"CR,p->METERCONST);
                pSend += sprintf(pSend,"CHECKNUM;%d"CR,p->CHECKNUM);
                pSend += sprintf(pSend,"STYPE;%d"CR,p->STYPE);
                pSend += sprintf(pSend,"SNUM;%d"CR,p->SNUM);
                pSend += sprintf(pSend,"CONST;%f"CR,p->AMMETER_CONST);
                pSend += sprintf(pSend,"CHECKTYPE;%d"CR,p->CHECKTYPE);
                pSend += sprintf(pSend,"KB;%f"CR,p->KB);
                pSend += sprintf(pSend,"KX;%f"CR,p->KX);
                pSend += sprintf(pSend,"TRATED;%f"CR,p->TRATED);
                pSend += sprintf(pSend,"TIMETRIGEDGE;%d"CR,p->TIMETRIGEDGE);
                pSend += sprintf(pSend,"TRANMODETYPE;%d"CR,p->TRANMODETYPE);
                pSend += sprintf(pSend,"SYNTYPE;%d"CR,p->SYNTYPE);
                pSend += sprintf(pSend,"TRANSFORMERCH;%d"CR,p->TRANSFORMERCH);
                pSend += sprintf(pSend,"MESUREPROTECT;%d"CR,p->MESUREPROTECT);
                pSend += sprintf(pSend,"2NVOLTAGERANGE;%f"CR,p->VOLTAGERANGE_2N);
                pSend += sprintf(pSend,"2NCURRENTRANGE;%f"CR,p->CURRENTRANGE_2N);
                pSend += sprintf(pSend,"CURRENTINPUT;%d"CR,p->CURRENTINPUT);
                pSend += sprintf(pSend,"IEC61850;%d"CR,p->IEC61850);
                pSend += sprintf(pSend,"IRIG_B;%d"CR,p->IRIG_B);
                pSend += sprintf(pSend,"TIMEDELAY;%d"CR,p->TIMEDELAY);
                pSend += sprintf(pSend,"COLLORNOSYN;%d"CR,p->COLLORNOSYN);
                pSend += sprintf(pSend,"FT3OUT;%d"CR,p->FT3OUT);
                pSend += sprintf(pSend,"FT3CALDELAY;%d"CR,p->FT3CALDELAY);
                pSend += sprintf(pSend,"COMPOSITEERR;%d"CR,p->COMPOSITEERR);
                pSend += sprintf(pSend,"IBSEL;%d"CR,p->IBSEL);
                pSend += sprintf(pSend,"IXSELSMALL;%d"CR,p->IXSELSMALL);
                pSend += sprintf(pSend,"TRANSIENT;%d"CR,p->TRANSIENT);
                pSend += sprintf(pSend,"VLANTYPE;0x%04x"CR,p->VLANTYPE);
                pSend += sprintf(pSend,"VLAN;0x%04x"CR,p->VLAN);

                UINT16 frameSize = pSend - (char*)sendBuf;
                retValue = readOneFrame(frameSize,(char*)"SP",NULL,(char*)"SPACK",0);
        }

        return retValue;
}

UINT8 xl618::getSP(pSPTYPE data)
{

    UINT8 retValue = ERR_UNIVERSAL;
    memset(sendBuf,0,sendBufSize);
    char *pSend = (char*)sendBuf;                   //指向同个地址
    strcpy(pSend,STR_RP CR);
    pSend += strlen(STR_RP CR);
    UINT16 frameSize = pSend - (char*)sendBuf;
    char product[10];
    pSPTYPE p = data;
    char *temp;

    if((retValue = readOneFrame(frameSize,(char*)"RP",NULL,(char*)"RPACK",500)) == ERR_RIGHT)
    {//atoi把字符串转换成整型数。
        temp = strstr((char*)recvBuf,"SAMNUM;");
        if(temp)
            data->SAMNUM = atoi(&temp[strlen("SAMNUM;")]);
        temp = strstr((char*)recvBuf,"DADDR;");
        if(temp)
        {
            data->DADDR[0] = atoi(&temp[strlen("DADDR;")]);
            temp = strstr(temp,",");
            if(temp)
                data->DADDR[1] = atoi(&temp[1]);
            temp ++;
            temp = strstr(temp,",");
            if(temp)
                data->DADDR[2] = atoi(&temp[1]);
            temp ++;
            temp = strstr(temp,",");
            if(temp)
                data->DADDR[3] = atoi(&temp[1]);
            temp ++;
            temp = strstr(temp,",");
            if(temp)
                data->DADDR[4] = atoi(&temp[1]);
            temp ++;
            temp = strstr(temp,",");
            if(temp)
                data->DADDR[5] = atoi(&temp[1]);
        }
            temp = strstr((char*)recvBuf,"PRODUCT;");
        if(temp)
        {
            data->PRODUCT = sscanf(&temp[strlen("PRODUCT;")],"%10s",product);
            if(strcmp(product,"XINGNING") == 0)
                    p->PRODUCT = 1;
            else if(strcmp(product,"XUJI") == 0)
                    p->PRODUCT = 2;
            else
                    p->PRODUCT = 0;
        }
        temp = strstr((char*)recvBuf,"ASDUNUM;");
        if(temp)
            data->ASDUNUM = atoi(&temp[strlen("ASDUNUM;")]);
        temp = strstr((char*)recvBuf,"RATEDDELAY;");
        if(temp)
            data->RATEDDELAY = atoi(&temp[strlen("RATEDDELAY;")]);
        temp = strstr((char*)recvBuf,"ANALOGRATE_V;");
        if(temp)
            data->ANALOGRATE_V = (FLOAT32)atof(&temp[strlen("ANALOGRATE_V;")]);
        temp = strstr((char*)recvBuf,"ANALOGRATE_I;");
        if(temp)
            data->ANALOGRATE_I = (FLOAT32)atof(&temp[strlen("ANALOGRATE_I;")]);
        temp = strstr((char*)recvBuf,"VOLTAGERANGE;");
        if(temp)
            data->VOLTAGERANGE = (FLOAT32)atof(&temp[strlen("VOLTAGERANGE;")]);
        temp = strstr((char*)recvBuf,"CURRENTRANGE;");

        if(temp)
            data->CURRENTRANGE = (FLOAT32)atof(&temp[strlen("CURRENTRANGE;")]);
        temp = strstr((char*)recvBuf,"NETPORT;");
        if(temp)
            data->NETPORT = atoi(&temp[strlen("NETPORT;")]);
        temp = strstr((char*)recvBuf,"NETTYPE;");
        if(temp)
            data->NETTYPE = atoi(&temp[strlen("NETTYPE;")]);
        temp = strstr((char*)recvBuf,"METERCONST;");
        if(temp)
            data->METERCONST = (FLOAT32)atof(&temp[strlen("METERCONST;")]);
        temp = strstr((char*)recvBuf,"CHECKNUM;");
        if(temp)
            data->CHECKNUM = atoi(&temp[strlen("CHECKNUM;")]);
        temp = strstr((char*)recvBuf,"STYPE;");
        if(temp)
            data->STYPE = atoi(&temp[strlen("STYPE;")]);
        temp = strstr((char*)recvBuf,"SNUM;");
        if(temp)
            data->SNUM = atoi(&temp[strlen("SNUM;")]);
        temp = strstr((char*)recvBuf,"\nCONST;");
        if(temp)
            data->AMMETER_CONST = (FLOAT32)atof(&temp[strlen("\nCONST;")]);
        temp = strstr((char*)recvBuf,"CHECKTYPE;");
        if(temp)
            data->CHECKTYPE = atoi(&temp[strlen("CHECKTYPE;")]);
        temp = strstr((char*)recvBuf,"KB;");
        if(temp)
            data->KB = (FLOAT32)atof(&temp[strlen("KB;")]);
        temp = strstr((char*)recvBuf,"KX;");
        if(temp)
            data->KX = (FLOAT32)atof(&temp[strlen("KX;")]);
        temp = strstr((char*)recvBuf,"TRATED;");
        if(temp)
            data->TRATED = (FLOAT32)atof(&temp[strlen("TRATED;")]);
        temp = strstr((char*)recvBuf,"TIMETRIGEDGE;");
        if(temp)
            data->TIMETRIGEDGE = atoi(&temp[strlen("TIMETRIGEDGE;")]);
        temp = strstr((char*)recvBuf,"TRANMODETYPE;");
        if(temp)
            data->TRANMODETYPE = atoi(&temp[strlen("TRANMODETYPE;")]);
        temp = strstr((char*)recvBuf,"SYNTYPE;");
        if(temp)
            data->SYNTYPE = atoi(&temp[strlen("SYNTYPE;")]);
        temp = strstr((char*)recvBuf,"TRANSFORMERCH;");
        if(temp)
            data->TRANSFORMERCH = atoi(&temp[strlen("TRANSFORMERCH;")]);
        temp = strstr((char*)recvBuf,"MESUREPROTECT;");
        if(temp)
            data->MESUREPROTECT = atoi(&temp[strlen("MESUREPROTECT;")]);
        temp = strstr((char*)recvBuf,"2NVOLTAGERANGE;");
        if(temp)
            data->VOLTAGERANGE_2N = (FLOAT32)atof(&temp[strlen("2NVOLTAGERANGE;")]);
        temp = strstr((char*)recvBuf,"2NCURRENTRANGE;");
        if(temp)
           data->CURRENTRANGE_2N = (FLOAT32)atof(&temp[strlen("2NCURRENTRANGE;")]);
        temp = strstr((char*)recvBuf,"CURRENTINPUT;");
        if(temp)
           data->CURRENTINPUT = atoi(&temp[strlen("CURRENTINPUT;")]);
        temp = strstr((char*)recvBuf,"IEC61850;");
        if(temp)
            data->IEC61850 = atoi(&temp[strlen("IEC61850;")]);
        temp = strstr((char*)recvBuf,"IRIG_B;");
        if(temp)
            data->IRIG_B = atoi(&temp[strlen("IRIG_B;")]);
        temp = strstr((char*)recvBuf,"TIMEDELAY;");
        if(temp)
            data->TIMEDELAY = atoi(&temp[strlen("TIMEDELAY;")]);
        temp = strstr((char*)recvBuf,"COLLORNOSYN;");
        if(temp)
            data->COLLORNOSYN = atoi(&temp[strlen("COLLORNOSYN;")]);

        temp = strstr((char*)recvBuf,"FT3OUT;");
        if(temp)
            data->FT3OUT = atoi(&temp[strlen("FT3OUT;")]);

        temp = strstr((char*)recvBuf,"FT3CALDELAY;");/////////////////////////////////////
       if(temp)
            data->FT3CALDELAY = atoi(&temp[strlen("FT3CALDELAY;")]);

#if 1
        temp = strstr((char*)recvBuf,"COMPOSITEERR;");

        if(temp)
            data->COMPOSITEERR = atoi(&temp[strlen("COMPOSITEERR;")]);

        temp = strstr((char*)recvBuf,"IBSEL;");
        if(temp)
            data->IBSEL = atoi(&temp[strlen("IBSEL;")]);
        temp = strstr((char*)recvBuf,"IXSELSMALL;");
        if(temp)
            data->IXSELSMALL = atoi(&temp[strlen("IXSELSMALL;")]);
        temp = strstr((char*)recvBuf,"TRANSIENT;");
        if(temp)
            data->TRANSIENT = atoi(&temp[strlen("TRANSIENT;")]);
        temp = strstr((char*)recvBuf,"VLANTYPE;");
        if(temp)
        {
            //sscanf(&temp[strlen("VLANTYPE;")],"%d",&(data->VLANTYPE));
            data->VLANTYPE = (UINT16)(atof(&temp[strlen("VLANTYPE;")]) +  0.5);
        }
        temp = strstr((char*)recvBuf,"VLAN;");
        if(temp)
        {
            //sscanf(&temp[strlen("VLAN;")],"%d",&(data->VLAN));
            data->VLAN = (UINT16)(atof(&temp[strlen("VLAN;")]) +  0.5);
        }
 #endif
     }

        return retValue;
}

UINT8 xl618::setSP_part(pSPTYPE data,pISABLE_SP isAble)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_SP CR);
    pSend += strlen(STR_SP CR);
    pSPTYPE p = data;
    if(isAble->SAMNUM)
            pSend += sprintf(pSend,"SAMNUM;%d"CR,p->SAMNUM);
    if(isAble->DADDR)
            pSend += sprintf(pSend,"DADDR;%d,%d,%d,%d,%d,%d"CR,p->DADDR[0],p->DADDR[1],p->DADDR[2],p->DADDR[3],p->DADDR[4],p->DADDR[5]);
    if(isAble->PRODUCT)
    {
            if(p->PRODUCT == 1)
                    pSend += sprintf(pSend,"PRODUCT;%s"CR,"XINGNING");
            else if(p->PRODUCT == 2)
                    pSend += sprintf(pSend,"PRODUCT;%s"CR,"XUJI");
            else
                    pSend += sprintf(pSend,"PRODUCT;%s"CR,"WEISHENG");
    }
    if(isAble->ASDUNUM)
            pSend += sprintf(pSend,"ASDUNUM;%d"CR,p->ASDUNUM);
    if(isAble->RATEDDELAY)
            pSend += sprintf(pSend,"RATEDDELAY;%d"CR,p->RATEDDELAY);
    if(isAble->ANALOGRATE_V)
            pSend += sprintf(pSend,"ANALOGRATE_V;%f"CR,p->ANALOGRATE_V);
    if(isAble->ANALOGRATE_I)
            pSend += sprintf(pSend,"ANALOGRATE_I;%f"CR,p->ANALOGRATE_I);
    if(isAble->VOLTAGERANGE)
            pSend += sprintf(pSend,"VOLTAGERANGE;%f"CR,p->VOLTAGERANGE);
    if(isAble->CURRENTRANGE)
            pSend += sprintf(pSend,"CURRENTRANGE;%f"CR,p->CURRENTRANGE);
    if(isAble->NETPORT)
            pSend += sprintf(pSend,"NETPORT;%d"CR,p->NETPORT);
    if(isAble->NETTYPE)
            pSend += sprintf(pSend,"NETTYPE;%d"CR,p->NETTYPE);
    if(isAble->METERCONST)
            pSend += sprintf(pSend,"METERCONST;%f"CR,p->METERCONST);
    if(isAble->CHECKNUM)
            pSend += sprintf(pSend,"CHECKNUM;%d"CR,p->CHECKNUM);
    if(isAble->STYPE)
            pSend += sprintf(pSend,"STYPE;%d"CR,p->STYPE);
    if(isAble->SNUM)
            pSend += sprintf(pSend,"SNUM;%d"CR,p->SNUM);
    if(isAble->AMMETER_CONST)
            pSend += sprintf(pSend,"CONST;%f"CR,p->AMMETER_CONST);
    if(isAble->CHECKTYPE)
            pSend += sprintf(pSend,"CHECKTYPE;%d"CR,p->CHECKTYPE);
    if(isAble->KB)
            pSend += sprintf(pSend,"KB;%f"CR,p->KB);
    if(isAble->KX)
            pSend += sprintf(pSend,"KX;%f"CR,p->KX);
    if(isAble->TRATED)
            pSend += sprintf(pSend,"TRATED;%f"CR,p->TRATED);
    if(isAble->TIMETRIGEDGE)
            pSend += sprintf(pSend,"TIMETRIGEDGE;%d"CR,p->TIMETRIGEDGE);
    if(isAble->TRANMODETYPE)
            pSend += sprintf(pSend,"TRANMODETYPE;%d"CR,p->TRANMODETYPE);
    if(isAble->SYNTYPE)
            pSend += sprintf(pSend,"SYNTYPE;%d"CR,p->SYNTYPE);
    if(isAble->TRANSFORMERCH)
            pSend += sprintf(pSend,"TRANSFORMERCH;%d"CR,p->TRANSFORMERCH);
    if(isAble->MESUREPROTECT)
            pSend += sprintf(pSend,"MESUREPROTECT;%d"CR,p->MESUREPROTECT);
    if(isAble->VOLTAGERANGE_2N)
            pSend += sprintf(pSend,"2NVOLTAGERANGE;%f"CR,p->VOLTAGERANGE_2N);
    if(isAble->CURRENTRANGE_2N)
            pSend += sprintf(pSend,"2NCURRENTRANGE;%f"CR,p->CURRENTRANGE_2N);
    if(isAble->CURRENTINPUT)
            pSend += sprintf(pSend,"CURRENTINPUT;%d"CR,p->CURRENTINPUT);
    if(isAble->IEC61850)
            pSend += sprintf(pSend,"IEC61850;%d"CR,p->IEC61850);
    if(isAble->IRIG_B)
            pSend += sprintf(pSend,"IRIG_B;%d"CR,p->IRIG_B);
    if(isAble->TIMEDELAY)
            pSend += sprintf(pSend,"TIMEDELAY;%d"CR,p->TIMEDELAY);
    if(isAble->COLLORNOSYN)
            pSend += sprintf(pSend,"COLLORNOSYN;%d"CR,p->COLLORNOSYN);
    if(isAble->FT3OUT)
    {
            pSend += sprintf(pSend,"FT3OUT;%d"CR,p->FT3OUT);
    }


    if(isAble->FT3CALDELAY)
            pSend += sprintf(pSend,"FT3CALDELAY;%d"CR,p->FT3CALDELAY);
    if(isAble->COMPOSITEERR)
            pSend += sprintf(pSend,"COMPOSITEERR;%d"CR,p->COMPOSITEERR);
    if(isAble->IBSEL)
            pSend += sprintf(pSend,"IBSEL;%d"CR,p->IBSEL);
    if(isAble->IXSELSMALL)
            pSend += sprintf(pSend,"IXSELSMALL;%d"CR,p->IXSELSMALL);
    if(isAble->TRANSIENT)
            pSend += sprintf(pSend,"TRANSIENT;%d"CR,p->TRANSIENT);
    if(isAble->VLANTYPE)
            pSend += sprintf(pSend,"VLANTYPE;0x%04x"CR,p->VLANTYPE);
    if(isAble->VLAN)
            pSend += sprintf(pSend,"VLAN;0x%04x"CR,p->VLAN);

    UINT16 frameSize = pSend - (char*)sendBuf;
    //qDebug("sendBuf==%s\n",sendBuf);
    //qDebug("frameSize==%d\n",frameSize);
    retValue = readOneFrame(frameSize,(char*)"SP",NULL,(char*)"SPACK",500);
    //qDebug("setSP_part.retValue==%d\n",retValue);

    return retValue;
}

UINT8 xl618::startPowTest()
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_EB CR);
    pSend += strlen(STR_EB CR);
    UINT16 frameSize = pSend - (char*)sendBuf;
    retValue = readOneFrame(frameSize,(char*)"EB",NULL,(char*)"EBACK",0);

    return retValue;
}

UINT8 xl618::stopPowTest()
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_EE CR);
    pSend += strlen(STR_EE CR);
    UINT16 frameSize = pSend - (char*)sendBuf;
    retValue = readOneFrame(frameSize,(char*)"EE",NULL,(char*)"EEACK",0);

    return retValue;
}

UINT8 xl618::readCh(pCHCFGTYPE ch)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;

    pSend += sprintf(pSend,STR_RCHCFG CR);

    UINT16 frameSize = pSend - (char*)sendBuf;

        if((retValue = readOneFrame(frameSize,(char*)"RCHCFG",NULL,(char*)"RCHCFGACK",0)) == ERR_RIGHT)
        {
                char* temp;
                temp = strstr((char*)recvBuf,"CHNUM;");
                if(temp)
                        ch->CHNUM = atoi((char*)&temp[strlen("CHNUM;")]);

                temp = strstr(temp,"IA;");
                if(temp)
                        ch->IA = atoi((char*)&temp[strlen("IA;")]);

                temp = strstr(temp,"IB;");
                if(temp)
                        ch->IB = atoi((char*)&temp[strlen("IB;")]);

                temp = strstr(temp,"IC;");
                if(temp)
                        ch->IC = atoi((char*)&temp[strlen("IC;")]);

                temp = strstr(temp,"I0;");
                if(temp)
                        ch->I0 = atoi((char*)&temp[strlen("I0;")]);

                temp = strstr(temp,"IMA;");
                if(temp)
                        ch->IMA = atoi((char*)&temp[strlen("IMA;")]);

                temp = strstr(temp,"IMB;");
                if(temp)
                        ch->IMB = atoi((char*)&temp[strlen("IMB;")]);

                temp = strstr(temp,"IMC;");
                if(temp)
                        ch->IMC = atoi((char*)&temp[strlen("IMC;")]);

                temp = strstr(temp,"UA;");
                if(temp)
                        ch->UA = atoi((char*)&temp[strlen("UA;")]);

                temp = strstr(temp,"UB;");
                if(temp)
                        ch->UB = atoi((char*)&temp[strlen("UB;")]);

                temp = strstr(temp,"UC;");
                if(temp)
                        ch->UC = atoi((char*)&temp[strlen("UC;")]);

                temp = strstr(temp,"U0;");
                if(temp)
                        ch->U0 = atoi((char*)&temp[strlen("U0;")]);

                temp = strstr(temp,"UL;");
                if(temp)
                        ch->UL = atoi((char*)&temp[strlen("UL;")]);
        }

        return retValue;
}

UINT8 xl618::writeCh(pCHCFGTYPE ch)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    pSend += sprintf (
                        pSend,STR_WCHCFG CR
                        "CHNUM;%d"CR
                        "IA;%d"CR
                        "IB;%d"CR
                        "IC;%d"CR
                        "I0;%d"CR
                        "IMA;%d"CR
                        "IMB;%d"CR
                        "IMC;%d"CR
                        "UA;%d"CR
                        "UB;%d"CR
                        "UC;%d"CR
                        "U0;%d"CR
                        "UL;%d"CR,
                        ch->CHNUM,
                        ch->IA,
                        ch->IB,
                        ch->IC,
                        ch->I0,
                        ch->IMA,
                        ch->IMB,
                        ch->IMC,
                        ch->UA,
                        ch->UB,
                        ch->UC,
                        ch->U0,
                        ch->UL);
    UINT16 frameSize = pSend - (char*)sendBuf;
    retValue = readOneFrame(frameSize,(char*)"WCHCFG",NULL,(char*)"WCHCFGACK",0);

    return retValue;
}

UINT8 xl618::setMPE(pMETYPE data,pMEable able)     //data，要设置的测量值，albe，是否有效0表示无效，1表示有效。每项只占用一位。
{

        UINT8 retValue = ERR_UNIVERSAL;
        char *pSend = (char*)sendBuf;
        strcpy(pSend,STR_MPE CR);
        pSend += strlen(STR_MPE CR);

        if(able->UL1)
                pSend += sprintf(pSend,"0;%lE"CR,data->UL1);
        else
                pSend += sprintf(pSend,"0;NC"CR);

        if(able->IL1)
                pSend += sprintf(pSend,"1;%lE"CR,data->IL1);
        else
                pSend += sprintf(pSend,"1;NC"CR);



        UINT16 frameSize = pSend - (char*)sendBuf;

        retValue = readOneFrame(frameSize,(char*)"MPE",NULL,(char*)"MPEACK",1);

        return retValue;
}

UINT8 xl618::getME(pMETYPE data)
{
    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;
    strcpy(pSend,STR_ME CR);
    pSend += strlen(STR_ME CR);
    char* temp;

        UINT16 frameSize = pSend - (char*)sendBuf;

        if((retValue = readOneFrame(frameSize,(char*)"ME",NULL,(char*)"MEACK",500)) == ERR_RIGHT)
        {//解析帧
                temp = strstr((char*)recvBuf,"0;");
                if(temp)
                        data->UL1 = atof(&temp[2]);

                temp = strstr((char*)recvBuf,"1;");
                if(temp)
                        data->IL1 = atof(&temp[2]);

                temp = strstr((char*)recvBuf,"2;");
                if(temp)
                        data->P1 = atof(&temp[2]);

                temp = strstr((char*)recvBuf,"3;");
                if(temp)
                        data->Price = atof(&temp[2]);

                temp = strstr((char*)recvBuf,"4;");
                if(temp)
                        data->Time = atof(&temp[2]);
        }


        return retValue;
}

UINT8 xl618::setSEDSP(UINT8 enable,UINT8 *addr,UINT16 appid,UINT8 *svid,pCHTYPE ch)
{

        UINT8 retValue = ERR_UNIVERSAL;
        char *pSend = (char*)sendBuf;
        UINT16 frameSize;

        pSend += sprintf(pSend,"SEDSP"CR);
        pSend += sprintf(pSend,"ENABLE;%d"CR,enable);
        pSend += sprintf(pSend,"DADDR;%s"CR,(char*)addr);
        pSend += sprintf(pSend,"APPID;0x%x"CR,appid);
        pSend += sprintf(pSend,"svID;%s"CR,(char*)svid);
        pSend += sprintf(pSend,"CHNUM;%d"CR,ch->chnum);
        pSend += sprintf(pSend,"IMA;%d"CR,ch->ima);
        pSend += sprintf(pSend,"IMB;%d"CR,ch->imb);
        pSend += sprintf(pSend,"IMC;%d"CR,ch->imc);
        pSend += sprintf(pSend,"UA;%d"CR,ch->ua);
        pSend += sprintf(pSend,"UB;%d"CR,ch->ub);
        pSend += sprintf(pSend,"UC;%d"CR,ch->uc);

        frameSize = pSend - (char*)sendBuf;
        retValue = readOneFrame(frameSize,(char*)"SEDSP",NULL,(char*)"SEDSPACK",2);

        return retValue;
}

UINT8 xl618::readSEDSP(UINT8 *enable,UINT8 *addr,UINT16 *appid,UINT8 *svid,pCHTYPE ch)
{

    UINT8 retValue = ERR_UNIVERSAL;
    char *pSend = (char*)sendBuf;

    char *temp;
    char *temp2;

    strcpy(pSend,"SEDRP"CR);
    pSend += strlen("SEDRP"CR);

    UINT16 frameSize = pSend - (char*)sendBuf;

    if((retValue = readOneFrame(frameSize,(char*)"SEDRP",NULL,(char*)"SEDRPACK",2)) == ERR_RIGHT)
    {//解析帧
            temp = strstr((char*)recvBuf,"ENABLE;");
            if(temp)
            {
                 *enable = atoi(&temp[strlen("enable;")]);
                //  qDebug("enable====%d",*enable);

            }
            temp = strstr((char*)recvBuf,"DADDR;");
            if(temp)
            {
                    temp2 = strstr(temp,CR);
                    if(temp2)
                    {
                            memcpy(addr,&temp[strlen("DADDR;")],1 + temp2 - &temp[strlen("DADDR;")]);
                            addr[temp2 - &temp[strlen("DADDR;")]] = 0;
                    }
                    //  qDebug("addr====%s",addr);
            }


            temp = strstr((char*)recvBuf,"APPID;");
            if(temp)
            {
                    sscanf(&temp[strlen("APPID;")],"0x%x",(unsigned int*)appid);
                   *appid = atoi(&temp[strlen("APPID;0X")]);
                    //qDebug("appid====%d",*appid);

            }

            temp = strstr((char*)recvBuf,"svID;");
            if(temp)
            {
                    temp2 = strstr(temp,CR);
                    if(temp2)
                    {
                            memcpy(svid,&temp[strlen((char*)"SVID;")],1 + temp2 - &temp[strlen((char*)"SVID;")]);
                           // memcpy(svid,&temp[strlen((char*)"SETSVIDSVID;")],1 + temp2 - &temp[strlen((char*)"SETSVIDSVID;")]);
                            svid[temp2 - &temp[strlen("SVID;")]] = 0;
                    }
                   /// qDebug("svid====%s",svid);
            }

            temp = strstr((char*)recvBuf,"CHNUM;");
            if(temp)
                    ch->chnum = atoi(&temp[strlen("CHNUM;")]);

            temp = strstr((char*)recvBuf,"IMA;");
            if(temp)
                    ch->ima = atoi(&temp[strlen("IMA;")]);

            temp = strstr((char*)recvBuf,"IMB;");
            if(temp)
                    ch->imb = atoi(&temp[strlen("IMB;")]);

            temp = strstr((char*)recvBuf,"IMC;");
            if(temp)
                    ch->imc = atoi(&temp[strlen("IMC;")]);

            temp = strstr((char*)recvBuf,"UA;");
            if(temp)
                    ch->ua = atoi(&temp[strlen("UA;")]);

            temp = strstr((char*)recvBuf,"UB;");
            if(temp)
                    ch->ub = atoi(&temp[strlen("UB;")]);

            temp = strstr((char*)recvBuf,"UC;");
            if(temp)
                    ch->uc = atoi(&temp[strlen("UC;")]);

    }
    return retValue;
}

