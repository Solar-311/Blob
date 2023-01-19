#ifndef EAU_H
#define EAU_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Type.h"

class Eau : public virtual Type {
protected:
    std::string sensible;
    std::string resitant;
    std::string type;
public :
    Eau();
    std::string estSensible() const;
    std::string estResistant() const;
    std::string getType() const;
};

#endif // EAU_H
