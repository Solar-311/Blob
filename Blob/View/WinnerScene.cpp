/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>

/* FILES */
#include "WinnerScene.h"
#include "ui_mainwindow.h"

/* ########### MAINWINDOW ########### */
WinnerScene::WinnerScene(Arene *arene, QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow)
{
    this->arene = arene;
    ui->setupUi(this);

    /* BACKGROUND */
    this->lb = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getNom()) + " WON");
    this->lb->setStyleSheet("font-family: Consolas;"
                    "font-weight: bold;"
                    "font-size: 20px;"
                    "background-color: black;"
                    "color: white;");
    this->lb->setAlignment(Qt::AlignTop);
    this->lb->setAlignment(Qt::AlignHCenter);

    QMovie *movie = new QMovie(":/Images/Images/winBackground.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    processLabel->resize(this->size());
    movie->setScaledSize(QSize(this->geometry().width(), this->geometry().height()));
    movie->start();

    this->centre = new QWidget();
    this->setCentralWidget(this->centre);
    this->vboxlayout = new QVBoxLayout();
    this->vboxlayout->addWidget(processLabel);
    this->vboxlayout->addWidget(this->lb);
    this->centre->setLayout(this->vboxlayout);

    auto palette = this->palette();
    palette.setColor(QPalette::Window, Qt::black);
    this->setPalette(palette);

    /* WINDOW */
    this->setWindowTitle("You Won");
    this->setWindowIcon(QIcon(":/Images/Images/Icon.png"));
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    this->setAutoFillBackground(true);
}

WinnerScene::~WinnerScene()
{
    delete ui;
    delete this->centre;
    delete this->vboxlayout;
}
