/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include <Model/Blob.h>
#include <QApplication>
#include "mainwindow.h"

// ATTAQUE
#include "Model/Attaque/Soin.h"
#include "Model/Attaque/Normale.h"

// TYPES
#include "Model/Type/Eau.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Plante.h"

int main(int argc, char *argv[])
{
    Blob *f = new Blob("Fabio", 100, new Eau());
    //f->afficheBlob();
    f->setPv_courant(80);
    //std::cout << f->getPv_courant() << std::endl;
    Soin s = Soin(50, "Attaque soin");
    //s.afficheAttaque();
    //f->mettreSoins(f, s);
    std::cout << f->getPv_courant() << std::endl;

    Normale n = Normale(40, "Attaque Normale");
    //n.afficheAttaque();
    f->attaque(f, n);
    std::cout << f->getPv_courant() << std::endl;

    return 0;
}
