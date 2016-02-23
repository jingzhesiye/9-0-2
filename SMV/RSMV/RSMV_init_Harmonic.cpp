#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "SMV/RSMV/RSMV_initHarmonic.h"

void Histogram::setColor( const QColor &symbolColor )
{
    QColor color = symbolColor;
    color.setAlpha( 180 );

    setPen( QPen( Qt::black ) );
    setBrush( QBrush( color ) );

    QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
    symbol->setFrameStyle( QwtColumnSymbol::Raised );
    symbol->setLineWidth( 2 );
    symbol->setPalette( QPalette( color ) );
    setSymbol( symbol );
}

void Histogram::setValues( uint numValues, const double *values )
{
    QVector<QwtIntervalSample> samples( numValues);
    for ( uint i = 0; i < numValues; i++ )
    {
        QwtInterval interval( double( i ), i+ 0.8 );//间隔
        interval.setBorderFlags( QwtInterval::ExcludeMaximum );
        samples[i] = QwtIntervalSample( values[i], interval );
    }

    setData( new QwtIntervalSeriesData( samples ) );

}

void MainWidget::init_RSMV_harmonic()
{
    ui->RSMV_Harmonic_TblWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->RSMV_Harmonic_QwtPlot->setAxisScale(QwtPlot::xBottom, 0,40);
    ui->RSMV_Harmonic_QwtPlot->setAxisScale(QwtPlot::yLeft  , 0,100);

    //ui->RSMV_Harmonic_QwtPlot->setPalette();
    RSMV.harmonic_grid_1 = new QwtPlotGrid;
    RSMV.harmonic_grid_1->enableX( false );
    RSMV.harmonic_grid_1->enableY( true );
    RSMV.harmonic_grid_1->enableXMin( false );
    RSMV.harmonic_grid_1->enableYMin( false );
    RSMV.harmonic_grid_1->setMajPen( QPen( QColor(0, 170, 255, 255), 0, Qt::DotLine ) );
    RSMV.harmonic_grid_1->attach( ui->RSMV_Harmonic_QwtPlot );
//stop:0 rgba(7, 85, 75, 255),
//stop:1 rgba(18, 220, 200, 255));
    const double juneValues[40]={0};
    RSMV_harmonic_histogram = new Histogram( "harmonic",  QColor(0, 170, 255) );
    RSMV_harmonic_histogram->setValues(sizeof( juneValues ) / sizeof( double ), juneValues );
    RSMV_harmonic_histogram->attach(  ui->RSMV_Harmonic_QwtPlot );
}

void MainWidget::set_RSMV_harmonic_histogram( uint numValues, const double *values)
{
    RSMV_harmonic_histogram->setValues(numValues, values );
    ui->RSMV_Harmonic_QwtPlot->replot();
}

//只能在这里初始??


