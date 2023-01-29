#ifndef MENU_H
#define MENU_H

/* ########## INCLUDE ########## */
/* LIBRARY */
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPalette>
#include <QPixmap>
#include <QPushButton>
#include <QDialog>
#include <QComboBox>
#include <QIcon>

/* FILES */
#include "Model/Arene/Arene.h"
#include "View/FightScene.h"
#include "Model/Menu/ListBlob.h"

class Menu : public QMainWindow
{
    Q_OBJECT

    public:
        Menu(Arene *arene, QWidget *parent = nullptr);
        ~Menu();

    private:
        Arene *arene;
        FightScene *fs;
        QLabel *label;
        QLineEdit *leftLineEdit;
        QLineEdit *rightLineEdit;
        QComboBox* cb1;
        QString selectedText1;
        QComboBox* cb2;
        QString selectedText2;
        QHBoxLayout *layout;
        QWidget *centralWidget;
        QPushButton* bouton;
        QVBoxLayout* vlayout;

    public slots:
        void init_slots();
        void changeScene();
        void choixBlob();
};

#endif // MENU_H
