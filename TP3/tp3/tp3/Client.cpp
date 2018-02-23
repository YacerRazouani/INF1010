/****************************************************************************
 * Fichier: Client.cpp
 * Auteur: Amar Ghaly et Yacer Razouani
 * Date: 18 février 2018
 * Mise a jour :
 * Description: Implementation de la classe Client
 ****************************************************************************/

#include "Client.h"
#include "Fournisseur.h"

/****************************************************************************
 * Fonction: Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date)
 * Description: Constructeur par parametres.
 * Parametres: (in): const string&  nom
 *				    const string& prenom
 *				    int identifiant
 *				    const string& codePostal
 *				    long date
 * Retour: Aucun
 ****************************************************************************/
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) : Usager(nom, prenom, identifiant, codePostal), dateNaissance_{0}, monPanier_{nullptr}
{
}

/****************************************************************************
 * Fonction: Client::~Client()
 * Description: Destructeur de la classe Client
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
Client::~Client()
{
    if (monPanier_ != nullptr)
        delete monPanier_;
}


/****************************************************************************
 * Fonction: Client::Client(const Client& client)
 * Description: Constructeur de copie.
 * Parametres: (in) const Client & client
 * Retour: Aucun
 ****************************************************************************/
Client::Client(const Client & client) :
Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),
dateNaissance_{ client.dateNaissance_ }
{
    if (client.monPanier_ == nullptr)
        monPanier_ = nullptr;
        else {
            monPanier_ = new Panier(client.obtenirIdentifiant());
            for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
                monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
            }
            int idClient = this->obtenirIdentifiant();
            monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
        }
}


// Methodes d'acces
long Client::obtenirDateNaissance() const
{
    return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
    return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
    dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(ProduitOrdinaire * prod)
{
    if (monPanier_ == nullptr)
        monPanier_ = new Panier(this->obtenirIdentifiant());
    monPanier_->ajouter(prod);
    // obtenir une note aléatoire
    int appreciation = rand() % 5;
    // faire la mise à jour de la satisfaction au fournisseur
    prod->obtenirFournisseur().noter(appreciation);
}

/****************************************************************************
 * Fonction:   Client::livrer()
 * Description:  Permet de livrer le contenu du panier, en supprimant le Panier actuel du client.
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
void Client::livrerPanier()
{
    monPanier_->livrer();
    delete monPanier_;
    monPanier_ = nullptr;
}

/****************************************************************************
 * Fonction:   Client::miserProduit()
 * Description:  Verifie si le montant mise est superieur au prix du produit, si oui
 * met à jour le prix du produit et l'identifiant du client et ajoute le produit au panier
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/
void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) {
    
    //Verifie si le montantMise est superieur au prix du produit
    if (montantMise > produitAuxEncheres->obtenirPrixBase()){
        
        // Si oui, modifie le prix du produit et change l'identifiant du client
        produitAuxEncheres->modifierPrixBase(montantMise);
        produitAuxEncheres->modifierIdentifiantClient(obtenirIdentifiant());
        
        //Ajout du produit au panier du client
        if (monPanier_ == nullptr){
            monPanier_ = new Panier(this->obtenirIdentifiant());
            monPanier_->ajouter(produitAuxEncheres);
        }
    }
    
    
}

/****************************************************************************
 * Fonction: Client::operator==(const Client & client)
 * Description: Surcharge de l'operateur ==
 * Parametres: (in) const Client & client
 * Retour: le pointeur this
 ****************************************************************************/
Client & Client::operator=(const Client & client)
{
    if (this != &client) {
        Usager temp(*this);
        temp = static_cast<Usager> (client);
        dateNaissance_ = client.obtenirDateNaissance();
        if (client.monPanier_ != nullptr) {
            delete monPanier_;
            monPanier_ = new Panier(obtenirIdentifiant());
            for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
                monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
            }
        }
        else
            monPanier_ = nullptr;
    }
    return *this;
}

/****************************************************************************
 * Fonction: ostream & operator<<(ostream & os, const Client & client)
 * Description: Surcharge de l'operateur << permettant d'afficher le contenu du panier du client et
 * le montant total
 * Parametres: (in) ostream & os, const Client & client
 * Retour: ostream.
 ****************************************************************************/
ostream & operator<<(ostream & os, const Client & client)
{
    Usager usager = static_cast<Usager>(client);
    os << "Client" << usager;
    os << "Le panier de " << client.obtenirPrenom();
    if(client.obtenirPanier() == nullptr) {
        os << " est vide !" << endl;
    }
    else
    {
        os << ":" << endl;
        os << *client.monPanier_
        << endl << endl
        << "----> total à payer : "
        << client.monPanier_->calculerTotalApayer()
        << endl;
    }
    return os; 
}
