#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	cout << "PROFILS" << endl;
	for (unsigned int i = 0; i < usagers_.size(); i++) {
		usagers_[i]->afficherProfil();
	}
}

double Gestionnaire::obtenirChiffreAffaires() const
{
    // TODO
	double total = 0;
	for (unsigned int i = 0; i < usagers_.size(); i++) {
		total += usagers_[i]->obtenirTotalAPayer();
	}
	return total;
}
void Gestionnaire::ajouterUsager(Usager *usager)
{
    // TODO
	bool ajouter = true;
	for (unsigned int i = 0; i < usagers_.size(); i++) {
		if (usagers_[i] == usager) {
			ajouter = false;
		}
	}
	if (ajouter == true) {
		usagers_.push_back(usager);
	}
}

void Gestionnaire::reinitialiser()
{
    // TODO
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    // TODO
}
