#include<mainwidget.h>

UINT8 timeThread::transmitsSimply (UINT8 *data)//串口快速发送
{
    UINT8   retValue = ERR_UNIVERSAL;
    UINT32  readSize=50;
    UINT8   *PtrReadTemp= (UINT8 *)malloc(readSize * sizeof(UINT8));
    UINT8   *PtrFree=PtrReadTemp;

    retValue = driver_619->sendOther(data,readSize,PtrReadTemp,&readSize);

    PtrReadTemp=PtrFree;
    free(PtrReadTemp);
    PtrReadTemp = NULL;

    return retValue;
}

void timeThread::slt_battery_timeDone()
{
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"ME_locked";
        return ;
    }

    QString str;
    if(driver_619->getRBAT(str) == ERR_RIGHT)
    {
        emit sig_battery_update(str);
    }

    mutexUpdate.unlock();
}

bool timeThread::setSP(pSPTYPE pSPTYPE_Temp)
{
    if(driver_619->setSP(pSPTYPE_Temp) != ERR_RIGHT)
    {
        return false;
    }

    return true;
}


bool timeThread:: getSP(pSPTYPE pSPTYPE_Temp)
{
    if(driver_619->getSP(pSPTYPE_Temp) != ERR_RIGHT)
    {
        return false;
    }

    return true;
}

//QStringList getRCR();
//QStringList getRVR();

QStringList timeThread:: getRVR()
{
    QStringList strList;

    pVRCRTYPE   pVRCRTYPE_Temp =NULL;
    pVRCRTYPE_Temp=(pVRCRTYPE)calloc(1,sizeof(VRCRTYPE));

    memset(pVRCRTYPE_Temp,0,sizeof(VRCRTYPE));

    if(driver_619->getRVR(pVRCRTYPE_Temp) != ERR_RIGHT)
    {
        return strList;
    }

    strList<<QString::number(pVRCRTYPE_Temp->L1);
    strList<<QString::number(pVRCRTYPE_Temp->L2);
    strList<<QString::number(pVRCRTYPE_Temp->L3);


    free(pVRCRTYPE_Temp);
    pVRCRTYPE_Temp=NULL;

    return strList;
}
QStringList timeThread:: getRCR()
{
    QStringList strList;

    pVRCRTYPE   pVRCRTYPE_Temp =NULL;
    pVRCRTYPE_Temp=(pVRCRTYPE)calloc(1,sizeof(VRCRTYPE));

    memset(pVRCRTYPE_Temp,0,sizeof(VRCRTYPE));

    if(driver_619->getRCR(pVRCRTYPE_Temp) != ERR_RIGHT)
    {
        return strList;
    }

    strList<<QString::number(pVRCRTYPE_Temp->L1);
    strList<<QString::number(pVRCRTYPE_Temp->L2);
    strList<<QString::number(pVRCRTYPE_Temp->L3);


    free(pVRCRTYPE_Temp);
    pVRCRTYPE_Temp=NULL;

    return strList;
}

//ME
void timeThread::slt_ME_timeDone()
{
//    qDebug()<<"slt_ME_timeDone";
#if 0
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"ME_locked";
        return ;
    }
#endif

#if 1
    if( driver_619->getME(driver_619->pMETYPE_Data) == ERR_RIGHT )
    {
         //qDebug()<<"slt_ME_timeDone"<<QString ::number(driver_619->pMETYPE_Data->UL1);
         emit sig_ME_update(driver_619->pMETYPE_Data);
    }
#endif
   // mutexUpdate.unlock();
 }



void timeThread::slt_RSMV_wave_timeDone()
{
    qDebug()<<"slt_RSMV_wave_timeDone"<<QString::number(wave_chlNum)<<QString::number(wave_sampleCnt);

//    if(mutexUpdate.tryLock()==false)
//    {
//        qDebug()<<"RSMV_wave_locked";
//        return ;
//    }

    pRKLTYPE      pRKLTYPE_Temp=NULL;

    if((pRKLTYPE_Temp=(pRKLTYPE)calloc(1,sizeof(RKLTYPE)))==NULL)
    {
        free(pRKLTYPE_Temp);
        pRKLTYPE_Temp=NULL;
        return ;
    }


    if( (driver_619->getKL(wave_chlNum,pRKLTYPE_Temp) == ERR_RIGHT) )
    {
#if 1
        for(int i = 0; i <wave_sampleCnt; i++ )  //wave_sampleCnt
        {

           RSMV_wave_axesY[0][i]= pRKLTYPE_Temp->U1R[i];//Ua
//         RSMV_wave_axesY[1][i]= (*(pKLTYPE_Temp->CH2))->elt[i];//Ub
//         RSMV_wave_axesY[2][i]= (*(pKLTYPE_Temp->CH3))->elt[i];//Uv

            qDebug("xxxx--%2f",pRKLTYPE_Temp->U1R[i]);
        }

            RSMV_arrayTemp[0] = search_maxDoubleValue(&RSMV_wave_axesY[0][0],wave_sampleCnt);
//          RSMV_arrayTemp[1] = search_maxDoubleValue(&RSMV_wave_axesY[1][0],RSMV_wave_sampleCnt);
//          RSMV_arrayTemp[2] = search_maxDoubleValue(&RSMV_wave_axesY[2][0],RSMV_wave_sampleCnt);
            RSMV_arrayTemp[3] = search_maxDoubleValue(&RSMV_arrayTemp[0],3);

           emit  sig_wave_update();
#endif
        }

    //qDebug()<<QString::number((*(pKLTYPE_Temp->CH1))->elt[0]);

    free(pRKLTYPE_Temp);
    pRKLTYPE_Temp=NULL;
//    mutexUpdate.unlock();

 }

