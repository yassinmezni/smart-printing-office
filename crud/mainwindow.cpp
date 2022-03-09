#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include "QMessageBox"
#include <QSqlQuery>
//delaration de C.S
#include <QRegExpValidator>

#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Employee E;
    ui->setupUi(this);
    //controle saisie mail
    QRegExp  rxEmail(EMAIL_RX);
    QRegExpValidator *valiEmail = new QRegExpValidator(rxEmail, this);
    ui->lineEdit_mail->setValidator(valiEmail);
    ui->lineEdit_matricule->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_GSM->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_Salaire->setValidator(new QIntValidator (0,99999999,this));
    ui->tab_employee->setModel(E.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    int Matricule=ui->lineEdit_matricule->text().toInt();
    QString Nom=ui->lineEdit_Nom->text();
    QString Prenom=ui->lineEdit_Prenom->text();
    QString Mail=ui->lineEdit_mail->text();
    int GSM=ui->lineEdit_GSM->text().toInt();
    QString Role=ui->lineEdit_Role->text();
    int Salaire=ui->lineEdit_Salaire->text().toInt();
    Employee E(Matricule,Nom,Prenom,Mail,GSM,Role,Salaire);
bool test=E.ajouter();
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("ajout successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_employee->setModel(E.afficher());
}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("ajout failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}

void MainWindow::on_pb_supprimer_clicked()
{
    Employee E; E.setMatricule(ui->lineEdit->text().toInt());
        bool test=E.supprimer(E.getMatricule());
        if(test)//si le requete est fonctionnable
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("suppression effectue\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            //refrech des la suppression
            ui->tab_employee->setModel(E.afficher());

      }
        else //si le requete n'est pas fonctionnable
            QMessageBox::critical(nullptr, QObject::tr("NOT ok"),
                        QObject::tr("suppression failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}





void MainWindow::on_pb_update_clicked()

    {
        int Matricule=ui->lineEdit_matricule_update->text().toInt();
        QString Nom=ui->lineEdit_Nom_update->text();
        QString Prenom=ui->lineEdit_prenom_update->text();
        QString Mail=ui->lineEdit_mail_update->text();
        int GSM=ui->lineEdit_gsm_update->text().toInt();
        QString Role=ui->lineEdit_role_update->text();
        int Salaire=ui->lineEdit_salaire_update->text().toInt();
        Employee E(Matricule,Nom,Prenom,Mail,GSM,Role,Salaire);
                     E.update(Matricule);
                     if(E.update(Matricule))
                     {   ui->tab_employee->setModel(E.afficher());
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("update effectue.\n"
                                                    "click cancel to exit."),QMessageBox::Cancel);

                     }
             else
                 {
                         ui->tab_employee->setModel(E.afficher());
             QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                        QObject::tr("update non effectue.\n"
                                                    "click cancel to exit."),QMessageBox::Cancel);}
        }



void MainWindow::on_tab_employee_activated(const QModelIndex &index)
{
    QString value=ui->tab_employee->model()->data(index).toString();

        QSqlQuery qry;
        Employee E;

        //Refresh (Actualiser)
        ui->tab_employee->setModel(E.afficher());

        qry.prepare("select * from EMPLOYE where MATRICULE='"+value+"'");
        if(qry.exec())
                 {
                     while(qry.next())
                     {
                      ui->lineEdit_matricule_update->setText(qry.value(0).toString());
                      ui->lineEdit_Nom_update->setText(qry.value(1).toString());
                      ui->lineEdit_prenom_update->setText(qry.value(2).toString());
                      ui->lineEdit_mail_update->setText(qry.value(3).toString());
                      ui->lineEdit_gsm_update->setText(qry.value(4).toString());
                      ui->lineEdit_role_update->setText(qry.value(5).toString());
                      ui->lineEdit_salaire_update->setText(qry.value(6).toString());
                      //optionnel quand ti cliques sur le matricule la supprisiion se rempli automatiquement
                      ui->lineEdit->setText(qry.value(0).toString());
                     }

                 }
}
