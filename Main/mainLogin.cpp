#include "mainwindow.h"
#include "ui_mainwindow.h"




/*LOGIN*/
void MainWindow::on_QuitterButton_clicked()
{
    /*
        void about
        void aboutQt
        StandardButton critical
        StandardButton information
        StandardButton question
        StandardButton warning
    */

    QString quitter=ui->comboBox_3->currentText();

    if (quitter=="Francais")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Êtes-vous sûr ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            QApplication::quit();
        } else
        {
            qDebug() <<"No is clicked";
        }
    }
    else if (quitter=="English")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Are you sure ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            QApplication::quit();
        } else
        {
            qDebug() <<"No is clicked";
        }
    }
    else if (quitter=="Espagnol")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Smart Printing System","Está usted seguro ?", QMessageBox::Yes | QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            ui->statusbar->clearMessage();
            QApplication::quit();
        } else
        {
            qDebug() <<"No is clicked";
        }
    }

}


int MainWindow::on_LoginButton_clicked()
{
    QString nom_utilisateur = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    int etat=0;


    if (nom_utilisateur == "admin" && password == "admin")
    {
        ui->stackedWidget->setCurrentIndex(1);
        etat=1; //chef
    }
    else if (nom_utilisateur == "simple" && password == "simple")
    {
        ui->stackedWidget->setCurrentIndex(3);
        etat=2; //simple
    }
    else if (nom_utilisateur == "livreur" && password == "livreur")
    {
        ui->stackedWidget->setCurrentIndex(2);
        etat=3; //livreur
    }
    else
    {
        QString conn=ui->comboBox_3->currentText();

        if (conn=="Francais")
        {
            QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"),
                QObject::tr("Le nom d'utilisateur ou le mot de passe que \n"
                            "vous avez saisi(e) n’est pas associé(e) à un compte.\n"
                            "Trouvez votre compte et connectez-vous.\n"), QMessageBox::Cancel);
        }
        else if (conn=="English")
        {
            QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"),
                QObject::tr("The username or password that you \n"
                            "entered is not associated with an account.\n"
                            "Find your account and sign in.\n"), QMessageBox::Cancel);
        }
        else if (conn=="Espagnol")
        {
            QMessageBox::critical(nullptr, QObject::tr("Smart Printing System"),
                QObject::tr("El nombre de usuario o contraseña\n"
                            "que ingresó no está asociado con una cuenta.\n"
                            "Encuentra tu cuenta e inicia sesión.\n"), QMessageBox::Cancel);
        }
    }

    if (nom_utilisateur.isEmpty() || password.isEmpty())
    {
        QString empt=ui->comboBox_3->currentText();

        if (password.isEmpty() && nom_utilisateur.isEmpty())
        {
            if (empt=="Francais")
            {
                QMessageBox::warning(this, tr("Champ vide"),
                        tr("Veuillez saisir votre nom \nd'utilisateur et mot de passe."));
            }
            else if (empt=="English")
            {
                QMessageBox::warning(this, tr("Empty field"),
                        tr("Please enter your \nusername and password."));
            }
            else if (empt=="Espagnol")
            {
                QMessageBox::warning(this, tr("Campo vacío"),
                        tr("Por favor introduzca su nombre \nde usuario y contraseña."));
            }

        }
        else if (nom_utilisateur.isEmpty())
        {
            if (empt=="Francais")
            {
                QMessageBox::warning(this, tr("Champ vide"),
                        tr("Veuillez saisir votre nom d'utilisateur."));
            }
            else if (empt=="English")
            {
                QMessageBox::warning(this, tr("Empty field"),
                        tr("Please enter your username."));
            }
            else if (empt=="Espagnol")
            {
                QMessageBox::warning(this, tr("Campo vacío"),
                        tr("Por favor introduzca su nombre de usuario."));
            }
        }
        else if (password.isEmpty())
        {
            if (empt=="Francais")
            {
                QMessageBox::warning(this, tr("Champ vide"),
                        tr("Veuillez saisir votre mot de passe."));
            }
            else if (empt=="English")
            {
                QMessageBox::warning(this, tr("Empty field"),
                        tr("Please enter your password."));
            }
            else if (empt=="Espagnol")
            {
                QMessageBox::warning(this, tr("Campo vacío"),
                        tr("Por favor introduzca su contraseña."));
            }

        }
    }
    return etat;
}




