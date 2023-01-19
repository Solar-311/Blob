/* ########## INCLUDE ########## */
/* FILES */
#include "Plante.h"

/* ########## CONSTRUCTOR ########## */
Plante::Plante()
{
    this->type="Plante";
    this->resitant="Eau";
    this->sensible="Feu";
}

std::string Plante::estResistant() const{
    return this->resitant;
}

std::string Plante::estSensible() const{
    return this->sensible;
}

std::string Plante::getType() const{
    return this->type;
}
