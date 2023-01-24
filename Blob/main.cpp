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
    // NE PAS OUBLIER DE SET LES TYPES

    /* TESTS */
    // ATTAQUES
    Soin *s = new Soin(50, "Attaque soin");
    Speciale *sp = new Speciale(60, "Attaque Speciale");
    Normale *n = new Normale(40, "Attaque Normale");

    // BLOBS
    Blob *f = new Blob("Fabio", 100, new Eau(), sp, n, s);
    Blob *g = new Blob("FabioGODMODE", 9999, new Plante());

    // JOUEUR
    Joueur *j = new Joueur("Fabio", g);
    j->afficherJoueur();

    Joueur *j2 = new Joueur("Fabio", f);
    j2->afficherJoueur();

    // ARENE
    Arene *arene = new Arene("ARENA WAR", j, j2);
    arene->afficherArene();

    /* UI */
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    /* ACTIONS */
    return 0;
}
