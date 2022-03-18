#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;//attribut de la classe connection
public:
    Connection();
    bool createconnect();
    void closeconnect();
};

#endif // CONNECTION_H
