/* ########## INCLUDE ########## */
/* FILES */
#include "Type.h"

/* ########## CONSTRUCTOR ########## */
Type::Type()
{
    this->isBetter = false;
}


Type::Type(std::string type)
{
    this->type = type;
    this->isBetter = false;
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
    if (this->type == "Plante" && type->estSensible() == "Plante")
    {
        setIsBetter(true);
    }

    if (this->type == "Feu" && type->estSensible() == "Feu")
    {
        setIsBetter(true);
    }

    if (this->type == "Eau" && type->estSensible() == "Eau")
    {
        setIsBetter(true);
    }

    return getIsBetter();
}
