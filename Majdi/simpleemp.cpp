#include "simpleemp.h"
#include "ui_simpleemp.h"
#include "client.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include"QIntValidator"
#include <QRegExpValidator>
#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"

SimpleEmp::SimpleEmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleEmp)
{
    ui->setupUi(this);
    QRegExp rxEmail(EMAIL_RX);
        QRegExpValidator *valiEmail = new QRegExpValidator(rxEmail, this);
        ui->le_mail->setValidator(valiEmail);
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
    int id_supp=ui->le_cin_sup->text().toInt();
        bool test=c.supprimer(id_supp);

        if(test)
        {
            ui->table_client->setModel(c.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Suppression effectuee\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                     QObject::tr("Suppression non effectuee\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
        }
}

void SimpleEmp::on_table_client_activated(const QModelIndex &index)
{
    QString cin_modif=ui->table_client->model()->data(index).toString();
        QSqlQuery qry;

        //Refresh (Actualiser)
        ui->table_client->setModel(c.afficher());

        qry.prepare("select * from clients where CIN='"+cin_modif+"'");
        if(qry.exec())
                 {
                     while(qry.next())
                     {
                      ui->le_cin_2->setText(qry.value(0).toString());
                      ui->le_nom_2->setText(qry.value(1).toString());
                      ui->le_prenom_2->setText(qry.value(2).toString());
                      ui->l_adresse_2->setText(qry.value(3).toString());
                      ui->le_num_2->setText(qry.value(4).toString());
                      ui->le_mail_2->setText(qry.value(5).toString());
                     }

                 }
}

void SimpleEmp::on_pushButton_clicked()
{
    int cin=ui->le_cin_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString adresse=ui->l_adresse_2->text();
    QString mail=ui->le_mail_2->text();
    int numtel=ui->le_num_2->text().toInt();
    client c( cin, nom, prenom, adresse, numtel,mail);
                     bool test=c.modifier(cin);
                     if(test)
                     {   ui->table_client->setModel(c.afficher());
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("update effectue.\n"
                                                    "click cancel to exit."),QMessageBox::Cancel);

                     }
             else
                 {
                         ui->table_client->setModel(c.afficher());
             QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                        QObject::tr("update non effectue.\n"
                                                    "click cancel to exit."),QMessageBox::Cancel);}
        }
