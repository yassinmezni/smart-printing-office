#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "historique.h"
#include "connection.cpp"
#include<QMessageBox>
#include<QComboBox>
#include<QSqlQuery>
#include <QIntValidator>
#include"produit1.h"
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QPrinter>
#include <QPrintDialog>
#include "smtp.h"
#include <QDebug>
#include<QComboBox>
#include <QPieSlice>
#include <QPieSeries>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include"QSortFilterProxyModel"
#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>
#include<QMediaPlayer>
#include <QTimer>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  produit b ;

    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    //this->setCentralWidget(vw);
    vw->setGeometry(100,100,300,400);
     QTimer::singleShot(10000,vw,SLOT(close()));


    player->play();


    slider = new QSlider(this);
    bar = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
    ui->statusBar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);


    ui->lineEdit_id->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_stock->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_prix->setValidator(new QIntValidator(0, 999999, this));
    ui->tab_produit->setModel(b.afficher());
    ui->comboBox->setModel(b.afficher_id());
    ui->comboBox_2->setModel(b.combobox_fk());
    ui->comboBox_3->setModel(b.combobox_fk());
    ui->comboBox_mail_4->setModel(b.afficher_email());


      QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b",
      QRegularExpression::CaseInsensitiveOption);
      ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rx, this));
      ui->lineEdit_viedo->setValidator(new QRegularExpressionValidator(rx, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_valider_clicked()
{
   int id_produit=ui->lineEdit_id->text().toInt();//Convertir la chaine saisie en un entier
    QString nom_produit=ui->lineEdit_nom->text();
     QString video=ui->lineEdit_viedo->text();
        int qt_stock=ui->lineEdit_stock->text().toInt();
       int prix_uni=ui->lineEdit_prix->text().toInt();
       int FK_FOURNISSEUR_PR=ui->comboBox_2->currentText().toInt();
         produit b(id_produit,qt_stock,FK_FOURNISSEUR_PR,nom_produit, video,prix_uni);
         bool test=b.ajouter();//inserition de l'instance objet produit dans la table produit
         if(test)
         {
             ui->comboBox->setModel(b.afficher_id());
             ui->tab_produit->setModel(b.afficher());

             QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("data added.\n"
                                                "clicl cancel to exit."),QMessageBox::Cancel);
         }
         else{
             QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("data not added.\n"
                                                "clicl cancel to exit."),QMessageBox::Cancel);
         }

}
















void MainWindow::on_read_clicked()
{
    produit b ;
    ui->tab_produit->setModel(b.afficher());
}

void MainWindow::on_pushButton_delete_clicked()
{

    int id_produit=ui->lineEdit_del->text().toInt();
    bool test= b.supprimer(id_produit);//Appel de la méthode supprimer() via l’attribut b
    if(test) {
        ui->comboBox->setModel(b.afficher_id());
        ui->tab_produit->setModel(b.afficher());
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("delete done.\n"
                                                  "clic cancel to exit."),QMessageBox::Cancel);
    }
    else
        {ui->tab_produit->setModel(b.afficher());
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("delete not done .\n"
                                           "clic cancel to exit."),QMessageBox::Cancel);}
}



