#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
Employee::Employee()
{
Matricule=0;//initialisier le matricule (id)a zero
Nom=" "; //nom = chaine vide
Prenom=" ";
Mail=" ";
GSM=0;
Role=" ";
Salaire=0;
}
//role de ce nouveau constructeur est d'affecter les nouveaux valeurs insere par l utilistateur et les attributués au niveau de mes attributs
Employee::Employee(int Matricule,QString Nom,QString Prenom,QString Mail,int GSM,QString Role,int Salaire)
{
    this->Matricule=Matricule;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Mail=Mail;
    this->GSM=GSM;
    this->Role=Role;
    this->Salaire=Salaire;

}

//Getters
int     Employee::getMatricule(){return Matricule;} // me retourner la valeur de matricule
QString Employee::getNom(){return Nom;}
QString Employee::getPrenom(){return Prenom;}
QString Employee::getMail(){return Mail;}
int     Employee::getGSM(){return GSM;}
QString Employee::getRole(){return Role;}
int     Employee::getSalaire(){return Salaire;}
//Setters
void Employee::setMatricule(int Matricule){this->Matricule=Matricule;}
void Employee::setNom(QString Nom){this->Nom=Nom;}
void Employee::setPrenom(QString Prenom){this->Prenom=Prenom;}
void Employee::setMail(QString Mail){this->Mail=Mail;}
void Employee::setGSM(int GSM){this->GSM=GSM;}
void Employee::setRole(QString Role){this->Role=Role;}
void Employee::setSalaire(int Salaire){this->Salaire=Salaire;}
bool Employee::ajouter()
{


    QSqlQuery query;
    QString Matricule_string=QString::number(Matricule);
    QString GSM_string=QString::number(GSM);
    QString Salaire_string=QString::number(Salaire);
    query.prepare("INSERT INTO EMPLOYE (MATRICULE, NOM_EMP, PRENOM_EMP,MAIL_EMP,GSM_EMP,ROLE_EMP,SALAIRE_EMP) "
                        "VALUES (:matricule, :nom, :prenom,:mail,:gsm,:role,:salaire)");
          query.bindValue(":matricule", Matricule_string);
          query.bindValue(":nom", Nom);
          query.bindValue(":prenom", Prenom);
          query.bindValue(":mail", Mail);
          query.bindValue(":gsm", GSM_string);
          query.bindValue(":role", Role);
          query.bindValue(":salaire", Salaire_string);



            return query.exec() ;

}
bool Employee::supprimer(int Mat)
{
    QSqlQuery query;
    QString res = QString::number(Mat);

        query.prepare(" Delete from EMPLOYE where MATRICULE=:Mat");

        query.bindValue(":Mat", res);


        return  query.exec();
}
QSqlQueryModel * Employee::afficher()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYE");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("MATRICULE"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("GSM"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("ROLE"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("SALAIRE"));
return model;
}
bool Employee::update(int Mat)
{

    QSqlQuery  query;
    QString Matricule_string=QString::number(Mat);
    QString GSM_string=QString::number(GSM);
    QString Salaire_string=QString::number(Salaire);
query.prepare("UPDATE EMPLOYE SET NOM_EMP=:nom, PRENOM_EMP=:prenom,MAIL_EMP=:mail,GSM_EMP=:gsm,ROLE_EMP=:role,SALAIRE_EMP=:salaire WHERE MATRICULE=:Mat");
query.bindValue(":Mat", Matricule_string);
query.bindValue(":nom", Nom);
query.bindValue(":prenom", Prenom);
query.bindValue(":mail", Mail);
query.bindValue(":gsm", GSM_string);
query.bindValue(":role", Role);
query.bindValue(":salaire", Salaire_string);
return query.exec();
}



