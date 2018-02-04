/****************************************************************************
 * Fichier: Panier.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour : 4 fevrier
 * Description: Implementation de la classe Panier
 ****************************************************************************/

#include "Panier.hpp"
#include <iomanip>

/****************************************************************************
 * Fonction: Panier::Panier(int capacite)
 * Description: Constructeur par parametre
 * Parametres: (in) int capacite
 * Retour: aucun
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
 * Parametres: aucun
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
 * Fonction: Panier::obtenirContenuPanier() const
 * Description: retourne contenuPanier_
 * Parametres: aucun
 * Retour: (Produit**) la valeur de contenuPanier_
 ****************************************************************************/
Produit** Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}

/****************************************************************************
 * Fonction:   Panier::obtenirNombreContenu() const
 * Description: Retourne le nombreContenu_
 * Parametres: aucun
 * Retour: (int) la valeur de nombreContenu_
 ****************************************************************************/
int Panier::obtenirNombreContenu() const
{
    return nombreContenu_;
}

/****************************************************************************
 * Fonction:   Panier::obtenirTotalApayer() const
 * Description: Retourne totalAPayer_
 * Parametres: aucun
 * Retour: (double) la valeur de totalApayer_
 ****************************************************************************/

double Panier::obtenirTotalApayer() const
{
    return totalAPayer_;
}

/****************************************************************************
 * Fonction:   Panier::ajouter ()
 * Description: Ajoute le pointeur Produit * prod au tableau de produits
 * Parametres: (in-out) Produit * prod
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
}

/****************************************************************************
* Fonction:   Panier::livrer()
* Description: Supprime le contenu du tableau et re-initialise l'etat des autres attributs
* Parametres: aucun
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
 * Fonction:   Panier::afficher() const 
 * Description: Affiche le contenu du panier
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/

void Panier::afficher() const
{
	cout << setw(120) << setfill('*') << "*" << endl;
	cout << setw(70) << setfill(' ') << "Le contenu du panier est : " << endl;
	for (int i = 0; i < nombreContenu_; i++) {
		cout << setw(42) << "Article numero " << (i + 1) << " :" << endl << setw(50) << " nom: " << setw(12) << contenuPanier_[i]->obtenirNom() << endl << setw(57) << " reference : " << contenuPanier_[i]->obtenirReference() << endl << setw(52) << " prix : " << setw(6) << contenuPanier_[i]->obtenirPrix() << endl;
	}
	
	cout << "Le nombre de contenu dans le panier est de : " << nombreContenu_ << endl;
	cout << "La capacite du panier est de : " << capaciteContenu_ << endl;
	cout << "Le total a payer est de : " << setprecision(3) << totalAPayer_ << "$" << endl;
}
