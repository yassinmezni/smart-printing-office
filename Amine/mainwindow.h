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



    void on_tableView_activated(const QModelIndex &index);
    void on_modifierButton_clicked();



    void on_tableView_aff_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Commande Ctmp;
};

#endif // MAINWINDOW_H
