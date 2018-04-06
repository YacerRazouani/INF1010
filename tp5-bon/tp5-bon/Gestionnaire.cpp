/********************************************
 * Titre: Travail pratique #5 -Gestionnaire.cpp
 * Date: 6 avril 2018
 * Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/
#include "Gestionnaire.h"

/****************************************************************************
 * Fonction:   Gestionnaire::obtenirUsagers() const
 * Description: Retourne le vecteurs contenant des pointeurs d'usagers
 * Parametres: Aucun
 * Retour: (out) vector<Usager*> - la valeur de l'attribut usagers_
 ****************************************************************************/
vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

/****************************************************************************
 * Fonction:   Gestionnaire::afficherLesProfils() const
 * Description: Affiche le profil de tous les utilisateurs enregistrés dans le
 *              gestionnaire
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void Gestionnaire::afficherLesProfils() const
{
    cout << "PROFILS" << endl;
    for (unsigned int i = 0; i < usagers_.size(); i++)
        usagers_[i]->afficher();
    cout << endl;
}


/****************************************************************************
 * Fonction:   Gestionnaire::obtenirChiffreAffaires() const
 * Description: Retourne la somme du total à payer de tous les usagers enregistrés
 *              dans le gestionnaire. Un fournisseur a un total de 0.
 * Parametres: Aucun
 * Retour: (double) la valeur du chiffre d'affaires
 ****************************************************************************/
double Gestionnaire::obtenirChiffreAffaires() const
{
    double chiffreAffaires = 0;
    for (unsigned int i = 0; i < usagers_.size(); i++)
        chiffreAffaires += usagers_[i]->obtenirTotalAPayer();
    return chiffreAffaires;
}

/****************************************************************************
 * Fonction:   Gestionnaire::ajouterUsager(Usager *usager)
 * Description: Ajoute un usager au gestionnaire
 * Parametres: (in) : Usager *usager
 * Retour: Aucun
 ****************************************************************************/
void Gestionnaire::ajouterUsager(Usager *usager)
{
    for (unsigned int i = 0; i < usagers_.size(); i++)
        if (usagers_[i] == usager)
            return;
    usagers_.push_back(usager);
}

/****************************************************************************
 * Fonction:   Gestionnaire::reinitialiser()
 * Description: Vide les paniers des clients et les catalogues des fournisseurs
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void Gestionnaire::reinitialiser()
{
    for (unsigned int i = 0; i < usagers_.size(); i++)
        usagers_[i]->reinitialiser();
}
/****************************************************************************
 * Fonction:   Gestionnaire::encherir()
 * Description: Surencheri un produit mis aux enchères en utilisant la fonction
 *              ProduitAuxEncheres::mettreAJourEnchere
 * Parametres: in : Client *client, ProduitAuxEncheres *produit, double montant
 * Retour: Aucun
 ****************************************************************************/
void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    if (produit->obtenirPrix() < montant)
        produit->mettreAJourEnchere(client, montant);
}
