/******************************************************************************
*界面 : 丢帧
*功能 : 9-1，9-2 发送丢帧数据
*人员 : jingzhesiye@163.com
*时间 : 2014.3.10
*******************************************************************************/
#include "mainwidget.h"
#include "ui_mainwidget.h"

/*******************************************************************************************************
*Function:     丢帧设置
*Description:  ratio：丢帧率；
               mode：0:随机发生,1:一个周波内连续发生；
               calcutype：0:插值1:丢包前数据 2:丢包后数据
               isON:启动?
*******************************************************************************************************/
void MainWidget::slt_SSMV_frameloss(float ratio,char mode ,char calcutype, char isON)
{
    int noEnd=0;

    pSETFRAMERR_TYPE   pSETFRAMERR_TYPE_Temp =NULL;

    if((pSETFRAMERR_TYPE_Temp=(pSETFRAMERR_TYPE)calloc(1,sizeof(SETFRAMERR_TYPE)))==NULL)
    {
        free(pSETFRAMERR_TYPE_Temp);
        pSETFRAMERR_TYPE_Temp=NULL;
        return ;
    }

    if(isON)
    {
       pSETFRAMERR_TYPE_Temp->ratio=ratio;
       pSETFRAMERR_TYPE_Temp->mode=mode;
       pSETFRAMERR_TYPE_Temp->calcutype=calcutype;
       pSETFRAMERR_TYPE_Temp->onoff=isON;

      do{
           if(theDevice->setFramerr(pSETFRAMERR_TYPE_Temp) == ERR_RIGHT ) //丢帧启动
           {
               showInformationBox("丢帧启动");
               noEnd=0;
           }
           else
           {
               noEnd ++;
               if(noEnd==5)
               {
                   showInformationBox("通信异常");
                   free(pSETFRAMERR_TYPE_Temp);
                   pSETFRAMERR_TYPE_Temp=NULL;
                   return;
               }
           }
         }  while(noEnd);
    }
    else
    {
       do{
            if(theDevice->setFramerr(pSETFRAMERR_TYPE_Temp) == ERR_RIGHT ) //丢帧停止
            {
                showInformationBox("停止丢帧");
                noEnd=0;
            }
            else
            {
                noEnd ++;
                if(noEnd==5)
                {
                    showInformationBox("通信异常");
                    free(pSETFRAMERR_TYPE_Temp);
                    pSETFRAMERR_TYPE_Temp=NULL;
                    return;
                }
            }
          }  while(noEnd);
    }

    free(pSETFRAMERR_TYPE_Temp);
    pSETFRAMERR_TYPE_Temp=NULL;
}

