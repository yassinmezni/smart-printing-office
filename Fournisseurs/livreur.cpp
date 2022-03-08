#include "livreur.h"
#include "ui_livreur.h"
#include <QMessageBox>
#include <QDebug>

Livreur::Livreur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Livreur)
{
    ui->setupUi(this);
}

Livreur::~Livreur()
{
    delete ui;
}

void Livreur::on_livrButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Livreur::on_deconnecterButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    } else
    {
        qDebug() <<"No is clicked";
    }
}

void Livreur::on_homeButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
