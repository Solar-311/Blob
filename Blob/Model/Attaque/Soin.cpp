/* ########## INCLUDE ########## */
/* FILES */
#include "Soin.h"

/* ########## CONSTRUCTOR ########## */
Soin::Soin()
{
    this->soin = 0;
    this->nom = "None";
}

Soin::Soin(int soin)
{
    this->soin = soin;
    this->nom = "None";
}

Soin::Soin(int soin, std::string nom)
{
    this->soin = soin;
    this->nom = nom;
}

/* ######## GETTER & SETTER ######## */
std::string Soin::getNom()
{
    return nom;
}

void Soin::setNom(std::string newNom)
{
    nom = newNom;
}

int Soin::getSoin()
{
    return soin;
}

void Soin::setSoin(int newSoin)
{
    soin = newSoin;
}

/* ######## FUNCTIONS ######## */
void Soin::afficheAttaque()
{
    std::cout << "***** Soins *****" << std::endl;
    std::cout << "Nom : " << this->getNom() << std::endl;
    std::cout << "Valeur : " << this->getSoin() << std::endl;
    std::cout << "*****************" << std::endl;
}
