/********************************************
 * Titre: Travail pratique #5 - Solde.h
 * Date: 10 mars 2018
 * Modifier par: -
 *******************************************/

#include "Solde.h"

Solde::Solde(int pourcentageRabais)
    : pourcentageRabais_(pourcentageRabais)
{
}

Solde::~Solde() {}

double Solde::obtenirPourcentageRabais() const
{
    return pourcentageRabais_;
}

void Solde::modifierPourcentageRabais(int pourcentageRabais)
{
    pourcentageRabais_ = pourcentageRabais;
}
