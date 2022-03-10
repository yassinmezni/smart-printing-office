#ifndef SIMPLEEMP_H
#define SIMPLEEMP_H
#include "client.h"

#include <QDialog>

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

    void on_addbutton_clicked();
    
    void on_homeButton_5_clicked();

    void on_deletebutton_clicked();

    void on_ajouter_clicked();

private:
    Ui::SimpleEmp *ui;
    client c;
};

#endif // SIMPLEEMP_H
