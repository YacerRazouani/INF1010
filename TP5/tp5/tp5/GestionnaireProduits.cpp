/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"
#include "Fournisseur.h"
#include <algorithm>
#include <functional>

using namespace std::placeholders;

void GestionnaireProduits::reinitialiserClient()
{
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if (ProduitAuxEncheres* produit = dynamic_cast<ProduitAuxEncheres*>((*it).second)) {
			produit->modifierEncherisseur(nullptr);
			produit->modifierPrixInitial(produit->obtenirPrixInitial());
		}
	}
	conteneur_.clear();
}

void GestionnaireProduits::reinitialiserFournisseur()
{
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it).second->modifierFournisseur(nullptr);
	}
	conteneur_.clear();
}

void GestionnaireProduits::afficher()
{
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		cout << (*it).second << endl;
	}
}

double GestionnaireProduits::obtenirTotalAPayer()
{
	double total = 0.0;
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		total += (*it).second->obtenirPrix();
	}
	return total;
}

double GestionnaireProduits::obtenirTotalApayerPremium()
{
	double total = 0.0;
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		double prix = (*it).second->obtenirPrix();
		if (prix > 5)
			prix -= 5;
		if (prix <= 5)
			prix = 0;
		total += prix;
	}
	return total;
}

Produit* GestionnaireProduits::trouverProduitPlusCher()
{
	auto comparaison = [](pair<int,Produit*> a, pair<int,Produit*> b) -> bool {
		return a.second->obtenirPrix() > b.second->obtenirPrix();
	};

	multimap<int, Produit*>::iterator it = max_element(conteneur_.begin(), conteneur_.end(), comparaison);

	return ((*it).second);
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double lw, double hr)
{
	vector<pair<int, Produit*>> produitsEntre;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(produitsEntre), FoncteurIntervalle(lw,hr));

	return produitsEntre;
}

Produit * GestionnaireProduits::obtenirProduitSuivant(Produit* produit)
{	 
	pair<int, Produit*> p = make_pair(produit->obtenirReference(), produit);
	auto it = find_if(conteneur_.begin(), conteneur_.end(), bind(greater<pair<int,Produit*>>(),_1,p));
	return (*it).second;
}
