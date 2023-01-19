/* ########## INCLUDE ########## */
/* FILES */
#include "Blob.h"

/* ########## CONSTRUCTOR ########## */
Blob::Blob()
{
    this->nom = "None";
    this->pv = 0;
<<<<<<< HEAD:Blob/Model/Blob.cpp
    this->type = new Type("Plante");
=======
    this->type = ;
>>>>>>> f4cd40f3fca0b0596b765b4dfc82c8fef909d9c2:Bubl/src/Game/Blob/Blob.cpp
}

Blob::Blob(std::string nom)
{
    this->nom = nom;
    this->pv = 0;
    this->type = Type();
}

Blob::Blob(std::string nom, int pv)
{
    this->nom = nom;
    this->pv = pv;
    this->type = Type();
}

Blob::Blob(std::string nom, int pv, Type type)
{
    this->nom = nom;
    this->pv = pv;
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

Type Blob::getType()
{
    return type;
}

void Blob::setType(Type newType)
{
    type = newType;
}

/* ######## FUNCTIONS ######## */
void Blob::afficheBlob(){
    std::cout <<
        "********** BLOB **********" <<
        "Nom : " << this->nom <<
        "Pv : " << this->pv <<
        "Type : ";
    std::cout <<
        "**************************" <<
        "\n" <<
    std::endl;
}

