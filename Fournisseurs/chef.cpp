#include "chef.h"
#include "connection.h"
#include "ui_chef.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QRegExpValidator>
#include "fournisseur.h"


#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"
#define NAME_RX "([A-Z][a-z]*)([\\s\\\'.][A-Z][a-z]*)*"


Chef::Chef(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chef)
{
    ui->setupUi(this);
    //Controle de saisie Email
    QRegExp rxEmail(EMAIL_RX);
    QRegExpValidator *valiEmail = new QRegExpValidator(rxEmail, this);
    ui->lineEdit_mail->setValidator(valiEmail);

    //Controle de saisie Nom Fournisseur
    QRegExp rxName(NAME_RX);
    QRegExpValidator *valiName = new QRegExpValidator(rxName, this);
    ui->lineEdit_nom->setValidator(valiName);

    //Controle de saisie Reference
    ui->lineEdit_ref->setValidator(new QIntValidator(100,9999999,this));

    //Controle de saisie GSM
    ui->lineEdit_gsm->setValidator(new QIntValidator(20000000,99999999,this));

    //Affichage
    ui->tableView->setModel(Ftmp.afficher());
    ui->tableView_2->setModel(Ftmp.afficher());
}

Chef::~Chef()
{
    delete ui;
}


void Chef::on_pushButton_12_clicked()
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

void Chef::on_prodButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Chef::on_cmdButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Chef::on_clButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Chef::on_livrButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Chef::on_empButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Chef::on_fournisseurButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Chef::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_afficher_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_supprimer_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_rechercher_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_instruction_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Chef::on_ajouterButton_clicked()
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

        //Refresh (Actualiser)
        ui->tableView->setModel(Ftmp.afficher());

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

void Chef::on_supprimerButton_clicked()
{
    int ref=ui->supprimer_par_reference->text().toInt();
    bool test=Ftmp.supprimer(ref);

    if(test)
    {

        //Refresh (Actualiser)
        ui->tableView->setModel(Ftmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                QObject::tr("Suppression non effectuée.\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
    }
}



void Chef::on_tableView_2_activated(const QModelIndex &index)
{
    QString value=ui->tableView_2->model()->data(index).toString();
    Connection c;
    c.closeConnection();
    QSqlQuery qry;

    //Refresh (Actualiser)
    ui->tableView_2->setModel(Ftmp.afficher());

    qry.prepare("select * from fournisseurs where REF_FOUR='"+value+"'");
    if(qry.exec())
             {
                 while(qry.next())
                 {
                  ui->lineEdit_reference->setText(qry.value(0).toString());
                  ui->lineEdit_nomfour->setText(qry.value(1).toString());
                  ui->lineEdit_email->setText(qry.value(2).toString());
                  ui->lineEdit_gsmfour->setText(qry.value(3).toString());
                  ui->lineEdit_ad->setText(qry.value(4).toString());
                 }

             }
}


void Chef::on_modifierButton_clicked()
{

    Fournisseur f;
    f.setRef(ui->lineEdit_reference->text().toInt());
    f.setNom_fourn(ui->lineEdit_nomfour->text());
    f.setMail_fourn(ui->lineEdit_email->text());
    f.setGSM(ui->lineEdit_gsmfour->text().toInt());
    f.setAdresse_fourn(ui->lineEdit_ad->text());

    //Refresh (Actualiser)
    ui->tableView_2->setModel(Ftmp.afficher());

   bool check=f.modifier();

    if (check)
    {
        QMessageBox::information(nullptr, QObject::tr("Modification"),
            QObject::tr("Modification avec succés.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
            QMessageBox::information(nullptr, QObject::tr("Modification"),
            QObject::tr("Modification échouée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}


