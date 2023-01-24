/* ########## INCLUDE ########## */
/* FILES */
#include "Eau.h"

/* ########## CONSTRUCTOR ########## */
Eau::Eau()
{
    this->type="Eau";
    this->resitant="Feu";
    this->sensible="Plante";
}

/* ######## GETTER & SETTER ######## */
std::string Eau::estResistant() const{
    return this->resitant;
}

std::string Eau::estSensible() const{
    return this->sensible;
}

std::string Eau::getType() const{
    return this->type;
}

/* ######## FUNCTIONS ######## */
