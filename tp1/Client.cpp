/****************************************************************************
 * Fichier: Client.cpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 23 janvier 2018
 * Mise a jour :
 * Description: Implementation de la classe Produit
 ****************************************************************************/

#include "Client.hpp"
#include "Produit.hpp"
#include "Panier.hpp"
/****************************************************************************
 * Fonction: Client::Client()
 * Description: Fusion des Constructeurs par parametre et par défaut
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Client::Client(string nom , string prenom, int identifiant, string codePostal, long dateNaissance, Panier* panier)
{
    // Constructeur
    nom_ = nom;
    prenom_ = prenom;
    identifiant_ = identifiant;
    codePostal_ = codePostal;
    dateNaissance_ = dateNaissance;
    monPanier_ = panier;
    
}

/****************************************************************************
 * Fonction: Client::~Client()
 * Description: Destructeur par defaut
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
Client::~Client()
{
    // Destructeur d'un client
    monPanier_->livrer();
    cout << "Le panier du client a ete detruit." << endl; 
}

/****************************************************************************
 * Fonction:   Client::obtenirNom() const
 * Description: Retourne l'attribut nom_
 * ParamËtres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Client::obtenirNom() const
{
    return nom_;
}

/****************************************************************************
 * Fonction:   Client::obtenirPrenom() const
 * Description: Retourne l'attribut prenom_
 * ParamËtres: aucun
 * Retour: (string) la valeur de prenom_
 ****************************************************************************/

string Client::obtenirPrenom() const
{
    return prenom_;
}

/****************************************************************************
 * Fonction:   Client::obtenirIdentifiant() const
 * Description: Retourne l'attribut identifiant_
 * ParamËtres: aucun
 * Retour: (int) la valeur de identifiant_
 ****************************************************************************/

int  Client::obtenirIdentifiant() const
{
    return identifiant_;
}

/****************************************************************************
 * Fonction:   Client::obtenirCodePostal() const
 * Description: Retourne l'attribut codePostal_
 * ParamËtres: aucun
 * Retour: (string) la valeur de codePostal_
 ****************************************************************************/
string Client::obtenirCodePostal() const
{
    return codePostal_;
}

/****************************************************************************
 * Fonction:   Client::obtenirDateNaissance() const
 * Description: Retourne l'attribut DateNaissance_
 * ParamËtres: aucun
 * Retour: (long) la valeur de dateNaissance_
 ****************************************************************************/
long Client::obtenirDateNaissance() const
{
    return dateNaissance_;
}

/****************************************************************************
 * Fonction:   Client::modifierNom
 * Description: Modifie l'attribut nom_
 * ParamËtres: string nom
 * Retour:
 ****************************************************************************/

void Client::modifierNom(string nom)
{
    nom_ = nom;
}
/****************************************************************************
 * Fonction:   Client::modifierPrenom
 * Description: Modifie l'attribut prenom_
 * ParamËtres: string prenom
 * Retour:
 ****************************************************************************/

void Client::modifierPrenom(string prenom)
{
    prenom_ = prenom;
}

/****************************************************************************
 * Fonction:   Client::modifierIdentifiant
 * Description: Modifie l'attribut identifiant_
 * ParamËtres: int identifiant
 * Retour:
 ****************************************************************************/

void Client::modifierIdentifiant (int identifiant)
{
    identifiant_ = identifiant;
}

/****************************************************************************
 * Fonction:   Client::modifierCodePostal
 * Description: Modifie l'attribut codePostal_
 * ParamËtres: string codePostal
 * Retour:
 ****************************************************************************/

void Client::modifierCodePostal (string codePostal)
{
    codePostal_ = codePostal;
}

/****************************************************************************
 * Fonction:   Client::modifierDateNaissance
 * Description: Modifie l'attribut DateNaissance_
 * ParamËtres: long dateNaissance
 * Retour:
 ****************************************************************************/

void Client::modifierDateNaissance (long dateNaissance)
{
    dateNaissance_ = dateNaissance;
}
/****************************************************************************
 * Fonction:   Clier::afficherAttributs()
 * Description: Affiche l'état des attributs
 * ParamËtres: aucun
 * Retour:
 ****************************************************************************/

void Client::afficherAttributs() const
{
    cout << "Le nom du client est : " << nom_ << endl;
    cout << "Le prénom du client est : " << prenom_ << endl;
    cout << "L'identifiant du client est : " << identifiant_ << endl;
    cout << "Le code postal du client est : " << codePostal_ << endl;
    cout << "La date de naissance du client est : " << dateNaissance_ << endl;
    cout << "Le contenu du panier est : " << endl;
    afficherPanier();
}
    
/****************************************************************************
 * Fonction:   Client::acheter()
 * Description: Ajoute un produit dans le panier du client. Si le panier n’existe pas, on créé un objet Panier de 4 produits, et on ajoute le produit dans le Panier du client
 * ParamËtres: Produit* produit
 * Retour:
 ****************************************************************************/


void Client::acheter(Produit * produit)
{
    if (monPanier_ == nullptr){														//Si le tableau est nul on crée un objet Panier de 4 produit
        Panier panier(4);
		monPanier_ = &panier;
		monPanier_->ajouter(produit);
    }

	else {
		monPanier_->ajouter(produit);
	}

}


/****************************************************************************
 * Fonction:   Client::afficherPanier() const
 * Description: Affiche le contenu du panier s'il n'est pas vide
 * ParamËtres: aucun
 * Retour:
 ****************************************************************************/

void Client::afficherPanier() const
{
	cout << "Le contenu du panier est : ";
	if (monPanier_->obtenirContenuPanier() == nullptr) {
		cout << "vide" << endl;
	}
	else {
		monPanier_->afficher();
	}
}
    
/****************************************************************************
* Fonction:   Client::livrer()
* Description:  Permet de livrer le contenu du panier, en supprimant le Panier actuel du client.
* ParamËtres: aucun
* Retour: aucun****************************************************************************/
    
void Client::livrerPanier()
{
        
    monPanier_->livrer();
        
}
