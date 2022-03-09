/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_viedo;
    QLineEdit *lineEdit_stock;
    QPushButton *valider;
    QLineEdit *lineEdit_prix;
    QLabel *label_14;
    QLabel *label_52;
    QPushButton *pushButton;
    QWidget *tab_2;
    QTableView *tab_produit;
    QPushButton *rechercher_2;
    QLineEdit *chercher_id;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *update_video;
    QLineEdit *update_prix;
    QLabel *label_12;
    QLineEdit *update_nom;
    QLabel *label_20;
    QLabel *label_10;
    QLineEdit *update_stock;
    QLabel *label_9;
    QLabel *label_13;
    QPushButton *read;
    QPushButton *pushButton_delete;
    QLineEdit *lineEdit_del;
    QLineEdit *update_id;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1034, 636);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget {\n"
" \n"
" background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #fff, stop: 1 #888) ;/*background: linear-gradient(rgba(0,0,0,.5), rgba(0,0,0,.5)),url(feuille.jpg); \n"
"    background-position: center;\n"
"    background-size: cover;\n"
"    display: flex;\n"
"    justify-content: center;\n"
"    align-items: center;\n"
"    font-family: 'Poppins', sans-serif*/\n"
" \n"
" \n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton {\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background-color:pink\n"
"}\n"
"\n"
" QPushButton:hover:!pressed{ background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF0ECE, stop: 1 #FFFFFF); } \n"
"QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF0ECE, stop: 1 #FFFFFF); }\n"
"/*QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left"
                        ": 20px;\n"
"padding -right: 20px;\n"
"background-color:white\n"
"}*/\n"
""));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1001, 621));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 30, 281, 20));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: black;"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 70, 56, 16));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("color:black;\n"
""));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 120, 111, 21));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: black;"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 170, 56, 16));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color:black;"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 220, 56, 16));
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral("color: black;"));
        lineEdit_id = new QLineEdit(tab);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(180, 70, 113, 22));
        lineEdit_id->setStyleSheet(QStringLiteral(""));
        lineEdit_nom = new QLineEdit(tab);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(180, 120, 113, 22));
        lineEdit_nom->setStyleSheet(QStringLiteral(""));
        lineEdit_viedo = new QLineEdit(tab);
        lineEdit_viedo->setObjectName(QStringLiteral("lineEdit_viedo"));
        lineEdit_viedo->setGeometry(QRect(180, 170, 113, 22));
        lineEdit_viedo->setStyleSheet(QStringLiteral(""));
        lineEdit_stock = new QLineEdit(tab);
        lineEdit_stock->setObjectName(QStringLiteral("lineEdit_stock"));
        lineEdit_stock->setGeometry(QRect(180, 220, 113, 22));
        lineEdit_stock->setStyleSheet(QStringLiteral(""));
        valider = new QPushButton(tab);
        valider->setObjectName(QStringLiteral("valider"));
        valider->setGeometry(QRect(570, 180, 101, 31));
        lineEdit_prix = new QLineEdit(tab);
        lineEdit_prix->setObjectName(QStringLiteral("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(180, 270, 113, 22));
        lineEdit_prix->setStyleSheet(QStringLiteral(""));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(-20, -10, 991, 631));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/lovepik-financial-real-estate-black-gold-background-image_400084852.jpg")));
        label_52 = new QLabel(tab);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(50, 270, 91, 21));
        label_52->setFont(font1);
        label_52->setStyleSheet(QStringLiteral("color: black;"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(790, 460, 161, 28));
        pushButton->setStyleSheet(QLatin1String("QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:rgb(34,36,44);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}"));
        tabWidget->addTab(tab, QString());
        label_14->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        lineEdit_id->raise();
        lineEdit_nom->raise();
        lineEdit_viedo->raise();
        lineEdit_stock->raise();
        valider->raise();
        lineEdit_prix->raise();
        label_52->raise();
        pushButton->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_produit = new QTableView(tab_2);
        tab_produit->setObjectName(QStringLiteral("tab_produit"));
        tab_produit->setGeometry(QRect(10, 10, 1011, 201));
        rechercher_2 = new QPushButton(tab_2);
        rechercher_2->setObjectName(QStringLiteral("rechercher_2"));
        rechercher_2->setGeometry(QRect(150, 460, 93, 28));
        chercher_id = new QLineEdit(tab_2);
        chercher_id->setObjectName(QStringLiteral("chercher_id"));
        chercher_id->setGeometry(QRect(40, 460, 111, 22));
        chercher_id->setStyleSheet(QLatin1String("QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:white\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 280, 56, 16));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color: black;"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(670, 230, 56, 16));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: black;"));
        update_video = new QLineEdit(tab_2);
        update_video->setObjectName(QStringLiteral("update_video"));
        update_video->setGeometry(QRect(790, 290, 113, 22));
        update_video->setStyleSheet(QLatin1String("/*QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:rgb(34,36,44);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}*/"));
        update_prix = new QLineEdit(tab_2);
        update_prix->setObjectName(QStringLiteral("update_prix"));
        update_prix->setGeometry(QRect(790, 380, 113, 22));
        update_prix->setStyleSheet(QLatin1String("/*QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:rgb(34,36,44);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}*/"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(670, 330, 71, 16));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("color: black;"));
        update_nom = new QLineEdit(tab_2);
        update_nom->setObjectName(QStringLiteral("update_nom"));
        update_nom->setGeometry(QRect(790, 260, 113, 22));
        update_nom->setStyleSheet(QLatin1String("/*QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:rgb(34,36,44);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}"));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(670, 380, 71, 21));
        label_20->setFont(font1);
        label_20->setStyleSheet(QStringLiteral("color:black;"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(670, 260, 91, 21));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: black;"));
        update_stock = new QLineEdit(tab_2);
        update_stock->setObjectName(QStringLiteral("update_stock"));
        update_stock->setGeometry(QRect(790, 320, 113, 22));
        update_stock->setStyleSheet(QLatin1String("/*QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:rgb(34,36,44);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(670, 300, 56, 16));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color: black;"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(-320, -30, 1331, 701));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/lovepik-financial-real-estate-black-gold-background-image_400084852.jpg")));
        label_13->setScaledContents(true);
        read = new QPushButton(tab_2);
        read->setObjectName(QStringLiteral("read"));
        read->setGeometry(QRect(430, 340, 93, 28));
        pushButton_delete = new QPushButton(tab_2);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(230, 280, 93, 28));
        lineEdit_del = new QLineEdit(tab_2);
        lineEdit_del->setObjectName(QStringLiteral("lineEdit_del"));
        lineEdit_del->setGeometry(QRect(90, 280, 113, 22));
        lineEdit_del->setStyleSheet(QLatin1String("/*QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:rgb(34,36,44);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}"));
        update_id = new QLineEdit(tab_2);
        update_id->setObjectName(QStringLiteral("update_id"));
        update_id->setGeometry(QRect(790, 220, 113, 22));
        update_id->setStyleSheet(QLatin1String("/*QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border -radius: 20px;\n"
"color: #FFF;\n"
"padding -left: 20px;\n"
"padding -right: 20px;\n"
"background-color:rgb(34,36,44);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(85,170,255);\n"
"background-color: rgb(43,45,56);\n"
"}"));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(810, 490, 93, 28));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(670, 490, 73, 22));
        tabWidget->addTab(tab_2, QString());
        label_13->raise();
        tab_produit->raise();
        rechercher_2->raise();
        chercher_id->raise();
        label_7->raise();
        label_8->raise();
        update_video->raise();
        update_prix->raise();
        label_12->raise();
        update_nom->raise();
        label_20->raise();
        label_10->raise();
        update_stock->raise();
        label_9->raise();
        read->raise();
        pushButton_delete->raise();
        lineEdit_del->raise();
        update_id->raise();
        pushButton_2->raise();
        comboBox->raise();
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1034, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Produits", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Nom produit", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Video", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Stock", Q_NULLPTR));
        valider->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label_14->setText(QString());
        label_52->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Connect to data base ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        rechercher_2->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "stock", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "prix", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "video", Q_NULLPTR));
        label_13->setText(QString());
        read->setText(QApplication::translate("MainWindow", "Read", Q_NULLPTR));
        pushButton_delete->setText(QApplication::translate("MainWindow", "delete", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Update", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Read", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
