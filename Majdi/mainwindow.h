#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
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

    void on_deletebutton_clicked();

    void on_table_client_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_lineEdit_recherche_client_textChanged();

    void on_comboBox_tri_activated();

    void on_excel_button_clicked();

private:
    Ui::MainWindow *ui;
client c;
};
#endif // MAINWINDOW_H
