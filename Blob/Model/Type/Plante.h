#ifndef PLANTE_H
#define PLANTE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Type.h"

class Plante : public virtual Type {
protected:
    std::string sensible;
    std::string resitant;
    std::string type;

public :
    /* CONSTRUCTOR */
    Plante();

    /* GETTER & SETTER */
    std::string estSensible() const;
    std::string estResistant() const;
    std::string getType() const;

    /* FUNCTIONS */
};

#endif // PLANTE_H
