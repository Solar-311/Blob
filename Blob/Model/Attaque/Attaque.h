#ifndef ATTAQUE_H
#define ATTAQUE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */


class Attaque{
    private :

    public :
        /* CONSTRUCTOR */
        Attaque();

        /* GETTER & SETTER */
        std::string getNom();
        void setNom(std::string nom);
        int getPuissance();
        void setPuissance(int puissance);

        /* FUNCTIONS */
        int attaque();
};

#endif // ATTAQUE_H
