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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *le_id;
    QLineEdit *le_prix;
    QLineEdit *le_DATE;
    QLineEdit *le_Quantite;
    QPushButton *pb_Ajouter;
    QComboBox *comboBox_2;
    QWidget *tab_2;
    QTableView *tableView_aff;
    QPushButton *pushButton;
    QWidget *tab_3;
    QLabel *supp_text;
    QPushButton *supp_Button;
    QLineEdit *supprimer_id;
    QWidget *tab_4;
    QLineEdit *le_id_2;
    QLabel *label_5;
    QLineEdit *le_prix_2;
    QLabel *label_6;
    QLineEdit *le_DATE_2;
    QLineEdit *le_Quantite_2;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *modifierButton;
    QComboBox *combobox_fk;
    QRadioButton *radioButton_tri_personnel;
    QMenuBar *menuBar;
    QMenu *menuCommandes;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(791, 487);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 731, 421));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(0, 0, 521, 211));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 91, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 91, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 71, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 120, 91, 16));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(120, 30, 113, 20));
        le_prix = new QLineEdit(groupBox);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(120, 60, 113, 20));
        le_DATE = new QLineEdit(groupBox);
        le_DATE->setObjectName(QStringLiteral("le_DATE"));
        le_DATE->setEnabled(true);
        le_DATE->setGeometry(QRect(120, 90, 113, 20));
        le_Quantite = new QLineEdit(groupBox);
        le_Quantite->setObjectName(QStringLiteral("le_Quantite"));
        le_Quantite->setGeometry(QRect(120, 120, 113, 20));
        pb_Ajouter = new QPushButton(groupBox);
        pb_Ajouter->setObjectName(QStringLiteral("pb_Ajouter"));
        pb_Ajouter->setGeometry(QRect(250, 140, 75, 23));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(320, 60, 81, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView_aff = new QTableView(tab_2);
        tableView_aff->setObjectName(QStringLiteral("tableView_aff"));
        tableView_aff->setGeometry(QRect(10, 10, 411, 192));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 230, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        supp_text = new QLabel(tab_3);
        supp_text->setObjectName(QStringLiteral("supp_text"));
        supp_text->setGeometry(QRect(60, 80, 191, 16));
        supp_Button = new QPushButton(tab_3);
        supp_Button->setObjectName(QStringLiteral("supp_Button"));
        supp_Button->setGeometry(QRect(190, 120, 75, 23));
        supprimer_id = new QLineEdit(tab_3);
        supprimer_id->setObjectName(QStringLiteral("supprimer_id"));
        supprimer_id->setGeometry(QRect(280, 80, 113, 20));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        le_id_2 = new QLineEdit(tab_4);
        le_id_2->setObjectName(QStringLiteral("le_id_2"));
        le_id_2->setGeometry(QRect(120, 50, 81, 20));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 50, 91, 16));
        le_prix_2 = new QLineEdit(tab_4);
        le_prix_2->setObjectName(QStringLiteral("le_prix_2"));
        le_prix_2->setGeometry(QRect(120, 80, 81, 20));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 80, 91, 16));
        le_DATE_2 = new QLineEdit(tab_4);
        le_DATE_2->setObjectName(QStringLiteral("le_DATE_2"));
        le_DATE_2->setGeometry(QRect(120, 110, 81, 20));
        le_Quantite_2 = new QLineEdit(tab_4);
        le_Quantite_2->setObjectName(QStringLiteral("le_Quantite_2"));
        le_Quantite_2->setGeometry(QRect(120, 140, 81, 20));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 110, 71, 16));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 140, 91, 16));
        modifierButton = new QPushButton(tab_4);
        modifierButton->setObjectName(QStringLiteral("modifierButton"));
        modifierButton->setGeometry(QRect(30, 180, 75, 23));
        combobox_fk = new QComboBox(tab_4);
        combobox_fk->setObjectName(QStringLiteral("combobox_fk"));
        combobox_fk->setGeometry(QRect(291, 80, 91, 22));
        radioButton_tri_personnel = new QRadioButton(tab_4);
        radioButton_tri_personnel->setObjectName(QStringLiteral("radioButton_tri_personnel"));
        radioButton_tri_personnel->setGeometry(QRect(430, 130, 83, 18));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 791, 22));
        menuCommandes = new QMenu(menuBar);
        menuCommandes->setObjectName(QStringLiteral("menuCommandes"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCommandes->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ID_COMMANDE", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "PRIX", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "DATE_COM", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "QT_COMMANDES", Q_NULLPTR));
        pb_Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter Commande", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "tri id", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher Commande", Q_NULLPTR));
        supp_text->setText(QApplication::translate("MainWindow", "Saisie l'id du commande \303\240 supprimer :", Q_NULLPTR));
        supp_Button->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Supprimer Commande", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ID_COMMANDE", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "PRIX", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "DATE_COM", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "QT_COMMANDES", Q_NULLPTR));
        modifierButton->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        radioButton_tri_personnel->setText(QApplication::translate("MainWindow", "RadioButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Modifier ", Q_NULLPTR));
        menuCommandes->setTitle(QApplication::translate("MainWindow", "Commandes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
