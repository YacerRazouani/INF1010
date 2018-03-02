#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	cout << "PROFILS" << endl;
	for (int i = 0; i < usagers_.size(); i++) {
		usagers_[i]->afficherProfil();
	}
}

double Gestionnaire::obtenirChiffreAffaires() const
{
    // TODO
	double total = 0;
	for (int i = 0; i < usagers_.size(); i++) {
		total += usagers_[i]->obtenirTotalAPayer();
	}
	return total;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
    // TODO
}

void Gestionnaire::reinitialiser()
{
    // TODO
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    // TODO
}
