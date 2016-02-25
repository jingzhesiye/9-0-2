#ifndef STDAFX_H
#define STDAFX_H

#include <QStringList>
#include <QDomElement>

#define ADCDEVICE           "/dev/adc"
#define SDDEVICE            "/dev/sdcard"
#define ttySAC1_DEVICE      "/dev/ttySAC1"
#define SERIAL_BUFFSIZE      0x2FFFF
#define CR		           "\r\n"

typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
typedef int INT32;
typedef short int INT16;
typedef signed char INT8;
typedef unsigned short WORD16;
typedef float FLOAT32;
typedef double FLOAT64;
typedef unsigned long DWORD;//双字即为4个字节，

typedef struct
{
    QString replaceStr;
    QString searchStr;
}replaceDocType;

typedef QList<replaceDocType> replaceDocTypeList;

typedef struct
{
    int num;
    QDomElement element;
}LN_Data, *pLN_Data;


typedef struct
{
    QStringList header;
    QList<QStringList> content;
}SmvScl_Data, *pSmvScl;

typedef struct
{
    QStringList header;
    QList<QStringList> content;
}GseScl_Data, *pGseScl_Data;

typedef struct
{
    UINT8  frame[3000];			//原始帧
}GSE_FRAMETYPE,*pGSE_FRAMETYPE,**ppGSE_FRAMETYPE;


typedef struct
{
    UINT32 STNUM;
    UINT32 SQNUM;
    UINT32 CHLNUM;
    UINT8  ALLDATA[3000];

}GSE_RGDATATYPE,*pGSE_RGDATATYPE,**ppGSE_RGDATATYPE;


typedef struct
{
    UINT32 GNUM;
    UINT32 APPID[16];
}GSE_SCANTYPE,*pGSE_SCANTYPE,**ppGSE_SCANTYPE;

typedef struct
{
    UINT8 stVal;
    UINT8 q[3];
    UINT8 t[8];
}GOOSE_DO_3_TYPE;

typedef struct
{
    UINT8 stVal;
    UINT8 q[3];
    UINT8 t[8];
}GOOSE_DA_3_TYPE;

typedef struct
{
    UINT8 stVal;
    UINT8 q[3];
}GOOSE_DA_2_TYPE;

typedef struct
{
    UINT8 stVal;
}GOOSE_DA_1_TYPE;

typedef  union
{
    GOOSE_DA_3_TYPE  DA3;      // s,q[3],t[8]
    GOOSE_DA_2_TYPE  DA2;      // s,q[3]
    GOOSE_DA_1_TYPE  DA1;     // 单点开关格式,s
    GOOSE_DO_3_TYPE  DO3;     // 结构型开关量格式，s,q[3],t[8]
    UINT8 chBstr2[2];    // 双点开关
    float Float_value;    // 浮点格式
    UINT8 Time[8];       // 时间类型
    UINT8 Quality[3];   // 品质类型
}GSE_UPGTYPE;

typedef struct
{
    UINT16 GOOSENUM;
    UINT16 DADDR[6];
    UINT16 TCIPRI;
    UINT16 TCIVID;
    UINT16 APPID;
    UINT8  *GOCBREF;
    UINT8  *DATASET;
    UINT8  *GOID;
    UINT16 TEST;
    UINT16 CONFREV;
    UINT16 CHANNLENUM;
    UINT8  DATAFORMAT[150];
    UINT16 TIME0;
    UINT16 TIME1;
    UINT16 TIME2;
    UINT16 TIME3;
    UINT16 TINVERSE;
    UINT16 INVEREN;


}GSE_SPTYPE,*pGSE_SPTYPE,**ppGSE_SPTYPE;

typedef struct
{
    UINT8 GOOSENUM:1;
    UINT8 DADDR:1;
    UINT8 TCIPRI:1;
    UINT8 TCIVID:1;
    UINT8 APPID:1;
    UINT8 GOCBREF:1;
    UINT8 DATASET:1;
    UINT8 GOID:1;
    UINT8 TEST:1;
    UINT8 CONFREV:1;
    UINT8 CHANNLENUM:1;
    UINT8 DATAFORMAT:1;
    UINT8 TIME0:1;
    UINT8 TIME1:1;
    UINT8 TIME2:1;
    UINT8 TIME3:1;
    UINT8 TINVERSE:1;
    UINT8 INVEREN:1;
}ISABLE_GSE_SP,*pISABLE_GSE_SP,**ppISABLE_GSE_SP;
typedef struct
{
        UINT16 start;
        UINT16 num;
}FRAME_TYPE,*pFRAME_TYPE,**ppFRAME_TYPE;

