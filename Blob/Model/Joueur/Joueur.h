#ifndef JOUEUR_H
#define JOUEUR_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Blob.h"

class Joueur {
    private :
        std::string nom;
        Blob *blob;

    public :
        /* CONSTRUCTOR */
        Joueur();
        Joueur(std::string nom);
        Joueur(std::string nom, Blob *blob);

        /* GETTER & SETTER */
        std::string getNom();
        void setNom(std::string newNom);
        Blob *getBlob();
        void setBlob(Blob *newBlob);

        /* FUNCTIONS */
        void afficherJoueur();
};

#endif // JOUEUR_H
