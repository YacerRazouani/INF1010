/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 6 avril 2018
* Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
*******************************************/

#include "GestionnaireUsagers.h"

/****************************************************************************
 * Fonction:    GestionnaireUsagers::obtenirChiffreAffaires() const
 * Description: Retourne le montal total du chiffre d'affaires
 * Parametres: Aucun
 * Retour: (double) la valeur de chiffreAffaires
 ****************************************************************************/
double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double chiffreAffaires = 0.0;
	for (set<Usager*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++){
		chiffreAffaires += (*it)->obtenirTotalAPayer();
	}
	return chiffreAffaires;
}
/****************************************************************************
 * Fonction:   GestionnaireUsagers::encherir()
 * Description: Surencheri un produit mis aux enchères en utilisant la fonction
 *              ProduitAuxEncheres::mettreAJourEnchere
 * Parametres: in : Client *client, ProduitAuxEncheres *produit, double montant
 * Retour: Aucun
 ****************************************************************************/
void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (produit->obtenirPrix() < montant) {
		produit->mettreAJourEnchere(client, montant);
	}
}
/****************************************************************************
 * Fonction:  GestionnaireUsager::reinitialiser()
 * Description: Réinitialise le contenu du conteneur_
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void GestionnaireUsagers::reinitialiser()
{
	for (set<Usager*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it)->reinitialiser();
	}
}
/****************************************************************************
 * Fonction:  GestionnaireUsager::afficherProfils()
 * Description: Affiche le contenu de l'attribut conteneur en fonction de son type
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void GestionnaireUsagers::afficherProfils() const
{
	cout << "PROFILS" << endl;
	for (set<Usager*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it)->afficher();
	}
	cout << endl;
}
