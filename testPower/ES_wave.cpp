/******************************************************************************
*dec:波形显示
*注:串口读取耗时间，6个通道大概需要5秒
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
    ui->ES_wave_QwtPlot->setAxisScale(QwtPlot::xBottom, 0.0,3.0);
    ui->ES_wave_QwtPlot->setAxisScale(QwtPlot::yLeft  , -150,150,150);
    ui->ES_wave_QwtPlot->enableAxis(QwtPlot::xBottom,false);  //隐藏x标
    ui->ES_wave_QwtPlot->enableAxis(QwtPlot::yLeft,false);  //隐藏y标

    RSMV.wave_vol_grid = new QwtPlotGrid;   //设置网格         //电压
    RSMV.wave_vol_grid->setMajPen( QPen(QColor(0, 170, 255, 255), 0, Qt::SolidLine ) );
    RSMV.wave_vol_grid->enableY(true);
    RSMV.wave_vol_grid->enableX(false);
    RSMV.wave_vol_grid->attach( ui->ES_wave_QwtPlot );

    RSMV.wave_vmid_marker = new QwtPlotMarker();
    RSMV.wave_vmid_marker->setLabel( QString::number(0) );
    RSMV.wave_vmid_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom ); //AlignRight
    RSMV.wave_vmid_marker->setLineStyle( QwtPlotMarker::HLine );
    RSMV.wave_vmid_marker->setYValue( 0.0 );
    RSMV.wave_vmid_marker->setLinePen( QColor(0, 170, 255, 255));
    RSMV.wave_vmid_marker->attach(  ui->ES_wave_QwtPlot );

    RSMV.wave_vmax_marker = new QwtPlotMarker();
    RSMV.wave_vmax_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom ); //AlignRight
    RSMV.wave_vmax_marker->setLineStyle( QwtPlotMarker::HLine );
    RSMV.wave_vmax_marker->setLabel(  QString::number(100) );
    RSMV.wave_vmax_marker->setYValue( 150 );
    RSMV.wave_vmax_marker->setLinePen( QColor(0, 170, 255, 255));
    RSMV.wave_vmax_marker->attach(  ui->ES_wave_QwtPlot );

    RSMV.wave_vmin_marker = new QwtPlotMarker();
    RSMV.wave_vmin_marker->setLabelAlignment( Qt::AlignLeft | Qt::AlignTop ); //AlignRight
    RSMV.wave_vmin_marker->setLineStyle( QwtPlotMarker::HLine );
    RSMV.wave_vmin_marker->setLabel(  QString::number(-100) );
    RSMV.wave_vmin_marker->setYValue( -150 );
    RSMV.wave_vmin_marker->setLinePen( QColor(0, 170, 255, 255));
    RSMV.wave_vmin_marker->attach(  ui->ES_wave_QwtPlot );

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

    RSMV.wave_Ua_curve ->attach(ui->ES_wave_QwtPlot);
    RSMV.wave_Ub_curve ->attach(ui->ES_wave_QwtPlot);
    RSMV.wave_Uc_curve ->attach(ui->ES_wave_QwtPlot);
}

void MainWidget:: startRD()
{
    timeThreadTimer.run(RD);
//    qDebug()<<"111111111111111111111startRD";
}

void MainWidget:: startRS()
{
    timeThreadTimer.run(RS);
//    qDebug()<<"111111111111111111111startRD";
}


//读取测量值ME
void MainWidget:: startME()
{
    timeThreadTimer.run(ME);
}

//读取波形图数据,803r默认为256点
void MainWidget:: startWAVE()
{
    RSMV.wave_Ua_curve ->setRawSamples( 0,0, 0);
    RSMV.wave_Ub_curve ->setRawSamples( 0,0, 0);
    RSMV.wave_Uc_curve ->setRawSamples( 0,0, 0);

    ui->ES_wave_QwtPlot->replot();


    UINT16 sampleCnt = 256 ;                   //采样数目
    timeThreadTimer.RSMV_wave_setArg(7,sampleCnt);                 //56 =111 000 =456 通道

    for(UINT16 i = 0; i < sampleCnt; i++ )                                    //X坐标的值
    {
        xval[i] = FLOAT64( i ) * 3.0 / FLOAT64( sampleCnt - 1 );
    }

    timeThreadTimer.run(RSMV_WAVE);
}


void MainWidget::slt_RSMV_wave_update( )
{
   // qDebug()<<"slt_RSMV_wave_update";
#if 1
    UINT16 sampleCnt = 256 ;

    ui->ES_wave_QwtPlot->setAxisScale(QwtPlot::yLeft  ,-timeThreadTimer.RSMV_arrayTemp[3]*1.5,timeThreadTimer.RSMV_arrayTemp[3]*1.5,timeThreadTimer.RSMV_arrayTemp[3]*1.5);

    RSMV.wave_vmax_marker->setLabel(QString::number(timeThreadTimer.RSMV_arrayTemp[3]));
    RSMV.wave_vmin_marker->setLabel(QString::number(-timeThreadTimer.RSMV_arrayTemp[3]));

    RSMV.wave_vmax_marker->setYValue( timeThreadTimer.RSMV_arrayTemp[3] );
    RSMV.wave_vmin_marker->setYValue( -timeThreadTimer.RSMV_arrayTemp[3] );

    RSMV.wave_Ua_curve ->setRawSamples( xval,timeThreadTimer.RSMV_wave_axesY[0], sampleCnt);
    RSMV.wave_Ub_curve ->setRawSamples( xval,timeThreadTimer.RSMV_wave_axesY[1], sampleCnt);
    RSMV.wave_Uc_curve ->setRawSamples( xval,timeThreadTimer.RSMV_wave_axesY[2], sampleCnt);

    //qDebug()<<"slt_RSMV_wave_update"<<QString::number(timeThreadTimer.RSMV_arrayTemp[3]);
//    for(int i = 0; i < sampleCnt; i++ )
//    {
//        qDebug("%d",timeThreadTimer.RSMV_wave_axesY[0][i]);
//    }
    ui->ES_wave_QwtPlot->replot();
    //timeThreadTimer.mutexUpdate.unlock();
#endif


}

