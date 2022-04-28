#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QTableView>
#include <QSystemTrayIcon>


class Commande
{
public:
    Commande();
    Commande(int,float,QString,int);
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
    int getID_CMD()
    {
        return ID_CMD;
    }
    float getPRIX()
    {
        return PRIX;
    }
    QString getDATE_COM()
    {
        return DATE_COM;
    }
    int getQT_COMMANDES()
    {
        return QT_COMMANDES;
    }

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * sort_ID_CMD();
    QSqlQueryModel * sort_QT_COMMANDES();
    QSqlQueryModel * sort_function_cm();
    QSqlQueryModel * sort_function_cmd();
    QSqlQueryModel * afficher_historique();
    void cleartable(QTableView * table );
    void cleartablee(QTableView * table );
    QSqlQueryModel *rechercher_ID_CMD(int ID_CMD);
    QSqlQueryModel *rechercherr_QT_COMMANDES(int QT_COMMANDES);
    void rechrcherr_PRIX(QTableView *table, int x);
    QSqlQueryModel* combobox_fk();

private:
    int ID_CMD;
    float PRIX;
    QString DATE_COM;
    int QT_COMMANDES;
};

#endif // COMMANDE_H
