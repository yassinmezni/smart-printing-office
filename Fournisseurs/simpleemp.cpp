#include "simpleemp.h"
#include "ui_simpleemp.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "fournisseur.h"

SimpleEmp::SimpleEmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleEmp)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ftmp.afficher());
}

SimpleEmp::~SimpleEmp()
{
    delete ui;
}

void SimpleEmp::on_clButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SimpleEmp::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_prodButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void SimpleEmp::on_homeButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_cmdButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void SimpleEmp::on_homeButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_livrButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void SimpleEmp::on_homeButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_fournisseurButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void SimpleEmp::on_homeButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_deconnecterButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    } else
    {
        qDebug() <<"No is clicked";
    }
}

void SimpleEmp::on_homeButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_homeButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_homeButton_supprimer_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_homeButton_rechercher_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SimpleEmp::on_ajouterButton_2_clicked()
{
    //Récupération des données
    int reference=ui->lineEdit_ref->text().toInt();
    QString nom_fourn=ui->lineEdit_nom->text();
    QString mail_fourn=ui->lineEdit_mail->text();
    int gsm_fourn=ui->lineEdit_gsm->text().toInt();
    QString adresse_fourn=ui->lineEdit_adresse->text();

    Fournisseur F(reference,nom_fourn,mail_fourn,gsm_fourn,adresse_fourn);

    bool test=F.ajouter();

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Warning"),
                              QObject::tr("Ajout non effectué\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }
}
