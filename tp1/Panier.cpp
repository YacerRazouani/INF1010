/****************************************************************************
 * Fichier: Panier.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour :
 * Description: Implementation de la classe Panier
 ****************************************************************************/

#include "Panier.hpp"
/****************************************************************************
 * Fonction: Panier::Panier(int capacite)
 * Description: Constructeur par parametre
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Panier::Panier(int capacite)
{
    // Constructeur par parametre
	contenuPanier_ = 0;
	nombreContenu_ = 0;
	capaciteContenu_ = capacite;
	totalAPayer_ = 0;
}

/****************************************************************************
 * Fonction: Panier::obtenirContenuPanier()
 * Description: retourne contenuPanier_
 * ParamËtres: aucun
 * Retour: Produit**
 ****************************************************************************/
Produit** Panier::obtenirContenuPanier()
{
	return contenuPanier_;
}

/****************************************************************************
 * Fonction:   Panier::obtenirNombreContenu()
 * Description: Retourne le nombreContenu_
 * ParamËtres: aucun
 * Retour: int
 ****************************************************************************/
int Panier::obtenirNombreContenu()
{
    return nombreContenu_;
}

/****************************************************************************
 * Fonction:   Panier::obtenirTotalApayer()
 * Description: Retourne totalAPayer_
 * ParamËtres: aucun
 * Retour: double
 ****************************************************************************/

double Panier::obtenirTotalApayer()
{
    return totalAPayer_;
}

/****************************************************************************
 * Fonction:   Panier::ajouter ( Produit * prod)
 * Description: Ajoute le pointeur Produit * prod au tableau de produits
 * ParamËtres: Produit * prod
 * Retour: aucun
 ****************************************************************************/

void Panier::ajouter(Produit * prod)
{
	int i = 0;												
	while (contenuPanier_[i] != nullptr) {
		i++;												
	}
	if (contenuPanier_[i] == nullptr && i < capaciteContenu_) {
		contenuPanier_[i] = prod;
	}
	else {
		for (int j = (capaciteContenu_ - 1); j < (capaciteContenu_ * 2); j++) {
			contenuPanier_[j] = new Produit;
		}
		capaciteContenu_ *= 2;
		contenuPanier_[(i + 1)] = prod;
	}
	totalAPayer_ += prod->obtenirPrix;
}

/****************************************************************************
* Fonction:   Panier::livrer()
* Description: Supprime le contenu du tableau et re-initialise l'etat des autres attributs
* ParamËtres: aucun
* Retour: aucun
****************************************************************************/

void Panier::livrer()
{
	for (int i = 0; i < capaciteContenu_; i++) {
		delete[] contenuPanier_[i];
	}

	delete[] contenuPanier_;
}

/****************************************************************************
 * Fonction:   Panier::afficher()
 * Description: Affiche ...
 * ParamËtres: aucun
 * Retour:
 ****************************************************************************/

void Panier::afficher()
{
	cout << "Le contenu du panier est : ";
	if (contenuPanier_[0] == nullptr) {
		cout << "vide" << endl;
	}
	else {
		for (int i = 0; i < capaciteContenu_; i++) {
			cout << "Article numero " << (i + 1) << " " << contenuPanier_[i]->obtenirNom << " reference: " << contenuPanier_[i]->obtenirReference << " prix: " << contenuPanier_[i]->obtenirPrix << endl;
		}
	}
	cout << "Le nombre de contenu dans le panier est de : " << nombreContenu_ << endl;
	cout << "La capacite du panier est de : " << capaciteContenu_ << endl;
	cout << "Le total a payer est de : " << totalAPayer_ << endl;
}
