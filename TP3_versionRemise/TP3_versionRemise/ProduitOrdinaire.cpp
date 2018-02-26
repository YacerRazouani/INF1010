/********************************************
 * Titre: Travail pratique #3 - ProduitOrdinaire.cpp
 * Date: 25 février 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/

#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

/****************************************************************************
 * Fonction: ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string &
 * nom, int reference, double prix, TypeProduit type, bool estTaxable)
 * Description: Constructeur par paramètre utilise le constructeur de la classe Produit
 *              et initialise la valeur de estTaxable
 * Parametres: (in) Fournisseur& fournisseur
 *                  const string& nom
 *				   int reference
 *				   double prix
 *                  TypeProduit type
 *                  bool estTaxable
 * Retour: Aucun
 ****************************************************************************/
ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type, bool estTaxable) : Produit(fournisseur, nom, reference, prix, type)
{
	estTaxable_ = estTaxable;
}

/****************************************************************************
 * Fonction:   ProduitOrdinaire::obtenirEstTaxable() const
 * Description: retourne l'attribut estTaxable_
 * Parametres: aucun
 * Retour: (bool) la valeur de estTaxable_
 ****************************************************************************/
bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_ ;
}

/****************************************************************************
 * Fonction:   ProduitOrdinaire::modifierEstTaxable()
 * Description: Modifie l'attribut estTaxable_
 * Parametres: (in) - bool estTaxable
 * Retour: Aucun
 ****************************************************************************/
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}
/****************************************************************************
 * Fonction: friend ostream & operator<<(ostream& os, const ProduitOrdinaire& produit)
 * Description: Surcharge de l'operateur <<
 * Parametres: (in) ostream& os, const ProduitOrdinaire& produit
 * Retour: (ostream) os.
 ****************************************************************************/
ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	os << "Produit Ordinaire ";
	Produit prod = static_cast<Produit>(produit);
	os << prod;
	os << "est Taxable : ";
	if (produit.obtenirEstTaxable())
		os << "true" << endl << endl;
	else
		os << "false" << endl << endl;
	return os;
}

/****************************************************************************
 * Fonction:friend istream & operator>>(istream & is, ProduitProduitOrdinaire & produit)
 * Description: Surcharge de l'operateur >>
 * Parametres: (in) istream & is, ProduitProduitOrdinaire & produit
 * Retour: (istream) is
 ****************************************************************************/
istream & operator>>(istream & is, ProduitOrdinaire & produit)
{
	Produit prod = static_cast<Produit>(produit);
	is >> prod;
	is >> produit.estTaxable_;
	return is;
}
