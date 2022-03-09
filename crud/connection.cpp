#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    //db attribut de la classe connection
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("bd");
db.setUserName("yassine");//inserer nom de l'utilisateur
db.setPassword("yassine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
