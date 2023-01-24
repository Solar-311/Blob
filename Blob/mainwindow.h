#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QRect>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget* centre;
    QLabel* nom;
    QLabel* type;
    QVBoxLayout* vboxlayout;
    QHBoxLayout* hBoxUn;
    QHBoxLayout* hBoxDeux;
    QGridLayout* gridTrois;
    QPushButton* boutonAtttaqueNormale;
    QPushButton* boutonSoin;
    QPushButton* boutonFuir;//abandonne le combat
    QPushButton* boutonAttaqueSpe;
    QLabel* nomAdversaire;
    QLabel* typeAdversaire;
    QPixmap* imageAdversaire;
    QPixmap* imagePerso;
    QLabel* imageLabelPerso;
    QLabel* imageLabelAdversaire;
    void init_components();
    void init_layout();
};
#endif // MAINWINDOW_H
