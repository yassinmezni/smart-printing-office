#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QDesktopServices>
#include "livraison.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_livraison->setModel(L.afficher());
    ui->le_id->setValidator(new QIntValidator (0,99999999,this));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_livrButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_deconnecterButton_clicked()
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

//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_homeButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString date=ui->la_date->text();
    QString localisation=ui->l_adress->text();
    int frais=ui->le_frais->text().toInt();


    livraison L(id, date, localisation, frais);

    bool test=L.ajouter();

    if(test)

 {   //REFRESH
     ui->table_livraison->setModel(L.afficher());

     QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("Ajout effectué\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                 QObject::tr("Ajout non effectué\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}

//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_pushButton_2_clicked()
{
    livraison l;
        l.setid(ui->le_id_2->text().toInt());
        l.setdate(ui->la_date_2->text());
        l.setlocalisation(ui->l_adress_2->text());
        l.setfrais(ui->le_frais_2->text().toInt());

        //Refresh (Actualiser l'affichage apres la modification)
        ui->table_livraison->setModel(L.afficher());

       bool check=l.modifier();

        if (check)
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                QObject::tr("Modification avec succés.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else{
                QMessageBox::information(nullptr, QObject::tr("Modification"),
                QObject::tr("Modification échoué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
}
//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_table_livraison_activated(const QModelIndex &index)
{    //lorsque on clique sur l'id
    QString value=ui->table_livraison->model()->data(index).toString();
        QSqlQuery qry;

        //Refresh (Actualiser)
        ui->table_livraison->setModel(L.afficher());

        qry.prepare("select * from livraison where ID_L='"+value+"'");
        if(qry.exec())
                 {
                     while(qry.next())
                     {
                      ui->le_id_2->setText(qry.value(0).toString());
                      ui->la_date_2->setText(qry.value(1).toString());
                      ui->l_adress_2->setText(qry.value(2).toString());
                      ui->le_frais_2->setText(qry.value(3).toString());

                      ui->le_id_sup_2->setText(qry.value(0).toString());
                     }

                 }
}
//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_recherche_textChanged()
{
    QString rech=ui->recherche->text();
        ui->table_livraison->setModel(L.Recherchelivreur(rech));
}

//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_supprimer2_clicked()
{
    int id_supp2=ui->le_id_sup_2->text().toInt();
    bool test=L.supprimer(id_supp2);

    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Suppression avec succes.");
          ui->table_livraison->setModel(L.afficher());

    }
    else
        msgBox.setText("Echec de suppression.");
        msgBox.exec();
}
//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_pushButton_3_clicked()
{
    QString link="https://esprit.tn/";
           QDesktopServices::openUrl(link);
}
//*********************************************************************************************************************************//
//*********************************************************************************************************************************//
void MainWindow::on_comboBox_tri_activated()
{
    if(ui->comboBox_tri->currentText()=="Tri par id croissant")
       {
           ui->table_livraison->setModel(L.trierlivraisonParid_M());

       }else if(ui->comboBox_tri->currentText()=="Tri par id Descendant")
       {
           ui->table_livraison->setModel(L.trierlivraisonParid_D());

       } else if(ui->comboBox_tri->currentText()=="Tri par localisation")
       {
           ui->table_livraison->setModel(L.trierlivraisonParlocalisation());
       }else
    {
        ui->table_livraison->setModel(L.trierlivraisonParfrais_M());
    }
}

void MainWindow::on_homeButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->table_livraison->setModel(L.afficher());
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tablehistorique->setModel(L.afficherhistorique());
}
