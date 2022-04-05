#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPainter>
#include <QTimer>
#include <QDateTime>

#include "connection.h"
#include "fournisseur.h"


#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"
#define NAME_RX "([A-Z][a-z]*)([\\s\\\'.][A-Z][a-z]*)*"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);





    /*LOGIN*/
    //Load Images
    QPixmap rajel(":/img/img/Rajel.png");
    int w = ui->Manpic->width();
    int h = ui->Manpic->height();
    ui->Manpic->setPixmap (rajel.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap logo(":/img/img/Logo.png");
    w = ui->logo_sps->width();
    h = ui->logo_sps->height();
    ui->logo_sps->setPixmap (logo.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap background(":/img/img/Background.jpg");
    int x = ui->Background->width();
    int y = ui->Background->height();
    ui->Background->setPixmap (background.scaled(x,y,Qt::KeepAspectRatio));

    //Login's Placeholders
    ui->lineEdit_username->setPlaceholderText("Nom d'utilisateur");
    ui->lineEdit_password->setPlaceholderText("Mot de passe");
    //Icons
    QIcon user(":/img/img/user.png");
    QIcon password(":/img/img/password.png");
    ui->lineEdit_username->addAction(user,QLineEdit::LeadingPosition);
    ui->lineEdit_password->addAction(password,QLineEdit::LeadingPosition);
    //Clear Buttons
    ui->lineEdit_username->setClearButtonEnabled(true);
    ui->lineEdit_password->setClearButtonEnabled(true);



    //CONTROLE DE SAISIE DE LA REFERENCE
    //Chef
    ui->lineEdit_ref->setValidator(new QIntValidator(100,9999999,this)); //Ajout
    ui->lineEdit_reference->setValidator(new QIntValidator(100,9999999,this)); //Modification
    //Simple Emp
    ui->lineEdit_ref_4->setValidator(new QIntValidator(100,9999999,this)); //Ajout
    ui->lineEdit_reference_4->setValidator(new QIntValidator(100,9999999,this)); //Modification



    //CONTROLE DE SAISIE DE NOM DE FOURNISSEUR
    QRegExp rxName(NAME_RX);
    QRegExpValidator *valiName = new QRegExpValidator(rxName, this);
    //Chef
    ui->lineEdit_nom->setValidator(valiName); //Ajout
    ui->lineEdit_nomfour->setValidator(valiName); //Modification
    //Simple Emp
    ui->lineEdit_nom_4->setValidator(valiName); //Ajout
    ui->lineEdit_nomfour_4->setValidator(valiName); //Modification



    //CONTROLE DE SAISIE EMAIL
    QRegExp rxEmail(EMAIL_RX);
    QRegExpValidator *valiEmail = new QRegExpValidator(rxEmail, this);
    //Chef
    ui->lineEdit_mail->setValidator(valiEmail); //Ajout
    ui->lineEdit_email->setValidator(valiEmail); //Modification
    //Simple Emp
    ui->lineEdit_mail_4->setValidator(valiEmail); //Ajout
    ui->lineEdit_email_4->setValidator(valiEmail); //Modification



    //CONTROLE DE SAISIE GSM
    //Chef
    ui->lineEdit_gsm->setValidator(new QIntValidator(100,99999999,this)); //Ajout
    ui->lineEdit_gsmfour->setValidator(new QIntValidator(100,99999999,this)); //Modification
    //Simple Emp
    ui->lineEdit_gsm_4->setValidator(new QIntValidator(100,99999999,this)); //Ajout
    ui->lineEdit_gsmfour_4->setValidator(new QIntValidator(100,99999999,this)); //Modification



}

MainWindow::~MainWindow()
{
    delete ui;
}








/*LOGIN PAGE*/


void MainWindow::on_QuitterButton_clicked()
{
    /*
        void about
        void aboutQt
        StandardButton critical
        StandardButton information
        StandardButton question
        StandardButton warning
    */

    QString quitter=ui->comboBox_3->currentText();

    if (quitter=="Francais")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            QApplication::quit();
        } else
        {
            qDebug() <<"No is clicked";
        }
    }
    else if (quitter=="English")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Are you sure ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            QApplication::quit();
        } else
        {
            qDebug() <<"No is clicked";
        }
    }
    else if (quitter=="Espagnol")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Está usted seguro ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            QApplication::quit();
        } else
        {
            qDebug() <<"No is clicked";
        }
    }

}


