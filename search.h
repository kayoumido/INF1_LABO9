/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : search.h
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 14.01.2019

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
 * @brief Search a vector for a given value
 * @param NEEDLE the searched value
 * @param HAYSTACK vector in which to search
 * @return the position of the needle in the haystack, if it wasn't found, string::npos is returned
 */
size_t searchAA(const std::string& NEEDLE, const std::vector<std::string>& HAYSTACK);

void sanitizeDictionary(std::vector<std::string>& dict);
std::string sanitizeWord(std::string word);

#endif //LABO09_SEARCH_H
