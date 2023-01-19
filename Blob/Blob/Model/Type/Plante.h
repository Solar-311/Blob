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
    Plante();
    std::string estSensible() const;
    std::string estResistant() const;
    std::string getType() const;
};

#endif // PLANTE_H
