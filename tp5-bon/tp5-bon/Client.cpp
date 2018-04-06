/****************************************************************************
 * Fichier: Client.cpp
 * Auteurs: Amar Ghaly et Yacer Razouani
 * Date: 6 avril 2018
 * Mise a jour :
 * Description: Implementation de la classe Client
 ****************************************************************************/
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include "GestionnaireProduits.h"
#include <iostream>

/****************************************************************************
 * Fonction: Client::Client(const Client& client)
 * Description: Constructeur de copie.
 * Parametres: (unsigned int)codeClient
 * Retour: Aucun
 ****************************************************************************/
Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient), panier_(new GestionnaireProduits)
{
	
}
/****************************************************************************
 * Fonction: Client::Client(const string &nom, const string &prenom, int identifiant,
 const string &codePostal, unsigned int codeClient)
 * Description: Constructeur par paramtre.
 * Parametres: (in) const string &nom, const string &prenom, int identifiant,
 *              const string &codePostal, unsigned int codeClient
 * Retour: Aucun
 ****************************************************************************/

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient), panier_(new GestionnaireProduits)
{
	// TODO : À modifier
}
/****************************************************************************
 * Fonction: Client::Client()
 * Description: Destructeur
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
Client::~Client()
{
	delete panier_;
}

/****************************************************************************
 * Fonction:    Client::obtenirCodeClient() const
 * Description: Retourne le code du client
 * Parametres: Aucun
 * Retour: (unsigned int) la valeur du codeClient_
 ****************************************************************************/
unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}
/****************************************************************************
 * Fonction:    Client::obtenirPanier() const
 * Description: Retourne le  panier
 * Parametres: Aucun
 * Retour: (GestionnaireProduits*) l'attribut panier_
 ****************************************************************************/
GestionnaireProduits* Client::obtenirPanier() const
{
	
    return panier_;
}
/****************************************************************************
 * Fonction:    Client::obtenirTotalAPayer() const
 * Description: Retourne le montal total du panier
 * Parametres: Aucun
 * Retour: (double) la valeur de totalAPayer
 ****************************************************************************/
double Client::obtenirTotalAPayer() const
{
	
	return panier_->obtenirTotalAPayer();
}

/****************************************************************************
 * Fonction:   Client::afficherPanier() const
 * Description: Affiche le contenu du panier
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void Client::afficherPanier() const
{
	
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    panier_->afficher();
    cout << endl;
}
/****************************************************************************
 * Fonction:   Client::afficher() const
 * Description: Affiche les informations du client
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void Client::afficher() const
{
	
    Usager::afficher();
    cout << "\t\t\t\tcode client:\t" << codeClient_ << endl
         << "\t\t\t\tpanier:\t\t \t" << panier_->obtenirConteneur().size() << " elements" << endl;
}

/****************************************************************************
 * Fonction:   Client::modifierCodeClient(unsigned int codeClient)
 * Description: Modifie le code du client pour celui passer en paramtre
 * Parametres: (in) - unsigned int codeClient
 * Retour: Aucun
 ****************************************************************************/
void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient;
}
/****************************************************************************
 * Fonction:   Client::enleverProduit()
 * Description: Enleve un produit ˆ l'attribut panier_
 * Parametres: (in) - Produit* produit
 * Retour: Aucun
 ****************************************************************************/
void Client::enleverProduit(Produit *produit)
{
	
	panier_->supprimer(produit);
}
/****************************************************************************
 * Fonction:   Client::ajouterProduit()
 * Description: Ajoute un produit ˆ l'attribut panier_
 * Parametres: (in) - Produit* produit
 * Retour: Aucun
 ****************************************************************************/
void Client::ajouterProduit(Produit *produit)
{
	
	panier_->ajouter(produit);
}
/****************************************************************************
 * Fonction:  Client::reinitialiser()
 * Description: Vide le paniers du client
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
void Client::reinitialiser()
{
	
    panier_->reinitialiserClient();
}
/****************************************************************************
 * Fonction:  Client::trouverProduitPlusCher() const
 * Description: Retourne le produit le plus cher du panier
 * Parametres: aucune
 * Retour: (out) Produit* - produit le plus cher
 ****************************************************************************/
Produit * Client::trouverProduitPlusCher() const
{
	return panier_->trouverProduitPlusCher();
}
