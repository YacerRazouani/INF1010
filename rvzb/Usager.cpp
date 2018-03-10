#include "Usager.h"
#include <iostream>

Usager::Usager(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
    : nom_(nom),
      prenom_(prenom),
      identifiant_(identifiant),
      codePostal_(codePostal)
{
}

string Usager::obtenirNom() const
{
    return nom_;
}

string Usager::obtenirPrenom() const
{
    return prenom_;
}

int Usager::obtenirIdentifiant() const
{
    return identifiant_;
}

string Usager::obtenirCodePostal() const
{
    return codePostal_;
}

double Usager::obtenirTotalAPayer() const
{
	return 0;      // car si l'usager est un fournisseur, il n'a rien a payer et si l'usager est un client, alors c'est sa méthode qui sera utilisée.
}

void Usager::afficherProfil() const
{
    // TODO
	cout << " \t " <<obtenirPrenom() << ", " << obtenirNom() << " (" << obtenirIdentifiant() << ")" << endl;
	cout << " \t \t code postal: \t " << obtenirCodePostal() << endl;
}

void Usager::modifierNom(const string &nom)
{
    nom_ = nom;
}

void Usager::modifierPrenom(const string &prenom)
{
    prenom_ = prenom;
}

void Usager::modifierIdentifiant(int identifiant)
{
    identifiant_ = identifiant;
}

void Usager::modifierCodePostal(const string &codePostal)
{
    codePostal_ = codePostal;
}

void Usager::reinitialiser() {
									// Rien à faire, car si usager est un client, ce sera la méthode du client qui sera utilisée. Idem pour fournisseur.
}

void Usager::ajouterProduit(Produit *produit) {
									// Rien à faire, car si usager est un client, ce sera la méthode du client qui sera utilisée. Idem pour fournisseur.
}

void Usager::enleverProduit(Produit *produit) {
									// Rien à faire, car si usager est un client, ce sera la méthode du client qui sera utilisée. Idem pour fournisseur.
}