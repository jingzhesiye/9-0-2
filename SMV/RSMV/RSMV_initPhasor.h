#ifndef RSMV_INITPHASOR_H
#define RSMV_INITPHASOR_H
#include <QWidget>
#include"QPainter"
#include"QPen"
#include"QBrush"
class PhasorPaint : public QWidget
{
   // Q_OBJECT
public:
    explicit PhasorPaint(QWidget *parent = 0);

    void setPen(QPen);
    void setBrush(QBrush);

    void  updatePhasor();
    QBrush brush;
    QPen pen;

    bool  isUpdatePhasor;


    float UaRotate;
    float UbRotate;
    float UcRotate;

    float IaRotate;
    float IbRotate;
    float IcRotate;
protected:
     void paintEvent ( QPaintEvent * event );
private:
     //QPainter line_x(this);

};

#endif // RSMV_INITPHASOR_H
