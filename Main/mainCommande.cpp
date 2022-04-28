#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>

#include "commande.h"
#include "statistic.h"



//CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF



void MainWindow::on_pb_Ajouter_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int ID_CMD=ui->le_id_5->text().toInt();
    float PRIX=ui->le_prix_3->text().toFloat();
    QString DATE_COM=ui->le_DATE_2->text();
    int QT_COMMANDES=ui->le_Quantite_2->text().toInt();

    Commande C(ID_CMD,PRIX,DATE_COM,QT_COMMANDES);
    bool test=C.ajouter();

    if(test)
    {
        ui->tableView_aff_2->setModel(Ctmp.afficher());

        if (aj=="Francais")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestion des commandes","Commande ajoutée.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="English")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Order management","Order added.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="Espagnol")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestión de pedidos","Pedido añadido.",QSystemTrayIcon::Information,15000);
        }
        ui->le_id_5->clear();
        ui->le_prix_3->clear();
        ui->le_DATE_2->clear();
        ui->le_Quantite_2->clear();
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
        ui->le_id_5->clear();
    }
}


void MainWindow::on_supp_Button_3_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id=ui->supprimer_id_2->text().toInt();
    bool test=Ctmp.supprimer(id);
    if (test)
    {
        ui->tableView_aff_2->setModel(Ctmp.afficher());

        if (aj=="Francais")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestion des commandes","Commande supprimée.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="English")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Order Management","Order deleted.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="Espagnol")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestión de pedidos","Pedido eliminado.",QSystemTrayIcon::Information,15000);
        }

        ui->supprimer_id_2->clear();
        ui->le_id_6->clear();
        ui->le_prix_4->clear();
        ui->le_DATE_5->clear();
        ui->le_Quantite_5->clear();
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
        ui->le_id_6->clear();
        ui->le_prix_4->clear();
        ui->le_DATE_5->clear();
        ui->le_Quantite_5->clear();
    }
}


void MainWindow::on_modifierButton_5_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int ID_CMD=ui->le_id_6->text().toInt();
    int PRIX=ui->le_prix_4->text().toFloat();
    QString DATE=ui->le_DATE_5->text();
    int QT_COMMANDES=ui->le_Quantite_5->text().toInt();


    Commande C(ID_CMD,PRIX,DATE,QT_COMMANDES);
    bool test=C.modifier();
    if(test)
    {
         ui->tableView_aff_2->setModel(Ctmp.afficher());

         if (aj=="Francais")
         {
             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->showMessage("Gestion des commandes","Commande modifiée.",QSystemTrayIcon::Information,15000);
         }
         else if (aj=="English")
         {
             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->showMessage("Order Management","Order modified.",QSystemTrayIcon::Information,15000);
         }
         else if (aj=="Espagnol")
         {
             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->showMessage("Gestión de pedidos","Pedido modificado.",QSystemTrayIcon::Information,15000);
         }
         ui->le_id_6->clear();
         ui->le_prix_4->clear();
         ui->le_DATE_5->clear();
         ui->le_Quantite_5->clear();
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

void MainWindow::on_tableView_aff_2_activated(const QModelIndex &index)
{
    QString id_modif=ui->tableView_aff_2->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("select * from commandes where ID_COMMANDE='"+id_modif+"'");
    if (qry.exec())
    {
        while (qry.next())
        {
            ui->supprimer_id_2->setText(qry.value(0).toString());
            ui->le_id_6->setText(qry.value(0).toString());
            ui->le_prix_4->setText(qry.value(1).toString());
            ui->le_DATE_5->setText(qry.value(2).toString());
            ui->le_Quantite_5->setText(qry.value(3).toString());
        }
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->tableView_aff_2->setModel(Ctmp.sort_ID_CMD());
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->tableView_aff_2->setModel(Ctmp.sort_QT_COMMANDES());
}

void MainWindow::on_modifierButton_recherche_3_clicked()
{
    int id = ui->find_4->text().toInt();
    ui->tableView_aff_2->setModel(Ctmp.rechercher_ID_CMD(id));
}

void MainWindow::on_modifierButton_recherche_4_clicked()
{
    int qt = ui->find_5->text().toInt();
    ui->tableView_aff_2->setModel(Ctmp.rechercherr_QT_COMMANDES(qt));
}

/*Bouton Actualiser*/
void MainWindow::on_Paffiche_2_clicked()
{
    ui->tableView_aff_2->setModel(Ctmp.afficher());
}

/*Bouton Actualiser Historique*/
void MainWindow::on_loadButton_historique_3_clicked()
{
    ui->tableView_historique_5->setModel(Ctmp.afficher_historique());
}

/*Bouton Statistiques*/
void MainWindow::on_pushButton_stat_2_clicked()
{
    statistic = new class Statistic(this);
    statistic->setWindowIcon(QIcon(":/img/img/Logo.png"));
    statistic->setWindowTitle("SPS | Statistiques");
    statistic->show();
}

//home->ajout
void MainWindow::on_homeButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

//home->gestion
void MainWindow::on_homeButton_10_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

//home->historique
void MainWindow::on_homeButton_12_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}



//SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE



void MainWindow::on_pb_Ajouter_3_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int ID_CMD=ui->le_id_7->text().toInt();
    float PRIX=ui->le_prix_5->text().toFloat();
    QString DATE_COM=ui->le_DATE_3->text();
    int QT_COMMANDES=ui->le_Quantite_3->text().toInt();

    Commande C(ID_CMD,PRIX,DATE_COM,QT_COMMANDES);
    bool test=C.ajouter();

    if(test)
    {
        ui->tableView_aff_3->setModel(Ctmp.afficher());

        if (aj=="Francais")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestion des commandes","Commande ajoutée.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="English")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Order management","Order added.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="Espagnol")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestión de pedidos","Pedido añadido.",QSystemTrayIcon::Information,15000);
        }
        ui->le_id_7->clear();
        ui->le_prix_5->clear();
        ui->le_DATE_3->clear();
        ui->le_Quantite_3->clear();
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
        ui->le_id_7->clear();
    }
}

