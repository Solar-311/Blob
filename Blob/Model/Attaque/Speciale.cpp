/* ########## INCLUDE ########## */
/* FILES */
#include "Speciale.h"

/* ########## CONSTRUCTOR ########## */
Speciale::Speciale()
{
    this->multiplicateur = 1;
}

Speciale::Speciale(int multiplicateur)
{
    this->multiplicateur = multiplicateur;
}

/* ######## GETTER & SETTER ######## */
int Speciale::getMultiplicateur()
{
    return multiplicateur;
}

void Speciale::setMultiplicateur(int newMultiplicateur)
{
    multiplicateur = newMultiplicateur;
}

/* ######## FUNCTIONS ######## */
int Speciale::attaque(Blob blob1, Blob blob2)
{
    if (blob1.getType()->estSensible() == "Plante")
    {
        if(blob2.getPv_courant() > 0)
        {
            blob2.setPv_courant(blob2.getPv_courant() /* rajouter attaque */);
        }
    }
}
