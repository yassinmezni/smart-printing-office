#ifndef LIVREUR_H
#define LIVREUR_H

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

private:
    Ui::Livreur *ui;
};

#endif // LIVREUR_H
