/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "Produit.h"
#include <map>
#include <algorithm>
#include <set>
#include "Usager.h"
// TODO : Cr�er le FoncteurEgal
template<typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* t) : t_(t)
	{
	}

	bool operator() (pair<int, T*> pair)
	{
		if (t_ == pair.second)
			return 1;
		else
			return 0;
	}
private:
	T* t_;
};

// TODO : Cr�er le FoncteurGenerateurId
/*
Attributs :
- id_;
M�thodes :
- operator(); Incr�menter id_ � chaque appel
*/
class FoncteurGenerateurId
{
public:
	int operator() ()
	{
		return id_++;
	}
private:
	int id_ = 0;
};

// TODO : Cr�er le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
M�thodes :
- operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
*/
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) : pourcentage_(pourcentage)
	{}
	
	void operator() (pair<int, Produit*> pair)
	{
		double nouveauPrix = (pair.second->Produit::obtenirPrix() - (pourcentage_/100.0 * pair.second->Produit::obtenirPrix()));
		pair.second->modifierPrix(nouveauPrix);
	}
private:
	int pourcentage_;
};

// TODO : Cr�er le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
M�thodes :
- operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
*/
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup)
	{}
	bool operator() (pair<int, Produit*> pair)
	{
		if (borneInf_ <= pair.second->obtenirPrix() && pair.second->obtenirPrix() <= borneSup_)
			return 1;
		else
			return 0;
	}
private:
	double borneInf_;
	double borneSup_;
};

// TODO : Cr�er le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
*/
class AjouterProduit
{
public:
	AjouterProduit(multimap<int, Produit*> &multimap) : multimap_(multimap)
	{}
	multimap<int, Produit*>& operator() (Produit* produit)
	{
		multimap_.insert(pair<int, Produit*> (produit->obtenirReference(), produit));
		return multimap_;
	}
private:
	multimap<int, Produit*>& multimap_;
};

// TODO : Cr�er le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
*/

class SupprimerProduit
{
public:
	SupprimerProduit(multimap<int, Produit*> &multimap) : multimap_(multimap)
	{}
	multimap<int, Produit*>& operator() (Produit* produit)
	{
		FoncteurEgal <Produit> foncteurEgal(produit);
		multimap<int, Produit*>::iterator it = find_if(multimap_.begin(), multimap_.end(), foncteurEgal);
		if (it != multimap_.end())
			multimap_.erase(it);
		return multimap_;
	}
private:
	multimap<int, Produit*> &multimap_;
};

//TODO : Cr�er le Foncteur AjouterUsager
/*
Attributs :
- &set;
M�thodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class AjouterUsager
{
public:
	AjouterUsager(set<Usager*> &set) : set_(set)
	{}
	set<Usager*>& operator() (Usager* usager)
	{
		set_.insert(usager);
		return set_;
	}
private:
	set<Usager*> &set_;
};

// Foncteur SupprimerUsager
class SupprimerUsager
{
public:
	SupprimerUsager(set<Usager*> &set) : set_(set)
	{}
	set<Usager*>& operator() (Usager* usager)
	{
		for (set<Usager*>::iterator it = set_.begin(); it != set_.end(); it++) {
			if (*it == usager) {
				set_.erase(it);
			}
		}
		return set_;
	}
private:
	set<Usager*> &set_;
};

