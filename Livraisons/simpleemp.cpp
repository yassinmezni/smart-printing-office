#include "simpleemp.h"
#include "ui_simpleemp.h"
#include "client.h"
#include "livraison.h"
#include <QMessageBox>
#include <QDebug>
#include"QIntValidator"


SimpleEmp::SimpleEmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleEmp)
{
    ui->setupUi(this);
     ui->stackedWidget->setCurrentIndex(0);
     ui->le_cin->setValidator(new QIntValidator(0,9999,this));
     ui->table_client->setModel(c.afficher());
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

void SimpleEmp::on_addbutton_clicked()
{
       int cin=ui->le_cin->text().toInt();
       QString nom=ui->le_nom->text();
       QString prenom=ui->le_prenom->text();
       QString adresse=ui->l_adresse->text();
       QString mail=ui->le_mail->text();
       int numtel=ui->le_num->text().toInt();
       client c( cin, nom, prenom, adresse, numtel,mail);
    bool test=c.ajouter();
    if(test)

    {   //REFRESH
        ui->table_client->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void SimpleEmp::on_deletebutton_clicked()
{
    client c1; c1.setcin(ui->le_cin_sup->text().toInt());
    bool test=c1.supprimer(c1.getcin());
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Suppression avec succes.");
          ui->table_client->setModel(c.afficher());

    }
    else
        msgBox.setText("Echec de suppression.");
        msgBox.exec();

}

void SimpleEmp::on_ajouter_clicked()
{

}
