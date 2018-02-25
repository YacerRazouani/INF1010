/********************************************
* Titre: Travail pratique #3 - Produit.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Produit.h"



/****************************************************************************
 * Fonction: Produit::Produit(Fournisseur & fournisseur, const string & nom, int reference,
 * double prix, TypeProduit type)
 * Description: Constructeur par paramtre
 * Parametres:  (in) Fournisseur& fournisseur
 *                  const string& nom
 *				   int reference
 *				   double prix
 *                  TypeProduit type
 *                  bool estTaxable
 * Retour: Aucun
 ****************************************************************************/
Produit::Produit(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type) :
	fournisseur_{ fournisseur },
	nom_{nom},
	reference_{reference},
	prix_{prix},
	type_{type}
{
	fournisseur_.ajouterProduit(this);
}
/****************************************************************************
 * Fonction: Produit::~Produit() ()
 * Description: Destructeur de la classe Produit
 * Parametres: Aucun
 * Retour: Aucun
 ****************************************************************************/
Produit::~Produit() {
	fournisseur_.enleverProduit(this);
}

// Methodes d'acces
/****************************************************************************
 * Fonction:   Produit::obtenirNom() const
 * Description: Retourne l'attribut nom_
 * Parametres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Produit::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
 * Fonction:   Produit::obtenirReference() const
 * Description: Retourne l'attribut reference_
 * Parametres: aucun
 * Retour: (int) la valeur de reference_
 ****************************************************************************/
int Produit::obtenirReference() const
{
	return reference_;
}
/****************************************************************************
 * Fonction:   Produit::obtenirPrix() const
 * Description: Retourne l'attribut prix_
 * Parametres: aucun
 * Retour: (double) la valeur de prix_
 ****************************************************************************/
double Produit::obtenirPrix() const
{
	return prix_;
}
/****************************************************************************
 * Fonction:   Produit::obtenirFournisseur() const
 * Description: Retourne l'attribut fournisseur_
 * Parametres: aucun
 * Retour: (Fournisseur&) la valeur de fournisseur_
 ****************************************************************************/
Fournisseur& Produit::obtenirFournisseur() const
{
	return fournisseur_;
}
/****************************************************************************
 * Fonction:   Produit::retournerType() const
 * Description: Retourne l'attribut type_
 * Parametres: aucun
 * Retour: (TypeProduit) la valeur de type_
 ****************************************************************************/
TypeProduit Produit::retournerType() {
	return type_;
}

// Methodes de modification
/****************************************************************************
 * Fonction:   Produit::modifierPrix()
 * Description: Modifie l'attribut prix_
 * Parametres: (in) - double prix
 * Retour: Aucun
 ****************************************************************************/
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}
/****************************************************************************
 * Fonction:   Produit::modifierPrix()
 * Description: Modifie l'attribut prix_
 * Parametres: (in) - double prix
 * Retour: Aucun
 ****************************************************************************/
void Produit::modifierReference(int reference)
{
	reference_ = reference;
}
/****************************************************************************
 * Fonction:   Produit::modifierPrix()
 * Description: Modifie l'attribut prix_
 * Parametres: (in) - double prix
 * Retour: Aucun
 ****************************************************************************/
void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

/****************************************************************************
 * Fonction: Produit::operator > (const Produit & produit)
 * Description: Surcharge de l'operateur >
 * Parametres: (in) const Produit & produit
 * Retour: bool. Si le prix (prix_) du produit sur lequel la fonction est utilise
 *				est superieur a celui du parametre la fonctione renvoit 'true',
 *				sinon 'false'.
 ****************************************************************************/
bool Produit::operator>(const Produit & produit) const
{
	return prix_ > produit.prix_;
}
/****************************************************************************
 * Fonction: Produit::operator < (const Produit & produit)
 * Description: Surcharge de l'operateur >
 * Parametres: (in) const Produit & produit
 * Retour: bool. Si le prix (prix_) du produit sur lequel la fonction est utilise
 *				est inferieur a celui du parametre la fonctione renvoit 'true',
 *				sinon 'false'.
 ****************************************************************************/
bool Produit::operator<(const Produit & produit) const
{
	return prix_ < produit.prix_;
}
/****************************************************************************
 * Fonction: Produit::operator == (const Produit & produit)
 * Description: Surcharge de l'operateur ==
 * Parametres: (in) const Produit & p
 * Retour: bool. Si le nom (nom_), la reference (reference_) et le prix (prix_)
 *				du produit sur lequel la fonction est utilise
 *				est egale a celui du parametre la fonctione renvoit 'true',
 *				sinon 'false'.
 ****************************************************************************/
bool Produit::operator==(const Produit & produit) const
{
	return (nom_ == produit.nom_ &&
			prix_ == produit.prix_ &&
			reference_ == produit.reference_);
}
//AJOUTER ENTETE
inline istream & operator >> (istream & is, TypeProduit & typeProduit) {
	unsigned int type = 0;
	if (is >> type)
		typeProduit = static_cast<TypeProduit>(type);
	return is;
}
/****************************************************************************
 * Fonction: friend istream & operator>>(istream & is, Produit & produit)
 * Description: Surcharge de l'operateur >>
 * Parametres: (in) istream & is, Produit & produit
 * Retour: (istream) is
 ****************************************************************************/
istream & operator>>(istream & is, Produit & produit)
{
	return is >> produit.nom_ >> produit.reference_ >> produit.prix_ >> produit.type_;
}
/****************************************************************************
 * Fonction: friend ostream & operator<<(ostream& os, const Produit& produit)
 * Description: Surcharge de l'operateur <<
 * Parametres: (in) ostream& os, const Produit& produit
 * Retour: (ostream) os.
 ****************************************************************************/
 ostream & operator<<(ostream & os, const Produit & produit)
{
	 os << "Produit :"
		 << " nom: " << produit.obtenirNom() << endl
		 << " \t \t ref : " << produit.obtenirReference() << endl
		 << " \t \t prix actuel : " << produit.obtenirPrix() << endl
		 << "\t Fournisseur " << produit.obtenirFournisseur().obtenirNom() << endl;
	 return os;
}


