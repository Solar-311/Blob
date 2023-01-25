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

        /* LAYOUT */
        QVBoxLayout* vboxlayout;
        QHBoxLayout* hBoxUn;
        QHBoxLayout* hBoxDeux;
        QGridLayout* gridTrois;

        /* JOUEUR 1 */
        QLabel* nomBlobJoueur1;
        QLabel* nomJoueur1;
        QLabel* typeJoueur1;
        QLabel* pvCourantJoueur1;
        QLabel* imageBlobJoueur1;

        /* JOUEUR 2 */
        QLabel* nomBlobJoueur2;
        QLabel* nomJoueur2;
        QLabel* typeJoueur2;
        QLabel* pvCourantJoueur2;
        QLabel* imageBlobJoueur2;

        /* BOUTONS */
        QPushButton* boutonNormale;
        QPushButton* boutonSoin;
        QPushButton* boutonSpeciale;
        QPushButton* boutonPasserTour;

        /* INIT */
        void init_components();
        void init_layout();
<<<<<<< HEAD
>>>>>>> ec3dc388f0d2dee0e23d7bbe5603ecfa21100669
=======

        /* GETTER & SETTER */

        /* FUNCTIONS */
        void playerButton(Joueur *currentPlayer);
        void init_slots();

public slots :
        void fermeJeux();
>>>>>>> 781399f0aef46cb039cb503232eb93d37f5af162
};
#endif // MAINWINDOW_H
