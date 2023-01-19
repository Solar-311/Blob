#ifndef BLOB_H
#define BLOB_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <iostream>
#include <stdio.h>

/* FILES */
#include "Type/Type.h"

class Blob{
    private :
        std::string nom;
        int pv;
        Type *type;
        std::string image;

    public :
        /* CONSTRUCTOR */
        Blob();
<<<<<<< HEAD

=======
>>>>>>> 2bdd28f6a43ec28637738b1b0cb8fd68f69e6987
        Blob(std::string nom);
        Blob(std::string nom, int pv);
        Blob(std::string nom, int pv, Type type);

<<<<<<< HEAD

=======
>>>>>>> 2bdd28f6a43ec28637738b1b0cb8fd68f69e6987
        /* GETTER & SETTER */
        std::string getNom();
        void setNom(std::string newNom);
        int getPv();
        void setPv(int newPv);
        Type getType();
        void setType(Type newType);

        /* FUNCTIONS */
        void afficheBlob();
        void creerBlob();
};

#endif // BLOB_H
