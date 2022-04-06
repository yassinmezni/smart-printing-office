#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qrcode.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_tab_employee_activated(const QModelIndex &index);

    void on_pb_update_clicked();

    void on_pushButton_clicked();

    //void on_radioButton_tri_personnel_clicked();

    void on_qrCode_linkActivated(const QString &link);
//***********************TRI****************************
    void on_radioButton_tri_personnel_3_clicked();

    void on_radioButton_tri_personnel_2_clicked();

    void on_radioButton_tri_personnel_4_clicked();

//******************************************************
    void on_pb_update_2_rechercher_2_clicked();

    void on_pushButton_2_clicked();


 void on_recherche_par_reference_2_textChanged(const QString &arg1);
 void on_qrCode_clicked();


 //void on_loadButton_historique_clicked();

 void on_loadButton_historique_clicked();

 void on_homeButton_recherche_clicked();


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
        //***********************

};

#endif // MAINWINDOW_H
