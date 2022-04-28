#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include<QString>
#include <QSqlQueryModel>

class Employee
{
public:
    //Constructeur par défaut
    Employee();
    //Constructeur parametrique qui prend par défaut le matricule,...
    Employee(int,QString,QString,QString,int,QString,int);

    //Getters
    int     getMatricule(); // me retourner un entier
    QString getNom();       // me retourner une chaine de caractere
    QString getPrenom();    // me retourner une chaine de caractere
    QString getMail();      // me retourner une chaine de caractere
    int     getGSM();       // me retourner un entier
    QString getRole();      // me retourner une chaine de caractere
    int     getSalaire();   // me retourner un entier
    //Setters
    void setMatricule(int);
    void setNom(QString);
    void setPrenom(QString);
    void setMail(QString);
    void setGSM(int);
    void setRole(QString);
    void setSalaire(int);
    //fonctionnalités de base relatives a l'entité employe

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    bool update(int);
    QSqlQueryModel * Rechercheemployee(QString recherche);
    //******************TRIER************************************************
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel *Tri_nom();
    QSqlQueryModel *  trierr(const QString &critere, const QString &mode );
    QSqlQueryModel * afficher_tri_gsm();
    QSqlQueryModel * afficher_tri_matricule();
    //**********************************************************************
    QSqlQueryModel * afficher_historique();

private:
    int Matricule,GSM,Salaire;
    QString Nom,Prenom,Mail,Role;

};

#endif // EMPLOYEE_H
