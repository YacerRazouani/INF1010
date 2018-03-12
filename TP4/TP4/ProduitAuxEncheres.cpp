#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}

void ProduitAuxEncheres::afficher() const
{
    // TODO
	Produit::afficher();
	cout << "prix initial: " << prixInitial_ << endl;
	cout << "encherisseur: " << encherisseur_->obtenirNom() << endl;

}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::modifierEncherisseur(Client * client)
{
	encherisseur_ = client;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
    // TODO
	if (encherisseur_ != encherisseur && nouveauPrix > prix_) {
		prix_ = nouveauPrix;
		encherisseur->ajouterProduit(this);
		if (encherisseur_ != nullptr) {
			encherisseur_->enleverProduit(this);
		}
		modifierEncherisseur(encherisseur);
	}
}
