#include "connection.h"

Connection::Connection()
{}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("projett");//inserer le nom de la source de données ODBC
db.setUserName("djo");//inserer nom de l'utilisateur
db.setPassword("majdi");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
