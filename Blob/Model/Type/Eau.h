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
        /* CONSTRUCTOR */
        Eau();

        /* GETTER & SETTER */
        std::string estSensible() const;
        std::string estResistant() const;
        std::string getType() const;

        /* FUNCTIONS */
};

#endif // EAU_H
