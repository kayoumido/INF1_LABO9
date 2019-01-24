/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09-b
Fichier     : main.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 24.01.2019

But         : Le but de ce laboratoire est d'utiliser les outils développés au laboratoire 9 pour créer un correcteur
                orthographique de base qui parcourt un texte et indique les mots mal orthographiés.

Remarque(s) : La casse n'est pas gérée, toutes les comparaisons se font en minuscule. Attention si vous compilez avec
              l'OS Linux, il se peut que les fichiers contenus dans le dossier "files" ne soient pas au bon format UNIX.
              Pour régler le problème il faut re-générer le fichier au bon format, c.f commande dos2unix.

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */


#include "read.h"
#include "search.h"
#include <algorithm>

using namespace std;


int main() {
    // Dictionary and text sentences loading
    vector<string> dict = readFile("../files/dictionary.txt");
    const vector<string> SENTENCES = readFile("../files/input_sh.txt");

    sanitizeDictionary(dict);
    sortAsc(dict); // Don't forget to sort asc, because we use binary_search algo.

    // Fetch all misspelled word and display them
    const vector<string> MISSSPELLED_WORDS = sentenceSpellcheck(dict, SENTENCES);
    displayDict(MISSSPELLED_WORDS);

    return 0;
}