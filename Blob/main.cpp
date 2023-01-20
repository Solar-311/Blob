/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include <Model/Blob.h>
#include <QApplication>
#include "mainwindow.h"
#include "Model/Attaque/Normale.h"
#include "Model/Attaque/Soin.h"


int main(int argc, char *argv[])
{
    //Blob *b = new Blob("toto", 100, new Eau());
    //b->afficheBlob();

    Blob f = Blob("fabio", 100, new Eau());
    //f->afficheBlob();
    f.setPv_courant(10);
    std::cout << f.getPv_courant() << std::endl;
    Soin s = Soin(50, "Attaque soin");
    //s.afficheAttaque();
    std::cout << f.mettreSoins(f, s);
    std::cout << f.getPv_courant();
}
