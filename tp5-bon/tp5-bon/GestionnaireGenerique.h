/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 6 avril 2018
 * Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
*******************************************/

#pragma once

/****************************************************************************
 * Classe:		GestionnaireGenerique<T, C, A, S, P>
 * Description: Classe qui contient les Foncteurs nécessaires aux classes 
 *              GestionnaireProduits et GestionnaireUsagers
 ****************************************************************************/
template<typename T, typename C, typename A, typename S, typename P>
class GestionnaireGenerique
{
public:
    /****************************************************************************
     * Fonction:		C obtenirConteneur()
     * Description: Retourne le conteneur peu importe son type
     ****************************************************************************/
	C obtenirConteneur()
	{
		return conteneur_;
	}
    
    /****************************************************************************
     * Fonction:		ajouter(T* t)
     * Description: Ajoute un objet au conteneur peu importe son type
     ****************************************************************************/
	void ajouter(T* t)
	{
		A foncteurAjout(conteneur_);
		foncteurAjout(t);
	}
    
    /****************************************************************************
     * Fonction:		supprime(T* t)
     * Description: Supprime un objet du conteneur peu importe son type
     ****************************************************************************/
	void supprimer(T* t)
	{
		S foncteurSupprimer(conteneur_);
		foncteurSupprimer(t);
	}
    
    /****************************************************************************
     * Fonction:		pourChaqueElement(P Predicat)
     * Description:  Prend en paramètre un foncteur qui agira comme un prédicat et
     * l'applique à tous les éléments du conteneur à l’aide d’un for_each.
     ****************************************************************************/
	void pourChaqueElement(P Predicat)
	{
		for_each(conteneur_.begin(), conteneur_.end(), Predicat);
	}
    
protected:
	C conteneur_;
};
