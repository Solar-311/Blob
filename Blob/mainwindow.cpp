#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

// ...

QGridLayout* layout = new QGridLayout();

QLabel* nomAllie = new QLabel("Notre Blob");
QLabel* typeAllie = new QLabel("Feu");
QLabel* pvAllie = new QLabel("100");
QLabel* imageAllie = new QLabel();
QPixmap imageAlliePixmap("chemin/vers/imageAllie.png");
//imageAllie->setPixmap(imageAlliePixmap);

QLabel* nomAdversaire = new QLabel("Blob méchant");
QLabel* typeAdversaire = new QLabel("Plante");
QLabel* pvAdversaire = new QLabel("100");
QLabel* imageAdversaire = new QLabel();
QPixmap imageAdversairePixmap("chemin/vers/imageAdversaire.png");
//imageAdversaire->setPixmap(imageAdversairePixmap);

QLayout->addWidget(nomAllie, 0, 0);
layout->addWidget(typeAllie, 1, 0);
layout->addWidget(pvAllie, 2, 0);
layout->addWidget(imageAllie, 3, 0);
layout->addWidget(nomAdversaire, 0, 1);
layout->addWidget(typeAdversaire, 1, 1);
layout->addWidget(pvAdversaire, 2, 1);
layout->addWidget(imageAdversaire, 3, 1);

setLayout(QLayout);
