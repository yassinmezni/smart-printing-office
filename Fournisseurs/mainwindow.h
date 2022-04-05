#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseur.h"

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

    int on_LoginButton_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_ajouterButton_clicked();

    void on_supprimerButton_2_clicked();

    void on_modifierButton_clicked();

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

    void on_livrButton_3_clicked();

    void on_homeButton_14_clicked();

    void on_pushButton_14_clicked();

    void on_fournisseurButton_3_clicked();

    void on_empButton_3_clicked();

    void on_clButton_3_clicked();

    void on_prodButton_3_clicked();

    void on_cmdButton_3_clicked();

    void on_clButton_4_clicked();

    void on_prodButton_4_clicked();

    void on_cmdButton_4_clicked();

    void on_livrButton_4_clicked();

    void on_empButton_4_clicked();

    void on_fournisseurButton_4_clicked();

    void on_pushButton_15_clicked();

    void on_homeButton_16_clicked();

    void on_homeButton_17_clicked();

    void on_homeButton_18_clicked();

    void on_homeButton_19_clicked();

    void on_homeButton_ajouter_4_clicked();

    void on_homeButton_modifier_4_clicked();

    void on_ajouterButton_4_clicked();

    void on_supprimerButton_5_clicked();

    void on_tableView_9_activated(const QModelIndex &index);

    void on_modifierButton_4_clicked();

    void on_LoadButton_clicked();

    void on_LoadButton_2_clicked();

    void on_PDFButton_clicked();

    void on_PDFButton_4_clicked();

    void on_trier_button_clicked();

    void on_TrierButton_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_LoadButton_Historique_clicked();

    void on_recherche_par_reference_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Fournisseur Ftmp;

};
#endif // MAINWINDOW_H
