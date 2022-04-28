#include "mainwindow.h"
#include "ui_mainwindow.h"
//***********camera*******
#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
#include<QFileDialog>

//************qrcode**********
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "QMessageBox"
#include <QSqlQuery>
#include <QTimer>
#include <QDateTime>
#include <QRegExpValidator>
using qrcodegen::QrCode;


#include "employee.h"
#include "qrcode.h"




//CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF


void MainWindow::on_pb_ajouter_3_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    //Récuperation les informations saisie dans les 7 champs.
    int Matricule=ui->lineEdit_matricule_3->text().toInt(); //Convertir la chaine saisie en un entier car l’attribut id est de type int
    QString Nom=ui->lineEdit_Nom_3->text();
    QString Prenom=ui->lineEdit_Prenom_3->text();
    QString Mail=ui->lineEdit_mail_5->text();
    int GSM=ui->lineEdit_GSM_3->text().toInt();
    QString Role=ui->lineEdit_Role_3->text();
    int Salaire=ui->lineEdit_Salaire_3->text().toInt();
    Employee E(Matricule,Nom,Prenom,Mail,GSM,Role,Salaire);//INSTANCIER UN OBJET DE LA CLASSE EMPLOYEE
                                                           //EN UTILISANT LES INFORMATIONS SAISIES DANS L INTERFACE7

    bool test=E.ajouter(); //INSERER L OBJET EMPLOYEE INSTANCIé DANS LE TABLE EMPLOYE
                           //ET RECUPERE LA VLEUR DE RETOUR DE QUERY.EXEC
    if(test) // si requéte executée ==> QMessage::information
    {
        ui->tab_employee_2->setModel(E.afficher());
        if (aj=="Francais")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                 QObject::tr("Ajout effectué\n"
                                             "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                 QObject::tr("Addition made\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                 QObject::tr("Adición hecha\n"
                                             "Haga click en Cancelar para smear."),QMessageBox::Cancel);
        }
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Addition not made\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Adición no hecha\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
}


void MainWindow::on_pb_supprimer_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    E.setMatricule(ui->lineEdit_2->text().toInt());
    bool test=E.supprimer(E.getMatricule());
    if(test)//si le requete est fonctionnable
    {
        ui->tab_employee_2->setModel(E.afficher());
        if (aj=="Francais")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression effectuée\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Addition not made\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Eliminación realizada\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "La référence n'existe pas."
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion not performed.\n"
                                              "The reference does not exist."
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Borrado no realizado.\n"
                                              "La referencia no existe."
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
    ui->lineEdit_2->clear();
}

void MainWindow::on_LoadButton_Historique_3_clicked()
{
    ui->tab_employee_2->setModel(E.afficher());
}

