#ifndef MISC_H
#define MISC_H

#include "stdafx.h"
#include <QObject>
#include <QModelIndex>


/**
 * @brief The Misc class
 * 一些常用操作
 */
class Misc : public QObject
{
    Q_OBJECT
public:
    explicit Misc(QObject *parent = 0);
    static float myMod(float a, int b); //取模操作
    static float phaseMod(float a); //取模操作

    static void topRow(QModelIndex input, int *val);      //返回顶层行
    /*写操作，返回修改后的source*/
    static QString dealPamFuncW(QString source, QString name, QString sp1, QString data, QString sp2, QString sp3); //name:名字 sp1：第一个分隔符 data:数据 sp2:第二个分隔符 sp3:前缀分隔符

    /*读操作，返回查询的数据*/
    static QString dealPamFuncR(QString source, QString name, QString sp1, QString sp2, QString sp3); //name:名字 sp1：第一个分隔符 data:数据 sp2:第二个分隔符 sp3:前缀分隔符



signals:

public slots:

};

#endif // MISC_H
