#include "ProduitSolde.h"

ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}

ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

double ProduitSolde::obtenirPrix() const
{
    // TODO
	double prix = obtenirPrix() - (obtenirPrix() * (obtenirPourcentageRabais() / 100));
	return prix;
}

void ProduitSolde::afficher() const
{
    // TODO
	Produit::afficher();
	cout << "rabais: " << obtenirPourcentageRabais() << "%" << endl;
}
