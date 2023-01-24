#ifndef LISTBLOB_H
#define LISTBLOB_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <list>

/* FILES */
#include "Model/Blob.h"

// TYPES
#include "Model/Type/Plante.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Eau.h"

class ListBlob {
    protected :
       std::list<Blob> listeBlob;

    public :
        /* CONSTRUCTOR */
        ListBlob();

        /* GETTER & SETTER */
        Blob getBlob();
        void setBlob(Blob blob);

        /* FUNCTIONS */
        Blob slectBlob (int numBlob);
};

#endif // LISTBLOB_H
