#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>


class client
{
public:
    client();
    client (int cin,QString nom,QString prenom,QString adresse,int numtel,QString mail);

    /*getters*/
    int getcin();
    QString getnom();
    QString getprenom();
    QString getadresse();
    int getnumtel();
    QString getmail();

    /*setters*/
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setnumtel(int);
    void setmail(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* Rechercheclient(QString);
    QSqlQueryModel * trierclientParCIN_M();
    QSqlQueryModel * trierclientParCIN_D();
    QSqlQueryModel * trierclientParNom();
    QSqlQueryModel * trierclientParPrenom();

private:
    int cin,numtel ;
    QString nom, prenom, adresse, mail;

};

#endif // CLIENT_H
