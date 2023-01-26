#ifndef ENDWINDOW_H
#define ENDWINDOW_H

/* ########## INCLUDE ########## */
/* LIBRARY QT */
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QRect>
#include <QMovie>
#include <QLineEdit>

/* FILES */
#include "Model/Joueur/Joueur.h"
#include "Model/Arene/Arene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class endWindow : public QMainWindow
{
    Q_OBJECT

    public:
        Arene *arene;
        endWindow(Arene *arene, QWidget *parent = nullptr);
        ~endWindow();

    private:
        Ui::MainWindow *ui;
        QWidget* centre;
        QVBoxLayout* vboxlayout;
        QLabel* lb;
};

#endif // ENDWINDOW_H
