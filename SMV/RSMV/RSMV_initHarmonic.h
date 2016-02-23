#ifndef RSMV_INITHARMONIC_H
#define RSMV_INITHARMONIC_H

#include <stdlib.h>
#include <qpen.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>

class Histogram: public QwtPlotHistogram
{
public:
    Histogram( const QString &, const QColor & );
    void setColor( const QColor & );
    void setValues( uint numValues, const double * );
};

Histogram::Histogram( const QString &title, const QColor &symbolColor ):
    QwtPlotHistogram( title )
{
    setStyle( QwtPlotHistogram::Columns );
    setColor( symbolColor );
};

#endif // RSMV_INITHARMONIC_H
