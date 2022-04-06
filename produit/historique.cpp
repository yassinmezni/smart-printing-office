/*#include "historique.h"

historique::historique()
{

}
void historique:: save_txt(int id_produit,int qt_stock,int FK_FOURNISSEUR_PR ,QString nom_produit,QString video,int prix_uni)
{
    QFile file ("C:/Users/moham/OneDrive/Bureau/Atelier_Connexion/Atelier_Connexion/historique.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
        // out << "id_produit: "+id_produit+"\nqt_stock: "+qt_stock+"\nprix: "+date+"\nnombre: "+montant+"\n"+genre << "\n";
}
QString historique::imp_hist()
{
    ch="";
       QFile file("C:/Users/moham/OneDrive/Bureau/Atelier_Connexion/Atelier_Connexion/historique.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}*/
