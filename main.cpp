/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : main.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 14.01.2019

But         : Fichier principale, contenant l'execution des différentes fonctions
                de recherche.

Remarque(s) :

Compilateur : MinGW-g++ <8.2.1>
-----------------------------------------------------------------------------------
 */


#include "read.h"
#include "search.h"
#include <iostream>

using namespace std;

// TODO : I'm a debug function dude ! Don't forgot to remove me later (=
void displayDict(const vector<string> &dict) {
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        cout << *it << endl;
    }
}



int main() {

    vector<string> dict = readFile("dictionary");

    sortAsc(dict);

    displayDict(dict);
    return 0;
}