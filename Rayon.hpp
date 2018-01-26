/********************************************
 * Titre: Travail pratique #1 -Rayon.h
 * Date: 20 janvier 2018
 * Auteur:
 *******************************************/

#ifndef Rayon_hpp
#define Rayon_hpp

#include <stdio.h>
#include <string>
#include "Produit.hpp"
using namespace std;

class Rayon
{
public:
    // Constructeurs par defaut et par paraametres
    Rayon();
    Rayon(string categorie);
    // Destructeur par defaut
    ~Rayon();
    
    
    // Methodes d'acces
    string obtenirCategorie() const;
    Produit ** obtenirTousProduits() const;
    int obtenirCapaciteProduits() const;
    int obtenirNombreProduits() const;
    
    
    // Methodes de modification
    void modifierCategorie(string categorie);
    
    // autres methodes
    void ajouterProduit (Produit * produit);
    void afficher();
    
    
private:
    
    // Attributs prives
    string categorie_;
    Produit ** tousProduits_;
    int capaciteProduits_;
    int nombreProduits_;
    
};
#endif /* Rayon_hpp */
