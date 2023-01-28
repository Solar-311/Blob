/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>

/* FILES */
#include "FightScene.h"
#include "ui_mainwindow.h"
#include "Menu.h"

/* ########### CONSTRUCTOR ########### */
FightScene::FightScene(Arene *arene, QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    this->arene = arene;
    ui->setupUi(this);

    /* BACKGROUND */
    QPixmap bkgnd(":/Images/Images/Background.png");
    QPalette palette;
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    /* WINDOW */
    this->setWindowTitle("Blob");
    this->setWindowIcon(QIcon(":/Images/Images/Icon.png"));
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    this->setAutoFillBackground(true);

    /* INITS */
    this->init_components();
    this->init_layout();
    this->init_slots();
}

/* ########### COMPONENTS ########### */
void FightScene::init_components(){
    /* CENTRAL WIDGET */
    this->centre = new QWidget();

    // Winner
    this->label = new QLabel(QString::fromStdString(this->arene->getCurrentPlayer()->getNom()) +"WON");
    this->label->setStyleSheet("QLabel { color : white; "
                             "font: bold 25px; "
                             "padding: 10px; "
                             "border-radius: 10px;}");

    /* COMPONENTS JOUEUR 2 */
    // Image Blob
    this->imageBlobJoueur2 = new Movement();
    QPixmap image(":/Images/Images/Icon.png");
    QPixmap image2 = image.scaled(150, 150, Qt::KeepAspectRatio);
    this->imageBlobJoueur2->setPixmap(image2);
    this->imageBlobJoueur2->show();

    // Position
    this->imageBlobJoueur2->setAlignment(Qt::AlignCenter);

    // Components
    this->typeJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getNom()) );
    this->nomBlobJoueur2->setStyleSheet("font-family: Consolas;"
                                    "font-style: italic;"
                                    "font-size: 15px;"
                                    "color: rgb(255, 255, 100);");
    this->pvCourantJoueur2 = new QLabel ( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur2->setStyleSheet("font-family: Consolas;"
                                          "font-weight: bold;"
                                          "font-size: 15px;"
                                          "color: white;");
    this->nomJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getNom()) );
    this->nomJoueur2->setStyleSheet("font-family: Consolas;"
                                    "font-size: 18px;"
                                    "background-color: rgb(30, 30, 30);"
                                    "color: white;"
                                    "font-weight: bold;");

    /* COMPONENTS JOUEUR 1 */
    // Image Blob
    this->imageBlobJoueur1 = new Movement();
    QPixmap image3(":/Images/Images/FireBlob.png");
    QPixmap image4 = image3.scaled(150, 150, Qt::KeepAspectRatio);
    this->imageBlobJoueur1->setPixmap(image4);
    this->imageBlobJoueur1->show();

    // Position
    this->imageBlobJoueur1->setAlignment(Qt::AlignCenter);

    // Components
    this->typeJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getNom()) );
    this->nomBlobJoueur1->setStyleSheet("font-family: Consolas;"
                                    "font-style: italic;"
                                    "font-size: 15px;"
                                    "color: rgb(255, 255, 100);");
    this->pvCourantJoueur1 = new QLabel ( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur1->setStyleSheet("font-family: Consolas;"
                                    "font-weight: bold;"
                                    "font-size: 15px;"
                                    "color: white;");
    this->nomJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getNom()) );
    this->nomJoueur1->setStyleSheet("font-family: Consolas;"
                                    "font-size: 18px;"
                                    "color: white;"
                                    "background-color: rgb(30, 30, 30);"
                                    "font-weight: bold;");

    /* GLOBAL COMPONENTS */
    this->boutonNormale = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getNormale()->getNom()) );
    this->boutonNormale->setStyleSheet(
                "font-weight: bold;"
                "font-size: 17px;"
                "letter-spacing: 1.5px;"
                "font-family: Consolas;"
                "border-bottom-left-radius:50px;"
                "border-top-left-radius:50px;"
                "border-width: 3px;"
                "border-style: solid;"
                "border-top-color: rgba(255, 255, 255, 0);"
                "border-left-color:  qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                "border-right-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                "border-bottom-color: black;"
                "background-color: rgb(255, 255, 100);"
                "color: black;");
    this->boutonSoin = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSoin()->getNom()) );
    this->boutonSoin->setStyleSheet(
                "font-weight: bold;"
                "font-size: 17px;"
                "letter-spacing: 1.5px;"
                "font-family: Consolas;"
                "border-bottom-left-radius:50px;"
                "border-top-left-radius:50px;"
                "border-width: 3px;"
                "border-style: solid;"
                "border-top-color: rgba(255, 255, 255, 0);"
                "border-left-color:  qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                "border-right-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                "border-bottom-color: black;"
                "background-color: rgb(255, 255, 100);"
                "color: rgb(0, 80, 0);");
    this->boutonSpeciale = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSpeciale()->getNom()) );
    this->boutonSpeciale->setStyleSheet(
                "font-weight: bold;"
                "font-size: 17px;"
                "letter-spacing: 1.5px;"
                "font-family: Consolas;"
                "border-bottom-left-radius:50px;"
                "border-top-left-radius:50px;"
                "border-width: 3px;"
                "border-style: solid;"
                "border-top-color: rgba(255, 255, 255, 0);"
                "border-left-color:  qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                "border-right-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                "border-bottom-color: black;"
                "background-color: rgb(255, 255, 100);"
                "color: rgb(80, 0, 0);");
    this->boutonPasserTour = new QPushButton("Next round");
    this->boutonPasserTour->setStyleSheet(
                "font-weight: bold;"
                "font-size: 17px;"
                "letter-spacing: 1.5px;"
                "font-family: Consolas;"
                "border-bottom-left-radius:50px;"
                "border-top-left-radius:50px;"
                "border-width: 3px;"
                "border-style: solid;"
                "border-top-color: rgba(255, 255, 255, 0);"
                "border-left-color:  qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 grey);"
                "border-right-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 grey);"
                "border-bottom-color: black;"
                "background-color: rgb(50, 50, 50);"
                "color: white;");

    this->boutonRejouer = new QPushButton("REJOUER LE COMBATs");
    this->boutonRejouer->setStyleSheet(
                "font-weight: bold;"
                "font-size: 17px;"
                "letter-spacing: 1.5px;"
                "font-family: Consolas;"
                "border-bottom-left-radius:50px;"
                "border-top-left-radius:50px;"
                "border-width: 3px;"
                "border-style: solid;"
                "border-top-color: rgba(255, 255, 255, 0);"
                "border-left-color:  qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 grey);"
                "border-right-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 grey);"
                "border-bottom-color: black;"
                "background-color: rgb(50, 50, 50);"
                "color: white;");
}

