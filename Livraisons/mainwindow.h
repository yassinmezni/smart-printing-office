#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "livraison.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_livrButton_clicked();

    void on_deconnecterButton_clicked();

    void on_homeButton_4_clicked();

    void on_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_table_livraison_activated(const QModelIndex &index);

    void on_recherche_textChanged();

    void on_pushButton_3_clicked();

    void on_supprimer2_clicked();

    void on_comboBox_tri_activated();

    void on_homeButton_5_clicked();


    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    livraison L;
};
#endif // MAINWINDOW_H
