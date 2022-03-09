#include "connection.h"

Connection::Connection()
{}

bool Connection::createconnect()
{
db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("Soumaya");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
void Connection::closeconnect(){db.close();}
