/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat }
{
}

Rayon::~Rayon()
{
	//if (tousProduits_ != nullptr)
	//	delete[] tousProduits_;
}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

vector< Produit* > Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return tousProduits_.capacity();;
}

int Rayon::obtenirNombreProduits() const
{
	return tousProduits_.size();
}

// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

//void Rayon::ajouterProduit(Produit * produit)
//{
//	if (tousProduits_ != nullptr)
//	{
//		if (nombreProduits_ >= capaciteProduits_)
//		{
//			Produit ** temp;
//			capaciteProduits_ += 5;
//			temp = new Produit*[capaciteProduits_];
//			for (int i = 0; i < nombreProduits_; i++)
//				temp[i] = tousProduits_[i];
//			delete[] tousProduits_;
//			tousProduits_ = temp;
//
//		}
//		tousProduits_[nombreProduits_++] = produit;
//	}
//	else
//	{
//		capaciteProduits_ = 5;
//		tousProduits_ = new Produit*[capaciteProduits_];
//		tousProduits_[nombreProduits_++] = produit;
//	}
//}

Rayon& Rayon::operator+=(Produit* produit)
{
	tousProduits_.push_back(produit);
	return *this;
}

int Rayon::compterDoublons(const Produit & produit)
{
	int nombreDoublons = 0;

	for (unsigned int i = 0; i < tousProduits_.size(); i++) {
		if ((*tousProduits_[i]).operator==(produit)) {
			nombreDoublons++;
		}
	}

	return nombreDoublons;
}

//void Rayon::afficher() const
//{
//	cout << "Le rayon " << categorie_ << ": " << endl;
//	for (int i = 0; i < nombreProduits_; i++) {
//		cout << "----> ";
//		tousProduits_[i]->afficher();
//	}
//}

ostream & operator<<(ostream& o, const Rayon& rayon)
{
	o << "Le rayon " << rayon.obtenirCategorie() << ": " << endl;
	for (int i = 0; i < rayon.obtenirNombreProduits(); i++) {
		o << "----> ";
		//tousProduits_[i]->afficher();
		o << rayon.tousProduits_[i];
	}
	return o;
}
