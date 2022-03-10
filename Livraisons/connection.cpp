#include "connection.h"

Connection::Connection()
{}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("bd_projet");//inserer le nom de la source de données ODBC
db.setUserName("iheb");//inserer nom de l'utilisateur
db.setPassword("projet");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
