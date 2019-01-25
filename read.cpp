/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09-b
Fichier     : read.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 24.01.2019

But         : Contient toutes les fonctions en lien avec la lecture de fichier et
                ordrage / manipulation de vecteur.

Remarque(s) :

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */
#include "read.h"
#include "search.h"
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

/**
 * @brief Build a word using string iterators
 * @param start starting iterator
 * @param end ending iterator
 * @return the newly constructed word
 */
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
    return !isalpha(c) and c != QUOTE;
}

string constructWord(const string::iterator &start, const string::iterator &end) {
    string word = string(start, end);

    // check if the start and/or the end of the constructed word equals QUOTE
    // if so, the QUOTE is removed.
    if (word.front() == QUOTE) word.erase(0, 1);
    if (word.back() == QUOTE) word.pop_back();

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

    if (!constructWord(start, end).empty()) words.push_back(constructWord(start, end));

    return words;
}

void sanitizeDictionary(std::vector<std::string>& dict) {
    for(string& word : dict){
        word = sanitizeWord(word);
    }
}

string sanitizeWord(std::string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

vector<string> sentenceSpellcheck(const vector<string>& DICT, const vector<string>& SENTENCES) {
    vector<string> allMisspelledWords;

    for(vector<string>::const_iterator it = SENTENCES.begin(); it < SENTENCES.end(); ++it) {
        // Get all words of the line and check if they are correctly spell. Every misspelled words are fetched.
        string currentSentence = *it;
        const vector<string> WORDS_OF_LINE = split(currentSentence.begin(), currentSentence.end());
        const vector<string> MISSPELLED_WORDS_OF_LINE = searchWords(DICT, WORDS_OF_LINE);
        size_t lineNb = distance(SENTENCES.begin(), it) + 1;
        // Put every misspelled words in a single vector that we'll return
        for(const string WORD : MISSPELLED_WORDS_OF_LINE) {
            const string STR_LINE = to_string(lineNb) + ": ";
            allMisspelledWords.push_back(STR_LINE + WORD);
        }
    }

    return allMisspelledWords;
}

void displayDict(const std::vector<std::string>& DICT) {
    for(string word : DICT) {
        cout << word << endl;
    }
}
