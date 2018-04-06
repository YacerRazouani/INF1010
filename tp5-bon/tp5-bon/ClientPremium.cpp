/****************************************************************************
 * Fichier: ClientPremium.cpp
 * Auteurs: Amar Ghaly et Yacer Razouani
 * Date: 6 avril 2018
 * Mise a jour :
 * Description: Implementation de la classe ClientPremium
 ****************************************************************************/

#include "ClientPremium.h"
#include <iostream>
/****************************************************************************
 * Fonction: ClientPremium::ClientPremium(unsigned int joursRestants)
 * Description: Constructeur de copie.
 * Parametres: (unsigned int) joursRestant
 * Retour: Aucun
 ****************************************************************************/
ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

/****************************************************************************
 * Fonction: lientPremium::ClientPremium(const string &nom, const string &prenom, 
 *  int identifiant, const string &codePostal, unsigned int codeClient,
 *  unsigned int joursRestants)
 * Description: Constructeur par paramètre.
 * Parametres: (in) cconst string &nom, const string &prenom, int identifiant,
 *  const string &codePostal, unsigned int codeClient,unsigned int joursRestants
 * Retour: Aucun
 ****************************************************************************/
ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

/****************************************************************************
 * Fonction:    ClientPremium::obtenirJoursRestants() const
 * Description: Retourne le nombre de jours restants avant la fin de l'abonnement
 * Parametres: Aucun
 * Retour: (unsigned int) la valeur de joursRestants
 ****************************************************************************/

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}
/****************************************************************************
 * Fonction:    ClientPremium::obtenirTotalAPayer() const
 * Description: Retourne le montal total du panier en tenant compte du rabais
 *              de 5$ pour chaque article
 * Parametres: Aucun
 * Retour: (double) la valeur de totalAPayer
 ****************************************************************************/
double ClientPremium::obtenirTotalAPayer() const
{
    return panier_->obtenirTotalApayerPremium();
}
/****************************************************************************
 * Fonction:   ClientPremium::afficherProfil() const
 * Description: Affiche les informations précises sur le client
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void ClientPremium::afficherProfil() const
{
    Client::afficher();
    cout << "\t\tjours restants:\t" << joursRestants_ << endl;
}

/****************************************************************************
 * Fonction:    ClientPremium::modifierJoursRestants()
 * Description: Modifie le nombre de jours restants par celui passer en paramètre
 * Parametres: (in) - (unsigned int) joursRestants
 * Retour: (out) - (unsigned int) la valeur de joursRestants_
 ****************************************************************************/
void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants;
}
