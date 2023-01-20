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

Speciale::Speciale(int puissance, std::string nom)
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
int Speciale::hierarchie(Blob *blob1, Blob *blob2)
{
    bool result = false;

    if (blob1->getType()->estSensible() == "Plante" && blob2->getType()->estResistant() == "Plante")
    {
        result = true;
    }

    if (blob1->getType()->estSensible() == "Feu" && blob2->getType()->estResistant() == "Feu")
    {
        result = true;
    }

    if (blob1->getType()->estSensible() == "Eau" && blob2->getType()->estResistant() == "Eau")
    {
        result = true;
    }

    return result;
}
