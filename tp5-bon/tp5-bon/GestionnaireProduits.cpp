/********************************************
 * Titre: Travail pratique #5 - GestionnaireProduits.h
 * Date: 6 avril 2018
 * Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/

/****************************************************************************
 * Fonction:   Gestionnaire::obtenirUsagers() const
 * Description: Retourne le vecteurs contenant des pointeurs d'usagers
 * Parametres: Aucun
 * Retour: (out) vector<Usager*> - la valeur de l'attribut usagers_
 ****************************************************************************/
#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"
#include "Fournisseur.h"
#include <algorithm>
#include <functional>

using namespace std::placeholders;

/****************************************************************************
 * Fonction:  GestionnaireProduits::reinitialiserClient()
 * Description:Réinitialise les informations du client (panier etc..)
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void GestionnaireProduits::reinitialiserClient()
{
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if (ProduitAuxEncheres* produit = dynamic_cast<ProduitAuxEncheres*>((*it).second)) {
			produit->modifierEncherisseur(nullptr);
			produit->modifierPrix(produit->obtenirPrixInitial());
		}
	}
	conteneur_.clear();
}

/****************************************************************************
 * Fonction:  GestionnaireProduits::reinitialiserFournisseur()
 * Description: Réinitialise les informations du fournisseur (catalogue etc..)
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void GestionnaireProduits::reinitialiserFournisseur()
{
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it).second->modifierFournisseur(nullptr);
	}
	conteneur_.clear();
}
/****************************************************************************
 * Fonction:  GestionnaireProduits::afficher()
 * Description: Affiche le contenu de l'attribut conteneur en fonction de son type
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void GestionnaireProduits::afficher()
{
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
        (*it).second -> afficher();
	}
}
/****************************************************************************
 * Fonction:    GestionnaireProduits::obtenirTotalAPayer()
 * Description: Retourne le montal total du panier ou du catalogue
 * Parametres: Aucun
 * Retour: (double) la valeur de total
 ****************************************************************************/
double GestionnaireProduits::obtenirTotalAPayer()
{
	double total = 0.0;
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		total += (*it).second->obtenirPrix();
	}
	return total;
}
/****************************************************************************
 * Fonction:    GestionnaireProduits::obtenirTotalAPayerPremium()
 * Description: Retourne le montal total du panier en tenant compte du rabais
 *              de 5$ pour chaque article
 * Parametres: Aucun
 * Retour: (double) la valeur de total
 ****************************************************************************/
double GestionnaireProduits::obtenirTotalApayerPremium()
{
    double prix = 0;
    double totalPremium = 0;
    for(multimap<int,Produit*>::iterator it = conteneur_.begin(); it != conteneur_.end(); ++it){
        prix = (*it).second->obtenirPrix();
        totalPremium += prix < 5 ? 0 : prix - 5;
    }
    return totalPremium;
}

/****************************************************************************
 * Fonction:   GestionnaireProduits::trouverProduitPlusCher() const
 * Description: Retourne le produit le plus cher du conteneur
 * Parametres: aucune
 * Retour: (out) Produit* - produit le plus cher
 ****************************************************************************/
Produit* GestionnaireProduits::trouverProduitPlusCher()
{
	if (conteneur_.empty())
		return nullptr;
	auto comparaison = [](pair<int,Produit*> a, pair<int,Produit*> b) -> bool {
		return a.second->obtenirPrix() < b.second->obtenirPrix();
	};

	multimap<int, Produit*>::iterator it = max_element(conteneur_.begin(), conteneur_.end(), comparaison);

	return (*it).second;
}
/****************************************************************************
 * Fonction:  GestionnaireProduits::obtenirProduitsEntre()
 * Description: Retourne les produits contenus dans l'intervalle des deux bornes
 *  passées en paramètres
 * Parametres: (in) double lw, double hr
 * Retour: (out) vector<pair<int, Produit*>> - produitsEntre
 ****************************************************************************/
vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double lw, double hr)
{
	vector<pair<int, Produit*>> produitsEntre;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(produitsEntre), FoncteurIntervalle(lw,hr));

	return produitsEntre;
}

/****************************************************************************
 * Fonction:  GestionnaireProduits::obtenirProduitSuivant()
 * Description: Retourne le produit suivant celui passé en paramètres
 * Parametres: (in) Produit* produit
 * Retour: (out) Produit* - le produit pointé par l'iterateur it
 ****************************************************************************/
Produit * GestionnaireProduits::obtenirProduitSuivant(Produit* produit)
{	 
	pair<int, Produit*> p = make_pair(produit->obtenirReference(), produit);
	auto it = find_if(conteneur_.begin(), conteneur_.end(), bind(greater<pair<int,Produit*>>(),_1,p));
	return (*it).second;
}
