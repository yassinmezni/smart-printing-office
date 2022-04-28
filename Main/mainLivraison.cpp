#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QDesktopServices>

#include "livraison.h"



//CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF


void MainWindow::on_ajouter_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id=ui->le_id_3->text().toInt();
    QString date=ui->la_date_3->text();
    QString localisation=ui->l_adress_3->text();
    int frais=ui->le_frais_3->text().toInt();

    livraison L(id, date, localisation, frais);
    bool test=L.ajouter();

    if(test)

    {
        //REFRESH
        ui->table_livraison->setModel(L.afficher());
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
        ui->le_id_3->clear();
        ui->la_date_3->clear();
        ui->l_adress_3->clear();
        ui->le_frais_3->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Ajout non effectué\n"
                                              "L'ID existe déjà\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Addition not made\n"
                                              "ID already exists\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Adición no hecha\n"
                                              "ID ya existe\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->le_id_3->clear();
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    L.setid(ui->le_id_2->text().toInt());
    L.setdate(ui->la_date_2->text());
    L.setlocalisation(ui->l_adress_2->text());
    L.setfrais(ui->le_frais_2->text().toInt());

    bool check=L.modifier();

    if (check)
    {
        //Refresh (Actualiser l'affichage apres la modification)
        ui->table_livraison->setModel(L.afficher());
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
        ui->le_id_2->clear();
        ui->la_date_2->clear();
        ui->l_adress_2->clear();
        ui->le_frais_2->clear();
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


void MainWindow::on_pushButton_clicked()
{
    ui->table_livraison->setModel(L.afficher());
}


void MainWindow::on_table_livraison_activated(const QModelIndex &index)
{
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


void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    QString rech=ui->recherche->text();
    ui->table_livraison->setModel(L.Recherchelivreur(rech));
}


void MainWindow::on_supprimer2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_supp2=ui->le_id_sup_2->text().toInt();
    bool test=L.supprimer(id_supp2);

    if(test)
    {
        //Refresh (Actualiser)
        ui->table_livraison->setModel(L.afficher());
        if (aj=="Francais")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression effectuée\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion was made\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Eliminación realizada\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->le_id_sup_2->clear();
        ui->le_id_2->clear();
        ui->la_date_2->clear();
        ui->l_adress_2->clear();
        ui->le_frais_2->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "L'ID n'existe pas."
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion not performed.\n"
                                              "ID does not exist."
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Borrado no realizado.\n"
                                              "ID no existe."
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->le_id_sup_2->clear();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString link="https://esprit.tn/";
    QDesktopServices::openUrl(link);
}


void MainWindow::on_comboBox_tri_activated(const QString &arg1)
{
    QString tri=ui->comboBox_tri->currentText();

    if(tri=="ID ASC" || tri=="Ascendant ID" || tri=="ID de ascendente")
    {
        ui->table_livraison->setModel(L.trierlivraisonParid_M());
    }
    else if(tri=="ID DESC" || tri=="Descendant ID" || tri=="ID de descendiente")
    {
        ui->table_livraison->setModel(L.trierlivraisonParid_D());
    }
    else if(tri=="Destination" || tri=="Destino")
    {
        ui->table_livraison->setModel(L.trierlivraisonParlocalisation());
    }
    else if(tri=="Frais" || tri=="Costs" || tri=="Costo")
    {
        ui->table_livraison->setModel(L.trierlivraisonParfrais_M());
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->tablehistorique->setModel(L.afficherhistorique());
}

void MainWindow::on_homeButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_11_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}




//LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR



void MainWindow::on_ajouter_5_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id=ui->le_id_16->text().toInt();
    QString date=ui->la_date_10->text();
    QString localisation=ui->l_adress_10->text();
    int frais=ui->le_frais_10->text().toInt();

    livraison L(id, date, localisation, frais);
    bool test=L.ajouter();

    if(test)

    {
        //REFRESH
        ui->table_livraison_5->setModel(L.afficher());
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
        ui->le_id_16->clear();
        ui->la_date_10->clear();
        ui->l_adress_10->clear();
        ui->le_frais_10->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Ajout non effectué\n"
                                              "L'ID existe déjà\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Addition not made\n"
                                              "ID already exists\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Adición no hecha\n"
                                              "Identificación ya existe\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->le_id_16->clear();
    }
}


void MainWindow::on_pushButton_38_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    L.setid(ui->le_id_17->text().toInt());
    L.setdate(ui->la_date_11->text());
    L.setlocalisation(ui->l_adress_11->text());
    L.setfrais(ui->le_frais_11->text().toInt());

    bool check=L.modifier();

    if (check)
    {
        //Refresh (Actualiser l'affichage apres la modification)
        ui->table_livraison_5->setModel(L.afficher());
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
        ui->le_id_17->clear();
        ui->la_date_11->clear();
        ui->l_adress_11->clear();
        ui->le_frais_11->clear();
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


void MainWindow::on_table_livraison_5_activated(const QModelIndex &index)
{
    QString value=ui->table_livraison_5->model()->data(index).toString();
    QSqlQuery qry;

    //Refresh (Actualiser)
    ui->table_livraison->setModel(L.afficher());

    qry.prepare("select * from livraison where ID_L='"+value+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->le_id_17->setText(qry.value(0).toString());
            ui->la_date_11->setText(qry.value(1).toString());
            ui->l_adress_11->setText(qry.value(2).toString());
            ui->le_frais_11->setText(qry.value(3).toString());
            ui->le_id_sup_6->setText(qry.value(0).toString());
        }
    }
}


void MainWindow::on_supprimer2_5_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_supp2=ui->le_id_sup_6->text().toInt();
    bool test=L.supprimer(id_supp2);

    if(test)
    {
        //Refresh (Actualiser)
        ui->table_livraison_5->setModel(L.afficher());
        if (aj=="Francais")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression effectuée\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion was made\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Eliminación realizada\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->le_id_sup_6->clear();
        ui->le_id_17->clear();
        ui->la_date_11->clear();
        ui->l_adress_11->clear();
        ui->le_frais_11->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "L'ID n'existe pas."
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion not performed.\n"
                                              "ID does not exist."
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Borrado no realizado.\n"
                                              "ID no existe."
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
    ui->le_id_sup_6->clear();
}


void MainWindow::on_comboBox_tri_8_activated(const QString &arg1)
{
    QString tri=ui->comboBox_tri_8->currentText();

    if(tri=="ID ASC" || tri=="Ascendant ID" || tri=="ID de ascendente")
    {
        ui->table_livraison_5->setModel(L.trierlivraisonParid_M());
    }
    else if(tri=="ID DESC" || tri=="Descendant ID" || tri=="ID de descendiente")
    {
        ui->table_livraison_5->setModel(L.trierlivraisonParid_D());
    }
    else if(tri=="Destination" || tri=="Destino")
    {
        ui->table_livraison_5->setModel(L.trierlivraisonParlocalisation());
    }
    else if(tri=="Frais" || tri=="Costs" || tri=="Costo")
    {
        ui->table_livraison_5->setModel(L.trierlivraisonParfrais_M());
    }
}


void MainWindow::on_recherche_5_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_5->text();
    ui->table_livraison_5->setModel(L.Recherchelivreur(rech));
}



