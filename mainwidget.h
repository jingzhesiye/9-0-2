#ifndef WIDGET_H
#define WIDGET_H
#include "ui_mainwidget.h"
#include "thread/timeThread.h"
#include"testPower/RSMV_option.h"
#include"testPower/qwt_option.h"
#include "xl618.h"
#include <QWidget>
#include "QToolButton"
#include "QTimer"

class QextSerialPort;


namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    
    void  show_MsBox(QString strMessages,int msec);                        //提示框
    void  set_TblWdiget_Header(QTableWidget *TblWiget,bool H,bool V);
    void  remove_TblWdiget_Row(QTableWidget *TblWiget);

    void  init_serPort();                                                  //初始化串口界面
    void  init_timeThreadTimer_connect();
    void  setColumnWidth();
    void  write_ini(QString path,QString arg);
    void  read_ini();
private:
    Ui::MainWidget *ui;

//侧边栏
    void  init_sideBar();
    QList<QToolButton *> sideBar_BtnList;
    QList<QPushButton *> serPort_shorCut_list;
    bool eventFilter(QObject *target,QEvent *event);

    QTimer *runTimer;
    QTime   runTime;   //运行时间
    int     runTimeCal;

    timeThread        timeThreadTimer ;
    QPolygonF         ESTD_PolygonF;//坐标点

    double            xval[300];  //波形图目前这样设置不会有问题


    void init_charging_wave();
    void charging_wave_update();
    void init_ripple_wave();
    void init_PE_wave();
    bool is_MT_semiAutomatic (bool);
    void Qt_delay(int msec);
    QString Qt_f_to_string_6(float a );
    void init_runTime();//定时器时间
    void init_rms_harmonic();

    void start_RD();
    void start_RS();
    void start_ME();
    void start_rippleWave();
    void startES();
    void startESTD();
    void start_RRF();
    void start_runTime();
    void startENERGY_PUL();
    void startENERGY_STD();
    void clean_main_SkWidget_1();
    void clean_main_SkWidget_2();

    QString getTemplatePath();
    void fillReplaceDocStructList(replaceDocTypeList *list, QString searchStr, QString replaceStr) ;
    void fill_formInfo( QTableWidget *modelDiscriptor, replaceDocTypeList *replaceDocTypeList_Data);

    void fill_form_time( QTableWidget *from_information_TbWidget, replaceDocTypeList *replaceDocTypeList_Data);
    void fill_form_intuit(QString str, replaceDocTypeList *replaceDocTypeList_Data);
    void fill_form_overallClu( QString str, replaceDocTypeList *replaceDocTypeList_Data);

    void fill_form_operating( QTableWidget *temp_TbWidget, replaceDocTypeList *replaceDocTypeList_Data);
    void fill_form_load( QTableWidget *temp_TbWidget, replaceDocTypeList *replaceDocTypeList_Data);

    void insert_form_time();
    void insert_form_operating();
    void insert_form_load();
    void fill_form_time();

signals:
    void sig_charging_wave_update();
    void sig_PE_wave_update();
private slots:
    void slt_charging_wave_update();
    void slt_PE_wave_update();
    void changeButtonStatus();
    void slot_serPort_shorCut_PsBtn();

    //串口
    void slot_serPort_open();
    void slot_serPort_close();
    void slt_serPort_RecDataToUI(const QByteArray &,int);
    void on_serPort_CleanRec_PsBtn_clicked();
    void on_serPort_CleanSend_PsBtn_clicked();
    void on_serPort_Send_PsBtn_clicked();

    void slt_battery_update(QString str);
    void slt_RD_update(pRDTYPE);
    void slt_RS_update(pRSTYPE);

    void slt_ME_update(pMETYPE);
    void slt_ES_update(pESTYPE );
    void slt_ENERGY_PUL_update(pPULSEPOW );
    void slt_ENERGY_STD_update(pPULSEPOW );
    void slt_wave_update();

    void slt_RRF_update(pRRFTYPE);

    void slt_runTimer_timeout();
    void on_start_PsBtn_clicked(bool checked);

    void on_serPort_write_SP_PsBtn_clicked();
    void on_serPort_read_SP_PsBtn_clicked();

    void on_serPort_portName_CbBox_activated(int index);
    void on_serPort_dataBit_CbBox_activated(int index);
    void on_serPort_baudRate_CbBox_activated(int index);
    void on_serPort_stopBit_CbBox_activated(int index);
    void on_serPort_parity_CbBox_activated(int index);
    void on_serPort_flowCtl_CbBox_activated(int index);

    void on_keyBoard_PsBtn_clicked();

    void on_ES_insertForm_PsBtn_clicked();

    void on_from_clearFrom_PsBtn_clicked();

    void on_from_buildForm_PsBtn_clicked();

    void on_intuit_CkBox_clicked(bool checked);

    void on_overallClu_CkBox_clicked(bool checked);


    void on_serPort_BVS_CbBox_activated(int index);

    void on_ES_standard_TblWidget_cellChanged(int row, int column);

    void on_error_wave_zoomOut_PsBtn_clicked();

    void on_error_wave_zoomIn_PsBtn_clicked();

private:
    QComboBox       *SP_chargeType_cbbox;
    QComboBox       *SP_loadType_cbbox;
    QComboBox       *SP_measureType_cbbox;

    ReceiveSMV  RSMV;
    OVERARLL_CONC   overAll_conc;
    QWT_option   qwtOption;

};

#endif // WIDGET_H
