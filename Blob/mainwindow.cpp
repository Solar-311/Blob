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
    QPixmap bkgnd(":Images/Images/Background.png");
    QPalette palette;
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    /* WINDOW */
    this->setWindowTitle("Blob");
    this->setWindowIcon(QIcon(":Images/Images/Icon.png"));
    this->setFixedSize(this->geometry().width(), this->geometry().height());

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
    QMovie *videoBlobJoueur2= new QMovie(":Images/Images/GreenBlob.gif");
    videoBlobJoueur2->setScaledSize(QSize(150, 150));
    this->imageBlobJoueur2->setMovie(videoBlobJoueur2);
    videoBlobJoueur2->start();
    // Components
    this->typeJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getNom()) );
    this->pvCourantJoueur2 = new QLabel ( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );
    this->nomJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getNom()) );

    /* COMPONENTS JOUEUR 1 */
    // Image Blob
    this->imageBlobJoueur1 = new QLabel();
    QMovie *videoBlobJoueur1= new QMovie(":Images/Images/BlobFabio.gif");
    videoBlobJoueur1->setScaledSize(QSize(150, 150));
    this->imageBlobJoueur1->setMovie(videoBlobJoueur1);
    videoBlobJoueur1->start();
    // Components
    this->typeJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getNom()) );
    this->pvCourantJoueur1 = new QLabel ( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->nomJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getNom()) );

    /* GLOBAL COMPONENTS */
    this->boutonNormale = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getNormale()->getNom()) );
    this->boutonSoin = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSoin()->getNom()) );
    this->boutonSpeciale = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSpeciale()->getNom()) );
    this->boutonPasserTour = new QPushButton("NEXT");
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

    /* LAYOUT BOUTONS ATTAQUES */
    this->gridTrois = new QGridLayout();
    this->gridTrois->addWidget(boutonNormale,0,0);
    this->gridTrois->addWidget(boutonSpeciale,0,1);
    this->gridTrois->addWidget(boutonSoin,1,0);
    this->gridTrois->addWidget(boutonPasserTour,1,1);

    /* ADD COMPONENTS JOUEUR 2 */
    this->vBoxTopL->addWidget(this->nomJoueur2);
    this->vBoxTopL->addWidget(this->nomBlobJoueur2);
    this->vBoxTopL->addWidget(this->pvCourantJoueur2);
    this->vBoxTopR->addWidget(this->imageBlobJoueur2);

    /* ADD COMPONENTS JOUEUR 1 */
    this->vBoxTopL->addWidget(this->nomJoueur1);
    this->vBoxTopL->addWidget(this->nomBlobJoueur1);
    this->vBoxTopL->addWidget(this->pvCourantJoueur1);
    this->vBoxBottomL->addWidget(this->imageBlobJoueur1);

    /* LAYOUT ORGANISATION */
    this->vboxlayout = new QVBoxLayout();
    this->vboxlayout->addLayout(hBoxL);
    this->vboxlayout->addLayout(hBoxR);
    this->hBoxL->addLayout(vBoxTopL);
    this->hBoxL->addLayout(vBoxBottomL);
    this->hBoxR->addLayout(vBoxTopR);
    this->hBoxR->addLayout(vBoxBottomR);
    this->vBoxBottomR->addLayout(gridTrois,3);

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
}

/* ########### MAINWINDOW ########### */
MainWindow::~MainWindow()
{
    delete ui;
    delete this->vboxlayout;
    delete this->centre;
}

