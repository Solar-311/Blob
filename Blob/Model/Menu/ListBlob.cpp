/* ########## INCLUDE ########## */
/* FILES */
#include "Model/Menu/ListBlob.h"

/* ########## CONSTRUCTOR ########## */
ListBlob::ListBlob()
{
    this->listeBlob.emplace_back(new Blob("Rocoo",80, new Feu()), new Speciale(35, "Coup dur"), new Normale(25, "Penetration"), new Soin(30, "Orgasme"));
    this->listeBlob.emplace_back(new Blob("Johnny",110, new Eau()), new Speciale(30, "BlowJob"), new Normale(20, "Gonflement"), new Soin(20, "UwU"));
    this->listeBlob.emplace_back(new Blob("Freddy",69, new Plante()), new Speciale(45, "Coup dur"), new Normale(25, "Penetration"), new Soin(30, "Orgasme"));
    this->listeBlob.emplace_back(new Blob("Thwomp",130, new Plante()), new Speciale(25, "Thwomp !"), new Normale(15, "Thwomp ?"), new Soin(40, "Thwomp ..."));
    this->listeBlob.emplace_back(new Blob("Franck",85, new Feu()), new Speciale(40, "Casse-Couille"), new Normale(25, "Casse-Cul"), new Soin(25, "Casse-Gueule"));
    this->listeBlob.emplace_back(new Blob("Maskass",120, new Feu()), new Speciale(40, "Nique ta mere"), new Normale(25, "Suce"), new Soin(40, "Batard"));
    this->listeBlob.emplace_back(new Blob("Carlos", 70, new Eau()), new Speciale(40, "Ouch"), new Normale(25, "Pouf"), new Soin(30, "Orgasme"));
    this->listeBlob.emplace_back(new Blob("Jordy", 80, new Eau()), new Speciale(35, "Coup dur"), new Normale(25, "Penetration"), new Soin(30, "Orgasme"));
    this->listeBlob.emplace_back(new Blob("Juan", 79, new Plante()), new Speciale(40, "Coup dur"), new Normale(25, "Penetration"), new Soin(30, "Orgasme"));

    // EL GRANDE FABIO
    this->listeBlob.emplace_back(new Blob("Fabio", 999, new Eau()), new Speciale(70, "Sexiest Man Alive"), new Normale(50, "Cheveux Tranchants"), new Soin(150, "Shampooing Aux Oeufs"));
}

/* ######## GETTER & SETTER ######## */
std::list<Blob *> ListBlob::getListeBlob()
{
    return listeBlob;
}

void ListBlob::setListeBlob(std::list<Blob *> newListeBlob)
{
    listeBlob = newListeBlob;
}

/* ######## FUNCTIONS ######## */
