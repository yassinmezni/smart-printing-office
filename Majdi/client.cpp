#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QDate>



client::client()
{
cin=0; numtel=0; nom=" "; prenom=" "; adresse=" "; mail=" ";
}

client::client(int cin,QString nom,QString prenom,QString adresse,int numtel,QString mail)
{ this->cin=cin ; this->nom=nom ; this->prenom=prenom ; this->adresse=adresse ; this->numtel=numtel; this->mail=mail ;}

int client::getcin(){return cin;}
QString client::getnom(){return nom;}
QString client::getprenom(){return prenom;}
QString client::getadresse(){return adresse;}
int client::getnumtel(){return numtel;}
QString client::getmail(){return mail;}

void client::setcin(int cin){ this->cin=cin;}
void client::setnom(QString nom){this->nom=nom;}
void client::setprenom(QString prenom){this->prenom=prenom;}
void client::setadresse(QString adresse){this->adresse=adresse;}
void client::setnumtel(int numtel){this->numtel=numtel;}
void client::setmail(QString mail){this->mail=mail;}




bool client::ajouter()
{   QSqlQuery query;
    QString res=QString::number(cin);


             query.prepare("INSERT INTO clients ( cin, nom_cl, prenom_cl, adresse_cl, num_tel, mail) "
                           "VALUES (:cin, :nom, :prenom, :adresse, :numtel, :mail)");
             query.bindValue(":cin", res);
             query.bindValue(":nom", nom);
             query.bindValue(":prenom", prenom);
             query.bindValue(":adresse", adresse);
             query.bindValue(":numtel", numtel);
             query.bindValue(":mail", mail);
           return  query.exec();
}
bool client::supprimer(int cin)
{
    QSqlQuery query;
    QString bes=QString::number(cin);

            query.prepare("Delete from clients where CIN=:cin");
            query.bindValue(":cin",bes);
          return  query.exec();
}
QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM clients");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant client"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("numéro du tél"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));


    return model;
}

bool client::modifier(int cin)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
        QString num_string=QString::number(numtel);
    query.prepare("Update clients set NOM_CL=:nom,PRENOM_CL=:prenom,ADRESSE_CL=:adresse,NUM_TEL=:numtel,MAIL=:mail where CIN=:cin");
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":numtel", num_string);
        query.bindValue(":mail",mail);
        query.bindValue(":cin",cin_string);

        return query.exec();
}


QSqlQueryModel* client::Rechercheclient(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM CLIENTS WHERE CIN LIKE '"+recherche+"%' OR NOM_CL LIKE '"+recherche+"%' OR PRENOM_CL LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant client"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("numéro du tél"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

return model;
}





//Trie Par CIN montant
QSqlQueryModel * client::trierclientParCIN_M()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by CIN ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par CIN descendent
QSqlQueryModel * client::trierclientParCIN_D()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by CIN DESC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par Nom
QSqlQueryModel * client::trierclientParNom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by NOM_CL ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}
//trie par prenom
QSqlQueryModel * client::trierclientParPrenom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by PRENOM_CL ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}
