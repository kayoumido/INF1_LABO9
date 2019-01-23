/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : main.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 16.01.2019

But         : Fichier principale, contenant l'execution des différentes fonctions
                de recherche.

Remarque(s) : 1. Nous avons décider de gérer entièrement la casse, dans le header search.h vous pouvez changer la variable
              "CASE_SENSITIVE" pour tester cela.
              2. Nous avons utiliser / tester notre code sur des plateformes Linux. Vous pouvez retrouver la variable
              "OS_TYPE" qui correspond à la plateforme que vous utiliser dans le header read.h. Il faut qu'elle corresponde
              à l'OS que vous utilisez car les dictionnaires n'ont pas le meme encodage sur Linux ou Windows.

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */


#include "read.h"
#include "search.h"
#include <iostream>
#include <algorithm>

using namespace std;

void displayDict(const vector<string>& DICT) {
    for(auto i = DICT.begin(); i < DICT.end(); ++i) {
        cout << *i << endl;
    }
}


int main() {

    // Dictionary loading
    vector<string> dict = readFile("../files/dictionary.txt");
    //vector<string> dict = readFile("../files/test_dict.txt");
    //vector<string> dict = {"mot1", "mot2", "mot3"};

    //sortAsc(dict);

    displayDict(dict);

    //vector<string> sentences = {"mot1 mot2 maison", "avion mot1"};
    //vector<string> sentences = readFile("../files/test_text.txt");
    vector<string> sentences = readFile("../files/input_sh.txt");
    //vector<string> foo = split(sentence.begin(), sentence.end());

    for(auto it = sentences.begin(); it < sentences.end(); ++it) {
        string currentSentence = *it;
        vector<string> words = split(currentSentence.begin(), currentSentence.end());

        for(auto itWords = words.begin(); itWords < words.end(); ++itWords) {
            vector<string> wordToSearch = {*itWords};
            //cout << *itWords << endl;
            auto itSearch = search(dict.begin(), dict.end(), wordToSearch.begin(), wordToSearch.end());
            if(itSearch == dict.end()) {
                size_t lineNb = distance(sentences.begin(), it) + 1;
                cout << "Line : " << lineNb << " " << *itWords << endl;
            }
        }
    }

    // displayDict(dict);
    return 0;
}