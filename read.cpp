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

using namespace std;

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


void inverse(vector<string> &dict) {
    for (size_t i = 0; i < dict.size() / 2; ++i) {
        string tmp = dict.at(i);
        // Last - 1 to be in range (size() - 0 = out of range and size() - 0 - 1 = in range)
        dict.at(i) = dict.at(dict.size() - i - 1);
        dict.at(dict.size() - i - 1) = tmp;
    }
}

void sortAsc(vector<string> &dict) {
    sort(dict.begin(), dict.end());
}
