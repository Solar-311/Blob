/* ########## INCLUDE ########## */
/* FILES */
#include "Arene.h"

/* ########## CONSTRUCTOR ########## */
Arene::Arene()
{
    this->nom = "Arene";
    this->joueur1 = new Joueur();
    this->joueur2 = new Joueur();
    this->currentPlayer = new Joueur();
    this->notCurrentPlayer = new Joueur();
}

Arene::Arene(std::string nom)
{
    this->nom = nom;
    this->joueur1 = new Joueur();
    this->joueur2 = new Joueur();
    this->currentPlayer = new Joueur();
    this->notCurrentPlayer = new Joueur();
}

Arene::Arene(std::string nom, Joueur *joueur1)
{
    this->nom = nom;
    this->joueur1 = joueur1;
    this->joueur2 = new Joueur();
    this->currentPlayer = new Joueur();
    this->notCurrentPlayer = new Joueur();
}

Arene::Arene(std::string nom, Joueur *joueur1, Joueur *joueur2)
{
    this->nom = nom;
    this->joueur1 = joueur1;
    this->joueur2 = joueur2;
    this->currentPlayer = joueur2;
    this->notCurrentPlayer = joueur1;
}

/* ######## GETTER & SETTER ######## */
Joueur *Arene::getJoueur1()
{
    return joueur1;
}

void Arene::setJoueur1(Joueur *newJoueur1)
{
    joueur1 = newJoueur1;
}

Joueur *Arene::getJoueur2()
{
    return joueur2;
}

void Arene::setJoueur2(Joueur *newJoueur2)
{
    joueur2 = newJoueur2;
}

std::string Arene::getNom()
{
    return nom;
}

void Arene::setNom(std::string newNom)
{
    nom = newNom;
}

Joueur *Arene::getCurrentPlayer()
{
    return currentPlayer;
}

void Arene::setCurrentPlayer(Joueur *newCurrentPlayer)
{
    currentPlayer = newCurrentPlayer;
}

Joueur *Arene::getNotCurrentPlayer()
{
    return notCurrentPlayer;
}

void Arene::setNotCurrentPlayer(Joueur *newNotCurrentPlayer)
{
    notCurrentPlayer = newNotCurrentPlayer;
}

/* ######## FUNCTIONS ######## */
void Arene::afficherArene()
{
    std::cout << std::endl;
    std::cout << "+-------------------- ARENE --------------------+" << std::endl;
    std::cout << "                    " << this->getNom() << std::endl;
    std::cout << std::endl;
    std::cout << "Joueur 1 : " << this->joueur1->getNom() << std::endl;
    std::cout << "Blob : " << this->joueur1->getBlob()->getNom() << std::endl;
    std::cout << std::endl;
    std::cout << "+-----------------------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Joueur 2 : " << this->joueur2->getNom() << std::endl;
    std::cout << "Blob : " << this->joueur2->getBlob()->getNom() << std::endl;
    std::cout << std::endl;
    std::cout << "+-----------------------------------------------+" << std::endl;
    std::cout << std::endl;
}

Joueur* Arene::changeJoueur()
{
    if(this->getCurrentPlayer() == this->getJoueur1())
    {
        this->setCurrentPlayer(this->getJoueur2());
        this->setNotCurrentPlayer(this->getJoueur1());
    }

    else
    {
        this->setCurrentPlayer(this->getJoueur1());
        this->setNotCurrentPlayer(this->getJoueur2());
    }

    return this->getCurrentPlayer();
}