/* ########### LAYOUTS ########### */
void FightScene::init_layout(){
    /* CENTRAL WIDGET */
    this->setCentralWidget(this->centre);
    this->hBoxL = new QHBoxLayout();
    this->vBoxTopL = new QVBoxLayout();
    this->vBoxBottomL = new QVBoxLayout();
    this->hBoxR = new QHBoxLayout();
    this->vBoxTopR = new QVBoxLayout();
    this->vBoxBottomR = new QVBoxLayout();

    /* ADD COMPONENTS INFOS COMBATS */
    this->gridInfo = new QGridLayout();
    this->gridInfo->addWidget(this->nomJoueur2, 0, 1);
    this->nomJoueur2->setAlignment(Qt::AlignCenter);
    this->gridInfo->addWidget(this->nomBlobJoueur2, 1, 1);
    this->nomBlobJoueur2->setAlignment(Qt::AlignCenter);
    this->gridInfo->addWidget(this->pvCourantJoueur2, 2, 1);
    this->pvCourantJoueur2->setAlignment(Qt::AlignCenter);
    this->gridInfo->addWidget(this->nomJoueur1, 0, 0);
    this->nomJoueur1->setAlignment(Qt::AlignCenter);
    this->gridInfo->addWidget(this->nomBlobJoueur1, 1, 0);
    this->nomBlobJoueur1->setAlignment(Qt::AlignCenter);
    this->gridInfo->addWidget(this->pvCourantJoueur1, 2, 0);
    this->pvCourantJoueur1->setAlignment(Qt::AlignCenter);
    this->gridInfo->setAlignment(Qt::AlignTop);

    /* LAYOUT BOUTONS ATTAQUES */
    this->gridTrois = new QGridLayout();
    this->gridTrois->addWidget(boutonNormale,0,0);
    this->gridTrois->addWidget(boutonSpeciale,0,1);
    this->gridTrois->addWidget(boutonSoin,1,0);
    this->gridTrois->addWidget(boutonPasserTour,1,1);

    /* ADD COMPONENTS COMBAT */
    this->vBoxTopR->addWidget(this->imageBlobJoueur2);
    this->vBoxBottomL->addWidget(this->imageBlobJoueur1);

    this->vBoxBottomR->addWidget(this->boutonRejouer, Qt::AlignCenter);
    this->boutonRejouer->setVisible(false);

    this->vBoxTopL->addWidget(this->label);
    this->label->setVisible(false);
    if (this->arene->getJoueur1()->getBlob()->getPv_courant() == 0 ||
        this->arene->getJoueur2()->getBlob()->getPv_courant() == 0){
        this->label->setVisible(true);
        this->label->setAlignment(Qt::AlignTop);
    }

    /* LAYOUT ORGANISATION */
    this->vboxlayout = new QVBoxLayout();
    this->vboxlayout->addLayout(hBoxL);
    this->vboxlayout->addLayout(hBoxR);
    this->hBoxL->addLayout(vBoxTopL);
    this->hBoxL->addLayout(vBoxBottomL);
    this->hBoxR->addLayout(vBoxTopR);
    this->hBoxR->addLayout(vBoxBottomR);
    this->vBoxBottomR->addLayout(gridTrois);
    this->vBoxTopL->addLayout(this->gridInfo);

    /* SET VLAYOUT TO CENTRAL */
    this->centre->setLayout(this->vboxlayout);
}

