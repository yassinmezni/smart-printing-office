#include "connection.h"
#include<QtDebug>
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase bd = QSqlDatabase::addDatabase("QODBC");

    bd.setDatabaseName("bd1");
    bd.setUserName("amine");//inserer nom de l'utilisateur
    bd.setPassword("amine");//inserer mot de passe de cet utilisateur

 if (bd.open())
{
  test=true;
}
    return  test;
}

void Connection::closeConnection()
{
    bd.close();
}
