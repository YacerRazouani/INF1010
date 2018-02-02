/****************************************************************************
 * Fichier: Produit.cpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour :
 * Description: Implementation de la classe Produit
 ****************************************************************************/

#include "Produit.hpp"

/****************************************************************************
 * Fonction: Produit::Produit()
 * Description: Fusion des Constructeurs par parametre et par défaut
 * ParamËtres: (string) nom, (int) reference, (double) prix
 * Retour: aucun
 ****************************************************************************/
Produit::Produit(string nom, int reference, double prix)
{
    // Constructeur par parametre
    nom_ = nom;
    reference_ = reference;
    prix_ = prix;
    
}

/****************************************************************************
 * Fonction: Produit::~Produit()
 * Description: Destructeur par defaut
 * ParamËtres: aucun
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
 * ParamËtres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Produit::obtenirNom() const
{
    return nom_;
}

/****************************************************************************
 * Fonction:   Produit::obtenirReference() const
 * Description: Retourne l'attribut reference_
 * ParamËtres: aucun
 * Retour: (int) la valeur de reference_
 ****************************************************************************/

int Produit::obtenirReference() const
{
    return reference_;
}

/****************************************************************************
 * Fonction:   Produit::obtenirPrix() const
 * Description: Retourne l'attribut prix_
 * ParamËtres: aucun
 * Retour: (double) la valeur de prix_
 ****************************************************************************/

double Produit::obtenirPrix() const
{
    return prix_;
}

/****************************************************************************
 * Fonction:   Produit::modifierNom()
 * Description: Modifie l'attribut nom_
 * ParamËtres: string nom
 * Retour: 
 ****************************************************************************/

void Produit::modifierNom(string nom)
{
    nom_ = nom;
}

/****************************************************************************
 * Fonction:   Produit::modifierReference()
 * Description: Modifie l'attribut reference_
 * ParamËtres: int reference
 * Retour:
 ****************************************************************************/

void Produit::modifierReference(int reference)
{
    reference_ = reference;
}

/****************************************************************************
 * Fonction:   Produit::modifierPrix()
 * Description: Modifie l'attribut prix_
 * ParamËtres: double prix_
 * Retour:
 ****************************************************************************/

void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}

/****************************************************************************
 * Fonction:   Produit::afficher()
 * Description: Affiche l’etat des attributs.
 * ParamËtres: aucun
 * Retour:
 ****************************************************************************/

void Produit::afficher() const
{
    cout << "Le nom du produit est : " << obtenirNom() << endl;
    cout << "La reference du produit est : " << obtenirReference() << endl;
    cout << "Le prix du produit est : "<< obtenirPrix() << endl;
}