int MainWindow::on_LoginButton_clicked()
{
    QString nom_utilisateur = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    int etat=0;


    if (nom_utilisateur == "admin" && password == "admin")
    {
        ui->stackedWidget->setCurrentIndex(1);
        etat=1; //chef
    }
    else if (nom_utilisateur == "simple" && password == "simple")
    {
        ui->stackedWidget->setCurrentIndex(3);
        etat=2; //simple
    }
    else if (nom_utilisateur == "livreur" && password == "livreur")
    {
        ui->stackedWidget->setCurrentIndex(2);
        etat=3; //livreur
    }
    else
    {
        QString conn=ui->comboBox_3->currentText();

        if (conn=="Francais")
        {
            QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"),
                QObject::tr("Le nom d'utilisateur ou le mot de passe que \n"
                            "vous avez saisi(e) n’est pas associé(e) à un compte.\n"
                            "Trouvez votre compte et connectez-vous.\n"), QMessageBox::Cancel);
        }
        else if (conn=="English")
        {
            QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"),
                QObject::tr("The username or password that you \n"
                            "entered is not associated with an account.\n"
                            "Find your account and sign in.\n"), QMessageBox::Cancel);
        }
        else if (conn=="Espagnol")
        {
            QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"),
                QObject::tr("El nombre de usuario o contraseña\n"
                            "que ingresó no está asociado con una cuenta.\n"
                            "Encuentra tu cuenta e inicia sesión.\n"), QMessageBox::Cancel);
        }
    }

    if (nom_utilisateur.isEmpty() || password.isEmpty())
    {
        QString empt=ui->comboBox_3->currentText();

        if (password.isEmpty() && nom_utilisateur.isEmpty())
        {
            if (empt=="Francais")
            {
                QMessageBox::warning(this, tr("Champ vide"),
                        tr("Veuillez saisir votre nom \nd'utilisateur et mot de passe."));
            }
            else if (empt=="English")
            {
                QMessageBox::warning(this, tr("Empty field"),
                        tr("Please enter your \nusername and password."));
            }
            else if (empt=="Espagnol")
            {
                QMessageBox::warning(this, tr("Campo vacío"),
                        tr("Por favor introduzca su nombre \nde usuario y contraseña."));
            }

        }
        else if (nom_utilisateur.isEmpty())
        {
            if (empt=="Francais")
            {
                QMessageBox::warning(this, tr("Champ vide"),
                        tr("Veuillez saisir votre nom d'utilisateur."));
            }
            else if (empt=="English")
            {
                QMessageBox::warning(this, tr("Empty field"),
                        tr("Please enter your username."));
            }
            else if (empt=="Espagnol")
            {
                QMessageBox::warning(this, tr("Campo vacío"),
                        tr("Por favor introduzca su nombre de usuario."));
            }
        }
        else if (password.isEmpty())
        {
            if (empt=="Francais")
            {
                QMessageBox::warning(this, tr("Champ vide"),
                        tr("Veuillez saisir votre mot de passe."));
            }
            else if (empt=="English")
            {
                QMessageBox::warning(this, tr("Empty field"),
                        tr("Please enter your password."));
            }
            else if (empt=="Espagnol")
            {
                QMessageBox::warning(this, tr("Campo vacío"),
                        tr("Por favor introduzca su contraseña."));
            }

        }
    }
    return etat;
}












/*CHEF*/



void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString value=ui->tableView_2->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from fournisseurs where REF_FOUR='"+value+"'");
    if(qry.exec())
             {
                 while(qry.next())
                 {
                  ui->lineEdit_reference->setText(qry.value(0).toString());
                  ui->lineEdit_nomfour->setText(qry.value(1).toString());
                  ui->lineEdit_email->setText(qry.value(2).toString());
                  ui->lineEdit_gsmfour->setText(qry.value(3).toString());
                  ui->lineEdit_ad->setText(qry.value(4).toString());
                  ui->supprimer_par_reference_2->setText(qry.value(0).toString());
                 }

             }
}