/*Actualiser*/
void MainWindow::on_pushButton_39_clicked()
{
    ui->table_livraison_5->setModel(L.afficher());
}

/*Actualiser Historique*/
void MainWindow::on_pushButton_42_clicked()
{
    ui->tablehistorique_5->setModel(L.afficherhistorique());
}

void MainWindow::on_homeButton_45_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_homeButton_46_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_pushButton_41_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_pushButton_40_clicked()
{
    QString link="https://esprit.tn/";
    QDesktopServices::openUrl(link);
}



//SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE


void MainWindow::on_ajouter_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id=ui->le_id_4->text().toInt();
    QString date=ui->la_date_4->text();
    QString localisation=ui->l_adress_4->text();
    int frais=ui->le_frais_4->text().toInt();

    livraison L(id, date, localisation, frais);
    bool test=L.ajouter();

    if(test)

    {
        //REFRESH
        ui->table_livraison_2->setModel(L.afficher());
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
        ui->le_id_4->clear();
        ui->la_date_4->clear();
        ui->l_adress_4->clear();
        ui->le_frais_4->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Ajout non effectué\n"
                                              "L'ID existe déjà\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Addition not made\n"
                                              "ID already exists\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Adición no hecha\n"
                                              "Identificación ya existe\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->le_id_4->clear();
    }
}

