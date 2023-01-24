/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Blob.h"
#include <QApplication>
#include "mainwindow.h"

// ARENE
#include "Model/Arene/Arene.h"

// ATTAQUE

// JOUEUR
#include "Model/Joueur/Joueur.h"

// TYPES
#include "Model/Type/Eau.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Plante.h"

// OUTILS

int main(int argc, char *argv[])
{
    /* PARAMETRES */
    //srand(time(nullptr));

    /* TESTS */
    // ATTAQUES
    Soin *s = new Soin(50, "Soin");
    Speciale *sp = new Speciale(60, "Speciale");
    Normale *n = new Normale(40, "Normale");

    // BLOBS
    Blob *f = new Blob("Noob", 100, new Eau(), sp, n, s);
    Blob *g = new Blob("FabioGODMODE", 9999, new Plante(), sp, n, s);

    // JOUEUR
    Joueur *j = new Joueur("Noob", f);
    //j->afficherJoueur();

    Joueur *j2 = new Joueur("Fabio", g);
    //j2->afficherJoueur();
    j2->useNormale(j);
    j->useSoin();
    j2->useSpeciale(j);
    j->afficherJoueur();

    // ARENE
    Arene *arene = new Arene("ARENA WAR", j, j2);
    //arene->afficherArene();

    /* UI *//*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/

    /* ACTIONS */
    return 0;
}
