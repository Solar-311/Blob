/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include <Model/Blob.h>
#include <QApplication>
#include "mainwindow.h"

// ATTAQUE

// TYPES
#include "Model/Type/Eau.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Plante.h"

// OUTILS

int main(int argc, char *argv[])
{
    /* PARAMETRES */
    //srand(time(nullptr));

    /* ACTIONS */
    Blob *f = new Blob("Fabio", 100, new Eau());
    Blob *g = new Blob("FabioGODMODE", 9999, new Plante());
    //f->afficheBlob();
    //f->setPv_courant(50);
    //f->afficheBlob();
    //std::cout << f->getPv_courant() << std::endl;
    Soin s = Soin(50, "Attaque soin");
    //s.afficheAttaque();
    //f->mettreSoins(f, s);
    //std::cout << f->getPv_courant() << std::endl;

    Normale n = Normale(40, "Attaque Normale");
    //n.afficheAttaque();
    //f->attaqueNormale(f, n);
    //std::cout << f->getPv_courant() << std::endl;

    //std::cout << f->isTypeBetter(g) << std::endl;
    Speciale sp = Speciale(60, "Attaque Speciale");

    return 0;
}