void MainWindow::on_homeButton_19_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}


void MainWindow::on_pushButton_17_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    L.setid(ui->le_id_9->text().toInt());
    L.setdate(ui->la_date_5->text());
    L.setlocalisation(ui->l_adress_5->text());
    L.setfrais(ui->le_frais_5->text().toInt());

    bool check=L.modifier();

    if (check)
    {
        //Refresh (Actualiser l'affichage apres la modification)
        ui->table_livraison_2->setModel(L.afficher());
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
        ui->le_id_9->clear();
        ui->la_date_5->clear();
        ui->l_adress_5->clear();
        ui->le_frais_5->clear();
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


void MainWindow::on_supprimer2_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_supp2=ui->le_id_sup_3->text().toInt();
    bool test=L.supprimer(id_supp2);

    if(test)
    {
        //Refresh (Actualiser)
        ui->table_livraison_2->setModel(L.afficher());
        if (aj=="Francais")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression effectuée\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion was made\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Eliminación realizada\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->le_id_sup_6->clear();
        ui->le_id_9->clear();
        ui->la_date_5->clear();
        ui->l_adress_5->clear();
        ui->le_frais_5->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "L'ID n'existe pas."
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion not performed.\n"
                                              "ID does not exist."
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Borrado no realizado.\n"
                                              "ID no existe."
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
    ui->le_id_sup_6->clear();
}


void MainWindow::on_table_livraison_2_activated(const QModelIndex &index)
{
    QString value=ui->table_livraison_2->model()->data(index).toString();
    QSqlQuery qry;

    //Refresh (Actualiser)
    ui->table_livraison->setModel(L.afficher());

    qry.prepare("select * from livraison where ID_L='"+value+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->le_id_9->setText(qry.value(0).toString());
            ui->la_date_5->setText(qry.value(1).toString());
            ui->l_adress_5->setText(qry.value(2).toString());
            ui->le_frais_5->setText(qry.value(3).toString());
            ui->le_id_sup_3->setText(qry.value(0).toString());
        }
    }
}


void MainWindow::on_comboBox_tri_4_activated(const QString &arg1)
{
    QString tri=ui->comboBox_tri_4->currentText();

    if(tri=="ID ASC" || tri=="Ascendant ID" || tri=="ID de ascendente")
    {
        ui->table_livraison_2->setModel(L.trierlivraisonParid_M());
    }
    else if(tri=="ID DESC" || tri=="Descendant ID" || tri=="ID de descendiente")
    {
        ui->table_livraison_2->setModel(L.trierlivraisonParid_D());
    }
    else if(tri=="Destination" || tri=="Destino")
    {
        ui->table_livraison_2->setModel(L.trierlivraisonParlocalisation());
    }
    else if(tri=="Frais" || tri=="Costs" || tri=="Costo")
    {
        ui->table_livraison_2->setModel(L.trierlivraisonParfrais_M());
    }
}


void MainWindow::on_recherche_2_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_2->text();
    ui->table_livraison_2->setModel(L.Recherchelivreur(rech));
}


void MainWindow::on_pushButton_18_clicked()
{
    ui->table_livraison_2->setModel(L.afficher());
}


void MainWindow::on_pushButton_19_clicked()
{
    QString link="https://esprit.tn/";
    QDesktopServices::openUrl(link);
}

void MainWindow::on_homeButton_24_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->tablehistorique_2->setModel(L.afficherhistorique());
}


