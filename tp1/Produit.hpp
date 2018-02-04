/****************************************************************************
 * Fichier: Produit.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour : 4 fevrier
 * Description: Definition de la classe Produit
 ****************************************************************************/

#ifndef Produit_hpp
#define Produit_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Produit
{
public:
    // Fusion des constructeurs par defaut et par parametres
    Produit(string nom = "outil", int reference = 0, double prix = 0.0);
    
    // Destructeur
    ~Produit();
    
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
