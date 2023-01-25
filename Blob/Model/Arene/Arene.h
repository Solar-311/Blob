#ifndef ARENE_H
#define ARENE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Joueur/Joueur.h"

class Arene{
    private :
        std::string nom;
        Joueur *joueur1;
        Joueur *joueur2;
        Joueur *currentPlayer;
        Joueur *notCurrentPlayer;

    public :
        /* CONSTRUCTOR */
        Arene();
        Arene(std::string nom);
        Arene(std::string nom, Joueur *joueur1);
        Arene(std::string nom, Joueur *joueur1, Joueur *joueur2);

        /* GETTER & SETTER */
        std::string getNom();
        void setNom(std::string newNom);
        Joueur *getJoueur1();
        void setJoueur1(Joueur *newJoueur);
        Joueur *getJoueur2();
        void setJoueur2(Joueur *newJoueur2);
        Joueur *getCurrentPlayer();
        void setCurrentPlayer(Joueur *newCurrentPlayer);
        Joueur *getNotCurrentPlayer();
        void setNotCurrentPlayer(Joueur *newNotCurrentPlayer);

        /* FUNCTIONS */
        void afficherArene();
        Joueur* changeJoueur();
};

#endif // ARENE_H
