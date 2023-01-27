/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>

/* FILES */
#include "mainwindow.h"
#include "ui_mainwindow.h"

/* ########### CONSTRUCTOR ########### */
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
    this->init_layouts();
    //this->init_slots();
}

void MainWindow::init_components()
{
    /* CENTRAL WIDGET */
    this->centre = new QWidget();
    this->lb = new QLabel("CHOISISSEZ VOTRE BLOB");
    this->text1 = new QLineEdit("Nom Joueur 1");
    this->text2 = new QLineEdit("Nom Joueur 2");
    this->bouton = new QPushButton("Valider");
}

void MainWindow::init_layouts()
{
    this->setCentralWidget(this->centre);

    this->hBoxTop->addWidget(this->lb);
    this->hBoxBottom->addWidget(this->text1);
    this->hBoxBottom->addWidget(this->text2);
    this->bottom->addWidget(this->bouton);

    this->vboxlayout = new QVBoxLayout();
    this->hBoxTop = new QHBoxLayout();
    this->hBoxBottom = new QHBoxLayout();
    this->bottom = new QHBoxLayout();

    this->vboxlayout->addLayout(this->hBoxTop);
    this->vboxlayout->addLayout(this->hBoxBottom);
    this->vboxlayout->addLayout(this->bottom);
    this->centre->setLayout(this->vboxlayout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->centre;
    delete this->vboxlayout;
}
