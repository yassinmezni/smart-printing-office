#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QTimer>
#include <QDateTime>


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
int Employee::getMatricule()
{
    return Matricule;
}

QString Employee::getNom()
{
    return Nom;
}

QString Employee::getPrenom()
{
    return Prenom;
}

QString Employee::getMail()
{
    return Mail;
}

int Employee::getGSM()
{
    return GSM;
}

QString Employee::getRole()
{
    return Role;
}

int Employee::getSalaire()
{
    return Salaire;
}

//Setters
void Employee::setMatricule(int Matricule)
{
    this->Matricule=Matricule;
}

void Employee::setNom(QString Nom)
{
    this->Nom=Nom;
}

void Employee::setPrenom(QString Prenom)
{
    this->Prenom=Prenom;
}

void Employee::setMail(QString Mail)
{
    this->Mail=Mail;
}

void Employee::setGSM(int GSM)
{
    this->GSM=GSM;
}

void Employee::setRole(QString Role)
{
    this->Role=Role;
}

void Employee::setSalaire(int Salaire)
{
    this->Salaire=Salaire;
}


bool Employee::ajouter()
{
    QString Matricule_string=QString::number(Matricule);
    QString GSM_string=QString::number(GSM);
    QString Salaire_string=QString::number(Salaire);
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (MATRICULE, NOM_EMP, PRENOM_EMP,MAIL_EMP,GSM_EMP,ROLE_EMP,SALAIRE_EMP) "
                        "VALUES (:matricule, :nom, :prenom,:mail,:gsm,:role,:salaire)");//BindValue (variable précédée par « : » et insérée dans la partie SQL)
    query.bindValue(":matricule", Matricule_string);
    query.bindValue(":nom", Nom);
    query.bindValue(":prenom", Prenom);
    query.bindValue(":mail", Mail);
    query.bindValue(":gsm", GSM_string);
    query.bindValue(":role", Role);
    query.bindValue(":salaire", Salaire_string);
    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion employe',:dateTime)");
    qry.bindValue(":dateTime",dateTime);
    qry.exec();

    return query.exec() ;
}


bool Employee::supprimer(int Mat)
{
    QSqlQuery query;
    QString res = QString::number(Mat);
    query.prepare(" Delete from EMPLOYE where MATRICULE=:Mat");
    query.bindValue(":Mat", res);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression employe',:dateTime)");
    qry.bindValue(":dateTime",dateTime);
    qry.exec();

    return  query.exec();
}


QSqlQueryModel * Employee::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("GSM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Rôle"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Image"));

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

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification employe',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return query.exec();
}


QSqlQueryModel * Employee::trierr(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EMPLOYE order by "+critere+" "+mode+"");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("GSM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Rôle"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Image"));

    return model;
}


QSqlQueryModel * Employee::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE order by MATRICULE asc ");

    return model;
}


QSqlQueryModel *  Employee::Tri_nom()
{
    QSqlQueryModel* model =new QSqlQueryModel();
    QSqlQuery  *nom = new QSqlQuery();
    nom->prepare("SELECT * FROM EMPLOYE order by NOM_EMP asc");
    nom->exec();
    model->setQuery(*nom);

    return model;
}

QSqlQueryModel * Employee::afficher_tri_gsm()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE order by GSM_EMP asc ");

    return model;
}

QSqlQueryModel * Employee::afficher_tri_matricule()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE order by MATRICULE asc ");

    return model;
}


QSqlQueryModel * Employee::afficher_historique()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from HISTORIQUE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Activite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date et Heure"));

    return model;
}


QSqlQueryModel* Employee::Rechercheemployee(QString recherche)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM Employe WHERE MATRICULE LIKE '"+recherche+"%' OR NOM_EMP LIKE '"+recherche+"%' OR PRENOM_EMP LIKE '"+recherche+"%' OR MAIL_EMP LIKE '"+recherche+"%' OR GSM_EMP LIKE '"+recherche+"%' OR ROLE_EMP LIKE '"+recherche+"%' OR SALAIRE_EMP LIKE '"+recherche+"%' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("GSM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Rôle"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Image"));

    return model;
}

