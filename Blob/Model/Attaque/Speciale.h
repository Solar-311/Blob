#ifndef SPECIALE_H
#define SPECIALE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Type/Eau.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Plante.h"

class Speciale{
    private :
        int multiplicateur;
        std::string nom;

    public :
        /* CONSTRUCTOR */
        Speciale();
        Speciale(int puissance);
        Speciale(int puissance, std::string nom);

        /* GETTER & SETTER */
        int getMultiplicateur();
        void setMultiplicateur(int newMultiplicateur);
        std::string getNom();
        void setNom(std::string newNom);

        /* FUNCTIONS */

};

#endif // SPECIALE_H
