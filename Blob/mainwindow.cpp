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
    QPixmap bkgrnd("C:/Users/Morin/Pictures/d83m36e-3b58ca48-fe8a-456e-9ffc-a5a84eca6613.png");
    QPalette palette;
    bkgrnd =bkgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, bkgrnd);
    this->setPalette(palette);
    this->setWindowTitle("Blob");
    this->setGeometry(100,100,800,600);
    this->init_components();
    this->init_layout();

}

void MainWindow::init_components(){
    this->centre = new QWidget();

    this->imageBlobAlier = new QLabel();
    QMovie *mavideo= new QMovie("C:/Users/Morin/Pictures/giphy.gif");
    mavideo->setScaledSize(QSize(100,100));
    this->imageBlobAlier->setMovie(mavideo);

    this->imageBlobEnnemie = new QLabel();
    QMovie *mavideo2= new QMovie("C:/Users/Morin/Pictures/Fabio.gif");
    mavideo2->setScaledSize(QSize(100,100));
    this->imageBlobEnnemie->setMovie(mavideo2);

    mavideo->start();
    mavideo2->start();

    this->nom = new QLabel("Notre Blob");
    this->type = new QLabel("Feu"); // importer type.h et remplacer Feu
    this->typeAdversaire = new QLabel("Plante"); // pareil
    this->nomAdversaire = new QLabel("BLob méchant"); // pareil
    this->boutonAtttaqueNormale = new QPushButton("Attaque normale");
    this->boutonFuir = new QPushButton("fuir");
    this->boutonSoin = new QPushButton("Soin");
    this->boutonAttaqueSpe = new QPushButton("Attaque Speciale !");
    this->pv = new QLabel("100");
    this->pvAdversaire = new QLabel("100");
}

void MainWindow::init_layout(){
    this->setCentralWidget(this->centre);
    this->hBoxUn = new QHBoxLayout();
    this->hBoxDeux = new QHBoxLayout();
    this->gridTrois = new QGridLayout();
    this->gridTrois->addWidget(boutonAtttaqueNormale,0,0);
    this->gridTrois->addWidget(boutonAttaqueSpe,0,1);
    this->gridTrois->addWidget(boutonSoin,1,0);
    this->gridTrois->addWidget(boutonFuir,1,1);
    this->hBoxUn->addWidget(new QLabel("Un"));
    this->hBoxUn->addWidget(new QLabel("deux"));
    this->hBoxUn->addWidget(new QPushButton("trois"));
    this->hBoxDeux->addWidget(this->nom);
    this->hBoxDeux->addWidget(this->pv);
    this->hBoxDeux->addWidget(this->type);
    this->hBoxDeux->addWidget(new QPushButton("quatre"));
    this->hBoxDeux->addWidget(new QLabel("cinq"));
    this->hBoxDeux->addWidget(new QLabel("six"));
    this->vboxlayout = new QVBoxLayout();
    this->vboxlayout->addLayout(hBoxUn,1);
    this->vboxlayout->addLayout(hBoxDeux,2);
    this->vboxlayout->addLayout(gridTrois,3);

    this->centre->setLayout(this->vboxlayout);

        // ...
        this->hBoxDeux->addWidget(this->nom);
        this->hBoxDeux->addWidget(this->pv);
        this->hBoxDeux->addWidget(this->type);
        this->hBoxDeux->addWidget(this->imageBlobAlier);
        // ...
        this->hBoxUn->addWidget(this->nomAdversaire);
        this->hBoxUn->addWidget(this->pvAdversaire);
        this->hBoxUn->addWidget(this->typeAdversaire);
        this->hBoxUn->addWidget(this->imageBlobEnnemie);
        // ...
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

