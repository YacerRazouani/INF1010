/********************************************
 * Titre: Travail pratique #5 - ProduitSolde.cpp
 * Date: 6 avril 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/
#include "ProduitSolde.h"

/****************************************************************************
 * Fonction:   ProduitSolde::ProduitSolde()
 * Description: Constructeur par defaut
 * Parametres: (in) : int pourcentageRabais
 * Retour: Aucun
 ****************************************************************************/
ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}
/****************************************************************************
 * Fonction:   ProduitSolde::ProduitSolde()
 * Description: Constructeur par paramètre
 * Parametres: (in) :Fournisseur *fournisseur, const string &nom,
 * int reference, double prix, int pourcentageRabais
 * Retour: Aucun
 ****************************************************************************/
ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

/****************************************************************************
 * Fonction:   ProduitSolde::obtenirPrix() const
 * Description: Retourne la valeur du nouveau prix soldé
 * Parametres: aucun
 * Retour: (double) la valeur de prix_
 ****************************************************************************/
double ProduitSolde::obtenirPrix() const
{
    return round(prix_ * ((100 - pourcentageRabais_) / 100.0));
}

/****************************************************************************
 * Fonction:   ProduitSolde::afficher() const
 * Description: Affiche les informations précises sur le produit en solde
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void ProduitSolde::afficher() const
{
    Produit::afficher();
    cout << "\t\t\t\trabais:\t\t\t" << pourcentageRabais_ << "%" << endl;
}
