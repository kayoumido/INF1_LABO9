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
#include "read.h"
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> searchWords(const vector<string>& DICT, const vector<string>& WORDS) {
    vector<string> wordsNotFounds;
    wordsNotFounds.reserve(WORDS.size());
    for(vector<string>::const_iterator itWords = WORDS.begin(); itWords < WORDS.end(); ++itWords) {
        bool found = binary_search(DICT.begin(), DICT.end(), sanitizeWord(*itWords));
        if(!found) {
            wordsNotFounds.push_back(*itWords);
        }
    }
    wordsNotFounds.shrink_to_fit();

    return wordsNotFounds;
}
