#ifndef SPECIALE_H
#define SPECIALE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Blob.h"
#include "Model/Type/Eau.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Plante.h"

class Speciale{
    private :
        int multiplicateur;

    public :
        /* CONSTRUCTOR */
        Speciale();
        Speciale(int puissance);

        /* GETTER & SETTER */
        int getMultiplicateur();
        void setMultiplicateur(int newMultiplicateur);

        /* FUNCTIONS */
        int attaque(Blob blob1, Blob blob2);
};

#endif // SPECIALE_H
