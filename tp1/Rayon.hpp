/****************************************************************************
 * Fichier: Rayon.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour :
 * Description: Definition de la classe Rayon
 ****************************************************************************/
#ifndef Rayon_hpp
#define Rayon_hpp

#include <stdio.h>
#include <string>
#include "Produit.hpp"
using namespace std;

class Rayon
{
public:
    // Fusion des constructeurs par defaut et par parametres
    Rayon(string categorie = "inconnu", Produit ** tousProduits = nullptr, int capaciteProduits = 0,int nombreProduits = 0) ;
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
    void afficher() const;
    
    
private:
    
    // Attributs prives
    string categorie_;
    Produit ** tousProduits_;
    int capaciteProduits_;
    int nombreProduits_;
    
};
#endif /* Rayon_hpp */
