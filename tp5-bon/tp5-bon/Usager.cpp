/********************************************
 * Titre: Travail pratique #5 - Usager.cpp
 * Date: 10 mars 2018
 * Modifier par: -
 *******************************************/
#include "Usager.h"
#include <iostream>

Usager::Usager(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
    : nom_(nom),
      prenom_(prenom),
      reference_(identifiant),
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

int Usager::obtenirReference() const
{
    return reference_;
}

string Usager::obtenirCodePostal() const
{
    return codePostal_;
}

double Usager::obtenirTotalAPayer() const
{
    return 0;
}

void Usager::afficher() const
{
    cout << "\t\t" << nom_ << ", " << prenom_ << " (" << reference_ << ")" << endl
        << "\t\t\t\tcode postal:\t" << codePostal_ << endl;
}

void Usager::modifierNom(const string &nom)
{
    nom_ = nom;
}

void Usager::modifierPrenom(const string &prenom)
{
    prenom_ = prenom;
}

void Usager::modifierReference(int identifiant)
{
	reference_ = identifiant;
}

void Usager::modifierCodePostal(const string &codePostal)
{
    codePostal_ = codePostal;
}
