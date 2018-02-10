/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothee CHAUVIN
*******************************************/

#include "Produit.h"

Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }

// Methodes d'acces
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

double Produit::obtenirPrix() const
{
	return prix_;
}


// Methodes de modification
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

bool Produit::operator>(const Produit& produitAComparer)
{
	return ((nom_ > produitAComparer.obtenirNom()) && (reference_ > produitAComparer.obtenirReference()) && (prix_ > produitAComparer.obtenirPrix()));
}

bool Produit::operator<(const Produit & produitAComparer)
{
	return ((nom_ < produitAComparer.obtenirNom()) && (reference_ < produitAComparer.obtenirReference()) && (prix_ < produitAComparer.obtenirPrix()));
}

bool Produit::operator==(const Produit& produitAComparer)
{
	return ((nom_ == produitAComparer.obtenirNom()) && (reference_ == produitAComparer.obtenirReference()) && ( prix_ == produitAComparer.obtenirPrix()));
}

//void Produit::afficher() const
//{
//	cout << "nom : " << nom_ 
//			  << "\t ref : " << reference_ 
//			  << "\t prix : " << prix_;
//}

istream& operator>>(istream& i, Produit& produit)
{
	 i >> produit.nom_
	    >> produit.reference_
		>> produit.prix_;
	 return i;
}

ostream& operator<<(ostream& o, const Produit& produit)
{
	o << "nom : " << produit.obtenirNom()
		<< "\t ref : " << produit.obtenirReference()
		<< "\t prix : " << produit.obtenirReference();
	return o;
}