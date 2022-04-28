#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QDate>



client::client()
{
    cin=0;
    numtel=0;
    nom=" ";
    prenom=" ";
    adresse=" ";
    mail=" ";
}

client::client(int cin,QString nom,QString prenom,QString adresse,int numtel,QString mail)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->numtel=numtel;
    this->mail=mail;
}

int client::getcin()
{
    return cin;
}

QString client::getnom()
{
    return nom;
}

QString client::getprenom()
{
    return prenom;
}

QString client::getadresse()
{
    return adresse;
}

int client::getnumtel()
{
    return numtel;
}

QString client::getmail()
{
    return mail;
}

void client::setcin(int cin)
{
    this->cin=cin;
}

void client::setnom(QString nom)
{
    this->nom=nom;
}

void client::setprenom(QString prenom)
{
    this->prenom=prenom;
}

void client::setadresse(QString adresse)
{
    this->adresse=adresse;
}

void client::setnumtel(int numtel)
{
    this->numtel=numtel;
}

void client::setmail(QString mail)
{
    this->mail=mail;
}



bool client::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(cin);

    query.prepare("INSERT INTO clients ( cin, nom_cl, prenom_cl, adresse_cl, num_tel, mail) "
                  "VALUES (:cin, :nom, :prenom, :adresse, :numtel, :mail)");
    query.bindValue(":cin", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":numtel", numtel);
    query.bindValue(":mail", mail);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion client',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return  query.exec();
}


bool client::supprimer(int cin)
{
    QSqlQuery query;
    QString bes=QString::number(cin);

    query.prepare("Delete from clients where CIN=:cin");
    query.bindValue(":cin",bes);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression client',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return  query.exec();
}


QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM clients");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numéro du tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

    return model;
}


bool client::modifier(int cin)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString num_string=QString::number(numtel);

    query.prepare("Update clients set NOM_CL=:nom,PRENOM_CL=:prenom,ADRESSE_CL=:adresse,NUM_TEL=:numtel,MAIL=:mail where CIN=:cin");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":numtel", num_string);
    query.bindValue(":mail",mail);
    query.bindValue(":cin",cin_string);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification client',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return query.exec();
}


QSqlQueryModel* client::Rechercheclient(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM CLIENTS WHERE CIN LIKE '"+recherche+"%' OR NOM_CL LIKE '"+recherche+"%' OR PRENOM_CL LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numéro du tel"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

     return model;
}


//Trie Par CIN montant
QSqlQueryModel * client::trierclientParCIN_M()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM clients order by CIN ASC");
    q->exec();
    model->setQuery(*q);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Tri des clients par cin ascendant',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}

//Trie Par CIN descendent
QSqlQueryModel * client::trierclientParCIN_D()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM clients order by CIN DESC");
    q->exec();
    model->setQuery(*q);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Tri des clients par cin descendant',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();
    return model;
}

//Trie Par Nom
QSqlQueryModel * client::trierclientParNom()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM clients order by NOM_CL ASC");
    q->exec();
    model->setQuery(*q);
    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Tri des clients par nom',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();
    return model;
}


//trie par prenom
QSqlQueryModel * client::trierclientParPrenom()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM clients order by PRENOM_CL ASC");
    q->exec();
    model->setQuery(*q);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Tri des clients par prenom',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}
