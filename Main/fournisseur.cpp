#include "fournisseur.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>





Fournisseur::Fournisseur()
{

}

Fournisseur::Fournisseur(int reference,QString nom_fourn,QString mail_fourn,int gsm_fourn,QString adresse_fourn)
{
    this->reference=reference;
    this->nom_fourn=nom_fourn;
    this->mail_fourn=mail_fourn;
    this->gsm_fourn=gsm_fourn;
    this->adresse_fourn=adresse_fourn;
}

bool Fournisseur::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(reference);
    QString bes = QString::number(gsm_fourn);

    //prepare() prend la requête en paramètre pour la préparer à l'exécution
    query.prepare("insert into FOURNISSEURS(REF_FOUR,NOM_FOUR,MAIL_Four,GSM_FOURN,ADRESSE_FOURN)"
                  "values (:reference,:nom_fourn,:mail_fourn,:gsm_fourn,:adresse_fourn)");

    //création des variables liées
    query.bindValue(":reference",res);
    query.bindValue(":nom_fourn",nom_fourn);
    query.bindValue(":mail_fourn",mail_fourn);
    query.bindValue(":gsm_fourn",bes);
    query.bindValue(":adresse_fourn",adresse_fourn);


    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion fournisseur',:dateTime)");
    qry.bindValue(":dateTime",dateTime);


    qry.exec();

    return query.exec();
    // exec() envoie la requete pour l'exécution
}

QSqlQueryModel * Fournisseur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from fournisseurs");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("GSM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));

    return model;
}

bool Fournisseur::supprimer(int ref)
{

    QSqlQuery query;
    QString res=QString::number(ref);

    query.prepare("Delete from fournisseurs where REF_FOUR= :ref");
    query.bindValue(":ref",res);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression fournisseur',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return query.exec();
}

bool Fournisseur::modifier()
{
    QSqlQuery query;
    query.prepare("Update fournisseurs set NOM_FOUR=:nom_fourn,MAIL_FOUR=:mail_fourn,GSM_FOURN=:gsm_fourn,ADRESSE_FOURN=:adresse_fourn where REF_FOUR=:reference");
    query.bindValue(":nom_fourn",nom_fourn);
    query.bindValue(":mail_fourn",mail_fourn);
    query.bindValue(":gsm_fourn",gsm_fourn);
    query.bindValue(":adresse_fourn",adresse_fourn);
    query.bindValue(":reference",reference);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification fournisseur',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return query.exec();
}


QSqlQueryModel* Fournisseur::Recherchefournisseur(QString recherche)
{
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM FOURNISSEURS WHERE REF_FOUR LIKE '"+recherche+"%' OR NOM_FOUR LIKE '"+recherche+"%' OR MAIL_FOUR LIKE '"+recherche+"%' OR GSM_FOURN LIKE '"+recherche+"%' OR ADRESSE_FOURN LIKE '"+recherche+"%'");
     model->setHeaderData(0,Qt::Horizontal, QObject::tr("Reference"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Email"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("GSM"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));

return model;
}


QSqlQueryModel* Fournisseur::RechercheLogin(QString login, QString pass)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGIN WHERE REF_FOUR LIKE '"+login+"%' OR PASSWORD LIKE '"+pass+"%'");

    return model;
}


QSqlQueryModel * Fournisseur::trier_ref()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM FOURNISSEURS ORDER BY REF_FOUR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("GSM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Trie des fournisseurs par reference',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}

QSqlQueryModel * Fournisseur::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM FOURNISSEURS ORDER BY NOM_FOUR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("GSM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Trie des fournisseurs par nom',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}

QSqlQueryModel * Fournisseur::trier_email()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM FOURNISSEURS ORDER BY MAIL_FOUR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("GSM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Trie des fournisseurs par email',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();

    return model;
}

QSqlQueryModel * Fournisseur::afficher_historique()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from HISTORIQUE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Activite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date et Heure"));


    return model;
}

