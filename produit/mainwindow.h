#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit1.h"
#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_valider_clicked();

    void on_tab_produit_activated(const QModelIndex &index);

    void on_read_clicked();

    void on_supprimer_clicked();

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);





    void on_pushButton_delete_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_2_clicked();

    void on_inserer_photo_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_textHighlighted(const QString &arg1);

private:
    Ui::MainWindow *ui;
    produit b;
};

#endif // MAINWINDOW_H
