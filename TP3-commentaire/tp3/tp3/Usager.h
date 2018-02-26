/********************************************
 * Titre: Travail pratique #3 -Usager.h
 * Date: 24 janvier 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/

#ifndef USAGER_H
#define USAGER_H

#include <string>
#include <iostream>
using namespace std;
class Usager
{

public:
    //Constructeur
	Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal);
    
	//Methodes d'acces
	string obtenirNom() const;
	string obtenirPrenom() const;
	int obtenirIdentifiant() const;
	string obtenirCodePostal() const;	
	
	//Methode de modifications
	void modifierNom(const string& nom);
	void modifierPrenom(const string & prenom);
	void modifierIdentifiant(int identifiant);
	void modifierCodePostal(const string & codePostal);
    
    //Surcharge des operateurs
	Usager & operator=(const Usager& usager);
	bool operator==(int identifiant) const;
	bool operator == (const Usager & usager);
	friend bool operator==(int identifiant, const Usager& usager);
	friend ostream& operator<<(ostream& os, const Usager& u);

private:
	string nom_;
	string prenom_;
	int identifiant_;
	string codePostal_;
	
};

#endif
