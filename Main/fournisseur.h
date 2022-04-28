#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class Fournisseur
{
    QString nom_fourn,mail_fourn,adresse_fourn,date;
    int reference,gsm_fourn;

public:
    //Constructeurs
    Fournisseur();
    Fournisseur(int,QString,QString,int,QString);

    //Getters
    int getRef(){return reference;}
    QString getNom_fourn(){return nom_fourn;}
    QString getMail_fourn(){return mail_fourn;}
    int getGSM(){return gsm_fourn;}
    QString getAdresse_fourn(){return adresse_fourn;}


    //Setters
    void setRef(int Ref)
    {
        reference=Ref;
    }

    void setNom_fourn(QString nom)
    {
        nom_fourn=nom;
    }

    void setMail_fourn(QString mail)
    {
        mail_fourn=mail;
    }

    void setGSM(int gsm)
    {
        gsm_fourn=gsm;
    }

    void setAdresse_fourn(QString adresse)
    {
        adresse_fourn=adresse;
    }


    //Fonctionalités de base relatives à l'éntité Fournisseur
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * Recherchefournisseur(QString recherche);

    QSqlQueryModel * RechercheLogin(QString login, QString pass);

    QSqlQueryModel * trier_ref();
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_email();
    QSqlQueryModel * afficher_historique();
};

#endif // FOURNISSEUR_H
