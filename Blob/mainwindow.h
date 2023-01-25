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




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QWidget* centre;
        QLabel* nom;
        QLabel* type;
        QLabel* pv;
        QLabel* pvAdversaire;
        QLabel* imageBlobAlier;
        QLabel* imageBlobEnnemie;
        QMovie mv;
        QMainWindow *fenetreChoix;

        /* LAYOUT */
        QVBoxLayout* vboxlayout;
        QHBoxLayout* hBoxUn;
        QHBoxLayout* hBoxDeux;
        QGridLayout* gridTrois;

        /* ELEMENTS */
        QPushButton* boutonAtttaqueNormale;
        QPushButton* boutonSoin;
        QPushButton* boutonFuir;//abandonne le combat
        QPushButton* boutonAttaqueSpe;
        QLabel* nomAdversaire;
        QLabel* typeAdversaire;
        QPixmap* imageAdversaire;
        QPixmap* imagePerso;
        QLabel* imageLabelPerso;
        QLabel* imageLabelAdversaire;

        /* INIT */
        void init_components();
        void init_layout();
        void init_slots();
        void fenetrechoix();
};
#endif // MAINWINDOW_H