void MainWindow::on_ajouterButton_clicked()
{
    QString aj=ui->comboBox_3->currentText();
    //Récupération des données
    int reference=ui->lineEdit_ref->text().toInt();
    QString nom_fourn=ui->lineEdit_nom->text();
    QString mail_fourn=ui->lineEdit_mail->text();
    int gsm_fourn=ui->lineEdit_gsm->text().toInt();
    QString adresse_fourn=ui->lineEdit_adresse->text();

    Fournisseur F(reference,nom_fourn,mail_fourn,gsm_fourn,adresse_fourn);

    bool test=F.ajouter();

    if (test)
    {

        //Refresh (Actualiser)
        ui->tableView_2->setModel(Ftmp.afficher());

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

        ui->lineEdit_ref->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_mail->clear();
        ui->lineEdit_gsm->clear();
        ui->lineEdit_adresse->clear();
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

        ui->lineEdit_ref->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_mail->clear();
        ui->lineEdit_gsm->clear();
        ui->lineEdit_adresse->clear();

    }
}

void MainWindow::on_supprimerButton_2_clicked()
{
    int ref=ui->supprimer_par_reference_2->text().toInt();
    bool test=Ftmp.supprimer(ref);

    if(test)
    {

        //Refresh (Actualiser)
        ui->tableView_2->setModel(Ftmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);

        ui->supprimer_par_reference_2->clear();
        ui->lineEdit_reference->clear();
        ui->lineEdit_nomfour->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_gsmfour->clear();
        ui->lineEdit_ad->clear();
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                QObject::tr("Suppression non effectuée.\n"
                            "La référence n'existe pas"
                            "Click Cancel to exit."),QMessageBox::Cancel);

        ui->supprimer_par_reference_2->clear();
        ui->lineEdit_reference->clear();
        ui->lineEdit_nomfour->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_gsmfour->clear();
        ui->lineEdit_ad->clear();
    }
}

void MainWindow::on_modifierButton_clicked()
{
    Fournisseur f;
    f.setRef(ui->lineEdit_reference->text().toInt());
    f.setNom_fourn(ui->lineEdit_nomfour->text());
    f.setMail_fourn(ui->lineEdit_email->text());
    f.setGSM(ui->lineEdit_gsmfour->text().toInt());
    f.setAdresse_fourn(ui->lineEdit_ad->text());

   bool check=f.modifier();

    if (check)
    {
        //Refresh (Actualiser)
        ui->tableView_2->setModel(Ftmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("Modification"),
            QObject::tr("Modification avec succés.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_reference->clear();
        ui->lineEdit_nomfour->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_gsmfour->clear();
        ui->lineEdit_ad->clear();

    }
    else{
            QMessageBox::information(nullptr, QObject::tr("Modification"),
            QObject::tr("Modification échouée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

            ui->lineEdit_reference->clear();
            ui->lineEdit_nomfour->clear();
            ui->lineEdit_email->clear();
            ui->lineEdit_gsmfour->clear();
            ui->lineEdit_ad->clear();

        }
}

void MainWindow::on_homeButton_ajouter_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_modifier_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    QString quitter2=ui->comboBox_3->currentText();

    if (quitter2=="Francais")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            ui->stackedWidget->setCurrentIndex(0);
        } else
        {
            qDebug() <<"No is clicked";
        }
    }
    else if (quitter2=="English")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Are you sure ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            ui->stackedWidget->setCurrentIndex(0);
        } else
        {
            qDebug() <<"No is clicked";
        }
    }
    else if (quitter2=="Espagnol")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Está usted seguro ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            ui->stackedWidget->setCurrentIndex(0);
        } else
        {
            qDebug() <<"No is clicked";
        }
    }
}

void MainWindow::on_clButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_prodButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_cmdButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_livrButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void MainWindow::on_empButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
}

void MainWindow::on_fournisseurButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
}

void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_rechercher_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_LoadButton_clicked()
{
    ui->tableView_2->setModel(Ftmp.afficher()); //Chef
}

