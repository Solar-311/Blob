#ifndef SPECIALE_H
#define SPECIALE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */

class Speciale{
    private :
        int puissance;
        std::string nom;

    public :
        /* CONSTRUCTOR */
        Speciale();
        Speciale(int puissance);
        Speciale(int puissance, std::string nom);

        /* GETTER & SETTER */
        int getPuissance();
        void setPuissance(int newPuissance);
        std::string getNom();
        void setNom(std::string newNom);

        /* FUNCTIONS */

};

#endif // SPECIALE_H
