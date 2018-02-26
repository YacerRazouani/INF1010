/****************************************************************************
 * Fichier: Fournisseur.cpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 18 février 2018
 * Mise a jour :
 * Description: Implementation de la classe Fournisseur
 ****************************************************************************/

#include "Fournisseur.h"
/****************************************************************************
 * Fonction: Fournisseur::Fournisseur
 * Description: Constructeur par défaut
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/

Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal) : Usager(nom, prenom, identifiant, codePostal)
{
    for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {
        satisfaction_.niveaux_[i] = 0;
    }
}

/****************************************************************************
 * Fonction:   Fournisseur::obtenirCatalogue()
 * Description: Retourne le contenuCatalogue_
 * ParamËtres: aucun
 * Retour: (vector<Produit*>) la valeur de contenuCatalogue_
 ****************************************************************************/
vector<Produit*> Fournisseur::obtenirCatalogue() const
{
    return contenuCatalogue_;
}

/****************************************************************************
 * Fonction:   Fournisseur::obtenirSatifaction() const
 * Description: Retourne satisfaction_
 * ParamËtres: aucun
 * Retour: (Satisfaction) la valeur de satifaction_
 ****************************************************************************/

Satisfaction Fournisseur::obtenirSatisfaction() const
{
    return satisfaction_;
}

/****************************************************************************
 * Fonction:   Fournisseur::modifierSatisfaction()
 * Description: Modifie l'attribut satisfaction_
 * Parametres: (in) - Satisfaction satisfaction
 * Retour: Aucun
 ****************************************************************************/
void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
    satisfaction_ = satisfaction;
}

/****************************************************************************
 * Fonction:   Fournisseur::noter()
 * Description: Incremente le tableau produit de la valeur de appreciation
 * Parametres: (in) - int appreciation
 * Retour: Aucun
 ****************************************************************************/

void Fournisseur::noter(int appreciation)
{
    satisfaction_.niveaux_[appreciation]++;
}

/****************************************************************************
 * Fonction:   Fournisseur::ajouterProduit()
 * Description: Ajoute un produit à l'attribut contenuCatalogue_
 * Parametres: (in) - Produit* produit
 * Retour: Aucun
 ****************************************************************************/
void Fournisseur::ajouterProduit(Produit* produit)
{
    contenuCatalogue_.push_back(produit);
}

/****************************************************************************
 * Fonction:   Fournisseur::enleverProduit()
 * Description: Enleve un produit à l'attribut contenuCatalogue_
 * Parametres: (in) - Produit* produit
 * Retour: Aucun
 ****************************************************************************/
void Fournisseur::enleverProduit(Produit* produit)
{
    for (unsigned int i = 0; i < contenuCatalogue_.size(); i++) {
        if (contenuCatalogue_[i] == produit) {												//Trouve le produit corespondant.
            contenuCatalogue_[i] = contenuCatalogue_[contenuCatalogue_.size() - 1];			//Copie le dernier element du vecteur a la position du produit rechercher.
            contenuCatalogue_.pop_back();													//Efface le dernier element du vecteur.
        }																					//On garde en tete que la position des produits dans le vecteur importait peu.
    }
}

/****************************************************************************
 * Fonction:   Fournisseur::operator=()
 * Description: Utilise la surcharge de l'operateur= de la classe Usager
 * Parametres: (in) - Produit* produit
 * Retour: Aucun
 ****************************************************************************/
Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
    Usager::operator=(fournisseur);
    return *this;
}

/****************************************************************************
 * Fonction:   Fournisseur::operator=()
 * Description: Utilise la surcharge de l'operateur= de la classe Usager
 * Parametres: (in) - Produit* produit
 * Retour: Aucun
 ****************************************************************************/

ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
    //Conversion d'un objet de classe fournisseur en objet de classe Usager
    Usager usager = static_cast<Usager>(fournisseur);
    os << "Fournisseur: ";
    os << usager;
    os << "notes ";
    for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {
        os << i << ": " << fournisseur.satisfaction_.niveaux_[i] << endl;
    }
    return os;
}

