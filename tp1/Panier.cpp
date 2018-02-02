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
 * ParamËtres: int capacite * Retour: aucun
 ****************************************************************************/
Panier::Panier(int capacite)
{
    // Constructeur par parametre
	contenuPanier_ = nullptr;
	nombreContenu_ = 0;
	capaciteContenu_ = capacite;
	totalAPayer_ = 0.0;

	//Allocation de l'espace memoire
	if (capacite > 0) {
		contenuPanier_ = new Produit*[capacite];
	}
	

}
/****************************************************************************
 * Fonction: Panier::~Panier()
 * Description: Destructeur par defaut
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Panier::~Panier()
{
    // Destructeur d'un panier
	delete[] contenuPanier_;
	contenuPanier_ = nullptr;
	cout << "Le panier a ete detruit" << endl;
}

/****************************************************************************
 * Fonction: Panier::obtenirContenuPanier()
 * Description: retourne contenuPanier_
 * Parametres: aucun
 * Retour: Produit**
 ****************************************************************************/
Produit** Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}

/****************************************************************************
 * Fonction:   Panier::obtenirNombreContenu()
 * Description: Retourne le nombreContenu_
 * ParamËtres: aucun
 * Retour: int
 ****************************************************************************/
int Panier::obtenirNombreContenu() const
{
    return nombreContenu_;
}

/****************************************************************************
 * Fonction:   Panier::obtenirTotalApayer()
 * Description: Retourne totalAPayer_
 * ParamËtres: aucun
 * Retour: double
 ****************************************************************************/

double Panier::obtenirTotalApayer() const
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
	if (nombreContenu_ == capaciteContenu_) {
		int capaciteNouveauTableau = capaciteContenu_ * 2;
		Produit** nouveauTableau = new Produit*[capaciteNouveauTableau];
		for (int i = 0; i < nombreContenu_; i++) {
			nouveauTableau[i] = contenuPanier_[i];
		}
		delete[] contenuPanier_;
		capaciteContenu_ = capaciteNouveauTableau;
		contenuPanier_ = nouveauTableau;
		contenuPanier_[nombreContenu_++] = prod;
	}

	else {
		contenuPanier_[nombreContenu_++] = prod;
	}

	totalAPayer_ = totalAPayer_ + prod->obtenirPrix();

	//else {
	//	if (capaciteContenu_ == 0) {
	//		capaciteContenu_ = 1;
	//	}
	//	int capaciteNouveauTableau = capaciteContenu_ * 2;
	//	Produit** nouveauTableau = new Produit*[capaciteContenu_];
	//	for (int i = 0; i < capaciteContenu_; i++) {
	//		nouveauTableau[i] = contenuPanier_[i];
	//	}
	//	delete[] contenuPanier_;
	//	capaciteContenu_ *= 2;
	//	contenuPanier_ = nouveauTableau;
	//	while (contenuPanier_[i] != nullptr) {
	//		i++;
	//	}
	//	if (contenuPanier_[i] == nullptr && i < capaciteContenu_) {
	//		contenuPanier_[i] = prod;
	//	}
	//}
	//totalAPayer_ = totalAPayer_ + prod->obtenirPrix();
}

/****************************************************************************
* Fonction:   Panier::livrer()
* Description: Supprime le contenu du tableau et re-initialise l'etat des autres attributs
* ParamËtres: aucun
* Retour: aucun
****************************************************************************/

void Panier::livrer()
{

	for (int i = 0; i < nombreContenu_; i++) {
		contenuPanier_[i] = nullptr;
		
	}
	nombreContenu_ = 0;
	capaciteContenu_ = 0;
	totalAPayer_ = 0.0;
}

/****************************************************************************
 * Fonction:   Panier::afficher()
 * Description: Affiche ...
 * ParamËtres: aucun
 * Retour:
 ****************************************************************************/

void Panier::afficher() const
{
	cout << "Le contenu du panier est : " << endl;
	for (int i = 0; i < nombreContenu_; i++) {
		cout << "Article numero " << (i + 1) << " " << contenuPanier_[i]->obtenirNom() << " reference: " << contenuPanier_[i]->obtenirReference() << " prix: " << contenuPanier_[i]->obtenirPrix() << endl;
	}
	
	cout << "Le nombre de contenu dans le panier est de : " << nombreContenu_ << endl;
	cout << "La capacite du panier est de : " << capaciteContenu_ << endl;
	cout << "Le total a payer est de : " << totalAPayer_ << endl;
}
