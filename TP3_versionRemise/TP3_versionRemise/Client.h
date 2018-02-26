/********************************************
* Titre: Travail pratique #3 - Client.h
* Date: 24 février 2018
* Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
*******************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Usager.h"
#include "Panier.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"

using namespace std;
class Client : public Usager
{

public:
    //Constructeur
	Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date);
	Client(const Client& client);
    
    //Destructeur
    ~Client();
    
    //Methode d'acces
	long obtenirDateNaissance() const;
	Panier* obtenirPanier() const;

    //Methode de modification
	void modifierDateNaissance(long date);

	void acheter(ProduitOrdinaire * prod);
	void livrerPanier();
	void miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise);
    
    //Surcharge des opérateurs
	Client& operator=(const Client& client);
	friend ostream& operator<<(ostream& os, const Client& client);

private:
	long dateNaissance_;
	Panier *  monPanier_;

};

#endif
