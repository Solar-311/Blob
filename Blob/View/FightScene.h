#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H

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
#include <QTimer>
#include <QLineEdit>
#include <QtCore>
#include <QtGui>

/* FILES */
#include "Model/Joueur/Joueur.h"
#include "Model/Arene/Arene.h"
#include "View/Movement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FightScene : public QMainWindow
{
    Q_OBJECT

    public:
        Arene *arene;
        FightScene(Arene *arene, QWidget *parent = nullptr);
        ~FightScene();

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
        Movement* imageBlobJoueur1;

        /* JOUEUR 2 */
        QLabel* nomBlobJoueur2;
        QLabel* nomJoueur2;
        QLabel* typeJoueur2;
        QLabel* pvCourantJoueur2;
        Movement* imageBlobJoueur2;

        /* BOUTONS */
        QPushButton* boutonNormale;
        QPushButton* boutonSoin;
        QPushButton* boutonSpeciale;
        QPushButton* boutonPasserTour;
        QPushButton* rejouer;

        /* INIT */
        void init_components();
        void init_layout();

        /* FUNCTIONS */
        void playerButton(Joueur *currentPlayer);
        void init_slots();
        void changeScene();
        void winnerManagment();

public slots :
        void slotChangeJoueur();
        void slotNormale();
        void slotSoins();
        void slotSpeciale();
};

#endif // FIGHTSCENE_H
