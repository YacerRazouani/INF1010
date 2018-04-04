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
// TODO : Créer le FoncteurEgal
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

// TODO : Créer le FoncteurGenerateurId
/*
Attributs :
- id_;
Méthodes :
- operator(); Incrémenter id_ à chaque appel
*/
class FoncteurGenerateurId
{
public:
	void operator() ()
	{
		id_++;
	}
private:
	int id_ = 0;
};

// TODO : Créer le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
Méthodes :
- operator(); Calule le nouveau prix du Produit de la pair passé en paramètre et le modifie
*/
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) : pourcentage_(pourcentage)
	{}
	
	void operator() (pair<int, Produit*> pair)
	{
		int nouveauPrix = ((pair.second)->obtenirPrix() - (pair.first * (pair.second)->obtenirPrix()));
		(pair.second)->modifierPrix(nouveauPrix);
	}
private:
	int pourcentage_;
};

// TODO : Créer le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
Méthodes :
- operator(); Vérifie que le Produit associé à la pair passé en paramètre est compris entre les bornes borneInf_ et borneSup_ (retourne un booléen)
*/
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup)
	{}
	bool operator() (pair<int, Produit*> pair)
	{
		if (borneInf_ < pair.second->obtenirPrix() && pair.second->obtenirPrix() < borneSup_)
			return 1;
		else
			return 0;
	}
private:
	double borneInf_;
	double borneSup_;
};

// TODO : Créer le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Ajoute dans la multimap la pair passé par paramètre et retourne la multimap_;
*/
class AjouterProduit
{
public:
	AjouterProduit(multimap<int, Produit*> &multimap) : multimap_(multimap)
	{}
	void operator() (Produit* produit)
	{
		multimap_.insert(pair<int, Produit*> (produit->obtenirReference(), produit));
	}
private:
	multimap<int, Produit*> multimap_;
};

// TODO : Créer le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/
template<typename T>
class SupprimerProduit
{
public:
	SupprimerProduit(multimap<int, Produit*> &multimap) : multimap_(multimap)
	{}
	void operator() (Produit* produit)
	{
		FoncteurEgal foncteurEgal = FoncteurEgal(produit);
		multimap<int, Produit*>::iterator it = find_if(multimap_.begin(), multimap_.end(), foncteurEgal());
		if (it != multimap_.end())
			multimap_.erase(it);
	}
private:
	multimap<int, Produit*> &multimap_;
};

//TODO : Créer le Foncteur AjouterUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class AjouterUsager
{
public:
	AjouterUsager(set<Usager*> set) : set_(set)
	{}
	void operator() (Usager* usager)
	{
		set_.insert(usager);
	}
private:
	set<Usager*> &set_;
};


template<typename T>
class SupprimerUsager
{
public:
	SupprimerUsager(set<Usager*> set) : set_(set)
	{}
	void operator() (Usager* usager)
	{
		FoncteurEgal foncteurEgal = FoncteurEgal(produit);
		set<Usager*>::iterator it = find_if(set_.begin(), set_.end(), foncteurEgal());
		if (it != set_.end())
			set_.erase(it);
	}
private:
	set<Usager*> &set_;
};

