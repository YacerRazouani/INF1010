/********************************************
 * Titre: Travail pratique #3 - ProduitOrdinaire.h
 * Date: 25 février 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/

#ifndef PRODUITORDINAIRE_H
#define PRODUITORDINAIRE_H

#include <string>
#include <iostream>
#include "Produit.h"

class ProduitOrdinaire : public Produit
{

public:
	//Constructeur
	ProduitOrdinaire(Fournisseur& fournisseur, 
		             const string& nom = "outil", int reference = 0,
		             double prix = 0.0, TypeProduit type = TypeProduitOrdinaire,bool estTaxable = true);
    //Methodes publiques
	bool obtenirEstTaxable() const;
	void modifierEstTaxable(bool estTaxable);
    
    //Surcharges de opérateurs
	friend ostream& operator<<(ostream& os, const ProduitOrdinaire& produit);
	friend istream& operator>>(istream& is, ProduitOrdinaire& produit);

private:

	bool estTaxable_;
	
};

#endif
