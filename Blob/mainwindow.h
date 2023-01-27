#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QDialog>

/* FILES */
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

    private :
        Ui::MainWindow *ui;
        QWidget* centre;

        /* LAYOUT */
        QVBoxLayout* vboxlayout;
        QHBoxLayout* hBoxTop;
        QHBoxLayout* hBoxBottom;
        QHBoxLayout* bottom;
        QLabel* lb;
        QLineEdit* text1;
        QLineEdit* text2;
        QPushButton* bouton;

        /* FUNCTIONS */
        void init_components();
        void init_layouts();
        //void init_slots();
};
#endif // MAINWINDOW_H
