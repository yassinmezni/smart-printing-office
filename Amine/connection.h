#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase bd;
public:
    Connection();
    QSqlDatabase getdb()
    {
        return bd;
    }
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
