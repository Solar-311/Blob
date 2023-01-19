/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>


/* FILES */
#include <src/Game/Blob/Blob.h>
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    Blob *b = new Blob("toto");
    b->afficheBlob();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
