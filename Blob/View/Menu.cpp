#include "Menu.h"
#include "View/FightScene.h"

Menu::Menu(Arene *arene, QWidget *parent) : QMainWindow(parent)
{
    this->arene = arene;

    std::string path = ":/Images/Images/MenuBackground.png";

    QPixmap bkgnd(QString::fromStdString(path));
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    /* WINDOW */
    this->setWindowTitle("Blob");
    this->setWindowIcon(QIcon(":/Images/Images/Icon.png"));
    this->setFixedSize(1000, 667);
    this->setAutoFillBackground(true);

    this->label = new QLabel("CHOIX DES PSEUDOS");
    this->label->setAlignment(Qt::AlignHCenter);
    this->label->setStyleSheet("QLabel { color : white; "
                         "font: bold 25px; "
                         "padding: 10px; "
                         "border-radius: 10px;}");
    this->bouton = new QPushButton("VALIDER");
    this->bouton->setStyleSheet("QPushButton { background-color: #4CAF50; "
                          "color: white; font-size: 18px; "
                          "padding: 14px 20px; border-radius: 10px;} "
                          "QPushButton:hover { background-color: #3E8E41; }");
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

    this->layout = new QHBoxLayout;
    this->layout->addWidget(leftLineEdit);
    this->layout->addWidget(rightLineEdit);

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

    FightScene *fs = new FightScene(this->arene);
    fs->show();
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
