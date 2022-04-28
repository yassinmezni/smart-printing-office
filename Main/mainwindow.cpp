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
#include <QLabel>
#include <QPieSlice>
#include <QPieSeries>
#include <QDebug>
#include <QComboBox>
#include <QPieSlice>
#include <QPieSeries>
#include <QMediaPlayer>
#include <QTimer>

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


#include "connection.h"
#include "arduino.h"
#include "fournisseur.h"
#include "produit.h"
#include "employee.h"
#include "qrcode.h"
#include "commande.h"
#include "qcustomplot.h"



#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"

#define NAME_RX "([A-Z][a-z]*)([\\s\\\'.][A-Z][a-z]*)*"

#define DATE_RX "(((0[1-9])|([12][0-9])|(3[01]))-(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)-((19[89][0123456789])|(20[01][0123456789])|(20[2][012])))"





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
    QIcon pass(":/img/img/password.png");
    ui->lineEdit_username->addAction(user,QLineEdit::LeadingPosition);
    ui->lineEdit_password->addAction(pass,QLineEdit::LeadingPosition);
    //Clear Buttons
    ui->lineEdit_username->setClearButtonEnabled(true);
    ui->lineEdit_password->setClearButtonEnabled(true);


    /*FOURNISSEURS*/
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



    /*ARDUINO*/
    int ret=A.connect_arduino(); //lancer la connexion à Arduino
    switch (ret)
    {
    case (0):
        qDebug() << "Arduino is available and connected to :" << A.getarduino_port_name();
        break;
    case (1):
        qDebug() << "Arduino is available but not connected to :" << A.getarduino_port_name();
        break;
    case (-1):
        qDebug() << "Arduino is not available";
        break;
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    //permet de lancer le slot update_label suite à la reception du signal radyRead (réception des données)



    /*PRODUITS*/
    ui->lineEdit_id->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_id_2->setValidator(new QIntValidator(0, 999999, this));
    ui->update_id->setValidator(new QIntValidator(0, 999999, this));
    ui->update_id_2->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_del->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_del_2->setValidator(new QIntValidator(0, 999999, this));

    ui->lineEdit_stock->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_stock_2->setValidator(new QIntValidator(0, 999999, this));
    ui->update_stock->setValidator(new QIntValidator(0, 999999, this));
    ui->update_stock_2->setValidator(new QIntValidator(0, 999999, this));

    ui->lineEdit_prix->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_prix_2->setValidator(new QIntValidator(0, 999999, this));
    ui->update_prix->setValidator(new QIntValidator(0, 999999, this));
    ui->update_prix_2->setValidator(new QIntValidator(0, 999999, this));

    ui->tab_produit->setModel(b.afficher());
    ui->comboBox_5->setModel(b.afficher_id());
    //ui->comboBox_4->setModel(b.combobox_fk());
    /*ui->comboBox_6->setModel(b.combobox_fk());
    ui->comboBox_mail_4->setModel(b.afficher_email());*/
    QRegularExpression rx("\\b[A-Z ._%+-]+@[A-Z .-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_nom_2->setValidator(new QRegularExpressionValidator(rx, this));
    ui->lineEdit_nom_3->setValidator(new QRegularExpressionValidator(rx, this));
    ui->update_nom->setValidator(new QRegularExpressionValidator(rx, this));
    ui->update_nom_2->setValidator(new QRegularExpressionValidator(rx, this));

    ui->lineEdit_viedo->setValidator(new QRegularExpressionValidator(rx, this));
    ui->lineEdit_viedo_2->setValidator(new QRegularExpressionValidator(rx, this));
    ui->update_video->setValidator(new QRegularExpressionValidator(rx, this));
    ui->update_video_2->setValidator(new QRegularExpressionValidator(rx, this));

    //Vidéo
    player = new QMediaPlayer(this);
    vw = new QVideoWidget(ui->test2);
    player->setVideoOutput(vw);
    vw->setGeometry(0,0,480,280);
    QTimer::singleShot(60000,vw,SLOT(close()));

    player->play();
    slider = new QSlider(this);
    bar = new QProgressBar(this);
    slider->setOrientation(Qt::Horizontal);
    ui->statusbar->addPermanentWidget(slider);
    ui->statusbar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

    /*Video2*/
    /*p = new QMediaPlayer(this);
    v = new QVideoWidget(ui->test1);
    p->setVideoOutput(v);
    v->setGeometry(0,0,480,280);
    QTimer::singleShot(60000,v,SLOT(close()));

    p->play();
    slider2 = new QSlider(this);
    bar2 = new QProgressBar(this);
    slider2->setOrientation(Qt::Horizontal);
    ui->statusbar->addPermanentWidget(slider2);
    ui->statusbar->addPermanentWidget(bar2);

    connect(p,&QMediaPlayer::durationChanged,slider2,&QSlider::setMaximum);
    connect(p,&QMediaPlayer::positionChanged,slider2,&QSlider::setValue);
    connect(slider2,&QSlider::sliderMoved,p,&QMediaPlayer::setPosition);

    connect(p,&QMediaPlayer::durationChanged,bar2,&QProgressBar::setMaximum);
    connect(p,&QMediaPlayer::positionChanged,bar2,&QProgressBar::setValue);*/




    /*CLIENTS*/

    ui->le_cin_3->setValidator(new QIntValidator(0,9999,this));
    ui->le_cin_4->setValidator(new QIntValidator(0,9999,this));
    ui->le_cin_sup_2->setValidator(new QIntValidator(0,9999,this));
    ui->le_cin_5->setValidator(new QIntValidator(0,9999,this));
    ui->le_cin_6->setValidator(new QIntValidator(0,9999,this));
    ui->le_cin_sup_3->setValidator(new QIntValidator(0,9999,this));

    ui->le_nom_3->setValidator(new QRegularExpressionValidator(rx, this));
    ui->le_nom_4->setValidator(new QRegularExpressionValidator(rx, this));
    ui->le_nom_5->setValidator(new QRegularExpressionValidator(rx, this));
    ui->le_nom_6->setValidator(new QRegularExpressionValidator(rx, this));

    ui->le_prenom_3->setValidator(new QRegularExpressionValidator(rx, this));
    ui->le_prenom_4->setValidator(new QRegularExpressionValidator(rx, this));
    ui->le_prenom_5->setValidator(new QRegularExpressionValidator(rx, this));
    ui->le_prenom_6->setValidator(new QRegularExpressionValidator(rx, this));

    ui->l_adresse_3->setValidator(new QRegularExpressionValidator(rx, this));
    ui->l_adresse_4->setValidator(new QRegularExpressionValidator(rx, this));
    ui->l_adresse_5->setValidator(new QRegularExpressionValidator(rx, this));
    ui->l_adresse_6->setValidator(new QRegularExpressionValidator(rx, this));

    ui->le_num_3->setValidator(new QIntValidator(0,9999,this));
    ui->le_num_4->setValidator(new QIntValidator(0,9999,this));
    ui->le_num_5->setValidator(new QIntValidator(0,9999,this));
    ui->le_num_6->setValidator(new QIntValidator(0,9999,this));

    ui->le_mail_3->setValidator(valiEmail);
    ui->le_mail_4->setValidator(valiEmail);
    ui->le_mail_5->setValidator(valiEmail);
    ui->le_mail_6->setValidator(valiEmail);


    ui->table_client_2->setModel(c.afficher());


    /*EMPLOYEE*/
    //*********CAMERA************************************
    mCamera = new QCamera(this);
    mCameraViewfinder= new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera , this);
    mlayout = new QVBoxLayout;
    mOptionsMenu= new QMenu("options",this);
    mEncenderAction= new QAction("Ouvrir la camera",this);
    mApagarAction= new QAction("stoper",this);
    mcapturerAction=new QAction("Capturer",this);
    mOptionsMenu->addActions({mEncenderAction,mApagarAction,mcapturerAction});
    mCamera->setViewfinder(mCameraViewfinder);
    ui->options_3->setMenu(mOptionsMenu);
    mlayout->addWidget(mCameraViewfinder);
    mlayout->setMargin(0);
    ui->scrollArea_3->setLayout(mlayout);
    connect(mEncenderAction, &QAction::triggered ,[&](){mCamera->start();});

    connect(mApagarAction,&QAction::triggered,[&](){mCamera->stop();});

    connect(mcapturerAction,&QAction::triggered,[&]()
    {
        auto filename = QFileDialog:: getSaveFileName(this,"capturar","/",
                                                            "imagen (.jpg;.jpeg)");
        if(filename.isEmpty())
        {
            return;
        }
        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });

    //Controle Saisie Mail
    ui->lineEdit_mail_5->setValidator(valiEmail);
    ui->lineEdit_matricule_3->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_GSM_3->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_Salaire_3->setValidator(new QIntValidator (0,99999999,this));
    ui->tab_employee_2->setModel(E.afficher());


    /*LIVRAISONS*/
    ui->table_livraison->setModel(L.afficher());
    ui->le_id_3->setValidator(new QIntValidator (0,99999999,this));
    ui->le_id_2->setValidator(new QIntValidator (0,99999999,this));
    ui->le_id_4->setValidator(new QIntValidator (0,99999999,this));
    ui->le_id_9->setValidator(new QIntValidator (0,99999999,this));
    ui->le_id_sup_3->setValidator(new QIntValidator (0,99999999,this));
    ui->le_id_sup_2->setValidator(new QIntValidator (0,99999999,this));



    ui->le_frais_2->setValidator(new QIntValidator (0,99999999,this));
    ui->le_frais_3->setValidator(new QIntValidator (0,99999999,this));
    ui->le_frais_4->setValidator(new QIntValidator (0,99999999,this));
    ui->le_frais_5->setValidator(new QIntValidator (0,99999999,this));


    ui->l_adress_2->setValidator(new QRegularExpressionValidator(rx, this));
    ui->l_adress_3->setValidator(new QRegularExpressionValidator(rx, this));
    ui->l_adress_4->setValidator(new QRegularExpressionValidator(rx, this));
    ui->l_adress_5->setValidator(new QRegularExpressionValidator(rx, this));


    QRegExp dtName(DATE_RX);
    QRegExpValidator *valiDate = new QRegExpValidator(dtName, this);
    ui->la_date_3->setValidator(valiDate);
    ui->la_date_2->setValidator(valiDate);
    ui->la_date_4->setValidator(valiDate);
    ui->la_date_5->setValidator(valiDate);



    /*COMMANDES*/
    ui->tableView_aff_2->setModel(Ctmp.afficher());
    ui->le_id_5->setValidator(new QIntValidator(0, 999999, this));
    ui->le_id_6->setValidator(new QIntValidator(0, 999999, this));
    ui->le_id_7->setValidator(new QIntValidator(0, 999999, this));
    ui->le_id_8->setValidator(new QIntValidator(0, 999999, this));
    ui->supprimer_id_2->setValidator(new QIntValidator(0, 999999, this));
    ui->supprimer_id_3->setValidator(new QIntValidator(0, 999999, this));

    ui->le_prix_3->setValidator(new QIntValidator(0, 999999, this));
    ui->le_prix_4->setValidator(new QIntValidator(0, 999999, this));
    ui->le_prix_5->setValidator(new QIntValidator(0, 999999, this));
    ui->le_prix_6->setValidator(new QIntValidator(0, 999999, this));

    ui->le_DATE_2->setValidator(valiDate);
    ui->le_DATE_5->setValidator(valiDate);
    ui->le_DATE_3->setValidator(valiDate);
    ui->le_DATE_6->setValidator(valiDate);

    ui->le_Quantite_2->setValidator(new QIntValidator(0, 999999, this));
    ui->le_Quantite_5->setValidator(new QIntValidator(0, 999999, this));
    ui->le_Quantite_3->setValidator(new QIntValidator(0, 999999, this));
    ui->le_Quantite_6->setValidator(new QIntValidator(0, 999999, this));

    ui->find_4->setValidator(new QIntValidator(0, 999999, this));
    ui->find_5->setValidator(new QIntValidator(0, 999999, this));
    ui->find_6->setValidator(new QIntValidator(0, 999999, this));
    ui->find_7->setValidator(new QIntValidator(0, 999999, this));




}

