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

std::vector<std::string> searchWords(const std::vector<std::string>& DICT, const std::vector<std::string>& WORDS);

#endif //LABO09_SEARCH_H
