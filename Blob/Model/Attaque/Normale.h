#ifndef NORMALE_H
#define NORMALE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Blob.h"

class Normale{
    private :
        int puissance;

    public :
        /* CONSTRUCTOR */
        Normale();
        Normale(int puissance);

        /* GETTER & SETTER */
        int getPuissance();
        void setPuissance(int newPuissance);

        /* FUNCTIONS */
        int attaque(Blob blob);
        void afficheAttaque();
};

#endif // NORMALE_H
