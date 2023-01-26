/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Blob.h"
#include <QApplication>
#include "mainwindow.h"
#include "View/endWindow.h"

// ARENE
#include "Model/Arene/Arene.h"

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
    Soin *s2 = new Soin(50, "Fabio Soin");
    Speciale *sp2 = new Speciale(60, "Fabio Speciale");
    Normale *n2 = new Normale(40, "Fabio Attaque");

    // BLOBS
    Blob *f = new Blob("Noob", 100, new Eau(), sp, n, s);
    Blob *g = new Blob("FabioGODMODE", 9999, new Plante(), sp2, n2, s2);
    Blob *x = new Blob("FabioGODMODE", 9999, new Feu(), sp2, n2, s2);

    // JOUEUR
    Joueur *j1 = new Joueur("Noob", f);
    //j->afficherJoueur();

    Joueur *j2 = new Joueur("Fabio", g);
    // j2->afficherJoueur();

    Joueur *j3 = new Joueur("Fabio", x);

    // ARENE
    Arene *arene = new Arene("ARENA WAR", j1, j2);
    //arene->afficherArene();

    QApplication a(argc, argv);
    MainWindow w (arene);
    w.show();
    return a.exec();

    /* ACTIONS */
    return 0;
}
