#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //***camera****
     a.setStyle("fusion");

    Connection c;  //une seule instance de la classe connection
    bool test=c.createconnect();//etablir la connexion
    MainWindow w;


    if(test)       //si la connexion est etablie
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else          // si la connexion est echoué
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();//La méthode exec() : Envoie la requête pour l’exécuter.
}
