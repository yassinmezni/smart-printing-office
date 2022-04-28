#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QDebug>
#include <QComboBox>
#include <QPieSlice>
#include <QPieSeries>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include "QSortFilterProxyModel"
#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>
#include <QMediaPlayer>
#include <QTimer>


#include "produit.h"
#include "smtp.h"




//CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF


void MainWindow::on_homeButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_8_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_9_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_valider_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    ui->comboBox_4->setModel(b.combobox_fk());
    ui->comboBox_6->setModel(b.combobox_fk());
    int id_produit=ui->lineEdit_id->text().toInt();//Convertir la chaine saisie en un entier
    QString nom_produit=ui->lineEdit_nom_2->text();
    QString video=ui->lineEdit_viedo->text();
    int qt_stock=ui->lineEdit_stock->text().toInt();
    int prix_uni=ui->lineEdit_prix->text().toInt();

    int FK_FOURNISSEUR_PR=ui->comboBox_4->currentText().toInt();
    produit b(id_produit,qt_stock,FK_FOURNISSEUR_PR,nom_produit, video,prix_uni);

    bool test=b.ajouter();//inserition de l'instance objet produit dans la table produit
    if(test)
    {
        ui->comboBox_5->setModel(b.afficher_id());
        ui->tab_produit->setModel(b.afficher());

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
                                              "La référence existe déjà\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Addition not made\n"
                                              "The reference already exists\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Adición no hecha\n"
                                              "La referencia ya existe\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
    ui->lineEdit_id->clear();
    ui->lineEdit_nom_2->clear();
    ui->lineEdit_viedo->clear();
    ui->lineEdit_stock->clear();
    ui->lineEdit_prix->clear();
}


void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    int id=ui->comboBox_5->currentText().toInt();

    QSqlQuery query;
    query.prepare("select * from PRODUITS where ID_PRODUIT=:id");
    query.bindValue(":id",id);

    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_del->setText(query.value(0).toString());
            ui->update_id->setText(query.value(0).toString());
            ui->update_nom->setText(query.value(1).toString());
            ui->update_stock->setText(query.value(2).toString());
            ui->update_prix->setText(query.value(3).toString());
            ui->update_video->setText(query.value(4).toString());
        }
    }
}


void MainWindow::on_tab_produit_activated(const QModelIndex &index)
{
    QString value=ui->tab_produit->model()->data(index).toString();

    QSqlQuery qry;
    produit b;

    //Refresh (Actualiser)
    ui->tab_produit->setModel(b.afficher());

    qry.prepare("select * from PRODUITS where id_produit='"+value+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_del->setText(qry.value(0).toString());
            ui->update_id->setText(qry.value(0).toString());
            ui->update_nom->setText(qry.value(1).toString());
            ui->update_stock->setText(qry.value(2).toString());
            ui->update_prix->setText(qry.value(3).toString());
            ui->update_video->setText(qry.value(4).toString());
        }
    }
}