void MainWindow::on_LoadButton_Historique_clicked()
{
    ui->tableView_historique->setModel(Ftmp.afficher_historique()); //Chef
}


void MainWindow::on_recherche_par_reference_2_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_par_reference_2->text();
            ui->tableView_2->setModel(Ftmp.Recherchefournisseur(rech));
}

//Trie
void MainWindow::on_trier_button_clicked()
{
    QString tri=ui->comboBox->currentText();

    if (tri=="Référence")
    {
        ui->tableView_2->setModel(Ftmp.trier_ref());
    }
    else if (tri=="Nom")
    {
        ui->tableView_2->setModel(Ftmp.trier_nom());
    }
    else if (tri=="Email")
    {
        ui->tableView_2->setModel(Ftmp.trier_email());
    }
}

//PDF
void MainWindow::on_PDFButton_clicked()
{
    QString ref_pdf=ui->recherche_par_reference_2->text();

    if (ref_pdf.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("PDF File Export"),
        QObject::tr("Pas de référence saisie. \nVeuillez saisir une référence.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        qDebug()<<dir;
        QPdfWriter pdf(dir+"/Contrat.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1200,1200,"Contrat de prestation de service");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawPixmap(QRect(4400,1200,918,1027),QPixmap(":/img/img/Logo.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.setPen(Qt::blue);
        painter.drawText(300,3300,"Référence");
        painter.drawText(2300,3300,"Nom");
        painter.drawText(4300,3300,"Email");
        painter.drawText(6300,3300,"GSM");
        painter.drawText(8300,3300,"Adresse");

        QSqlQuery query;
        query.prepare("SELECT * FROM FOURNISSEURS WHERE REF_FOUR='"+ref_pdf+"'");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(2300,i,query.value(1).toString());
            painter.drawText(4300,i,query.value(2).toString());
            painter.drawText(6300,i,query.value(3).toString());
            painter.drawText(8300,i,query.value(4).toString());
            i = i +500;
        }
        painter.setFont(QFont("Arial", 9));
        painter.setPen(Qt::blue);
        painter.drawText(300,i+200,"Entre les soussignés :");
        painter.drawText(300,i+500,"La société au capital de OO USD, dont le siège social est enregistrée au Registre du Commerce et des Sociétés");
        painter.drawText(300,i+800,"sous le numéro OO, Représentée par M. OO ci après désignée Le Client d une part");
        painter.drawText(300,i+1100,"et La société OO, dont le siège social est enregistrée au Registre du Commerce sous le numéro OO, représentée par M. OO,");
        painter.drawText(300,i+1400,"ci après dénommée le Prestataire de services ou le Prestataire,");
        painter.drawText(300,i+1700,"d autre part il a été convenu ce qui suit :");



        int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
            painter.end();
        }
        else
        {
            painter.end();
        }

        QSqlQuery qry;
        QDateTime dateTime=QDateTime::currentDateTime();

        QString date=dateTime.toString();

        qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Generation de PDF',:dateTime)");
        qry.bindValue(":dateTime",dateTime);

        qry.exec();

        ui->recherche_par_reference_2->clear();
    }

}


