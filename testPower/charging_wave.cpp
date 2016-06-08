/******************************************************************************
*dec:波形显示
*注:
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "testPower/RSMV_option.h"
#include <qwt_symbol.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

void MainWidget::init_ES_wave(void)
{
    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::xBottom, 0.0,3.0);
    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::xTop, 0.0,3.0);

    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::yLeft  , -150,150,150);
    ui->charging_wave_QwtPlot->setAxisScale(QwtPlot::yRight  , -150,150,150);

    ui->charging_wave_QwtPlot->enableAxis(QwtPlot::yLeft,true); //显示坐标轴
    ui->charging_wave_QwtPlot->enableAxis(QwtPlot::yRight,true);


    #if 0
    RSMV.wave_vol_grid = new QwtPlotGrid;   //设置网格         //电压
    RSMV.wave_vol_grid->setMajPen( QPen(QColor(0, 170, 255, 255), 0, Qt::SolidLine ) );
    RSMV.wave_vol_grid->enableY(true);
    RSMV.wave_vol_grid->enableX(false);
    RSMV.wave_vol_grid->attach( ui->charging_wave_QwtPlot );

    RSMV.wave_vmid_marker = new QwtPlotMarker();
    RSMV.wave_vmid_marker->setLabel( QString::number(0) );
    RSMV.wave_vmid_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom ); //AlignRight
    RSMV.wave_vmid_marker->setLineStyle( QwtPlotMarker::HLine );
    RSMV.wave_vmid_marker->setYValue( 0.0 );
    RSMV.wave_vmid_marker->setLinePen( QColor(0, 170, 255, 255));
    RSMV.wave_vmid_marker->attach(  ui->charging_wave_QwtPlot );

    RSMV.wave_vmax_marker = new QwtPlotMarker();
    RSMV.wave_vmax_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom ); //AlignRight
    RSMV.wave_vmax_marker->setLineStyle( QwtPlotMarker::HLine );
    RSMV.wave_vmax_marker->setLabel(  QString::number(100) );
    RSMV.wave_vmax_marker->setYValue( 150 );
    RSMV.wave_vmax_marker->setLinePen( QColor(0, 170, 255, 255));
    RSMV.wave_vmax_marker->attach(  ui->charging_wave_QwtPlot );

    RSMV.wave_vmin_marker = new QwtPlotMarker();
    RSMV.wave_vmin_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignTop ); //AlignRight
    RSMV.wave_vmin_marker->setLineStyle( QwtPlotMarker::HLine );
    RSMV.wave_vmin_marker->setLabel(  QString::number(-100) );
    RSMV.wave_vmin_marker->setYValue( -150 );
    RSMV.wave_vmin_marker->setLinePen( QColor(0, 170, 255, 255));
    RSMV.wave_vmin_marker->attach(  ui->charging_wave_QwtPlot );

    RSMV.wave_Ua_curve = new QwtPlotCurve("wave_Ua_curve");//设置曲线
    RSMV.wave_Ua_curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    RSMV.wave_Ua_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine,true);
    RSMV.wave_Ua_curve->setSymbol( new QwtSymbol( QwtSymbol::NoSymbol , Qt::red, QPen( Qt::red ), QSize( 10, 10 ) ) );
    RSMV.wave_Ua_curve->setStyle( QwtPlotCurve::Lines );//波形
    RSMV.wave_Ua_curve->setPen( QColor( Qt::yellow ) );//波形颜色
    RSMV.wave_Ua_curve->setCurveAttribute( QwtPlotCurve::Fitted );//拟合

    RSMV.wave_Ub_curve = new QwtPlotCurve("wave_Ub_curve");
    RSMV.wave_Ub_curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    RSMV.wave_Ub_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine,true);
    RSMV.wave_Ub_curve->setSymbol( new QwtSymbol( QwtSymbol::NoSymbol , Qt::yellow, QPen( Qt::yellow ), QSize( 5, 5 ) ) );
    RSMV.wave_Ub_curve->setStyle( QwtPlotCurve::Lines );
    RSMV.wave_Ub_curve->setPen( QColor( Qt::green ) );
    RSMV.wave_Ub_curve->setCurveAttribute( QwtPlotCurve::Fitted );

    RSMV.wave_Uc_curve = new QwtPlotCurve("wave_Uc_curve");
    RSMV.wave_Uc_curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    RSMV.wave_Uc_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine,true);
    RSMV.wave_Uc_curve->setSymbol( new QwtSymbol( QwtSymbol::NoSymbol, Qt::blue, QPen( Qt::blue ), QSize( 5, 5 ) ) );
    RSMV.wave_Uc_curve->setStyle( QwtPlotCurve::Lines );
    RSMV.wave_Uc_curve->setPen( QColor( Qt::red ) );
    RSMV.wave_Uc_curve->setCurveAttribute( QwtPlotCurve::Fitted );

    RSMV.wave_Ua_curve ->attach(ui->charging_wave_QwtPlot);
    RSMV.wave_Ub_curve ->attach(ui->charging_wave_QwtPlot);
    RSMV.wave_Uc_curve ->attach(ui->charging_wave_QwtPlot);
    #endif
}

