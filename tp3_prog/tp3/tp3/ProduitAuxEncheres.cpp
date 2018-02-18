/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type) : Produit(fournisseur, nom, reference, prix, type)
{
	prixBase_ = 0;
	identifiantClient_ = 0;
}

int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

istream & operator>>(istream & is, ProduitAuxEncheres & produit)
{
	Produit prod = static_cast<Produit>(produit);
	is >> prod;
	return is;
}

ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	os << "Produit aux encheres ";
	Produit prod = static_cast<Produit>(produit);
	os << prod;
	os << "Prix de base " << produit.obtenirPrixBase() << endl;
	os << "Identifiant Client " << produit.obtenirIdentifiantClient() << endl << endl;
	return os;
}