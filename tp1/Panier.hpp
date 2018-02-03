/****************************************************************************
 * Fichier: Panier.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour :
 * Description: Definition de la classe Panier
 ****************************************************************************/

#ifndef Panier_hpp
#define Panier_hpp

#include <stdio.h>
#include <string>
#include "Produit.hpp"

class Panier
{
public:
    // Constructeur
    Panier (int capacite);
    // Destructeur
    ~Panier();
    // methodes d'acces
    Produit **  obtenirContenuPanier() const;
    int obtenirNombreContenu() const;
    double obtenirTotalApayer() const;
    
    // methodes de modification
    
    // autres methodes
    void ajouter ( Produit * prod);
    void livrer();
    void afficher() const;
    
private:
    
    Produit ** contenuPanier_;
    int  nombreContenu_;
    int capaciteContenu_;
    double totalAPayer_;
};

#endif /* Panier_hpp */
