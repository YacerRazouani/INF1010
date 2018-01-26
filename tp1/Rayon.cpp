/****************************************************************************
 * Fichier: Rayon.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour :
 * Description: Implementation de la classe Rayon
 ****************************************************************************/

#include "Rayon.hpp"
#include "Produit.hpp"
/****************************************************************************
 * Fonction: Rayon::Rayon()
 * Description: Constructeur par dÈfaut
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Rayon::Rayon()
{
    // Constructeur par defaut
    categorie_ = "inconnu";
    tousProduits_ = nullptr;
    capaciteProduits_ = 0;
    nombreProduits_ = 0;
    
}

/****************************************************************************
 * Fonction: Rayon::Rayon()
 * Description: Constructeur par parametre
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Rayon::Rayon(string categorie)
{
    // Constructeur par defaut
    categorie_ = categorie;
    tousProduits_ = nullptr;
    capaciteProduits_ = 0;
    nombreProduits_ = 0;
    
}


/****************************************************************************
 * Fonction: Rayon::~Rayon()
 * Description: Destructeur par defaut
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Rayon::~Rayon()
{
    // Destructeur d'un produit
}

/****************************************************************************
 * Fonction:   Rayon::obtenirCategorie()
 * Description: Retourne le nom_
 * ParamËtres: aucun
 * Retour: (string) la valeur de categorie_
 ****************************************************************************/
string Rayon::obtenirCategorie() const
{
    return categorie_;
}

/****************************************************************************
 * Fonction:   Rayon::obtenirTousProduits() const
 * Description: Retourne tousProduits_
 * ParamËtres: aucun
 * Retour: (Produit) la valeur de tousProduits_
 ****************************************************************************/

Produit** Rayon::obtenirTousProduits() const
{
    return tousProduits_;
}

/****************************************************************************
 * Fonction:   Rayon::obtenirNombreProduits() const
 * Description: Retourne nombreProduits_
 * ParamËtres: aucun
 * Retour: (int) la valeur de nombreProduits_
 ****************************************************************************/

int Rayon::obtenirNombreProduits() const
{
    return nombreProduits_;
}
/****************************************************************************
* Fonction:   Rayon::obtenirCapaciteProduits() const
* Description: Retourne capaciteProduits_
* ParamËtres: aucun
* Retour: (int) la valeur de capaciteProduits_
****************************************************************************/

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

/****************************************************************************
 * Fonction:   Rayon::modifierCategorie()
 * Description: Modifie l'attribut categorie_
 * ParamËtres: string caterogie
 * Retour: aucun
 ****************************************************************************/

void Rayon::modifierCategorie (string categorie)
{
    categorie_ = categorie;
}

/****************************************************************************
 * Fonction:   Rayon::ajouterProduits()
 * Description: Modifie l'attribut tousProduits_
 * ParamËtres: Produit* produit
 * Retour:
 ****************************************************************************/

void Rayon::ajouterProduit(Produit * produit)
{
    /*A COMPLETER ; ajoute le pointeur d’un objet produit au tableau
    dynamique. Si le tableau est null, on crée le tableau initial avec une capacité de 5. Si le
    tableau est non null et que la capacité est atteinte, on augmente la capacité de 5 du tableau
    */
    if (tousProduits_ == nullptr){								//Si le tableau est nul on rajoute 5 cases.
		tousProduits_ = new Produit*[5];
		tousProduits_[0] = produit;
    }
	else {
		int i = 0;												// On parcourt le tableau tant qu'on ne trouve pas une case vide. 
		while (tousProduits_[i] != nullptr) {					// Remarque: j'utilise un while et non une boucle for car ca me permet
			i++;												// de sauvegarder la valeur de i.
		}
		if (tousProduits_[i] == nullptr) {						//Si je trouve une case vide, je rajoute le produit.
			tousProduits_[i] = produit;
		}
		else {													//Sinon je rajoute 5 cases vides. Puis je rajoute le produit.
			for (int j = i; j = i + 5; j++) {
				tousProduits_[j] = new Produit;
			}
			tousProduits_[(i + 1)] = produit;
		}
	}
}

/****************************************************************************
 * Fonction:   Produit::afficher()
 * Description: Affiche ...
 * ParamËtres: aucun
 * Retour:
 ****************************************************************************/

void Rayon::afficher()
{
    cout << "La categorie est : " << categorie_ << endl;
    cout << "Le nombre de produit est : " << nombreProduits_ << endl;
    cout << "La capacité est : " << capaciteProduits_ << endl;
    // A COMPLETER;

}
