#include "fournisseur.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



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

    return query.exec();

}
