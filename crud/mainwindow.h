#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_tab_employee_activated(const QModelIndex &index);

    void on_pb_update_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
