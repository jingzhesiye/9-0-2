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


//METERCONST;0.000000
//CHECKNUM;0
//CONST;0.000000
//CHECKTYPE;0
bool timeThread:: setSP_part(QStringList  strList)
{
    bool isTrue=false;
    pSPTYPE   pSPTYPE_Temp =NULL;
    pSPTYPE_Temp=(pSPTYPE)calloc(1,sizeof(SPTYPE));

    pISABLE_SP   pISABLE_SP_Temp =NULL;
    pISABLE_SP_Temp=(pISABLE_SP)calloc(1,sizeof(ISABLE_SP));

    memset(pISABLE_SP_Temp,0,sizeof(ISABLE_SP));

    pSPTYPE_Temp->METERCONST =atof(strList.at(0).toLatin1().data());
    pSPTYPE_Temp->CHECKNUM=atof(strList.at(1).toLatin1().data());
    pSPTYPE_Temp->AMMETER_CONST=atof(strList.at(2).toLatin1().data());
    pSPTYPE_Temp->CHECKTYPE=atof(strList.at(3).toLatin1().data());//有功0
    pSPTYPE_Temp->SAMNUM=256;//有功0

    pISABLE_SP_Temp->METERCONST =1;
    pISABLE_SP_Temp->CHECKNUM=1;
    pISABLE_SP_Temp->AMMETER_CONST=1;
    pISABLE_SP_Temp->CHECKTYPE=1;
    pISABLE_SP_Temp->SAMNUM=1;
    if(driver_619->setSP_part(pSPTYPE_Temp,pISABLE_SP_Temp) == ERR_RIGHT)
    {
       isTrue =true;
    }

    free(pSPTYPE_Temp);
    pSPTYPE_Temp=NULL;

    free(pISABLE_SP_Temp);
    pISABLE_SP_Temp=NULL;

    //qDebug("free.retValue==%d\n",returnValue);

    return isTrue;

}

QStringList timeThread:: getSP()
{
    QStringList strList;

    pSPTYPE   pSPTYPE_Temp =NULL;
    pSPTYPE_Temp=(pSPTYPE)calloc(1,sizeof(SPTYPE));

    memset(pSPTYPE_Temp,0,sizeof(ISABLE_SP));

    if(driver_619->getSP(pSPTYPE_Temp) != ERR_RIGHT)
    {
        return strList;
    }

    strList<<QString::number(pSPTYPE_Temp->METERCONST,'d',6);
    strList<<QString::number(pSPTYPE_Temp->CHECKNUM);
    strList<<QString::number(pSPTYPE_Temp->AMMETER_CONST,'d',6);
    strList<<QString::number(pSPTYPE_Temp->CHECKTYPE);

    free(pSPTYPE_Temp);
    pSPTYPE_Temp=NULL;

    return strList;
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
void timeThread::slt_RSMV_rms_timeDone()
{

    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"RSMV_rms_locked";
        return ;
    }
#if 1
    if( driver_619->getME(driver_619->pMETYPE_Data) == ERR_RIGHT )
    {
         //qDebug()<<"slt_SSMV_rms_timeDone2"<<QString ::number(driver_619->pMETYPE_Data->UL1);
         emit sig_RSMV_rms_update(driver_619->pMETYPE_Data);
    }
#endif
    mutexUpdate.unlock();
 }



void timeThread::slt_RSMV_wave_timeDone()
{
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"RSMV_wave_locked";
        return ;
    }
    qDebug()<<"slt_RSMV_wave_timeDone";

    pKLTYPE      pKLTYPE_Temp=NULL;
    if((pKLTYPE_Temp=driver_619->newKLBuf(63,256))==NULL)
    {
        free(pKLTYPE_Temp);
        pKLTYPE_Temp=NULL;
        return ;
    }

//    memset(&((*(pKLTYPE_Temp->CH1))->elt[0]),0,4*256);
//    memset(&((*(pKLTYPE_Temp->CH2))->elt[0]),0,4*256);
//    memset(&((*(pKLTYPE_Temp->CH3))->elt[0]),0,4*256);

