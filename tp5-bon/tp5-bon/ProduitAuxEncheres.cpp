/********************************************
 * Titre: Travail pratique #5 - ProduitAuxEncheres.cpp
 * Date:  6 avril 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/
#include "ProduitAuxEncheres.h"

/****************************************************************************
 * Fonction:   ProduitAuxEncheres::ProduitAuxEncheres()
 * Description: Constructeur par defaut
 * Parametres: (in) : double prix
 * Retour: Aucun
 ****************************************************************************/
ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}
/****************************************************************************
 * Fonction:   ProduitAuxEncheres::ProduitAuxEncheres()
 * Description: Constructeur par paramètre
 * Parametres: (in) : Fournisseur *fournisseur, const string &nom,
 * int reference, double prix
 * Retour: Aucun
 ****************************************************************************/
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

/****************************************************************************
 * Fonction:   ProduitAuxEncheres::obtenirPrixInitial()
 * Description: Retourne la valeur de l'attribut prixInitial_
 * Parametres: Aucun
 * Retour: (out) - double prixInitial_
 ****************************************************************************/
double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}
/****************************************************************************
 * Fonction:   ProduitAuxEncheres::obtenirEncherisseur()
 * Description: Retourne la valeur de l'attribut encherisseur_
 * Parametres: Aucun
 * Retour: (out) - Client* encherisseur_
 ****************************************************************************/
Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}
/****************************************************************************
 * Fonction:   ProduitAuxEncheres::afficher() const
 * Description: Affiche les informations précises sur le produit aux encheres
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void ProduitAuxEncheres::afficher() const
{
    Produit::afficher();
    cout << "\t\t\t\tprix initial:\t" << prixInitial_ << endl
         << "\t\t\t\tencherisseur:\t" << encherisseur_->obtenirNom() << endl;
}
/****************************************************************************
 * Fonction:   ProduitAuxEncheres::modifierPrixInitial()
 * Description: modifie la valeur de l'attribut prixInitial_
 * Parametres: (in) : double prixInitial
 * Retour: Aucun
 ****************************************************************************/
void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}
/****************************************************************************
 * Fonction:   ProduitAuxEncheres::modifierEncherisseur()
 * Description: modifie la valeur de l'attribut enchirisseur_
 * Parametres: (in) : Client *client
 * Retour: Aucun
 ****************************************************************************/
void ProduitAuxEncheres::modifierEncherisseur(Client *encherisseur)
{
    encherisseur_ = encherisseur;
}
/****************************************************************************
 * Fonction:   ProduitAuxEncheres::mettreAJourEnchere()
 * Description: Met a jour les informations sur le produit aux enchere
 * Parametres: (in) : Client *encherisseur , double nouveauPrix
 * Retour: Aucun
 ****************************************************************************/
void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
    if (encherisseur_ == encherisseur)
        return;
    prix_ = nouveauPrix;
    encherisseur->ajouterProduit(this);
    if (encherisseur_ != nullptr)
        encherisseur_->enleverProduit(this);
    encherisseur_ = encherisseur;
}
