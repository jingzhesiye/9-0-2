#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <qwt_symbol.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

//纹波测试
void MainWidget::init_ripple_wave(void)
{
    ui->ripple_wave_QwtPlot->setAxisScale(QwtPlot::xBottom, 0.0,3.0);
    ui->ripple_wave_QwtPlot->setAxisScale(QwtPlot::yLeft  , -150,150,150);
    ui->ripple_wave_QwtPlot->enableAxis(QwtPlot::xBottom,false);  //隐藏x标
    ui->ripple_wave_QwtPlot->enableAxis(QwtPlot::yLeft,false);  //隐藏y标

    qwtOption.ripple_QPGrid = new QwtPlotGrid;   //设置网格         //电压
    qwtOption.ripple_QPGrid->setMajPen( QPen(QColor(0, 170, 255, 255), 0, Qt::SolidLine ) );
    qwtOption.ripple_QPGrid->enableY(true);
    qwtOption.ripple_QPGrid->enableX(false);
    qwtOption.ripple_QPGrid->attach( ui->ripple_wave_QwtPlot );

    qwtOption.ripple_vmid_marker = new QwtPlotMarker();
    qwtOption.ripple_vmid_marker->setLabel( QString::number(0) );
    qwtOption.ripple_vmid_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom ); //AlignRight
    qwtOption.ripple_vmid_marker->setLineStyle( QwtPlotMarker::HLine );
    qwtOption.ripple_vmid_marker->setYValue( 0.0 );
    qwtOption.ripple_vmid_marker->setLinePen( QColor(0, 170, 255, 255));
    qwtOption.ripple_vmid_marker->attach(  ui->ripple_wave_QwtPlot );

    qwtOption.ripple_vmax_marker = new QwtPlotMarker();
    qwtOption.ripple_vmax_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom ); //AlignRight
    qwtOption.ripple_vmax_marker->setLineStyle( QwtPlotMarker::HLine );
    qwtOption.ripple_vmax_marker->setLabel(  QString::number(100) );
    qwtOption.ripple_vmax_marker->setYValue( 150 );
    qwtOption.ripple_vmax_marker->setLinePen( QColor(0, 170, 255, 255));
    qwtOption.ripple_vmax_marker->attach(  ui->ripple_wave_QwtPlot );

    qwtOption.ripple_vmin_marker = new QwtPlotMarker();
    qwtOption.ripple_vmin_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignTop ); //AlignRight
    qwtOption.ripple_vmin_marker->setLineStyle( QwtPlotMarker::HLine );
    qwtOption.ripple_vmin_marker->setLabel(  QString::number(-100) );
    qwtOption.ripple_vmin_marker->setYValue( -150 );
    qwtOption.ripple_vmin_marker->setLinePen( QColor(0, 170, 255, 255));
    qwtOption.ripple_vmin_marker->attach(  ui->ripple_wave_QwtPlot );

    qwtOption.ripple_Ua_QPCurve = new QwtPlotCurve("wave_Ua_curve");//设置曲线
    qwtOption.ripple_Ua_QPCurve->setRenderHint(QwtPlotItem::RenderAntialiased);
    qwtOption.ripple_Ua_QPCurve->setLegendAttribute(QwtPlotCurve::LegendShowLine,true);
    qwtOption.ripple_Ua_QPCurve->setSymbol( new QwtSymbol( QwtSymbol::NoSymbol , Qt::red, QPen( Qt::red ), QSize( 10, 10 ) ) );
    qwtOption.ripple_Ua_QPCurve->setStyle( QwtPlotCurve::Lines );//波形
    qwtOption.ripple_Ua_QPCurve->setPen( QColor( Qt::yellow ) );//波形颜色
    qwtOption.ripple_Ua_QPCurve->setCurveAttribute( QwtPlotCurve::Fitted );//拟合

    qwtOption.ripple_Ua_QPCurve ->attach(ui->ripple_wave_QwtPlot);
}

//KL
//CHANNAL;U1
//读取波形图数据,803r默认为256点
void MainWidget:: start_rippleWave()
{
    int sampleCnt =256;
    qwtOption.ripple_Ua_QPCurve ->setRawSamples( 0,0, 0);

    ui->ripple_wave_QwtPlot->replot();

    timeThreadTimer.wave_chlNum =ui->RRF_ripple_chl_CbBox->currentIndex(); //0电压 1电流

    timeThreadTimer.wave_sampleCnt = sampleCnt;                       //采样数目

    for(UINT16 i = 0; i < sampleCnt; i++ )                                 //X坐标的值
    {
        xval[i] = FLOAT64( i ) * 3.0 / FLOAT64( sampleCnt - 1 );
    }

    timeThreadTimer.run(KL);
}

void MainWidget::slt_wave_update( )
{
   // qDebug()<<"slt_wave_update";
#if 1

    ui->ripple_wave_QwtPlot->setAxisScale(QwtPlot::yLeft  ,-timeThreadTimer.KL_arrayTemp[3]*1.5,timeThreadTimer.KL_arrayTemp[3]*1.5,timeThreadTimer.KL_arrayTemp[3]*1.5);

    qwtOption.ripple_vmax_marker->setLabel(QString::number(timeThreadTimer.KL_arrayTemp[3]));
    qwtOption.ripple_vmin_marker->setLabel(QString::number(-timeThreadTimer.KL_arrayTemp[3]));

    qwtOption.ripple_vmax_marker->setYValue( timeThreadTimer.KL_arrayTemp[3] );
    qwtOption.ripple_vmin_marker->setYValue( -timeThreadTimer.KL_arrayTemp[3] );

    if( timeThreadTimer.wave_chlNum ==0)
    {
       qwtOption.ripple_Ua_QPCurve ->setRawSamples( xval,timeThreadTimer.KL_axesY[0], timeThreadTimer.wave_sampleCnt);
    }
    else
    {
       qwtOption.ripple_Ua_QPCurve ->setRawSamples( xval,timeThreadTimer.KL_axesY[1], timeThreadTimer.wave_sampleCnt);
    }

    ui->ripple_wave_QwtPlot->replot();
#endif
}
