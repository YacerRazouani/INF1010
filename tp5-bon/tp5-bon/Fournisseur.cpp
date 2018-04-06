/****************************************************************************
 * Fichier: Fournisseur.cpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 6 avril 2018
 * Mise a jour :
 * Description: Implementation de la classe Fournisseur
 ****************************************************************************/

#include "Fournisseur.h"
#include <iostream>
/****************************************************************************
 * Fonction: Fournisseur::Fournisseur
 * Description: Constructeur par d�faut
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
Fournisseur::Fournisseur()
    : Usager(), catalogue_(new GestionnaireProduits)
{

}
/****************************************************************************
 * Fonction: Fournisseur::Fournisseur
 * Description: Constructeur par param�tre
 * Parametres: const string &nom, const string &prenom, int identifiant, 
 * const string &codePostal
 * Retour: aucun
 ****************************************************************************/
Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal), catalogue_(new GestionnaireProduits)
{
	// TODO : � modifiercatalogue_ = new GestionnaireProduits
}

/****************************************************************************
 * Fonction: Fournisseur::Fournisseur
 * Description: Destructeur par d�faut
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
Fournisseur::~Fournisseur()
{
	delete catalogue_;
}
/****************************************************************************
 * Fonction:   Fournisseur::obtenirCatalogue() const
 * Description: Retourne le catalogue_
 * Param�tres: aucun
 * Retour: (GestionnaireProduits*) le contenu du catalogue_
 ****************************************************************************/
GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
	
    return catalogue_;
}
/****************************************************************************
 * Fonction:   Fournisseur::afficherCatalogue() const
 * Description: Affiche le catalogue du fournisseur
 * Param�tres: aucun
 * Retour: -
 ****************************************************************************/
void Fournisseur::afficherCatalogue() const
{
	// TODO : � modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	catalogue_->afficher();
    cout << endl;
}
/****************************************************************************
 * Fonction:   Fournisseur::afficher() const
 * Description: Affiche les informations du fournisseur et se servant de la
 * de la m�thode Usager::afficher();
 * Param�tres: aucun
 * Retour: -
 ****************************************************************************/
void Fournisseur::afficher() const
{
	
    Usager::afficher();
    cout << "\t\t\t\tcatalogue:\t\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}
/****************************************************************************
 * Fonction:   Fournisseur::reinitialiser()
 * Description: R�initialise les informations du fournisseur
 * Param�tres: aucun
 * Retour: -
 ****************************************************************************/
void Fournisseur::reinitialiser()
{
	
	catalogue_->reinitialiserFournisseur();
}

/****************************************************************************
* Fonction:   Fournisseur::ajouterProduit()
* Description: Ajoute un produit � l'attribut contenuCatalogue_
* Parametres: (in) - Produit* produit
* Retour: Aucun
****************************************************************************/
void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : � modifier
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	catalogue_->ajouter(produit);
}

/****************************************************************************
 * Fonction:   Fournisseur::enleverProduit()
 * Description: Enleve un produit � l'attribut contenuCatalogue_
 * Parametres: (in) - Produit* produit
 * Retour: Aucun
 ****************************************************************************/
void Fournisseur::enleverProduit(Produit *produit)
{
	
    produit->modifierFournisseur(nullptr);
	catalogue_->supprimer(produit);
}
/****************************************************************************
 * Fonction:  Fournisseur::trouverProduitPlusCher() const
 * Description: Retourne le produit le plus cher du catalogue
 * Parametres: aucune
 * Retour: (out) Produit* - produit le plus cher
 ****************************************************************************/
Produit * Fournisseur::trouverProduitPlusCher() const
{
	return catalogue_->trouverProduitPlusCher();
}
/****************************************************************************
 * Fonction:  Fournisseur::DiminuerPrix(int pourcent) const
 * Description: diminue le prix des �l�ments du catalogue par le pourcentage
 * envoy� en param�tre
 * Parametres: (in) int pourcent
 * Retour: -
 ****************************************************************************/
void Fournisseur::DiminuerPrix(int pourcent) const
{
	catalogue_->pourChaqueElement(FoncteurDiminuerPourcent(pourcent));
}
