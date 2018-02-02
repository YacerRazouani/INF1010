/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: 20 janvier 2018
 * Auteur: Amar Ghaly et Yacer Razouani
 **************************************************/

#include "Produit.hpp"
#include "Rayon.hpp"
#include "Client.hpp"
#include "Panier.hpp"
#include <string>
#include <iostream>

using namespace std;

//Q1: composition
//Q2: aggregation

int main()
{
    //C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments
    
    //1-  Creez 15 objets du classe produit
    const int NOMBRE_DE_PRODUITS = 15;
    Produit** listeProduits = new Produit*[NOMBRE_DE_PRODUITS];
    for (int i = 0; i < NOMBRE_DE_PRODUITS; i++){
        listeProduits[i] = new Produit;
    }
    
    //2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
    listeProduits[2]->modifierNom("banane");
    listeProduits[2]->modifierReference(4);
    listeProduits[2]->modifierPrix(2.00);
   
    
    //3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
    Rayon rayon;
    
    //4-  Modifiez la catégorie  du rayon
    rayon.modifierCategorie("Produits Laitiers");
    
    // 5- Ajouter 6 produits de  voret chaoix dans le rayon créé
    const int NOMBRE_DE_PRODUITS_AJOUTES = 6;
    for (int i = 0; i < NOMBRE_DE_PRODUITS_AJOUTES; i++){
		rayon.ajouterProduit(listeProduits[i]);
    }

    // 6- afficher le contenu du rayon
   // rayon.afficher();
    
    //7-  Creez un objet de classe client à l'aide du constructeur
    Client client = Client("Chan", "Jackie", 5, "HT6P0P", 1998);
    
    //8-  afficher l'etat des attributs du client
    client.afficherAttributs();
    
    //9-   Le client achete 9 produits
    const int NOMBRE_DE_PRODUITS_ACHETES = 9;
    for (int i = 0; i < NOMBRE_DE_PRODUITS_ACHETES; i++){
        client.acheter(listeProduits[i]);
    }

    //10- Afficher le contenu du panier du client
    client.afficherPanier();
    
    //11- livrer le panier du client
    client.livrerPanier();
    
    //12- afficher le contenu du panier du client
    client.afficherPanier();
    
    //13-  terminer le programme correctement
    // AJOUTER LES DELETE
    
    
    return 0;
}
