/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>


/* FILES */
#include <Model/Blob.h>
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    Blob *b = new Blob("toto", 100, new Eau());
    b->afficheBlob();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
