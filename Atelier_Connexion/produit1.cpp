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
}
produit::produit(int id_produit,int qt_stock,QString nom_produit,QString video,int prix_uni)
{
    this->id_produit=id_produit;
    this->qt_stock=qt_stock;
    this->nom_produit=nom_produit;
    this->video=video;
    this->prix_uni=prix_uni;
}
bool produit::add( )
{
    QSqlQuery query;
    QString id_string=QString::number(id_produit);
    QString stock_string=QString::number(qt_stock);
    QString prix_string=QString::number(prix_uni);

    query.prepare("INSERT INTO PRODUITS (id_produit, nom_pr, QT_STOCK,PRIX_UNI,VIDEO) "
                  "VALUES (:id, :nom, :stock, :prix, :video);"
                  );
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom_produit);
    query.bindValue(":stock", stock_string);
    query.bindValue(":prix", prix_string);
    query.bindValue(":video", video);

    if(!query.exec()){
        qDebug()<<"not added";
    }
    return true;
}


QSqlQueryModel * produit::read()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PRODUITS");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_produit"));

return model;
}
QSqlQueryModel*  produit ::read_id()
{QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select ID_PRODUIT from PRODUITS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PRODUIT"));
return model;
}
QSqlQueryModel * produit::read1()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PRODUITS");
         return model;
}
bool produit::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM PRODUITS where id_produit=:id");
    query.bindValue(":id",res);
return query.exec();
}
bool produit::update(int id)
{

    QSqlQuery  query;
    QString res = QString::number(id);

    QString stock_string=QString::number(qt_stock);
    QString prix_string=QString::number(prix_uni);
query.prepare("UPDATE PRODUITS SET nom_pr=:nom,QT_STOCK=:stock,PRIX_UNI=:prix,VIDEO=:video WHERE id_produit=:id");
query.bindValue(":id",res);
query.bindValue(":nom", nom_produit);
query.bindValue(":stock", stock_string);
query.bindValue(":prix", prix_string);
query.bindValue(":video", video);
return query.exec();
}