void MainWindow::on_pushButton_2_clicked()
{
    int id_produit=ui->update_id->text().toInt();
     QString nom_produit=ui->update_nom->text();
      QString video=ui->update_video->text();
       int qt_stock=ui->update_stock->text().toInt();
        int prix_uni=ui->update_prix->text().toInt();
        int FK_FOURNISSEUR_PR=ui->comboBox_3->currentText().toInt();
          produit b(id_produit,qt_stock,FK_FOURNISSEUR_PR,nom_produit, video,prix_uni);
             b.update(id_produit);
             if(b.update(id_produit))
             {   ui->comboBox->setModel(b.afficher_id());
                 ui->tab_produit->setModel(b.afficher());
         QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("update effectue.\n"
                                            "clic cancel to exit."),QMessageBox::Cancel);

             }
     else
         {ui->tab_produit->setModel(b.afficher());
     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("update non effectue.\n"
                                            "clic cancel to exit."),QMessageBox::Cancel);}
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int id=ui->comboBox->currentText().toInt();

        QSqlQuery query;

    query.prepare("select * from PRODUITS where ID_PRODUIT=:id");
    query.bindValue(":id",id);
    if(query.exec())
    {
        while(query.next())
              {
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
                    /*      ui->lineEdit_matricule_update->setText(qry.value(0).toString());
                          ui->lineEdit_Nom_update->setText(qry.value(1).toString());
                          ui->lineEdit_prenom_update->setText(qry.value(2).toString());
                          ui->lineEdit_mail_update->setText(qry.value(3).toString());
                          ui->lineEdit_gsm_update->setText(qry.value(4).toString());
                          ui->lineEdit_role_update->setText(qry.value(5).toString());
                          ui->lineEdit_salaire_update->setText(qry.value(6).toString());
                          //optionnel quand ti cliques sur le matricule la supprisiion se rempli automatiquement*/
                          ui->lineEdit_del->setText(qry.value(0).toString());
                         }

                     }
    }
}


/*void MainWindow::on_rechercher_2_clicked()
{
    produit p;
        int id_produit;
        id_produit=ui->chercher_id->text().toInt();


       bool test= true;
        if(test==(true))
        {
          ui->tab_produit->setModel(p.rechercher(id_produit));
    }
}

void MainWindow::on_recherche_nom_clicked()
{
    produit p;
        QString nom_pr;
        nom_pr=ui->chercher_nom->text();


       bool test= true;
        if(test==(true))
        {
          ui->tab_produit->setModel(p.rechercher_nom(nom_pr));
    }
}

void MainWindow::on_recherche_prix_clicked()
{
    produit p;
        int prix_uni;
        prix_uni=ui->chercher_prix->text().toInt();


       bool test= true;
        if(test==(true))
        {
          ui->tab_produit->setModel(p.rechercher_prix(prix_uni));
    }
}
*/
void MainWindow::on_recherche_par_reference_2_textChanged(const QString &arg1)
{produit p;
    QString rech=ui->recherche_par_reference_2->text();
            ui->tab_produit->setModel(p.Rechercheproduit(rech));
}

void MainWindow::on_radioButton_clicked()
{
    produit p;
        ui->tab_produit->setModel( p.tri_id());
}

void MainWindow::on_radioButton_2_clicked()
{
    produit p;
        ui->tab_produit->setModel( p.Tri_nom());
}

void MainWindow::on_radioButton_3_clicked()
{
    produit p;
        ui->tab_produit->setModel( p.tri_prix());
}

void MainWindow::on_pushButton_mail_clicked()
{
    Smtp* smtp = new Smtp("mediouni7.dhia@gmail.com","xmanetdhia@2020","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("mediouni7.dhia@gmail.com",ui->comboBox_mail_4->currentText(),ui->subject->text(),ui->msg->toPlainText());

}

void MainWindow::on_pb_tri_id_clicked()
{
    produit p;
        ui->tab_produit->setModel( p.tri_id());

}

void MainWindow::on_pb_tri_nom_clicked()
{
    produit p;
        ui->tab_produit->setModel( p.Tri_nom());
}

void MainWindow::on_pb_tri_prix_clicked()
{
    produit p;
        ui->tab_produit->setModel( p.tri_prix());
}

void MainWindow::on_pb_gotomail_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);

}

/*void MainWindow::on_pb_video_clicked()
{
    player->setVideoOutput(vw);
        player->setMedia(QUrl::fromLocalFile("C:/Downloads/Qtvideo.mp4"));

        vw->setGeometry(100,100,300,400);
        vw->show();

        player->play();
}*/


void MainWindow::on_actionopen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    on_actionstop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionplay_triggered();
}

void MainWindow::on_actionplay_triggered()
{
    player->play();
    ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionpause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("Paused...");
}

void MainWindow::on_actionstop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("Stopped");
}


void MainWindow::on_loadButton_historique_clicked()
{
    produit p;
    ui->tableView_historique->setModel(p.afficher_historique()); //Chef
}

void MainWindow::on_homeButton_recherche_clicked()
{

}