typedef struct
{
        FLOAT32 frame_delay;
        FLOAT32 cloclk_delay;
        FLOAT32 delayshake;
}MUTYPE,*pMUTYPE,**ppMUTYPE;

typedef struct
{
        FLOAT32 dimSize;		//数组大小
        FLOAT32 elt[1];
}FLOARR,*pFLOARR,**FloHandle;

typedef struct
{
    FloHandle CH1;
    FloHandle CH2;
    FloHandle CH3;
    FloHandle CH4;
    FloHandle CH5;
    FloHandle CH6;
}KLTYPE,*pKLTYPE,**ppKLTYPE;


typedef struct
{
        FLOAT32 rms;//有效值
        FLOAT32 rms1;//基波有效值
        UINT32 samdot;//采样点数
        FloHandle fN;//谐波含有率
        FloHandle qN;//谐波相位
}HARMONIC_TYPE,*pHARMONIC_TYPE,**ppHARMONIC_TYPE;

typedef struct
{
        UINT8 mode;			//丢帧模式：0:随机发生,1:一个周波内连续发生
        UINT8 calcutype;	//丢包类型：0:插值1:丢包前数据 2:丢包后数据
        UINT8 onoff;		//0:不启动 1:启动
        //对齐：占1字节
        FLOAT32 ratio;		//丢帧率; 0.01代表 1%
        UINT32 intTimes;	//中断数,就是在1秒钟内中断的周波数
}SETFRAMERR_TYPE,*pSETFRAMERR_TYPE,**ppSETFRAMERR_TYPE;


typedef struct
{
        float f; //f为谐波含量单位 %。
        float q;//q 为谐波相位单位 为 度
}HAIMONICVALUE_TYPE;
typedef struct
{
        HAIMONICVALUE_TYPE Ua[40];
        HAIMONICVALUE_TYPE Ub[40];
        HAIMONICVALUE_TYPE Uc[40];
        HAIMONICVALUE_TYPE Ia[40];
        HAIMONICVALUE_TYPE Ib[40];
        HAIMONICVALUE_TYPE Ic[40];
        float RMSUa1;                           //Ua基波有效值单位为 V
        float RMSUb1;                           //Ub基波有效值单位为 V
        float RMSUc1;                           //Uc基波有效值单位为 V
        float RMSIa1;                           //Ia基波有效值单位为 a
        float RMSIb1;                           //Ib基波有效值单位为 a
        float RMSIc1;                           //Ic基波有效值单位为 a
 }SET_HARMONIC_TYPE,*pSET_HARMONIC_TYPE;


typedef struct
{
        UINT16 product;				//厂家
        UINT16 asduNum;				//ASDU单元数
        UINT32 samNum;				//采样点数
        UINT32 ratedDelay;			//额定延时
        FLOAT32 voltagerange;		//电压量程
        FLOAT32 currentrange;		//电流量程
        UINT32 maxSamcnt;			//最大采样点计数
        UINT8  frame[3000];			//原始帧
        UINT32 frame_size;			//原始帧
}IECTYPE,*pIECTYPE,**ppIECTYPE;

typedef struct
{
        INT32 dimSize;
        INT32 elt[1];
}INTARR,*pINTARR,**IntHandle;
typedef struct
{
        INT32 delay1;
        IntHandle CH1;

        INT32 delay2;
        IntHandle CH2;

        INT32 delay3;
        IntHandle CH3;

        INT32 delay4;
        IntHandle CH4;

        INT32 delay5;
        IntHandle CH5;

        INT32 delay6;
        IntHandle CH6;
}LKLTYPE,*pLKLTYPE,**ppLKLTYPE;

typedef struct
{
    UINT8 chnum;
    UINT8 ima;
    UINT8 imb;
    UINT8 imc;
    UINT8 ua;
    UINT8 ub;
    UINT8 uc;
}CHTYPE2,*pCHTYPE;

typedef struct
{
    UINT8 UL1:1;   //UL1只能赋值为0,1 只占一位
    UINT8 UL2:1;
    UINT8 UL3:1;
    UINT8 IL1:1;
    UINT8 IL2:1;
    UINT8 IL3:1;
    UINT8 Phi1:1;
    UINT8 Phi2:1;
    UINT8 Phi3:1;
    UINT8 Phi4:1;
    UINT8 Phi5:1;
    UINT8 Phi6:1;
    UINT8 cos1:1;
    UINT8 cos2:1;
    UINT8 cos3:1;
    UINT8 P1:1;
    UINT8 P2:1;
    UINT8 P3:1;
    UINT8 Q1:1;
    UINT8 Q2:1;
    UINT8 Q3:1;
    UINT8 S1:1;
    UINT8 S2:1;
    UINT8 S3:1;
    UINT8 SP:1;
    UINT8 SQ:1;
    UINT8 SS:1;
    UINT8 Freq:1;
    UINT8 DC1:1;
    UINT8 DC2:1;
    UINT8 DC3:1;
    UINT8 DC4:1;
    UINT8 DC5:1;
    UINT8 DC6:1;
    UINT32 BB:30;//占位，用足64bit
}MEable,*pMEable,**ppMEable;

