
/****************************************************************************
 * Fichier: Client.cpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 18 février 2018
 * Mise a jour :
 * Description: Implementation de la classe ProduitAuxEncheres
 ****************************************************************************/
#include "ProduitAuxEncheres.h"

/****************************************************************************
 * Fonction: ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type) : Produit(fournisseur, nom, reference, prix, type)
 * Description: Constructeur par parametres et par defaut.
 * Parametres: (in): Fournisseur& fournisseur
 *				    const string& nom
 *				    int reference
 *				    double prix
 *				    TypeProduit type
 * Retour: Aucun
 ****************************************************************************/
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type) : Produit(fournisseur, nom, reference, prix, type)
{
    prixBase_ = 0;
    identifiantClient_ = 0;
}

// Methodes d'acces
/****************************************************************************
 * Fonction:   ProduitAuxEncheres::obtenirIdentifiantClient() const
 * Description: Retourne l'attribut identifiantClient_
 * Parametres: aucun
 * Retour: (int) la valeur de identifiantClient_
 ****************************************************************************/
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
    return identifiantClient_;
}

/****************************************************************************
 * Fonction:   ProduitAuxEncheres::obtenirPrixBase() const
 * Description: Retourne l'attribut prixBase_
 * Parametres: aucun
 * Retour: (double) la valeur de prixBase_
 ****************************************************************************/
double ProduitAuxEncheres::obtenirPrixBase() const
{
    return prixBase_;
}

//Méthode de modification

/****************************************************************************
 * Fonction:   ProduitAuxEncheres::modifierIdentifiantClient()
 * Description: modifie l'attribut identifiantClient_
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
    identifiantClient_ = identifiantClient;
}

/****************************************************************************
 * Fonction:   ProduitAuxEncheres::obtenirPrixBase()
 * Description: Retourne l'attribut prixBase_
 * Parametres: aucun
 * Retour: (double) la valeur de prixBase_
 ****************************************************************************/
void ProduitAuxEncheres::modifierPrixBase(double prixBase )
{
    prixBase_ = prixBase;
}

/****************************************************************************
 * Fonction: istream & operator>>(istream & is, const Client & client)
 * Description: Surcharge de l'operateur >> qui utilise la surcharge de la classe Produit
 * Parametres: (in) ostream & is, const Client & client
 * Retour: is.
 ****************************************************************************/
istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
    Produit prod = static_cast<Produit>(produit);
    is >> prod;
    return is;
}

/****************************************************************************
 * Fonction: ostream & operator<<(ostream & os, ProduitAuxEncheres& produit)
 * Description: Surcharge de l'operateur << permettant d'afficher les attributs d'un produit aux encheres
 * Parametres: (in) ostream & os, const ProduitAuxEncheres& produit
 * Retour: os.
 ****************************************************************************/
ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
    Produit prod = static_cast<Produit>(produit);
    os << "Produit aux enchere" <<  prod;
    os << "Prix de base " << produit.obtenirPrixBase();
    os << "Identifiant Client " << produit.obtenirIdentifiantClient()
    << endl;
    
    return os;
}
