/* ########## INCLUDE ########## */
/* FILES */
#include "Normale.h"

/* ########## CONSTRUCTOR ########## */
Normale::Normale()
{
    this->puissance = 0;
}

Normale::Normale(int puissance)
{
    this->puissance = puissance;
}

/* ######## GETTER & SETTER ######## */
int Normale::getPuissance()
{
    return puissance;
}

void Normale::setPuissance(int newPuissance)
{
    puissance = newPuissance;
}

/* ######## FUNCTIONS ######## */
int Normale::attaque(Blob blob)
{
    if(blob.getPv_courant() > 0)
    {
        blob.setPv_courant(blob.getPv_courant() - this->puissance);
    }
}

void Normale::afficheAttaque()
{
    std::cout << "***** Attaque *****" << std::endl;
    std::cout << "Valeur : " << this->getPuissance() << std::endl;
    std::cout << "*******************" << std::endl;
}
