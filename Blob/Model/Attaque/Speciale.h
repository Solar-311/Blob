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

    public :
        /* CONSTRUCTOR */
        Speciale();
        Speciale(int puissance);

        /* GETTER & SETTER */
        int getPuissance();
        void setPuissance(int newPuissance);

        /* FUNCTIONS */

};

#endif // SPECIALE_H
