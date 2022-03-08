#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chef.h"
#include "simpleemp.h"
#include "livreur.h"


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

    void on_LoginButton_clicked();

private:
    Ui::MainWindow *ui;
    Chef *chef;
    SimpleEmp *simp_emp;
    Livreur *livreur;

};
#endif // MAINWINDOW_H
