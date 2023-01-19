#ifndef LISTBLOB_H
#define LISTBLOB_H

#include "Model/Blob.h"
#include <list>
#include "Model/Type/Type.h"
#include "Model/Type/Plante.h"
#include "Model/Type/Feu.h"
#include "Model/Type/Eau.h"

class ListBlob {
    protected :
       std::list<Blob> listeBlob;

    public :
        /* CONSTRUCTOR */
        ListBlob();

        Blob getBlob();
        void setBlob(Blob blob);

        Blob slectBlob (int numBlob);
};

#endif // LISTBLOB_H
