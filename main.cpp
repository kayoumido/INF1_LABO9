/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : main.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 14.01.2019

But         : Fichier principale, contenant l'execution des différentes fonctions
                de recherche.

Remarque(s) : 1. Nous avons décider de gérer entièrement la casse, dans le header search.h vous pouvez changer la variable
              "CASE_SENSITIVE" pour tester cela.
              2. Nous avons utiliser / tester notre code sur des plateformes Linux. Vous pouvez retrouver la variable
              "OS_TYPE" qui correspond à la plateforme que vous utiliser dans le header read.h. Il faut qu'elle corresponde
              à l'OS que vous utilisez car les dictionnaires n'ont pas le meme encodage sur Linux ou Windows.

Compilateur : MinGW-g++ <8.2.1>
-----------------------------------------------------------------------------------
 */


#include "read.h"
#include "search.h"
#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    // Dictionary loading
    vector<string> dict = readFile("dictionary");

    vector<string> inverseDict= readFile("inverse_dictionary");
    inverse(inverseDict);

    vector<string> orderedDict = readFile("ordered_dictionary");

    vector<string> natoDict = readFile("nato");

    vector<string> natoShuffled = readFile("nato_shuffled");
    sortAsc(natoShuffled);

    vector<string> otanDict = readFile("otan");
    inverse(otanDict);


    // User input
    string searchWord;
    cout << "Veuillez entrer un mot à rechercher : ";
    cin >> searchWord;

    cout << "Recherche du mot : " << searchWord << endl;
    cout << "------------------------------------" << endl;

    cout << "Recherche lineaire sans iterateur (inverse_dictionary) : ";
    size_t linearResponsePos = linearSearch(inverseDict, searchWord);
    if(linearResponsePos == string::npos) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche lineaire avec iterateur (dictionary) : ";
    vector<string>::iterator linearResponseIt = linearSearch(dict.begin(), dict.end(), searchWord);
    if(linearResponseIt == dict.end()) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique (nato) : ";
    size_t binaryResponsePos = binarySearch(natoDict, searchWord);
    if(binaryResponsePos == string::npos) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique avec iterateur (nato_shuffled) : ";
    vector<string>::iterator binaryResponseIt = binarySearch(natoShuffled.begin(), natoShuffled.end(), searchWord);
    if(binaryResponseIt == natoShuffled.end()) {
        cout << "Pas trouve" << endl;
    } else {
        cout << "Trouve" << endl;
    }


    cout << "Recherche dichotomique recursive (otan) : ";
    size_t recursiveBinaryResponse1 = recursiveBinarySearch(otanDict, searchWord);
    if(recursiveBinaryResponse1 == string::npos) {
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

    return 0;
}