//TRADUCTION
void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
   if(index == 0) //fr
   {
       //LOGIN * LOGIN * LOGIN * LOGIN * LOGIN * LOGIN
       ui->langue->setText("Langue :");
       ui->nom_utilisateur_3->setText("Nom utilisateur : ");
       ui->label_35->setText("Mot de passe :");
       ui->lineEdit_username->setPlaceholderText("Nom d'utilisateur");
       ui->lineEdit_password->setPlaceholderText("Mot de passe");
       ui->LoginButton->setText("Se connecter");
       ui->QuitterButton->setText("Quitter");




       //CHEF * CHEF * CHEF * CHEF * CHEF * CHEF
       //Chef->Home
       ui->label->setText("Bienvenue, vous êtes le chef !!");
       ui->prodButton->setText("Produits");
       ui->livrButton->setText("Livraisons");
       ui->empButton->setText("Employées");
       ui->fournisseurButton->setText("Fournisseurs");
       ui->cmdButton->setText("Commandes");
       ui->clButton->setText("Clients");
       ui->pushButton_12->setText("Déconnecter");

       //Chef->Fournisseurs
       ui->Lesfournisseurs->setText("Les fournisseurs");
       ui->tabWidget->setTabText(0,"Ajoutez un fournisseur");
       ui->tabWidget->setTabText(1,"Gestion des fournisseurs");
       ui->tabWidget->setTabText(2,"Historique de contrôle");
       ui->tabWidget->setTabText(3,"Parking");
       //Chef->Fournisseurs->Insertion
       ui->textajoutezfournisseur->setText("Ajoutez un fournisseur :");
       ui->label_9->setText("Référence :");//ref
       ui->label_10->setText("Nom Fournisseur :");//nom
       ui->label_11->setText("GSM Fournisseur :");//gsm
       ui->label_12->setText("Mail Fournisseur :");//mail
       ui->label_17->setText("Adresse Fournisseur :");//adresse
       ui->ajouterButton->setText("Ajouter");
       ui->label_13->setText("* La référence est un nombre positive.");
       ui->label_8->setText("* La 1ére lettre du nom de fournissuer doit être en majuscule.");
       ui->label_14->setText("* Le GSM du fournisseur est nombre positive qui contient que 8 chiffres.");
       ui->label_15->setText("* L'email du fournisseur obéit à sa forme générale.");
       ui->label_16->setText("* L'adresse du fournisseur peut contient des chiffres, des lettres et de symboles.");
       ui->homeButton_ajouter->setText("Menu");
       //Chef->Fournisseurs->Gestion
       ui->nb->setText("NB: Double click sur la référence du fournisseur à modifier où supprimer ");
       ui->saisir_r->setText("Saisir la référence du fournisseur à chercher :");
       ui->PDFButton->setText("Génération PDF");
       ui->LoadButton->setText("Actualiser");
       ui->label_ref->setText("Référence :");
       ui->label_nom->setText("Nom :");
       ui->label_mail->setText("Email :");
       ui->label_gsm->setText("GSM :");
       ui->label_adresse->setText("Adresse :");
       ui->modifierButton->setText("Modifier");
       ui->label_ref_2->setText("Référence à supprimer :");
       ui->supprimerButton_2->setText("Supprimer");
       ui->trier_button->setText("Trier");
       ui->comboBox->setItemText(0,"Référence");
       ui->comboBox->setItemText(1,"Nom");
       ui->comboBox->setItemText(2,"Email");
       ui->homeButton_modifier->setText("Menu");
       //Chef->Fournisseurs->Historique
       ui->homeButton_rechercher->setText("Menu");
       ui->LoadButton_Historique->setText("Actualiser");
       //Chef->Fournisseurs->Parking
       ui->Button->setText("Ouvrir");
       ui->CloseButton->setText("Fermer");
       ui->label_2->setText("Porte");
       /*PRODUITS*/
       //Chef->Produits
       ui->tabWidget_2->setTabText(0,"Ajouter un produit");
       ui->tabWidget_2->setTabText(1,"Gestion des produits");
       ui->tabWidget_2->setTabText(2,"Email");
       ui->tabWidget_2->setTabText(3,"Vidéo de publicité");
       ui->tabWidget_2->setTabText(4,"Historique de contrôle");
       //Chef->Produits->Insertion
       ui->label_19->setText("Produits");
       ui->label_20->setText("ID :");
       ui->label_21->setText("Nom :");
       ui->label_22->setText("Vidéo :");
       ui->label_23->setText("Stock :");
       ui->label_24->setText("Prix :");
       ui->label_25->setText("ID Fournisseur :");
       ui->valider->setText("Ajouter");
       ui->homeButton_2->setText("Menu");
       //Chef->Produits->Gestion
       ui->radioButton->setText("Trier par ID");
       ui->radioButton_2->setText("Trier par Nom");
       ui->radioButton_3->setText("Trier par Prix");
       ui->comboBox_5->setItemText(0,"id");
       ui->label_26->setText("Identification");
       ui->pushButton_delete->setText("Supprimer");
       ui->label_42->setText("Votre choix recherche");
       ui->read->setText("Actualiser");
       ui->label_27->setText("ID :");
       ui->label_30->setText("Nom :");
       ui->label_31->setText("Vidéo :");
       ui->label_28->setText("Stock :");
       ui->label_29->setText("Prix :");
       ui->label_32->setText("ID Fournisseur :");
       ui->pushButton_2->setText("Modifier");
       ui->homeButton_6->setText("Menu");
       //Chef->Produits->Email
       ui->label_43->setText("Sujet :");
       ui->label_44->setText("Message :");
       ui->pushButton_mail->setText("Envoyer");
       ui->pb_gotomail->setText("Email");
       ui->homeButton_7->setText("Menu");
       //Chef->Produits->Video
       ui->homeButton_8->setText("Menu");
       //Chef->Produits->Historique
       ui->loadButton_historique->setText("Actualiser");
       ui->homeButton_9->setText("Menu");
       /*CLIENTS*/
       //Chef->Clients
       ui->tabWidget_5->setTabText(0,"Ajouter un client");
       ui->tabWidget_5->setTabText(1,"Gestion des clients");
       ui->tabWidget_5->setTabText(2,"Historique de contrôle");
       //Chef->Clients->Insertion
       ui->label_3->setText("Clients");
       ui->label_74->setText("CIN :");
       ui->label_75->setText("Nom :");
       ui->label_76->setText("Prénom :");
       ui->label_77->setText("Adresse :");
       ui->label_78->setText("Numéro du téléphone :");
       ui->label_79->setText("Email :");
       ui->addbutton_2->setText("Ajouter");
       ui->homeButton->setText("Menu");
       //Chef->Clients->Gestion
       ui->label_83->setText("CIN :");
       ui->label_80->setText("Nom :");
       ui->label_81->setText("Prénom :");
       ui->label_82->setText("Adresse :");
       ui->label_85->setText("Numéro du téléphone :");
       ui->label_84->setText("Email :");
       ui->deletebutton_4->setText("Actualiser");
       ui->excel_button_2->setText("Fichier Excel");
       ui->pushButton_3->setText("Modifier");
       ui->deletebutton_3->setText("Supprimer");
       ui->label_87->setText("CIN à supprimer :");
       ui->label_86->setText("Rechercher :");
       ui->label_88->setText("Trier par :");
       ui->comboBox_tri_2->setItemText(0,"CIN Montant");
       ui->comboBox_tri_2->setItemText(1,"CIN Descendant");
       ui->comboBox_tri_2->setItemText(2,"Nom");
       ui->comboBox_tri_2->setItemText(3,"Prénom");
       //Chef->Clients->Historique
       ui->loadButton_historique_2->setText("Actualiser");
       /*EMPLOYEES*/
       //Chef->Employees
       ui->tabWidget_3->setTabText(0,"Ajouter un employée");
       ui->tabWidget_3->setTabText(1,"Gestion des employées");
       ui->tabWidget_3->setTabText(2,"Historique de contôle");
       //Chef->Employees->Insertion
       ui->label_67->setText("Employés");
       ui->label_Matricule_3->setText("Matricule :");
       ui->label_Nom_3->setText("Nom :");
       ui->label_prenom_3->setText("Prénom :");
       ui->label_mail_5->setText("Email :");
       ui->label_GSM_3->setText("GSM :");
       ui->label_Role_3->setText("Rôle :");
       ui->label_Salaire_3->setText("Salaire :");
       ui->pb_ajouter_3->setText("Ajouter");
       ui->options_3->setText("Options");
       ui->homeButton_5->setText("Menu");
       //Chef->Employees->Gestion
       ui->label_Matricule_5->setText("Matricule :");
       ui->label_Nom_5->setText("Nom :");
       ui->label_prenom_5->setText("Prénom :");
       ui->label_mail_6->setText("Email :");
       ui->label_GSM_5->setText("GSM :");
       ui->label_Role_5->setText("Rôle :");
       ui->label_Salaire_5->setText("Salaire :");
       ui->pb_update_2->setText("Modifier");
       ui->label_7->setText("Matricule :");
       ui->pb_supprimer_2->setText("Supprimer");
       ui->LoadButton_Historique_3->setText("Actualiser");
       ui->radioButton_tri_personnel_5->setText(" Trier par Matricule");
       ui->radioButton_tri_personnel_6->setText(" Trier par Nom");
       ui->radioButton_tri_personnel_7->setText(" Trier par GSM");
       ui->qrCode_2->setText("QR");
       ui->label_45->setText("Chercher");
       //Chef->Employees->Historique
       ui->homeButton_recherche_2->setText("Actualiser");
       /*LIVRAISONS*/
       //Chef->Livraisons
       ui->historique->setTabText(0,"Ajouter une livraison");
       ui->historique->setTabText(1,"Gestion des livraisons");
       ui->historique->setTabText(2,"Historique de contôle");
       //Chef->Livraisons->Insertion
       ui->label_4->setText("Livraisons");
       ui->label_68->setText("ID Livraison :");
       ui->label_69->setText("Date Livraison :");
       ui->label_70->setText("Frais Livraison :");
       ui->label_71->setText("Destination :");
       ui->ajouter->setText("Ajouter");
       ui->label_34->setText("* Veuillez obéir à la format spécifique de la date : DD-MM-YYYY.");
       ui->label_37->setText("* Veuillez obéir à la format spécifique du mois : (JAN-FEV...).");
       ui->label_40->setText("* L'année doit être entre 1980 et 2022.");
       ui->homeButton_4->setText("Menu");
       //Chef->Livraisons->Gestion
       ui->label_66->setText("ID Livraison :");
       ui->label_50->setText("Date Livraison :");
       ui->label_49->setText("Frais Livraison :");
       ui->label_55->setText("Destination :");
       ui->pushButton_5->setText("Modifier");
       ui->label_47->setText("ID à supprimer :");
       ui->supprimer2->setText("Supprimer");
       ui->label_46->setText("Rechercher :");
       ui->label_6->setText("Trier par :");
       ui->comboBox_tri->setItemText(0,"Frais");
       ui->comboBox_tri->setItemText(1,"ID ASC");
       ui->comboBox_tri->setItemText(2,"ID DESC");
       ui->comboBox_tri->setItemText(3,"Destination");
       ui->pushButton->setText("Actualiser");
       ui->pushButton_4->setText("Accés site web");
       ui->homeButton_11->setText("Menu");
       //Chef->Livraisons->Historique
       ui->pushButton_6->setText("Actualiser");
       ui->pushButton_7->setText("Menu");
       /*COMMANDES*/
       //Chef->Commandes
       ui->tabWidget_6->setTabText(0,"Ajouter une commande");
       ui->tabWidget_6->setTabText(1,"Gestion des commandes");
       ui->tabWidget_6->setTabText(2,"Historique de contôle");
       //Chef->Commandes->Insertion
       ui->label_98->setText("Commandes");
       ui->label_5->setText("ID Commande :");
       ui->label_92->setText("Prix :");
       ui->label_93->setText("Date :");
       ui->label_94->setText("Quantité :");
       ui->pb_Ajouter_2->setText("Ajouter");
       ui->label_95->setText("* Veuillez obéir à la format spécifique de la date : DD-MM-YYYY.");
       ui->label_96->setText("* Veuillez obéir à la format spécifique du mois : (JAN-FEB...).");
       ui->label_97->setText("* L'année doit être entre 1980 et 2022.");
       ui->homeButton_3->setText("Menu");
       //Chef->Commandes->Gestion
       ui->supp_text_3->setText("ID à Supprimer :");
       ui->supp_Button_3->setText("Supprimer");
       ui->label_41->setText("Chercher par ID :");
       ui->label_48->setText("Chercher par Qte :");
       ui->modifierButton_recherche_3->setText("Rechercher");
       ui->modifierButton_recherche_4->setText("Rechercher");
       ui->label_100->setText("ID Commande :");
       ui->label_102->setText("Prix :");
       ui->label_99->setText("Date :");
       ui->label_101->setText("Quantité :");
       ui->modifierButton_5->setText("Modifier");
       ui->pushButton_stat_2->setText("Statistiques");
       ui->Paffiche_2->setText("Actualiser");
       ui->pushButton_10->setText("Trier par Qte");
       ui->pushButton_11->setText("Trier par ID");
       ui->homeButton_10->setText("Menu");
       //Chef->Commandes->Historique
       ui->loadButton_historique_3->setText("Actualiser");
       ui->homeButton_12->setText("Menu");






       //LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR * LIVREUR
       //Livreur->Home
       ui->label_33->setText("Bienvenue, vous êtes le livreur !!");
       ui->prodButton_3->setText("Produits");
       ui->livrButton_3->setText("Livraisons");
       ui->empButton_3->setText("Employées");
       ui->fournisseurButton_3->setText("Fournisseurs");
       ui->cmdButton_3->setText("Commandes");
       ui->clButton_3->setText("Clients");
       ui->pushButton_14->setText("Déconnecter");
       /*LIVRAISONS*/
       //Livreur->Livraisons
       ui->historique_5->setTabText(0,"Ajouter une livraison");
       ui->historique_5->setTabText(1,"Gestion des livraisons");
       ui->historique_5->setTabText(2,"Historique de contôle");
       //Livreur->Livraisons->Insertion
       ui->label_276->setText("Livraisons");
       ui->label_269->setText("ID Livraison :");
       ui->label_270->setText("Date Livraison :");
       ui->label_271->setText("Frais Livraison :");
       ui->label_272->setText("Destination :");
       ui->ajouter_5->setText("Ajouter");
       ui->label_273->setText("* Veuillez obéir à la format spécifique de la date : DD-MM-YYYY.");
       ui->label_274->setText("* Veuillez obéir à la format spécifique du mois : (JAN-FEV...).");
       ui->label_275->setText("* L'année doit être entre 1980 et 2022.");
       ui->homeButton_45->setText("Menu");
       //Livreur->Livraisons->Gestion
       ui->label_277->setText("ID Livraison :");
       ui->label_278->setText("Date Livraison :");
       ui->label_279->setText("Frais Livraison :");
       ui->label_280->setText("Destination :");
       ui->pushButton_38->setText("Modifier");
       ui->label_283->setText("ID à supprimer :");
       ui->supprimer2_5->setText("Supprimer");
       ui->label_282->setText("Rechercher :");
       ui->label_281->setText("Trier par :");
       ui->comboBox_tri_8->setItemText(0,"Frais");
       ui->comboBox_tri_8->setItemText(1,"ID ASC");
       ui->comboBox_tri_8->setItemText(2,"ID DESC");
       ui->comboBox_tri_8->setItemText(3,"Destination");
       ui->pushButton_39->setText("Actualiser");
       ui->pushButton_40->setText("Accés site web");
       ui->homeButton_46->setText("Menu");
       //Livreur->Livraisons->Historique
       ui->pushButton_42->setText("Actualiser");
       ui->pushButton_41->setText("Menu");





       //SIMPLEEMPLOYEE * SIMPLEEMPLOYEE * SIMPLEEMPLOYEE * SIMPLEEMPLOYEE
       //SimpleEmployee->Home
       ui->label_36->setText("Bienvenue, vous êtes le livreur !!");
       ui->prodButton_4->setText("Produits");
       ui->livrButton_4->setText("Livraisons");
       ui->empButton_4->setText("Employées");
       ui->fournisseurButton_4->setText("Fournisseurs");
       ui->cmdButton_4->setText("Commandes");
       ui->clButton_4->setText("Clients");
       ui->pushButton_15->setText("Déconnecter");
       //SimpleEmployee->Fournisseurs
       ui->Lesfournisseurs_4->setText("Les fournisseurs");
       ui->tabWidget_4->setTabText(0,"Ajoutez un fournisseur");
       ui->tabWidget_4->setTabText(1,"Gestion des fournisseurs");
       //SimpleEmployee->Fournisseurs->Insertion
       ui->textajoutezfournisseur_4->setText("Ajoutez un fournisseur :");
       ui->label_56->setText("Référence :");//ref
       ui->label_57->setText("Nom Fournisseur :");//nom
       ui->label_58->setText("GSM Fournisseur :");//gsm
       ui->label_59->setText("Mail Fournisseur :");//mail
       ui->label_60->setText("Adresse Fournisseur :");//adresse
       ui->ajouterButton_4->setText("Ajouter");
       ui->label_61->setText("* La référence est un nombre positive.");
       ui->label_62->setText("* La 1ére lettre du nom de fournissuer doit être en majuscule.");
       ui->label_63->setText("* Le GSM du fournisseur est nombre positive qui contient que 8 chiffres.");
       ui->label_64->setText("* L'email du fournisseur obéit à sa forme générale.");
       ui->label_65->setText("* L'adresse du fournisseur peut contient des chiffres, des lettres et de symboles.");
       ui->homeButton_ajouter_4->setText("Menu");
       //SimpleEmployee->Fournisseurs->Gestion
       ui->nb_4->setText("NB: Double click sur la référence du fournisseur à modifier où supprimer ");
       ui->saisir_r_4->setText("Saisir la référence du fournisseur à chercher :");
       ui->PDFButton_4->setText("Génération PDF");
       ui->LoadButton_2->setText("Actualiser");
       ui->label_ref_7->setText("Référence :");
       ui->label_nom_4->setText("Nom :");
       ui->label_mail_4->setText("Email :");
       ui->label_gsm_4->setText("GSM :");
       ui->label_adresse_4->setText("Adresse :");
       ui->modifierButton_4->setText("Modifier");
       ui->label_ref_8->setText("Référence à supprimer :");
       ui->supprimerButton_5->setText("Supprimer");
       ui->TrierButton->setText("Trier");
       ui->comboBox_2->setItemText(0,"Référence");
       ui->comboBox_2->setItemText(1,"Nom");
       ui->comboBox_2->setItemText(2,"Email");
       ui->homeButton_modifier_4->setText("Menu");
       /*PRODUITS*/
       //SimpleEmployee->Produits
       ui->tabWidget_8->setTabText(0,"Ajouter un produit");
       ui->tabWidget_8->setTabText(1,"Gestion des produits");
       ui->tabWidget_8->setTabText(2,"Email");
       ui->tabWidget_8->setTabText(3,"Vidéo de publicité");
       ui->tabWidget_8->setTabText(4,"Historique de contrôle");
       //SimpleEmployee->Produits->Insertion
       ui->label_51->setText("Produits");
       ui->label_52->setText("ID :");
       ui->label_72->setText("Nom :");
       ui->label_73->setText("Vidéo :");
       ui->label_115->setText("Stock :");
       ui->label_116->setText("Prix :");
       ui->label_117->setText("ID Fournisseur :");
       ui->valider_2->setText("Ajouter");
       ui->homeButton_15->setText("Menu");
       //SimpleEmployee->Produits->Gestion
       ui->radioButton_4->setText("Trier par ID");
       ui->radioButton_5->setText("Trier par Nom");
       ui->radioButton_6->setText("Trier par Prix");
       ui->comboBox_9->setItemText(0,"ID Produit");
       ui->label_118->setText("Identification");
       ui->pushButton_delete_2->setText("Supprimer");
       ui->label_119->setText("Votre choix recherche");
       ui->read_2->setText("Actualiser");
       ui->label_120->setText("ID :");
       ui->label_121->setText("Nom :");
       ui->label_122->setText("Vidéo :");
       ui->label_123->setText("Stock :");
       ui->label_124->setText("Prix :");
       ui->label_125->setText("ID Fournisseur :");
       ui->pushButton_9->setText("Modifier");
       ui->homeButton_16->setText("Menu");
       ui->comboBox_10->setItemText(0,"ID Fournisseur");
       //SimpleEmployee->Produits->Email
       ui->label_127->setText("Sujet :");
       ui->label_126->setText("Message :");
       ui->pushButton_mail_2->setText("Envoyer");
       ui->pb_gotomail_2->setText("Email");
       ui->homeButton_17->setText("Menu");
       //SimpleEmployee->Produits->Video
       ui->homeButton_20->setText("Menu");
       //SimpleEmployee->Produits->Historique
       ui->loadButton_historique_5->setText("Actualiser");
       ui->homeButton_21->setText("Menu");
       /*CLIENTS*/
       //SimpleEmployee->Clients
       ui->tabWidget_7->setTabText(0,"Ajouter un client");
       ui->tabWidget_7->setTabText(1,"Gestion des clients");
       ui->tabWidget_7->setTabText(2,"Historique de contrôle");
       //SimpleEmployee->Clients->Insertion
       ui->label_39->setText("Clients");
       ui->label_89->setText("CIN :");
       ui->label_90->setText("Nom :");
       ui->label_91->setText("Prénom :");
       ui->label_103->setText("Adresse :");
       ui->label_104->setText("Numéro du téléphone :");
       ui->label_105->setText("Email :");
       ui->addbutton_3->setText("Ajouter");
       ui->homeButton_14->setText("Menu");
       //SimpleEmployee->Clients->Gestion
       ui->label_106->setText("CIN :");
       ui->label_107->setText("Nom :");
       ui->label_108->setText("Prénom :");
       ui->label_109->setText("Adresse :");
       ui->label_110->setText("Numéro du téléphone :");
       ui->label_111->setText("Email :");
       ui->deletebutton_5->setText("Actualiser");
       ui->excel_button_3->setText("Fichier Excel");
       ui->pushButton_8->setText("Modifier");
       ui->deletebutton_6->setText("Supprimer");
       ui->label_112->setText("CIN à supprimer :");
       ui->label_113->setText("Rechercher :");
       ui->label_114->setText("Trier par :");
       ui->comboBox_tri_3->setItemText(0,"CIN Montant");
       ui->comboBox_tri_3->setItemText(1,"CIN Descendant");
       ui->comboBox_tri_3->setItemText(2,"Nom");
       ui->comboBox_tri_3->setItemText(3,"Prénom");
       ui->homeButton_25->setText("Menu");
       //SimpleEmployee->Clients->Historique
       ui->loadButton_historique_4->setText("Actualiser");
       ui->homeButton_26->setText("Menu");
       /*LIVRAISONS*/
       //SimpleEmployee->Livraisons
       ui->historique_2->setTabText(0,"Ajouter une livraison");
       ui->historique_2->setTabText(1,"Gestion des livraisons");
       ui->historique_2->setTabText(2,"Historique de contrôle");
       //SimpleEmployee->Livraisons->Insertion
       ui->label_147->setText("Livraisons");
       ui->label_141->setText("ID Livraison :");
       ui->label_142->setText("Date Livraison :");
       ui->label_143->setText("Frais Livraison :");
       ui->label_144->setText("Destination :");
       ui->ajouter_2->setText("Ajouter");
       ui->label_54->setText("* Veuillez obéir à la format spécifique de la date : DD-MM-YYYY.");
       ui->label_145->setText("* Veuillez obéir à la format spécifique du mois : (JAN-FEV...).");
       ui->label_146->setText("* L'année doit être entre 1980 et 2022.");
       ui->homeButton_19->setText("Menu");
       //SimpleEmployee->Livraisons->Gestion
       ui->label_148->setText("ID Livraison :");
       ui->label_149->setText("Date Livraison :");
       ui->label_150->setText("Frais Livraison :");
       ui->label_151->setText("Destination :");
       ui->pushButton_17->setText("Modifier");
       ui->label_154->setText("ID à supprimer :");
       ui->supprimer2_2->setText("Supprimer");
       ui->label_153->setText("Chercher :");
       ui->label_152->setText("Trier par :");
       ui->comboBox_tri_4->setItemText(0,"Frais");
       ui->comboBox_tri_4->setItemText(1,"ID ASC");
       ui->comboBox_tri_4->setItemText(2,"ID DESC");
       ui->comboBox_tri_4->setItemText(3,"Destination");   //ó    í
       ui->pushButton_18->setText("Actualiser");
       ui->pushButton_19->setText("Accès au site web");
       ui->homeButton_24->setText("Menu");
       //SimpleEmployee->Livraisons->Historique
       ui->pushButton_21->setText("Actualiser");
       ui->pushButton_20->setText("Menu");
       /*COMMANDES*/
       //SimpleEmployee->Commandes
       ui->tabWidget_9->setTabText(0,"Ajouter une commande");
       ui->tabWidget_9->setTabText(1,"Gestion des commandes");
       ui->tabWidget_9->setTabText(2,"Historique de contôle");
       //SimpleEmployee->Commandes->Insertion
       ui->label_131->setText("Commandes");
       ui->label_53->setText("ID Commande :");
       ui->label_132->setText("Prix :");
       ui->label_133->setText("Date :");
       ui->label_134->setText("Quantité :");
       ui->pb_Ajouter_3->setText("Ajouter");
       ui->label_128->setText("* Veuillez obéir à la format spécifique de la date : DD-MM-YYYY.");
       ui->label_129->setText("* Veuillez obéir à la format spécifique du mois : (JAN-FEB...).");
       ui->label_130->setText("* L'année doit être entre 1980 et 2022.");
       ui->homeButton_18->setText("Menu");
       //SimpleEmployee->Commandes->Gestion
       ui->supp_text_4->setText("ID à Supprimer :");
       ui->supp_Button_4->setText("Supprimer");
       ui->label_139->setText("Chercher par ID :");
       ui->label_140->setText("Chercher par Qte :");
       ui->modifierButton_recherche_5->setText("Rechercher");
       ui->modifierButton_recherche_6->setText("Rechercher");
       ui->label_135->setText("ID Commande :");
       ui->label_136->setText("Prix :");
       ui->label_137->setText("Date :");
       ui->label_138->setText("Quantité :");
       ui->modifierButton_7->setText("Modifier");
       ui->pushButton_stat_3->setText("Statistiques");
       ui->Paffiche_3->setText("Actualiser");
       ui->pushButton_13->setText("Trier par Qte");
       ui->pushButton_16->setText("Trier par ID");
       ui->homeButton_22->setText("Menu");
       //SimpleEmployee->Commandes->Historique
       ui->loadButton_historique_6->setText("Actualiser");
       ui->homeButton_23->setText("Menu");




   }
   if(index == 1) //en
   {
       //LOGIN * LOGIN * LOGIN
       ui->langue->setText("Language :");
       ui->nom_utilisateur_3->setText("Username : ");
       ui->label_35->setText("Password :");
       ui->lineEdit_username->setPlaceholderText("Username");
       ui->lineEdit_password->setPlaceholderText("Password");
       ui->LoginButton->setText("Login");
       ui->QuitterButton->setText("Quit");




       //CHEF * CHEF * CHEF
       //Chef->Home
       ui->label->setText("Welcome, you're the chief !!");
       ui->prodButton->setText("Products");
       ui->livrButton->setText("Deliveries");
       ui->empButton->setText("Employees");
       ui->fournisseurButton->setText("Suppliers");
       ui->cmdButton->setText("Orders");
       ui->clButton->setText("Customers");
       ui->pushButton_12->setText("Disconnect");

       //Chef->Fournisseurs
       ui->Lesfournisseurs->setText("Suppliers");
       ui->tabWidget->setTabText(0,"Add a supplier");
       ui->tabWidget->setTabText(1,"Management of suppliers");
       ui->tabWidget->setTabText(2,"Control history");
       ui->tabWidget->setTabText(3,"Parking");
       //Chef->Fournisseurs->Insertion
       ui->textajoutezfournisseur->setText("Add a supplier :");
       ui->label_9->setText("Reference :");//ref
       ui->label_10->setText("Name of supplier :");//nom
       ui->label_11->setText("GSM of supplier :");//gsm
       ui->label_12->setText("Email of supplier :");//mail
       ui->label_17->setText("Addresse of supplier :");//adresse
       ui->ajouterButton->setText("Add");
       ui->label_13->setText("* The reference is a positive number.");
       ui->label_8->setText("* The 1st letter of the supplier's name must be capitalized.");
       ui->label_14->setText("* The provider's GSM is a positive number which contains only 8 digits.");
       ui->label_15->setText("* The supplier's email follows its general form.");
       ui->label_16->setText("* The supplier's addresse contains numbers, lettres and symboles.");
       ui->homeButton_ajouter->setText("Home");
       //Chef->Fournisseurs->Gestion
       ui->nb->setText("Note: Double click on the supplier's reference to modify or delete");
       ui->saisir_r->setText("Enter the reference of the supplier to be searched:");
       ui->PDFButton->setText("Generate PDF");
       ui->LoadButton->setText("Load List");
       ui->label_ref->setText("Reference :");
       ui->label_nom->setText("Name of supplier :");
       ui->label_mail->setText("Email of supplier :");
       ui->label_gsm->setText("GSM of supplier :");
       ui->label_adresse->setText("Addresse of supplier :");
       ui->modifierButton->setText("Modify");
       ui->label_ref_2->setText("Reference to delete:");
       ui->supprimerButton_2->setText("Delete");
       ui->trier_button->setText("Sort");
       ui->comboBox->setItemText(0,"Reference");
       ui->comboBox->setItemText(1,"Name");
       ui->comboBox->setItemText(2,"Email");
       ui->homeButton_modifier->setText("Home");
       //Chef->Fournisseurs->Historique
       ui->homeButton_rechercher->setText("Home");
       ui->LoadButton_Historique->setText("Load");
       //Chef->Fournisseurs->Parking
       ui->Button->setText("Open");
       ui->CloseButton->setText("Close");
       ui->label_2->setText("Door");
       /*PRODUITS*/
       //Chef->Produits
       ui->tabWidget_2->setTabText(0,"Add a product");
       ui->tabWidget_2->setTabText(1,"Management of products");
       ui->tabWidget_2->setTabText(2,"Mailing");
       ui->tabWidget_2->setTabText(3,"Advertising video");
       ui->tabWidget_2->setTabText(4,"Control History");
       //Chef->Produits->Insertion
       ui->label_19->setText("Products");
       ui->label_20->setText("ID :");
       ui->label_21->setText("Name :");
       ui->label_22->setText("Video :");
       ui->label_23->setText("Stock :");
       ui->label_24->setText("Price :");
       ui->label_25->setText("ID Supplier :");
       ui->valider->setText("Add");
       ui->homeButton_2->setText("Home");
       //Chef->Produits->Gestion
       ui->radioButton->setText("Sort by ID");
       ui->radioButton_2->setText("Sort by Name");
       ui->radioButton_3->setText("Sort by Price");
       ui->comboBox_5->setItemText(0,"ID");
       ui->label_26->setText("Identification");
       ui->pushButton_delete->setText("Delete");
       ui->label_42->setText("Your choice to search");
       ui->read->setText("Load");
       ui->label_27->setText("ID :");
       ui->label_30->setText("Name :");
       ui->label_31->setText("Video :");
       ui->label_28->setText("Stock :");
       ui->label_29->setText("Price :");
       ui->label_32->setText("ID Supplier :");
       ui->pushButton_2->setText("Modify");
       ui->homeButton_6->setText("Home");
       //Chef->Produits->Email
       ui->label_43->setText("Subject :");
       ui->label_44->setText("Message :");
       ui->pushButton_mail->setText("Send");
       ui->pb_gotomail->setText("Mail");
       ui->homeButton_7->setText("Home");
       //Chef->Produits->Video
       ui->homeButton_8->setText("Home");
       //Chef->Produits->Historique
       ui->loadButton_historique->setText("Load");
       ui->homeButton_9->setText("Home");
       /*CLIENTS*/
       //Chef->Clients
       ui->tabWidget_5->setTabText(0,"Add a customer");
       ui->tabWidget_5->setTabText(1,"Management of customers");
       ui->tabWidget_5->setTabText(2,"Control History");
       //Chef->Clients->Insertion
       ui->label_3->setText("Customers");
       ui->label_74->setText("ID Card :");
       ui->label_75->setText("Name :");
       ui->label_76->setText("First Name :");
       ui->label_77->setText("Address :");
       ui->label_78->setText("Phone number :");
       ui->label_79->setText("Mail :");
       ui->addbutton_2->setText("Add");
       ui->homeButton->setText("Home");
       //Chef->Clients->Gestion
       ui->label_83->setText("ID Card :");
       ui->label_80->setText("Name :");
       ui->label_81->setText("First Name :");
       ui->label_82->setText("Address :");
       ui->label_85->setText("Phone Number :");
       ui->label_84->setText("Mail :");
       ui->deletebutton_4->setText("Load");
       ui->excel_button_2->setText("Excel File");
       ui->pushButton_3->setText("Modify");
       ui->deletebutton_3->setText("Delete");
       ui->label_87->setText("ID Card to delete :");
       ui->label_86->setText("Search :");
       ui->label_88->setText("Sort by :");
       ui->comboBox_tri_2->setItemText(0,"CIN Ascending");
       ui->comboBox_tri_2->setItemText(1,"CIN Descending");
       ui->comboBox_tri_2->setItemText(2,"Name");
       ui->comboBox_tri_2->setItemText(3,"First Name");
       //Chef->Clients->Historique
       ui->loadButton_historique_2->setText("Load");
       /*EMPLOYEES*/
       //Chef->Employees
       ui->tabWidget_3->setTabText(0,"Add an employee");
       ui->tabWidget_3->setTabText(1,"Management of employees");
       ui->tabWidget_3->setTabText(2,"Contol History");
       //Chef->Employees->Insertion
       ui->label_67->setText("Employees");
       ui->label_Matricule_3->setText("Registration number");
       ui->label_Nom_3->setText("Name :");
       ui->label_prenom_3->setText("First Name :");
       ui->label_mail_5->setText("Mail :");
       ui->label_GSM_3->setText("GSM :");
       ui->label_Role_3->setText("Role :");
       ui->label_Salaire_3->setText("Salary :");
       ui->pb_ajouter_3->setText("Add");
       ui->options_3->setText("Options");
       ui->homeButton_5->setText("Home");
       //Chef->Employees->Gestion
       ui->label_Matricule_5->setText("Registration number");
       ui->label_Nom_5->setText("Name :");
       ui->label_prenom_5->setText("First Name :");
       ui->label_mail_6->setText("Mail :");
       ui->label_GSM_5->setText("GSM :");
       ui->label_Role_5->setText("Role :");
       ui->label_Salaire_5->setText("Salary :");
       ui->pb_update_2->setText("Modify");
       ui->label_7->setText("Registration number");
       ui->pb_supprimer_2->setText("Delete");
       ui->LoadButton_Historique_3->setText("Load");
       ui->radioButton_tri_personnel_5->setText(" Sort by Number");
       ui->radioButton_tri_personnel_6->setText(" Sort by Name");
       ui->radioButton_tri_personnel_7->setText(" Sort by GSM");
       ui->qrCode_2->setText("QR");
       ui->label_45->setText("Search");
       //Chef->Employees->Historique
       ui->homeButton_recherche_2->setText("Load");
       /*LIVRAISONS*/
       //Chef->Livraisons
       ui->historique->setTabText(0,"Add a delivery");
       ui->historique->setTabText(1,"Delivery management");
       ui->historique->setTabText(2,"Control history");
       //Chef->Livraisons->Insertion
       ui->label_4->setText("Deliveries");
       ui->label_68->setText("Delivery ID :");
       ui->label_69->setText("Delivery date :");
       ui->label_70->setText("Shipping cost :");
       ui->label_71->setText("Destination :");
       ui->ajouter->setText("Add");
       ui->label_34->setText("* Please obey the date's specific format : DD-MM-YYYY.");
       ui->label_37->setText("* Please obey the month's specific format : (JAN-FEB...).");
       ui->label_40->setText("* The year must be between 1980 and 2022.");
       ui->homeButton_4->setText("Home");
       //Chef->Livraisons->Gestion
       ui->label_66->setText("Delivery ID :");
       ui->label_50->setText("Delivery date :");
       ui->label_49->setText("Shipping cost :");
       ui->label_55->setText("Destination :");
       ui->pushButton_5->setText("Edit");
       ui->label_47->setText("ID to delete :");
       ui->supprimer2->setText("Delete");
       ui->label_46->setText("Search :");
       ui->label_6->setText("Sort by :");
       ui->comboBox_tri->setItemText(0,"Costs");
       ui->comboBox_tri->setItemText(1,"Ascendant ID");
       ui->comboBox_tri->setItemText(2,"Descendant ID");
       ui->comboBox_tri->setItemText(3,"Destination");
       ui->pushButton->setText("Load");
       ui->pushButton_4->setText("Website access");
       ui->homeButton_11->setText("Home");
       //Chef->Livraisons->Historique
       ui->pushButton_6->setText("Load");
       ui->pushButton_7->setText("Home");
       /*COMMANDES*/
       //Chef->Commandes
       ui->tabWidget_6->setTabText(0,"Add an order");
       ui->tabWidget_6->setTabText(1,"Order management");
       ui->tabWidget_6->setTabText(2,"Control history");
       //Chef->Commandes->Insertion
       ui->label_98->setText("Orders");
       ui->label_5->setText("Order ID :");
       ui->label_92->setText("Price :");
       ui->label_93->setText("Date :");
       ui->label_94->setText("Quantity :");
       ui->pb_Ajouter_2->setText("Add");
       ui->label_95->setText("* Please obey the date's specific format : DD-MM-YYYY.");
       ui->label_96->setText("* Please obey the month's specific format : (JAN-FEB...).");
       ui->label_97->setText("* The year must be between 1980 and 2022.");
       ui->homeButton_3->setText("Home");
       //Chef->Commandes->Gestion
       ui->supp_text_3->setText("ID to Delete :");
       ui->supp_Button_3->setText("Delete");
       ui->label_41->setText("Search with ID :");
       ui->label_48->setText("Search with Quantity :");
       ui->modifierButton_recherche_3->setText("Search");
       ui->modifierButton_recherche_4->setText("Search");
       ui->label_100->setText("Order ID :");
       ui->label_102->setText("Price :");
       ui->label_99->setText("Date :");
       ui->label_101->setText("Quantity :");
       ui->modifierButton_5->setText("Modify");
       ui->pushButton_stat_2->setText("Statistics");
       ui->Paffiche_2->setText("Load");
       ui->pushButton_10->setText("Sort by Quantity");
       ui->pushButton_11->setText("Sort by ID");
       ui->homeButton_10->setText("Home");
       //Chef->Commandes->Historique
       ui->loadButton_historique_3->setText("Load");
       ui->homeButton_12->setText("Home");







       //LIVREUR * LIVREUR * LIVREUR
       //Livreur->Home
       ui->label_33->setText("Welcome, you're the delivery man !!");
       ui->prodButton_3->setText("Products");
       ui->livrButton_3->setText("Deliveries");
       ui->empButton_3->setText("Employees");
       ui->fournisseurButton_3->setText("Suppliers");
       ui->cmdButton_3->setText("Orders");
       ui->clButton_3->setText("Customers");
       ui->pushButton_14->setText("Disconnect");
       /*LIVRAISONS*/
       //Livreur->Livraisons
       ui->historique_5->setTabText(0,"Add a delivery");
       ui->historique_5->setTabText(1,"Deliveries management");
       ui->historique_5->setTabText(2,"Control history");
       //Livreur->Livraisons->Insertion
       ui->label_276->setText("Deliveries");
       ui->label_269->setText("Delivery ID :");
       ui->label_270->setText("Delivery date :");
       ui->label_271->setText("Shipping cost :");
       ui->label_272->setText("Destination :");
       ui->ajouter_5->setText("Add");
       ui->label_273->setText("* Please obey the date's specific format : DD-MM-YYYY.");
       ui->label_274->setText("* Please obey the month's specific format : (JAN-FEB...).");
       ui->label_275->setText("* The year must be between 1980 and 2022.");
       ui->homeButton_45->setText("Home");
       //Livreur->Livraisons->Gestion
       ui->label_277->setText("Delivery ID :");
       ui->label_278->setText("Delivery date :");
       ui->label_279->setText("Shipping cost :");
       ui->label_280->setText("Destination :");
       ui->pushButton_38->setText("Modify");
       ui->label_283->setText("ID to delete :");
       ui->supprimer2_5->setText("Delete");
       ui->label_282->setText("Search :");
       ui->label_281->setText("Sort by :");
       ui->comboBox_tri_8->setItemText(0,"Costs");
       ui->comboBox_tri_8->setItemText(1,"Ascendant ID");
       ui->comboBox_tri_8->setItemText(2,"Descendant ID");
       ui->comboBox_tri_8->setItemText(3,"Destination");
       ui->pushButton_39->setText("Load");
       ui->pushButton_40->setText("Website access");
       ui->homeButton_46->setText("Home");
       //Livreur->Livraisons->Historique
       ui->pushButton_42->setText("Load");
       ui->pushButton_41->setText("Home");






       //SIMPLEEMPLOYEE * SIMPLEEMPLOYEE * SIMPLEEMPLOYEE
       //Simpleemployee->Home
       ui->label_36->setText("Welcome, you're the employee !!");
       ui->prodButton_4->setText("Products");
       ui->livrButton_4->setText("Deliveries");
       ui->empButton_4->setText("Employees");
       ui->fournisseurButton_4->setText("Suppliers");
       ui->cmdButton_4->setText("Orders");
       ui->clButton_4->setText("Customers");
       ui->pushButton_15->setText("Disconnect");
       //SimpleEmployee->Fournisseurs
       ui->Lesfournisseurs_4->setText("Suppliers");
       ui->tabWidget_4->setTabText(0,"Add a supplier");
       ui->tabWidget_4->setTabText(1,"Management of suppliers");
       //SimpleEmployee->Fournisseurs->Insertion
       ui->textajoutezfournisseur_4->setText("Add a supplier :");
       ui->label_56->setText("Reference :");//ref
       ui->label_57->setText("Name of supplier :");//nom
       ui->label_58->setText("GSM of supplier :");//gsm
       ui->label_59->setText("Email of supplier :");//mail
       ui->label_60->setText("Addresse of supplier :");//adresse
       ui->ajouterButton_4->setText("Add");
       ui->label_61->setText("* The reference is a positive number.");
       ui->label_62->setText("* The 1st letter of the supplier's name must be capitalized.");
       ui->label_63->setText("* The provider's GSM is a positive number which contains only 8 digits.");
       ui->label_64->setText("* The supplier's email follows its general form.");
       ui->label_65->setText("* The supplier's addresse contains numbers, lettres and symboles.");
       ui->homeButton_ajouter_4->setText("Home");
       //SimpleEmployee->Fournisseurs->Gestion
       ui->nb_4->setText("Note: Double click on the supplier's reference to modify or delete");
       ui->saisir_r_4->setText("Enter the reference of the supplier to be searched:");
       ui->PDFButton_4->setText("Generate PDF");
       ui->LoadButton_2->setText("Load List");
       ui->label_ref_7->setText("Reference :");
       ui->label_nom_4->setText("Name :");
       ui->label_mail_4->setText("Email :");
       ui->label_gsm_4->setText("GSM :");
       ui->label_adresse_4->setText("Addresse :");
       ui->modifierButton_4->setText("Modify");
       ui->label_ref_8->setText("Reference to delete :");
       ui->supprimerButton_5->setText("Delete");
       ui->TrierButton->setText("Sort");
       ui->comboBox_2->setItemText(0,"Reference");
       ui->comboBox_2->setItemText(1,"Name");
       ui->comboBox_2->setItemText(2,"Email");
       ui->homeButton_modifier_4->setText("Home");
       /*PRODUITS*/
       //SimpleEmployee->Produits
       ui->tabWidget_8->setTabText(0,"Add a product");
       ui->tabWidget_8->setTabText(1,"Product management");
       ui->tabWidget_8->setTabText(2,"Mail");
       ui->tabWidget_8->setTabText(3,"Advertising video");
       ui->tabWidget_8->setTabText(4,"Control history");
       //SimpleEmployee->Produits->Insertion
       ui->label_51->setText("Products");
       ui->label_52->setText("ID :");
       ui->label_72->setText("Name :");
       ui->label_73->setText("Video :");
       ui->label_115->setText("Stock :");
       ui->label_116->setText("Price :");
       ui->label_117->setText("ID Supplier :");
       ui->valider_2->setText("Add");
       ui->homeButton_15->setText("Load");
       //SimpleEmployee->Produits->Gestion
       ui->radioButton_4->setText("Sort by ID");
       ui->radioButton_5->setText("Sort by Name");
       ui->radioButton_6->setText("Sort by Price");
       ui->comboBox_9->setItemText(0,"ID Product");
       ui->label_118->setText("Identification");
       ui->pushButton_delete_2->setText("Delete");
       ui->label_119->setText("Your search's choice");
       ui->read_2->setText("Load");
       ui->label_120->setText("ID :");
       ui->label_121->setText("Name :");
       ui->label_122->setText("Video :");
       ui->label_123->setText("Stock :");
       ui->label_124->setText("Price :");
       ui->label_125->setText("ID Supplier :");
       ui->pushButton_9->setText("Modify");
       ui->homeButton_16->setText("Home");
       ui->comboBox_10->setItemText(0,"ID Supplier");
       //SimpleEmployee->Produits->Email
       ui->label_127->setText("Subject :");
       ui->label_126->setText("Message :");
       ui->pushButton_mail_2->setText("Send");
       ui->pb_gotomail_2->setText("Mail");
       ui->homeButton_17->setText("Load");
       //SimpleEmployee->Produits->Video
       ui->homeButton_20->setText("Load");
       //SimpleEmployee->Produits->Historique
       ui->loadButton_historique_5->setText("Load");
       ui->homeButton_21->setText("Home");
       /*CLIENTS*/
       //SimpleEmployee->Clients
       ui->tabWidget_7->setTabText(0,"Add a customer");
       ui->tabWidget_7->setTabText(1,"Customers management");
       ui->tabWidget_7->setTabText(2,"Control history");
       //SimpleEmployee->Clients->Insertion
       ui->label_39->setText("Customers");
       ui->label_89->setText("ID Card :");
       ui->label_90->setText("Name :");
       ui->label_91->setText("First name :");
       ui->label_103->setText("Address :");
       ui->label_104->setText("Phone number :");
       ui->label_105->setText("Mail :");
       ui->addbutton_3->setText("Add");
       ui->homeButton_14->setText("Home");
       //SimpleEmployee->Clients->Gestion
       ui->label_106->setText("ID Card :");
       ui->label_107->setText("Name :");
       ui->label_108->setText("First name :");
       ui->label_109->setText("Address :");
       ui->label_110->setText("Phone number :");
       ui->label_111->setText("Mail :");
       ui->deletebutton_5->setText("Load");
       ui->excel_button_3->setText("Excel File");
       ui->pushButton_8->setText("Modify");
       ui->deletebutton_6->setText("Delete");
       ui->label_112->setText("ID Card to delete :");
       ui->label_113->setText("Search :");
       ui->label_114->setText("Sort by :");
       ui->comboBox_tri_3->setItemText(0,"CIN Ascending");
       ui->comboBox_tri_3->setItemText(1,"CIN Descending");
       ui->comboBox_tri_3->setItemText(2,"Name");
       ui->comboBox_tri_3->setItemText(3,"First Name");
       ui->homeButton_25->setText("Home");
       //SimpleEmployee->Clients->Historique
       ui->loadButton_historique_4->setText("Load");
       ui->homeButton_26->setText("Home");
       /*LIVRAISONS*/
       //SimpleEmployee->Livraisons
       ui->historique_2->setTabText(0,"Add a delivery");
       ui->historique_2->setTabText(1,"Deliveries management");
       ui->historique_2->setTabText(2,"Control history");
       //SimpleEmployee->Livraisons->Insertion
       ui->label_147->setText("Deliveries");
       ui->label_141->setText("Delievery ID :");
       ui->label_142->setText("Delivery date :");
       ui->label_143->setText("Shipping cost :");
       ui->label_144->setText("Destination :");
       ui->ajouter_2->setText("Add");
       ui->label_54->setText("* Please obey the date's specific format : DD-MM-YYYY.");
       ui->label_145->setText("* Please obey the month's specific format : (JAN-FEB...).");
       ui->label_146->setText("* The year must be between 1980 and 2022.");
       ui->homeButton_19->setText("Home");
       //SimpleEmployee->Livraisons->Gestion
       ui->label_148->setText("Delivery ID :");
       ui->label_149->setText("Delivery date :");
       ui->label_150->setText("Shipping cost :");
       ui->label_151->setText("Destination :");
       ui->pushButton_17->setText("Modify");
       ui->label_154->setText("ID to delete :");
       ui->supprimer2_2->setText("Delete");
       ui->label_153->setText("Search :");
       ui->label_152->setText("Sort by :");
       ui->comboBox_tri_4->setItemText(0,"Costs");
       ui->comboBox_tri_4->setItemText(1,"Ascendant ID");
       ui->comboBox_tri_4->setItemText(2,"Descendant ID");
       ui->comboBox_tri_4->setItemText(3,"Destination");   //ó    í
       ui->pushButton_18->setText("Load");
       ui->pushButton_19->setText("Website access");
       ui->homeButton_24->setText("Home");
       //SimpleEmployee->Livraisons->Historique
       ui->pushButton_21->setText("Load");
       ui->pushButton_20->setText("Home");
       /*COMMANDES*/
       //SimpleEmployee->Commandes
       ui->tabWidget_9->setTabText(0,"Add an order");
       ui->tabWidget_9->setTabText(1,"Orders management");
       ui->tabWidget_9->setTabText(2,"Control history");
       //SimpleEmployee->Commandes->Insertion
       ui->label_131->setText("Orders");
       ui->label_53->setText("Order ID :");
       ui->label_132->setText("Price :");
       ui->label_133->setText("Date :");
       ui->label_134->setText("Quantity :");
       ui->pb_Ajouter_3->setText("Add");
       ui->label_128->setText("* Please obey the date's specific format : DD-MM-YYYY.");
       ui->label_129->setText("* Please obey the month's specific format : (JAN-FEB...).");
       ui->label_130->setText("* The year must be between 1980 and 2022.");
       ui->homeButton_18->setText("Home");
       //SimpleEmployee->Commandes->Gestion
       ui->supp_text_4->setText("ID to delete :");
       ui->supp_Button_4->setText("Delete");
       ui->label_139->setText("Search with ID :");
       ui->label_140->setText("Search with Quantity :");
       ui->modifierButton_recherche_5->setText("Search");
       ui->modifierButton_recherche_6->setText("Search");
       ui->label_135->setText("Order ID :");
       ui->label_136->setText("Price :");
       ui->label_137->setText("Date :");
       ui->label_138->setText("Quantity :");
       ui->modifierButton_7->setText("Modify");
       ui->pushButton_stat_3->setText("Statistics");
       ui->Paffiche_3->setText("Load");
       ui->pushButton_13->setText("Sort by Quantity");
       ui->pushButton_16->setText("Sort by ID");
       ui->homeButton_22->setText("Home");
       //SimpleEmployee->Commandes->Historique
       ui->loadButton_historique_6->setText("Load");
       ui->homeButton_23->setText("Home");


   }
   if(index == 2) //esp
   {
       //LOGIN * LOGIN * LOGIN
       ui->langue->setText("Lingua :");
       ui->nom_utilisateur_3->setText("Nombre usuario : ");
       ui->label_35->setText("Clave :");
       ui->lineEdit_username->setPlaceholderText("Nombre usuario");
       ui->lineEdit_password->setPlaceholderText("Clave");
       ui->LoginButton->setText("Acceso");
       ui->QuitterButton->setText("Salir");



       //CHEF * CHEF * CHEF
       //Chef->Home
       ui->label->setText("Bienvenido, tu eres el chef !!");
       ui->prodButton->setText("Productos");
       ui->livrButton->setText("Entregas");
       ui->empButton->setText("Empleados");
       ui->fournisseurButton->setText("Proveedores");
       ui->cmdButton->setText("Pedidos");
       ui->clButton->setText("Clientela");
       ui->pushButton_12->setText("Desconectar");
       /*FOURNISSEURS*/
       //Chef->Fournisseurs
       ui->Lesfournisseurs->setText("Proveedores");
       ui->tabWidget->setTabText(0,"Añadir un proveedor");
       ui->tabWidget->setTabText(1,"Gestión de proveedores");
       ui->tabWidget->setTabText(2,"Historial de control");
       ui->tabWidget->setTabText(3,"Estacionamiento");
       //Chef->Fournisseurs->Insertion
       ui->textajoutezfournisseur->setText("Añadir un proveedor :");
       ui->label_9->setText("Referencia :");//ref
       ui->label_10->setText("Nombre del proveedor :");//nom
       ui->label_11->setText("GSM del proveedor :");//gsm
       ui->label_12->setText("Email del proveedor :");//mail
       ui->label_17->setText("Dirección del proveedor :");//adresse
       ui->ajouterButton->setText("Agregar");
       ui->label_13->setText("* La referencia es un número positivo.");
       ui->label_8->setText("* La primera letra del nombre del proveedor debe estar en mayúscula.");
       ui->label_14->setText("* El GSM del proveedor es un número positivo que contiene solo 8 dígitos.");
       ui->label_15->setText("* El correo electrónico del proveedor sigue su forma general.");
       ui->label_16->setText("* La dirección del proveedor puede contener números, letras y símbolos.");
       ui->homeButton_ajouter->setText("Menù");
       //Chef->Fournisseurs->Gestion
       ui->nb->setText("Nota: Haga doble clic en la referencia del proveedor para modificar o eliminar");
       ui->saisir_r->setText("Introduzca la referencia del proveedor a buscar:");
       ui->PDFButton->setText("Generación de PDF");
       ui->LoadButton->setText("Actualizar");
       ui->label_ref->setText("Referencia:");
       ui->label_nom->setText("Nombre:");
       ui->label_mail->setText("Email:");
       ui->label_gsm->setText("GSM:");
       ui->label_adresse->setText("Dirección:");
       ui->modifierButton->setText("Editar");
       ui->label_ref_2->setText("Referencia a eliminar:");
       ui->supprimerButton_2->setText("Retirar");
       ui->trier_button->setText("Ordenar");
       ui->comboBox->setItemText(0,"Referencia");
       ui->comboBox->setItemText(1,"Nombre");
       ui->comboBox->setItemText(2,"Email");
       ui->homeButton_modifier->setText("Menù");
       //Chef->Fournisseurs->Historique
       ui->homeButton_rechercher->setText("Menù");
       ui->LoadButton_Historique->setText("Actualizar");
       //Chef->Fournisseurs->Parking
       ui->Button->setText("Abrir");
       ui->CloseButton->setText("Cerrar");
       ui->label_2->setText("Puerta");
       /*PRODUITS*/
       //Chef->Produits
       ui->tabWidget_2->setTabText(0,"Añadir un producto");
       ui->tabWidget_2->setTabText(1,"Gestión de productos");
       ui->tabWidget_2->setTabText(2,"Correo electrónico");
       ui->tabWidget_2->setTabText(3,"Vídeo publicitario");
       ui->tabWidget_2->setTabText(4,"Historial de control");
       //Chef->Produits->Insertion
       ui->label_19->setText("Productos");
       ui->label_20->setText("Identificación :");
       ui->label_21->setText("Nombre :");
       ui->label_22->setText("Vídeo :");
       ui->label_23->setText("Valores :");
       ui->label_24->setText("Precio :");
       ui->label_25->setText("ID Provedoor :");
       ui->valider->setText("Agregar");
       ui->homeButton_2->setText("Menù");
       //Chef->Produits->Gestion
       ui->radioButton->setText("Ordenar por ID");
       ui->radioButton_2->setText("Ordenar por nombre");
       ui->radioButton_3->setText("Ordenar por precio");
       ui->comboBox_5->setItemText(0,"Identificación");
       ui->label_26->setText("Identificación");
       ui->pushButton_delete->setText("Retirar");
       ui->label_42->setText("Tu elección para buscar");
       ui->read->setText("Actualizar");
       ui->label_27->setText("Identificación :");
       ui->label_30->setText("Nombre :");
       ui->label_31->setText("Vídeo :");
       ui->label_28->setText("Valores :");
       ui->label_29->setText("Precio :");
       ui->label_32->setText("ID Provedoor :");
       ui->pushButton_2->setText("Editar");
       ui->homeButton_6->setText("Menù");
       //Chef->Produits->Email
       ui->label_43->setText("Asunto :");
       ui->label_44->setText("Mensaje :");
       ui->pushButton_mail->setText("Enviar");
       ui->pb_gotomail->setText("Correo");
       ui->homeButton_7->setText("Menù");
       //Chef->Produits->Video
       ui->homeButton_8->setText("Menù");
       //Chef->Produits->Historique
       ui->loadButton_historique->setText("Actualizar");
       ui->homeButton_9->setText("Menù");
       /*CLIENTS*/
       //Chef->Clients
       ui->tabWidget_5->setTabText(0,"Añadir un cliente");
       ui->tabWidget_5->setTabText(1,"Gestión de clientes");
       ui->tabWidget_5->setTabText(2,"Historial de control");
       //Chef->Clients->Insertion
       ui->label_3->setText("Clientas");
       ui->label_74->setText("Tarjeta de identificación :");
       ui->label_75->setText("Nombre :");
       ui->label_76->setText("Apellido :");
       ui->label_77->setText("Dirección :");
       ui->label_78->setText("Número de teléfono :");
       ui->label_79->setText("Correo :");
       ui->addbutton_2->setText("Agregar");
       ui->homeButton->setText("Menù");
       //Chef->Clients->Gestion
       ui->label_83->setText("Tarjeta de identificación :");
       ui->label_80->setText("Nombre :");
       ui->label_81->setText("Apellido :");
       ui->label_82->setText("Dirección :");
       ui->label_85->setText("Número de teléfono :");
       ui->label_84->setText("Correo :");
       ui->deletebutton_4->setText("Actualizar");
       ui->excel_button_2->setText("Archivo Excel");
       ui->pushButton_3->setText("Editar");
       ui->deletebutton_3->setText("Retirar");
       ui->label_87->setText("Tarjeta de identificación para eliminar :");
       ui->label_86->setText("Buscar :");
       ui->label_88->setText("Ordenar por :");
       ui->comboBox_tri_2->setItemText(0,"CIN Ascendente");
       ui->comboBox_tri_2->setItemText(1,"CIN Descendiente");
       ui->comboBox_tri_2->setItemText(2,"Nombre");
       ui->comboBox_tri_2->setItemText(3,"Apellido");
       //Chef->Clients->Historique
       ui->loadButton_historique_2->setText("Actualizar");
       /*EMPLOYEES*/
       //Chef->Employees
       ui->tabWidget_3->setTabText(0,"Agregar un empleado");
       ui->tabWidget_3->setTabText(1,"Gestión de empleados");
       ui->tabWidget_3->setTabText(2,"Historial de control");
       //Chef->Employees->Insertion
       ui->label_67->setText("Empleados");
       ui->label_Matricule_3->setText("Número de registro :");
       ui->label_Nom_3->setText("Nombre :");
       ui->label_prenom_3->setText("Apellido :");
       ui->label_mail_5->setText("Correo :");
       ui->label_GSM_3->setText("GSM :");
       ui->label_Role_3->setText("Role :");
       ui->label_Salaire_3->setText("Salario :");
       ui->pb_ajouter_3->setText("Agregar");
       ui->options_3->setText("Opciones");
       ui->homeButton_5->setText("Menù");
       //Chef->Employees->Gestion
       ui->label_Matricule_5->setText("Número de registro");
       ui->label_Nom_5->setText("Nombre :");
       ui->label_prenom_5->setText("Apellido :");
       ui->label_mail_6->setText("Correo :");
       ui->label_GSM_5->setText("GSM :");
       ui->label_Role_5->setText("Role :");
       ui->label_Salaire_5->setText("Salario :");
       ui->pb_update_2->setText("Editar");
       ui->label_7->setText("Número de registro");
       ui->pb_supprimer_2->setText("Retirar");
       ui->LoadButton_Historique_3->setText("Actualizar");
       ui->radioButton_tri_personnel_5->setText(" Ordenar por Número");
       ui->radioButton_tri_personnel_6->setText(" Ordenar por Nombre");
       ui->radioButton_tri_personnel_7->setText(" Ordenar por GSM");
       ui->qrCode_2->setText("QR");
       ui->label_45->setText("Buscar");
       //Chef->Employees->Historique
       ui->homeButton_recherche_2->setText("Actualizar");
       /*LIVRAISONS*/
       //Chef->Livraisons
       ui->historique->setTabText(0,"Agregar una entrega");
       ui->historique->setTabText(1,"Gestión de entregas");
       ui->historique->setTabText(2,"Historial de control");
       //Chef->Livraisons->Insertion
       ui->label_4->setText("Entregas");
       ui->label_68->setText("ID de entrega :");
       ui->label_69->setText("Fecha de entrega :");
       ui->label_70->setText("Costo de envío :");
       ui->label_71->setText("Destino :");
       ui->ajouter->setText("Agregar");
       ui->label_34->setText("* Obedezca el formato específico de la fecha : DD-MM-YYYY.");
       ui->label_37->setText("* Obedezca el formato específico del mes : (JAN-FEB...).");
       ui->label_40->setText("* El año debe estar entre 1980 y 2022.");
       ui->homeButton_4->setText("Menù");
       //Chef->Livraisons->Gestion
       ui->label_66->setText("ID de entrega :");
       ui->label_50->setText("Fecha de entrega :");
       ui->label_49->setText("Costo de envío :");
       ui->label_55->setText("Destino :");
       ui->pushButton_5->setText("Editar");
       ui->label_47->setText("ID para eliminar :");
       ui->supprimer2->setText("Retirar");
       ui->label_46->setText("Buscar :");
       ui->label_6->setText("Ordenar con :");
       ui->comboBox_tri->setItemText(0,"Costo");
       ui->comboBox_tri->setItemText(1,"ID de ascendente");
       ui->comboBox_tri->setItemText(2,"ID de descendiente");
       ui->comboBox_tri->setItemText(3,"Destino");
       ui->pushButton->setText("Actualizar");
       ui->pushButton_4->setText("Acceso al sitio web");
       ui->homeButton_11->setText("Menù");
       //Chef->Livraisons->Historique
       ui->pushButton_6->setText("Actualizar");
       ui->pushButton_7->setText("Menù");
       /*COMMANDES*/
       //Chef->Commandes
       ui->tabWidget_6->setTabText(0,"Añadir un pedido");
       ui->tabWidget_6->setTabText(1,"Gestión de pedidos");
       ui->tabWidget_6->setTabText(2,"Historial de control");
       //Chef->Commandes->Insertion
       ui->label_98->setText("Pedidos");
       ui->label_5->setText("Pedido ID :");
       ui->label_92->setText("Pricio :");
       ui->label_93->setText("Fecha :");
       ui->label_94->setText("Cantidad :");
       ui->pb_Ajouter_2->setText("Agregar");
       ui->label_95->setText("* Obedezca el formato específico de la fecha : DD-MM-YYYY.");
       ui->label_96->setText("* Obedezca el formato específico del mes : (JAN-FEB...).");
       ui->label_97->setText("* El año debe estar entre 1980 y 2022.");
       ui->homeButton_3->setText("Menù");
       //Chef->Commandes->Gestion
       ui->supp_text_3->setText("ID para eliminar :");
       ui->supp_Button_3->setText("Retirar");
       ui->label_41->setText("Buscar con ID :");
       ui->label_48->setText("Buscar con Cantidad :");
       ui->modifierButton_recherche_3->setText("Buscar");
       ui->modifierButton_recherche_4->setText("Buscar");
       ui->label_100->setText("Pedido ID :");
       ui->label_102->setText("Pricio :");
       ui->label_99->setText("Fecha :");
       ui->label_101->setText("Cantidad :");
       ui->modifierButton_5->setText("Editar");
       ui->pushButton_stat_2->setText("Estadísticas");
       ui->Paffiche_2->setText("Actualizar");
       ui->pushButton_10->setText("Ordenar con Cantidad");
       ui->pushButton_11->setText("Ordenar con ID");
       ui->homeButton_10->setText("Menù");
       //Chef->Commandes->Historique
       ui->loadButton_historique_3->setText("Actualizar");
       ui->homeButton_12->setText("Menù");







       //LIVREUR * LIVREUR * LIVREUR
       //Livreur->Home
       ui->label_33->setText("Bienvenido, tu eres el repartidor !!");
       ui->prodButton_3->setText("Productos");
       ui->livrButton_3->setText("Entregas");
       ui->empButton_3->setText("Empleados");
       ui->fournisseurButton_3->setText("Proveedores");
       ui->cmdButton_3->setText("Pedidos");
       ui->clButton_3->setText("Clientela");
       ui->pushButton_14->setText("Desconectar");
       /*LIVRAISONS*/
       //Livreur->Livraisons
       ui->historique_5->setTabText(0,"Agregar una entrega");
       ui->historique_5->setTabText(1,"Gestión de entregas");
       ui->historique_5->setTabText(2,"Historial de control");
       //Livreur->Livraisons->Insertion
       ui->label_276->setText("Entregas");
       ui->label_269->setText("ID de entrega :");
       ui->label_270->setText("Fecha de entrega :");
       ui->label_271->setText("Costo de evío :");
       ui->label_272->setText("Destino :");
       ui->ajouter_5->setText("Agregar");
       ui->label_273->setText("* Obedezca el formato específico de la fecha : DD-MM-YYYY.");
       ui->label_274->setText("* Obedezca el formato específico del mes : (JAN-FEB...).");
       ui->label_275->setText("* El año debe estar entre 1980 y 2022.");
       ui->homeButton_45->setText("Menù");
       //Livreur->Livraisons->Gestion
       ui->label_277->setText("ID de entrega :");
       ui->label_278->setText("Fecha de entrega :");
       ui->label_279->setText("Costo de envío :");
       ui->label_280->setText("Destino :");
       ui->pushButton_38->setText("Editar");
       ui->label_283->setText("ID para eliminar :");
       ui->supprimer2_5->setText("Retirar");
       ui->label_282->setText("Buscar :");
       ui->label_281->setText("Ordenar con :");
       ui->comboBox_tri_8->setItemText(0,"Costo");
       ui->comboBox_tri_8->setItemText(1,"ID de ascendente");
       ui->comboBox_tri_8->setItemText(2,"ID de descendiente");
       ui->comboBox_tri_8->setItemText(3,"Destino");   //ó    í
       ui->pushButton_39->setText("Actualizar");
       ui->pushButton_40->setText("Acceso al sitio web");
       ui->homeButton_46->setText("Menù");
       //Livreur->Livraisons->Historique
       ui->pushButton_42->setText("Actualizar");
       ui->pushButton_41->setText("Menù");







       //SIMPLEEMPLOYEE * SIMPLEEMPLOYEE * SIMPLEEMPLOYEE
       //Simpleemployee->Home
       ui->label_36->setText("Bienvenido, tu eres el empleado !!");
       ui->prodButton_4->setText("Productos");
       ui->livrButton_4->setText("Entregas");
       ui->empButton_4->setText("Empleados");
       ui->fournisseurButton_4->setText("Proveedores");
       ui->cmdButton_4->setText("Pedidos");
       ui->clButton_4->setText("Clientela");
       ui->pushButton_15->setText("Desconectar");
       /*FOURNISSEURS*/
       //SimpleEmployee->Fournisseurs
       ui->Lesfournisseurs_4->setText("Proveedores");
       ui->tabWidget_4->setTabText(0,"Añadir un proveedor");
       ui->tabWidget_4->setTabText(1,"Gestión de proveedores");
       //SimpleEmployee->Fournisseurs->Insertion
       ui->textajoutezfournisseur_4->setText("Añadir un proveedor :");
       ui->label_56->setText("Referencia :");//ref
       ui->label_57->setText("Nombre del proveedor :");//nom
       ui->label_58->setText("GSM del proveedor :");//gsm
       ui->label_59->setText("Email del proveedor :");//mail
       ui->label_60->setText("Dirección del proveedor :");//adresse
       ui->ajouterButton_4->setText("Agregar");
       ui->label_61->setText("* La referencia es un número positivo.");
       ui->label_62->setText("* La primera letra del nombre del proveedor debe estar en mayúscula.");
       ui->label_63->setText("* El GSM del proveedor es un número positivo que contiene solo 8 dígitos.");
       ui->label_64->setText("* El correo electrónico del proveedor sigue su forma general.");
       ui->label_65->setText("* La dirección del proveedor puede contener números, letras y símbolos.");
       ui->homeButton_ajouter_4->setText("Menù");
       //SimpleEmployee->Fournisseurs->Gestion
       ui->nb_4->setText("Nota: Haga doble clic en la referencia del proveedor para modificar o eliminar");
       ui->saisir_r_4->setText("Introduzca la referencia del proveedor a buscar:");
       ui->PDFButton_4->setText("Generación de PDF");
       ui->LoadButton_2->setText("Actualizar");
       ui->label_ref_7->setText("Referencia :");
       ui->label_nom_4->setText("Nombre :");
       ui->label_mail_4->setText("Email :");
       ui->label_gsm_4->setText("GSM :");
       ui->label_adresse_4->setText("Dirección :");
       ui->modifierButton_4->setText("Editar");
       ui->label_ref_8->setText("Referencia a eliminar:");
       ui->supprimerButton_5->setText("Retirar");
       ui->TrierButton->setText("Ordenar");
       ui->comboBox_2->setItemText(0,"Referencia");
       ui->comboBox_2->setItemText(1,"Nombre");
       ui->comboBox_2->setItemText(2,"Email");
       ui->homeButton_modifier_4->setText("Menù");
       /*PRODUITS*/
       //SimpleEmployee->Produits
       ui->tabWidget_8->setTabText(0,"Añadir un producto");
       ui->tabWidget_8->setTabText(1,"Gestión de productos");
       ui->tabWidget_8->setTabText(2,"Correo");
       ui->tabWidget_8->setTabText(3,"Vídeo publicitario");
       ui->tabWidget_8->setTabText(4,"Historial de controles");
       //SimpleEmployee->Produits->Insertion
       ui->label_51->setText("Productos");
       ui->label_52->setText("ID :");
       ui->label_72->setText("Nombre :");
       ui->label_73->setText("Video :");
       ui->label_115->setText("Valores :");
       ui->label_116->setText("Precio :");
       ui->label_117->setText("ID Provedoor :");
       ui->valider_2->setText("Agregar");
       ui->homeButton_15->setText("Actualizar");
       //SimpleEmployee->Produits->Gestion
       ui->radioButton_4->setText("Ordenar con ID");
       ui->radioButton_5->setText("Ordenar con Nombre");
       ui->radioButton_6->setText("Ordenar con Precio");
       ui->comboBox_9->setItemText(0,"ID Producto");
       ui->label_118->setText("Identificación");
       ui->pushButton_delete_2->setText("Retirar");
       ui->label_119->setText("Tu opción de búsqueda");
       ui->read_2->setText("Actualizar");
       ui->label_120->setText("ID :");
       ui->label_121->setText("Nombre :");
       ui->label_122->setText("Video :");
       ui->label_123->setText("Valores :");
       ui->label_124->setText("Precio :");
       ui->label_125->setText("ID Provedoor :");
       ui->pushButton_9->setText("Editar");
       ui->homeButton_16->setText("Menù");
       ui->comboBox_10->setItemText(0,"ID Provedoor");
       //SimpleEmployee->Produits->Email
       ui->label_127->setText("Sujeto :");
       ui->label_126->setText("Mensaje :");
       ui->pushButton_mail_2->setText("Enviar");
       ui->pb_gotomail_2->setText("Correo");
       ui->homeButton_17->setText("Actualizar");
       //SimpleEmployee->Produits->Video
       ui->homeButton_20->setText("Actualizar");
       //SimpleEmployee->Produits->Historique
       ui->loadButton_historique_5->setText("Actualizar");
       ui->homeButton_21->setText("Menù");
       /*CLIENTS*/
       //SimpleEmployee->Clients
       ui->tabWidget_7->setTabText(0,"Agregar un cliente");
       ui->tabWidget_7->setTabText(1,"Gestión de clientes");
       ui->tabWidget_7->setTabText(2,"Historial de control");
       //SimpleEmployee->Clients->Insertion
       ui->label_39->setText("Clientes");
       ui->label_89->setText("Tarjeta de identificación :");
       ui->label_90->setText("Nombre :");
       ui->label_91->setText("Apellido :");
       ui->label_103->setText("Dirección :");
       ui->label_104->setText("Número de teléfono :");
       ui->label_105->setText("Correo :");
       ui->addbutton_3->setText("Agregar");
       ui->homeButton_14->setText("Menù");
       //SimpleEmployee->Clients->Gestion
       ui->label_106->setText("Tarjeta de identificación :");
       ui->label_107->setText("Nombre :");
       ui->label_108->setText("Apellido :");
       ui->label_109->setText("Dirección :");
       ui->label_110->setText("Número de teléfono :");
       ui->label_111->setText("Correo :");
       ui->deletebutton_5->setText("Actualizar");
       ui->excel_button_3->setText("Archivo Excel");
       ui->pushButton_8->setText("Editar");
       ui->deletebutton_6->setText("Retirar");
       ui->label_112->setText("Tarjeta de identificación para eliminar :");
       ui->label_113->setText("Buscar :");
       ui->label_114->setText("Ordenar con :");
       ui->comboBox_tri_3->setItemText(0,"CIN Ascendente");
       ui->comboBox_tri_3->setItemText(1,"CIN Descendiente");
       ui->comboBox_tri_3->setItemText(2,"Nombre");
       ui->comboBox_tri_3->setItemText(3,"Apellido");
       ui->homeButton_25->setText("Menù");
       //SimpleEmployee->Clients->Historique
       ui->loadButton_historique_4->setText("Actualizar");
       ui->homeButton_26->setText("Menù");
       /*LIVRAISONS*/
       //SimpleEmployee->Livraisons
       ui->historique_2->setTabText(0,"Agregar una entrega");
       ui->historique_2->setTabText(1,"Gestión de entregas");
       ui->historique_2->setTabText(2,"Historial de control");
       //SimpleEmployee->Livraisons->Insertion
       ui->label_147->setText("Entregas");
       ui->label_141->setText("ID de entrega :");
       ui->label_142->setText("Fecha de entrega :");
       ui->label_143->setText("Costo de evío :");
       ui->label_144->setText("Destino :");
       ui->ajouter_2->setText("Agregar");
       ui->label_54->setText("* Obedezca el formato específico de la fecha : DD-MM-YYYY.");
       ui->label_145->setText("* Obedezca el formato específico del mes : (JAN-FEB...).");
       ui->label_146->setText("* El año debe estar entre 1980 y 2022.");
       ui->homeButton_19->setText("Menù");
       //SimpleEmployee->Livraisons->Gestion
       ui->label_148->setText("ID de entrega :");
       ui->label_149->setText("Fecha de entrega :");
       ui->label_150->setText("Costo de envío :");
       ui->label_151->setText("Destino :");
       ui->pushButton_17->setText("Editar");
       ui->label_154->setText("ID para eliminar :");
       ui->supprimer2_2->setText("Retirar");
       ui->label_153->setText("Buscar :");
       ui->label_152->setText("Ordenar con :");
       ui->comboBox_tri_4->setItemText(0,"Costo");
       ui->comboBox_tri_4->setItemText(1,"ID de ascendente");
       ui->comboBox_tri_4->setItemText(2,"ID de descendiente");
       ui->comboBox_tri_4->setItemText(3,"Destino");   //ó    í
       ui->pushButton_18->setText("Actualizar");
       ui->pushButton_19->setText("Acceso al sitio web");
       ui->homeButton_24->setText("Menù");
       //SimpleEmployee->Livraisons->Historique
       ui->pushButton_21->setText("Actualizar");
       ui->pushButton_20->setText("Menù");
       /*COMMANDES*/
       //SimpleEmployee->Commandes
       ui->tabWidget_9->setTabText(0,"Añadir un pedido");
       ui->tabWidget_9->setTabText(1,"Gestión de pedidos");
       ui->tabWidget_9->setTabText(2,"Historial de control");
       //SimpleEmployee->Commandes->Insertion
       ui->label_131->setText("Pedidos");
       ui->label_53->setText("Pedido ID :");
       ui->label_132->setText("Precio :");
       ui->label_133->setText("Fecha :");
       ui->label_134->setText("Cantidad :");
       ui->pb_Ajouter_3->setText("Agregar");
       ui->label_128->setText("* Obedezca el formato específico de la fecha : DD-MM-YYYY.");
       ui->label_129->setText("* Obedezca el formato específico del mes : (JAN-FEB...).");
       ui->label_130->setText("* El año debe estar entre 1980 y 2022.");
       ui->homeButton_18->setText("Manù");
       //SimpleEmployee->Commandes->Gestion
       ui->supp_text_4->setText("ID para eliminar :");
       ui->supp_Button_4->setText("Retirar");
       ui->label_139->setText("Buscar con ID :");
       ui->label_140->setText("Buscar con cantidad :");
       ui->modifierButton_recherche_5->setText("Buscar");
       ui->modifierButton_recherche_6->setText("Buscar");
       ui->label_135->setText("Pedido ID :");
       ui->label_136->setText("Precio :");
       ui->label_137->setText("Fecha :");
       ui->label_138->setText("Cantidad :");
       ui->modifierButton_7->setText("Editar");
       ui->pushButton_stat_3->setText("Estadísticas");
       ui->Paffiche_3->setText("Actualizar");
       ui->pushButton_13->setText("Ordenar con cantidad");
       ui->pushButton_16->setText("Ordenar con ID");
       ui->homeButton_22->setText("Menù");
       //SimpleEmployee->Commandes->Historique
       ui->loadButton_historique_6->setText("Actualizar");
       ui->homeButton_23->setText("Menù");


   }
}
