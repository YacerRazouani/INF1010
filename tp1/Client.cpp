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
#include <iomanip>

/****************************************************************************
 * Fonction: Client::Client()
 * Description: Fusion des Constructeurs par parametre et par défaut
 * Parametres: (in) - (string) nom, (string) prenom, (int) identifiant, (string) codePostal, (long) dateNaissance, (Panier*) panier
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
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
Client::~Client()
{
    // Destructeur d'un client

	if (monPanier_->obtenirContenuPanier() == 0) {
		delete[] monPanier_;
	}
    cout << "Le panier du client a ete detruit." << endl; 
}

/****************************************************************************
 * Fonction:   Client::obtenirNom() const
 * Description: Retourne l'attribut nom_
 * Parametres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Client::obtenirNom() const
{
    return nom_;
}

/****************************************************************************
 * Fonction:   Client::obtenirPrenom() const
 * Description: Retourne l'attribut prenom_
 * Parametres: aucun
 * Retour: (string) la valeur de prenom_
 ****************************************************************************/

string Client::obtenirPrenom() const
{
    return prenom_;
}

/****************************************************************************
 * Fonction:   Client::obtenirIdentifiant() const
 * Description: Retourne l'attribut identifiant_
 * Parametres: aucun
 * Retour: (int) la valeur de identifiant_
 
 ****************************************************************************/

int  Client::obtenirIdentifiant() const
{
    return identifiant_;
}

/****************************************************************************
 * Fonction:   Client::obtenirCodePostal() const
 * Description: Retourne l'attribut codePostal_
 * Parametres: aucun
 * Retour: (string) la valeur de codePostal_
 ****************************************************************************/
string Client::obtenirCodePostal() const
{
    return codePostal_;
}

/****************************************************************************
 * Fonction:   Client::obtenirDateNaissance() const
 * Description: Retourne l'attribut DateNaissance_
 * Parametres: aucun
 * Retour: (long) la valeur de dateNaissance_
 ****************************************************************************/
long Client::obtenirDateNaissance() const
{
    return dateNaissance_;
}

/****************************************************************************
 * Fonction:   Client::modifierNom
 * Description: Modifie l'attribut nom_
 * Parametres: (in) - string nom
 * Retour:
 ****************************************************************************/

void Client::modifierNom(string nom)
{
    nom_ = nom;
}
/****************************************************************************
 * Fonction:   Client::modifierPrenom
 * Description: Modifie l'attribut prenom_
 * Parametres: (in) - string prenom
 * Retour:
 ****************************************************************************/

void Client::modifierPrenom(string prenom)
{
    prenom_ = prenom;
}

/****************************************************************************
 * Fonction:   Client::modifierIdentifiant
 * Description: Modifie l'attribut identifiant_
 * Parametres: (in) - int identifiant
 * Retour:
 ****************************************************************************/

void Client::modifierIdentifiant (int identifiant)
{
    identifiant_ = identifiant;
}

/****************************************************************************
 * Fonction:   Client::modifierCodePostal
 * Description: Modifie l'attribut codePostal_
 * Parametres: (in) - string codePostal
 * Retour:
 ****************************************************************************/

void Client::modifierCodePostal (string codePostal)
{
    codePostal_ = codePostal;
}

/****************************************************************************
 * Fonction:   Client::modifierDateNaissance()
 * Description: Modifie l'attribut DateNaissance_
 * Parametres: (in) - long dateNaissance
 * Retour:
 ****************************************************************************/

void Client::modifierDateNaissance (long dateNaissance)
{
    dateNaissance_ = dateNaissance;
}
/****************************************************************************
 * Fonction:   Clier::afficherAttributs() const
 * Description: Affiche l'etat des attributs
 * Parametres: aucun
 * Retour:
 ****************************************************************************/

void Client::afficherAttributs() const
{
    cout << setw(51) << "->Le nom du client est : " << setw(23) << obtenirNom() << endl;
    cout << setw(54) << "->Le prenom du client est : " << setw(22) << obtenirPrenom() << endl;
    cout << setw(58) << "->L'identifiant du client est : " << setw(13) << obtenirIdentifiant() << endl;
    cout << setw(59) << "->Le code postal du client est : " << setw(17) << obtenirCodePostal() << endl;
    cout << setw(65) << "->La date de naissance du client est : " << setw(9) << obtenirDateNaissance() << endl;
}
    
/****************************************************************************
 * Fonction:   Client::acheter()
 * Description: Ajoute un produit dans le panier du client. Si le panier n’existe pas, on cree un objet Panier de 4 produits, et on ajoute le produit dans le Panier du client
 * Parametres: (in-out) Produit* produit
 * Retour:
 ****************************************************************************/


void Client::acheter(Produit * produit)
{
    if (monPanier_ == nullptr){														//Si le tableau est nul on cree un objet Panier de 4 produit
		monPanier_ = new Panier(4);
		monPanier_->ajouter(produit);
    }

	else {
		monPanier_->ajouter(produit);
	}

}


/****************************************************************************
 * Fonction:   Client::afficherPanier() const
 * Description: Affiche le contenu du panier s'il n'est pas vide
 * Parametres: aucun
 * Retour:
 ****************************************************************************/

void Client::afficherPanier() const
{
	monPanier_->afficher();
}
    
/****************************************************************************
* Fonction:   Client::livrer()
* Description:  Permet de livrer le contenu du panier, en supprimant le Panier actuel du client.
* Parametres: aucun
* Retour: aucun****************************************************************************/
    
void Client::livrerPanier()
{
        
    monPanier_->livrer();
        
}
