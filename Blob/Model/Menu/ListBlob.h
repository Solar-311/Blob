#ifndef LISTBLOB_H
#define LISTBLOB_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <list>

/* FILES */
#include "Model/Blob.h"

class ListBlob {
    protected :
       std::list<Blob*> listeBlob;

    public :
        /* CONSTRUCTOR */
        ListBlob();

        /* GETTER & SETTER */
        std::list<Blob *> getListeBlob();
        void setListeBlob(std::list<Blob *> newListeBlob);

        /* FUNCTIONS */

};

#endif // LISTBLOB_H
