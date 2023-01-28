#include "Movement.h"

Movement::Movement(QWidget *parent) : QLabel(parent)
{
    m_step = 0;
    m_direction = 1;

    m_timer.setInterval(50); // intervalle de temps en ms
    connect(&m_timer, &QTimer::timeout, this, &Movement::moveImage);
    m_timer.start();
}

void Movement::moveImage()
{
    if(m_step < 50 && m_direction == 1) {
        move(x(), y() - 1);
        m_step++;
    }
    else if(m_step >= 50 && m_direction == 1) {
        m_direction = -1;
    }
    else if(m_step > 0 && m_direction == -1) {
        move(x(), y() + 1);
        m_step--;
    }
    else if(m_step <= 0 && m_direction == -1) {
        m_direction = 1;
    }
}
