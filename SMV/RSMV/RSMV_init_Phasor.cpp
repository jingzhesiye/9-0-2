/*************************************************************
*界面 : 相位
*功能 : 将painter重载,绘制phase
*人员 : jingzhesiye@163.com
*时间 : 2013.9.25
***************************************************************/
#include"SMV/RSMV/RSMV_initPhasor.h"
#include "mainwidget.h"
#include "ui_mainwidget.h"

PhasorPaint::PhasorPaint(QWidget *parent) :
    QWidget(parent)
{
      QPalette PhasorPaint_Palette = palette();//设置背景色
      PhasorPaint_Palette.setColor( backgroundRole(), Qt::black );
      setPalette( PhasorPaint_Palette );
      setAutoFillBackground( true );//覆盖全屏
}

//70
//circle_1.drawEllipse(205,155,70,70);             //画圆
//circle_1.drawEllipse(170,120,140,140);
//circle_1.drawEllipse(135,85,210,210);
//circle_1.drawEllipse(100,50,280,280);

void PhasorPaint::paintEvent(QPaintEvent *)
{
  if(isUpdatePhasor)
    {
      updatePhasor();
    }
}

void PhasorPaint::updatePhasor()
{
    int  radius   = 40;     //半径
    int  tempX    = 25;
    int  tempY    = 20;
    int  circleX        = tempX+(radius/2)*4;     //圆心
    int  circleY        = tempY+(radius/2)*4;     //圆心
    int  lineLengthU    = radius*2;               //直线长度
    int  arrowLengthU   = lineLengthU -5;           //箭头长度
    int  lineLengthI    = (radius/2)*3;               //直线长度
    int  arrowLengthI   = lineLengthI -5;           //箭头长度

    int scale_vale=1;
    QPainter circle_1(this);
    circle_1.setPen(QPen( QColor(0, 170, 255, 255),1,Qt::DashLine)); //paint circle
    circle_1.setBrush(brush);
    //circle_1.drawEllipse(tempX+radius/2*3,tempY+radius/2*3,radius,radius);             //画圆
    //circle_1.drawEllipse(tempX+radius,tempY+radius,radius*2,radius*2);
    circle_1.drawEllipse(tempX+radius/2,tempY+radius/2,radius*3,radius*3);
    circle_1.drawEllipse(tempX,tempY,radius*4,radius*4);

    QPainter line_1(this);
    line_1.setPen(QPen( QColor(0, 170, 255, 255),1,Qt::DashLine));                 // paint line
    line_1.setBrush(brush);
    line_1.translate(circleX,circleY);	                               //  把窗体的坐标原点移到中心点


    for(int i=0;i<6;i++)
    {
        line_1.rotate(30);
        line_1.drawLine(0,0,0,lineLengthU);
        line_1.drawLine(0,0,0,-lineLengthU);
    }

    QPainter line_Ua(this);
    line_Ua.setPen(QPen(QColor(255,255, 0, 255),1));                // Ua
    line_Ua.setBrush(brush);
    line_Ua.translate(circleX,circleY);
    line_Ua.rotate(-UaRotate);
    line_Ua.scale(scale_vale,scale_vale);
    line_Ua.drawLine(0,0,0,radius*2);
    line_Ua.drawLine(5, arrowLengthU,0,lineLengthU);
    line_Ua.drawLine(-5,arrowLengthU,0,lineLengthU);
    line_Ua.drawText(-15,lineLengthU-15,tr("Ua"));

    QPainter line_Ub(this);
    line_Ub.setPen(QPen(QColor(0,255, 0, 255),1));                  // Ub
    line_Ub.setBrush(brush);
    line_Ub.translate(circleX,circleY);
    line_Ub.scale(scale_vale,scale_vale);
    line_Ub.rotate(-UbRotate);
    line_Ub.drawLine(0,0,0,lineLengthU);
    line_Ub.drawLine(5,arrowLengthU,0,lineLengthU);
    line_Ub.drawLine(-5,arrowLengthU,0,lineLengthU);
    line_Ub.drawText(-15,lineLengthU-5,tr("Ub"));

    QPainter line_Uc(this);
    line_Uc.setPen(QPen(QColor(255, 0, 0, 255),1));                // Uc
    line_Uc.setBrush(brush);
    line_Uc.translate(circleX,circleY);
    line_Uc.scale(scale_vale,scale_vale);
    line_Uc.rotate(-UcRotate);
    line_Uc.drawLine(0,0,0,lineLengthU);
    line_Uc.drawLine(5,arrowLengthU,0,lineLengthU);
    line_Uc.drawLine(-5,arrowLengthU,0,lineLengthU);
    line_Uc.drawText(-15,lineLengthU+15,tr("Uc"));

    QPainter line_Ia(this);
    line_Ia.setPen(QPen(QColor(255, 255, 0, 255),1));              // Ia
    line_Ia.setBrush(brush);
    line_Ia.translate(circleX,circleY);
    line_Ia.scale(scale_vale,scale_vale);
    line_Ia.rotate(-IaRotate);
    line_Ia.drawLine(0,0,0,lineLengthI);
    line_Ia.drawLine(5,arrowLengthI,0,lineLengthI);
    line_Ia.drawLine(-5,arrowLengthI,0,lineLengthI);
    line_Ia.drawText(-15,arrowLengthI-15,tr("Ia"));

    QPainter line_Ib(this);
    line_Ib.setPen(QPen(QColor(0, 255, 0, 255),1));                // Ib
    line_Ib.setBrush(brush);
    line_Ib.translate(circleX,circleY);
    line_Ib.scale(scale_vale,scale_vale);
    line_Ib.rotate(-IbRotate);
    line_Ib.drawLine(0,0,0,lineLengthI);
    line_Ib.drawLine(5,arrowLengthI,0,lineLengthI);
    line_Ib.drawLine(-5,arrowLengthI,0,lineLengthI);
    line_Ib.drawText(-15,arrowLengthI,tr("Ib"));

    QPainter line_Ic(this);
    line_Ic.setPen(QPen(QColor(255, 0, 0, 255),1));                   // Ic
    line_Ic.setBrush(brush);
    line_Ic.translate(circleX,circleY);
    line_Ic.scale(scale_vale,scale_vale);
    line_Ic.rotate(-IcRotate);
    line_Ic.drawLine(0,0,0,lineLengthI);
    line_Ic.drawLine(5,arrowLengthI,0,lineLengthI);
    line_Ic.drawLine(-5,arrowLengthI,0,lineLengthI);
    line_Ic.drawText(-15,arrowLengthI+15,tr("Ic"));
}

void PhasorPaint::setPen(QPen p)
{
    pen = p;
    update();
}

void PhasorPaint::setBrush(QBrush b)
{
    brush = b;
    update();
}



