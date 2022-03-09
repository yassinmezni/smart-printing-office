#ifndef CHEF_H
#define CHEF_H

#include <QDialog>
#include "fournisseur.h"

namespace Ui {
class Chef;
}

class Chef : public QDialog
{
    Q_OBJECT

public:
    explicit Chef(QWidget *parent = nullptr);
    ~Chef();

private slots:
    void on_pushButton_12_clicked();

    void on_prodButton_clicked();

    void on_cmdButton_clicked();

    void on_clButton_clicked();

    void on_livrButton_clicked();

    void on_empButton_clicked();

    void on_homeButton_clicked();

    void on_homeButton_2_clicked();

    void on_homeButton_3_clicked();

    void on_homeButton_4_clicked();

    void on_homeButton_5_clicked();

    void on_homeButton_6_clicked();

    void on_fournisseurButton_clicked();

    void on_homeButton_7_clicked();

    void on_homeButton_ajouter_clicked();

    void on_homeButton_afficher_clicked();

    void on_homeButton_supprimer_clicked();

    void on_homeButton_rechercher_clicked();

    void on_ajouterButton_clicked();

    void on_supprimerButton_clicked();

    void on_modifierButton_clicked();

    void on_homeButton_modifier_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_homeButton_instruction_clicked();

private:
    Ui::Chef *ui;

    Fournisseur Ftmp;
};

#endif // CHEF_H
