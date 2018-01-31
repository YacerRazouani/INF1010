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

int main()
{
    //C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments
    
    //1-  Creez 15 objets du classe produit

    static const int NOMBRE_PRODUITS = 15;
    for (unsigned i = 0; i < NOMBRE_PRODUITS; i++){
        Produit *p[i] = new Produit();
    }
    
    //2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
    p3->modifierNom("Jus d'organges");
    p3->modifierReference(1);
    p3->modifierPrix(3.00);
    p3->afficher();
   
    
    //3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
    Rayon *rayon = new Rayon();
    
    //4-  Modifiez la catégorie  du rayon
    rayon->modifierCategorie("Produits Laitiers");
    
    
    // 5- Ajouter 6 produits de  voret chaoix dans le rayon créé
    static const int NOMBRE_PRODUITS_AJOUTER = 6
    for (unsigned i = 0; i < NOMBRE_PRODUITS_AJOUTER; i++){
        rayon->ajouterProduit(p[i]);
    }
    
    // 6- afficher le contenu du rayon
    rayon->afficher();
    
    
    //7-  Creez un objet de classe client à l'aide du constructeur
    Client client = Client();
    
    //8-  afficher l'etat des attributs du client
    client.afficherAttributs();
    
    //9-   Le client achete 9 produits
    static const int NOMBRE_PRODUITS_ACHETER = 9;
    for (unsigned i = 0; i < NOMBRE_PRODUITS_ACHETER; i++){
        client.acheter(p[i]);
    }
    //10- Afficher le contenu du panier du client
    
    client.afficherPanier();
    //11- livrer le panier du client
    client.livrerPanier();
    
    //12- afficher le contenu du panier du client
    client.afficherPanier();
    //13-  terminer le programme correctement
    // AJOUTER LES DELETES
    
 
    return 0;
}
