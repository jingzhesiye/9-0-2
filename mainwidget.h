#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QToolButton"
#include "stdafx.h"
#include "xl618.h"

#include "ui_mainwidget.h"
#include "thread/timeThread.h"
#include "SMV/RSMV/RSMV_initPhasor.h"
#include "SMV/RSMV/RSMV_option.h"
#include "QTimer"
#define _WIN_

class QextSerialPort;
class Histogram;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    
    void  show_MsBox(QString strMessages,int msec);//提示框
    void  set_TblWdiget_Header(QTableWidget *TblWiget,bool H,bool V);
    void  remove_TblWdiget_Row(QTableWidget *TblWiget);

    void  init_serPort();                //初始化串口界面
    void  init_timeThreadTimer_connect();
    void  write_ini(QString path,QString arg);
    void  read_ini();
private:
    Ui::MainWidget *ui;

//侧边栏
    void  init_sideBar();
    QList<QToolButton *> sideBar_BtnList;
    QList<QPushButton *> serPort_shorCut_list;
    bool eventFilter(QObject *target,QEvent *event);

    QTimer *elapseTimer;
    QTime   elapseTime;   //运行时间
    int   elapseTimeCal;
    timeThread        timeThreadTimer ;
    PhasorPaint       *RSMV_phasorPaint;
    ReceiveSMV        RSMV;
    Histogram         *RSMV_harmonic_histogram;
    QPolygonF         RSMV_ESTD_PolygonF;//坐标点

    double            xval[300];  //波形图目前这样设置不会有问题


    void init_RSMV_wave();
    void init_ESTD_wave();
    void init_RSMV_harmonic();
    void init_elapseTime();//定时器时间
    void set_RSMV_harmonic_histogram( uint numValues, const double *values);

    void init_rms_harmonic();

    void startRD();
    void startRS();
    void startME();
    void startWAVE();
    void startHR();
    void startES();
    void startESTD();
    void startELAPSETIME();
    void startENERGY_PUL();
    void startENERGY_STD();
    void clean_stackedWidgetIndex1();

    QString getTemplatePath();
    void fillReplaceDocStructList(replaceDocTypeList *list, QString searchStr, QString replaceStr) ;
    void fillReplaceDocTypeList( QTableWidget *modelDiscriptor, replaceDocTypeList *replaceDocTypeList_Data);

private slots:
    void changeButtonStatus();
    void slot_serPort_shorCut_PsBtn();

    //串口
    void  slot_serPort_open();
    void  slot_serPort_close();

    void  slt_serPort_RecDataToUI(const QByteArray &,int);

    void on_serPort_CleanRec_PsBtn_clicked();
    void on_serPort_CleanSend_PsBtn_clicked();
    void on_serPort_Send_PsBtn_clicked();

    void slt_RD_update(pRDTYPE);
    void slt_RS_update(pRSTYPE);

    void slt_RSMV_rms_update(pMETYPE);
    void slt_RSMV_ES_update(pESTYPE );
    void slt_RSMV_ESTD_update(pESTDTYPE );
    void slt_ENERGY_PUL_update(pPULSEPOW );
    void slt_ENERGY_STD_update(pPULSEPOW );
    void slt_RSMV_wave_update();
    void slt_RSMV_harmonic_update();

    void slt_elapseTimer_timeout();
    void on_start_PsBtn_clicked(bool checked);


    void on_RSMV_Harmonic_Phase_CbBox_activated(int index);
    void on_RSMV_Harmonic_Times_CbBox_activated(int index);
    void on_RSMV_Harmonic_Range_HSlider_valueChanged(int value);

    void on_serPort_write_SP_PsBtn_clicked();
    void on_serPort_read_SP_PsBtn_clicked();
    void on_RSMV_zoomOut_PsBtn_clicked();
    void on_RSMV_zoomIn_PsBtn_clicked();
    void on_RSMV_wave_CkBox_clicked(bool checked);
    void on_serPort_EVT_PsBtn_clicked();
    void on_serPort_portName_CbBox_activated(int index);
    void on_serPort_dataBit_CbBox_activated(int index);
    void on_serPort_baudRate_CbBox_activated(int index);
    void on_serPort_stopBit_CbBox_activated(int index);
    void on_serPort_parity_CbBox_activated(int index);
    void on_serPort_flowCtl_CbBox_activated(int index);
    void on_serPort_METERCONST_LnEdit_textChanged(const QString &arg1);
    void on_serPort_CONST_LnEdit_textChanged(const QString &arg1);
    void on_serPort_CHECKNUM_LnEdit_textChanged(const QString &arg1);
    void on_serPort_CHECKTYPE_CbBox_activated(int index);
    void on_serPort_VR_CbBox_activated(int index);
    void on_serPort_CR_CbBox_activated(int index);
    void on_RSMV_energy_from_PsBtn_clicked();
    void on_RSMV_clearFrom_PsBtn_clicked();
    void on_RSMV_buildFrom_PsBtn_clicked();

    void on_RSMV_readFrom_PsBtn_clicked();
    void on_RSMV_keyBoard_PsBtn_clicked();
    void on_RSMV_saveFormMsg_PsBtn_clicked();

};

#endif // WIDGET_H
