/* ########## INCLUDE ########## */
/* FILES */
#include "Feu.h"

/* ########## CONSTRUCTOR ########## */
Feu::Feu()
{
    this->type="Feu";
    this->resitant="Plante";
    this->sensible="Eau";
    this->isBetter = false;
}

/* ######## GETTER & SETTER ######## */
std::string Feu::estResistant() const{
    return this->resitant;
}

std::string Feu::estSensible() const{
    return this->sensible;
}

std::string Feu::getType() const{
    return this->type;
}

/* ######## FUNCTIONS ######## */
