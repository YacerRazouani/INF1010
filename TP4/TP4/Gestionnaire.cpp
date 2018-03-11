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
	double chiffre = 0;
	for (unsigned int i = 0; i < usagers_.size(); i++) {
		chiffre += usagers_[i]->obtenirTotalAPayer();
	}
	return chiffre;
}
void Gestionnaire::ajouterUsager(Usager *usager)
{
    // TODO
	bool ajouterUsager = true;
	for (unsigned int i = 0; i < usagers_.size(); i++) {
		if (usagers_[i] == usager) {
			ajouterUsager = false;
		}
	}
	if (ajouterUsager == true) {
		usagers_.push_back(usager);
	}
}

void Gestionnaire::reinitialiser()
{
    // TODO
    for (unsigned int i = 0; i < usagers_.size(); i++) {
        usagers_[i]->reinitialiser();
    }
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    // TODO
    if (montant <= produit->obtenirPrix()) {
    }
    else
        produit->mettreAJourEnchere(client, montant);
}
