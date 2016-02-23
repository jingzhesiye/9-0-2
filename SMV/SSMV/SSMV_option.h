#ifndef SSMV_OPTION_H
#define SSMV_OPTION_H
#include"QDialog"
#include"QMenu"
#include"QAction"
#include"QComboBox"
#include"qwt_plot_grid.h"

class SendSMV : public QDialog
{
    Q_OBJECT

public:
    void init_option();


public:
    SendSMV();

    QMenu           *rms_mode_menu ;
    QAction         *rms_harmonic_action;
    QAction         *rms_rms_action;

    QMenu           *rms_set_menu ;
    QAction         *rms_loss_action;
    QAction         *rms_timeSyn_action;

    QMenu           *rms_show_menu;
    QAction         *rms_wave_action;
    QAction         *rms_phasor_action;

    QwtPlotGrid     *harmonic_grid;

};

#endif // SSMV_OPTION_H
