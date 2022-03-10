#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
Commande::Commande()
{
 ID_CMD=0;  PRIX=0;DATE_COM=" ";QT_COMMANDES=0;
}
 Commande::Commande(int ID_CMD,int QT_COMMANDES,QString DATE_COM,float PRIX)
 {
     this ->ID_CMD=ID_CMD;
     this->DATE_COM=DATE_COM;
     this->PRIX=PRIX;
     this->QT_COMMANDES=QT_COMMANDES;
 }



bool Commande::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID_CMD);
    QString bes = QString::number(QT_COMMANDES);
    QString fes = QString::number(PRIX);

    query.prepare("INSERT INTO COMMANDES (ID_COMMANDE,QT_COMMANDES, DATE_COM, PRIX) "
                          "VALUES (:ID_CMD,:QT_COMMANDES, :DATE_COM,:PRIX)");
    query.bindValue(":ID_CMD",res);
    query.bindValue(":QT_COMMANDES",bes);
    query.bindValue(":PRIX",fes);
    query.bindValue(":DATE_COM",DATE_COM);


        if(!query.exec()){
            qDebug()<<"not added";
        }
        return true;
}



QSqlQueryModel * Commande::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from commandes");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CMD"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_COM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QT_COMMANDES"));


    return model;
}


bool Commande::supprimer(int ID_CMD)
{
   QSqlQuery query;
   QString res=QString::number(ID_CMD);

   query.prepare("Delete from commandes where ID_COMMANDE= :ID_CMD");
   query.bindValue(":ID_CMD",res);

   return query.exec();
}

bool Commande::modifier()
{




        QSqlQuery  query;
        QString id_string=QString::number(ID_CMD);
        QString qt_string=QString::number(QT_COMMANDES);
        QString prix_string=QString::number(PRIX);
        query.prepare("UPDATE COMMANDES SET  PRIX=:prix,DATE_COM=:DATE_COM,QT_COMMANDES=:QT_COMMANDES WHERE ID_COMMANDE=:ID_COMMANDE");
        query.bindValue(":ID_COMMANDE", id_string);
        query.bindValue(":prix", prix_string);
        query.bindValue(":DATE_COM", DATE_COM);
        query.bindValue(":QT_COMMANDES", qt_string);

        return query.exec();

}


