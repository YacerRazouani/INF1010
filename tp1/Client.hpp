/****************************************************************************
 * Fichier: Client.hpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour :
 * Description: Definition de la classe Client
 ****************************************************************************/

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include <string>
#include "Panier.hpp"
using namespace std;
class Client
{
public:
    //Constructeur
    Client (string nom = "aucun" ,  string prenom = "aucun", int identifiant = 0, string codePostal = "aucun" ,  long dateNaissance = 0, Panier* panier = nullptr);
    //Destructeur
    ~Client();
    
    // methodes d'acces
    
    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    long obtenirDateNaissance() const;
    
    // methodes de modification
    void modifierNom(string nom) ;
    void modifierPrenom(string prenom) ;
    void modifierIdentifiant(int identifiant) ;
    void modifierCodePostal(string codePostal);
    void modifierDateNaissance(long date);
    
    // autres méthodes
    void afficherAttributs() const;
    void acheter (Produit * produit);
    void afficherPanier() const;
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
