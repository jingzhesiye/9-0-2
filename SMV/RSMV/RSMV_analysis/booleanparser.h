#ifndef BOOLEANPARSER_H
#define BOOLEANPARSER_H
#include <qobject.h>
#include <QAbstractItemModel>
#include <QList>
#include <QString>

class Node
{
public:
    Node(QString type, const QString &str = "",quint16 start=0,quint16 length=0xFFFF);
    ~Node();

    QString type;
    QString str;
    Node *parent;
    quint16 start;
    quint16 length;
    QList<Node *> children;
    };

class BooleanModel : public QAbstractItemModel
{
public:
    BooleanModel(QObject *parent = 0);
    ~BooleanModel();

    void setRootNode(Node *node);

    QModelIndex index(int row, int column,
                      const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role) const;
    void getStartLength(const QModelIndex &index,quint16 &start,quint16 &length);

private:
    Node *nodeFromIndex(const QModelIndex &index) const;

    Node *rootNode;
};

class BooleanParser: public QObject
{
public:
    Node *parse(const QString &expr);

private:
    void addChild(Node *parent, Node *child);
    QString in;
    int pos;

        quint8 intemToXML(quint8 *strIn,qint32 &Ini,Node *parent,quint8 pinzi);
        quint8 IEC61850ToXML(quint8 *strIn,Node *parent,quint8 pinzi);
        quint16 getTLV(quint8 *temp,quint8 &lenB);
        quint32 getTLVValue(quint8 dataLen,quint8 *index);

        quint32 ntohl(quint32 netlong);
        quint16 ntohs(quint16 netshort);

        struct ValidityType
        {//品质因数定义quint32//860.73
                quint32 validity:2;
                quint32 overflow:1;
                quint32 outOfRange:1;
                quint32 badReference:1;
                quint32 oscillatory:1;
                quint32 failure:1;
                quint32 oldData:1;
                quint32 inconsistent:1;
                quint32 inaccurate:1;
                quint32 source:1;
                quint32 test:1;
                quint32 operatorBlocked:1;
                quint32 derived:1;
                quint32 otherDefine:18;
        };
        struct StatusWord1Type
        {//-9-1状态字1，quint16
                quint16 WeiXiu:1;
                quint16 LLN0Mode:1;
                quint16 JiFaShiJian:1;
                quint16 MuSyncType:1;
                quint16 IsSync:1;
                quint16 Ch1Status:1;
                quint16 Ch2Status:1;
                quint16 Ch3Status:1;
                quint16 Ch4Status:1;
                quint16 Ch5Status:1;
                quint16 Ch6Status:1;
                quint16 Ch7Status:1;
                quint16 CTOutputType:1;
                quint16 RangeFlag:1;
                quint16 spare1:1;
                quint16 spare2:1;
        };
        struct StatusWord2Type
        {//-9-1状态字2，quint16
                quint16 Ch8Status:1;
                quint16 Ch9Status:1;
                quint16 Ch10Status:1;
                quint16 Ch11Status:1;
                quint16 Ch12Status:1;
                quint16 spare3:1;
                quint16 spare4:1;
                quint16 spare5:1;
                quint16 special1:1;
                quint16 special2:1;
                quint16 special3:1;
                quint16 special4:1;
                quint16 special5:1;
                quint16 special6:1;
                quint16 special7:1;
                quint16 special8:1;
        };
};

#endif // BOOLEANPARSER_H
