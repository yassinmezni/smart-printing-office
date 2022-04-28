#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "excel.h"
#include "client.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include"QIntValidator"
#include<QFile>
#include<QTextStream>
#include<QDate>
#include<QFileDialog>
#include<QUrl>
#include<QDesktopServices>

#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rxEmail(EMAIL_RX);
        QRegExpValidator *valiEmail = new QRegExpValidator(rxEmail, this);
        ui->le_mail->setValidator(valiEmail);
     ui->stackedWidget->setCurrentIndex(0);
     ui->le_cin->setValidator(new QIntValidator(0,9999,this));
     ui->table_client->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_clButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_prodButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_homeButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_cmdButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_homeButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_livrButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_homeButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_fournisseurButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_homeButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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

void MainWindow::on_addbutton_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString adresse=ui->l_adresse->text();
    QString mail=ui->le_mail->text();
    int numtel=ui->le_num->text().toInt();
    QString cin1=ui->le_cin->text();
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


 QString nomFile ="Historique";
      QFile file("C:/Users/majdi/Desktop/qtt/Historique.txt");
      QString finalmsg="fichier modifie avec succes";
       if(!file.exists()){
       finalmsg="fichier cree avec succes";
       }
      file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



      QTextStream txt(&file);
        QString d_info = QDateTime::currentDateTime().toString();

      QString message2=d_info+" - Un Client a été ajoutée avec le cin "+ cin1 +"\n";
      txt << message2;

 ui->le_cin->clear();
 ui->le_nom->clear();
 ui->le_prenom->clear();
 ui->l_adresse ->clear();
 ui->le_mail->clear();

}

void MainWindow::on_deletebutton_clicked()
{
    int id_supp=ui->le_cin_sup->text().toInt();
        bool test=c.supprimer(id_supp);
        QString cin1=ui->le_cin_sup->text();

        if(test)
        {
            ui->table_client->setModel(c.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Suppression effectuee\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            QString nomFile ="Historique";
                 QFile file("C:/Users/majdi/Desktop/qtt/Historique.txt");
                 QString finalmsg="fichier modifie avec succes";
                  if(!file.exists()){
                  finalmsg="fichier cree avec succes";
                  }
                 file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                 QTextStream txt(&file);
                   QString d_info = QDateTime::currentDateTime().toString();

                 QString message2=d_info+" - Un Client a été supprimé avec le cin "+ cin1 +"\n";
                 txt << message2;
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                     QObject::tr("Suppression non effectuee\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
        }

}

void MainWindow::on_table_client_activated(const QModelIndex &index)
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


void MainWindow::on_pushButton_clicked()
{
    int cin=ui->le_cin_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString adresse=ui->l_adresse_2->text();
    QString mail=ui->le_mail_2->text();
    int numtel=ui->le_num_2->text().toInt();
    client c( cin, nom, prenom, adresse, numtel,mail);
     QString cin1=ui->le_cin_2->text();
                     bool test=c.modifier(cin);
                     if(test)
                     {   ui->table_client->setModel(c.afficher());
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("update effectue.\n"
                                                    "click cancel to exit."),QMessageBox::Cancel);
                 QString nomFile ="Historique";
                      QFile file("C:/Users/majdi/Desktop/qtt/Historique.txt");
                      QString finalmsg="fichier modifie avec succes";
                       if(!file.exists()){
                       finalmsg="fichier cree avec succes";
                       }
                      file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                      QTextStream txt(&file);
                        QString d_info = QDateTime::currentDateTime().toString();

                      QString message2=d_info+" - Un Client a été modifié avec le cin "+ cin1 +"\n";
                      txt << message2;

                     }
             else
                 {
                         ui->table_client->setModel(c.afficher());
             QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                        QObject::tr("update non effectue.\n"
                                                    "click cancel to exit."),QMessageBox::Cancel);}
}

void MainWindow::on_lineEdit_recherche_client_textChanged()
{
    QString rech=ui->lineEdit_recherche_client->text();
      ui->table_client->setModel(c.Rechercheclient(rech));

}

void MainWindow::on_comboBox_tri_activated()
{
    if(ui->comboBox_tri->currentText()=="Tri par CIN Monatnt")
       {
           ui->table_client->setModel(c.trierclientParCIN_M());

       }else if(ui->comboBox_tri->currentText()=="Tri par CIN Descendant")
       {
           ui->table_client->setModel(c.trierclientParCIN_D());

       }else if(ui->comboBox_tri->currentText()=="Tri par nom")
       {
           ui->table_client->setModel(c.trierclientParNom());
       }else
    {
        ui->table_client->setModel(c.trierclientParPrenom());
    }

}

void MainWindow::on_excel_button_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->table_client);

           //colums to export
           obj.addField(0, "cin", "NUMBER");
           obj.addField(1, "nom_cl", "varchar(50)");
           obj.addField(2, "prenom_cl", "varchar(50)");
           obj.addField(3, "adresse_cl", "varchar(50)");
           obj.addField(4, "num_tel", "NUMBER");
           obj.addField(5, "mail", "varchar(50)");


           int retVal = obj.export2Excel();
           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}
