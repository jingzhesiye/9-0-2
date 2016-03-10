#ifndef RSMV_OPTION_H
#define RSMV_OPTION_H

#include"QDialog"
#include"QMenu"
#include"QAction"
#include"qwt_plot_curve.h"
#include"qwt_plot_grid.h"
#include"qwt_plot_marker.h"
#include "QComboBox"
class ReceiveSMV : public QDialog
{
    //Q_OBJECT
public:
    ReceiveSMV()
    {

    }

    QComboBox       *ptl_manufter_cbbox;                //厂    家
    QComboBox       *ptl_mac_cbbox;                     //mac
    QComboBox       *ptl_smvType_cbbox;                 //smv类型
    QComboBox       *ptl_asduNum_cbbox;                 //ASDU数目
    QComboBox       *ptl_sampleCnt_cbbox;               //采样点数目

    QMenu           *rms_mode_menu;
    QAction         *rms_rms_action;                          //有效值
    QAction         *rms_wave_action;                         //波形图
    QAction         *rms_phasor_action;                       //相量图
    QAction         *rms_full_action;                         //完整性
    QAction         *rms_power_action;                        //功  率
    QAction         *rms_straggling_action;                   //离散度
    QAction         *rms_harmonic_action;                     //谐波显示
    QAction         *rms_analysis_action;                     //协议解析
    QAction         *rms_waveall_action;                      //全帧解析
    QAction         *rms_packetcal_action;                    //报文统计

    QwtPlotGrid     *wave_ESTD_grid;
    QwtPlotCurve    *wave_ESTD_curve;


    QwtPlotGrid     *wave_vol_grid;
    QwtPlotMarker   *wave_vmid_marker;
    QwtPlotMarker   *wave_vmax_marker;
    QwtPlotMarker   *wave_vmin_marker;

    QwtPlotGrid     *wave_cur_grid;
    QwtPlotMarker   *wave_cmid_marker;
    QwtPlotMarker   *wave_cmax_marker;
    QwtPlotMarker   *wave_cmin_marker;

    QwtPlotCurve    *wave_Ua_curve;
    QwtPlotCurve    *wave_Ub_curve;
    QwtPlotCurve    *wave_Uc_curve;

    QwtPlotCurve    *wave_Ia_curve;
    QwtPlotCurve    *wave_Ib_curve;
    QwtPlotCurve    *wave_Ic_curve;


    QwtPlotCurve    *waveall_curve_1;
    QwtPlotCurve    *waveall_curve_2;
    QwtPlotCurve    *waveall_curve_3;

    QwtPlotGrid     *waveall_grid_1;
    QwtPlotGrid     *waveall_grid_2;
    QwtPlotGrid     *waveall_grid_3;


    QMenu           *full_ctl_menu;
    QAction         *full_start_action;
    QAction         *full_stop_action;
    QAction         *full_save_action;

    QwtPlotGrid     *harmonic_grid_1 ;

    QMenu           *straggling_ctl_menu;
    QAction         *straggling_start_action;
    QAction         *straggling_stop_action;
    QAction         *straggling_save_action;
};

#endif // RSMV_OPTION_H
