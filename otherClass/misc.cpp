#include "misc.h"

Misc::Misc(QObject *parent) :
    QObject(parent)
{
}

float Misc::myMod(float a, int b)   //取模操作
{
    float c =  qAbs(static_cast<float>(b));
    float d = 0-c;
    while (a > c)
    {
        a -= c;
    }

    while (a < d)
    {
        a += c;
    }
    return a;
}

float Misc::phaseMod(float a) //取模操作
{
    while (a < 0.0)
    {
        a = 360.0 + a;
    }
    return a;
}


void Misc::topRow(QModelIndex input, int *val)        //活去顶层项的位置
{
    if (!input.isValid())
    {
        *val = -1;
        return;
    }

   if (input.parent().isValid())
   {
       topRow(input.parent(), val);
   }
   else
   {
       ////qDebug()<<"top row is："<<input.row();
       *val = input.row();
       ////qDebug()<<"*val = "<<*val;
   }
}

/*写操作，返回修改后的source*/
QString Misc::dealPamFuncW(QString source, QString name, QString sp1, QString data, QString sp2, QString sp3) //name:名字 sp1：第一个分隔符 data:数据 sp2:第二个分隔符 sp3:前缀分隔符
{
    int indexS = -1;
    int indexE = -1;
    int indexSP3 = -1;
    int len = -1;

    indexSP3 = source.indexOf(sp3);
    if (indexSP3 != -1)
    {
        source.remove(0, indexSP3);
    }

    if ((indexS = source.indexOf(sp3+name+sp1)) != -1)
    {
        if ((indexE = source.indexOf(sp2, indexS)) != -1)
        {
            indexS = indexS + sp3.size() + name.size() + sp1.size(); //指向data第一个元素
            len = indexE - indexS;
            source.replace(indexS, len, data);
        }
        else
        {
            //qDebug()<<"indexE:"<<indexE;
        }
    }
    else
    {
        //qDebug()<<"indexS:"<<indexS;
        source.append(tr("%1%2%3%4%5").arg(sp3, name, sp1, data, sp2));
    }

    return source;
}

/*读操作，返回查询的数据*/
QString Misc::dealPamFuncR(QString source, QString name, QString sp1, QString sp2, QString sp3) //name:名字 sp1：第一个分隔符 data:数据 sp2:第二个分隔符 sp3:前缀分隔符
{
    QString data;
    int indexS = -1;
    int indexE = -1;
    int indexSP3 = -1;
    int len = -1;

    indexSP3 = source.indexOf(sp3);
    if (indexSP3 != -1)
    {
        source.remove(0, indexSP3);
    }

    if ((indexS = source.indexOf(sp3+name+sp1)) != -1)
    {
        //qDebug()<<"indexS1:"<<indexS;
        if ((indexE = source.indexOf(sp2, indexS)) != -1)
        {
            indexS = indexS + sp3.size() + name.size() + sp1.size(); //指向data第一个元素
            //qDebug()<<"indexS2:"<<indexS;
            //qDebug()<<"indexE1:"<<indexE;
            len = indexE - indexS;
            //qDebug()<<"len:"<<len;
            data = source.mid(indexS, len);
        }
        else
        {
           ////qDebug()<<"indexE = -1";
        }
    }
    else
    {
      // //qDebug()<<"indexS = -1";
    }

    return data;
}
