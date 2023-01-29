#include "Menu.h"

Menu::Menu(Arene *arene, QWidget *parent) : QMainWindow(parent)
{
    this->arene = arene;

    std::string path = ":/Images/Images/MenuBackground.jpg";

    QPixmap bkgnd(QString::fromStdString(path));
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    /* WINDOW */
    this->setWindowTitle("Blob");
    this->setWindowIcon(QIcon(":/Images/Images/Icon.png"));
    this->setFixedSize(bkgnd.size().width(), bkgnd.size().height());
    this->setAutoFillBackground(true);

    this->label = new QLabel("BLOBEMON");
    this->label->setAlignment(Qt::AlignHCenter);
    this->label->setStyleSheet("QLabel { color : white; "
                         "font: bold 25px; "
                         "padding: 10px; "
                         "border-radius: 10px;}");
    this->bouton = new QPushButton("VALIDER");
    this->bouton->setStyleSheet("QPushButton { background-color: white; "
                          "color: black; font-size: 18px; "
                          "font-weight: bold;"
                          "padding: 14px 20px; border-radius: 10px;} "
                          "QPushButton:hover { background-color: grey; }");
    this->leftLineEdit = new QLineEdit();
    this->leftLineEdit->setPlaceholderText("Nom Joueur 1");
    this->leftLineEdit->setStyleSheet("QLineEdit { background-color: rgba(255, 255, 255, 0.8); "
                                "padding: 10px; "
                                "border-radius: 10px; "
                                "border: 2px solid gray; }");
    this->leftLineEdit->setAlignment(Qt::AlignTop);
    this->rightLineEdit = new QLineEdit();
    this->rightLineEdit->setPlaceholderText("Nom Joueur 2");
    this->rightLineEdit->setStyleSheet("QLineEdit { background-color: rgba(255, 255, 255, 0.8); "
                                 "padding: 10px; border-radius: 10px; "
                                 "border: 2px solid gray; }");
    this->rightLineEdit->setAlignment(Qt::AlignTop);
    this->vlayout = new QVBoxLayout();
    this->vlayout->addWidget(label);
    this->vlayout->addWidget(bouton, Qt::AlignHCenter);

    this->cb1 = new QComboBox();
    this->cb1->move(cb1->x() + 100, cb1->y() + 50);
    this->cb1->setStyleSheet("QComboBox {background-color: rgb(50, 195, 255); selection-background-color: gray; border: 1px solid gray; padding: 5px; border-radius: 30px; font : bold 10px}"
                                  "QComboBox QAbstractItemView::item {min-height: 25px;}"
                                  "QComboBox QAbstractItemView {background-color: white; border: 1px solid gray;}");
    this->cb1->addItem("Blob FEU");
    this->cb1->addItem("Blob EAU");
    this->cb1->addItem("Blob PLANTE");
    this->cb2 = new QComboBox();
    this->cb2->move(cb2->x() + 100, cb1->y() + 50);
    this->cb2->setStyleSheet("QComboBox {background-color: rgb(130, 30, 30); selection-background-color: gray; border: 1px solid gray; padding: 5px; border-radius: 30px; font : bold 10px}"
                                  "QComboBox QAbstractItemView::item {min-height: 25px;}"
                                  "QComboBox QAbstractItemView {background-color: white; border: 1px solid gray;}");
    this->cb2->addItem("Blob FEU");
    this->cb2->addItem("Blob EAU");
    this->cb2->addItem("Blob PLANTE");

    this->layout = new QHBoxLayout;
    this->layout->addWidget(leftLineEdit);
    this->layout->addWidget(this->cb1);
    this->layout->addWidget(rightLineEdit);
    this->layout->addWidget(this->cb2);
    this->centralWidget = new QWidget(this);
    this->centralWidget->setLayout(layout);
    this->layout->addLayout(vlayout);
    setCentralWidget(centralWidget);
    this->init_slots();
}

void Menu::init_slots(){
    connect(this->bouton, &QPushButton::released, this, &Menu::changeScene);
}

void Menu::changeScene()
{
    this->hide();

    if(!leftLineEdit->text().isEmpty())
        this->arene->getJoueur1()->setNom(leftLineEdit->text().toStdString());

    if(!rightLineEdit->text().isEmpty())
        this->arene->getJoueur2()->setNom(rightLineEdit->text().toStdString());

    this->choixBlob();
    FightScene *fs = new FightScene(this->arene);
    fs->show();
}

void Menu::choixBlob()
{
    this->selectedText1 = this->cb1->currentText();
    this->selectedText2 = this->cb2->currentText();

    Soin *sfeu = new Soin(20, "Soin");
    Speciale *spfeu = new Speciale(40, "Speciale FEU");
    Normale *nfeu = new Normale(30, "Normale FEU");

    Soin *splante = new Soin(30, "Soin");
    Speciale *spplante = new Speciale(40, "Speciale PLANTE");
    Normale *nplante = new Normale(25, "Normale PLANTE");

    Soin *seau = new Soin(30, "Soin");
    Speciale *speau = new Speciale(40, "Speciale EAU");
    Normale *neau = new Normale(35, "Normale EAU");

    Blob *f = new Blob("Nooby Feu", 100, new Feu(), spfeu, nfeu, sfeu);
    Blob *p = new Blob("Bloby PLante", 85, new Plante(), spplante, nplante, splante);
    Blob *e = new Blob("FabioGODMODE", 120, new Eau(), speau, neau, seau);
    // JOUEUR
    Joueur *j1 = new Joueur("Joueur 1", new Blob());
    Joueur *j2 = new Joueur("Joueur 2", new Blob());

    if (this->selectedText1 == "Blob FEU")
        this->arene->getJoueur1()->setBlob(f);

    if (this->selectedText1 == "Blob PLANTE")
       this->arene->getJoueur1()->setBlob(p);

    if (this->selectedText1 == "Blob EAU")
       this->arene->getJoueur1()->setBlob(e);

    if (this->selectedText2 == "Blob FEU")
       this->arene->getJoueur2()->setBlob(f);

    if (this->selectedText2 == "Blob PLANTE")
       this->arene->getJoueur2()->setBlob(p);

    if (this->selectedText2 == "Blob EAU")
       this->arene->getJoueur2()->setBlob(e);
}

Menu::~Menu()
{
    delete label;
    delete leftLineEdit;
    delete rightLineEdit;
    delete layout;
    delete centralWidget;
    delete bouton;
    delete vlayout;
}
