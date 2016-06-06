#include "mainwidget.h"
#include "ui_mainwidget.h"


//读纹波系数
void MainWidget::start_RRF(void)
{
   timeThreadTimer.run(RRF);
}

void MainWidget::slt_RRF_update(pRRFTYPE pRRFTYPE_Temp)
{
   double  floatTemp;
   ui->RRF_ripple_TblWidget->item(0,0)->setText(QString ::number(pRRFTYPE_Temp->L1RF,'d',4));
   ui->RRF_ripple_TblWidget->item(0,1)->setText(QString ::number(pRRFTYPE_Temp->L1RA,'d',4));

   floatTemp =(float)(pRRFTYPE_Temp->L1RA)/(pRRFTYPE_Temp->L1RF);
   ui->RRF_ripple_TblWidget->item(0,2)->setText(QString ::number(floatTemp,'d',4));  //纹波基数:（纹波大小/纹波系数）

   ui->RRF_ripple_TblWidget->item(1,0)->setText(QString ::number(pRRFTYPE_Temp->L2RF,'d',4));
   ui->RRF_ripple_TblWidget->item(1,1)->setText(QString ::number(pRRFTYPE_Temp->L2RA,'d',4));
   floatTemp =(float)(pRRFTYPE_Temp->L2RA)/(pRRFTYPE_Temp->L2RF);
   ui->RRF_ripple_TblWidget->item(1,2)->setText(QString ::number(floatTemp,'d',4));  //纹波基数:（纹波大小/纹波系数）

}

