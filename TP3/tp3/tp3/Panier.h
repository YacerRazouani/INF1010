/********************************************
* Titre: Travail pratique #3 - Panier.h
* Date: 16 fevrier 2018
* Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
*******************************************/

#ifndef PANIER_H
#define PANIER_H

#include <string>
#include <vector>
#include "Produit.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
const double TAUX_TAXE = 0.15;
using namespace std;
class Panier
{

public:
	
	Panier(int idClient);
	~Panier();

	vector<Produit*>  obtenirContenuPanier()const;
	int obtenirNombreContenu() const;
	double obtenirTotalApayer() const;
	double calculerTotalApayer() const ;
	int obtenirIdClient() const;

	void modifierTotalAPayer(double totalAPayer);
	void modifierIdClient(int idClient);

	void ajouter(Produit * prod);
	void livrer();

	Produit* trouverProduitPlusCher();
	friend ostream& operator<<(ostream& os, const Panier & panier);

private:
	double totalAPayer_;
	int idClient_;
	vector<Produit*> contenuPanier_;
	

};

#endif
