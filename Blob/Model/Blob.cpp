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
    this->isBetter = false;
    this->normale = new Normale();
    this->speciale = new Speciale();
    this->soin = new Soin();
}

Blob::Blob(std::string nom)
{
    this->nom = nom;
    this->pv = 0;
    this->pv_courant = 0;
    this->type = new Plante();
    this->isBetter = false;
    this->normale = new Normale();
    this->speciale = new Speciale();
    this->soin = new Soin();
}

Blob::Blob(std::string nom, int pv)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant = 0;
    this->type = new Plante();
    this->isBetter = false;
    this->normale = new Normale();
    this->speciale = new Speciale();
    this->soin = new Soin();
}

Blob::Blob(std::string nom, int pv, Type *type)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant = pv;
    this->type = type;
    this->isBetter = false;
    this->normale = new Normale();
    this->speciale = new Speciale();
    this->soin = new Soin();
}

Blob::Blob(std::string nom, int pv, Type *type, Speciale *speciale)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant = pv;
    this->type = type;
    this->isBetter = false;
    this->normale = new Normale();
    this->speciale = speciale;
    this->soin = new Soin();
}

Blob::Blob(std::string nom, int pv, Type *type, Speciale *speciale, Normale *normale)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant = pv;
    this->type = type;
    this->isBetter = false;
    this->normale = normale;
    this->speciale = speciale;
    this->soin = new Soin();
}

Blob::Blob(std::string nom, int pv, Type *type, Speciale *speciale, Normale *normale, Soin *soin)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant = pv;
    this->type = type;
    this->isBetter = false;
    this->normale = normale;
    this->speciale = speciale;
    this->soin = soin;
}

/* ######## GETTER & SETTER ######## */
bool Blob::getIsBetter()
{
    return isBetter;
}

void Blob::setIsBetter(bool newIsBetter)
{
    isBetter = newIsBetter;
}

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
    if (newPv > 0)
    {
        pv = newPv;
    }

    else
    {
        pv = 0;
    }
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
    if (newPv_courant  > 0)
    {
        pv_courant = newPv_courant;
    }

    else
    {
        pv_courant = 0;
    }
}

Speciale *Blob::getSpeciale()
{
    return speciale;
}

void Blob::setSpeciale(Speciale *newSpeciale)
{
    speciale = newSpeciale;
}

Normale *Blob::getNormale()
{
    return normale;
}

void Blob::setNormale(Normale *newNormale)
{
    normale = newNormale;
}

Soin *Blob::getSoin()
{
    return soin;
}

void Blob::setSoin(Soin *newSoin)
{
    soin = newSoin;
}

/* ######## FUNCTIONS ######## */
void Blob::afficheBlob()
{
    std::cout << "---------- Etat ----------" << std::endl;
    std::cout << "Nom : " << this->nom << std::endl;
    std::cout << "Pv : " << this->pv << std::endl;
    std::cout << "Pv courant : " << this->pv_courant << std::endl;
    std::cout << "Type : "<< this->type->getType() << std::endl;
    std::cout << "Attaque Speciale : " << this->getSpeciale()->getPuissance() << std::endl;
    std::cout << "Attaque Normale : "<< this->getNormale()->getPuissance() << std::endl;
    std::cout << "Attaque Soin : "<< this->getSoin()->getSoin() << std::endl;
    std::cout << "--------------------------" << std::endl;
}

int Blob::mettreSoins(Blob *blob, Soin *soin)
{
    if ((blob->getPv_courant() + soin->getSoin()) > blob->getPv() &&
         blob->getPv_courant() > 0)
    {
        blob->setPv_courant(blob->getPv());
    }

    else if (blob->getPv_courant() > 0)
    {
        blob->setPv_courant(blob->getPv_courant() + soin->getSoin());
    }

    return blob->getPv_courant();
}

int Blob::attaqueNormale(Blob *blob, Normale *puissance)
{
    int crit = Utils::generateRandomNumber(0, 100);
    int chanceCrit = 10;
    int lowCritRate = 25;
    int highCritRate = 35;
    int damage = Utils::generateRandomNumber(lowCritRate, highCritRate);
    int critical = (puissance->getPuissance() * (100 + damage) / 100);

    if (blob->getPv_courant() > 0)
    {
        if (crit <= chanceCrit)
        {
            std::cout << "***** COUP CRITIQUE *****" << std::endl;
            blob->setPv_courant(blob->getPv_courant() - critical);
        }

        else
        {
            blob->setPv_courant(blob->getPv_courant() - puissance->getPuissance());
        }
    }

    return blob->getPv_courant();
}

int Blob::attaqueSpeciale(Blob *blob, Speciale *speciale)
{
    this->isTypeBetter(blob);

    int crit = Utils::generateRandomNumber(0, 100);
    int chanceCrit = 5;
    int lowCritRate = 20;
    int highCritRate = 25;
    int damage = Utils::generateRandomNumber(lowCritRate, highCritRate);
    int critical = (speciale->getPuissance() * (100 + damage) / 100);

    if (blob->getPv_courant() > 0 && this->getIsBetter() == true)
    {
        if (crit <= chanceCrit)
        {
            std::cout << "***** COUP SPECIAL CRITIQUE *****" << std::endl;
            blob->setPv_courant(blob->getPv_courant() - critical);
        }

        else
        {
            blob->setPv_courant(blob->getPv_courant() - speciale->getPuissance());
        }
    }

    return blob->getPv_courant();
}

bool Blob::isTypeBetter(Blob *blob)
{
    if (this->getType()->estResistant() == blob->getType()->estSensible())
    {
        setIsBetter(true);
    }

    return getIsBetter();
}

void Blob::isDead(Blob blob)
{
    if (blob.getPv_courant() < 0)
    {
        std::cout << "***** BLOB MORT *****" << std::endl;
    }

    else
    {
        std::cout << "***** BLOB VIVANT *****" << std::endl;
    }
}
