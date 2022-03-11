#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chef.h"
#include "simpleemp.h"
#include "livreur.h"


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
    void on_QuitterButton_clicked();

    void on_LoginButton_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_ajouterButton_clicked();

    void on_supprimerButton_2_clicked();

    void on_modifierButton_clicked();

    void on_homeButton_instruction_clicked();

    void on_homeButton_ajouter_clicked();

    void on_pushButton_12_clicked();

    void on_fournisseurButton_clicked();

    void on_clButton_clicked();

    void on_prodButton_clicked();

    void on_cmdButton_clicked();

    void on_livrButton_clicked();

    void on_empButton_clicked();

    void on_homeButton_clicked();

    void on_homeButton_2_clicked();

    void on_homeButton_3_clicked();

    void on_homeButton_4_clicked();

    void on_homeButton_5_clicked();

    void on_homeButton_modifier_clicked();

    void on_homeButton_rechercher_clicked();

private:
    Ui::MainWindow *ui;
    Chef *chef;
    SimpleEmp *simp_emp;
    Livreur *livreur;
    Fournisseur Ftmp;

};
#endif // MAINWINDOW_H
