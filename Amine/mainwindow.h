#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <commande.h>
#include <QMainWindow>
#include <QTableView>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_Ajouter_clicked();
    void on_supp_Button_clicked();
    void on_modifierButton_clicked();
    void on_tableView_aff_activated(const QModelIndex &index);
    void on_comboBox_2_activated(const QString &arg1);
    void on_le_id_cursorPositionChanged(int arg1, int arg2);
    void on_combobox_fk_activated(const QString &arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_recherche_clicked();
    void on_le_id_2_textChanged(const QString &arg1);
    void on_le_id_2_cursorPositionChanged(int arg1, int arg2);

    void on_le_Quantite_2_cursorPositionChanged(int arg1, int arg2);

    void on_le_Quantite_2_textChanged(const QString &arg1);

    void on_le_prix_2_textChanged(const QString &arg1);

    void on_find_cursorPositionChanged(int arg1, int arg2);

    void on_le_DATE_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    Commande Ctmp;
};

#endif // MAINWINDOW_H