/* SLOTS */
void FightScene::init_slots()
{
    connect(this->boutonPasserTour, &QPushButton::pressed, this, &FightScene::slotChangeJoueur);
    connect(this->boutonNormale, &QPushButton::released, this, &FightScene::slotNormale);
    connect(this->boutonSoin, &QPushButton::released, this, &FightScene::slotSoins);
    connect(this->boutonSpeciale, &QPushButton::released, this, &FightScene::slotSpeciale);
}

/* ########### SLOTS ########### */
void FightScene::slotChangeJoueur()
{
    this->arene->changeJoueur();

    // Refresh
    this->boutonNormale->setText( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getNormale()->getNom()) );
    this->boutonSpeciale->setText( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSpeciale()->getNom()) );
    this->boutonSoin->setText( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSoin()->getNom()) );

    // Buttons
    this->boutonNormale->setVisible(true);
    this->boutonSpeciale->setVisible(true);
    this->boutonSoin->setVisible(true);

    // Reset Animation
    this->pvCourantJoueur2->setStyleSheet("font-family: Consolas;"
                                        "font-weight: bold;"
                                        "font-size: 15px;"
                                        "color: white;");
    this->pvCourantJoueur1->setStyleSheet("font-family: Consolas;"
                                        "font-weight: bold;"
                                        "font-size: 15px;"
                                        "color: white;");

    if(this->arene->getJoueur1()->getBlob()->getPv_courant() <= 0 && this->arene->getJoueur2()->getBlob()->getPv_courant() > 0){
        this->imageBlobJoueur2->hide();
        this->boutonNormale->setVisible(false);
        this->boutonSpeciale->setVisible(false);
        this->boutonSoin->setVisible(false);
        this->boutonPasserTour->setVisible(false);
        this->pvCourantJoueur1->setVisible(false);
        this->nomJoueur1->setVisible(false);
        this->nomBlobJoueur1->setVisible(false);

        this->gridInfo->setAlignment(Qt::AlignVCenter);

        QPushButton* rejouer = new QPushButton("REJOUER");
        rejouer->setStyleSheet(
                    "font-weight: bold;"
                    "font-size: 17px;"
                    "letter-spacing: 1.5px;"
                    "font-family: Consolas;"
                    "border-bottom-left-radius:50px;"
                    "border-top-left-radius:50px;"
                    "border-width: 3px;"
                    "border-style: solid;"
                    "border-top-color: rgba(255, 255, 255, 0);"
                    "border-left-color:  qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                    "border-right-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                    "border-bottom-color: black;"
                    "background-color: rgb(255, 255, 100);"
                    "color: black;");
        this->vBoxTopR->addWidget(rejouer);
        connect(rejouer, &QPushButton::released, this, &FightScene::changeScene);
    }

    else if (this->arene->getJoueur1()->getBlob()->getPv_courant() > 0 && this->arene->getJoueur2()->getBlob()->getPv_courant() <= 0)
    {
        this->imageBlobJoueur1->hide();
        this->boutonNormale->setVisible(false);
        this->boutonSpeciale->setVisible(false);
        this->boutonSoin->setVisible(false);
        this->boutonPasserTour->setVisible(false);
        this->pvCourantJoueur2->setVisible(false);
        this->nomJoueur2->setVisible(false);
        this->nomBlobJoueur2->setVisible(false);

        this->gridInfo->setAlignment(Qt::AlignVCenter);

        QPushButton* rejouer = new QPushButton("REJOUER");
        rejouer->setStyleSheet(
                    "font-weight: bold;"
                    "font-size: 17px;"
                    "letter-spacing: 1.5px;"
                    "font-family: Consolas;"
                    "border-bottom-left-radius:50px;"
                    "border-top-left-radius:50px;"
                    "border-width: 3px;"
                    "border-style: solid;"
                    "border-top-color: rgba(255, 255, 255, 0);"
                    "border-left-color:  qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                    "border-right-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 yellow);"
                    "border-bottom-color: black;"
                    "background-color: rgb(255, 255, 100);"
                    "color: black;");
        this->vBoxTopR->addWidget(rejouer);
    }
}

