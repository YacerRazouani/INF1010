#include "ClientPremium.h"
#include <iostream>

ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::obtenirTotalAPayer() const
{
    // TODO
	double total = Client::obtenirTotalAPayer() - (5 * panier_.size());
	for (unsigned int i = 0; i < panier_.size(); i++) {                       // Cette boucle permet de parcourir les produits des clients et de vérifier si
		if (panier_[i]->obtenirPrix() < 5)                                    // certains produits n'ont pas coûtés moins que 0 $. Elle permet de rajouter la
			total += 5 - panier_[i]->obtenirPrix();                     // somme nécessaire afin de remmettre le coût d'un produit à 0$, après avoir appliqué
	}                                                                         // le rabais de client premium.
	return total;
}

void ClientPremium::afficherProfil() const
{
    // TODO
	Client::afficherProfil();
	cout << "jours restants: " << obtenirJoursRestants() << endl;
}

void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
