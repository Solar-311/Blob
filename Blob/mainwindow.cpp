/* ########## INCLUDE ########## */
/* LIBRARY */

/* FILES */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgrnd("/Others/Images/Background.png");
    QPalette palette;
    bkgrnd = bkgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, bkgrnd);
    this->setPalette(palette);
    this->setWindowTitle("Blob");
    this->setGeometry(100,100,800,600);
    this->init_components();
    this->init_layout();
    this->init_slots();
}

void MainWindow::init_components(){
    /* CENTRAL WIDGET */
    this->centre = new QWidget();

    /* COMPONENTS LAYOUT BACK */
    // Image Blob
    this->imageBlobAllier = new QLabel();
    QMovie *mavideo= new QMovie("C:/Users/Morin/Pictures/giphy.gif");
    mavideo->setScaledSize(QSize(100,100));
    this->imageBlobAllier->setMovie(mavideo);
    mavideo->start();
    // Components
    this->typeAdversaire = new QLabel("Plante"); // pareil
    this->nomAdversaire = new QLabel(); // pareil
    this->pvAdversaire = new QLabel("100");

    /* COMPONENTS LAYOUT FRONT */
    // Image Blob
    this->imageBlobEnnemie = new QLabel();
    QMovie *mavideo2= new QMovie("C:/Users/Morin/Pictures/Fabio.gif");
    mavideo2->setScaledSize(QSize(100,100));
    this->imageBlobEnnemie->setMovie(mavideo2);
    mavideo2->start();
    // Components
    this->pv = new QLabel("100");
    this->nom = new QLabel("Notre Blob");
    this->type = new QLabel("Feu"); // importer type.h et remplacer Feu

    /* COMPONENTS BOUTONS ATTAQUES */
    this->boutonAtttaqueNormale = new QPushButton("Attaque normale");
    this->boutonFuir = new QPushButton("fuir");
    this->boutonSoin = new QPushButton("Soin");
    this->boutonAttaqueSpe = new QPushButton("Attaque Speciale !"); // this.getcurrentplayer().getAttribut
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
    this->gridTrois->addWidget(boutonAtttaqueNormale,0,0);
    this->gridTrois->addWidget(boutonAttaqueSpe,0,1);
    this->gridTrois->addWidget(boutonSoin,1,0);
    this->gridTrois->addWidget(boutonFuir,1,1);

    /* ADD COMPONENTS LAYOUT BACK */
    this->hBoxUn->addWidget(new QLabel("Un"));
    this->hBoxUn->addWidget(new QLabel("deux"));
    this->hBoxUn->addWidget(new QPushButton("trois"));
    this->hBoxUn->addWidget(this->nomAdversaire);
    this->hBoxUn->addWidget(this->pvAdversaire);
    this->hBoxUn->addWidget(this->typeAdversaire);
    this->hBoxUn->addWidget(this->imageBlobEnnemie);

    /* ADD COMPONENTS LAYOUT FRONT */
    this->hBoxDeux->addWidget(this->nom);
    this->hBoxDeux->addWidget(this->pv);
    this->hBoxDeux->addWidget(this->type);
    this->hBoxDeux->addWidget(new QPushButton("quatre"));
    this->hBoxDeux->addWidget(new QLabel("cinq"));
    this->hBoxDeux->addWidget(new QLabel("six"));
    this->hBoxDeux->addWidget(this->imageBlobAllier);

    /* ADD COMPONENTS CENTRAL LAYOUT */
    this->vboxlayout = new QVBoxLayout();
    this->vboxlayout->addLayout(hBoxUn,1);
    this->vboxlayout->addLayout(hBoxDeux,2);
    this->vboxlayout->addLayout(gridTrois,3);

    /* SET VLAYOUT TO CENTRAL */
    this->centre->setLayout(this->vboxlayout);
}


void MainWindow::init_slots(){
    connect(this->boutonFuir, SIGNAL(clicked()),this,SLOT(fermeJeux()));
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

