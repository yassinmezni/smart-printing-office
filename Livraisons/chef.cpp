#include "chef.h"
#include "ui_chef.h"
#include <QMessageBox>
#include <QDebug>

Chef::Chef(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chef)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Chef::~Chef()
{
    delete ui;
}


void Chef::on_pushButton_12_clicked()
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

void Chef::on_prodButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Chef::on_cmdButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Chef::on_clButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Chef::on_livrButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Chef::on_empButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Chef::on_fournisseurButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Chef::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Chef::on_homeButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void Chef::on_ajouter_clicked()
{

}
