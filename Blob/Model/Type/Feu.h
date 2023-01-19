#ifndef FEU_H
#define FEU_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Type.h"

class Feu : public virtual Type {
protected:
    std::string sensible;
    std::string resitant;
    std::string type;
public :
    Feu();
    std::string estSensible() const;
    std::string estResistant() const;
    std::string getType() const;
};

#endif // FEU_H