typedef struct
{
    FLOAT64 UL1;
    FLOAT64 IL1;
    FLOAT64 P1;
    FLOAT64 Price;
    FLOAT64 Time;
}METYPE,*pMETYPE,**ppMETYPE;

typedef struct
{
    UINT16 CHNUM;
    UINT16 IA;
    UINT16 IB;
    UINT16 IC;
    UINT16 I0;
    UINT16 IMA;
    UINT16 IMB;
    UINT16 IMC;
    UINT16 UA;
    UINT16 UB;
    UINT16 UC;
    UINT16 U0;
    UINT16 UL;
}CHCFGTYPE,*pCHCFGTYPE,**ppCHCFGTYPE;

typedef struct
{
        UINT8 ASDUNUM;
        UINT8 PRODUCT;
        UINT8 NETTYPE;
        UINT8 CHECKTYPE;
        UINT8 TIMETRIGEDGE;
        UINT8 TRANMODETYPE;
        UINT8 SYNTYPE;
        UINT8 TRANSFORMERCH;
        UINT8 MESUREPROTECT;
        UINT8 CURRENTINPUT;
        UINT8 STYPE;
        UINT8 IEC61850;
        UINT8 NETPORT;
        UINT8 DADDR;
        UINT8 IRIG_B;
        UINT8 SAMNUM;
        UINT8 ANALOGRATE_V;
        UINT8 ANALOGRATE_I;
        UINT8 AMMETER_CONST;
        UINT8 METERCONST;
        UINT8 RATEDDELAY;
        UINT8 CHECKNUM;
        UINT8 VOLTAGERANGE;
        UINT8 CURRENTRANGE;
        UINT8 VOLTAGERANGE_2N;
        UINT8 CURRENTRANGE_2N;
        UINT8 KB;
        UINT8 KX;
        UINT8 TRATED;
        UINT8 SNUM;
        UINT8 TIMEDELAY;
        UINT8 COLLORNOSYN;
        UINT8 FT3OUT;
        UINT8 FT3CALDELAY;
        UINT8 COMPOSITEERR;
        UINT8 IBSEL;
        UINT8 IXSELSMALL;
        UINT8 TRANSIENT;
        UINT8 VLANTYPE;
        UINT8 VLAN;
}ISABLE_SP,*pISABLE_SP,**ppISABLE_SP;
typedef struct
{
    FLOAT32 SAMRATE;
    UINT8   PRODUCT[30];
    UINT8   CHARGETYPE;
    UINT8   LOADTYPE;
    FLOAT32 VOLTAGERANGE;
    FLOAT32 CURRENTRANGE;
    FLOAT32 METERCONST;
    FLOAT32 CONST;
    FLOAT32 PRICE;
    UINT8   MEASURETYPE;

}SPTYPE,*pSPTYPE,**ppSPTYPE;


typedef struct
{
    UINT8 STATE;
    UINT8 CHARGEMODE;
    FLOAT32 VOLTAGENEED;
    FLOAT32 CURRENCENEED;
    FLOAT32 VOLTAGEOUT;
    FLOAT32 CURRENCEOUT;
    FLOAT32 CHARGETIME;
}RSTYPE,*pRSTYPE,**ppRSTYPE;


typedef struct
{
    FLOAT32 CURRENCEINMAX;
    FLOAT32 VOLTAGEINMAX;
    FLOAT32 VOLTAGEBAT;
    FLOAT32 VOLTAGEOUTMAX;
    FLOAT32 VOLTAGEOUTMIN;
    FLOAT32 CURRENCEOUTMAX;
    FLOAT32 VOLTAGEMEASURE;
    FLOAT32 CURRENCEMEASURE;
    FLOAT32 SOC;
    FLOAT32 TIMEREMAIN;
    FLOAT32 TIMECHARGE;
    FLOAT32 POWER;
}RDTYPE,*pRDTYPE,**ppRDTYPE;


typedef struct
{
    FLOAT32 L1;
    FLOAT32 L2;
    FLOAT32 L3;
}VRCRTYPE,*pVRCRTYPE,**ppVRCRTYPE;

