/********************************************
* Titre: Travail pratique #3 - Client.h
* Date:
* Auteur:
*******************************************/

#include "Usager.h"
using namespace std;

/****************************************************************************
 * Fonction: Usager::Usager(const string&  nom, const string& prenom, int identifiant,
 * const string& codePostal)
 * Description: Fusion des Constructeurs par parametre 
 * Parametres: (in): const string&  nom
 *				    const string& prenom
 *				    int identifiant
 *				    const string& codePostal
 * Retour: Aucun
 ****************************************************************************/

Usager::Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal):
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal }	
{
}

/****************************************************************************
 * Fonction:   Usager::obtenirNom() const
 * Description: Retourne l'attribut nom_
 * Parametres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Usager::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
 * Fonction:   Usager::obtenirPrenom() const
 * Description: Retourne l'attribut prenom_
 * Parametres: aucun
 * Retour: (string) la valeur de prenom_
 ****************************************************************************/
string Usager::obtenirPrenom() const
{
	return prenom_;
}

/****************************************************************************
 * Fonction:   Usager::obtenirIdentifiant() const
 * Description: Retourne l'attribut identifiant_
 * Parametres: aucun
 * Retour: (int) la valeur de identifiant_
 ****************************************************************************/
int Usager::obtenirIdentifiant() const
{
	return identifiant_;
}

/****************************************************************************
 * Fonction:   Usager::obtenirCodePostal() const
 * Description: Retourne l'attribut codePostal_
 * Parametres: aucun
 * Retour: (string) la valeur de codePostal_
 ****************************************************************************/

string Usager::obtenirCodePostal() const
{
	return codePostal_;
}

/****************************************************************************
 * Fonction:   Usager::modifierNom()
 * Description: Modifie l'attribut nom_
 * Parametres: (in) - const string& nom
 * Retour: Aucun
 ****************************************************************************/
void  Usager::modifierNom(const string& nom)
{
	nom_ = nom;
}
/****************************************************************************
 * Fonction:   Usager::modifierPrenom()
 * Description: Modifie l'attribut prenom_
 * Parametres: (in) - const string& prenom
 * Retour: Aucun
 ****************************************************************************/
void Usager::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

/****************************************************************************
 * Fonction:   Usager::modifierIdentifiant()
 * Description: Modifie l'attribut identifiant_
 * Parametres: (in) - int identifiant
 * Retour: Aucun
 ****************************************************************************/
void Usager::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}
/****************************************************************************
 * Fonction:   Usager::modifierCodePostal()
 * Description: Modifie l'attribut codePostal_
 * Parametres: (in) - const string& codePostal_
 * Retour: Aucun
 ****************************************************************************/
void Usager::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

/****************************************************************************
 * Fonction: Usager::operator=(const Usager & usager)
 * Description: Surcharge de l'operateur =
 * Parametres: (in) const Usager& usager
 * Retour: le contenu du pointeur this
 ****************************************************************************/
Usager &Usager::operator=(const Usager & usager)
{
	if (this != &usager) {
		nom_ = usager.nom_;
		prenom_ = usager.prenom_;
		identifiant_ = usager.identifiant_;
		codePostal_ = usager.codePostal_;		
	}
	return *this;
}
/****************************************************************************
 * Fonction: Usager::operator == (int identifiant) const
 * Description: Surcharge de l'operateur ==
 * Parametres: (in) int identifiant
 * Retour: bool. retourne true sur les identifiants sont les mêmes
 ****************************************************************************/
bool Usager::operator==(int identifiant) const {
	return identifiant_ == identifiant_;
}

/****************************************************************************
 * Fonction: Usager::operator == (const Usager & usager)
 * Description: Surcharge de l'operateur ==
 * Parametres: (in) (const Usager & usager)
 * Retour: bool retourne true le contenu du pointeur this s'il est le même que
 * l'identifiant de l'usager.
 ****************************************************************************/
bool Usager::operator == (const Usager & usager)
{
	return  *this == usager.obtenirIdentifiant();
}

/****************************************************************************
 * Fonction: operator == (int identifiant,const Usager & usager)
 * Description: Surcharge de l'operateur ==
 * Parametres: (in) (int identifiant, const Usager & usager)
 * Retour: bool retourne true si l'usager est égale à l'identifiant
 ****************************************************************************/
bool operator==(int identifiant, const Usager& usager) {
	return usager == identifiant;
}

/****************************************************************************
 * Fonction: ostream & operator<<(ostream & os, const Usager & usager)
 * Description: Surcharge de l'operateur << permettant d'afficher les attributs de Usager
 * Parametres: (in) ostream & os, const Usager & usager
 * Retour: ostream.
 ****************************************************************************/
ostream & operator<<(ostream & os, const Usager & usager)
{
	os << " Usager :";
	os << "\t nom : " << usager.obtenirNom() << endl
	   << "\t prenom : " << usager.obtenirPrenom() << endl
	   << "\t codePostal: " << usager.obtenirCodePostal() << endl;
	return os;
}