//TRADUCTION
void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
   if(index == 0) //fr
   {
       //LOGIN
       ui->langue->setText("Langue :");
       ui->nom_utilisateur_3->setText("Nom utilisateur : ");
       ui->label_35->setText("Mot de passe :");
       ui->LoginButton->setText("Se connecter");
       ui->QuitterButton->setText("Quitter");

       //HOME
       /*Chef*/
       ui->label->setText("Bienvenue, vous êtes le chef !!");
       ui->prodButton->setText("Produits");
       ui->livrButton->setText("Livraisons");
       ui->empButton->setText("Employées");
       ui->fournisseurButton->setText("Fournisseurs");
       ui->cmdButton->setText("Commandes");
       ui->clButton->setText("Clients");
       ui->pushButton_12->setText("Déconnecter");

       /*Livreur*/
       ui->label_33->setText("Bienvenue, vous êtes le livreur !!");
       ui->prodButton_3->setText("Produits");
       ui->livrButton_3->setText("Livraisons");
       ui->empButton_3->setText("Employées");
       ui->fournisseurButton_3->setText("Fournisseurs");
       ui->cmdButton_3->setText("Commandes");
       ui->clButton_3->setText("Clients");
       ui->pushButton_14->setText("Déconnecter");


       //FOURNISSEURS

       /*Chef*/
       ui->Lesfournisseurs->setText("Les fournisseurs");
       //Insertion
       ui->textajoutezfournisseur->setText("Ajoutez un fournisseur :");
       ui->label_9->setText("Référence :");//ref
       ui->label_10->setText("Nom Fournisseur :");//nom
       ui->label_11->setText("GSM Fournisseur :");//gsm
       ui->label_12->setText("Mail Fournisseur :");//mail
       ui->label_17->setText("Adresse Fournisseur :");//adresse
       ui->ajouterButton->setText("Ajouter");
       ui->label_13->setText("* La référence est un nombre positive.");
       ui->label_8->setText("* La 1ére lettre du nom de fournissuer doit être en majuscule.");
       ui->label_14->setText("* Le GSM du fournisseur est nombre positive qui contient que 8 chiffres.");
       ui->label_15->setText("* L'email du fournisseur obéit à sa forme générale.");
       ui->label_16->setText("* L'adresse du fournisseur peut contient des chiffres, des lettres et de symboles.");
       ui->homeButton_ajouter->setText("Menu");
       //Gestion
       ui->nb->setText("NB: Double click sur la référence du fournisseur à modifier où supprimer ");
       ui->saisir_r->setText("Saisir la référence du fournisseur à chercher :");
       ui->PDFButton->setText("Génération PDF");
       ui->LoadButton->setText("Actualiser");
       ui->label_ref->setText("Référence :");
       ui->label_nom->setText("Nom :");
       ui->label_mail->setText("Email :");
       ui->label_gsm->setText("GSM :");
       ui->label_adresse->setText("Adresse :");
       ui->modifierButton->setText("Modifier");
       ui->label_ref_2->setText("Référence à supprimer :");
       ui->supprimerButton_2->setText("Supprimer");
       ui->trier_button->setText("Trier");
       ui->homeButton_modifier->setText("Menu");
       //Historique
       ui->homeButton_rechercher->setText("Menu");
       ui->LoadButton_Historique->setText("Actualiser");


   }
   if(index == 1) //en
   {
       //Login
       ui->langue->setText("Language :");
       ui->nom_utilisateur_3->setText("Username : ");
       ui->label_35->setText("Password :");
       ui->LoginButton->setText("Login");
       ui->QuitterButton->setText("Quit");

       //Home
       /*Chef*/
       ui->label->setText("Welcome, you're the chief !!");
       ui->prodButton->setText("Products");
       ui->livrButton->setText("Deliveries");
       ui->empButton->setText("Employees");
       ui->fournisseurButton->setText("Suppliers");
       ui->cmdButton->setText("Orders");
       ui->clButton->setText("Clients");
       ui->pushButton_12->setText("Disconnect");

       /*Livreur*/
       ui->label_33->setText("");
       ui->prodButton_3->setText("");
       ui->livrButton_3->setText("");
       ui->empButton_3->setText("");
       ui->fournisseurButton_3->setText("");
       ui->cmdButton_3->setText("");
       ui->clButton_3->setText("");
       ui->pushButton_14->setText("Disconnect");

       //Chef Fournisseurs
       ui->Lesfournisseurs->setText("Suppliers");

       //Chef Fournisseurs Insertion
       ui->textajoutezfournisseur->setText("Add a supplier :");
       ui->label_9->setText("Reference :");//ref
       ui->label_10->setText("Name of supplier :");//nom
       ui->label_11->setText("GSM of supplier :");//gsm
       ui->label_12->setText("Email of supplier :");//mail
       ui->label_17->setText("Addresse of supplier :");//adresse
       ui->ajouterButton->setText("Add");
       ui->label_13->setText("* The reference is a positive number.");
       ui->label_8->setText("* The 1st letter of the supplier's name must be capitalized.");
       ui->label_14->setText("* The provider's GSM is a positive number which contains only 8 digits.");
       ui->label_15->setText("* The supplier's email follows its general form.");
       ui->label_16->setText("* The supplier's addresse contains numbers, lettres and symboles.");
       ui->homeButton_ajouter->setText("Home");

       //Chef Fournisseurs Gestion
       ui->nb->setText("Note: Double click on the supplier's reference to modify or delete");
       ui->saisir_r->setText("Enter the reference of the supplier to be searched:");
       ui->PDFButton->setText("Generate PDF");
       ui->LoadButton->setText("Load List");
       ui->label_ref->setText("Reference :");
       ui->label_nom->setText("Name of supplier :");
       ui->label_mail->setText("Email of supplier :");
       ui->label_gsm->setText("GSM of supplier :");
       ui->label_adresse->setText("Addresse of supplier :");
       ui->modifierButton->setText("Modify");
       ui->label_ref_2->setText("Reference to delete:");
       ui->supprimerButton_2->setText("Delete");
       ui->trier_button->setText("Sort");
       ui->homeButton_modifier->setText("Home");

       //Chef Fournisseurs Historique
       ui->homeButton_rechercher->setText("Home");
       ui->LoadButton_Historique->setText("Load");
   }
   if(index == 2) //esp
   {
       //Login
       ui->langue->setText("Lingua :");
       ui->nom_utilisateur_3->setText("Nombre usuario : ");
       ui->label_35->setText("Clave :");
       ui->LoginButton->setText("Acceso");
       ui->QuitterButton->setText("Salir");

       //Chef Home
       ui->label->setText("Bienvenido, tu eres el chef !!");
       ui->prodButton->setText("Productos");
       ui->livrButton->setText("Entregas");
       ui->empButton->setText("Empleados");
       ui->fournisseurButton->setText("Proveedores");
       ui->cmdButton->setText("Pedidos");
       ui->clButton->setText("Clientela");
       ui->pushButton_12->setText("Desconectar");

       //Chef Fournisseurs
       ui->Lesfournisseurs->setText("Proveedores");

       //Chef Fournisseurs Insertion
       ui->textajoutezfournisseur->setText("Añadir un proveedor :");
       ui->label_9->setText("Referencia :");//ref
       ui->label_10->setText("Nombre del proveedor :");//nom
       ui->label_11->setText("GSM del proveedor :");//gsm
       ui->label_12->setText("Email del proveedor :");//mail
       ui->label_17->setText("Dirección del proveedor :");//adresse
       ui->ajouterButton->setText("Agregar");
       ui->label_13->setText("* La referencia es un número positivo.");
       ui->label_8->setText("* La primera letra del nombre del proveedor debe estar en mayúscula.");
       ui->label_14->setText("* El GSM del proveedor es un número positivo que contiene solo 8 dígitos.");
       ui->label_15->setText("* El correo electrónico del proveedor sigue su forma general.");
       ui->label_16->setText("* La dirección del proveedor puede contener números, letras y símbolos.");
       ui->homeButton_ajouter->setText("Menù");

       //Chef Fournisseurs Gestion
       ui->nb->setText("Nota: Haga doble clic en la referencia del proveedor para modificar o eliminar");
       ui->saisir_r->setText("Introduzca la referencia del proveedor a buscar:");
       ui->PDFButton->setText("Generación de PDF");
       ui->LoadButton->setText("Actualizar");
       ui->label_ref->setText("Referencia:");
       ui->label_nom->setText("Nombre:");
       ui->label_mail->setText("Email:");
       ui->label_gsm->setText("GSM:");
       ui->label_adresse->setText("Dirección:");
       ui->modifierButton->setText("Editar");
       ui->label_ref_2->setText("Referencia a eliminar:");
       ui->supprimerButton_2->setText("Retirar");
       ui->trier_button->setText("Ordenar");
       ui->homeButton_modifier->setText("Menù");

       //Chef Fournisseurs Historique
       ui->homeButton_rechercher->setText("Menù");
       ui->LoadButton_Historique->setText("Actualizar");


   }
}