typedef struct
{
    FLOAT32 PE;
    FLOAT32 TE;
    //注意对齐
}ESTYPE,*pESTYPE,**ppESTYPE;

typedef struct
{
    FLOAT32 s;
    UINT32 valid;
    FLOAT32 b1;
    FLOAT32 b2;
}ESTDTYPE,*pESTDTYPE,**ppESTDTYPE;

typedef struct
{
    FLOAT64	WP;		//有功电能
    FLOAT64	WQ;		//无功电能
    UINT32	NP;		//有功脉冲累积个数
    UINT32	NQ;		//有功脉冲累积个数
    FLOAT64	P;		//有功功率
    FLOAT64	Q;		//无功功率
}PULSEPOW,*pPULSEPOW,**ppPULSEPOW;//脉冲输入电能


/*命令字符串定义*/
#define STR_PTPID	        "RPTPID"
#define STR_RGDATA	        "RGDATA"
#define STR_UPG			"UPG"
#define STR_SGP			"SGP"
#define STR_SM			"SM"
#define STR_RSM			"RSM"
#define STR_SP			"SP"
#define STR_SETBAUD		"SETBAUD"
#define STR_SETBAUDACK	"SETBAUDACK"
#define STR_GETENERGYPUL	"GETENERGYPUL"
#define STR_GETENERGYPULACK	"GETENERGYPULACK"
#define STR_RP			"RP"
#define STR_VR			"VR"
#define STR_CR			"CR"
#define STR_MT			"MT"
#define STR_RVR			"RVR"
#define STR_RCR			"RCR"
#define STR_ME			"ME"
#define STR_MPE			"MPE"
#define STR_EB			"EB"
#define STR_EE			"EE"
#define STR_ES			"ES"
#define STR_RD			"RD"
#define STR_RS			"RS"
#define STR_EV			"EV"
#define STR_EVT			"EVT"
#define STR_HR			"HR"
#define STR_HRN			"HRN"
#define STR_KL			"KL"
#define STR_LKL			"LKL"
#define STR_AV			"AV"
#define STR_ADW			"ADW"
#define STR_DTW			"DTW"
#define STR_DTR			"DTR"
#define STR_RMD			"RMD"
#define STR_WMD			"WMD"
#define STR_IEC61850	"IEC61850"
#define STR_SAN			"SAN"
#define STR_SANACK		"SANACK"
#define STR_MSV			"MSV"
#define STR_SR			"SR"
#define STR_SETCINPUT	"SETCINPUT"
#define STR_FRAM		"FRAM"
#define STR_SKL			"SKL"
#define STR_SMACK		"SMACK"
#define STR_SPACK		"SPACK"
#define STR_VRACK		"VRACK"
#define STR_CRACK		"CRACK"
#define STR_MPACK		"MPACK"
#define STR_EBACK		"EBACK"
#define STR_EEACK		"EEACK"
#define STR_EVTACK		"EVTACK"
#define STR_MPACK		"MPACK"
#define STR_SKLACK		"SKLACK"
#define STR_MPEACK		"MPEACK"
#define STR_HR			"HR"
#define STR_ESTD		"ESTD"
#define STR_SETFRAMERR	"SETFRAMERR"
#define STR_SETFRAMERRACK	"SETFRAMERRACK"
#define STR_GETSYN		"GETSYN"
#define STR_RSR			"RSR"
#define STR_SETMAC		"SETMAC"
#define STR_SETMACACK	"SETMACACK"
#define STR_GETMAC		"GETMAC"
#define STR_GETMACACK	"GETMACACK"
#define STR_FRAMERR		"FRAMERR"
#define STR_FRAMERRACK	"FRAMERRACK"
#define STR_CLRFRAMERR	"CLRFRAMERR"
#define STR_CLRFRAMERRACK	"CLRFRAMERRACK"
#define STR_WCHCFG		"WCHCFG"
#define STR_WCHCFGACK	"WCHCFGACK"
#define STR_RCHCFG		"RCHCFG"
#define STR_RCHCFGACK	"RCHCFGACK"
#define STR_RNOSYN		"RNOSYN"
#define STR_RNOSYNACK	"RNOSYNACK"
#define STR_RDDEVICE	"RDDEVICE"
#define STR_RDDEVICEACK	"RDDEVICEACK"
#define STR_AUTOPORTSEL	"AUTOPORTSEL"
#define STR_AUTOPORTSELACK	"AUTOPORTSELACK"
#define STR_AUTOIECSEL "AUTOIECSEL"
#define STR_AUTOIECSELACK "AUTOIECSELACK"
#define STR_AUTOSIGSEL	"AUTOSIGSEL"
#define STR_AUTOSIGSELACK	"AUTOSIGSELACK"
#define STR_AUTOCALRATIO	"AUTOCALRATIO"
#define STR_AUTOCALRATIOACK	"AUTOCALRATIOACK"
#define STR_AUTOTRANSEL "AUTOTRANSEL"
#define STR_AUTOTRANSELACK "AUTOTRANSELACK"
#define STR_RWAVEALL	"RWAVEALL"
#define STR_RWAVEALLACK	"RWAVEALLACK"
#define STR_MU			"MU"
#define STR_MUACK		"MUACK"
#define STR_MUFULL		"MUFULL"
#define STR_MUFULLACK	"MUFULLACK"

