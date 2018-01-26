//
//  Produit.hpp
//  TP1
//
//  Created by Amar Ghaly on 18-01-23.
//  Copyright © 2018 Amar Ghaly. All rights reserved.
//

#ifndef Produit_hpp
#define Produit_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Produit
{
public:
    // Constructeurs par defaut et par parametres
    Produit();
    ~Produit();
    Produit(string nom, int reference, double prix);
    
    // Methodes d'acces
    string obtenirNom() const;
    int obtenirReference() const;
    double obtenirPrix() const;
    
    // Methodes de modification
    void modifierNom(string nom);
    void modifierReference(int reference);
    void modifierPrix(double prix);
    
    // autres methodes
    void afficher() const;
    
private:
    
    // attributs prives
    string nom_;
    int reference_;
    double prix_;
};

#endif /* Produit_hpp */
