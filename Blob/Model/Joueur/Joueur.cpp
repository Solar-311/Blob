/* ########## INCLUDE ########## */
/* FILES */
#include "Joueur.h"

/* ########## CONSTRUCTOR ########## */
Joueur::Joueur()
{
    this->nom = "None";
    this->blob = new Blob();
}

Joueur::Joueur(std::string nom)
{
    this->nom = nom;
    this->blob = new Blob();
}

Joueur::Joueur(std::string nom, Blob *blob)
{
    this->nom = nom;
    this->blob = blob;
}

/* ######## GETTER & SETTER ######## */
Blob *Joueur::getBlob()
{
    return blob;
}

void Joueur::setBlob(Blob *newBlob)
{
    blob = newBlob;
}

std::string Joueur::getNom()
{
    return nom;
}

void Joueur::setNom(std::string newNom)
{
    nom = newNom;
}

/* ######## FUNCTIONS ######## */
void Joueur::afficherJoueur()
{
    std::cout << "+---------- JOUEUR ----------+" << std::endl;
    std::cout << "Nom : " << this->getNom() << std::endl;
    std::cout << "***** Blob de " << this->getNom() << " *****" << std::endl;
    this->getBlob()->afficheBlob();
    std::cout << "+----------------------------+" << std::endl;
}

int Joueur::useSpeciale(Joueur *target)
{
    int speciale = this->getBlob()->attaqueSpeciale(target->getBlob(), this->getBlob()->getSpeciale());
    return speciale;
}

int Joueur::useSoin()
{
    int soin = this->getBlob()->mettreSoins(this->getBlob(), this->getBlob()->getSoin());
    return soin;
}

int Joueur::useNormale(Joueur *target)
{
    int normale = this->getBlob()->attaqueNormale(target->getBlob(), this->getBlob()->getNormale());
    return normale;
}
