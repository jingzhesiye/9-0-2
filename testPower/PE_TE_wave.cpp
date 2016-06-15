#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <qwt_symbol.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include "QWheelEvent"

// LeftButton for the zooming MidButton for the panning RightButton: zoom out by 1  Ctrl+RighButton: zoom out to full size

 void MainWidget::init_PE_wave(void)
 {

     ui->ES_TbWidget->setCurrentIndex(0);
//   ui->error_wave_QwtPlot->setAxisScale(QwtPlot::xBottom, 0.0,10.0);
//   ui->error_wave_QwtPlot->setAxisScale(QwtPlot::yLeft,-10,10,5);
//   ui->error_wave_QwtPlot->setAxisScale(QwtPlot::yRight,-10,10,5);
//   ui->error_wave_QwtPlot->enableAxis(QwtPlot::xBottom,false);  //隐藏x标
//   ui->error_wave_QwtPlot->enableAxis(QwtPlot::yLeft,false);  //隐藏y标

     ui->error_wave_QwtPlot->enableAxis(QwtPlot::yLeft,true);
     ui->error_wave_QwtPlot->enableAxis(QwtPlot::yRight,true);

     qwtOption.PE_QPGrid = new QwtPlotGrid;   //设置网格         //电压
     qwtOption.PE_QPGrid->setMajPen( QPen(QColor(0,170, 255, 255), 0, Qt::SolidLine ) );
     qwtOption.PE_QPGrid->enableY(true);
     qwtOption.PE_QPGrid->enableX(false);
     //RSMV.wave_ESTD_grid->attach( ui->error_wave_QwtPlot );

     qwtOption.PE_QPCurve = new QwtPlotCurve("PE_QPCurve");
     qwtOption.PE_QPCurve->setRenderHint(QwtPlotItem::RenderAntialiased);
     qwtOption.PE_QPCurve->setStyle( QwtPlotCurve::Lines );
     qwtOption.PE_QPCurve->setPen( QColor( 255, 0, 0 ) );
     qwtOption.PE_QPCurve->setYAxis(QwtPlot::yLeft); //设置波形关联轴


     QwtSymbol *symbol_1 = new QwtSymbol( QwtSymbol::NoSymbol,QBrush( QColor( 255, 0, 0 ) ), QPen(  QColor( 255, 0, 0 ), 2 ), QSize( 2, 2 ) );
     qwtOption.PE_QPCurve->setSymbol( symbol_1 );

     qwtOption.TE_QPCurve = new QwtPlotCurve("TE_QPCurve");
     qwtOption.TE_QPCurve->setRenderHint(QwtPlotItem::RenderAntialiased);
     qwtOption.TE_QPCurve->setStyle( QwtPlotCurve::Lines );
     qwtOption.TE_QPCurve->setPen( QColor( 255, 255, 0 ) );
     qwtOption.TE_QPCurve->setYAxis(QwtPlot::yRight); //设置波形关联轴

     QwtSymbol *symbol_2 = new QwtSymbol( QwtSymbol::NoSymbol,QBrush( QColor( 255, 255, 0 ) ), QPen(  QColor( 255, 255, 0 ), 2 ), QSize( 2, 2 ) );
     qwtOption.TE_QPCurve->setSymbol( symbol_2 );

    (void) new QwtPlotMagnifier( ui->error_wave_QwtPlot->canvas() );
    (void) new QwtPlotPanner(ui->error_wave_QwtPlot->canvas()  );

  //鼠标滚轮放大
  #if 0
      QwtPlotZoomer* zoomer = new QwtPlotZoomer(ui->qwtPlot->canvas());
      zoomer->setRubberBandPen( QColor( Qt::black ) );
      zoomer->setTrackerPen( QColor( Qt::black ) );
      zoomer->setMousePattern( QwtEventPattern::MouseSelect2,
          Qt::RightButton, Qt::ControlModifier );
      zoomer->setMousePattern( QwtEventPattern::MouseSelect3,
          Qt::RightButton );
  #endif

    qwtOption.PE_QPCurve ->attach(ui->error_wave_QwtPlot);
    qwtOption.TE_QPCurve ->attach(ui->error_wave_QwtPlot);
    ui->error_wave_QwtPlot->replot();
 }

 void MainWidget::slt_PE_wave_update()//电能，时钟
 {
     if(SP_measureType_cbbox->currentIndex() == 0)
     {
         qwtOption.PE_QPCurve->setSamples( qwtOption.PE_polygonF );
     }

     qwtOption.PE_QPCurve->setSamples( qwtOption.PE_polygonF );
     qwtOption.TE_QPCurve->setSamples( qwtOption.TE_polygonF );
     ui->error_wave_QwtPlot->replot();
 }

 void MainWidget::on_error_wave_zoomOut_PsBtn_clicked()
 {
     QWheelEvent event(QPoint(150, 80),-120, Qt::LeftButton, Qt::NoModifier);
     QApplication::sendEvent( ui->error_wave_QwtPlot->canvas(), &event);
 }

 void MainWidget::on_error_wave_zoomIn_PsBtn_clicked()
 {
     QWheelEvent event(QPoint(150, 80),120, Qt::LeftButton, Qt::NoModifier);
     QApplication::sendEvent( ui->error_wave_QwtPlot->canvas(), &event);
 }
