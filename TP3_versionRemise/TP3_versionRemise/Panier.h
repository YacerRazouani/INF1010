/********************************************
 * Titre: Travail pratique #3 - Panier.h
 * Date: 25 février 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
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
    
	//Constructeur
	Panier(int idClient);
    //Destructeur
	~Panier();
    
    //Methodes publiques
	vector<Produit*>  obtenirContenuPanier()const;
	int obtenirNombreContenu() const;
	double obtenirTotalApayer() const;
	double calculerTotalApayer() const ;
	int obtenirIdClient() const;

    //Methode de modification
	void modifierTotalAPayer(double totalAPayer);
	void modifierIdClient(int idClient);

	void ajouter(Produit * prod);
	void livrer();

	Produit* trouverProduitPlusCher();
    
    //Surcharge
	friend ostream& operator<<(ostream& os, const Panier & panier);

private:
	double totalAPayer_;
	int idClient_;
	vector<Produit*> contenuPanier_;
	

};

#endif