MainWindow::~MainWindow()
{
    delete ui;
}





int etat=0;
/*ARDUINO*/

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    //ui->test->setText(data);
    QString total;
    QString total2;
    QString space;
    const char* send;

    QString s1="s";
    QString s2="1";
    QString s3="0";

    const char* c1=s1.toStdString().c_str();
    const char* c2=s2.toStdString().c_str();
    const char* c3=s3.toStdString().c_str();

    if(data.contains(c1))
    {
        qDebug() << "hello";
        QSqlQuery qry;
        qry.prepare("select * from parking");
        qry.exec();
        qry.next();
        total=qry.value(0).toString();
        qDebug() << total;
        space=qry.value(1).toString();
        total2=total+space; //

        send=total2.toStdString().c_str();
        qDebug() << send;
        A.write_to_arduino(send);
    }
    else if (data.contains(c3))
    {
         qDebug() << "Sakker lbeb";
         A.write_to_arduino("11111");
         if (etat==0)
         {
            etat=2;
         }
         if (etat==1)
         {
            etat=0;
         }
    }
    else if (data.contains(c2))
    {
        qDebug() << "Hell lbeb";
        A.write_to_arduino("1111");
        if (etat==0)
        {
            etat=1;
        }
        if (etat==2)
        {
            etat=0;
        }
    }

    if (etat==0)
    {
        ui->test->setText("fermé");
    }
    else if ((etat==1)||(etat==2))
    {
        ui->test->setText("ouvert");
    }
}

