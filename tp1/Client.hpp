//
//  Client.hpp
//  TP1
//
//  Created by Amar Ghaly on 18-01-23.
//  Copyright © 2018 Amar Ghaly. All rights reserved.
//

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include <string>
#include "Panier.hpp"
using namespace std;
class Client
{
public:
    Client (string  nom,  string prenom, int identifiant, string codePostal,  long date);
    // methodes d'acces
    
    string obtenirNom() ;
    string obtenirPrenom() ;
    int obtenirIdentifiant() ;
    string obtenirCodePostal() ;
    long obtenirDateNaissance() ;
    
    // methodes de modification
    void modifierNom(string nom) ;
    void modifierPrenom(string prenom) ;
    void modifierIdentifiant(int identifiant) ;
    void modifierCodePostal(string codePostal);
    void modifierDateNaissance(long date);
    
    // autres méthodes
    void acheter (Produit * prod);
    void afficherPanier();
    void livrerPanier();
    
    
private:
    
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
    long dateNaissance_;
    Panier *  monPanier_;
};

#endif /* Client_hpp */
