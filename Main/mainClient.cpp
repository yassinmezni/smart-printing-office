#include "mainwindow.h"
#include "ui_mainwindow.h"

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

#include "excel.h"
#include "client.h"




//CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF


void MainWindow::on_addbutton_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int cin=ui->le_cin_3->text().toInt();
    QString nom=ui->le_nom_3->text();
    QString prenom=ui->le_prenom_3->text();
    QString adresse=ui->l_adresse_3->text();
    QString mail=ui->le_mail_3->text();
    int numtel=ui->le_num_3->text().toInt();
    QString cin1=ui->le_cin_3->text();

    client c( cin, nom, prenom, adresse, numtel,mail);
    bool test=c.ajouter();

    if(test)

    {   //REFRESH
        ui->table_client_2->setModel(c.afficher());
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

    ui->le_cin_3->clear();
    ui->le_nom_3->clear();
    ui->le_prenom_3->clear();
    ui->l_adresse_3->clear();
    ui->le_num_3->clear();
    ui->le_mail_3->clear();
}


void MainWindow::on_deletebutton_3_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_supp=ui->le_cin_sup_2->text().toInt();
    bool test=c.supprimer(id_supp);
    QString cin1=ui->le_cin_sup_2->text();

    if(test)
    {
        ui->table_client_2->setModel(c.afficher());
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
    ui->le_cin_sup_2->clear();
}


void MainWindow::on_table_client_2_activated(const QModelIndex &index)
{
    QString cin_modif=ui->table_client_2->model()->data(index).toString();
    QSqlQuery qry;

    //Refresh (Actualiser)
    ui->table_client_2->setModel(c.afficher());

    qry.prepare("select * from clients where CIN='"+cin_modif+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->le_cin_sup_2->setText(qry.value(0).toString());
            ui->le_cin_4->setText(qry.value(0).toString());
            ui->le_nom_4->setText(qry.value(1).toString());
            ui->le_prenom_4->setText(qry.value(2).toString());
            ui->l_adresse_4->setText(qry.value(3).toString());
            ui->le_num_4->setText(qry.value(4).toString());
            ui->le_mail_4->setText(qry.value(5).toString());
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int cin=ui->le_cin_4->text().toInt();
    QString nom=ui->le_nom_4->text();
    QString prenom=ui->le_prenom_4->text();
    QString adresse=ui->l_adresse_4->text();
    QString mail=ui->le_mail_4->text();
    int numtel=ui->le_num_4->text().toInt();

    client c( cin, nom, prenom, adresse, numtel,mail);
    QString cin1=ui->le_cin_4->text();

    bool test=c.modifier(cin);
    if(test)
    {
        ui->table_client_2->setModel(c.afficher());
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
}


void MainWindow::on_lineEdit_recherche_client_2_textChanged(const QString &arg1)
{
    QString rech=ui->lineEdit_recherche_client_2->text();
    ui->table_client_2->setModel(c.Rechercheclient(rech));
}

void MainWindow::on_comboBox_tri_2_activated(const QString &arg1)
{
    QString tri=ui->comboBox_tri_2->currentText();

    if(tri=="CIN Montant" || tri=="CIN Ascending" || tri=="CIN Ascendente")
    {
        ui->table_client_2->setModel(c.trierclientParCIN_M());
    }
    else if(tri=="CIN Descendant" || tri=="CIN Descending"|| tri=="CIN Descendiente")
    {
        ui->table_client_2->setModel(c.trierclientParCIN_D());
    }
    else if(tri=="Nom"|| tri=="Name" || tri=="Nombre")
    {
        ui->table_client_2->setModel(c.trierclientParNom());
    }
    else if(tri=="Prénom" || tri=="First Name" || tri=="Apellido")
    {
        ui->table_client_2->setModel(c.trierclientParPrenom());
    }
}


void MainWindow::on_deletebutton_4_clicked()
{
    ui->table_client_2->setModel(c.afficher());
}


void MainWindow::on_excel_button_2_clicked()
{
        QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                               tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
             return;

        ExportExcelObject obj(fileName, "mydata", ui->table_client_2);

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
                                     QString(tr("%1 records exported!")).arg(retVal));
        }
}


void MainWindow::on_loadButton_historique_2_clicked()
{
    ui->tableView_historique_3->setModel(E.afficher_historique());
}





//SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE



