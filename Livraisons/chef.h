#ifndef CHEF_H
#define CHEF_H

#include <QDialog>

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

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_prodButton_clicked();

    void on_cmdButton_clicked();

    void on_clButton_clicked();

    void on_livrButton_clicked();

    void on_empButton_clicked();

    void on_homeButton_clicked();

    void on_homeButton_2_clicked();

    void on_pushButton_clicked();

    void on_homeButton_3_clicked();

    void on_homeButton_4_clicked();

    void on_homeButton_5_clicked();

    void on_homeButton_6_clicked();

    void on_fournisseurButton_clicked();

    void on_ajouter_clicked();

private:
    Ui::Chef *ui;
};

#endif // CHEF_H