void MainWindow::on_pb_update_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int Matricule=ui->lineEdit_matricule_update_2->text().toInt();
    QString Nom=ui->lineEdit_Nom_update_2->text();
    QString Prenom=ui->lineEdit_prenom_update_2->text();
    QString Mail=ui->lineEdit_mail_update_2->text();
    int GSM=ui->lineEdit_gsm_update_2->text().toInt();
    QString Role=ui->lineEdit_role_update_2->text();
    int Salaire=ui->lineEdit_salaire_update_2->text().toInt();
    Employee E(Matricule,Nom,Prenom,Mail,GSM,Role,Salaire);

    bool test=E.update(Matricule);
    if(test)
    {
        ui->tab_employee_2->setModel(E.afficher());
        if (aj=="Francais")
        {
            QMessageBox::information(nullptr, QObject::tr("Smart Printing System"),
                                  QObject::tr("Modification avec succés.\n"
                                              "Cliquez sur annuler pour quitter."), QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Change successfully.\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Cambiar con éxito.\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"),
                                  QObject::tr("Modification échouée.\n"
                                              "Cliquez sur annuler pour quitter."), QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Change failed.\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("El cambio falló.\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
    ui->lineEdit_matricule_update_2->clear();
    ui->lineEdit_Nom_update_2->clear();
    ui->lineEdit_prenom_update_2->clear();
    ui->lineEdit_mail_update_2->clear();
    ui->lineEdit_gsm_update_2->clear();
    ui->lineEdit_role_update_2->clear();
    ui->lineEdit_salaire_update_2->clear();
}

void MainWindow::on_tab_employee_2_activated(const QModelIndex &index)
{
    QString value=ui->tab_employee_2->model()->data(index).toString();

    QSqlQuery qry;

    //Refresh (Actualiser)
    ui->tab_employee_2->setModel(E.afficher());

    qry.prepare("select * from EMPLOYE where MATRICULE='"+value+"'");
    if(qry.exec())
    {
       while(qry.next())
       {
           ui->lineEdit_matricule_update_2->setText(qry.value(0).toString());
           ui->lineEdit_Nom_update_2->setText(qry.value(1).toString());
           ui->lineEdit_prenom_update_2->setText(qry.value(2).toString());
           ui->lineEdit_mail_update_2->setText(qry.value(3).toString());
           ui->lineEdit_gsm_update_2->setText(qry.value(4).toString());
           ui->lineEdit_role_update_2->setText(qry.value(5).toString());
           ui->lineEdit_salaire_update_2->setText(qry.value(6).toString());
           //optionnel quand ti cliques sur le matricule le champ de la suppression se rempli automatiquement
           ui->lineEdit_2->setText(qry.value(0).toString());
       }
    }
}

void MainWindow::on_radioButton_tri_personnel_7_clicked()
{
    ui->tab_employee_2->setModel(E.afficher_tri_matricule());
}

void MainWindow::on_radioButton_tri_personnel_5_clicked()
{
    ui->tab_employee_2->setModel( E.Tri_nom());
}

void MainWindow::on_radioButton_tri_personnel_6_clicked()
{
    ui->tab_employee_2->setModel( E.afficher_tri_gsm());
}

void MainWindow::on_recherche_par_reference_6_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_par_reference_6->text();
    ui->tab_employee_2->setModel(E.Rechercheemployee(rech));
}


void MainWindow::on_qrCode_2_clicked()
{
    int tabeq=ui->tab_employee_2->currentIndex().row();
    QVariant idd=ui->tab_employee_2->model()->data(ui->tab_employee_2->model()->index(tabeq,0));
    QString matricule=idd.toString();
    // QString code=idd.toSTring();
    QSqlQuery qry;
    qry.prepare("select * from EMPLOYE where code=:code");
    qry.bindValue(":code",matricule);
    qry.exec();

    QString nom_emp,prenom_emp,mail_emp,role_emp;//attributs
    int matricule_emp,gsm_emp,salaire_emp;
    QDate datep;

    while(qry.next())
    {
        matricule=qry.value(1).toInt();
        nom_emp=qry.value(2).toString();
        prenom_emp=qry.value(3).toString();
        mail_emp=qry.value(4).toString();
        gsm_emp=qry.value(5).toInt();
        role_emp=qry.value(6).toString();
        salaire_emp=qry.value(7).toInt();
    }
    matricule=QString(matricule);
    matricule="MATRICULE:\t" +matricule+ "NOM_EMP\t:" +nom_emp+ "PRENOM_EMP:\t" +prenom_emp+ "MAIL_EMP:\t" +mail_emp+ "GSM:\t" +gsm_emp+ "ROLE_EMP:\t" +role_emp+ "SALAIRE_EMP:\t" +salaire_emp ;
    QrCode qr = QrCode::encodeText(matricule.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++)
    {
       for (int x = 0; x < qr.getSize(); x++)
       {
           int color = qr.getModule(x, y);  // 0 for white, 1 for black
           // You need to modify this part
           if(color==0)
               im.setPixel(x, y,qRgb(254, 254, 254));
           else
               im.setPixel(x, y,qRgb(0, 0, 0));
       }
    }
    im=im.scaled(200,200);
    ui->qr_code_2->setPixmap(QPixmap::fromImage(im));
}


void MainWindow::on_homeButton_recherche_2_clicked()
{
    ui->tableView_historique_4->setModel(E.afficher_historique());
}
