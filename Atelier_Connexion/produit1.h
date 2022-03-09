#ifndef BUYER_H
#define BUYER_H
#include <QString>
#include <QtSql>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>


class produit
{
public:
   produit ();
   produit (int,int,QString,QString,int );
   int getID(){return id_produit;}
   QString getNAME(){return nom_produit;}
   QString getVIDEO(){return video;}
   int getSTOCK(){return qt_stock;}
   int getPRIX(){return prix_uni;}


   void setID(int id){this->id_produit=id;}
   void setNAME(QString l){nom_produit=l;}
   void setVIDEO(QString n){video=n;}
   void setSTOCK(int a){qt_stock=a;}


   void setPRIX(int num){this->prix_uni=num;}

  bool add ();
  QSqlQueryModel* read();
  QSqlQueryModel* read1();
  QSqlQueryModel* read_id();
  bool supprimer(int);
  bool update(int);  //authentification

private:
  int id_produit,qt_stock;
  QString nom_produit,video;
  int prix_uni;
};
#endif // PROPERTY_H
