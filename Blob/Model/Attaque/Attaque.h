#ifndef ATTAQUE_H
#define ATTAQUE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */


class Attaque{
    private :
        std::string nom;
        int puissance;

    public :
        /* CONSTRUCTOR */
        Attaque();
        Attaque(std::string nom);
        Attaque(std::string nom, int puissance);

        /* GETTER & SETTER */

        /* FUNCTIONS */
};

#endif // ATTAQUE_H
