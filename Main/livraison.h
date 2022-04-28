#ifndef LIVRAISON_H
#define LIVRAISON_H
#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>



class livraison
{
public:
    livraison();
    livraison (int id,QString date,QString localisation,int frais);

    /*getters*/
    int getid();
    QString getdate();
    QString getlocalisation();
    int getfrais();

    /*setters*/
    void setid(int);
    void setdate(QString);
    void setlocalisation(QString);
    void setfrais(int);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* Recherchelivreur(QString);
    QSqlQueryModel * trierlivraisonParid_M();
    QSqlQueryModel * trierlivraisonParid_D();
    QSqlQueryModel * trierlivraisonParlocalisation();
    QSqlQueryModel * trierlivraisonParfrais_M();
    QSqlQueryModel * afficherhistorique();

private:
    int id,frais;
    QString localisation, date;
};

#endif // LIVRAISON_H
