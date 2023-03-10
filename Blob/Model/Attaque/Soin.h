#ifndef SOIN_H
#define SOIN_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */

class Soin{
    private :
        std::string nom;
        int soin;

    public :
        /* CONSTRUCTOR */
        Soin();
        Soin(int soin);
        Soin(int soin, std::string nom);

        /* GETTER & SETTER */
        int getSoin();
        void setSoin(int newSoin);
        std::string getNom();
        void setNom(std::string newNom);

        /* FUNCTIONS */
        void afficheAttaque();
};

#endif // SOIN_H
