/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: 4 fevrier 2018
 * Auteur: Amar Ghaly et Yacer Razouani
 **************************************************/

#include "Produit.hpp"
#include "Rayon.hpp"
#include "Client.hpp"
#include "Panier.hpp"
#include <string>
#include <iostream>

using namespace std;

//Q1: Le lien entre la classe Client et la classe Panier est un lien de composition. En effet, la classe Client est compose de l'objet monPanier_ (attribut private de la classe Client) de classe Panier. Si le client est detruit, le panier l'est aussi. De plus, puisque monPanier est de type pointeur, en regardant la definition et l'implementation de la classe Client, dans le destructeur Client::~Client(), on voit bien que l'espace memoire alloue pour monPanier est desalloue.
//Q2: Le lien entre la classe Produit et la classe Tayon est un lien d'aggregation. En effet, l'objet tousProduit de type Produit** (attribut private de la classe Rayon) fait partie de la classe Rayon. Par contre, si le rayon est detruit, le produit ne le sera pas. Il existe de maniere independante à la classe Rayon. De plus, puisque tousProduit_ est de type pointeur, en regardant la definition et l'implementation de la classe Rayon, dans le destructeur Rayon::~Rayon(), on voit bien que l'espace memoire alloue pour tousProduit n'est pas desalloue par ce destructeur.


int main()
{
    //C'est a vous de voir si vous devez allouer dynamiquement ou non les elements
    
    //1-  Creez 15 objets du classe produit
    const int NOMBRE_DE_PRODUITS = 15;
    Produit** listeProduits = new Produit*[NOMBRE_DE_PRODUITS];
    for (int i = 0; i < NOMBRE_DE_PRODUITS; i++){
        listeProduits[i] = new Produit;
    }

	//Produit p0 = Produit();
	//Produit p1 = Produit();
	//Produit p2 = Produit();
	//Produit p3 = Produit();
	//Produit p4 = Produit();
	//Produit p5 = Produit();
	//Produit p6 = Produit();




    //2-  Modifiez le nom, la reference, le prix de  troisieme objet Produit cree
    //   afficher les attributs de cet objet Produit
    listeProduits[2]->modifierNom("banane");
    listeProduits[2]->modifierReference(4);
    listeProduits[2]->modifierPrix(2.00);
	//p2.modifierNom("banane");
	//p2.modifierReference(4);
	//p2.modifierPrix(2.00);
    
    //3-  Creez un objet du classe rayon e l'aide du constructeur par defaut
    Rayon rayon;
    
    //4-  Modifiez la categorie  du rayon
    rayon.modifierCategorie("Produits Laitiers");
    
    // 5- Ajouter 6 produits de  votre choix dans le rayon cree
    const int NOMBRE_DE_PRODUITS_AJOUTES = 6;
    for (int i = 0; i < NOMBRE_DE_PRODUITS_AJOUTES; i++){
		rayon.ajouterProduit(listeProduits[i]);
    }

	//rayon.ajouterProduit(&p0);
	//rayon.ajouterProduit(&p1);
	//rayon.ajouterProduit(&p2);
	//rayon.ajouterProduit(&p3);
	//rayon.ajouterProduit(&p4);
	//rayon.ajouterProduit(&p5);

    // 6- afficher le contenu du rayon
    rayon.afficher();
    
    //7-  Creez un objet de classe client a l'aide du constructeur
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
	delete[] listeProduits;
	listeProduits = nullptr;
    
    
    return 0;
}
