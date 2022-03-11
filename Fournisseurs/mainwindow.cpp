#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QRegExpValidator>
#include "connection.h"
#include "fournisseur.h"

#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"
#define NAME_RX "([A-Z][a-z]*)([\\s\\\'.][A-Z][a-z]*)*"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Affichage
    ui->tableView_2->setModel(Ftmp.afficher());
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
    ui->lineEdit_gsm->setValidator(new QIntValidator(100,99999999,this));



    //Load Images
    QPixmap rajel(":/img/img/Rajel.png");
    int w = ui->Manpic->width();
    int h = ui->Manpic->height();
    ui->Manpic->setPixmap (rajel.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap logo(":/img/img/Logo.png");
    w = ui->logo_sps->width();
    h = ui->logo_sps->height();
    ui->logo_sps->setPixmap (logo.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap background(":/img/img/Background.jpg");
    int x = ui->Background->width();
    int y = ui->Background->height();
    ui->Background->setPixmap (background.scaled(x,y,Qt::KeepAspectRatio));

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
        ui->stackedWidget->setCurrentIndex(1);
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

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString value=ui->tableView_2->model()->data(index).toString();
    Connection c;
    c.closeConnection();
    QSqlQuery qry;

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
                  ui->supprimer_par_reference_2->setText(qry.value(0).toString());
                 }

             }
}

void MainWindow::on_ajouterButton_clicked()
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
        ui->tableView_2->setModel(Ftmp.afficher());

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

void MainWindow::on_supprimerButton_2_clicked()
{
    int ref=ui->supprimer_par_reference_2->text().toInt();
    bool test=Ftmp.supprimer(ref);

    if(test)
    {

        //Refresh (Actualiser)
        ui->tableView_2->setModel(Ftmp.afficher());

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

void MainWindow::on_modifierButton_clicked()
{
    Fournisseur f;
    f.setRef(ui->lineEdit_reference->text().toInt());
    f.setNom_fourn(ui->lineEdit_nomfour->text());
    f.setMail_fourn(ui->lineEdit_email->text());
    f.setGSM(ui->lineEdit_gsmfour->text().toInt());
    f.setAdresse_fourn(ui->lineEdit_ad->text());

   bool check=f.modifier();

    if (check)
    {
        //Refresh (Actualiser)
        ui->tableView_2->setModel(Ftmp.afficher());

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

void MainWindow::on_homeButton_instruction_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_ajouter_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_modifier_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        ui->stackedWidget->setCurrentIndex(0);
        //QApplication::quit();
    } else
    {
        qDebug() <<"No is clicked";
    }
}

void MainWindow::on_clButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_prodButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_cmdButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_livrButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void MainWindow::on_empButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
}

void MainWindow::on_fournisseurButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
}

void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_rechercher_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}
