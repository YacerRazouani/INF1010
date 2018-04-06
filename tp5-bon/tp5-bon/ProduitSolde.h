/********************************************
 * Titre: Travail pratique #5- ProduitSolde.h
 * Date: 6 avril 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/

#ifndef PRODUIT_SOLDE_H
#define PRODUIT_SOLDE_H

#include <string>
#include <iostream>
#include "Solde.h"
#include "Produit.h"
#include <math.h>  

using namespace std;

class ProduitSolde : public Produit, public Solde
{
  public:
    ProduitSolde(int pourcentageRabais = 0);
    ProduitSolde(Fournisseur *fournisseur, const string &nom, int reference,
                 double prix, int pourcentageRabais = 0);

    virtual double obtenirPrix() const;
    virtual void afficher() const;
};

#endif
