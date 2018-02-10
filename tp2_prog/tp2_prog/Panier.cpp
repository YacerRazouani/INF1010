/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Panier.h"

Panier::Panier() :
	//capaciteContenu_{ capacite }
	//nombreContenu_{ 0 },
	//contenuPanier_{ new Produit *[capaciteContenu_] },
	totalAPayer_{ 0 }
{
}

Panier::~Panier()
{
}

// methodes d'accès
vector< Produit* > Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

// méthodes de modification

// autres méthodes
void Panier::ajouter(Produit * prod)
{
	//if (nombreContenu_ >= capaciteContenu_)
	//{
	//	Produit ** temp;
	//	capaciteContenu_ *= 2;
	//	temp = new Produit*[capaciteContenu_];
	//	for (int i = 0; i < nombreContenu_; i++)
	//		temp[i] = contenuPanier_[i];
	//	delete contenuPanier_;
	//	contenuPanier_ = temp;
	//}
	//contenuPanier_[nombreContenu_++] = prod;

	contenuPanier_.push_back(prod);

	totalAPayer_ += prod->obtenirPrix();
}

void Panier::livrer()
{
	//delete[]contenuPanier_;
	//nombreContenu_ = 0;
	//totalAPayer_ = 0;
	//contenuPanier_ = new Produit *[capaciteContenu_];

	contenuPanier_.clear();
	totalAPayer_ = 0;

}

Produit * Panier::trouverProduitPlusCher()
{
	Produit* produitCher = nullptr;
	for (unsigned int i = 0; i < contenuPanier_.size(); i++) {
		if (contenuPanier_[i]->operator>(*contenuPanier_[(i + 1)])) {
			produitCher = contenuPanier_[i];
		}
		else {
			produitCher = contenuPanier_[i + 1];
		}
	}
	return produitCher;
}

//void Panier::afficher() const
//{
//	for (int i = 0; i < nombreContenu_; i++)
//		contenuPanier_[i]->afficher();
//
//	cout << "----> total a payer : " << totalAPayer_ << endl;
//}

ostream & operator<<(ostream & o, const Panier & panier)
{
	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
		operator<<(o, *panier.contenuPanier_[i]);

	o << "----> total a payer : " << panier.totalAPayer_ << endl;
	return o;
}
