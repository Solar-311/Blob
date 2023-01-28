#include "Movement.h"

Movement::Movement(QWidget *parent) : QLabel(parent)
{
    m_offset = 0;
    startTimer(50);
}

void Movement::timerEvent(QTimerEvent *event)
{
    m_offset++;
    setGeometry(x(), y() + qSin(m_offset / 10.0) * 2, width(), height());
}
