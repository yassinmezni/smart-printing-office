#ifndef LIVREUR_H
#define LIVREUR_H
#include "livraison.h"

#include <QDialog>

namespace Ui {
class Livreur;
}

class Livreur : public QDialog
{
    Q_OBJECT

public:
    explicit Livreur(QWidget *parent = nullptr);
    ~Livreur();

private slots:
    void on_livrButton_clicked();

    void on_homeButton_clicked();

    void on_deconnecterButton_clicked();

    void on_homeButton_4_clicked();

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_table_livraison_activated(const QModelIndex &index);

private:
    Ui::Livreur *ui;
    livraison L;
};

#endif // LIVREUR_H
