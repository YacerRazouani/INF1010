/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

// TODO : Créer la classe GestionnaireGenerique

// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/

template<typename T, typename C, typename A, typename S, typename P>
class GestionnaireGenerique
{
public:
	C obtenirConteneur()
	{
		return conteneur_;
	}
	void ajouter(T* t)
	{
		A foncteurAjout(conteneur_);
		foncteurAjout(t);
	}
	void supprimer(T* t)
	{
		S foncteurSupprimer(conteneur_);
		foncteurSupprimer(t);
	}
	void pourChaqueElement(P Predicat)
	{
		for_each(conteneur_.begin(), conteneur_.end(), Predicat);
	}
protected:
	C conteneur_;
};