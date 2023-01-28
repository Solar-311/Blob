#ifndef MOVEMENT_H
#define MOVEMENT_H

// Scene.h
#include <QtCore>
#include <QLabel>

class Movement : public QLabel
{
    Q_OBJECT

public:
    Movement(QWidget *parent = 0);

protected:
    void timerEvent(QTimerEvent *event);

private:
    int m_offset;
};

#endif // MOVEMENT_H
