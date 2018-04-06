/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 6 avril 2018
* Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Produit.h"
#include <vector>
#include <map>
#include "Foncteur.h"


class GestionnaireProduits : public GestionnaireGenerique <Produit, multimap<int, Produit*>, AjouterProduit, SupprimerProduit, FoncteurDiminuerPourcent>
{
public:
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher();
	double obtenirTotalAPayer();
	double obtenirTotalApayerPremium();
	Produit* trouverProduitPlusCher();
	vector<pair<int, Produit*>> obtenirProduitsEntre(double lw, double hr);
	Produit* obtenirProduitSuivant(Produit*);
};
