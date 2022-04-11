#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include<QMessageBox>
#include <QString>
#include <QSqlQuery>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Commande Ctmp;
    ui->setupUi(this);
    ui->tableView_aff->setModel(Ctmp.afficher());
    ui->le_id->setValidator( new QIntValidator(0, 999999, this));
    ui->le_id ->setValidator( new QIntValidator(0, 999999, this));


    ui->comboBox_2->setModel(Ctmp.combobox_fk());


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
    int ID_CL=ui->comboBox_2->currentText().toInt();
    int FK_LIVRAISON=ui->comboBox_2->currentText().toInt();
    int FK_PRODUIT=ui->comboBox_2->currentText().toInt();
    Commande C(ID_CMD,PRIX,DATE_COM,QT_COMMANDES,ID_CL,FK_LIVRAISON,FK_PRODUIT);
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
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes "," Commande ajouté! ",QSystemTrayIcon::Information,15000);

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
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes "," Commande supprimé!! ",QSystemTrayIcon::Information,15000);
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
            int ID_CL=ui->comboBox_2->currentText().toInt();
            int FK_LIVRAISON=ui->comboBox_2->currentText().toInt();
            int FK_PRODUIT=ui->comboBox_2->currentText().toInt();
             Commande C(ID_CMD,PRIX,DATE,QT_COMMANDES,ID_CL,FK_LIVRAISON,FK_PRODUIT);
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
                         QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                         notifyIcon->show();
                         notifyIcon->showMessage("Gestion des commandes "," Commande modifié!!! ",QSystemTrayIcon::Information,15000);

            }

/*void MainWindow::on_comboBox_2_activated(const QString &arg1)
{

}

void MainWindow::on_le_id_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_combobox_fk_activated(const QString &arg1)
{

}
*/

void MainWindow::on_pushButton_clicked()
{
    ui->tableView_aff->setModel(Ctmp.sort_ID_CMD());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

/*void MainWindow::on_pushButton_2_clicked()
{
    Ctmp.cleartable(ui->tableView_aff);

}
*/


/*void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}*/

void MainWindow::on_le_id_2_textChanged(const QString &arg1)
{
    Ctmp.cleartable(ui->tableView_aff);
    int id = ui->le_id_2->text().toInt();
    Ctmp.rechercher_ID_CMD(ui->tableView_aff,id);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView_aff->setModel(Ctmp.sort_QT_COMMANDES());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche_clicked()
{

}




void MainWindow::on_le_Quantite_2_textChanged(const QString &arg1)
{
    Ctmp.cleartable(ui->tableView_aff);
    int qnt = ui->le_Quantite_2->text().toInt();
    Ctmp.rechercherr_QT_COMMANDES(ui->tableView_aff,qnt);
}

void MainWindow::on_le_prix_2_textChanged(const QString &arg1)
{
    Ctmp.cleartable(ui->tableView_aff);
    int prix = ui->le_prix_2->text().toFloat();
    Ctmp.rechrcherr_PRIX(ui->tableView_aff,prix);
}

void MainWindow::on_find_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_combobox_fk_activated(const QString &arg1)
{

}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{

}

void MainWindow::on_le_DATE_cursorPositionChanged(int arg1, int arg2)
{

}
