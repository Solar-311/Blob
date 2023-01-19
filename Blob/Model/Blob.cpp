/* ########## INCLUDE ########## */
/* FILES */
#include "Blob.h"


/* ########## CONSTRUCTOR ########## */
Blob::Blob()
{
    this->nom = "None";
    this->pv = 0;
    this->type = new Plante();
    this->pv_courant=0;
}

Blob::Blob(std::string nom)
{
    this->nom = nom;
    this->pv = 0;
    this->pv_courant=0;
    this->type = new Plante();
}

Blob::Blob(std::string nom, int pv)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant=pv;
    this->type = new Plante();
}

Blob::Blob(std::string nom, int pv, Type *type)
{
    this->nom = nom;
    this->pv = pv;
    this->pv_courant=pv;
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
    if(newPv > 50 && newPv < 100){
        pv = newPv;
    }
    else{
        std::cout << "ERROR pv : must be 50 < pv < 100" << std::endl;
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

/* ######## FUNCTIONS ######## */
void Blob::afficheBlob(){
    std::cout << "********** BLOB **********" << std::endl;
    std::cout << "Nom : " << this->nom << std::endl;
    std::cout << "Pv : " << this->pv << std::endl;
    std::cout << "Type : "<< this->type->getType() << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << std::endl;
}

