#ifndef TOOLCIRCLE_H
#define TOOLCIRCLE_H

#include <QFrame>
#include <QPropertyAnimation>
#include "dragClass/dragframecharm.h"

namespace Ui {
class ToolCircle;
}

/**
 * @brief The ToolCircle class
 * 辅助球
 */
class ToolCircle : public QFrame
{
    Q_OBJECT

public:
    explicit ToolCircle(QWidget *parent = 0);
    ~ToolCircle();

public:
    DragFrameCharm *m_dragFrameCharm;
    QPropertyAnimation *m_propertyAnimation;

public:
    void initAnimation();

public:
    void initDrag();

signals:
    void signal_escaped();
    void signal_enter(int);
    void signal_mouseRelease_For_Clicked();

public:
    Ui::ToolCircle *ToolcUI;
};

#endif // TOOLCIRCLE_H