void MainWindow::on_Button_clicked()
{
    qDebug() << A.write_to_arduino("11111");
    if (etat==0)
    {
        etat=1;
    }
    if (etat==2)
    {
        etat=0;
    }

    if (etat==0)
    {
        ui->test->setText("fermé");
    }
    else if ((etat==1)||(etat==2))
    {
        ui->test->setText("ouvert");
    }
}

void MainWindow::on_CloseButton_clicked()
{
    qDebug() << A.write_to_arduino("1111");
    if (etat==0)
    {
        etat=2;
    }
    if (etat==1)
    {
        etat=0;
    }


    if (etat==0)
    {
        ui->test->setText("fermé");
    }
    else if ((etat==1)||(etat==2))
    {
        ui->test->setText("ouvert");
    }

}






//CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF * CHEF



/*chef->home*/

//Cliquer sur le bouton chef->home->fournisseur->Deconnecter
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

//Cliquer sur le bouton chef->home->clients
void MainWindow::on_clButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

//Cliquer sur le bouton chef->home->produits
void MainWindow::on_prodButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

//Cliquer sur le bouton chef->home->commandes
void MainWindow::on_cmdButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

//Cliquer sur le bouton chef->home->livraisons
void MainWindow::on_livrButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

//Cliquer sur le bouton chef->home->employees
void MainWindow::on_empButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
}

