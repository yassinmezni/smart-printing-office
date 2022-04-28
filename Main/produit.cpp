#include "produit.h"
#include <QMessageBox>
#include <QtSql>
#include <QComboBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>


produit::produit()
{
    id_produit=0;
    qt_stock=0;
    nom_produit=" ";
    video=" ";
    prix_uni=0;
    FK_FOURNISSEUR_PR=0;
}


produit::produit(int id_produit,int qt_stock,int FK_FOURNISSEUR_PR ,QString nom_produit,QString video,int prix_uni)
{
    this->id_produit=id_produit;
    this->qt_stock=qt_stock;
    this->nom_produit=nom_produit;
    this->video=video;
    this->prix_uni=prix_uni;
    this->FK_FOURNISSEUR_PR=FK_FOURNISSEUR_PR;
}


bool produit::ajouter( )
{
    QSqlQuery query;
    QString id_string=QString::number(id_produit);
    QString stock_string=QString::number(qt_stock);
    QString prix_string=QString::number(prix_uni);
    QString fk_string=QString::number(FK_FOURNISSEUR_PR);

    query.prepare("INSERT INTO PRODUITS (id_produit, nom_pr, QT_STOCK,PRIX_UNI,VIDEO) "//,FK_FOURNISSEUR_PR
                  "VALUES (:id, :nom ,:stock, :prix, :video);");//,:FK_FOURNISSEUR_PR
    query.bindValue(":id", id_string);//(marqueur nominatif)
    query.bindValue(":nom", nom_produit);
    query.bindValue(":stock", stock_string);
    query.bindValue(":prix", prix_string);
    query.bindValue(":video", video);
    //query.bindValue(":FK_FOURNISSEUR_PR", fk_string);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();
    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion produit',:dateTime)");
    qry.bindValue(":dateTime",dateTime);
    qry.exec();

    if(!query.exec())
    {
        qDebug()<<"not added";
    }

    return true;
}


QSqlQueryModel * produit::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Produit"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Stock"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Video"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Réf Fournisseur"));

    return model;
}


QSqlQueryModel*  produit ::afficher_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select ID_PRODUIT from PRODUITS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Produit"));

    return model;
}


QSqlQueryModel* produit::combobox_fk()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select REF_FOUR from FOURNISSEURS");
    return model;
}


bool produit::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM PRODUITS where id_produit=:id");
    query.bindValue(":id",res);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();
    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression produit',:dateTime)");
    qry.bindValue(":dateTime",dateTime);
    qry.exec();

    return query.exec();
}


bool produit::update(int id)
{
    QSqlQuery  query;
    QString res = QString::number(id);

    QString stock_string=QString::number(qt_stock);
    QString prix_string=QString::number(prix_uni);
    //QString fk_string=QString::number(FK_FOURNISSEUR_PR);

    query.prepare("UPDATE PRODUITS SET nom_pr=:nom,QT_STOCK=:stock,PRIX_UNI=:prix,VIDEO=:video WHERE id_produit=:id");//,FK_FOURNISSEUR_PR=:FK_FOURNISSEUR_PR
    query.bindValue(":id",res);
    query.bindValue(":nom", nom_produit);
    query.bindValue(":stock", stock_string);
    query.bindValue(":prix", prix_string);
    query.bindValue(":video", video);
    //query.bindValue(":FK_FOURNISSEUR_PR", fk_string);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification produit',:dateTime)");
    qry.bindValue(":dateTime",dateTime);


    qry.exec();
    return query.exec();
}

QSqlQueryModel* produit::Rechercheproduit(QString recherche)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS WHERE ID_PRODUIT LIKE '"+recherche+"%' OR NOM_PR LIKE '"+recherche+"%' OR QT_STOCK LIKE '"+recherche+"%' OR PRIX_UNI LIKE '"+recherche+"%' OR VIDEO LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Produit"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Stock"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Video"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Réf Fournisseur"));

    return model;
}

QSqlQueryModel * produit::trierr(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PRODUITS order by "+critere+" "+mode+"");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Produit"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Stock"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Video"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Ref Fournisseur"));

    return model;
}

QSqlQueryModel * produit::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PRODUITS order by ID_PRODUIT asc ");

    return model;
}

QSqlQueryModel * produit::tri_prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PRODUITS order by PRIX_UNI asc ");

    return model;
}

QSqlQueryModel *  produit::Tri_nom()
{
     QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *nom_produit = new QSqlQuery();
     nom_produit->prepare("SELECT * FROM PRODUITS order by NOM_PR asc");
     nom_produit->exec();
     model->setQuery(*nom_produit);

     return model ;
}

QSqlQueryModel * produit::afficher_email()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select MAIL_EMP from EMPLOYE");

    return model;
}

QSqlQueryModel * produit::afficher_historique()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from HISTORIQUE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Activite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date et Heure"));

    return model;
}
