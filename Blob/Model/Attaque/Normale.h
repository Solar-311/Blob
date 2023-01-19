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

    public :
        /* CONSTRUCTOR */
        Normale();
        Normale(int puissance);

        /* GETTER & SETTER */
        int getPuissance();
        void setPuissance(int newPuissance);

        /* FUNCTIONS */

};

#endif // NORMALE_H
