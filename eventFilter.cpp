#include "mainwidget.h"

bool MainWidget::eventFilter(QObject *target,QEvent *event)
{
#if 0
    if(event->type() == QEvent::HoverEnter)
    {
        qDebug()<<"eventFilter11";
        ui->sideBar_TlBtn_1->setStyleSheet(QString::fromUtf8(
"    border-right: 3px solid rgb(170, 170, 170);\n"
"    border-left: 3px solid rgb(170, 170, 170);\n"
"    background: qlineargradient(spread:reflect,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 rgba(100, 100, 100, 255),\n"
"        stop:1 rgba(250, 250, 250, 255));\n"
"}"));

        ui->sideBar_TlBtn_1->update();

        ui->sideBar_TlBtn_1->setIconSize(QSize(90,90));

   }
    if(event->type() == QEvent::HoverLeave)
    {
        qDebug()<<"eventFilter11";
        ui->sideBar_TlBtn_1->setIconSize(QSize(80,80));

   }
#endif
    return QWidget::eventFilter(target, event);
}