void MainWindow::on_pushButton_delete_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_produit=ui->lineEdit_del->text().toInt();
    bool test= b.supprimer(id_produit);//Appel de la méthode supprimer() via l’attribut b

    if(test)
    {
        ui->comboBox_5->setModel(b.afficher_id());
        ui->tab_produit->setModel(b.afficher());
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
        ui->lineEdit_del->clear();
        ui->update_id->clear();
        ui->update_nom->clear();
        ui->update_video->clear();
        ui->update_stock->clear();
        ui->update_prix->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion not performed.\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Borrado no realizado.\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_produit=ui->update_id->text().toInt();
    QString nom_produit=ui->update_nom->text();
    QString video=ui->update_video->text();
    int qt_stock=ui->update_stock->text().toInt();
    int prix_uni=ui->update_prix->text().toInt();

    int FK_FOURNISSEUR_PR=ui->comboBox_6->currentText().toInt();
    produit b(id_produit,qt_stock,FK_FOURNISSEUR_PR,nom_produit, video,prix_uni);//
    b.update(id_produit);

    if(b.update(id_produit))
    {
        ui->comboBox_5->setModel(b.afficher_id());
        ui->tab_produit->setModel(b.afficher());
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
        ui->lineEdit_del->clear();
        ui->update_id->clear();
        ui->update_nom->clear();
        ui->update_video->clear();
        ui->update_stock->clear();
        ui->update_prix->clear();

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



void MainWindow::on_pushButton_mail_clicked()
{
    ui->comboBox_mail_4->setModel(b.afficher_email());
    Smtp* smtp = new Smtp("mediouni7.dhia@gmail.com","xmanetdhia@2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("mediouni7.dhia@gmail.com",ui->comboBox_mail_4->currentText(),ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::on_pb_gotomail_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
    QDesktopServices::openUrl(link);
}


void MainWindow::on_recherche_par_reference_3_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_par_reference_3->text();
    ui->tab_produit->setModel(b.Rechercheproduit(rech));
}

void MainWindow::on_read_clicked()
{
    ui->tab_produit->setModel(b.afficher());
}


void MainWindow::on_radioButton_3_clicked()
{
    ui->tab_produit->setModel(b.tri_prix());
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->tab_produit->setModel(b.Tri_nom());
}

void MainWindow::on_radioButton_clicked()
{
    ui->tab_produit->setModel(b.tri_id());
}

void MainWindow::on_loadButton_historique_clicked()
{
    ui->tableView_historique_2->setModel(b.afficher_historique());
}


void MainWindow::on_actionstop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stopped");
}

void MainWindow::on_actionpause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Paused...");
}

void MainWindow::on_actionplay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing");
}


void MainWindow::on_actionNew_User_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    on_actionstop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionplay_triggered();
}



//SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE


void MainWindow::on_valider_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    ui->comboBox_7->setModel(b.combobox_fk());
    ui->comboBox_10->setModel(b.combobox_fk());

    int id_produit=ui->lineEdit_id_2->text().toInt();//Convertir la chaine saisie en un entier
    QString nom_produit=ui->lineEdit_nom_3->text();
    QString video=ui->lineEdit_viedo_2->text();
    int qt_stock=ui->lineEdit_stock_2->text().toInt();
    int prix_uni=ui->lineEdit_prix_2->text().toInt();

    int FK_FOURNISSEUR_PR=ui->comboBox_4->currentText().toInt();
    produit b(id_produit,qt_stock,FK_FOURNISSEUR_PR,nom_produit, video,prix_uni);

    bool test=b.ajouter();//inserition de l'instance objet produit dans la table produit
    if(test)
    {
        ui->comboBox_9->setModel(b.afficher_id());
        ui->tab_produit_2->setModel(b.afficher());

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
        ui->lineEdit_id_2->clear();
        ui->lineEdit_nom_3->clear();
        ui->lineEdit_viedo_2->clear();
        ui->lineEdit_stock_2->clear();
        ui->lineEdit_prix_2->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Ajout non effectué\n"
                                              "La référence existe déjà\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Addition not made\n"
                                              "The reference already exists\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Adición no hecha\n"
                                              "La referencia ya existe\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
        ui->lineEdit_id_2->clear();
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_produit=ui->update_id_2->text().toInt();
    QString nom_produit=ui->update_nom_2->text();
    QString video=ui->update_video_2->text();
    int qt_stock=ui->update_stock_2->text().toInt();
    int prix_uni=ui->update_prix_2->text().toInt();

    int FK_FOURNISSEUR_PR=ui->comboBox_10->currentText().toInt();
    produit b(id_produit,qt_stock,FK_FOURNISSEUR_PR,nom_produit, video,prix_uni);
    b.update(id_produit);

    if(b.update(id_produit))
    {
        ui->comboBox_9->setModel(b.afficher_id());
        ui->tab_produit_2->setModel(b.afficher());
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
        ui->lineEdit_del_2->clear();
        ui->update_id_2->clear();
        ui->update_nom_2->clear();
        ui->update_video_2->clear();
        ui->update_stock_2->clear();
        ui->update_prix_2->clear();
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


void MainWindow::on_pushButton_delete_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();

    int id_produit=ui->lineEdit_del_2->text().toInt();
    bool test= b.supprimer(id_produit);//Appel de la méthode supprimer() via l’attribut b

    if(test)
    {
        ui->comboBox_9->setModel(b.afficher_id());
        ui->tab_produit_2->setModel(b.afficher());
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
        ui->lineEdit_del_2->clear();
        ui->update_id_2->clear();
        ui->update_nom_2->clear();
        ui->update_video_2->clear();
        ui->update_stock_2->clear();
        ui->update_prix_2->clear();
    }
    else
    {
        if (aj=="Francais")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }
        else if (aj=="English")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Deletion not performed.\n"
                                              "Click cancel to exit."),QMessageBox::Cancel);
        }
        else if (aj=="Espagnol")
        {
            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Borrado no realizado.\n"
                                              "Haga clic en cancelar para salir."),QMessageBox::Cancel);
        }
    }
}



