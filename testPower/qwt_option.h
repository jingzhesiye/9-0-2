#ifndef QWT_OPTION_H
#define QWT_OPTION_H
#include"qwt_plot_curve.h"
#include"qwt_plot_grid.h"
#include"qwt_plot_marker.h"

#include"QDialog"

class QWT_option : public QDialog
{
//    Q_OBJECT
public:

    QWT_option()
    {

    }

    QwtPlotGrid     *charging_QPGrid;
    QwtPlotCurve    *charging_vol_QPCurve;

    QwtPlotGrid     *charging_cur_QPGrid;
    QwtPlotCurve    *charging_cur_QPCurve;

    QwtPlotGrid     *wave_vol_grid;

    QwtPlotCurve    *charging_Ua_QPCurve;
    QwtPlotCurve    *wave_Ub_curve;
    QwtPlotCurve    *wave_Uc_curve;

    QwtPlotCurve    *charging_Ia_QPCurve;
    QwtPlotCurve    *wave_Ib_curve;
    QwtPlotCurve    *wave_Ic_curve;

    QPolygonF        vol_polygonF;//坐标点
    QPolygonF        cur_polygonF;//坐标点
    QPolygonF        PE_polygonF;//坐标点
    QPolygonF        TE_polygonF;//坐标点

    QwtPlotGrid     *PE_QPGrid;
    QwtPlotCurve    *PE_QPCurve;
    QwtPlotCurve    *TE_QPCurve;




};
#endif // QWT_OPTION_H
