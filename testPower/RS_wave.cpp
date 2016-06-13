/******************************************************************************
*dec:波形显示
*注:
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <qwt_symbol.h>


void MainWidget::init_charging_wave(void)
{
//    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::xBottom, 0.0,3.0);
//    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::xTop, 0.0,3.0);

    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::yLeft  , 0,750,250);
    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::yRight  , 0,300,100);

    ui->charging_wave_QwtPlot->enableAxis(QwtPlot::xBottom,true);
    ui->charging_wave_QwtPlot->enableAxis(QwtPlot::yLeft,true); //显示坐标轴
    ui->charging_wave_QwtPlot->enableAxis(QwtPlot::yRight,true);

    qwtOption.charging_QPGrid = new QwtPlotGrid;     //设置网格:电压
    qwtOption.charging_QPGrid->setMajPen( QPen(QColor(0, 170, 255, 255), 0, Qt::DotLine ) );
    qwtOption.charging_QPGrid->enableY(false);
    qwtOption.charging_QPGrid->enableX(false);
    qwtOption.charging_QPGrid->attach( ui->charging_wave_QwtPlot );

    qwtOption.charging_Ua_QPCurve = new QwtPlotCurve("charging_Ua_QPCurve");//设置曲线
    qwtOption.charging_Ua_QPCurve->setRenderHint(QwtPlotItem::RenderAntialiased);//线条光滑化
//  qwtOption.charging_Ua_QPCurve->setLegendAttribute(QwtPlotCurve::LegendShowLine,false);
//  qwtOption.charging_Ua_QPCurve->setSymbol( new QwtSymbol( QwtSymbol::NoSymbol , Qt::red, QPen( Qt::red ), QSize( 3, 3 ) ) );
    qwtOption.charging_Ua_QPCurve->setStyle( QwtPlotCurve::Lines );//波形
    qwtOption.charging_Ua_QPCurve->setPen( QColor( 255, 0, 0 ) );//波形颜色
//    qwtOption.charging_Ua_QPCurve->setCurveAttribute( QwtPlotCurve::Fitted );//拟合
    qwtOption.charging_Ua_QPCurve->setYAxis(QwtPlot::yLeft); //设置波形关联轴
    qwtOption.charging_Ua_QPCurve ->attach(ui->charging_wave_QwtPlot);

    QwtSymbol *symbol_1 = new QwtSymbol(QwtSymbol::NoSymbol,QBrush(QColor(255,0,0)),QPen(QColor(255,0,0),2), QSize(2,2));
    qwtOption.charging_Ua_QPCurve->setSymbol( symbol_1 );

    qwtOption.charging_Ia_QPCurve = new QwtPlotCurve("charging_Ia_QPCurve");//设置曲线
    qwtOption.charging_Ia_QPCurve->setRenderHint(QwtPlotItem::RenderAntialiased);
    qwtOption.charging_Ia_QPCurve->setStyle( QwtPlotCurve::Lines );//波形
    qwtOption.charging_Ia_QPCurve->setPen( QColor( QColor( 255, 255, 0,255) ) );//波形颜色
    qwtOption.charging_Ia_QPCurve->setYAxis(QwtPlot::yRight); //设置波形关联轴

    QwtSymbol *symbol_2 = new QwtSymbol( QwtSymbol::NoSymbol,QBrush( QColor(255,255,0)),QPen(QColor(255,255,0),2), QSize(2,2));
    qwtOption.charging_Ia_QPCurve->setSymbol( symbol_2 );

    qwtOption.charging_Ia_QPCurve ->attach(ui->charging_wave_QwtPlot);

}

void MainWidget::slt_charging_wave_update()//0:电压.1:电流
{
    qwtOption.charging_Ua_QPCurve->setSamples( qwtOption.vol_polygonF );
    qwtOption.charging_Ia_QPCurve->setSamples( qwtOption.cur_polygonF );
    ui->charging_wave_QwtPlot->replot();
    //qDebug()<<QString::number(f_Vol)<<QString::number(runTimeCal);
}

