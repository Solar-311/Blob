/* ########## INCLUDE ########## */
/* FILES */
#include "Attaque.h"

<<<<<<< HEAD

/* ########## CONSTRUCTOR ########## */

Attaque::Attaque()
{
    this->nom ="None";
    this->puissance = 0;
}

Attaque::Attaque(std::string nom)
{
    this->nom = nom;
    this->puissance = 0;
}

Attaque::Attaque(std::string nom, int puissance)
{
    this->nom = nom;
    this->puissance = puissance;
}


/* ########## GETTEUR/SETTEUR ########## */
std::string Attaque::getNom()
{
    return nom;
}

int Attaque::getPuissance()
{
    return puissance;
}

void Attaque::setNom(std::string nom)
{
       this->nom = nom;
}

void Attaque::setPuissance(int puissance)
{
    this->puissance = puissance;
}

/* ######## FUNCTIONS ######## */
int attaque()
{
    if ()
}
=======
/* ########## CONSTRUCTOR ########## */
Attaque::Attaque()
{

}

/* ######## GETTER & SETTER ######## */

>>>>>>> a514d5c6dbb88d223d3cc42d87cb58389accf7de
