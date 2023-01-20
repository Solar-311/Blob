#ifndef NORMALE_H
#define NORMALE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */

class Normale{
    private :
        int puissance;
        std::string nom;

    public :
        /* CONSTRUCTOR */
        Normale();
        Normale(int puissance);
        Normale(int puissance, std::string nom);

        /* GETTER & SETTER */
        int getPuissance();
        void setPuissance(int newPuissance);

        /* FUNCTIONS */
        void afficheAttaque();
        std::string getNom();
        void setNom(std::string newNom);
};

#endif // NORMALE_H
