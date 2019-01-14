/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : read.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 14.01.2019

But         : Contient toutes les fonctions en lien avec la lecture de fichier et
                ordrage de vecteur.

Remarque(s) :

Compilateur : MinGW-g++ <8.2.1>
-----------------------------------------------------------------------------------
 */
#include "read.h"
#include <fstream>

using namespace std;

vector<string> readFile(const string &FILE_NAME) {
    string relativePath = DICT_FILE_LOCATION + OS_TYPE + FILE_NAME + FILE_EXTENSION;
    vector<string> content;
    ifstream ifs;

    ifs.open(relativePath);
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
    bool unsorted = true;

    while (unsorted) {
        unsorted = false;
        for (size_t i = 0; i < dict.size(); ++i) {
            if (i + 1 < dict.size() and dict.at(i) > dict.at(i + 1)) {
                string current = dict.at(i);
                dict.at(i) = dict.at(i + 1);
                dict.at(i + 1) = current;
                unsorted = true;
            }
        }
    }
}
