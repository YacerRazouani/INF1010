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
	cout << " \t \t prix initial: \t $" << prixInitial_ << endl;
	cout << " \t \t encherisseur: \t " << encherisseur_->obtenirNom() << endl;

}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::modifierEncherisseur(Client* client) {

	encherisseur_ = client;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
	if (encherisseur == nullptr) {
		encherisseur_->enleverProduit(this);
		modifierEncherisseur(encherisseur);
		modifierPrix(nouveauPrix);
	}
	else if (encherisseur != encherisseur_ && nouveauPrix > prix_) {

		if (encherisseur_ != nullptr)
			encherisseur_->enleverProduit(this);

		modifierEncherisseur(encherisseur);
		modifierPrix(nouveauPrix);
		encherisseur_->ajouterProduit(this);
	}
}

