/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Client.h"

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ nullptr }
{
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

// Methodes d'acces
string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier();
	monPanier_->ajouter(prod);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

Client & Client::operator=(const Client & client)
{
	if (this == &client) {
		return *this;
	}
	
	nom_ = client.obtenirNom();
	prenom_ = client.obtenirPrenom();
	identifiant_ = client.obtenirIdentifiant();
	codePostal_ = client.obtenirCodePostal();
	dateNaissance_ = client.obtenirDateNaissance();
	for (int i = 0; i < client.obtenirPanier()->obtenirNombreContenu(); i++) {
		monPanier_[i] = client.obtenirPanier()[i];
	}
	return *this;
}

//void Client::afficherPanier() const
//{
//	if (monPanier_ != nullptr) {
//		cout << "Le panier de " << prenom_ << ": " << endl;
//		monPanier_->afficher();
//	}
//	else {
//		cout << "Le panier de " <<prenom_ << " est vide !" << endl;
//	}
//}

bool operator==(const Client client, const int identifiant)
{
	if (client.identifiant_ == identifiant)
		return true;
	else
		return false;
}

bool operator==(const int identifiant, const Client client)
{
	if (identifiant == client.identifiant_)
		return true;
	else
		return false;
}

ostream & operator<<(ostream & o, const Client & client)
{
	if (client.monPanier_ != nullptr) {
		o << "Le panier de " << client.prenom_ << ": " << endl;
		operator<<(o, *client.monPanier_);
	}
	else {
		o << "Le panier de " << client.prenom_ << " est vide !" << endl;
	}
	return o;
}
