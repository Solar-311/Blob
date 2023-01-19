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
    if ((blob.getPv() + soin) > 100 ||
         blob.getPv() > 0)
    {
        blob.setPv(100);
    }

    else
    {
        blob.setPv(blob.getPv() + soin);
    }
}
