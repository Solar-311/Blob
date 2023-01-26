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

        /* LAYOUT */
        QVBoxLayout* vboxlayout;
        QGridLayout* gridTrois;
        QGridLayout* gridInfo;
        QHBoxLayout* hBoxL;
        QVBoxLayout* vBoxTopL;
        QVBoxLayout* vBoxBottomL;
        QHBoxLayout* hBoxR;
        QVBoxLayout* vBoxTopR;
        QVBoxLayout* vBoxBottomR;

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


        /* GETTER & SETTER */

        /* FUNCTIONS */
        void playerButton(Joueur *currentPlayer);
        void init_slots();

    public slots :
        void fermeJeux();
        void slotChangeJoueur();
        void slotNormale();
        void slotSoins();
        void slotSpeciale();
        void winWindow();
};
#endif // MAINWINDOW_H
