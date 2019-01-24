/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09-b
Fichier     : search.h
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 24.01.2019

But         : Contient le prototype des fonctions de recherche

Remarque(s) :

Compilateur : MinGW-g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef LABO09_SEARCH_H
#define LABO09_SEARCH_H

#include <cstdio>
#include <vector>
#include <string>

/**
 * @brief Check every words passed in parameters if they exist in the specific dictionary.
 *
 * @param DICT The dictionnary that contains every well spelled words.
 * @param WORDS All words we want to check
 * @return a vector of string that contains all misspelled words
 */
std::vector<std::string> searchWords(const std::vector<std::string>& DICT, const std::vector<std::string>& WORDS);

#endif //LABO09_SEARCH_H
