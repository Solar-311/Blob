/* ########## INCLUDE ########## */
/* FILES */
#include "Normale.h"

/* ########## CONSTRUCTOR ########## */
Normale::Normale()
{
    this->puissance = 0;
    //this->nom = "Normale";
}

Normale::Normale(int puissance)
{
    this->puissance = puissance;
    //this->nom = "Normale";
}

Normale::Normale(int puissance, std::string nom)
{
    this->puissance = puissance;
    this->nom = nom;
}

/* ######## GETTER & SETTER ######## */
std::string Normale::getNom()
{
    return nom;
}

void Normale::setNom(std::string newNom)
{
    nom = newNom;
}

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
    std::cout << "Nom : " << this->getNom() << std::endl;
    std::cout << "Valeur : " << this->getPuissance() << std::endl;
    std::cout << "*******************" << std::endl;
}
