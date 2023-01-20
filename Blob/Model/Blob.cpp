/* ########## INCLUDE ########## */
/* FILES */
#include "Blob.h"

/* ########## CONSTRUCTOR ########## */
Blob::Blob()
{
    this->nom = "None";
    this->pv = 0;
    this->type = new Plante();
    this->pv_courant = 0;
}

Blob::Blob(std::string nom)
{
    this->nom = nom;
    this->pv = 0;
    this->pv_courant = 0;
    this->type = new Plante();
}

Blob::Blob(std::string nom, int pv)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant = 0;
    this->type = new Plante();
}

Blob::Blob(std::string nom, int pv, Type *type)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant = pv;
    this->type = type;
}

/* ######## GETTER & SETTER ######## */
std::string Blob::getNom()
{
    return nom;
}

void Blob::setNom(std::string newNom)
{
    nom = newNom;
}

int Blob::getPv()
{
    return pv;
}

void Blob::setPv(int newPv)
{
    pv = newPv;
}

Type* Blob::getType()
{
    return this->type;
}

void Blob::setType(Type *newType)
{
    type = newType;
}

int Blob::getPv_courant()
{
    return pv_courant;
}

void Blob::setPv_courant(int newPv_courant)
{
    pv_courant = newPv_courant;
}

/* ######## FUNCTIONS ######## */
void Blob::afficheBlob()
{
    std::cout << "********** BLOB **********" << std::endl;
    std::cout << "Nom : " << this->nom << std::endl;
    std::cout << "Pv : " << this->pv << std::endl;
    std::cout << "Pv courant : " << this->pv_courant << std::endl;
    std::cout << "Type : "<< this->type->getType() << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << std::endl;
}

int Blob::mettreSoins(Blob *blob, Soin soin)
{
    if ((blob->getPv_courant() + soin.getSoin()) > blob->getPv() &&
         blob->getPv_courant() > 0)
    {
        blob->setPv_courant(blob->getPv());
    }

    else if (blob->getPv_courant() > 0)
    {
        blob->setPv_courant(blob->getPv_courant() + soin.getSoin());
    }

    return blob->getPv_courant();
}

int Blob::attaque(Blob *blob, Normale puissance)
{
    int crit = Utils::generateRandomNumber(0, 100);
    int chanceCrit = 10;
    int lowCritRate = 25;
    int highCritRate = 35;
    int damage = Utils::generateRandomNumber(lowCritRate, highCritRate);
    int critical = (puissance.getPuissance() * (100 + damage) / 100);

    if (blob->getPv_courant() > 0)
    {
        if (crit <= chanceCrit)
        {
            std::cout << "***** COUP CRITIQUE *****" << std::endl;
            blob->setPv_courant(blob->getPv_courant() - critical);
        }

        else
        {
            blob->setPv_courant(blob->getPv_courant() - puissance.getPuissance());
        }
    }

    return blob->getPv_courant();
}

void Blob::isDead(Blob blob)
{
    if (blob.getPv_courant() < 0)
    {
        std::cout << "BLOB MORT" << std::endl;
    }

    else
    {
        std::cout << "BLOB VIVANT" << std::endl;
    }
}