void MainWindow::on_addbutton_3_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int cin=ui->le_cin_5->text().toInt();
    QString nom=ui->le_nom_5->text();
    QString prenom=ui->le_prenom_5->text();
    QString adresse=ui->l_adresse_5->text();
    QString mail=ui->le_mail_5->text();
    int numtel=ui->le_num_5->text().toInt();
    QString cin1=ui->le_cin_5->text();

    client c( cin, nom, prenom, adresse, numtel,mail);
    bool test=c.ajouter();

    if(test)

    {   //REFRESH
        ui->table_client_3->setModel(c.afficher());
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
        ui->le_cin_5->clear();
        ui->le_nom_5->clear();
        ui->le_prenom_5->clear();
        ui->l_adresse_5->clear();
        ui->le_num_5->clear();
        ui->le_mail_5->clear();
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
        ui->le_cin_5->clear();
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int cin=ui->le_cin_6->text().toInt();
    QString nom=ui->le_nom_6->text();
    QString prenom=ui->le_prenom_6->text();
    QString adresse=ui->l_adresse_6->text();
    QString mail=ui->le_mail_6->text();
    int numtel=ui->le_num_6->text().toInt();

    client c( cin, nom, prenom, adresse, numtel,mail);

    bool test=c.modifier(cin);
    if(test)
    {
        ui->table_client_3->setModel(c.afficher());
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
        ui->le_cin_6->clear();
        ui->le_nom_6->clear();
        ui->le_prenom_6->clear();
        ui->l_adresse_6->clear();
        ui->le_mail_6->clear();
        ui->le_num_6->clear();
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
        ui->le_cin_6->clear();
        ui->le_nom_6->clear();
        ui->le_prenom_6->clear();
        ui->l_adresse_6->clear();
        ui->le_mail_6->clear();
        ui->le_num_6->clear();
    }
}

void MainWindow::on_deletebutton_5_clicked()
{
    ui->table_client_3->setModel(c.afficher());
}

void MainWindow::on_excel_button_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
         return;

    ExportExcelObject obj(fileName, "mydata", ui->table_client_2);

    //colums to export
    obj.addField(0,"CIN","NUMBER");
    obj.addField(1,"Nom","varchar(50)");
    obj.addField(2,"Prénom","varchar(50)");
    obj.addField(3,"Adresse","varchar(50)");
    obj.addField(4,"Num Tel","NUMBER");
    obj.addField(5,"Email","varchar(50)");

    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal));
    }
}

void MainWindow::on_deletebutton_6_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_supp=ui->le_cin_sup_3->text().toInt();
    bool test=c.supprimer(id_supp);
    QString cin1=ui->le_cin_sup_3->text();

    if(test)
    {
        ui->table_client_3->setModel(c.afficher());
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
        ui->le_cin_sup_3->clear();
        ui->le_cin_6->clear();
        ui->le_nom_6->clear();
        ui->le_prenom_6->clear();
        ui->l_adresse_6->clear();
        ui->le_mail_6->clear();
        ui->le_num_6->clear();
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
    ui->le_cin_sup_3->clear();
}



void MainWindow::on_comboBox_tri_3_activated(const QString &arg1)
{
    QString tri=ui->comboBox_tri_3->currentText();

    if(tri=="CIN Montant" || tri=="CIN Ascending" || tri=="CIN Ascendente")
    {
        ui->table_client_3->setModel(c.trierclientParCIN_M());
    }
    else if(tri=="CIN Descendant" || tri=="CIN Descending"|| tri=="CIN Descendiente")
    {
        ui->table_client_3->setModel(c.trierclientParCIN_D());
    }
    else if(tri=="Nom"|| tri=="Name" || tri=="Nombre")
    {
        ui->table_client_3->setModel(c.trierclientParNom());
    }
    else if(tri=="Prénom" || tri=="First Name" || tri=="Apellido")
    {
        ui->table_client_3->setModel(c.trierclientParPrenom());
    }
}


void MainWindow::on_table_client_3_activated(const QModelIndex &index)
{
    QString cin_modif=ui->table_client_3->model()->data(index).toString();
    QSqlQuery qry;

    //Refresh (Actualiser)
    ui->table_client_3->setModel(c.afficher());

    qry.prepare("select * from clients where CIN='"+cin_modif+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
          ui->le_cin_sup_3->setText(qry.value(0).toString());
          ui->le_cin_6->setText(qry.value(0).toString());
          ui->le_nom_6->setText(qry.value(1).toString());
          ui->le_prenom_6->setText(qry.value(2).toString());
          ui->l_adresse_6->setText(qry.value(3).toString());
          ui->le_num_6->setText(qry.value(4).toString());
          ui->le_mail_6->setText(qry.value(5).toString());
        }
    }
}


void MainWindow::on_lineEdit_recherche_client_3_textChanged(const QString &arg1)
{
    QString rech=ui->lineEdit_recherche_client_3->text();
    ui->table_client_3->setModel(c.Rechercheclient(rech));
}


void MainWindow::on_loadButton_historique_4_clicked()
{
    ui->tableView_historique_6->setModel(E.afficher_historique());
}


void MainWindow::on_homeButton_14_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_25_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_26_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}
