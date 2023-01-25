/* ########## INCLUDE ########## */
/* FILES */
#include "Speciale.h"

/* ########## CONSTRUCTOR ########## */
Speciale::Speciale()
{
    this->puissance = 0;
    this->nom = "Speciale";
}

Speciale::Speciale(int puissance)
{
    this->puissance = puissance;
    this->nom = "Speciale";
}

Speciale::Speciale(int puissance, std::string nom)
{
    this->puissance = puissance;
    this->nom = nom;
}

/* ######## GETTER & SETTER ######## */
std::string Speciale::getNom()
{
    return nom;
}

void Speciale::setNom(std::string newNom)
{
    nom = newNom;
}

int Speciale::getPuissance()
{
    return puissance;
}

void Speciale::setPuissance(int newPuissance)
{
    puissance = newPuissance;
}

/* ######## FUNCTIONS ######## */
void Speciale::afficheAttaqueSpeciale()
{
    std::cout << "***** Speciale *****" << std::endl;
    std::cout << "Nom : " << this->getNom() << std::endl;
    std::cout << "Valeur : " << this->getPuissance() << std::endl;
    std::cout << "*****************" << std::endl;
}
