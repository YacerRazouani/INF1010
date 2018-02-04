/****************************************************************************
 * Fichier: Rayon.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour : 4 fevrier
 * Description: Implementation de la classe Rayon
 ****************************************************************************/

#include "Rayon.hpp"
#include "Produit.hpp"
#include <iomanip>

/****************************************************************************
 * Fonction: Rayon::Rayon()
 * Description: Fusion des Constructeurs par parametre/par defaut
 * Parametres: (string) categorie, (Produit **) tousProduits, (int) capaciteProduits, (int) nombreProduit
 * Retour: aucun
 ****************************************************************************/
Rayon::Rayon(string categorie, Produit ** tousProduits, int capaciteProduits, int nombreProduits)
{
    // Constructeur
    categorie_ = categorie;
    tousProduits_ = nullptr;
    capaciteProduits_ = 0;
    nombreProduits_ = 0;
    
}


/****************************************************************************
 * Fonction: Rayon::~Rayon()
 * Description: Destructeur par defaut
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
Rayon::~Rayon()
{
    // Destructeur d'un rayon
	cout << "Le rayon a ete detruit" << endl;
}

/****************************************************************************
 * Fonction:   Rayon::obtenirCategorie() const
 * Description: Retourne le nom_
 * Parametres: aucun
 * Retour: (string) la valeur de categorie_
 ****************************************************************************/
string Rayon::obtenirCategorie() const
{
    return categorie_;
}

/****************************************************************************
 * Fonction:   Rayon::obtenirTousProduits() const
 * Description: Retourne tousProduits_
 * Parametres: aucun
 * Retour: (Produit**) la valeur de tousProduits_
 ****************************************************************************/

Produit** Rayon::obtenirTousProduits() const
{
    return tousProduits_;
}

/****************************************************************************
 * Fonction:   Rayon::obtenirNombreProduits() const
 * Description: Retourne nombreProduits_
 * Parametres: aucun
 * Retour: (int) la valeur de nombreProduits_
 ****************************************************************************/

int Rayon::obtenirNombreProduits() const
{
    return nombreProduits_;
}
/****************************************************************************
* Fonction:   Rayon::obtenirCapaciteProduits() const
* Description: Retourne capaciteProduits_
* Parametres: aucun
* Retour: (int) la valeur de capaciteProduits_
****************************************************************************/

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

/****************************************************************************
 * Fonction:   Rayon::modifierCategorie()
 * Description: Modifie l'attribut categorie_
 * Parametres: (in) - string caterogie
 * Retour: aucun
 ****************************************************************************/

void Rayon::modifierCategorie (string categorie)
{
    categorie_ = categorie;
}

/****************************************************************************
 * Fonction:   Rayon::ajouterProduits()
 * Description: Modifie l'attribut tousProduits_
 * Parametres: (in-out) - Produit* produit
 * Retour:
 ****************************************************************************/

void Rayon::ajouterProduit(Produit * produit)
{

	if (tousProduits_ == nullptr){											
		capaciteProduits_ = 5;
		tousProduits_ = new Produit* [capaciteProduits_];
		tousProduits_[nombreProduits_++] = produit;
	}
	
	else if (tousProduits_ != nullptr && nombreProduits_ == capaciteProduits_) {
		int capaciteNouveauTableau = capaciteProduits_ + 5;
		Produit** nouveauTableau = new Produit*[capaciteNouveauTableau];
		for (int i = 0; i < nombreProduits_; i++) {
			nouveauTableau[i] = tousProduits_[i];
		}
		delete[] tousProduits_;
		capaciteProduits_ += 5;
		tousProduits_ = nouveauTableau;
		tousProduits_[nombreProduits_++] = produit;
	}

	else if (tousProduits_ != nullptr) {
		tousProduits_[(nombreProduits_++)] = produit;
	}

	
}

/****************************************************************************
 * Fonction:   Rayon::afficher() const
 * Description: Affiche l'état des attributs
 * Parametres: aucun
 * Retour:
 ****************************************************************************/

void Rayon::afficher() const
{
	
	cout << setw(120) << setfill('*') << "*" << endl;
	cout << setw(60) << setfill(' ') << "->La categorie du rayon est : " << categorie_ << "<-" << endl;
    cout << setw(65) << "- Le nombre de produits du rayon est : " << nombreProduits_ << endl;
    cout << setw(55) << "- La capacite du rayon est : " << capaciteProduits_ << endl;
    
	cout << setw(54) << "- Le contenu du rayon est : " << endl;

	for (int i = 0; i < nombreProduits_; i++) {
		tousProduits_[i]->afficher();
	}
	cout << setw(120) << setfill('*') << "*" << endl;
	cout << setfill(' ');


}
