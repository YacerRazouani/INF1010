/********************************************
 * Titre: Travail pratique #3 - Panier.cpp
 * Date: 25 février 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/

#include "Panier.h"
using namespace std;
/****************************************************************************
 * Fonction: Panier::Panier()
 * Description: Constructeur par paramètre et par default
 * Parametres: int idClient
 * Retour: Aucun
 ****************************************************************************/
Panier::Panier(int idClient) {
	idClient_ = idClient;
	totalAPayer_ = 0;

}

/****************************************************************************
 * Fonction: Panier::~Panier()
 * Description: Destructeur de la classe Panier
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
Panier::~Panier()
{
	contenuPanier_.clear();
}

/****************************************************************************
 * Fonction: Panier::obtenirContenuPanier()const
 * Description: Retourne le vecteur contenuPanier_
 * Parametres: Aucun
 * Retour: vector<Produit*> : un vecteur contenant des Produit*
 ****************************************************************************/
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}
/****************************************************************************
 * Fonction: Panier::obtenirNombreContenu()const
 * Description: Retourne la taille du vecteur contenuPanier_
 * Parametres: Aucun
 * Retour: int : la taille du vecteur
 ****************************************************************************/
int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}

/****************************************************************************
 * Fonction: Panier::obtenirIdClient() const
 * Description: Retourne l'attribut idClient_
 * Parametres: Aucun
 * Retour: int idClient_
 ****************************************************************************/

int Panier::obtenirIdClient() const {
	return idClient_;
}
/****************************************************************************
 * Fonction: Panier::obtenirTotalApayer() const
 * Description: Retourne l'attribut totalAPayer_
 * Parametres: Aucun
 * Retour: (double) le total a payer
 ****************************************************************************/
double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}

/****************************************************************************
 * Fonction: Panier::calculerTotalApayer() const
 * Description: Retourne l'attribut totalAPayer_
 * Parametres: Aucun
 * Retour: (double) le total a payer
 ****************************************************************************/
double Panier::calculerTotalApayer()  const
{
	double totalAPayer = totalAPayer_;
	for (unsigned int i = 0; i < contenuPanier_.size(); i++) {
		if (contenuPanier_[i]->retournerType() == 1) {											//Le type 1 est le type ProduitAuxEncheres.
			ProduitAuxEncheres* produit = static_cast<ProduitAuxEncheres*>(contenuPanier_[i]);
			if (produit->obtenirIdentifiantClient() == idClient_) {
				totalAPayer += produit->obtenirPrixBase();
			}
		}
	}
	return totalAPayer;
}

/****************************************************************************
 * Fonction: Panier::modifierTotalAPayer(double totalAPayer)
 * Description: Modifie l'attribut totalAPayer_
 * Parametres: (in) double totalAPayer
 * Retour: double : le total a payer
 ****************************************************************************/
void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

/****************************************************************************
 * Fonction: Panier::modifierIdClient(int idClient)
 * Description: Modifie l'attribut  idClient_
 * Parametres: (in) int idClient
 * Retour: int idClient
 ****************************************************************************/
void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}


/****************************************************************************
 * Fonction:   Panier::ajouter ()
 * Description: Ajoute le pointeur Produit * prod au vecteur contenuPanier_
 * Parametres: (in-out) Produit * prod
 * Retour: aucun
 ****************************************************************************/
void Panier::ajouter(Produit * prod)
{

	if (prod->retournerType() == 0) {											//Le type 0 est le type ProduitOrdinaire.
		ProduitOrdinaire* produit = static_cast<ProduitOrdinaire*>(prod);
		if (produit->obtenirEstTaxable()) {
			totalAPayer_ += (produit->obtenirPrix() + (produit->obtenirPrix()* TAUX_TAXE));
		}
	}
	else {
		ProduitAuxEncheres* produit = static_cast<ProduitAuxEncheres*>(prod);
		totalAPayer_ += produit->obtenirPrix();
	}
	contenuPanier_.push_back(prod);
}

/****************************************************************************
 * Fonction:   Panier::livrer()
 * Description: Supprime le contenu du tableau et
 *			   re-initialise l'etat de l'attribut totalAPayer_.
 * Parametres: aucun
 * Retour: aucun
 ****************************************************************************/

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

/****************************************************************************
 * Fonction:   Panier::trouverProduitPlusCher()
 * Description: Trouve le produit le plus cher dans le Panier (contenuPanier_).
 * Parametres: aucun
 * Retour: Produit* : retourne un pointeur vers le produit le plus cher.
 ****************************************************************************/
Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}
/****************************************************************************
 *Fonction: Panier::operator << (ostream& os, const Panier & panier)
 * Description : Surcharge de l'operateur <<
 * Parametres : (in) ostream & os, const Panier & panier
 * Retour : ostream os.
 ****************************************************************************/
ostream & operator<<(ostream & os,  const Panier & panier)
{

	for (unsigned int i = 0; i < panier.obtenirContenuPanier().size(); i++) {
		if (panier.obtenirContenuPanier()[i]->retournerType() == 0) {													//Type ProduitOrdinaire.
			ProduitOrdinaire* produit = static_cast<ProduitOrdinaire*> (panier.obtenirContenuPanier()[i]);
			os << *produit;
		}
		if (panier.obtenirContenuPanier()[i]->retournerType() == 1) {													//Type ProduitAuxEncheres.
			ProduitAuxEncheres* produit = static_cast<ProduitAuxEncheres*> (panier.obtenirContenuPanier()[i]);
			os << *produit;
		}
	}
	return os;
}
