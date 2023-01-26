/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>

/* FILES */
#include "endwindow.h"
#include "ui_mainwindow.h"

endWindow::endWindow(Arene *arene, QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    this->arene = arene;
    ui->setupUi(this);

    /* BACKGROUND */
    this->lb = new QLabel( QString::fromStdString(this->arene->getJoueur1()->getNom()) + " WON");
    this->lb->setStyleSheet("font-family: Consolas;"
                            "font-weight: bold;"
                            "font-size: 15px;"
                            "color: white;");

    QMovie *movie = new QMovie(":/Images/Images/winBackground.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    processLabel->resize(this->size());
    movie->setScaledSize(QSize(this->geometry().width(), this->geometry().height()));
    movie->start();

    this->vboxlayout = new QVBoxLayout();
    this->vboxlayout->addWidget(processLabel);

    /* WINDOW */
    this->setWindowTitle("You Won");
    this->setWindowIcon(QIcon(":/Images/Images/Icon.png"));
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    this->setAutoFillBackground(true);
    this->show();
}

/* ########### MAINWINDOW ########### */
endWindow::~endWindow()
{
    delete ui;
}
