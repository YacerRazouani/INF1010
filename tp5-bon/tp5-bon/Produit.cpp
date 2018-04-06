/********************************************
 * Titre: Travail pratique #5 - Produit.cpp
 * Date: 6 avril 2018
 * Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/
#include "Produit.h"
#include "Fournisseur.h"
#include <iostream>
#include <string>
/****************************************************************************
 * Fonction:   Produit::Produit(Fournisseur *fournisseur, const string &nom, 
 * int reference, double prix
 * Description: Constructeur de copie
 * Parametres: (in) : Fournisseur *fournisseur, const string &nom, int 
 *  reference, double prix
 * Retour: Aucun
 ****************************************************************************/
Produit::Produit(Fournisseur *fournisseur, const string &nom, int reference, double prix)
    : fournisseur_(fournisseur),
      nom_(nom),
      reference_(reference),
      prix_(prix)
{
    if (fournisseur_ != nullptr)
        fournisseur_->ajouterProduit(this);
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
 * Fonction:   PProduit::obtenirFournisseur() const
 * Description: Retourne l'attribut fournisseur_
 * Parametres: aucun
 * Retour: (fournisseur*) la valeur de fournisseur_
 ****************************************************************************/
Fournisseur *Produit::obtenirFournisseur() const
{
    return fournisseur_;
}

/****************************************************************************
 * Fonction:   Produit::afficher() const
 * Description: Affiche les informations précises sur le produit
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void Produit::afficher() const
{
    cout << "\t\t" << nom_ << endl
         << "\t\t\t\treference:\t\t" << reference_ << endl
         << "\t\t\t\tprix:\t\t\t" << "$" << prix_ << endl;
    if (fournisseur_ != nullptr)
        cout << "\t\t\t\tfournisseur:\t\t\t" << fournisseur_->obtenirNom() << endl;
}
/****************************************************************************
 * Fonction:   Produit::modifierNom()
 * Description: Modifie le nom par celui passer en Paramètre
 * Parametres: (in) const string &nom
 * Retour: Aucun
 ****************************************************************************/
void Produit::modifierNom(const string &nom)
{
    nom_ = nom;
}
/****************************************************************************
 * Fonction:   Produit::modifierReference()
 * Description: Modifie la reference par celui passer en Paramètre
 * Parametres: (in) int reference
 * Retour: Aucun
 ****************************************************************************/
void Produit::modifierReference(int reference)
{
    reference_ = reference;
}
/****************************************************************************
 * Fonction:   Produit::modifierPrix()
 * Description: Modifie le prix par celui passer en Paramètre
 * Parametres: (in) double prix
 * Retour: Aucun
 ****************************************************************************/
void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}
/****************************************************************************
 * Fonction:   Produit::modifierFournisseur()
 * Description: Modifie le fournisseur par celui passer en Paramètre
 * Parametres: (in) Fournisseur* fournisseur
 * Retour: Aucun
 ****************************************************************************/
void Produit::modifierFournisseur(Fournisseur *fournisseur)
{
    fournisseur_ = fournisseur;
}
