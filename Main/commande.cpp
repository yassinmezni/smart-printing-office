#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QComboBox>
#include <QTableView>
#include <QTimer>
#include <QDateTime>

Commande::Commande()
{
    ID_CMD=0;
    PRIX=0;
    DATE_COM=" ";
    QT_COMMANDES=0;
};

Commande::Commande(int ID_CMD,float PRIX,QString DATE_COM,int QT_COMMANDES)
{
    this ->ID_CMD=ID_CMD;
    this->PRIX=PRIX;
    this->DATE_COM=DATE_COM;
    this->QT_COMMANDES=QT_COMMANDES;
}


bool Commande::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID_CMD);
    QString fes = QString::number(PRIX);
    QString bes = QString::number(QT_COMMANDES);

    query.prepare("INSERT INTO COMMANDES (ID_COMMANDE,QT_COMMANDES, DATE_COM, PRIX) "
                  "VALUES (:ID_CMD,:QT_COMMANDES, :DATE_COM,:PRIX)");
    query.bindValue(":ID_CMD",res);
    query.bindValue(":PRIX",fes);
    query.bindValue(":DATE_COM",DATE_COM);
    query.bindValue(":QT_COMMANDES",bes);

    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();
    QString date=dateTime.toString();
    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion Commande',:dateTime)");
    qry.bindValue(":dateTime",dateTime);


    qry.exec();

    if(!query.exec())
    {
        qDebug()<<"not added";
    }

    return true;
}

bool Commande::supprimer(int ID_CMD)
{
    QSqlQuery query;
    QString res=QString::number(ID_CMD);

    query.prepare("Delete from commandes where ID_COMMANDE= :ID_CMD");
    query.bindValue(":ID_CMD",res);
    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date=dateTime.toString();

    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression Commande',:dateTime)");
    qry.bindValue(":dateTime",dateTime);

    qry.exec();
    return query.exec();
}

QSqlQueryModel * Commande::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from commandes");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN Client"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Livraison"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID Produit"));

    return model;
}

bool Commande::modifier()
{
    QSqlQuery  query;
    QString id_string=QString::number(ID_CMD);
    QString prix_string=QString::number(PRIX);
    QString qt_string=QString::number(QT_COMMANDES);

    query.prepare("UPDATE COMMANDES SET  PRIX=:prix,DATE_COM=:DATE_COM,QT_COMMANDES=:QT_COMMANDES WHERE ID_COMMANDE=:ID_COMMANDE");
    query.bindValue(":ID_COMMANDE", id_string);
    query.bindValue(":prix", prix_string);
    query.bindValue(":DATE_COM", DATE_COM);
    query.bindValue(":QT_COMMANDES", qt_string);


    QSqlQuery qry;
    QDateTime dateTime=QDateTime::currentDateTime();
    QString date=dateTime.toString();
    qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification Commande',:dateTime)");
    qry.bindValue(":dateTime",dateTime);
    qry.exec();

    return query.exec();
    /*QSqlQueryModel* Commande::combobox_fk();*/

}

// recherche
QSqlQueryModel *Commande::rechercher_ID_CMD(int ID_CMD)
{
    QSqlQueryModel * model1=new QSqlQueryModel();
    QString res=QString::number(ID_CMD);

    model1->setQuery("select * from COMMANDES where ID_COMMANDE LIKE '"+res+"%'");
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN Client"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Livraison"));
    model1->setHeaderData(6, Qt::Horizontal, QObject::tr("ID Produit"));

    return model1;
}

QSqlQueryModel *Commande::rechercherr_QT_COMMANDES(int QT_COMMANDES)
{
    QSqlQueryModel * model1=new QSqlQueryModel();
    QString res=QString::number(QT_COMMANDES);

    model1->setQuery("select * from COMMANDES where QT_COMMANDES LIKE '"+res+"%'");
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN Client"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Livraison"));
    model1->setHeaderData(6, Qt::Horizontal, QObject::tr("ID Produit"));

    return model1;
}

// tri ID_CMD
QSqlQueryModel * Commande::sort_ID_CMD()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from commandes order by ID_COMMANDE ");
    return model;
}


// clear table
void cleartable(QTableView * table );

void Commande::cleartable(QTableView * table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

QSqlQueryModel* Commande::combobox_fk()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select CIN from CLIENTS");
    return model;
}

// tri QT_COMMMANDES
QSqlQueryModel * Commande::sort_QT_COMMANDES()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from commandes order by QT_COMMANDES ");
    return model;
}

// tri function
QSqlQueryModel * Commande::sort_function_cm()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from commandes order by function_cmd  ");
    return model;
}


// clear table
void cleartablee(QTableView * table );

void Commande::cleartablee(QTableView * table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}


QSqlQueryModel * Commande::afficher_historique()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from HISTORIQUE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Activite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date et Heure"));
    return model;
}
