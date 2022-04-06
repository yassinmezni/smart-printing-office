
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include "QMessageBox"
#include <QSqlQuery>

//***********camera*******
#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
#include<QFileDialog>
//****************************

//************qrcode**********
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <utility>
#include "qrcode.h"
//****************************
//delaration de C.S
#include <QRegExpValidator>
using qrcodegen::QrCode;


//#include "qrcodegen.hpp"

#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"

#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Employee E;
    ui->setupUi(this);
    //*********CAMERA***********************************************************************************************************************************

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
    ui->options ->setMenu(mOptionsMenu);
    mlayout->addWidget(mCameraViewfinder);
    mlayout->setMargin(0);
    ui->scrollArea->setLayout(mlayout);
    connect(mEncenderAction, &QAction::triggered ,[&](){
        mCamera->start();
    });

    connect(mApagarAction,&QAction::triggered,[&](){
        mCamera->stop();
    });

    connect(mcapturerAction,&QAction::triggered,[&](){
        auto filename = QFileDialog:: getSaveFileName(this,"capturar","/",
                                                            "imagen (.jpg;.jpeg)");
              if(filename.isEmpty()){
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
//*******************************************************************************************************

    //Controle Saisie Mail
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
{  //Récuperation les informations saisie dans les 7 champs.
    int Matricule=ui->lineEdit_matricule->text().toInt(); //Convertir la chaine saisie en un entier car l’attribut id est de type int
    QString Nom=ui->lineEdit_Nom->text();
    QString Prenom=ui->lineEdit_Prenom->text();
    QString Mail=ui->lineEdit_mail->text();
    int GSM=ui->lineEdit_GSM->text().toInt();
    QString Role=ui->lineEdit_Role->text();
    int Salaire=ui->lineEdit_Salaire->text().toInt();
    Employee E(Matricule,Nom,Prenom,Mail,GSM,Role,Salaire);//INSTANCIER UN OBJET DE LA CLASSE EMPLOYEE
                                                           //EN UTILISANT LES INFORMATIONS SAISIES DANS L INTERFACE7

bool test=E.ajouter(); //INSERER L OBJET EMPLOYEE INSTANCIé DANS LE TABLE EMPLOYE
                       //ET RECUPERE LA VLEUR DE RETOUR DE QUERY.EXEC
if(test) // si requéte executée ==> QMessage::information
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
                     bool test=E.update(Matricule);
                     if(test)
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





//************************TRI*******************************************************
void MainWindow::on_radioButton_tri_personnel_4_clicked()
{
    Employee E;
        ui->tab_employee->setModel( E.afficher_tri_matricule());

}


void MainWindow::on_radioButton_tri_personnel_3_clicked()
{
    Employee E;
        ui->tab_employee->setModel( E.Tri_nom());

}

void MainWindow::on_radioButton_tri_personnel_2_clicked()
{
    Employee E;
        ui->tab_employee->setModel( E.afficher_tri_gsm());

}
//*******************************rechercher****************************************************
void MainWindow::on_recherche_par_reference_2_textChanged(const QString &arg1)
{    Employee E;

    QString rech=ui->recherche_par_reference_2->text();
            ui->tab_employee->setModel(E.Rechercheemployee(rech));
}

//*****************************qr*************************************************************
void MainWindow::on_qrCode_clicked()
{
    int tabeq=ui->tab_employee->currentIndex().row();
                   QVariant idd=ui->tab_employee->model()->data(ui->tab_employee->model()->index(tabeq,0));
                   QString matricule=idd.toString();
                  // QString code=idd.toSTring();
                   QSqlQuery qry;
                   qry.prepare("select * from EMPLOYE where code=:code");
                   qry.bindValue(":code",matricule);
                   qry.exec();

                    QString nom_emp,prenom_emp,mail_emp,role_emp;//attributs
                    int matricule_emp,gsm_emp,salaire_emp;
                    QDate datep;

                  while(qry.next()){

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
                   for (int y = 0; y < qr.getSize(); y++) {
                       for (int x = 0; x < qr.getSize(); x++) {
                           int color = qr.getModule(x, y);  // 0 for white, 1 for black

                           // You need to modify this part
                           if(color==0)
                               im.setPixel(x, y,qRgb(254, 254, 254));
                           else
                               im.setPixel(x, y,qRgb(0, 0, 0));
                       }
                   }
                   im=im.scaled(200,200);
                  ui->qr_code->setPixmap(QPixmap::fromImage(im));
}



void MainWindow::on_loadButton_historique_clicked()
{
    Employee E;
        ui->tableView_historique->setModel(E.afficher_historique());

}

void MainWindow::on_homeButton_recherche_clicked()
{
    Employee E;
        ui->tableView_historique->setModel(E.afficher_historique());

}

