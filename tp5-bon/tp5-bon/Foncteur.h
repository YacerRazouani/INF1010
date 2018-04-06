/********************************************
 * Titre: Travail pratique #5 - Foncteur.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 * Modifié par : Amar Ghaly et Yacer Razouani
 *******************************************/

#include <utility>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include "Usager.h"
#include "Produit.h"
#pragma once

using namespace std;



/****************************************************************************
 * Classe:		FoncteurEgal<T>
 * Description: Foncteur predicat qui compare deux objets et retourne vrai si
 *              T* de la pair est égale à t_
 ****************************************************************************/
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

/****************************************************************************
 * Classe:		FoncteurGenerateurId
 * Description: Foncteur générateur d'id unique pour les produits
 *              et les clients en incrémentant de 1 à chaque appel
 ****************************************************************************/
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

/****************************************************************************
 * Classe:		FoncteurDiminuerPourcent
 * Description: Foncteur utilisé par le fournisseur permettant de diminuer le
 *              prix d'un certain pourcentage
 ****************************************************************************/
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

/****************************************************************************
 * Classe:		FoncteurIntervalle
 * Description: Foncteur prédicat utilisé par le GestionnaireProduit afin de trouver
 *              le Produit de la multimap dont le prix est compris entre
 *              borneInf_ et borneSup_
 ****************************************************************************/
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

/****************************************************************************
 * Classe:		AjouterProduit
 * Description: Foncteur permettant l'ajout d'un produit
 *              dans un conteneur de type multimap.
 ****************************************************************************/
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

/****************************************************************************
 * Classe:		SupprimerProduit
 * Description: Foncteur permettant la suppression d'un produit
 *              dans un conteneur de type multimap.
 ****************************************************************************/

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

/****************************************************************************
 * Classe:		AjouterUsager
 * Description: Foncteur permettant l'ajout d'un usager
 *              dans un conteneur de type set.
 ****************************************************************************/
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

/****************************************************************************
 * Classe:		SupprimerUsager
 * Description: Foncteur permettant la suppression d'un usager
 *              dans un conteneur de type set.
 ****************************************************************************/

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

