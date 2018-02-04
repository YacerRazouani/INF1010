/****************************************************************************
 * Fichier: Produit.cpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour : 4 fevrier
 * Description: Implementation de la classe Produit
 ****************************************************************************/

#include "Produit.hpp"
#include <iomanip>

/****************************************************************************
 * Fonction: Produit::Produit()
 * Description: Fusion des Constructeurs par parametre et par défaut
 * Parametres: (in)- (string) nom, (int) reference, (double) prix
 * Retour: aucun
 ****************************************************************************/
Produit::Produit(string nom, int reference, double prix)
{
    // Constructeur
    nom_ = nom;
    reference_ = reference;
    prix_ = prix;
    
}

/****************************************************************************
 * Fonction: Produit::~Produit()
 * Description: Destructeur par defaut
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
Produit::~Produit()
{
    // Destructeur d'un produit
	cout << "Le produit a ete detruit" << endl;
}

/****************************************************************************
 * Fonction:   Produit::obtenirNom() const
 * Description: Retourne l'attribut nom_
 * Parametres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Produit::obtenirNom() const
{
    return nom_;
}

/****************************************************************************
 * Fonction:   Produit::obtenirReference() const
 * Description: Retourne l'attribut reference_
 * Parametres: aucun
 * Retour: (int) la valeur de reference_
 ****************************************************************************/

int Produit::obtenirReference() const
{
    return reference_;
}

/****************************************************************************
 * Fonction:   Produit::obtenirPrix() const
 * Description: Retourne l'attribut prix_
 * Parametres: aucun
 * Retour: (double) la valeur de prix_
 ****************************************************************************/

double Produit::obtenirPrix() const
{
    return prix_;
}

/****************************************************************************
 * Fonction:   Produit::modifierNom()
 * Description: Modifie l'attribut nom_
 * Parametres: (in) - string nom
 * Retour: 
 ****************************************************************************/

void Produit::modifierNom(string nom)
{
    nom_ = nom;
}

/****************************************************************************
 * Fonction:   Produit::modifierReference()
 * Description: Modifie l'attribut reference_
 * Parametres: (in) - int reference
 * Retour:
 ****************************************************************************/

void Produit::modifierReference(int reference)
{
    reference_ = reference;
}

/****************************************************************************
 * Fonction:   Produit::modifierPrix()
 * Description: Modifie l'attribut prix_
 * Parametres: (in) - double prix
 * Retour:
 ****************************************************************************/

void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}

/****************************************************************************
 * Fonction:   Produit::afficher() const
 * Description: Affiche l’etat des attributs.
 * Parametres: aucun
 * Retour:
 ****************************************************************************/

void Produit::afficher() const
{
    cout << setw(60) << "-->Le nom du produit est : " << setw(15) << obtenirNom() << endl;
    cout << setw(66) << "-->La reference du produit est : " << setw(5) << obtenirReference() << endl;
    cout << setw(61) << "-->Le prix du produit est : "<< setw(10) << obtenirPrix() << endl;
}
