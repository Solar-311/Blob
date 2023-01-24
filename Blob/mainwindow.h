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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

<<<<<<< HEAD
private:
    Ui::MainWindow *ui;
    QWidget* centre;
    QLabel* nom;
    QLabel* type;
    QLabel* pv;
    QLabel* pvAdversaire;
    QVBoxLayout* vboxlayout;
    QHBoxLayout* hBoxUn;
    QHBoxLayout* hBoxDeux;
    QGridLayout* gridTrois;
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
    void init_components();
    void init_layout();
=======
    private:
        Ui::MainWindow *ui;
        QWidget* centre;
        QLabel* nom;
        QLabel* type;
        QLabel* pv;
        QLabel* pvAdversaire;

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
>>>>>>> ec3dc388f0d2dee0e23d7bbe5603ecfa21100669
};
#endif // MAINWINDOW_H
