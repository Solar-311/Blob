#ifndef TYPE_H
#define TYPE_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */

class Type {
    protected :
        std::string type;

    public :
        /* CONSTRUCTOR */
        Type();
        Type(std::string type);

        /* GETTER & SETTER */
        std::string virtual estSensible() const = 0;
        std::string virtual estResistant() const = 0;
        std::string virtual getType() const = 0;

        /* FUNCTIONS */
};

#endif // TYPE_H
