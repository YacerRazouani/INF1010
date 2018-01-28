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
 * Description: Fusion des Constructeurs par parametre/par défaut
 * ParamËtres: (string) categorie
 * Retour: aucun
 ****************************************************************************/
Rayon::Rayon(string categorie)
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
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Rayon::~Rayon()
{
    // Destructeur d'un rayon
}

/****************************************************************************
 * Fonction:   Rayon::obtenirCategorie()
 * Description: Retourne le nom_
 * ParamËtres: aucun
 * Retour: (string) la valeur de categorie_
 ****************************************************************************/
string Rayon::obtenirCategorie() const
{
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
    if (tousProduits_ == nullptr){								//Si le tableau est nul on rajoute 5 cases.
		capaciteProduits_ = 5;
		tousProduits_ = new Produit*[capaciteProduits_];
		tousProduits_[0] = produit;
    }
	else {
		int i = 0;												// On parcourt le tableau tant qu'on ne trouve pas une case vide. 
		while (tousProduits_[i] != nullptr) {					// Remarque: j'utilise un while et non une boucle for car ca me permet
			i++;												// de sauvegarder la valeur de i (la position dans le tableau).
		}
		if (tousProduits_[i] == nullptr && i < capaciteProduits_) { //Si je trouve une case vide, je rajoute le produit.
			tousProduits_[i] = produit;
		}
		else {													//Sinon je rajoute 5 cases vides. Puis je rajoute le produit.
			for (int j = i; j = i + 5; j++) {
				tousProduits_[j] = new Produit;
			}
			capaciteProduits_ += 5;
			tousProduits_[(i + 1)] = produit;
		}
	}
}

/****************************************************************************
 * Fonction:   Rayon::afficher()
 * Description: Affiche l'état des attributs
 * ParamËtres: aucun
 * Retour:
 ****************************************************************************/

void Rayon::afficher() const
{
    cout << "La categorie du rayon est : " << categorie_ << endl;
    cout << "Le nombre de produits du rayon est : " << nombreProduits_ << endl;
    cout << "La capacité du rayon est : " << capaciteProduits_ << endl;
    
    cout << "Le contenu du rayon est : ";
    if (tousProduits_[0] == nullptr) {
        cout << "vide" << endl;
    }
    else {
        for (int i = 0; i < capaciteProduits_; i++) {
            cout << "Article numero " << (i + 1) << " " << tousProduits_[i]->obtenirNom << " reference: " << tousProduits_[i]->obtenirReference << " prix: " << tousProduis_[i]->obtenirPrix << endl;
        }
    }

    // A COMPLETER;

}
