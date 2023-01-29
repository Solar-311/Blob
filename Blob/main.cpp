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

    // ARENE
    Arene *arene = new Arene("ARENA WAR", new Joueur(),  new Joueur());
    //arene->afficherArene();

    QApplication a(argc, argv);
    Menu m(arene);
    m.show();

    return a.exec();
    return 0;
}
