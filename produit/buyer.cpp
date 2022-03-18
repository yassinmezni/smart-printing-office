#include"buyer.h"
#include<QMessageBox>
#include<QtSql>
#include<QComboBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
buyer::buyer(){
    id_produit=0;
    qt_stock=0;
    nom_produit=" ";
    video=" ";
    prix_uni=0;
}
buyer::buyer(int id_produit,int qt_stock,QString nom_produit,QString video,int prix_uni)
{
    this->id_produit=id_produit;
    this->qt_stock=qt_stock;
    this->nom_produit=nom_produit;
    this->video=video;
    this->prix_uni=prix_uni;
}
bool buyer::addbuyer( )
{
    QSqlQuery query;
    QString id_string=QString::number(id_produit);
    QString stock_string=QString::number(qt_stock);
    QString prix_string=QString::number(prix_uni);

       /* QString id_string=QString::number(id);
         QString lastname_string=QString::number(lastname);
          QString name_string=QString::number(name);
           QString adress_string=QString::number(adress);
            QString request_string=QString::number(request);
             QString num_string=QString::number(num);
              QString mail_string=QString::number(mail);*/

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


QSqlQueryModel * buyer::read()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM BUYER");
        /* model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_BUY"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("LASTNAME_BUY"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("NAME_BUY"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESS_BUY"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("REQUEST_BUY"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_BUY"));
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("MAIL_BUY"));*/
return model;
}
QSqlQueryModel*  buyer ::read_id()
{QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select ID_PRODUIT from PRODUITS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PRODUIT"));
return model;
}
QSqlQueryModel * buyer::read1()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PRODUITS");
         return model;
}
bool buyer::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM PRODUITS where id_produit=:id");
    query.bindValue(":id",res);
return query.exec();
}
bool buyer::update(int idRech)
{

    QSqlQuery  query;
    QString res = QString::number(idRech);
    QString stock_string=QString::number(qt_stock);
    QString prix_string=QString::number(prix_uni);
query.prepare("UPDATE BUYER SET nom_pr=:nom,QT_STOCK=:stock,PRIX_UNI=:prix,VIDEO=:video WHERE id_produit=:idRech");
query.bindValue(":idRech",res);
query.bindValue(":nom", nom_produit);
query.bindValue(":stock", stock_string);
query.bindValue(":prix", prix_string);
query.bindValue(":video", video);
return query.exec();
}

