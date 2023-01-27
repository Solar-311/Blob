#ifndef WINNERSCENE_H
#define WINNERSCENE_H

/* ########## INCLUDE ########## */
/* LIBRARY QT */
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QRect>
#include <QMovie>
#include <QLineEdit>

/* FILES */
#include "Model/Joueur/Joueur.h"
#include "Model/Arene/Arene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WinnerScene : public QMainWindow
{
    Q_OBJECT

    public:
        Arene *arene;
        WinnerScene(Arene *arene, QWidget *parent = nullptr);
        ~WinnerScene();

    private:
        Ui::MainWindow *ui;
        QWidget* centre;
        QVBoxLayout* vboxlayout;
        QLabel* lb;
};

#endif // WINNERSCENE_H
