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

template<typename T, typename C, typename A, typename S>
class GestionnaireGenerique
{
public:
	obtenirConteneur()
	{
		return conteneur_;
	}
	void ajouter(T* t)
	{
		A foncteurAjout(conteneur_);
		foncteurAjout(t);
	}
	supprimer(T* t)
	{
		S foncteurSupprimer(conteneur_);
		foncteurSupprimer(t);
	}
	pourChaqueElement()
	{

	}
protected:
	C conteneur_;
};