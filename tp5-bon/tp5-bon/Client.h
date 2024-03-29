/********************************************
 * Titre: Travail pratique #5 - Client.h
 * Date: 6 avril 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "GestionnaireProduits.h"

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);

	~Client();
    unsigned int obtenirCodeClient() const;
	void modifierCodeClient(unsigned int codeClient);
	// TODO : Modifier ses méthodes : -------------------
    GestionnaireProduits* obtenirPanier() const;
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
    virtual void afficher() const;
    virtual void enleverProduit(Produit *produit);
    virtual void ajouterProduit(Produit *produit);
    virtual void reinitialiser();
	// --------------------------------------------------

	// TODO : Implémenter cette méthodes : 
	Produit* trouverProduitPlusCher() const;
  
  protected:
    GestionnaireProduits* panier_;

  private:
    unsigned int codeClient_;
};

#endif