void MainWindow::on_homeButton_18_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_modifierButton_7_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int ID_CMD=ui->le_id_8->text().toInt();
    int PRIX=ui->le_prix_6->text().toFloat();
    QString DATE=ui->le_DATE_6->text();
    int QT_COMMANDES=ui->le_Quantite_6->text().toInt();


    Commande C(ID_CMD,PRIX,DATE,QT_COMMANDES);
    bool test=C.modifier();
    if(test)
    {
         ui->tableView_aff_3->setModel(Ctmp.afficher());

         if (aj=="Francais")
         {
             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->showMessage("Gestion des commandes","Commande modifiée.",QSystemTrayIcon::Information,15000);
         }
         else if (aj=="English")
         {
             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->showMessage("Order Management","Order modified.",QSystemTrayIcon::Information,15000);
         }
         else if (aj=="Espagnol")
         {
             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->showMessage("Gestión de pedidos","Pedido modificado.",QSystemTrayIcon::Information,15000);
         }
         ui->le_id_8->clear();
         ui->le_prix_6->clear();
         ui->le_DATE_6->clear();
         ui->le_Quantite_6->clear();
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

void MainWindow::on_supp_Button_4_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id=ui->supprimer_id_3->text().toInt();
    bool test=Ctmp.supprimer(id);
    if (test)
    {
        ui->tableView_aff_3->setModel(Ctmp.afficher());

        if (aj=="Francais")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestion des commandes","Commande supprimée.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="English")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Order Management","Order deleted.",QSystemTrayIcon::Information,15000);
        }
        else if (aj=="Espagnol")
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Gestión de pedidos","Pedido eliminado.",QSystemTrayIcon::Information,15000);
        }

        ui->supprimer_id_3->clear();
        ui->le_id_8->clear();
        ui->le_prix_6->clear();
        ui->le_DATE_6->clear();
        ui->le_Quantite_6->clear();
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
        ui->le_id_sup_3->clear();
    }
}


void MainWindow::on_tableView_aff_3_activated(const QModelIndex &index)
{
    QString id_modif=ui->tableView_aff_3->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("select * from commandes where ID_COMMANDE='"+id_modif+"'");
    if (qry.exec())
    {
        while (qry.next())
        {
            ui->supprimer_id_3->setText(qry.value(0).toString());
            ui->le_id_8->setText(qry.value(0).toString());
            ui->le_prix_6->setText(qry.value(1).toString());
            ui->le_DATE_6->setText(qry.value(2).toString());
            ui->le_Quantite_6->setText(qry.value(3).toString());
        }
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->tableView_aff_3->setModel(Ctmp.sort_ID_CMD());
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->tableView_aff_3->setModel(Ctmp.sort_QT_COMMANDES());
}

void MainWindow::on_modifierButton_recherche_5_clicked()
{
    int id = ui->find_6->text().toInt();
    ui->tableView_aff_3->setModel(Ctmp.rechercher_ID_CMD(id));
}

void MainWindow::on_modifierButton_recherche_6_clicked()
{
    int qt = ui->find_7->text().toInt();
    ui->tableView_aff_3->setModel(Ctmp.rechercherr_QT_COMMANDES(qt));
}


void MainWindow::on_Paffiche_3_clicked()
{
    ui->tableView_aff_3->setModel(Ctmp.afficher());
}

void MainWindow::on_pushButton_stat_3_clicked()
{
    statistic = new class Statistic(this);
    statistic->setWindowIcon(QIcon(":/img/img/Logo.png"));
    statistic->setWindowTitle("SPS | Statistiques");
    statistic->show();
}


void MainWindow::on_homeButton_22_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}


void MainWindow::on_loadButton_historique_6_clicked()
{
    ui->tableView_historique_8->setModel(Ctmp.afficher_historique());
}


void MainWindow::on_homeButton_23_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}