void FightScene::changeScene()
{
    this->close();
    Soin *s = new Soin(50, "Soin");
    Speciale *sp = new Speciale(60, "Speciale");
    Normale *n = new Normale(40, "Normale");
    Soin *s2 = new Soin(50, "Fabio Soin");
    Speciale *sp2 = new Speciale(60, "Fabio Speciale");
    Normale *n2 = new Normale(50, "Fabio Attaque");
    Blob *f = new Blob("Nooby Noob", 100, new Feu(), sp, n, s);
    Blob *x = new Blob("FabioGODMODE", 120, new Feu(), sp2, n2, s2);
    Joueur *j1 = new Joueur("Joueur 1", f);
    Joueur *j2 = new Joueur("Joueur 2", x);
    Arene* arene = new Arene("ARENA WAR", j1, j2);
    Menu* m = new Menu(arene);
    m->show();

}

void FightScene::slotNormale()
{
    // Animation
    if (this->arene->getCurrentPlayer() == this->arene->getJoueur1()
            && this->arene->getCurrentPlayer()->getBlob()->getPv_courant() > 0
            && this->arene->getNotCurrentPlayer()->getBlob()->getPv_courant() != 0)
    {
        this->arene->getCurrentPlayer()->useNormale(this->arene->getNotCurrentPlayer());
        this->pvCourantJoueur2->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }
    else if (this->arene->getCurrentPlayer()->getBlob()->getPv_courant() > 0
             && this->arene->getNotCurrentPlayer()->getBlob()->getPv_courant() != 0)
    {
        this->arene->getCurrentPlayer()->useNormale(this->arene->getNotCurrentPlayer());
        this->pvCourantJoueur1->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }

    // Refresh
    this->pvCourantJoueur1->setText( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur2->setText( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );

    // Buttons
    this->boutonNormale->setVisible(false);
    this->boutonSpeciale->setVisible(false);
    this->boutonSoin->setVisible(false);
}

void FightScene::slotSoins()
{
    // Animation
    if (this->arene->getCurrentPlayer() == this->arene->getJoueur1()
            && this->arene->getJoueur1()->getBlob()->getPv_courant() > 0)
    {
        this->arene->getCurrentPlayer()->useSoin();
        this->pvCourantJoueur1->setStyleSheet("border-image: url(:/Images/Images/Heal.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }
    else if (this->arene->getCurrentPlayer() == this->arene->getJoueur2()
            && this->arene->getJoueur2()->getBlob()->getPv_courant() > 0)
    {
        this->arene->getCurrentPlayer()->useSoin();
        this->pvCourantJoueur2->setStyleSheet("border-image: url(:/Images/Images/Heal.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }

    // Refresh
    this->pvCourantJoueur1->setText( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur2->setText( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );

    // Buttons
    this->boutonNormale->setVisible(false);
    this->boutonSpeciale->setVisible(false);
    this->boutonSoin->setVisible(false);
}

void FightScene::slotSpeciale()
{
    // Animation
    if (this->arene->getCurrentPlayer() == this->arene->getJoueur1()
            && this->arene->getNotCurrentPlayer()->getBlob()->getPv_courant() != 0
            && this->arene->getCurrentPlayer()->getBlob()->getPv_courant() > 0
            && this->arene->getCurrentPlayer()->getBlob()->isTypeBetter(this->arene->getNotCurrentPlayer()->getBlob())){
        this->arene->getCurrentPlayer()->useSpeciale(this->arene->getNotCurrentPlayer());
        this->pvCourantJoueur2->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }
    else if(this->arene->getCurrentPlayer()->getBlob()->isTypeBetter(this->arene->getNotCurrentPlayer()->getBlob())
            && this->arene->getCurrentPlayer()->getBlob()->getPv_courant() > 0
            && this->arene->getNotCurrentPlayer()->getBlob()->getPv_courant() != 0)
    {
        this->arene->getCurrentPlayer()->useSpeciale(this->arene->getNotCurrentPlayer());
        this->pvCourantJoueur1->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }

    // Refresh
    this->pvCourantJoueur1->setText( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur2->setText( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );

    // Buttons
    this->boutonNormale->setVisible(false);
    this->boutonSpeciale->setVisible(false);
    this->boutonSoin->setVisible(false);
}

/* ########### MAINWINDOW ########### */
FightScene::~FightScene()
{
    delete ui;
}