#define STR_GETMETERENERGY	"GETMETERENERGY"
#define STR_GETMETERENERGYACK	"GETMETERENERGYACK"

#define STR_SETMETERENERGY	"SETMETERENERGY"
#define STR_SETMETERENERGYACK	"SETMETERENERGYACK"

#define STR_CLRENERGY		"CLRENERGY"
#define STR_CLRENERGYACK	"CLRENERGYACK"
/*end 命令字符串定义*/

/*错误返回值：>=0x80表示的是各函数自定义的错误*/
#define ERR_UNIVERSAL				0x00		//通用错误
#define ERR_RIGHT					0x01		//无错误
#define ERR_SEND					0x02		//数据发送错误
#define ERR_RECV					0x03		//数据接收错误
#define ERR_BUFFER					0x04		//缓冲区不足
#define ERR_REPORT					0x05		//其它上报帧类，即不是期待的帧
#define ERR_RRETURN					0x06		//错误应答

#define ERR_PARA					0x81		//参数错误
#define ERR_KLDATA					0x82		//通道数据错误
#define ERR_MAXTIMES				0x83		//超过最大读取错误
#define ERR_CONNECT					0x84		//连接错误
#define ERR_NETERROR				0x85		//UDP创建错误
/*end 错误返回值*/

/*参数定义*/
//SM参数
#define PAR_PRICISIONTRANSFER				0
#define PAR_VIRTUALLOAD						1
#define PAR_ACTUALLOAD						2
#define PAR_MULTIMETER						3
#define PAR_DIGITALTRANSFORMERS				4
#define PAR_SMALLSIGNALTRANSFORMERS			5
#define PAR_DIGITALTRANSFORMERSTRANSFER		6
#define PAR_VIRTUALTEST						7
#define PAR_NOSYNTRAN						8
#define PAR_COLLECTOR						9
#define PAR_DIGITALTRANS					10
#define PAR_BAOHUNOSYNTRAN					11
#define PAR_FT3TEST							12
#define PAR_MUTEST							13
#define PAR_TRADITIONAL						14

#define STR_PRICISIONTRANSFER				"PRICISIONTRANSFER"
#define STR_VIRTUALLOAD						"VIRTUALLOAD"
#define STR_ACTUALLOAD						"ACTUALLOAD"
#define STR_MULTIMETER						"MULTIMETER"
#define STR_DIGITALTRANSFORMERS				"DIGITALTRANSFORMERS"
#define STR_SMALLSIGNALTRANSFORMERS			"SMALLSIGNALTRANSFORMERS"
#define STR_DIGITALTRANSFORMERSTRANSFER		"DIGITALTRANSFORMERSTRANSFER"
#define STR_VIRTUALTEST						"VIRTUALTEST"
#define STR_NOSYNTRAN						"NOSYNTRAN"
#define STR_COLLECTOR						"COLLECTOR"
#define STR_DIGITALTRANS					"DIGITALTRANS"
#define STR_BAOHUNOSYNTRAN					"BAOHUNOSYNTRAN"
#define STR_FT3TEST							"FT3TEST"
#define STR_MUTEST							"MUTEST"
#define STR_TRADITIONAL						"TRADITIONAL"

typedef QList<int> QIntList;
//定时器类型

#define SSMV_RMS	       10
#define RSMV_WAVE	       31              //波形图
#define RSMV_PHASOR 	       32          //相位
#define RSMV_HARMONIC 	       35          //谐波
#define RSMV_WAVEALL	       37          //解析
#define RFT3_WAVE	       40           //FT3反馈
#define ESTD         51           //GSE扫描报文APPID
#define ENERGY_PUL     60
#define ENERGY_STD         61


#define ES                 50
#define ME	               30
#define RD                 71
#define RS	               72

#endif // STDAFX_H