void MainWindow::on_comboBox_9_currentIndexChanged(int index)
{
    int id=ui->comboBox_9->currentText().toInt();

    QSqlQuery query;
    query.prepare("select * from PRODUITS where ID_PRODUIT=:id");
    query.bindValue(":id",id);

    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_del_2->setText(query.value(0).toString());
            ui->update_id_2->setText(query.value(0).toString());
            ui->update_nom_2->setText(query.value(1).toString());
            ui->update_stock_2->setText(query.value(2).toString());
            ui->update_prix_2->setText(query.value(3).toString());
            ui->update_video_2->setText(query.value(4).toString());
        }
    }
}


void MainWindow::on_tab_produit_2_activated(const QModelIndex &index)
{
    QString value=ui->tab_produit_2->model()->data(index).toString();

    QSqlQuery qry;
    produit b;

    //Refresh (Actualiser)
    ui->tab_produit_2->setModel(b.afficher());

    qry.prepare("select * from PRODUITS where id_produit='"+value+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_del_2->setText(qry.value(0).toString());
            ui->update_id_2->setText(qry.value(0).toString());
            ui->update_nom_2->setText(qry.value(1).toString());
            ui->update_stock_2->setText(qry.value(2).toString());
            ui->update_prix_2->setText(qry.value(3).toString());
            ui->update_video_2->setText(qry.value(4).toString());
        }
    }
}


void MainWindow::on_recherche_par_reference_5_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_par_reference_5->text();
    ui->tab_produit_2->setModel(b.Rechercheproduit(rech));
}



void MainWindow::on_radioButton_6_clicked()
{
    ui->tab_produit_2->setModel(b.tri_prix());
}

void MainWindow::on_radioButton_5_clicked()
{
    ui->tab_produit_2->setModel(b.Tri_nom());
}

void MainWindow::on_radioButton_4_clicked()
{
    ui->tab_produit_2->setModel(b.tri_id());
}


void MainWindow::on_read_2_clicked()
{
    ui->tab_produit_2->setModel(b.afficher());
}



void MainWindow::on_pushButton_mail_2_clicked()
{
    ui->comboBox_mail_5->setModel(b.afficher_email());
    Smtp* smtp = new Smtp("mediouni7.dhia@gmail.com","xmanetdhia@2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("mediouni7.dhia@gmail.com",ui->comboBox_mail_5->currentText(),ui->subject_2->text(),ui->msg_2->toPlainText());
}


void MainWindow::on_pb_gotomail_2_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
    QDesktopServices::openUrl(link);
}



void MainWindow::on_loadButton_historique_5_clicked()
{
    ui->tableView_historique_7->setModel(b.afficher_historique());
}

void MainWindow::on_homeButton_21_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_20_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_17_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_16_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}
void MainWindow::on_homeButton_15_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}
