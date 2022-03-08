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

bool Fournisseur::modifier(int ref)
{





    QString REF_string=QString::number(ref);

    QSqlQuery query;
      query.prepare("update fournisseurs set nom_four=:nom_fourn,mail_four=:mail_four,gsm_fourn=:gsm_fournn,adresse_fourn=:adresse_fourn where ref_four=:ref_four");
      query.bindValue(":ref_four",REF_string);
      query.bindValue(":nom_fourn",nom_fourn);
      query.bindValue(":mail_fourn",mail_fourn);
      query.bindValue(":gsm_fourn",gsm_fourn);
      query.bindValue(":adresse_fourn",adresse_fourn);


      return query.exec();
}
