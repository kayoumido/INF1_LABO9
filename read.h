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

// Vector to contain all the different word separators
const std::vector<char> SEPARATORS = {
    ' ',
    '-',
    ',',
};

/**
 * @brief Reads a file and store it's content in a vector
 * @param FILE path of the file to open
 * @return the content of the file in the form of a vector of strings
 */
std::vector<std::string> readFile(const std::string &FILE);

/**
 * @brief Separate each word of a sentence in a vector
 * @param SENTENCE to separate
 * @return Vector containing each word of the given sentence
 */
std::vector<std::string> split(std::string::iterator start, std::string::iterator end);

/**
 * @brief ASC Sort a vector of string using
 * @param dict vector to sort
 */
void sortAsc(std::vector<std::string> &dict);

#endif //LABO09_READ_H
