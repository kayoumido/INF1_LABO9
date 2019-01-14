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


int main() {

    string searchWord = "zuludw";

    vector<string> inverseDict= readFile("inverse_dictionary");
    inverse(inverseDict);

    vector<string> orderedDict = readFile("ordered_dictionary");

    vector<string> natoDict = readFile("nato");

    vector<string> natoShuffled = readFile("nato_shuffled");
    sortAsc(natoShuffled);

    vector<string> otanDict = readFile("otan");
    sortAsc(otanDict);


    cout << "Recherche lineaire sans iterateur (inverse_dictionary) : ";
    size_t linearResponsePos = linearSearch(inverseDict, searchWord);
    if(linearResponsePos == string::npos) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche lineaire avec iterateur (orderedDict) : ";
    vector<string>::iterator linearResponseIt = linearSearch(orderedDict.begin(), orderedDict.end(), searchWord);
    if(*linearResponseIt == "") {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique (nato) : ";
    size_t binaryResponsePos = linearSearch(natoDict, searchWord);
    if(binaryResponsePos == string::npos) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique avec iterateur (nato_shuffled) : ";
    vector<string>::iterator binaryResponseIt = linearSearch(natoShuffled.begin(), natoShuffled.end(), searchWord);
    if(*binaryResponseIt == "") {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique recursive (otan) : ";
    bool recursiveBinaryResponse1 = recursiveBinarySearch(otanDict, searchWord);
    if(!recursiveBinaryResponse1) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique recursive avec iterateur (otan) : ";
    bool recursiveBinaryResponse2 = recursiveBinarySearch(otanDict.begin(), otanDict.end(), searchWord);
    if(!recursiveBinaryResponse2) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique recursive 2 (otan) : ";
    bool recursiveBinaryResponse3 = recursiveBinarySearch(otanDict, searchWord, 0, otanDict.size());
    if(!recursiveBinaryResponse3) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }

    return 0;
}