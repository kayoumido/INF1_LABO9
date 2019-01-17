/*
-----------------------------------------------------------------------------------
Laboratoire : Labo09
Fichier     : read.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 14.01.2019

But         : Contient le prototype des fonctions en lien avec la lecture de fichier
                et l'ordage de vecteur.

Remarque(s) :

Compilateur : MinGW-g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef LABO09_READ_H
#define LABO09_READ_H

#include <string>
#include <vector>

/**
 * @brief Reads a file and store it's content in a vector
 * @param fileName to open
 * @return the vector containing the file content
 */
std::vector<std::string> readFile(const std::string &FILE);

/**
 * @brief Inverse order of all the items in a vector of strings.
 * @param dict the vector of strings to invert
 */
void inverse(std::vector<std::string> &dict);

/**
 * @brief ASC Sort a vector of string using
 * @param dict vector to sort
 */
void sortAsc(std::vector<std::string> &dict);

#endif //LABO09_READ_H
