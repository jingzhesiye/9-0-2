#include "mainwidget.h"
#include "ui_mainwidget.h"

//KL
//CHANNAL;U1
//读取波形图数据,803r默认为256点
void MainWidget:: start_rippleWave()
{
    int sampleCnt =256;
    RSMV.wave_Ua_curve ->setRawSamples( 0,0, 0);
    RSMV.wave_Ub_curve ->setRawSamples( 0,0, 0);
    RSMV.wave_Uc_curve ->setRawSamples( 0,0, 0);

    ui->ES_wave_QwtPlot->replot();

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
    UINT16 sampleCnt = 256 ;

    ui->ripple_wave_QwtPlot->setAxisScale(QwtPlot::yLeft  ,-timeThreadTimer.KL_arrayTemp[3]*1.5,timeThreadTimer.KL_arrayTemp[3]*1.5,timeThreadTimer.KL_arrayTemp[3]*1.5);

    RSMV.wave_vmax_marker->setLabel(QString::number(timeThreadTimer.KL_arrayTemp[3]));
    RSMV.wave_vmin_marker->setLabel(QString::number(-timeThreadTimer.KL_arrayTemp[3]));

    RSMV.wave_vmax_marker->setYValue( timeThreadTimer.KL_arrayTemp[3] );
    RSMV.wave_vmin_marker->setYValue( -timeThreadTimer.KL_arrayTemp[3] );

    if( timeThreadTimer.wave_chlNum ==0)
    {
        RSMV.wave_Ua_curve ->setRawSamples( xval,timeThreadTimer.KL_axesY[0], timeThreadTimer.wave_sampleCnt);
    }
    else
    {
        RSMV.wave_Ua_curve ->setRawSamples( xval,timeThreadTimer.KL_axesY[1], timeThreadTimer.wave_sampleCnt);
    }

//    RSMV.wave_Ua_curve ->setRawSamples( xval,timeThreadTimer.KL_axesY[0], sampleCnt);
//    RSMV.wave_Ub_curve ->setRawSamples( xval,timeThreadTimer.KL_axesY[1], sampleCnt);
//    RSMV.wave_Uc_curve ->setRawSamples( xval,timeThreadTimer.KL_axesY[2], sampleCnt);

    //qDebug()<<"slt_wave_update"<<QString::number(timeThreadTimer.RSMV_arrayTemp[3]);
//    for(int i = 0; i < sampleCnt; i++ )
//    {
//        qDebug("%d",timeThreadTimer.KL_axesY[0][i]);
//    }
    ui->ripple_wave_QwtPlot->replot();
    //timeThreadTimer.mutexUpdate.unlock();
#endif


}
