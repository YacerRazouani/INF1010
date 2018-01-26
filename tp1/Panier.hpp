
//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//



#ifndef Panier_hpp
#define Panier_hpp

#include <stdio.h>
#include <string>
#include "Produit.hpp"

class Panier
{
public:
    Panier (int capacite);
    // methodes d'accès
    Produit **  obtenirContenuPanier();
    int obtenirNombreContenu();
    double obtenirTotalApayer();
    
    // méthodes de modification
    
    // autres méthodes
    void ajouter ( Produit * prod);
    void livrer();
    void afficher();
    
private:
    
    Produit ** contenuPanier_;
    int  nombreContenu_;
    int capaciteContenu_;
    double totalAPayer_;
};

#endif /* Panier_hpp */
