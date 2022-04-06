#include"produit1.h"
#include<QMessageBox>
#include<QtSql>
#include<QComboBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>


produit::produit(){
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

    query.prepare("INSERT INTO PRODUITS (id_produit, nom_pr,FK_FOURNISSEUR_PR, QT_STOCK,PRIX_UNI,VIDEO) "
                  "VALUES (:id, :nom,:FK_FOURNISSEUR_PR ,:stock, :prix, :video);"
                  );
    query.bindValue(":id", id_string);//(marqueur nominatif)
    query.bindValue(":nom", nom_produit);
    query.bindValue(":stock", stock_string);
    query.bindValue(":prix", prix_string);
    query.bindValue(":video", video);
    query.bindValue(":FK_FOURNISSEUR_PR", fk_string);

    QSqlQuery qry;
        QDateTime dateTime=QDateTime::currentDateTime();

        QString date=dateTime.toString();

        qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion produit',:dateTime)");
        qry.bindValue(":dateTime",dateTime);


        qry.exec();
    if(!query.exec()){
        qDebug()<<"not added";
    }

    return true;
}


QSqlQueryModel * produit::afficher()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PRODUITS");


return model;
}



QSqlQueryModel*  produit ::afficher_id()
{QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select ID_PRODUIT from PRODUITS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PRODUIT"));
return model;
}
QSqlQueryModel* produit::combobox_fk()
{QSqlQueryModel *model=new QSqlQueryModel();
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

        qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('supprission produit',:dateTime)");
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
    QString fk_string=QString::number(FK_FOURNISSEUR_PR);
query.prepare("UPDATE PRODUITS SET nom_pr=:nom,QT_STOCK=:stock,PRIX_UNI=:prix,VIDEO=:video,FK_FOURNISSEUR_PR=:FK_FOURNISSEUR_PR WHERE id_produit=:id");
query.bindValue(":id",res);
query.bindValue(":nom", nom_produit);
query.bindValue(":stock", stock_string);
query.bindValue(":prix", prix_string);
query.bindValue(":video", video);
query.bindValue(":FK_FOURNISSEUR_PR", fk_string);

QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('update produit',:dateTime)");
    qry.bindValue(":dateTime",dateTime);


    qry.exec();
return query.exec();
}
/*
QSqlQueryModel * produit::rechercher(int id_produit)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    QString res = QString::number(id_produit);
    query.prepare("Select * from PRODUITS where id_produit =:id_produit");
    query.bindValue(":id_produit",res);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));

        return model;
   }
QSqlQueryModel * produit::rechercher_prix(int prix_uni)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    QString pes = QString::number(prix_uni);
    query.prepare("Select * from PRODUITS where prix_uni =:prix_uni");
    query.bindValue(":id_produit",pes);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("prix_uni"));

        return model;
   }

QSqlQueryModel * produit::rechercher_nom(QString nom_pr)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from PRODUITS where nom_pr =:nom_pr");
    query.bindValue(":nom_pr",nom_pr);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom_poduit"));

        return model;
   }
*/
QSqlQueryModel* produit::Rechercheproduit(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM PRODUITS WHERE ID_PRODUIT LIKE '"+recherche+"%' OR NOM_PR LIKE '"+recherche+"%' OR QT_STOCK LIKE '"+recherche+"%' OR PRIX_UNI LIKE '"+recherche+"%' OR VIDEO LIKE '"+recherche+"%' OR FK_FOURNISSEUR_PR LIKE '"+recherche+"%'");
     /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Email"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("GSM"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));*/

return model;
}

QSqlQueryModel * produit::trierr(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRODUITS order by "+critere+" "+mode+"");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_produit"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("stock"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("video"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("cle_fk"));


    return model;
}

QSqlQueryModel * produit::tri_id()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRODUITS order by ID_PRODUIT asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));

    return model;
}

QSqlQueryModel * produit::tri_prix()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRODUITS order by PRIX_UNI asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("prix_uni"));

    return model;
}

QSqlQueryModel *  produit::Tri_nom()
{produit p;
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *nom_produit = new QSqlQuery();
     nom_produit->prepare("SELECT * FROM PRODUITS order by NOM_PR asc");
     nom_produit->exec();
     model->setQuery(*nom_produit);
     return model ;

}
QSqlQueryModel * produit::afficher_email()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select MAIL_EMP from EMPLOYE   ");
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


