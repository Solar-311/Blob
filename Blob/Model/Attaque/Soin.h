#ifndef SOIN_H
#define SOIN_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Model/Blob.h"

class Soin{
    private :
        int soin;

    public :
        /* CONSTRUCTOR */
        Soin();
        Soin(int soin);

        /* GETTER & SETTER */
        int getSoin();
        void setSoin(int newSoin);

        /* FUNCTIONS */
        int mettreSoins(Blob blob);
};

#endif // SOIN_H
