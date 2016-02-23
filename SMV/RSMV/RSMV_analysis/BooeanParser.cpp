#include <QtCore>
#include <QTextStream>
#include "booleanparser.h"

Node *BooleanParser::parse(const QString &expr)
{
    in = expr;
    in.replace(" ", "");
    pos = 0;

    Node *node = new Node("");

       // quint8 bb[256];

        int strLen = expr.length() / 2;
        quint8 *bb = new quint8[strLen];
        for(int i = 0; i < strLen; i ++)
        {
                bb[i] = expr.mid(i*2,2).toInt(0,16);
        }

        IEC61850ToXML(bb,node,1);
        delete []bb;
    return node;
}

void BooleanParser::addChild(Node *parent, Node *child)
{
    if (child)
        {
        parent->children += child;
        //parent->str += child->str;
        child->parent = parent;
    }
}
//lenB：Len域占用字节数，返回值：数据域占用字节数。
quint16 BooleanParser::getTLV(quint8 *temp,quint8 &lenB)
{
        quint16 len = 0;

        if(*temp & 0x80)
        {//多字节模式
                lenB = ((*temp) & 0x7F);
                if(lenB == 1)
                        len = temp[1];
                else if(lenB == 2)
                        len = temp[1] * 256 + temp[2];
                lenB += 1;
        }else
        {
                lenB = 1;
                len = temp[0];
        }
        return len;
}
quint32 BooleanParser::getTLVValue(quint8 dataLen,quint8 *index)
{
        quint32 retValue = 0;
        if(dataLen == 1)
                retValue = index[0];
        else if(dataLen == 2)
                retValue = index[0]*256 + index[1];
        else if(dataLen == 3)
                retValue = index[0]*256*256 + index[1]*256 + index[2];
        else if(dataLen == 4)
                retValue = index[0]*256*256*256 + index[1]*256*256 + index[2]*256 + index[3];

        return retValue;

}
quint8 BooleanParser::intemToXML(quint8 *strIn,qint32 &Ini,Node *parent,quint8 pinzi)
{
        quint8 tempB;
        quint16 temp;
        quint16 t2;
        quint16 Start,Length;

        Start = Ini;

        quint8 type = strIn[Ini];
        Ini += 1;	//偏移标识符
        quint16 dataLen = getTLV(&strIn[Ini],tempB);
        Ini += tempB;//偏移长度域
        t2 = Ini;//t2指标数据域开始位置
        Ini += dataLen;//偏移数据域

        Length = Ini - Start;



        if(type == 0x80)
        {//SVID
                addChild(parent,new Node(tr("svID"),QString().fromAscii((char*)&strIn[t2],dataLen),Start,Length));
        }else if(type == 0x81)
        {//DataSet
                addChild(parent,new Node("dataSet","",Start,Length));
        }else if(type == 0x82)
        {//sampleCount
                quint32 smpCnt  = getTLVValue(dataLen,&strIn[t2]);
                addChild(parent,new Node("smpCnt",QString().sprintf("%d",smpCnt),Start,Length));
        }else if(type == 0x83)
        {//conf
                quint32 confRev = getTLVValue(dataLen,&strIn[t2]);//ntohl(*((quint32*)&strIn[t2]));
                addChild(parent,new Node("conf",QString().sprintf("%d",confRev),Start,Length));
        }else if(type == 0x84)
        {//Refrtm
                addChild(parent,new Node("refrTm","",Start,Length));
        }else if(type == 0x85)
        {//syn
                quint32 smpSynch = getTLVValue(dataLen,&strIn[t2]);
                addChild(parent,new Node("smpSynch",QString().sprintf("%d",smpSynch),Start,Length));
        }else if(type == 0x86)
        {//rate
                quint32 smpRate = getTLVValue(dataLen,&strIn[t2]);
                addChild(parent,new Node("smpRate",QString().sprintf("%d",smpRate),Start,Length));
        }else if(type == 0x87)
        {//samples
                tempB = dataLen / 8;//通道数

                Node *tempNode = 0;
                tempNode = parent;
                parent = new Node("SequenceOfData",QString().sprintf("总通道数:%d",tempB),Start,Length);
                addChild(tempNode,parent);

                for(int i = 0; i < tempB; i ++)
                {
                        temp = i * 8 + t2;

                        tempNode = parent;
                        parent = new Node(QString().sprintf("通道%d",i + 1),"",temp,8);
                        addChild(tempNode,parent);

                        qint32 value = ntohl(*((quint32*)&strIn[temp]));
                        addChild(parent,new Node("数值",QString().sprintf("%d",value),temp,4));

                        quint32 pt = ntohl(*((quint32*)&strIn[temp + 4]));
                        //品质因数IEC61850-73

                        if(pinzi)
                        {
                                Node *tempNode = 0;
                                tempNode = parent;
                                parent = new Node("品质",QString().sprintf("0x%08X",pt),temp + 4,4);
                                addChild(tempNode,parent);

                                ValidityType valid = *(ValidityType*)&pt;
                                char strTemp[10];
                                char *pstr = strTemp;
                                switch(valid.validity)
                                {
                                case 0 :
                                        strcpy(pstr,"好");
                                        break;
                                case 1 :
                                        strcpy(pstr,"非法");
                                        break;
                                case 2 :
                                        strcpy(pstr,"保留");
                                        break;
                                case 3 :
                                        strcpy(pstr,"可疑");
                                        break;
                                }
                                addChild(parent,new Node("合法性",QString().sprintf("%d-",valid.validity) + pstr,temp + 4,4));
                                addChild(parent,new Node("溢出",QString().sprintf("%d-",valid.overflow) + (valid.overflow ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("超量程",QString().sprintf("%d-",valid.outOfRange) + (valid.outOfRange ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("坏引用",QString().sprintf("%d-",valid.badReference) + (valid.badReference ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("振荡",QString().sprintf("%d-",valid.oscillatory) + (valid.oscillatory ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("故障",QString().sprintf("%d-",valid.failure) + (valid.failure ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("老数据",QString().sprintf("%d-",valid.oldData) + (valid.oldData ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("不一致",QString().sprintf("%d-",valid.inconsistent) + (valid.inconsistent ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("不准确",QString().sprintf("%d-",valid.inaccurate) + (valid.inaccurate ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("源",QString().sprintf("%d-",valid.source) + (valid.source ? "取代":"过程"),temp + 4,4));
                                addChild(parent,new Node("测试",QString().sprintf("%d-",valid.test) + (valid.test ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("操作员闭锁",QString().sprintf("%d-",valid.operatorBlocked) + (valid.operatorBlocked ? "是":"否"),temp + 4,4));
                                addChild(parent,new Node("未定义",QString().sprintf("%d",valid.otherDefine),temp + 4,4));

                                parent = parent->parent;	//品质
                        }else
                        {
                                addChild(parent,new Node("品质",QString().sprintf("0x%08X",pt),temp + 4,4));
                        }
                        parent = parent->parent;	//通道%d
                }
                parent = parent->parent;		//总通道数:%d
        }else
        {//未识别
                addChild(parent,new Node("未识别标识","",Start,Length));
        }
        return 1;
}
quint32 BooleanParser::ntohl(quint32 netlong)
{
        quint32 retValue;
        *(((quint8*)&retValue)+0) = *(((quint8*)&netlong)+3);
        *(((quint8*)&retValue)+1) = *(((quint8*)&netlong)+2);
        *(((quint8*)&retValue)+2) = *(((quint8*)&netlong)+1);
        *(((quint8*)&retValue)+3) = *(((quint8*)&netlong)+0);
        return retValue;
}
quint16 BooleanParser::ntohs(quint16 netshort)
{
        quint16 retValue;
        *((quint8*)&retValue) = *(((quint8*)&netshort)+1);
        *(((quint8*)&retValue)+1) = *((quint8*)&netshort);
        return retValue;
}
quint8 BooleanParser::IEC61850ToXML(quint8 *strIn,Node *parent,quint8 pinzi)
{
        Node *node = parent;
        Node *tempNode = 0;
        QString tempQStr;

        qint32 index = 0;
        quint16 temp;
        quint8 tempB;
        quint16 tempLen;
        quint16 Start,Length;

        Start = index;
        Length = 12;
        tempNode = node;
        node = new Node(tr("以太网帧头"),"",Start,Length);
        addChild(tempNode,node);

        Start = index;
        Length = 6;

        addChild(node,new Node(tr("目标地址"),
                QString().sprintf("%02X-%02X-%02X-%02X-%02X-%02X",strIn[index],strIn[index+1],strIn[index+2],strIn[index+3],strIn[index+4],strIn[index+5]),
                Start,Length));
        index += 6;

        Start = index;
        Length = 6;

        addChild(node,new Node(tr("源地址"),
                QString().sprintf("%02X-%02X-%02X-%02X-%02X-%02X",strIn[index],strIn[index+1],strIn[index+2],strIn[index+3],strIn[index+4],strIn[index+5]),
                Start,Length));

        index += 6;

        Start = index;
        Length = 2;

        quint16 netType = ntohs(*((quint16*)&strIn[index]));
        index += 2;

        if(netType == 0x8100 || netType == 0x88ba)
        {
                if(netType == 0x8100)
                {//带VLANID标识符
                        addChild(node,new Node(tr("以太网报文类型"),"0x8100",Start,Length));

                        node = node->parent;//以太网帧头

                        Start = index;
                        Length = 2;

                        temp =  ntohs(*((quint16*)&strIn[index]));
                        index += 2;
                        tempNode = node;
                        node = new Node(tr("虚拟局域网"),"",Start,Length);
                        addChild(tempNode,node);

                        addChild(node,new Node(tr("优先级"),QString().sprintf("%d",(temp & 0xE000) >> 13),Start,Length));
                        addChild(node,new Node("CFI",QString().sprintf("%d",(temp & 0x1000) >> 12),Start,Length));
                        addChild(node,new Node("VLANID",QString().sprintf("%d",temp & 0x0FFF),Start,Length));

                        Start = index;
                        Length = 2;
                        temp = ntohs(*((quint16*)&strIn[index]));
                        index += 2;
                        if(temp == 0x88ba)
                        {
                                addChild(node,new Node(tr("以太网报文类型"),"0x88BA",Start,Length));
                        }
                        node = node->parent;	//虚拟局域网
                }else if(netType == 0x88ba)
                {//不带VLANID标识符
                        addChild(node,new Node(tr("以太网报文类型"),"0x88BA",Start,Length));
                        node = node->parent;	//虚拟局域网
                }

                Start = index;
                Length = 0xFFFF;

                tempNode = node;
                node = new Node(tr("IEC61850报文头"),"",Start,Length);
                addChild(tempNode,node);

                temp =  ntohs(*((quint16*)&strIn[index]));
                Start = index;
                Length = 2;

                index += 2;
                addChild(node,new Node("APPID",QString().sprintf("0x%x",temp),Start,Length));

                temp =  ntohs(*((quint16*)&strIn[index]));
                Start = index;
                Length = 2;
                index += 2;
                addChild(node,new Node("Length",QString().sprintf("%d",temp),Start,Length));

                temp =  ntohs(*((quint16*)&strIn[index]));
                Start = index;
                Length = 2;
                index += 2;
                addChild(node,new Node("Reserved",QString().sprintf("0x%04X",temp),Start,Length));

                temp =  ntohs(*((quint16*)&strIn[index]));
                Start = index;
                Length = 2;
                index += 2;
                addChild(node,new Node("Reserved",QString().sprintf("0x%04X",temp),Start,Length));

                tempB = strIn[index];
                Start = index;
                index += 1;
                if(tempB == 0x80)
                {//-9-1
                        temp = getTLV(&strIn[index],tempB);
                        Length = tempB + temp + 1;

                        index += tempB;
                        tempNode = node;
                        node = new Node("savpdu","IEC61850-9-1",Start,Length);
                        addChild(tempNode,node);

                        temp =  ntohs(*((quint16*)&strIn[index]));
                        Start = index;
                        Length = 2;
                        index += 2;
                        addChild(node,new Node(tr("ASDU数"),QString().sprintf("%d",temp),Start,Length));

                        Start = index;
                        Length = temp;

                        tempNode = node;
                        node = new Node("seqASDU","",Start,Length);
                        addChild(tempNode,node);

                        quint16 asduNum = temp;
                        for(int i = 0; i < asduNum; i++)
                        {
                                tempNode = node;
                                node = new Node(QString().sprintf("ASDU%d",i+1),"",Start,46);
                                addChild(tempNode,node);

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node(tr("ASDU长度"),QString().sprintf("%d",temp),Start,Length));

                                temp =  strIn[index];
                                Start = index;
                                Length = 1;
                                index += 1;
                                addChild(node,new Node("LNName",QString().sprintf("%d",temp),Start,Length));

                                temp =  strIn[index];
                                Start = index;
                                Length = 1;
                                index += 1;
                                addChild(node,new Node("DataSetName",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("LDName",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                if(temp == 0)
                                {
                                        addChild(node,new Node(tr("额定相电流"),QString().sprintf("%d(可配置)",temp),Start,Length));
                                }
                                else
                                {
                                      addChild(node,new Node("额定相电流",QString().sprintf("%d(%d A)",temp),Start,Length));
                                      // addChild(node,new Node("额定相电流",QString().sprintf("%d(%d A)",temp),Start,Length));

                                }

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                if(temp == 0)
                                {
                                        addChild(node,new Node("额定中线电流",QString().sprintf("%d(可配置)",temp),Start,Length));
                                }
                                else
                                {
                                        addChild(node,new Node("额定中线电流",QString().sprintf("%d(%d A)",temp),Start,Length));
                                }

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                if(temp == 0)
                                {
                                        addChild(node,new Node("额定相电压",QString().sprintf("%d(可配置)",temp),Start,Length));
                                }
                                else if(temp == 1)
                                {
                                        addChild(node,new Node("额定相电压",QString().sprintf("%d(%d V/√3)",temp,temp * 100),Start,Length));
                                }
                                else
                                {
                                        addChild(node,new Node("额定相电压",QString().sprintf("%d(%d kV/√3)",temp,temp / 100),Start,Length));
                                }

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("额定时延",QString().sprintf("%d(%d us)",temp,temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("A相保护电流",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("B相保护电流",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("C相保护电流",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("中线电流",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("A相测量电流",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("B相测量电流",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("C相测量电流",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("A相电压",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("B相电压",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("C相电压",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("零序电压",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("母线电压",QString().sprintf("%d",temp),Start,Length));

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;

                                tempNode = node;
                                node = new Node("状态字1",QString().sprintf("0x%04X",temp));
                                addChild(tempNode,node);
                                if(pinzi)
                                {
                                        StatusWord1Type w1 = *(StatusWord1Type*)&temp;
                                        addChild(node,new Node("要求维修",QString().sprintf("%d-",w1.WeiXiu) + (w1.WeiXiu?"要求维修":"良好"),Start,Length));
                                        addChild(node,new Node("LLNO.Mode",QString().sprintf("%d-",w1.LLN0Mode) + (w1.LLN0Mode?"试验":"接通"),Start,Length));
                                        addChild(node,new Node("激发时间",QString().sprintf("%d-",w1.JiFaShiJian) + (w1.JiFaShiJian?"数据无效":"数据有效"),Start,Length));
                                        addChild(node,new Node("插值法",QString().sprintf("%d-",w1.MuSyncType) + (w1.MuSyncType?"支持":"不支持"),Start,Length));
                                        addChild(node,new Node("同步状态",QString().sprintf("%d-",w1.IsSync) + (w1.IsSync?"同步无效":"同步有效"),Start,Length));
                                        addChild(node,new Node("通道1",QString().sprintf("%d-",w1.Ch1Status) + (w1.Ch1Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道2",QString().sprintf("%d-",w1.Ch2Status) + (w1.Ch2Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道3",QString().sprintf("%d-",w1.Ch3Status) + (w1.Ch3Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道4",QString().sprintf("%d-",w1.Ch4Status) + (w1.Ch4Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道5",QString().sprintf("%d-",w1.Ch5Status) + (w1.Ch5Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道6",QString().sprintf("%d-",w1.Ch6Status) + (w1.Ch6Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道7",QString().sprintf("%d-",w1.Ch7Status) + (w1.Ch7Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("CT类型",QString().sprintf("%d-",w1.CTOutputType) + (w1.CTOutputType?"空心线圈":"非空心线圈"),Start,Length));
                                        addChild(node,new Node("标度因子",QString().sprintf("%d-",w1.RangeFlag) + (w1.RangeFlag?"0x01E7":"0x01CF"),Start,Length));
                                        addChild(node,new Node("将来使用",QString().sprintf("%d",w1.spare1),Start,Length));
                                        addChild(node,new Node("将来使用",QString().sprintf("%d",w1.spare2),Start,Length));
                                }
                                node = node->parent;	//状态字1

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                tempNode = node;
                                node = new Node("状态字2",QString().sprintf("0x%04X",temp));
                                addChild(tempNode,node);

                                if(pinzi)
                                {
                                        StatusWord2Type w2 = *(StatusWord2Type*)&temp;

                                        addChild(node,new Node("通道8",QString().sprintf("%d-",w2.Ch8Status) + (w2.Ch8Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道9",QString().sprintf("%d-",w2.Ch9Status) + (w2.Ch9Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道10",QString().sprintf("%d-",w2.Ch10Status) + (w2.Ch10Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道11",QString().sprintf("%d-",w2.Ch11Status) + (w2.Ch11Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("通道12",QString().sprintf("%d-",w2.Ch12Status) + (w2.Ch12Status?"无效":"有效"),Start,Length));
                                        addChild(node,new Node("将来使用",QString().sprintf("%d",w2.spare3),Start,Length));
                                        addChild(node,new Node("将来使用",QString().sprintf("%d",w2.spare4),Start,Length));
                                        addChild(node,new Node("将来使用",QString().sprintf("%d",w2.spare5),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special1),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special2),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special3),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special4),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special5),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special6),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special7),Start,Length));
                                        addChild(node,new Node("供专用",QString().sprintf("%d",w2.special8),Start,Length));
                                }

                                node = node->parent;		//状态字2

                                temp =  ntohs(*((quint16*)&strIn[index]));
                                Start = index;
                                Length = 2;
                                index += 2;
                                addChild(node,new Node("采样计数器",QString().sprintf("%d",temp),Start,Length));

                                temp =  strIn[index];
                                Start = index;
                                Length = 1;
                                index += 1;
                                addChild(node,new Node("采样频率",QString().sprintf("%d",temp),Start,Length));

                                temp =  strIn[index];
                                Start = index;
                                Length = 1;
                                index += 1;
                                addChild(node,new Node("配置版本",QString().sprintf("%d",temp),Start,Length));

                                node = node->parent;	//ASDU%d
                        }
                        node = node->parent;	//seqASDU
                        node = node->parent;	//savpdu
                }else if(tempB == 0x60)
                {//-9-2LE
                        temp = getTLV(&strIn[index],tempB);
                        Length = tempB + temp + 1;
                        index += tempB;

                        tempNode = node;
                        node = new Node("savpdu","IEC61850-9-2",Start,Length);
                        addChild(tempNode,node);


                        //80
                        tempB = strIn[index];
                        Start = index;
                        index += 1;

                        temp = getTLV(&strIn[index],tempB);
                        Length = tempB + temp + 1;
                        index += tempB;

                        quint8 asduNum = getTLVValue(temp,&strIn[index]);

                        index += temp;

                        tempNode = node;
                        node = new Node("ASDU数",QString().sprintf("%d",asduNum),Start,Length);
                        addChild(tempNode,node);

                        //A2
                        tempB = strIn[index];
                        Start = index;
                        index += 1;

                        tempLen = getTLV(&strIn[index],tempB);
                        index += tempB;

                        Length = tempLen + tempB + 1;

                        tempNode = node;
                        node = new Node("seqASDU","",Start,Length);
                        addChild(tempNode,node);

                        for(int i = 0; i < asduNum; i ++)
                        {
                               // quint8 asT = strIn[index];
                                Start = index;
                                index += 1;
                                temp = getTLV(&strIn[index],tempB);
                                index += tempB;
                                Length = temp + tempB + 1;

                                tempNode = node;
                                node = new Node(QString().sprintf("ASDU%d",i+1),"",Start,46);
                                addChild(tempNode,node);

                                qint32 tempIndex = index;
                                while(index < (tempIndex + temp))
                                        intemToXML(strIn,index,node,pinzi);

                                node = node->parent;

                        }
                        node = node->parent;	//seqASDU
                        node = node->parent;	//savpdu
                }else
                {
                        addChild(node,new Node("savpdu",QString().sprintf("未识别类型：0x%02X",tempB),Start,Length));
                }
                node = node->parent;		//IEC61850报文头
        }else
        {//无法识别
                addChild(node,new Node("未识别标识","",Start,0xFFFF));
                node = node->parent;	//以太网帧头
        }	return 1;

}

