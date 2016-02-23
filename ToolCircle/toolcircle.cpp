#include "toolcircle.h"
#include "ui_toolcircle.h"
#include "stdafx.h"
#include "mainwidget.h"
#include "ui_mainwidget.h"

ToolCircle::ToolCircle(QWidget *parent) :
    QFrame(parent),
    ToolcUI(new Ui::ToolCircle)
{
    ToolcUI->setupUi(this);
    ToolcUI->tbtn_Return->hide();

    initAnimation();
    initDrag();
}

ToolCircle::~ToolCircle()
{
    delete ToolcUI;
}

void ToolCircle::initAnimation()
{
    m_propertyAnimation = new QPropertyAnimation(this, "geometry");
    m_propertyAnimation->setDuration(150);
    m_propertyAnimation->setEasingCurve(QEasingCurve::Linear);
}

void ToolCircle::initDrag()
{
    setWindowFlags(Qt::FramelessWindowHint);

    m_dragFrameCharm = new DragFrameCharm;
    m_dragFrameCharm->activateOn(this);
    connect(m_dragFrameCharm, SIGNAL(signal_enter(int)), this, SIGNAL(signal_enter(int)));
    connect(m_dragFrameCharm, SIGNAL(signal_escaped()), this, SIGNAL(signal_escaped()));
    connect(m_dragFrameCharm, SIGNAL(signal_mouseRelease_For_Clicked()), this, SIGNAL(signal_mouseRelease_For_Clicked()));
}

void MainWidget::initToolCircle()
{
    m_ToolCircle = new ToolCircle(this);
    m_ToolCircle->hide();
    m_ToolCircle->m_dragFrameCharm->setLimitXFlag(true);
    m_ToolCircle->m_dragFrameCharm->setLimitYFlag(true);
    m_ToolCircle->m_dragFrameCharm->setLimitRect(QRect(0, 0, width(), height()));

    QString qssStr = "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.711864 rgba(255, 255, 255, 255), stop:1 rgba(180, 180, 180, 255));border-radius:10";
    tbtn_ToolCircle = new DragToolBtn(this);
    tbtn_ToolCircle->m_dragFrameCharm->setLimitXFlag(true);
    tbtn_ToolCircle->m_dragFrameCharm->setLimitYFlag(true);
    tbtn_ToolCircle->m_dragFrameCharm->setLimitRect(QRect(0, 0, width(), height()));
    tbtn_ToolCircle->resize(70, 70);
    tbtn_ToolCircle->setStyleSheet(qssStr);
    tbtn_ToolCircle->show();
    tbtn_ToolCircle->move(width() - tbtn_ToolCircle->width(), 0);
    tbtn_ToolCircle->raise();


    //connect(tbtn_ToolCircle                         , SIGNAL(clicked()), this, SLOT(showToolCircle()));
    connect(tbtn_ToolCircle                         , SIGNAL(signal_mouseRelease_For_Clicked()), this, SLOT(showToolCircle()));


    connect(m_ToolCircle->ToolcUI->tbtn_Home        , SIGNAL(clicked()), this, SLOT(gohomePage()));
    connect(m_ToolCircle->ToolcUI->tbtn_Return      , SIGNAL(clicked()), this, SLOT(closeToolCircle()));
#if (!defined _SOFT604_)
    connect(m_ToolCircle->ToolcUI->tbtn_Set         , SIGNAL(clicked()), this, SLOT(showBasicSet_Auto()));
#endif
    connect(m_ToolCircle                            , SIGNAL(signal_mouseRelease_For_Clicked()), this, SLOT(closeToolCircle()));
    connect(m_ToolCircle->ToolcUI->tbtn_KeyBoard    , SIGNAL(clicked()), this, SLOT(showKeyboard()));
    connect(m_ToolCircle->ToolcUI->tbtn_Sys         , SIGNAL(clicked()), this, SLOT(showFilemanager()));
#if (defined _WITH_POPPLER_)
    connect(m_ToolCircle->ToolcUI->tbtn_Help        , SIGNAL(clicked()), this, SLOT(showPdfFrame()));
#endif  //_WITH_POPPLER_
    connect(m_ToolCircle->ToolcUI->tbtn_Return_2    , SIGNAL(clicked()), this, SLOT(showToolCircle()));
    connect(m_ToolCircle->ToolcUI->tbtn_PrintScreen , SIGNAL(clicked()), this, SLOT(printscreen_Wait()));
    connect(m_ToolCircle->ToolcUI->tbtn_Tool        , SIGNAL(clicked()), this, SLOT(showToolCircle_ToolPage()));

    connect(m_ToolCircle->ToolcUI->tbtn_Home        , SIGNAL(clicked())     , this, SLOT(closeToolCircle()));
    connect(m_ToolCircle->ToolcUI->tbtn_Set         , SIGNAL(clicked())     , this, SLOT(closeToolCircle()));
    connect(m_ToolCircle->ToolcUI->tbtn_KeyBoard    , SIGNAL(clicked())     , this, SLOT(closeToolCircle()));
    connect(m_ToolCircle->ToolcUI->tbtn_Sys         , SIGNAL(clicked())     , this, SLOT(closeToolCircle()));
    connect(m_ToolCircle->ToolcUI->tbtn_Help        , SIGNAL(clicked())     , this, SLOT(closeToolCircle()));
    connect(m_ToolCircle->ToolcUI->tbtn_PrintScreen , SIGNAL(clicked())     , this, SLOT(closeToolCircle()));
}

void MainWidget::closeToolCircle()
{
    m_ToolCircle->m_propertyAnimation->setCurrentTime(m_ToolCircle->m_propertyAnimation->duration());
    m_ToolCircle->m_propertyAnimation->setStartValue(QRect(m_ToolCircle->geometry()));
    m_ToolCircle->m_propertyAnimation->setEndValue(QRect(tbtn_ToolCircle->geometry().center(), QSize(0, 0)));
    m_ToolCircle->m_propertyAnimation->start();

    tbtn_ToolCircle->show();
    tbtn_ToolCircle->raise();
}

void MainWidget::showToolCircle()
{
    m_ToolCircle->resize(210, 210);
    QPoint centerPointTmp = tbtn_ToolCircle->frameGeometry().center();
    int posX = centerPointTmp.x() - m_ToolCircle->width() / 2;
    int posY = centerPointTmp.y() - m_ToolCircle->height() / 2;

    if ((posX + m_ToolCircle->width()) > width())
    {
        posX = width() - m_ToolCircle->width();
    }
    else if (posX < 0)
    {
        posX = 0;
    }

    if (posY < 0)
    {
        posY = 0;
    }
    else if ((posY + m_ToolCircle->height()) > height())
    {
        posY = height() - m_ToolCircle->height();
    }

    tbtn_ToolCircle->hide();

    m_ToolCircle->hide();
    m_ToolCircle->setWindowModality(Qt::WindowModal);
    m_ToolCircle->move(posX, posY);
    m_ToolCircle->show();
    m_ToolCircle->raise();
    m_ToolCircle->ToolcUI->stkWidget_Main->setCurrentIndex(0);


    m_ToolCircle->m_propertyAnimation->setCurrentTime(m_ToolCircle->m_propertyAnimation->duration());
    m_ToolCircle->m_propertyAnimation->setStartValue(QRect(tbtn_ToolCircle->geometry().center(), QSize(0, 0)));
    m_ToolCircle->m_propertyAnimation->setEndValue(QRect(QPoint(posX, posY), QSize(210, 210)));
    m_ToolCircle->m_propertyAnimation->start();

    //qDebug()<<"showToolCircle x:"<<posX<<" y:"<<posY;
}