/*LIVREUR*/

void MainWindow::on_livrButton_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}

void MainWindow::on_homeButton_14_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        ui->stackedWidget->setCurrentIndex(0);
    } else
    {
        qDebug() <<"No is clicked";
    }
}

void MainWindow::on_fournisseurButton_3_clicked()
{
    QMessageBox::critical(nullptr, QObject::tr("Gestion des fournisseurs"),
    QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_empButton_3_clicked()
{
    QMessageBox::critical(nullptr, QObject::tr("Gestion des employes"),
    QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_clButton_3_clicked()
{
    QMessageBox::critical(nullptr, QObject::tr("Gestion des clients"),
    QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_prodButton_3_clicked()
{
    QMessageBox::critical(nullptr, QObject::tr("Gestion des produits"),
    QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_cmdButton_3_clicked()
{
    QMessageBox::critical(nullptr, QObject::tr("Gestion des commandes"),
    QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}













/*SIMPLE EMPLOYE*/


void MainWindow::on_clButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_prodButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

void MainWindow::on_cmdButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(3);
}

void MainWindow::on_livrButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(4);
}

void MainWindow::on_empButton_4_clicked()
{
    QMessageBox::critical(nullptr, QObject::tr("Gestion des employes"),
    QObject::tr("Vous êtes un simple employé. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_fournisseurButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(6);
}

void MainWindow::on_pushButton_15_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        ui->stackedWidget->setCurrentIndex(0);
    } else
    {
        qDebug() <<"No is clicked";
    }
}

void MainWindow::on_homeButton_16_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_17_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_18_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_19_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_ajouter_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_homeButton_modifier_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_ajouterButton_4_clicked()
{
    //Récupération des données
    int reference=ui->lineEdit_ref_4->text().toInt();
    QString nom_fourn=ui->lineEdit_nom_4->text();
    QString mail_fourn=ui->lineEdit_mail_4->text();
    int gsm_fourn=ui->lineEdit_gsm_4->text().toInt();
    QString adresse_fourn=ui->lineEdit_adresse_4->text();

    Fournisseur F(reference,nom_fourn,mail_fourn,gsm_fourn,adresse_fourn);

    bool test=F.ajouter();

    if (test)
    {

        //Refresh (Actualiser)
        ui->tableView_9->setModel(Ftmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);

        ui->lineEdit_ref_4->clear();
        ui->lineEdit_nom_4->clear();
        ui->lineEdit_mail_4->clear();
        ui->lineEdit_gsm_4->clear();
        ui->lineEdit_adresse_4->clear();

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Warning"),
                              QObject::tr("Ajout non effectué\n"
                                          "La référence existe déjà"
                                          "Click Cancel to exit."),QMessageBox::Cancel);

        ui->lineEdit_ref_4->clear();
        ui->lineEdit_nom_4->clear();
        ui->lineEdit_mail_4->clear();
        ui->lineEdit_gsm_4->clear();
        ui->lineEdit_adresse_4->clear();

    }
}

void MainWindow::on_supprimerButton_5_clicked()
{
    int ref=ui->supprimer_par_reference_5->text().toInt();
    bool test=Ftmp.supprimer(ref);

    if(test)
    {

        //Refresh (Actualiser)
        ui->tableView_9->setModel(Ftmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);

        ui->supprimer_par_reference_5->clear();
        ui->lineEdit_reference_4->clear();
        ui->lineEdit_nomfour_4->clear();
        ui->lineEdit_email_4->clear();
        ui->lineEdit_gsmfour_4->clear();
        ui->lineEdit_ad_4->clear();
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                QObject::tr("Suppression non effectuée.\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);

        ui->supprimer_par_reference_5->clear();
        ui->lineEdit_reference_4->clear();
        ui->lineEdit_nomfour_4->clear();
        ui->lineEdit_email_4->clear();
        ui->lineEdit_gsmfour_4->clear();
        ui->lineEdit_ad_4->clear();
    }
}

void MainWindow::on_tableView_9_activated(const QModelIndex &index)
{
    QString value=ui->tableView_9->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("select * from fournisseurs where REF_FOUR='"+value+"'");
    if(qry.exec())
             {
                 while(qry.next())
                 {
                  ui->lineEdit_reference_4->setText(qry.value(0).toString());
                  ui->lineEdit_nomfour_4->setText(qry.value(1).toString());
                  ui->lineEdit_email_4->setText(qry.value(2).toString());
                  ui->lineEdit_gsmfour_4->setText(qry.value(3).toString());
                  ui->lineEdit_ad_4->setText(qry.value(4).toString());
                  ui->supprimer_par_reference_5->setText(qry.value(0).toString());
                 }
             }
}

void MainWindow::on_modifierButton_4_clicked()
{
    Fournisseur f;
    f.setRef(ui->lineEdit_reference_4->text().toInt());
    f.setNom_fourn(ui->lineEdit_nomfour_4->text());
    f.setMail_fourn(ui->lineEdit_email_4->text());
    f.setGSM(ui->lineEdit_gsmfour_4->text().toInt());
    f.setAdresse_fourn(ui->lineEdit_ad_4->text());

   bool check=f.modifier();

    if (check)
    {
        //Refresh (Actualiser)
        ui->tableView_9->setModel(Ftmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("Modification"),
            QObject::tr("Modification avec succés.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_reference_4->clear();
        ui->lineEdit_nomfour_4->clear();
        ui->lineEdit_email_4->clear();
        ui->lineEdit_gsmfour_4->clear();
        ui->lineEdit_ad_4->clear();

    }
    else{
            QMessageBox::information(nullptr, QObject::tr("Modification"),
            QObject::tr("Modification échouée.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

            ui->lineEdit_reference_4->clear();
            ui->lineEdit_nomfour_4->clear();
            ui->lineEdit_email_4->clear();
            ui->lineEdit_gsmfour_4->clear();
            ui->lineEdit_ad_4->clear();
        }
}


void MainWindow::on_LoadButton_2_clicked()
{
    ui->tableView_9->setModel(Ftmp.afficher());
}

void MainWindow::on_TrierButton_clicked()
{
    QString tri=ui->comboBox_2->currentText();

    if (tri=="Référence")
    {
        ui->tableView_9->setModel(Ftmp.trier_ref());
    }
    else if (tri=="Nom")
    {
        ui->tableView_9->setModel(Ftmp.trier_nom());
    }
    else if (tri=="Email")
    {
        ui->tableView_9->setModel(Ftmp.trier_email());
    }
}



void MainWindow::on_PDFButton_4_clicked()
{
    QString ref_pdf=ui->recherche_par_reference_4->text();

    if (ref_pdf.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("PDF File Export"),
        QObject::tr("Pas de référence saisie. \nVeuillez saisir une référence.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        qDebug()<<dir;
        QPdfWriter pdf(dir+"/Contrat.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1200,1200,"Contrat de prestation de service");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawPixmap(QRect(4400,1200,918,1027),QPixmap(":/img/img/Logo.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.setPen(Qt::blue);
        painter.drawText(300,3300,"Référence");
        painter.drawText(2300,3300,"Nom");
        painter.drawText(4300,3300,"Email");
        painter.drawText(6300,3300,"GSM");
        painter.drawText(8300,3300,"Adresse");

        QSqlQuery query;
        query.prepare("SELECT * FROM FOURNISSEURS WHERE REF_FOUR='"+ref_pdf+"'");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(2300,i,query.value(1).toString());
            painter.drawText(4300,i,query.value(2).toString());
            painter.drawText(6300,i,query.value(3).toString());
            painter.drawText(8300,i,query.value(4).toString());
            i = i +500;
        }
        painter.setFont(QFont("Arial", 9));
        painter.setPen(Qt::blue);
        painter.drawText(300,i+200,"Entre les soussignés :");
        painter.drawText(300,i+500,"La société au capital de OO USD, dont le siège social est enregistrée au Registre du Commerce et des Sociétés");
        painter.drawText(300,i+800,"sous le numéro OO, Représentée par M. OO ci après désignée Le Client d une part");
        painter.drawText(300,i+1100,"et La société OO, dont le siège social est enregistrée au Registre du Commerce sous le numéro OO, représentée par M. OO,");
        painter.drawText(300,i+1400,"ci après dénommée le Prestataire de services ou le Prestataire,");
        painter.drawText(300,i+1700,"d autre part il a été convenu ce qui suit :");



        int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
            painter.end();
        }
        else
        {
            painter.end();
        }

        ui->recherche_par_reference_4->clear();
    }
}






