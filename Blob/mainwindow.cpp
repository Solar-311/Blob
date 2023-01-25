/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>

/* FILES */
#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::init_components(){
    /* CENTRAL WIDGET */
    this->centre = new QWidget();

    /* COMPONENTS LAYOUT BACK */
    /* JOUEUR 2 */
    // Image Blob
    this->imageBlobJoueur2 = new QLabel();
    QMovie *videoBlobJoueur2= new QMovie(":Images/Images/GreenBlob.gif");
    videoBlobJoueur2->setScaledSize(QSize(100, 100));
    this->imageBlobJoueur2->setMovie(videoBlobJoueur2);
    videoBlobJoueur2->start();
    // Components
    this->typeJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getBlob()->getNom()) );
    this->pvCourantJoueur2 = new QLabel ( QString::number(this->arene->getJoueur2()->getBlob()->getPv_courant()) );
    this->nomJoueur2 = new QLabel( QString::fromStdString(this->arene->getJoueur2()->getNom()) );

    /* COMPONENTS LAYOUT FRONT */
    /* JOUEUR 1 */
    // Image Blob
    this->imageBlobJoueur1 = new QLabel();
    QMovie *videoBlobJoueur1= new QMovie(":Images/Images/BlobFabio.gif");
    videoBlobJoueur1->setScaledSize(QSize(100, 100));
    this->imageBlobJoueur1->setMovie(videoBlobJoueur1);
    videoBlobJoueur1->start();
    // Components
    this->typeJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getType()->getType()) );
    this->nomBlobJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getBlob()->getNom()) );
    this->pvCourantJoueur1 = new QLabel ( QString::number(this->arene->getJoueur1()->getBlob()->getPv_courant()) );
    this->nomJoueur1 = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getNom()) );

    /* COMPONENT ATTAQUES */
    this->boutonNormale = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getNormale()->getNom()) );
    this->boutonSoin = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSoin()->getNom()) );
    this->boutonSpeciale = new QPushButton( QString::fromStdString(this->arene->getCurrentPlayer()->getBlob()->getSpeciale()->getNom()) );
    this->boutonPasserTour = new QPushButton("PASSER");
}

void MainWindow::init_layout(){
    /* CENTRAL WIDGET */
    this->setCentralWidget(this->centre);

    /* LAYOUT JOUEUR BACK */
    this->hBoxUn = new QHBoxLayout();

    /* LAYOUT JOUEUR FRONT */
    this->hBoxDeux = new QHBoxLayout();

    /* LAYOUT BOUTONS ATTAQUES */
    this->gridTrois = new QGridLayout();
    this->gridTrois->addWidget(boutonNormale,0,0);
    this->gridTrois->addWidget(boutonSpeciale,0,1);
    this->gridTrois->addWidget(boutonSoin,1,0);
    this->gridTrois->addWidget(boutonPasserTour,1,1);

    /* ADD COMPONENTS LAYOUT BACK */
    this->hBoxUn->addWidget(new QLabel("Un"));
    this->hBoxUn->addWidget(new QLabel("deux"));
    this->hBoxUn->addWidget(new QPushButton("trois"));
    this->hBoxUn->addWidget(this->nomBlobJoueur2);
    this->hBoxUn->addWidget(this->pvCourantJoueur2);
    this->hBoxUn->addWidget(this->typeJoueur2);
    this->hBoxUn->addWidget(this->imageBlobJoueur2);

    /* ADD COMPONENTS LAYOUT FRONT */
    this->hBoxDeux->addWidget(this->nomBlobJoueur1);
    this->hBoxDeux->addWidget(this->pvCourantJoueur1);
    this->hBoxDeux->addWidget(this->typeJoueur1);
    this->hBoxDeux->addWidget(new QPushButton("quatre"));
    this->hBoxDeux->addWidget(new QLabel("cinq"));
    this->hBoxDeux->addWidget(new QLabel("six"));
    this->hBoxDeux->addWidget(this->imageBlobJoueur1);

    /* ADD COMPONENTS CENTRAL LAYOUT */
    this->vboxlayout = new QVBoxLayout();
    this->vboxlayout->addLayout(hBoxUn,1);
    this->vboxlayout->addLayout(hBoxDeux,2);
    this->vboxlayout->addLayout(gridTrois,3);

    /* SET VLAYOUT TO CENTRAL */
    this->centre->setLayout(this->vboxlayout);
}

void MainWindow::init_slots(){
    connect(this->boutonPasserTour, SIGNAL(clicked()),this,SLOT(fermeJeux()));
}

void MainWindow::fermeJeux(){
    std::cout<<"aaaahhh"<<std::endl;
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->vboxlayout;
    delete this->centre;
}

