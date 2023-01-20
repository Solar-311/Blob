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
void Normale::afficheAttaque()
{
    std::cout << "***** Attaque *****" << std::endl;
    std::cout << "Valeur : " << this->getPuissance() << std::endl;
    std::cout << "*******************" << std::endl;
}
