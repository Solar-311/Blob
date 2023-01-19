/* ########## INCLUDE ########## */
/* FILES */
#include "Model/Menu/ListBlob.h"

ListBlob::ListBlob()
{
    this->listeBlob.emplace_back(new Blob("Rocoo",80,new Feu()));
    this->listeBlob.emplace_back(new Blob("Johnny",110,new Eau()));
    this->listeBlob.emplace_back(new Blob("Freddy",69,new Plante()));
    this->listeBlob.emplace_back(new Blob("Thwomp",130,new Plante()));
    this->listeBlob.emplace_back(new Blob("Franck",85,new Feu()));
    //this->listeBlob.emplace_back(new Blob("Maskass",));
    this->listeBlob.emplace_back(new Blob("Carlos"));
    this->listeBlob.emplace_back(new Blob("Jordy"));
    this->listeBlob.emplace_back(new Blob("Juan"));

    this->listeBlob.emplace_back(new Blob("Fabio"));
}
