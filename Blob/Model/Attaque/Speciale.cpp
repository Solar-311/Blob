/* ########## INCLUDE ########## */
/* FILES */
#include "Speciale.h"

/* ########## CONSTRUCTOR ########## */
Speciale::Speciale()
{
    this->multiplicateur = 1;
    this->nom = "Speciale";
}

Speciale::Speciale(int multiplicateur)
{
    this->multiplicateur = multiplicateur;
    this->nom = "Speciale";
}

Speciale::Speciale(int multiplicateur, std::string nom)
{
    this->multiplicateur = multiplicateur;
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

int Speciale::getMultiplicateur()
{
    return multiplicateur;
}

void Speciale::setMultiplicateur(int newMultiplicateur)
{
    multiplicateur = newMultiplicateur;
}

/* ######## FUNCTIONS ######## */

