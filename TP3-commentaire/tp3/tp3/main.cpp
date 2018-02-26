/**************************************************
* Titre: Travail pratique #3 - main.cpp
* Date: 25 février 2018
* Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
**************************************************/

#include "Fournisseur.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int  NB_PRODUCTS = 15;

/**
*Répondez aux questions ici :
* 1/ Il est logique de deriver les classes ProduitOrdinaires et ProduitAuxEncheres de la classe Produit car
*	 ces dernieres possedent toutes les attributs d'un Produit avant tout, ensuite ils ont des attributs 
*	 qui sont propres a leur classes. Bref ils sont tous avant tout des Produit ensuite ils ont des 
*	 caracteristiques qui sont propres a eux.
* 2/
* 2.1 Il est utile d'utiliser static_cast car cela permet de transformer notre Produit en ProduitOrdinaire 
*	  ou ProduitAuxEncheres (une fois que l'on sait a quel classe il appartient) et d'utiliser la surcharge
*	  de l'operateur<< d'une de ces classes pour afficher notre Produit.
* 2.2 On ne pourra pas utiliser la surcharge de l'operateur<< de la classe ProduitOrdinaire ou ProduitAuxEncheres,
*	  car nous pourrions pas distinguer si le produit est ordinaire ou aux encheres. Nous pourrions alors afficher
*	  le produit que en tant que classe Produit.
**/

int main()
{
	// Creez un objet de classe client à l'aide du constructeur
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// creez un objet de la classe client à l'aide du constructeur de copie
	// et modifier son identifiant
	Client maCopie(martine);
	maCopie.modifierIdentifiant(777);

	// vérifier si les copies sont identiques;

	if (maCopie == martine) {
		cout << "clients identitiques" << endl;
	}
	else {
		cout << " non Identiques " << endl;
	}

	Client unAutreClient("Client", "autre", 2222, "h3T3A7", 20180212);
	unAutreClient = maCopie;

	cout << unAutreClient;

	// Creez un fournisseur
	Fournisseur poly = Fournisseur("Ecole", "Polytechnique", 123456789, "H3T 1J4");
	// afficher le fournisseur
	cout << poly;
	// Creation de 15 Produits Ordinaire
	ProduitOrdinaire* produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] =
	{ 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };
	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new ProduitOrdinaire(poly, "p" + to_string(i), i, echantillonPrix[i], TypeProduitOrdinaire, true);

	// Creez un produit aux encheres
	ProduitAuxEncheres* prodAuxEncheres = new ProduitAuxEncheres(poly, "pAuxEncheres", 20,
		100, TypeProduitAuxEncheres);

	// Le client achete les 7 premiers porduits
	for (int i = 0; i < 7; i++)
		martine.acheter(produits[i]);

	// Afficher Panier du client
	cout << martine;

	// afficher le fournisseur
	cout << poly;

	// Client mise sur le produit aux encheres 
	martine.miserProduit(prodAuxEncheres, 500);

	// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;

	// Ma copie mise aussi  sur le produit  aux enchères
	maCopie.miserProduit(prodAuxEncheres, 555);

	// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;

	// Afficher Panier du client
	cout << martine << endl;

	// trouver le produit le plus cher du panier
	cout << " Produit le plus cher "<< *martine.obtenirPanier()->trouverProduitPlusCher();
	
	// livrer le panier du client martine
	martine.livrerPanier();

	// Afficher lefournisseur
	cout << poly << endl;
	
	// Nettoyer la memoire 
	for (int i = 0; i < NB_PRODUCTS;i++) {
		delete produits[i];
	}
	delete prodAuxEncheres;
	
}
