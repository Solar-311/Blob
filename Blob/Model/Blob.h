#ifndef BLOB_H
#define BLOB_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
// TYPES
#include "Type/Type.h"
#include "Model/Type/Plante.h"

// ATTAQUE
#include "Model/Attaque/Soin.h"
#include "Model/Attaque/Normale.h"
#include "Model/Attaque/Speciale.h"

//OUTILS
#include "Model/Utils/Utils.h"

class Blob {
    protected :
        std::string nom;
        int pv;
        int pv_courant;
        Type *type;
        std::string image;

    public :
        /* CONSTRUCTOR */
        Blob();
        Blob(std::string nom);
        Blob(std::string nom, int pv);
        Blob(std::string nom, int pv, Type *type);


        /* GETTER & SETTER */
        std::string getNom();
        void setNom(std::string newNom);
        int getPv();
        void setPv(int newPv);
        Type* getType();
        void setType(Type *newType);
        int getPv_courant();
        void setPv_courant(int newPv_courant);

        /* FUNCTIONS */
        void afficheBlob();
        void isDead(Blob blob);
        bool hierarchie(Blob *blob1, Blob *blob2);
        int mettreSoins(Blob *blob, Soin soin);
        int attaqueNormale(Blob *blob, Normale puissance);
        int attaqueSpeciale(Blob *blob, Normale puissance);
};

#endif // BLOB_H
