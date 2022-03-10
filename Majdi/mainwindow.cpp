#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap rajel(":/img/img/Rajel.png");
    int w = ui->Manpic->width();
    int h = ui->Manpic->height();
    ui->Manpic->setPixmap (rajel.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap logo(":/img/img/Logo.png");
    w = ui->logo_sps->width();
    h = ui->logo_sps->height();
    ui->logo_sps->setPixmap (logo.scaled(w,h,Qt::KeepAspectRatio));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_QuitterButton_clicked()
{
    /*
        void about
        void aboutQt
        StandardButton critical
        StandardButton information
        StandardButton question
        StandardButton warning
    */

    QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    } else
    {
        qDebug() <<"No is clicked";
    }
}

void MainWindow::on_LoginButton_clicked()
{
    QString nom_utilisateur = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (nom_utilisateur == "admin" && password == "admin")
    {
        hide();
        chef = new Chef(this);
        chef->show();
    } else if (nom_utilisateur == "simple" && password == "simple")
            {
                hide();
                simp_emp = new SimpleEmp(this);
                simp_emp->show();
            } else if (nom_utilisateur == "livreur" && password == "livreur")
                    {
                        hide();
                        livreur = new Livreur(this);
                        livreur->show();
                    } else {
                                ui->statusbar->showMessage("Le nom d'utilisateur ou le mot de passe est(sont) incorrecte(s).");
                            }
}
