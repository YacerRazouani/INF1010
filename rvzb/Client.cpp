#include "Client.h"
#include <iostream>
#include "ProduitAuxEncheres.h"

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	double TotalAPayer = 0;
	for (unsigned int i = 0; i < panier_.size(); i++) {
		TotalAPayer += panier_[i]->obtenirPrix();
	}

	return TotalAPayer;
    // TODO
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
    // TODO
	Usager::afficherProfil();
	cout << " \t \t code client: \t " << obtenirCodeClient() << endl;
	cout << " \t \t panier: \t " << obtenirPanier().size() << " elements" << endl;

}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

void Client::reinitialiser()
{
    // TODO
for (unsigned int i = 0; i < panier_.size(); i++) {
		if (ProduitAuxEncheres* prod = dynamic_cast<ProduitAuxEncheres*>(panier_[i])) {
			prod->modifierEncherisseur(nullptr);
			prod->modifierPrix(prod->obtenirPrixInitial());
			enleverProduit(panier_[i]);

		}
		else
			enleverProduit(panier_[i]);
	}
panier_.clear();

}
	
