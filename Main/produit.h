#ifndef PRODUIT_H
#define PRODUIT_H
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
    produit();
    produit (int,int,int,QString,QString,int );
    int getID()
    {
        return id_produit;
    }
    QString getNAME()
    {
        return nom_produit;
    }
    QString getVIDEO()
    {
        return video;
    }
    int getSTOCK()
    {
        return qt_stock;
    }
    int getPRIX()
    {
        return prix_uni;
    }


    void setID(int id)
    {
        this->id_produit=id;
    }
    void setNAME(QString l)
    {
        nom_produit=l;
    }
    void setVIDEO(QString n)
    {
        video=n;
    }
    void setSTOCK(int a)
    {
        qt_stock=a;
    }
    void setPRIX(int num)
    {
        this->prix_uni=num;
    }

   bool ajouter ();
   QSqlQueryModel* afficher();
   QSqlQueryModel* afficher_id();
   QSqlQueryModel* combobox_fk();
   bool supprimer(int);
   bool update(int);
   QSqlQueryModel * rechercher(int );
   QSqlQueryModel * rechercher_nom(QString );
   QSqlQueryModel * rechercher_prix(int );
   QSqlQueryModel * Rechercheproduit(QString recherche);
   QSqlQueryModel * tri_id();
   QSqlQueryModel * tri_prix();
   QSqlQueryModel * Tri_nom();
   QSqlQueryModel * trierr(const QString &critere, const QString &mode );
   QSqlQueryModel * afficher_email();
   QSqlQueryModel * afficher_historique();

private:
   int id_produit,qt_stock,FK_FOURNISSEUR_PR;
   QString nom_produit,video;
   int prix_uni;
};

#endif // PRODUIT_H
