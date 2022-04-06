#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit1.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_valider_clicked();

    void on_tab_produit_activated(const QModelIndex &index);

    void on_read_clicked();

    void on_supprimer_clicked();

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);





    void on_pushButton_delete_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_2_clicked();

    void on_inserer_photo_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_textHighlighted(const QString &arg1);

    void on_rechercher_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_mail_clicked();

    void on_pb_tri_id_clicked();

    void on_pb_tri_nom_clicked();

    void on_pb_tri_prix_clicked();

    void on_pb_gotomail_clicked();

    void on_pb_video_clicked();

    void on_actionopen_triggered();

    void on_actionplay_triggered();

    void on_actionpause_triggered();

    void on_actionstop_triggered();

    void on_recherche_nom_clicked();

    void on_recherche_prix_clicked();

    void on_loadButton_historique_clicked();

    void on_homeButton_recherche_clicked();
     void on_recherche_par_reference_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    produit b;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;
};

#endif // MAINWINDOW_H
