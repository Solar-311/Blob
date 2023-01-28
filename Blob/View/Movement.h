#ifndef MOVEMENT_H
#define MOVEMENT_H

// Scene.h
#include <QtCore>
#include <QLabel>
#include <QTimer>
class Movement : public QLabel
{
    Q_OBJECT

public:
    Movement(QWidget *parent = 0);

private:
    int m_step;
    int m_direction;
    QTimer m_timer;

private slots:
    void moveImage();
};

#endif // MOVEMENT_H
