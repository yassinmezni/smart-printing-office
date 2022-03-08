#ifndef SIMPLEEMP_H
#define SIMPLEEMP_H

#include <QDialog>
#include "fournisseur.h"


namespace Ui {
class SimpleEmp;
}

class SimpleEmp : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleEmp(QWidget *parent = nullptr);
    ~SimpleEmp();

private slots:
    void on_clButton_clicked();

    void on_homeButton_clicked();

    void on_prodButton_clicked();

    void on_homeButton_2_clicked();

    void on_cmdButton_clicked();

    void on_homeButton_3_clicked();

    void on_livrButton_clicked();

    void on_homeButton_4_clicked();

    void on_fournisseurButton_clicked();

    void on_homeButton_6_clicked();

    void on_deconnecterButton_clicked();

    void on_homeButton_13_clicked();

    void on_homeButton_14_clicked();

    void on_homeButton_supprimer_3_clicked();

    void on_homeButton_rechercher_3_clicked();

    void on_ajouterButton_2_clicked();

    void on_supprimerButton_3_clicked();

private:
    Ui::SimpleEmp *ui;

    Fournisseur Ftmp;
};

#endif // SIMPLEEMP_H
