/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : read.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 16.01.2019

But         : Contient toutes les fonctions en lien avec la lecture de fichier et
                ordrage de vecteur.

Remarque(s) :

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */
#include "read.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @brief UnaryPredicate for split find_if, to find separators chars in string
 * @param c current char to compare
 * @return true if a separator was found otherwise false
 */
bool isSeparator(char c);

string constructWord(const string::iterator &start, const string::iterator &end);

vector<string> readFile(const string &FILE) {
    vector<string> content;
    ifstream ifs;

    ifs.open(FILE);
    // check if the file was opened
    if (!ifs.good()) return content;

    string line;
    // read the file line by line
    while (getline(ifs, line)) {
        if (line.length() > 0) content.push_back(line);
    }
    ifs.close();

    return content;
}

void sortAsc(vector<string> &dict) {
    sort(dict.begin(), dict.end());
}

bool isSeparator(char c) {
    return !isalnum(c);
}

string constructWord(const string::iterator &start, const string::iterator &end) {
    string word = string(start, end);
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    return word;
}

vector<string> split(string::iterator start, string::iterator end) {
    vector<string> words;

    string::iterator wordEnd;
    string word;
    while((wordEnd = find_if(start, end, isSeparator)) != end) {

        word = constructWord(start, wordEnd);

        if (!word.empty()) words.push_back(word);
        start = wordEnd + 1;
    }

    words.push_back(constructWord(start, end));

    return words;
}
