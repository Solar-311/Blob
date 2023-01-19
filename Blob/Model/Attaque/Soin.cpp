/* ########## INCLUDE ########## */
/* FILES */
#include "Soin.h"

/* ########## CONSTRUCTOR ########## */
Soin::Soin()
{
    this->soin = 0;
}

Soin::Soin(int soin)
{
    this->soin = soin;
}

/* ######## GETTER & SETTER ######## */
int Soin::getSoin()
{
    return soin;
}

void Soin::setSoin(int newSoin)
{
    soin = newSoin;
}

/* ######## FUNCTIONS ######## */
int Soin::mettreSoins(Blob blob)
{
    if ((blob.getPv_courant() + soin) > blob.getPv() ||
         blob.getPv_courant() > 0)
    {
        blob.setPv(blob.getPv());
    }

    else
    {
        blob.setPv(blob.getPv_courant() + soin);
    }
}
