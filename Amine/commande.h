#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtDebug>
class Commande
{

public:
    Commande();
    Commande(int,int,QString,float);


    void setID_CMD(int id)
    {
        ID_CMD=id;
    }

    void setDATE_COM(QString date)
    {
        DATE_COM=date;
    }

    void setQT_COMMANDES(int qt)
    {
        QT_COMMANDES=qt;
    }

    void setPRIX(float p)
    {
        PRIX=p;
    }

    int getID_CMD(){return ID_CMD;}
    QString getDATE_COM(){return DATE_COM;}
    int getQT_COMMANDES(){return QT_COMMANDES;}
    float getPRIX(){return PRIX;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

private:
    int ID_CMD;
    int QT_COMMANDES;
    float PRIX;
    QString DATE_COM;
};

#endif // COMMANDE_H
