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

// JOUEUR
#include "Model/Joueur/Joueur.h"

// TYPES
#include "Model/Type/Eau.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Plante.h"

// WINDOW
#include "View/FightScene.h"
#include "View/Menu.h"""

int main(int argc, char *argv[])
{
    /* PARAMETRES */
    //srand(time(nullptr));

    // BLOBS
    Soin *sfeu = new Soin(20, "Soin");
    Speciale *spfeu = new Speciale(40, "Speciale FEU");
    Normale *nfeu = new Normale(30, "Normale FEU");

    Soin *splante = new Soin(30, "Soin");
    Speciale *spplante = new Speciale(40, "Speciale PLANTE");
    Normale *nplante = new Normale(25, "Normale PLANTE");

    Soin *seau = new Soin(30, "Soin");
    Speciale *speau = new Speciale(40, "Speciale EAU");
    Normale *neau = new Normale(35, "Normale EAU");

    Blob *f = new Blob("Nooby Feu", 100, new Feu(), spfeu, nfeu, sfeu);
    Blob *p = new Blob("Bloby PLante", 9999, new Plante(), spplante, nplante, splante);
    Blob *e = new Blob("FabioGODMODE", 120, new Feu(), speau, neau, seau);
    // JOUEUR
    Joueur *j1 = new Joueur("Joueur 1", f);
    Joueur *j2 = new Joueur("Joueur 2", e);

    //Joueur *j3 = new Joueur("Fabio", x);

    // ARENE
    Arene *arene = new Arene("ARENA WAR", j1, j2);
    //arene->afficherArene();

    QApplication a(argc, argv);
    Menu m(arene);
    m.show();

    /*FightScene *fs = new FightScene(arene);
    fs->show();*/
    /* ACTIONS */
    return a.exec();
    return 0;
}
