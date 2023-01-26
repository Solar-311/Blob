/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>

/* FILES */
#include "mainwindow.h"
#include "ui_mainwindow.h"

/* ########### CONSTRUCTEUR ########### */
MainWindow::MainWindow(Arene *arene, QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
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
void MainWindow::init_components(){
    /* CENTRAL WIDGET */
    this->centre = new QWidget();

    /* COMPONENTS JOUEUR 2 */
    // Image Blob
    this->imageBlobJoueur2 = new QLabel();
    QMovie *videoBlobJoueur2= new QMovie(":/Images/Images/GreenBlob.gif");
    videoBlobJoueur2->setScaledSize(QSize(150, 150));
    this->imageBlobJoueur2->setMovie(videoBlobJoueur2);
    // Position
    this->imageBlobJoueur2->setAlignment(Qt::AlignCenter);
    videoBlobJoueur2->start();
    // Components
    this->typeJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getNom()) );
    this->nomBlobJoueur2->setStyleSheet("font-family: Consolas;"
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
                                    "color: white;"
                                    "font-weight: bold;"
                                    "text-decoration: underline;");

    /* COMPONENTS JOUEUR 1 */
    // Image Blob
    this->imageBlobJoueur1 = new QLabel();
    QMovie *videoBlobJoueur1= new QMovie(":/Images/Images/BlobFabio.gif");
    videoBlobJoueur1->setScaledSize(QSize(150, 150));
    this->imageBlobJoueur1->setMovie(videoBlobJoueur1);
    // Position
    this->imageBlobJoueur1->setAlignment(Qt::AlignCenter);
    videoBlobJoueur1->start();
    // Components
    this->typeJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getNom()) );
    this->nomBlobJoueur1->setStyleSheet("font-family: Consolas;"
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
                                    "font-weight: bold;"
                                    "text-decoration: underline;");

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
                "background-color: grey;"
                "color: white;");
}

/* ########### LAYOUTS ########### */
void MainWindow::init_layout(){
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
void MainWindow::init_slots(){
    connect(this->boutonPasserTour, &QPushButton::released, this, &MainWindow::slotChangeJoueur);
    connect(this->boutonNormale, &QPushButton::released, this, &MainWindow::slotNormale);
    connect(this->boutonSoin, &QPushButton::released, this, &MainWindow::slotSoins);
    connect(this->boutonSpeciale, &QPushButton::released, this, &MainWindow::slotSpeciale);
}

void MainWindow::fermeJeux(){
    this->close();
}

/* ########### SLOTS ########### */
void MainWindow::slotChangeJoueur()
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
}

void MainWindow::slotNormale()
{
    this->arene->getCurrentPlayer()->useNormale(this->arene->getNotCurrentPlayer());
    // Refresh
    this->pvCourantJoueur1->setText( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur2->setText( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );

    // Buttons
    this->boutonNormale->setVisible(false);
    this->boutonSpeciale->setVisible(false);
    this->boutonSoin->setVisible(false);

    // Animation
    if (this->arene->getCurrentPlayer() == this->arene->getJoueur1()){
        this->pvCourantJoueur2->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }
    else
    {
        this->pvCourantJoueur1->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }
}

void MainWindow::slotSoins()
{
    this->arene->getCurrentPlayer()->useSoin();
    // Refresh
    this->pvCourantJoueur1->setText( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur2->setText( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );

    // Buttons
    this->boutonNormale->setVisible(false);
    this->boutonSpeciale->setVisible(false);
    this->boutonSoin->setVisible(false);
}

void MainWindow::slotSpeciale()
{
    this->arene->getCurrentPlayer()->useSpeciale(this->arene->getNotCurrentPlayer());
    // Refresh
    this->pvCourantJoueur1->setText( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->pvCourantJoueur2->setText( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );

    // Buttons
    this->boutonNormale->setVisible(false);
    this->boutonSpeciale->setVisible(false);
    this->boutonSoin->setVisible(false);

    // Animation
    if (this->arene->getCurrentPlayer() == this->arene->getJoueur1() && this->arene->getCurrentPlayer()->getBlob()->isTypeBetter(this->arene->getNotCurrentPlayer()->getBlob())){
        this->pvCourantJoueur2->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }
    else if(this->arene->getCurrentPlayer()->getBlob()->isTypeBetter(this->arene->getNotCurrentPlayer()->getBlob()))
    {
        this->pvCourantJoueur1->setStyleSheet("border-image: url(:/Images/Images/blood.png);"
                                            "font-family: Consolas;"
                                            "font-weight: bold;"
                                            "font-size: 15px;"
                                            "color: white;");
    }
}

/* ########### MAINWINDOW ########### */
MainWindow::~MainWindow()
{
    delete ui;
    delete this->vboxlayout;
    delete this->centre;
}

