/* ########## INCLUDE ########## */
/* FILES */
#include "Speciale.h"

/* ########## CONSTRUCTOR ########## */
Speciale::Speciale()
{
    this->puissance = 0;
}

Speciale::Speciale(int puissance)
{
    this->puissance = puissance;
}

/* ######## GETTER & SETTER ######## */
int Speciale::getPuissance()
{
    return puissance;
}

void Speciale::setPuissance(int newPuissance)
{
    puissance = newPuissance;
}

/* ######## FUNCTIONS ######## */

