/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient) {
	// TODO
	idClient_ = idClient;
	totalAPayer_ = 0;

}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer()  const
{
	 // TODO
	double totalAPayer = totalAPayer_;
	for (unsigned int i = 0; i < contenuPanier_.size(); i++) {
		if (contenuPanier_[i]->retournerType() == 1) {											//Le type 1 est le type ProduitAuxEncheres.
			ProduitAuxEncheres* produit = static_cast<ProduitAuxEncheres*>(contenuPanier_[i]);
			if (produit->obtenirIdentifiantClient() == idClient_) {
				totalAPayer += produit->obtenirPrixBase();
			}
		}
	}
	return totalAPayer;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod)
{
	// TODO
	if (prod->retournerType() == 0) {											//Le type 0 est le type ProduitOrdinaire.
		ProduitOrdinaire* produit = static_cast<ProduitOrdinaire*>(prod);
		if (produit->obtenirEstTaxable()) {
			totalAPayer_ += (produit->obtenirPrix() + (produit->obtenirPrix()* TAUX_TAXE));
		}
	}
	else {
		ProduitAuxEncheres* produit = static_cast<ProduitAuxEncheres*>(prod);
		totalAPayer_ += produit->obtenirPrix();
	}
	contenuPanier_.push_back(prod);
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	// TODO
	for (unsigned int i = 0; i < panier.obtenirContenuPanier().size(); i++) {
		if (panier.obtenirContenuPanier()[i]->retournerType() == 0) {													//Type ProduitOrdinaire.
			ProduitOrdinaire* produit = static_cast<ProduitOrdinaire*> (panier.obtenirContenuPanier()[i]);
			os << *produit;
		}
		if (panier.obtenirContenuPanier()[i]->retournerType() == 1) {													//Type ProduitAuxEncheres.
			ProduitAuxEncheres* produit = static_cast<ProduitAuxEncheres*> (panier.obtenirContenuPanier()[i]);
			os << *produit;
		}
	}
	return os;
}
