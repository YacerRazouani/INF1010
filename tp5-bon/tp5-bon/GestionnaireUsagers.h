/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 6 avril 2018
* Auteur: Amar Ghaly (1905322) & Yacer Razouani (1899606)
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Usager.h"
#include <set>
#include "Foncteur.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"


class GestionnaireUsagers : public GestionnaireGenerique <Usager, set<Usager*>, AjouterUsager, SupprimerUsager, FoncteurDiminuerPourcent>
{
public:
	double obtenirChiffreAffaires() const;
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	void reinitialiser();
	void afficherProfils() const;
};
