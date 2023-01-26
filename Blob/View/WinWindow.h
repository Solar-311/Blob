#ifndef WINWINDOW_H
#define WINWINDOW_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        Arene *arene;
        MainWindow(Arene *arene, QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QWidget* centre;

        /* INIT */
        void init_components();
        void init_layout();

        /* GETTER & SETTER */

    public slots :
};

#endif // WINWINDOW_H
