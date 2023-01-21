/* ########## INCLUDE ########## */
/* FILES */
#include "Type.h"

/* ########## CONSTRUCTOR ########## */
Type::Type()
{
    //NULL
}


Type::Type(std::string type)
{
    this->type=type;
}

/* ######## GETTER & SETTER ######## */
bool Type::getIsBetter()
{
    return isBetter;
}

void Type::setIsBetter(bool newIsBetter)
{
    isBetter = newIsBetter;
}

/* ######## FUNCTIONS ######## */
bool Type::hierarchie(Type *type)
{
    if (this->estResistant() == "Plante" && type->estSensible() == "Plante")
    {
        setIsBetter(true);
    }

    if (this->estResistant() == "Feu" && type->estSensible() == "Feu")
    {
        setIsBetter(true);
    }

    if (this->estResistant() == "Eau" && type->estSensible() == "Eau")
    {
        setIsBetter(true);
    }

    return getIsBetter();
}
