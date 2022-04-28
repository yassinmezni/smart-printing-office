#include "livraison.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QTimer>
#include <QDateTime>


livraison::livraison()
{
    id=0;
    frais=0;
    date=" ";
    localisation=" ";
}

livraison::livraison(int id,QString date,QString localisation,int frais)
{
    this->id=id ;
    this->date=date ;
    this->localisation=localisation ;
    this->frais=frais;
}

int livraison::getid()
{
    return id;
}

QString livraison::getdate()
{
    return date;
}

QString livraison::getlocalisation()
{
    return localisation;
}

int livraison::getfrais()
{
    return frais;
}

void livraison::setid(int id)
{
    this->id=id;
}

void livraison::setdate(QString date)
{
    this->date=date;
}

void livraison::setlocalisation(QString localisation)
{
    this->localisation=localisation;
}

void livraison::setfrais(int frais)
{
    this->frais=frais;
}



bool livraison::ajouter()
{
    QSqlQuery query;
    QString id_QString=QString::number(id);
    QString frais_QString=QString::number(frais);


    query.prepare("INSERT INTO LIVRAISON (ID_L,DATE_LIVRAISON,LOCALISATION,FRAIS_LIVRAISONS) "
                  "VALUES (:id,:date,:localisation,:frais)");
    query.bindValue(":id",id_QString);
    query.bindValue(":date", date);
    query.bindValue(":localisation", localisation);
    query.bindValue(":frais", frais_QString);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion livraison',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return  query.exec();
}


bool livraison::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from livraison where id_l=:id_l");
    query.bindValue(0, id);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();
    QString date=dateTime.toString();
    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression livraison',:dateTime)");
    qry.bindValue(":dateTime",dateTime);
    qry.exec();

    return  query.exec();
}


QSqlQueryModel* livraison::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM livraison");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Livraison"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Livraison"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Frais Livraison"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN Employé"));

    return model;
}


bool livraison::modifier()
{
    QSqlQuery query;
    query.prepare("Update livraison set ID_L=:id,DATE_LIVRAISON=:date,LOCALISATION=:localisation,FRAIS_LIVRAISONS=:frais where ID_L=:id");

    query.bindValue(":date",date);
    query.bindValue(":localisation",localisation);
    query.bindValue(":frais",frais);
    query.bindValue(":id",id);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification livraison',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return query.exec();
}


QSqlQueryModel* livraison::Recherchelivreur(QString recherche)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIVRAISON WHERE ID_L LIKE '"+recherche+"%' OR FRAIS_LIVRAISONS LIKE '"+recherche+"%' OR LOCALISATION LIKE '"+recherche+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Livraison"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Livraison"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Frais Livraison"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN Employé"));

    return model;
}


//Trie Par id croissant
QSqlQueryModel * livraison::trierlivraisonParid_M()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM LIVRAISON order by ID_L ASC");
    q->exec();
    model->setQuery(*q);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Trie livraison par id asc',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}


//Trie Par id descendent
QSqlQueryModel * livraison::trierlivraisonParid_D()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM LIVRAISON order by ID_L DESC");
    q->exec();
    model->setQuery(*q);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Trie livraison par id desc',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}


//Trie Par localisation
QSqlQueryModel * livraison::trierlivraisonParlocalisation()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM LIVRAISON order by LOCALISATION ASC");
    q->exec();
    model->setQuery(*q);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Trie livraison par localisation asc',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}


//Trie Par frais croissant
QSqlQueryModel * livraison::trierlivraisonParfrais_M()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM LIVRAISON order by FRAIS_LIVRAISONs ASC");
    q->exec();
    model->setQuery(*q);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Trie livraison par frais asc',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}


QSqlQueryModel * livraison::afficherhistorique()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from HISTORIQUE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Activite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));

    return model;
}
