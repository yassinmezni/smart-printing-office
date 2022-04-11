#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtDebug>
#include <QTableView>
#include<QSystemTrayIcon>


class Commande
{

public:




    Commande();
    Commande(int,float,QString,int,int,int,int);


    void setID_CMD(int id)
    {
        ID_CMD=id;
    }

    void setPRIX(float p)
    {
        PRIX=p;
    }
    void setDATE_COM(QString date)
    {
        DATE_COM=date;
    }

    void setQT_COMMANDES(int qt)
    {
        QT_COMMANDES=qt;
    }

    QSqlQueryModel * sort_ID_CMD();
    QSqlQueryModel * sort_QT_COMMANDES();
    QSqlQueryModel * sort_function_cm();
    QSqlQueryModel * sort_function_cmd();
    QSqlQueryModel * afficher_historique();
     void cleartable(QTableView * table );
     void cleartablee(QTableView * table );
     void rechercher_ID_CMD(QTableView *table, int x);
     void rechercherr_QT_COMMANDES(QTableView *table, int x);
     void rechrcherr_PRIX(QTableView *table, int x);
    int getID_CMD(){return ID_CMD;}
    float getPRIX(){return PRIX;}
    QString getDATE_COM(){return DATE_COM;}
    int getQT_COMMANDES(){return QT_COMMANDES;}
    int getID_CL(){return ID_CL;}
    int getFK_LIVRAISON(){return FK_LIVRAISON;}
    int getFK_PRODUIT(){return FK_PRODUIT;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* combobox_fk();
private:
    int ID_CMD;
    float PRIX;
    QString DATE_COM;
    int QT_COMMANDES;
    int ID_CL;
    int FK_LIVRAISON;
    int FK_PRODUIT;

};

#endif // COMMANDE_H
