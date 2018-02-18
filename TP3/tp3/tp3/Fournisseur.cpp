/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal) : Usager(nom, prenom, identifiant, codePostal)
{
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {
		satisfaction_.niveaux_[i] = 0;
	}
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}

void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit * produit)
{
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit * produit)
{
	for (int i = 0; i < contenuCatalogue_.size(); i++) {
		if (contenuCatalogue_[i] == produit) {												//Trouve le produit corespondant.
			contenuCatalogue_[i] = contenuCatalogue_[contenuCatalogue_.size() - 1];			//Copie le dernier element du vecteur a la position du produit rechercher.
			contenuCatalogue_.pop_back();													//Efface le dernier element du vecteur. 
		}																					//On garde en tete que la position des produits dans le vecteur importait peu.
	}
}

Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
	Usager::operator=(fournisseur);
	return *this;
}

ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
	Usager usager = static_cast<Usager>(fournisseur);
	os << "Fournisseur: ";
	os << usager;
	os << "notes ";
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {
		os << i << ": " << fournisseur.satisfaction_.niveaux_[i] << endl;
	}
	return os;
}
