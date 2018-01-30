/*
 * File:   main.cpp
 * Author: bram
 *
 * Created on November 8, 2015, 8:39 PM
 */

#include <iostream>
#include "HashMap.h"
#include <string>
#include <fstream>
using namespace std;


/*
 * Logiciel : Pari
 * Description: Le logiciel Pari a pour but de prendre le nom
 d'un fichier comme argument, d'imprimer le mot le plus populaire
 du fichier texte ainsi que son nombre d'occurences.
*/


int main(int argc, char** argv, char** nomFichier) {
    HashMap mymap;
    
    fstream fichier("nomFichier");
    while (fichier.peek() != EOF ){
      string mot;
      mot = fichier.get();
      mymap.compteur(mot);
      cout << mot << endl;
    }
      fichier.close();
    
  //utilisation normale
    vector<string> clefs = mymap.getKeys();
    string clefMax = clefs.at(0);
    
    int nbFoisMax;
    for (int i = 0; i < clefs.size(); i++) {
        int nbFoisCourant;
        mymap.get(clefs.at(i), nbFoisCourant);
        mymap.get(clefMax, nbFoisMax);
        
        if (nbFoisCourant>nbFoisMax){
            clefMax = clefs.at(i);
        }
    }
    
    cout << "Le mot le plus populaire du fichier texte est "<< clefMax << " fois." << endl;
    cout << "Il y apparait " << nbFoisMax << " fois." << endl;
    
  return 0;
}
