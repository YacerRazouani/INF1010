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
	cout << "encherisseur: " << encherisseur_ << endl;

}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}


void ProduitAuxEncheres::modifierEncherisseur(Client* encherisseur) {
    
    encherisseur_ = encherisseur;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client * nouvelEncherisseur, double nouveauPrix)
{
    // TODO
	if (nouvelEncherisseur == nullptr){
		encherisseur_->enleverProduit(this);
        modifierEncherisseur(nouvelEncherisseur);
        modifierPrixInitial(nouveauPrix);
	}
    else if (encherisseur_ != nouvelEncherisseur && nouveauPrix >= prix_) {
        if (encherisseur_ != nullptr){
            encherisseur_->enleverProduit(this);
        }
        modifierEncherisseur(nouvelEncherisseur);
        modifierPrixInitial(nouveauPrix);
        encherisseur_-> ajouterProduit(this);
    }
}
