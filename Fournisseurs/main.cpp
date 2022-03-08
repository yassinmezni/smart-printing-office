#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;

    bool test=c.createconnect();
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Smart Printing System"), QObject::tr("Connection successful.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"), QObject::tr("Connection failed.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