void timeThread::slt_RRF_timeDone()
{
    qDebug()<<"slt_RRF_timeDone";

#if 0
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"ME_locked";
        return ;
    }
#endif
    pRRFTYPE   pRRFTYPE_Temp =NULL;
    pRRFTYPE_Temp=(pRRFTYPE)calloc(1,sizeof(RRFTYPE));

#if 1
    if( driver_619->getRRF(pRRFTYPE_Temp) == 1 )
    {
         // qDebug()<<"slt_RRF_timeDone"<<QString ::number(pRRFTYPE_Temp->RV,'d',4);
          emit sig_RRF_update(pRRFTYPE_Temp);
    }


    free(pRRFTYPE_Temp);
    pRRFTYPE_Temp=NULL;
     //timeThreadTimer.mutexUpdate.unlock();
   // mutexUpdate.unlock();
#endif

 }


void timeThread::slt_ES_timeDone()
{
    qDebug()<<"slt_ES_timeDone";
#if 0
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"ME_locked";
        return ;
    }
#endif
    pESTYPE   pESTYPE_Temp =NULL;
    pESTYPE_Temp=(pESTYPE)calloc(1,sizeof(ESTYPE));

#if 1
    if( driver_619->getES(pESTYPE_Temp) == 1 )
    {

         emit sig_ES_update(pESTYPE_Temp);
    }


    free(pESTYPE_Temp);
    pESTYPE_Temp=NULL;
     //timeThreadTimer.mutexUpdate.unlock();
   // mutexUpdate.unlock();
#endif
}


void timeThread::slt_ESTD_timeDone()
{
    //qDebug()<<"slt_ESTD_timeDone";

#if 1
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"slt_ESTD_tryLock";
        return ;
    }

    pESTDTYPE   pESTDTYPE_Temp =NULL;
    pESTDTYPE_Temp=(pESTDTYPE)calloc(1,sizeof(ESTDTYPE));

    if( driver_619->getESTD(pESTDTYPE_Temp) == 1 )
    {
         //qDebug()<<"getES"<<QString ::number(pESTYPE_Temp->PE);
         emit sig_ESTD_update(pESTDTYPE_Temp);
    }

    free(pESTDTYPE_Temp);
    pESTDTYPE_Temp=NULL;
#endif

    mutexUpdate.unlock();
}


void timeThread::slt_ENERGY_PUL_timeDone()
{
    //qDebug()<<"slt_ENERGY_PUL_timeDone";

#if 1
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"slt_ENERGY_PUL_locked";
        return ;
    }

    pPULSEPOW   pPULSEPOW_Temp =NULL;
    pPULSEPOW_Temp=(pPULSEPOW)calloc(1,sizeof(PULSEPOW));

    if( driver_619->getEnergyPul(pPULSEPOW_Temp) == 1 )
    {
         //qDebug()<<"ENERGY_PUL"<<QString ::number(pPULSEPOW_Temp->WP);
         emit sig_ENERGY_PUL_update(pPULSEPOW_Temp);
    }

    free(pPULSEPOW_Temp);
    pPULSEPOW_Temp=NULL;

    mutexUpdate.unlock();
#endif
}


void timeThread::slt_ENERGY_STD_timeDone()
{
#if 1
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"slt_ENERGY_STD_locked";
        return ;
    }

    pPULSEPOW   pPULSEPOW_Temp =NULL;
    pPULSEPOW_Temp=(pPULSEPOW)calloc(1,sizeof(PULSEPOW));

    if( driver_619->getMeterenrgy(pPULSEPOW_Temp) == 1 )
    {
         //qDebug()<<"getES"<<QString ::number(pESTYPE_Temp->PE);
         emit sig_ENERGY_STD_update(pPULSEPOW_Temp);
    }

    free(pPULSEPOW_Temp);
    pPULSEPOW_Temp=NULL;

    mutexUpdate.unlock();
#endif
}