//Cliquer sur le bouton chef->home->fournisseurs
void MainWindow::on_fournisseurButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
}



/*FOURNISSEURS*/
/*Les fonctions de base dans chef->fournisseurs*/

//Cliquer sur la reference d'un fournisseur dans le tabView
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

//Cliquer sur le bouton AJOUTER
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
    }
}

//Cliquer sur le bouton fournisseur->ajouter->home
void MainWindow::on_homeButton_ajouter_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

//Cliquer sur le bouton SUPPRIMER
void MainWindow::on_supprimerButton_2_clicked()
{
    QString aj=ui->comboBox_3->currentText();
    int ref=ui->supprimer_par_reference_2->text().toInt();
    bool test=Ftmp.supprimer(ref);

    if(test)
    {

        //Refresh (Actualiser)
        ui->tableView_2->setModel(Ftmp.afficher());

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

        ui->supprimer_par_reference_2->clear();
        ui->lineEdit_reference->clear();
        ui->lineEdit_nomfour->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_gsmfour->clear();
        ui->lineEdit_ad->clear();
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
        ui->lineEdit_reference->clear();
        ui->lineEdit_nomfour->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_gsmfour->clear();
        ui->lineEdit_ad->clear();
    }
}

//Cliquer sur le bouton MODIFIER
void MainWindow::on_modifierButton_clicked()
{
    QString aj=ui->comboBox_3->currentText();
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


        ui->lineEdit_reference->clear();
        ui->lineEdit_nomfour->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_gsmfour->clear();
        ui->lineEdit_ad->clear();

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

//Cliquer sur le bouton fournisseur->modifier(gestion)->home
void MainWindow::on_homeButton_modifier_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

//Cliquer sur le bouton fournisseur->modifier(gestion)->load
void MainWindow::on_LoadButton_clicked()
{
    ui->tableView_2->setModel(Ftmp.afficher()); //Chef
}



void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_homeButton_2_clicked()
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


//Recherche
void MainWindow::on_recherche_par_reference_2_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_par_reference_2->text();
            ui->tableView_2->setModel(Ftmp.Recherchefournisseur(rech));
}

