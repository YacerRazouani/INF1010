#include "Foncteur.h"

template<typename T>
FoncteurEgal::FoncteurEgal(T* t) : t_(t)
{
}

template<typename T>
bool FoncteurEgal::operator() (pair<int, T*>)
{
	if (pair.first == pair.second)
		return 1;
	else
		return 0;
}

