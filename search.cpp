/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : search.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 16.01.2019

But         : Contient les divers fonctions de recherches (Linéaire, Dicotomique, etc.)

Remarque(s) :

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */
#include "search.h"
#include <algorithm>

using namespace std;

void sanitizeDictionary(std::vector<std::string>& dict) {
    for(string& word : dict){
        word = sanitizeWord(word);
    }
}

string sanitizeWord(std::string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

size_t searchAA(const string& NEEDLE, const vector<string>& HAYSTACK) {

    // the word wasn't found
    return string::npos;
}