//Trie
void MainWindow::on_trier_button_clicked()
{
    QString tri=ui->comboBox->currentText();

    if (tri=="Référence" || tri=="Referencia" || tri=="Reference")
    {
        ui->tableView_2->setModel(Ftmp.trier_ref());
    }
    else if (tri=="Nom" || tri=="Nombre" || tri=="Name")
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
        QString pdf_trad=ui->comboBox_3->currentText();
        if (pdf_trad=="Francais")
        {
            QMessageBox::critical(nullptr, QObject::tr("Exportation de fichiers PDF"),
            QObject::tr("Pas de référence saisie. \nVeuillez saisir une référence.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (pdf_trad=="English")
        {
            QMessageBox::critical(nullptr, QObject::tr("PDF File Export"),
            QObject::tr("No reference entered. \nPlease enter a reference.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (pdf_trad=="Espagnol")
        {
            QMessageBox::critical(nullptr, QObject::tr("Exportación de archivos PDF"),
            QObject::tr("No se ha introducido ninguna referencia. \nPor favor ingrese una referencia.\n"
                                    "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
        }
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


        QString pdf_trad=ui->comboBox_3->currentText();
        if (pdf_trad=="Francais")
        {
            int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
                painter.end();
            }
            else
            {
                painter.end();
            }
        }
        else if (pdf_trad=="English")
        {
            int reponse = QMessageBox::question(this, "PDF Export", "PDF Saved.\nYou want to view it ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
                painter.end();
            }
            else
            {
                painter.end();
            }
        }
        else if (pdf_trad=="Espagnol")
        {
            int reponse = QMessageBox::question(this, "Exportación de PDF", "PDF es guardado.\nQuieres verlo ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
                painter.end();
            }
            else
            {
                painter.end();
            }
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

//Cliquer sur le bouton fournisseur->historique->load
void MainWindow::on_LoadButton_Historique_clicked()
{
    ui->tableView_historique->setModel(Ftmp.afficher_historique()); //Chef
}









//LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR


//Cliquer sur le bouton livreur->home->Deconnecter
void MainWindow::on_pushButton_14_clicked()
{
    QString quitter=ui->comboBox_3->currentText();

    if (quitter=="Francais")
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
    else if (quitter=="English")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Are you sure ?", QMessageBox::Yes | QMessageBox::No);
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
    else if (quitter=="Espagnol")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Está usted seguro ?", QMessageBox::Yes | QMessageBox::No);
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
}

//Cliquer sur le bouton livraison
void MainWindow::on_livrButton_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}

//Cliquer sur le bouton livraison->home


//Cliquer sur le bouton fournisseur
void MainWindow::on_fournisseurButton_3_clicked()
{
    QString lang=ui->comboBox_3->currentText();
    if (lang=="Francais")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestion des fournisseurs"),
        QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
    else if (lang=="English")
    {
        QMessageBox::critical(nullptr, QObject::tr("Management of suppliers"),
        QObject::tr("You are a delivery man. \nYou don't have the necessary access rights to access.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (lang=="Espagnol")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestión de proveedores"),
        QObject::tr("Eres un repartidor. \nNo tiene los derechos de acceso necesarios para acceder.\n"
                                "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
    }
}

//Cliquer sur le bouton employee
void MainWindow::on_empButton_3_clicked()
{
    QString lang=ui->comboBox_3->currentText();
    if (lang=="Francais")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestion des employes"),
        QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
    else if (lang=="English")
    {
        QMessageBox::critical(nullptr, QObject::tr("Employee management"),
        QObject::tr("You are a delivery man. \nYou don't have the necessary access rights to access.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (lang=="Espagnol")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestión de empleados"),
        QObject::tr("Eres un repartidor. \nNo tiene los derechos de acceso necesarios para acceder.\n"
                                "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
    }
}

//Cliquer sur le bouton clients
void MainWindow::on_clButton_3_clicked()
{
    QString lang=ui->comboBox_3->currentText();
    if (lang=="Francais")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestion des clients"),
        QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
    else if (lang=="English")
    {
        QMessageBox::critical(nullptr, QObject::tr("Customer management"),
        QObject::tr("You are a delivery man. \nYou don't have the necessary access rights to access.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (lang=="Espagnol")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestión de clientes"),
        QObject::tr("Eres un repartidor. \nNo tiene los derechos de acceso necesarios para acceder.\n"
                                "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
    }
}

//Cliquer sur le bouton produits
void MainWindow::on_prodButton_3_clicked()
{
    QString lang=ui->comboBox_3->currentText();
    if (lang=="Francais")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestion des produits"),
        QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
    else if (lang=="English")
    {
        QMessageBox::critical(nullptr, QObject::tr("Product management"),
        QObject::tr("You are a delivery man. \nYou don't have the necessary access rights to access.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (lang=="Espagnol")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestión de productos"),
        QObject::tr("Eres un repartidor. \nNo tiene los derechos de acceso necesarios para acceder.\n"
                                "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
    }

}

//Cliquer sur le bouton commandes
void MainWindow::on_cmdButton_3_clicked()
{
    QString lang=ui->comboBox_3->currentText();
    if (lang=="Francais")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestion des commandes"),
        QObject::tr("Vous êtes un livreur. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
    else if (lang=="English")
    {
        QMessageBox::critical(nullptr, QObject::tr("Order management"),
        QObject::tr("You are a delivery man. \nYou don't have the necessary access rights to access.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (lang=="Espagnol")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestión de pedidos"),
        QObject::tr("Eres un repartidor. \nNo tiene los derechos de acceso necesarios para acceder.\n"
                                "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
    }

}













//SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE * SIMPLE EMPLOYE



//Cliquer sur le bouton simpleemployee->home->Deconnecter
void MainWindow::on_pushButton_15_clicked()
{
    QString quitter=ui->comboBox_3->currentText();

    if (quitter=="Francais")
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
    else if (quitter=="English")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Are you sure ?", QMessageBox::Yes | QMessageBox::No);
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
    else if (quitter=="Espagnol")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Está usted seguro ?", QMessageBox::Yes | QMessageBox::No);
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
}



//Cliquer sur le bouton employees
void MainWindow::on_empButton_4_clicked()
{
    QString lang=ui->comboBox_3->currentText();
    if (lang=="Francais")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestion des employes"),
        QObject::tr("Vous êtes un simple employé. \nVous n'avez pas les droits d'accées nécessaires pour accéder.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (lang=="English")
    {
        QMessageBox::critical(nullptr, QObject::tr("Employee management"),
        QObject::tr("YYou are just an employee. \nYou don't have the necessary access rights to access.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (lang=="Espagnol")
    {
        QMessageBox::critical(nullptr, QObject::tr("Gestión de empleados"),
        QObject::tr("Eres solo un empleado. \nNo tiene los derechos de acceso necesarios para acceder.\n"
                                "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
    }
}

//Cliquer sur le bouton clients
void MainWindow::on_clButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

//Cliquer sur le bouton produits
void MainWindow::on_prodButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

//Cliquer sur le bouton commandes
void MainWindow::on_cmdButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(3);
}

//Cliquer sur le bouton livraisons
void MainWindow::on_livrButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(4);
}

//Cliquer sur le bouton fournisseurs
void MainWindow::on_fournisseurButton_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(6);
}


/*Les fonctions de base dans chef->fournisseurs*/

//Cliquer sur le bouton AJOUTER
void MainWindow::on_ajouterButton_4_clicked()
{
    QString aj=ui->comboBox_3->currentText();
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

        ui->lineEdit_ref_4->clear();
        ui->lineEdit_nom_4->clear();
        ui->lineEdit_mail_4->clear();
        ui->lineEdit_gsm_4->clear();
        ui->lineEdit_adresse_4->clear();

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
        ui->lineEdit_ref_4->clear();
    }
}

//Cliquer sur le bouton fournisseur->ajouter->home
void MainWindow::on_homeButton_ajouter_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

//Cliquer sur le bouton SUPPRIMER
void MainWindow::on_supprimerButton_5_clicked()
{
    QString aj=ui->comboBox_3->currentText();
    int ref=ui->supprimer_par_reference_5->text().toInt();
    bool test=Ftmp.supprimer(ref);

    if(test)
    {

        //Refresh (Actualiser)
        ui->tableView_9->setModel(Ftmp.afficher());

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

        ui->supprimer_par_reference_5->clear();
        ui->lineEdit_reference_4->clear();
        ui->lineEdit_nomfour_4->clear();
        ui->lineEdit_email_4->clear();
        ui->lineEdit_gsmfour_4->clear();
        ui->lineEdit_ad_4->clear();
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
        ui->lineEdit_reference_4->clear();
    }
}

//Cliquer sur la reference du fournisseur dans tableView
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

//Cliquer sur le bouton MODIFIER
void MainWindow::on_modifierButton_4_clicked()
{
    Fournisseur f;
    f.setRef(ui->lineEdit_reference_4->text().toInt());
    f.setNom_fourn(ui->lineEdit_nomfour_4->text());
    f.setMail_fourn(ui->lineEdit_email_4->text());
    f.setGSM(ui->lineEdit_gsmfour_4->text().toInt());
    f.setAdresse_fourn(ui->lineEdit_ad_4->text());

   bool check=f.modifier();
   QString aj=ui->comboBox_3->currentText();

    if (check)
    {
        //Refresh (Actualiser)
        ui->tableView_9->setModel(Ftmp.afficher());

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

        ui->lineEdit_reference_4->clear();
        ui->lineEdit_nomfour_4->clear();
        ui->lineEdit_email_4->clear();
        ui->lineEdit_gsmfour_4->clear();
        ui->lineEdit_ad_4->clear();

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

//Cliquer sur le bouton fournisseur->modifier(gestion)->home
void MainWindow::on_homeButton_modifier_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

//Cliquer sur le bouton fournisseur->modifier(gestion)->load
void MainWindow::on_LoadButton_2_clicked()
{
    ui->tableView_9->setModel(Ftmp.afficher());
}

//Chercher
void MainWindow::on_recherche_par_reference_4_textChanged(const QString &arg1)
{
    QString rech=ui->recherche_par_reference_4->text();
            ui->tableView_9->setModel(Ftmp.Recherchefournisseur(rech));
}

//Trie simpleemployee
void MainWindow::on_TrierButton_clicked()
{
    QString tri=ui->comboBox_2->currentText();

    if (tri=="Référence" || tri=="Referencia" || tri=="Reference")
    {
        ui->tableView_9->setModel(Ftmp.trier_ref());
    }
    else if (tri=="Nom" || tri=="Nombre" || tri=="Name")
    {
        ui->tableView_9->setModel(Ftmp.trier_nom());
    }
    else if (tri=="Email")
    {
        ui->tableView_9->setModel(Ftmp.trier_email());
    }
}

//PDF simpleemployee
void MainWindow::on_PDFButton_4_clicked()
{
    QString ref_pdf=ui->recherche_par_reference_4->text();

    if (ref_pdf.isEmpty())
    {
        QString pdf_trad=ui->comboBox_3->currentText();
        if (pdf_trad=="Francais")
        {
            QMessageBox::critical(nullptr, QObject::tr("Exportation de fichiers PDF"),
            QObject::tr("Pas de référence saisie. \nVeuillez saisir une référence.\n"
                                    "Cliquez sur annuler pour quitter."), QMessageBox::Cancel);
        }
        else if (pdf_trad=="English")
        {
            QMessageBox::critical(nullptr, QObject::tr("PDF File Export"),
            QObject::tr("No reference entered. \nPlease enter a reference.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (pdf_trad=="Espagnol")
        {
            QMessageBox::critical(nullptr, QObject::tr("Exportación de archivos PDF"),
            QObject::tr("No se ha introducido ninguna referencia. \nPor favor ingrese una referencia.\n"
                                    "Haga clic en Cancelar para salir."), QMessageBox::Cancel);
        }
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



        QString pdf_trad=ui->comboBox_3->currentText();
        if (pdf_trad=="Francais")
        {
            int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
                painter.end();
            }
            else
            {
                painter.end();
            }
        }
        else if (pdf_trad=="English")
        {
            int reponse = QMessageBox::question(this, "PDF Export", "PDF Saved.\nYou want to view it ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
                painter.end();
            }
            else
            {
                painter.end();
            }
        }
        else if (pdf_trad=="Espagnol")
        {
            int reponse = QMessageBox::question(this, "Exportación de PDF", "PDF es guardado.\nQuieres verlo ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Contrat.pdf"));
                painter.end();
            }
            else
            {
                painter.end();
            }
        }

        ui->recherche_par_reference_4->clear();
    }
}




