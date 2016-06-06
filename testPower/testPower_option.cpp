#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "testPower/RSMV_option.h"
#include <qwt_symbol.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>


#if 1
 void MainWidget::init_ESTD_wave(void)//标准偏差
 {
     //ui->ES_PE_QwtPlot->setAxisScale(QwtPlot::xBottom, 0.0,10.0);
     //ui->ES_PE_QwtPlot->setAxisScale(QwtPlot::yLeft,-10,10,5);
     //ui->ES_PE_QwtPlot->enableAxis(QwtPlot::xBottom,false);  //隐藏x标
     //ui->ES_PE_QwtPlot->enableAxis(QwtPlot::yLeft,false);  //隐藏y标

     //uiES_PE_QwtPlot

     RSMV.wave_ESTD_grid = new QwtPlotGrid;   //设置网格         //电压
     RSMV.wave_ESTD_grid->setMajPen( QPen(QColor(0,170, 255, 255), 0, Qt::SolidLine ) );
     RSMV.wave_ESTD_grid->enableY(true);
     RSMV.wave_ESTD_grid->enableX(false);
     //RSMV.wave_ESTD_grid->attach( ui->ES_PE_QwtPlot );

     RSMV.wave_ESTD_curve = new QwtPlotCurve("wave_ESTD_curve");
     RSMV.wave_ESTD_curve->setRenderHint(QwtPlotItem::RenderAntialiased);
     RSMV.wave_ESTD_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine,true);
     RSMV.wave_ESTD_curve->setSymbol( new QwtSymbol( QwtSymbol::NoSymbol, Qt::blue, QPen( Qt::blue ), QSize( 5, 5 ) ) );
     RSMV.wave_ESTD_curve->setStyle( QwtPlotCurve::Lines );
     RSMV.wave_ESTD_curve->setPen( QColor( Qt::white ) );
     RSMV.wave_ESTD_curve->setCurveAttribute( QwtPlotCurve::Fitted );

//     RSMV.wave_ESTD_curve = new QwtPlotCurve("wave_Ua_curve");//设置曲线
//     RSMV.wave_ESTD_curve->setRenderHint(QwtPlotItem::RenderAntialiased);
//     RSMV.wave_ESTD_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine,true);
//     //RSMV.wave_ESTD_curve->setStyle( QwtPlotCurve::NoCurve );
//     RSMV.wave_ESTD_curve->setStyle( QwtPlotCurve::Lines );
     QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
         QBrush( Qt::yellow ), QPen( Qt::yellow, 2 ), QSize( 3, 3 ) );
      RSMV.wave_ESTD_curve->setSymbol( symbol );


      // LeftButton for the zooming
      // MidButton for the panning
      // RightButton: zoom out by 1
      // Ctrl+RighButton: zoom out to full size

      (void) new QwtPlotMagnifier( ui->ES_PE_QwtPlot->canvas() );
      (void) new QwtPlotPanner(ui->ES_PE_QwtPlot->canvas()  );
  //鼠标放大
  #if 0
      QwtPlotZoomer* zoomer = new QwtPlotZoomer(ui->qwtPlot->canvas());
      zoomer->setRubberBandPen( QColor( Qt::black ) );
      zoomer->setTrackerPen( QColor( Qt::black ) );
      zoomer->setMousePattern( QwtEventPattern::MouseSelect2,
          Qt::RightButton, Qt::ControlModifier );
      zoomer->setMousePattern( QwtEventPattern::MouseSelect3,
          Qt::RightButton );
  #endif

    RSMV.wave_ESTD_curve ->attach(ui->ES_PE_QwtPlot);
    ui->ES_PE_QwtPlot->replot();
 }
#endif



