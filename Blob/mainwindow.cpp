<<<<<<< HEAD
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

// ...

QGridLayout* layout = new QGridLayout();

QLabel* nomAllie = new QLabel("Notre Blob");
QLabel* typeAllie = new QLabel("Feu");
QLabel* pvAllie = new QLabel("100");
QLabel* imageAllie = new QLabel();
QPixmap imageAlliePixmap("chemin/vers/imageAllie.png");
//imageAllie->setPixmap(imageAlliePixmap);

QLabel* nomAdversaire = new QLabel("Blob méchant");
QLabel* typeAdversaire = new QLabel("Plante");
QLabel* pvAdversaire = new QLabel("100");
QLabel* imageAdversaire = new QLabel();
QPixmap imageAdversairePixmap("chemin/vers/imageAdversaire.png");
//imageAdversaire->setPixmap(imageAdversairePixmap);

QLayout->addWidget(nomAllie, 0, 0);
layout->addWidget(typeAllie, 1, 0);
layout->addWidget(pvAllie, 2, 0);
layout->addWidget(imageAllie, 3, 0);
layout->addWidget(nomAdversaire, 0, 1);
layout->addWidget(typeAdversaire, 1, 1);
layout->addWidget(pvAdversaire, 2, 1);
layout->addWidget(imageAdversaire, 3, 1);
=======
/* ########## INCLUDE ########## */
/* LIBRARY */

/* FILES */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowTitle("Blob");
    this->setGeometry(100,100,800,600);
    this->init_components();
    this->init_layout();

}

void MainWindow::init_components(){
    this->centre = new QWidget();
    this->nom = new QLabel("Notre Blob");
    this->type = new QLabel("Feu"); // importer type.h et remplacer Feu
    this->typeAdversaire = new QLabel("Plante"); // pareil
    this->nomAdversaire = new QLabel("BLob méchant"); // pareil
    this->boutonAtttaqueNormale = new QPushButton("Attaque normale");
    this->boutonFuir = new QPushButton("Attaque normale");
    this->boutonSoin = new QPushButton("Soin");
    this->boutonAttaqueSpe = new QPushButton("Attaque Speciale !");
    this->pv = new QLabel("100");
    this->pvAdversaire = new QLabel("100");
}

void MainWindow::init_layout(){
    QString imagePath ="C:/Users/Morin/Pictures/d83m36e-3b58ca48-fe8a-456e-9ffc-a5a84eca6613.png";
    this->setCentralWidget(this->centre);
    this->centre->setStyleSheet("background-image: url("+imagePath+");");
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
        // ...
        this->hBoxUn->addWidget(this->nomAdversaire);
        this->hBoxUn->addWidget(this->pvAdversaire);
        this->hBoxUn->addWidget(this->typeAdversaire);
        // ...
    }
    //this->imageLabelAdversaire->setPixmap(imageAdversaire);
    //this->imageLabelPerso->setPixmap(imagePerso);




MainWindow::~MainWindow()
{
    delete ui;
    delete this->vboxlayout;
    delete this->centre;
}
>>>>>>> ec3dc388f0d2dee0e23d7bbe5603ecfa21100669

setLayout(QLayout);
