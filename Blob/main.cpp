/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Blob.h"
#include <QApplication>
#include "mainwindow.h"

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
    Soin s = Soin(50, "Attaque soin");
    Speciale sp = Speciale(60, "Attaque Speciale");
    Normale n = Normale(40, "Attaque Normale");

    // BLOBS
    Blob *f = new Blob("Fabio", 100, new Eau());
    Blob *g = new Blob("FabioGODMODE", 9999, new Plante());

    // JOUEUR
    Joueur *j = new Joueur("Fabio", f);
    j->afficherJoueur();

    /* ACTIONS */
    return 0;
}
