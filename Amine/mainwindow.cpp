#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include<QMessageBox>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_aff->setModel(Ctmp.afficher());
    ui->le_id->setValidator( new QIntValidator(0, 999999, this));
    ui->le_id ->setValidator( new QIntValidator(0, 999999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_Ajouter_clicked()
{
    int ID_CMD=ui->le_id->text().toInt();
    float PRIX=ui->le_prix->text().toFloat();

    QString DATE_COM=ui->le_DATE->text();
    int QT_COMMANDES=ui->le_Quantite->text().toInt();

    Commande C(ID_CMD,PRIX,DATE_COM,QT_COMMANDES);
    bool test=C.ajouter();

    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Ajout effectué\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                     QObject::tr("Ajout non effectué.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supp_Button_clicked()
{
    int id=ui->supprimer_id->text().toInt();
    bool test=Ctmp.supprimer(id);

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("Ok"),
                                 QObject::tr("Suppression effectuee\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Suppression non effectuee\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }
}







void MainWindow::on_tableView_aff_activated(const QModelIndex &index)
{
    QString id_modif=ui->tableView_aff->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("select * from commandes where ID_COMMANDE='"+id_modif+"'");
    if (qry.exec())
    {
        while (qry.next())
        {
            ui->le_id_2->setText(qry.value(0).toString());
            ui->le_prix_2->setText(qry.value(1).toString());
            ui->le_DATE_2->setText(qry.value(2).toString());
            ui->le_Quantite_2->setText(qry.value(3).toString());
        }
    }
}

void MainWindow::on_modifierButton_clicked()


        {
            int ID_CMD=ui->le_id_2->text().toInt();
            int PRIX=ui->le_prix_2->text().toFloat();
            QString DATE=ui->le_DATE_2->text();




            int QT_COMMANDES=ui->le_Quantite_2->text().toInt();

            Commande C(ID_CMD,PRIX,DATE,QT_COMMANDES);

                         bool test=C.modifier();
                         if(test)
                         {   ui->tableView_aff->setModel(Ctmp.afficher());
                     QMessageBox::information(nullptr,QObject::tr("OK"),
                                            QObject::tr("update effectue.\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);

                         }
                 else
                     {
                             ui->tableView_aff->setModel(Ctmp.afficher());
                 QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                            QObject::tr("update non effectue.\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);}
            }


