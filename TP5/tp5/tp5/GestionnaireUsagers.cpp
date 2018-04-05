/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double chiffreAffaires = 0.0;
	for (set<Usager*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++){
		chiffreAffaires += (*it)->obtenirTotalAPayer();
	}
	return chiffreAffaires;
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (produit->obtenirPrix() < montant) {
		produit->mettreAJourEnchere(client, montant);
	}
}

void GestionnaireUsagers::reinitialiser()
{
	for (set<Usager*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it)->reinitialiser();
	}
}

void GestionnaireUsagers::afficherProfils() const
{
	cout << "PROFILS" << endl;
	for (set<Usager*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it)->afficher();
	}
	cout << endl;
}
