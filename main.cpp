#include <QtGui/QApplication>
#include "mainwidget.h"
#include <QWSServer>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QFont font("kalinga",11,QFont::Normal); //simfang
    a.setFont(font);

    w.show();
    
    return a.exec();
}