//    memset(&((*(pKLTYPE_Temp->CH4))->elt[0]),0,4*256);
//    memset(&((*(pKLTYPE_Temp->CH5))->elt[0]),0,4*256);
//    memset(&((*(pKLTYPE_Temp->CH6))->elt[0]),0,4*256);

    if( (driver_619->getKL(RSMV_wave_chlNum,pKLTYPE_Temp) == ERR_RIGHT) )
    {

#if 1
        for(int i = 0; i < RSMV_wave_sampleCnt; i++ )
        {
            if(RSMV_wave_chlNum  == 7)
            {
                RSMV_wave_axesY[0][i]= (*(pKLTYPE_Temp->CH1))->elt[i];//Ua
                RSMV_wave_axesY[1][i]= (*(pKLTYPE_Temp->CH2))->elt[i];//Ub
                RSMV_wave_axesY[2][i]= (*(pKLTYPE_Temp->CH3))->elt[i];//Uv
            }
            else
            {
                RSMV_wave_axesY[0][i]= (*(pKLTYPE_Temp->CH4))->elt[i];//Ia
                RSMV_wave_axesY[1][i]= (*(pKLTYPE_Temp->CH5))->elt[i];//Ib
                RSMV_wave_axesY[2][i]= (*(pKLTYPE_Temp->CH6))->elt[i];//Ic
            }
            //qDebug("%lf",RSMV_wave_axesY[0][i]);
        }
#endif
#if 1
            RSMV_arrayTemp[0] = search_maxDoubleValue(&RSMV_wave_axesY[0][0],RSMV_wave_sampleCnt);
            RSMV_arrayTemp[1] = search_maxDoubleValue(&RSMV_wave_axesY[1][0],RSMV_wave_sampleCnt);
            RSMV_arrayTemp[2] = search_maxDoubleValue(&RSMV_wave_axesY[2][0],RSMV_wave_sampleCnt);
            RSMV_arrayTemp[3] = search_maxDoubleValue(&RSMV_arrayTemp[0],3);
#endif
            //qDebug("%lf",RSMV_arrayTemp[0]);
            emit  sig_RSMV_wave_update();
        }

    //qDebug()<<QString::number((*(pKLTYPE_Temp->CH1))->elt[0]);

    driver_619->deleteKLBuf(pKLTYPE_Temp);
    pKLTYPE_Temp=NULL;
    mutexUpdate.unlock();

 }

void timeThread::slt_RSMV_harmonic_timeDone()
{
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"slt_RSMV_harmonic_lock";
        return ;
    }
    pHARMONIC_TYPE       pHARMONIC_TYPE_Temp;
    pHARMONIC_TYPE_Temp= driver_619->newHRNBuf(45);
    if( pHARMONIC_TYPE_Temp != NULL )
    {

        //int t =driver_619->getHRN( SMV_harmonic_ChlNum, pHARMONIC_TYPE_Temp, SMV_harmonic_H1, SMV_harmonic_H2);
        //qDebug()<<QString::number(t);
        if( (driver_619->getHRN( SMV_harmonic_ChlNum, pHARMONIC_TYPE_Temp, SMV_harmonic_H1, SMV_harmonic_H2) == ERR_RIGHT) )
        {
            RSMV_arrayTemp[0]=0;
            RSMV_arrayTemp[1]=100;
            for( uint i=0;i<(SMV_harmonic_H2-2);i++)
            {
              RSMV_arrayTemp[i+2]=(*(pHARMONIC_TYPE_Temp->fN))->elt[i];
               //qDebug("RSMV_arrayTemp==%f",RSMV_arrayTemp[i+2]);
            }
            emit sig_RSMV_harmonic_update();
         }
    }

    driver_619->deleteHRNBuf(pHARMONIC_TYPE_Temp);
    pHARMONIC_TYPE_Temp=NULL;
    mutexUpdate.unlock();
 }


void timeThread::slt_RSMV_ES_timeDone()
{
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"RSMV_rms_locked";
        return ;
    }

    pESTYPE   pESTYPE_Temp =NULL;
    pESTYPE_Temp=(pESTYPE)calloc(1,sizeof(ESTYPE));


#if 1
    if( driver_619->getES(pESTYPE_Temp) == 1 )
    {
         //qDebug()<<"getES"<<QString ::number(pESTYPE_Temp->PE);
         emit sig_RSMV_ES_update(pESTYPE_Temp);
    }
#endif

    free(pESTYPE_Temp);
    pESTYPE_Temp=NULL;
     //timeThreadTimer.mutexUpdate.unlock();
    mutexUpdate.unlock();
}


void timeThread::slt_RSMV_ESTD_timeDone()
{
    //qDebug()<<"slt_RSMV_ESTD_timeDone";

#if 1
    if(mutexUpdate.tryLock()==false)
    {
        qDebug()<<"slt_RSMV_ESTD_tryLock";
        return ;
    }

    pESTDTYPE   pESTDTYPE_Temp =NULL;
    pESTDTYPE_Temp=(pESTDTYPE)calloc(1,sizeof(ESTDTYPE));

    if( driver_619->getESTD(pESTDTYPE_Temp) == 1 )
    {
         //qDebug()<<"getES"<<QString ::number(pESTYPE_Temp->PE);
         emit sig_RSMV_ESTD_update(pESTDTYPE_Temp);
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




