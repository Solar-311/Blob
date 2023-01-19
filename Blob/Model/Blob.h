#ifndef BLOB_H
#define BLOB_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Type/Type.h"
#include "Type/Plante.h"
#include "Type/Feu.h"
#include "Type/Eau.h"

class Blob{
    private :
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

        /* FUNCTIONS */
        void afficheBlob();
        void creerBlob();
};

#endif // BLOB_H
