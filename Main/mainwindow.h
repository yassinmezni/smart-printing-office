#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include "fournisseur.h"
#include "arduino.h"
#include "produit.h"
#include "client.h"
#include "employee.h"
#include "qrcode.h"
#include "livraison.h"
#include "commande.h"
#include "statistic.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//***********camera*******
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
//************************

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*LOGIN + FOURNISSEURS*/
    void on_QuitterButton_clicked();

    int on_LoginButton_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_ajouterButton_clicked();

    void on_supprimerButton_2_clicked();

    void on_modifierButton_clicked();

    void on_homeButton_ajouter_clicked();

    void on_pushButton_12_clicked();

    void on_fournisseurButton_clicked();

    void on_clButton_clicked();

    void on_prodButton_clicked();

    void on_cmdButton_clicked();

    void on_livrButton_clicked();

    void on_empButton_clicked();

    void on_homeButton_clicked();

    void on_homeButton_2_clicked();

    void on_homeButton_3_clicked();

    void on_homeButton_4_clicked();

    void on_homeButton_5_clicked();

    void on_homeButton_modifier_clicked();

    void on_homeButton_rechercher_clicked();

    void on_livrButton_3_clicked();

    void on_homeButton_14_clicked();

    void on_pushButton_14_clicked();

    void on_fournisseurButton_3_clicked();

    void on_empButton_3_clicked();

    void on_clButton_3_clicked();

    void on_prodButton_3_clicked();

    void on_cmdButton_3_clicked();

    void on_clButton_4_clicked();

    void on_prodButton_4_clicked();

    void on_cmdButton_4_clicked();

    void on_livrButton_4_clicked();

    void on_empButton_4_clicked();

    void on_fournisseurButton_4_clicked();

    void on_pushButton_15_clicked();

    void on_homeButton_16_clicked();

    void on_homeButton_17_clicked();

    void on_homeButton_18_clicked();

    void on_homeButton_19_clicked();

    void on_homeButton_ajouter_4_clicked();

    void on_homeButton_modifier_4_clicked();

    void on_ajouterButton_4_clicked();

    void on_supprimerButton_5_clicked();

    void on_tableView_9_activated(const QModelIndex &index);

    void on_modifierButton_4_clicked();

    void on_LoadButton_clicked();

    void on_LoadButton_2_clicked();

    void on_PDFButton_clicked();

    void on_PDFButton_4_clicked();

    void on_trier_button_clicked();

    void on_TrierButton_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_LoadButton_Historique_clicked();

    void on_recherche_par_reference_2_textChanged(const QString &arg1);

    void update_label();

    void on_recherche_par_reference_4_textChanged(const QString &arg1);

    void on_Button_clicked();

    void on_CloseButton_clicked();

    /*PRODUITS*/
    void on_homeButton_6_clicked();

    void on_homeButton_7_clicked();

    void on_homeButton_8_clicked();

    void on_homeButton_9_clicked();

    void on_valider_clicked();

    void on_comboBox_5_currentIndexChanged(int index);

    void on_pushButton_delete_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_mail_clicked();

    void on_recherche_par_reference_3_textChanged(const QString &arg1);

    void on_read_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pb_gotomail_clicked();

    void on_loadButton_historique_clicked();

    void on_actionNew_User_triggered();

    void on_actionstop_triggered();

    void on_actionpause_triggered();

    void on_actionplay_triggered();

    /*CLIENTS*/

    void on_addbutton_2_clicked();

    void on_deletebutton_3_clicked();

    void on_table_client_2_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_lineEdit_recherche_client_2_textChanged(const QString &arg1);

    void on_comboBox_tri_2_activated(const QString &arg1);

    void on_loadButton_historique_2_clicked();

    void on_excel_button_2_clicked();

    void on_deletebutton_4_clicked();

    /*EMPLOYEES*/

    void on_pb_ajouter_3_clicked();

    void on_pb_supprimer_2_clicked();

    void on_LoadButton_Historique_3_clicked();

    void on_pb_update_2_clicked();

    void on_tab_employee_2_activated(const QModelIndex &index);

    void on_radioButton_tri_personnel_7_clicked();

    void on_radioButton_tri_personnel_5_clicked();

    void on_radioButton_tri_personnel_6_clicked();

    void on_recherche_par_reference_6_textChanged(const QString &arg1);

    void on_qrCode_2_clicked();

    void on_homeButton_recherche_2_clicked();

    /*LIVRAISONS*/

    void on_ajouter_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_table_livraison_activated(const QModelIndex &index);

    void on_recherche_textChanged(const QString &arg1);

    void on_supprimer2_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_tri_activated(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_homeButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_pb_Ajouter_2_clicked();

    void on_modifierButton_5_clicked();

    void on_pushButton_11_clicked();

    void on_tableView_aff_2_activated(const QModelIndex &index);

    void on_modifierButton_recherche_3_clicked();

    void on_modifierButton_recherche_4_clicked();

    void on_supp_Button_3_clicked();

    void on_pushButton_10_clicked();

    void on_loadButton_historique_3_clicked();

    void on_pushButton_stat_2_clicked();

    void on_Paffiche_2_clicked();

    void on_homeButton_10_clicked();

    void on_homeButton_12_clicked();

    void on_homeButton_45_clicked();

    void on_homeButton_46_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_40_clicked();

    void on_ajouter_5_clicked();

    void on_pushButton_38_clicked();

    void on_table_livraison_5_activated(const QModelIndex &index);

    void on_supprimer2_5_clicked();

    void on_comboBox_tri_8_activated(const QString &arg1);

    void on_pushButton_39_clicked();

    void on_recherche_5_textChanged(const QString &arg1);

    void on_pushButton_42_clicked();



    void on_addbutton_3_clicked();

    void on_pushButton_8_clicked();

    void on_deletebutton_5_clicked();

    void on_excel_button_3_clicked();

    void on_deletebutton_6_clicked();

    void on_comboBox_tri_3_activated(const QString &arg1);

    void on_homeButton_25_clicked();

    void on_homeButton_26_clicked();

    void on_loadButton_historique_4_clicked();

    void on_table_client_3_activated(const QModelIndex &index);

    void on_tab_produit_activated(const QModelIndex &index);

    void on_valider_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_delete_2_clicked();

    void on_comboBox_9_currentIndexChanged(int index);

    void on_tab_produit_2_activated(const QModelIndex &index);

    void on_recherche_par_reference_5_textChanged(const QString &arg1);

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_4_clicked();

    void on_read_2_clicked();

    void on_pb_gotomail_2_clicked();

    void on_pushButton_mail_2_clicked();

    void on_loadButton_historique_5_clicked();

    void on_homeButton_21_clicked();

    void on_homeButton_20_clicked();

    void on_homeButton_15_clicked();

    void on_lineEdit_recherche_client_3_textChanged(const QString &arg1);

    void on_ajouter_2_clicked();

    void on_pushButton_17_clicked();

    void on_supprimer2_2_clicked();

    void on_table_livraison_2_activated(const QModelIndex &index);

    void on_comboBox_tri_4_activated(const QString &arg1);

    void on_recherche_2_textChanged(const QString &arg1);

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_homeButton_24_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pb_Ajouter_3_clicked();

    void on_modifierButton_7_clicked();

    void on_supp_Button_4_clicked();

    void on_homeButton_22_clicked();

    void on_tableView_aff_3_activated(const QModelIndex &index);

    void on_pushButton_16_clicked();

    void on_pushButton_13_clicked();

    void on_modifierButton_recherche_5_clicked();

    void on_modifierButton_recherche_6_clicked();

    void on_Paffiche_3_clicked();

    void on_loadButton_historique_6_clicked();

    void on_pushButton_stat_3_clicked();

    void on_homeButton_23_clicked();

private:
    Ui::MainWindow *ui;
    //***********camera*******
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mlayout;
    QMenu *mOptionsMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mcapturerAction;
    //**********Video*********
    QMediaPlayer* player/*,*p*/;
    QVideoWidget* vw/*,*v*/;
    QProgressBar* bar/*,*bar2*/;
    QSlider* slider/*,*slider2*/;

    Fournisseur Ftmp;
    produit b;
    client c;
    Employee E;
    livraison L;
    Commande Ctmp;
    Statistic *statistic;
    QByteArray data; //variable contenant les données reçues
    Arduino A;

};
#endif // MAINWINDOW_H
