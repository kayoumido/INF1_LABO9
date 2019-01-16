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

const bool CASE_SENSITIVE = false;

/**
 * @brief Perform a linear search of a word in a vector of strings (or dictionnary)
 * @param DICT vector of the strings to search in
 * @param word to search
 * @return the position of the searched word, string::npos if nothing was found
 */
std::size_t linearSearch(const std::vector<std::string> &DICT, std::string word);

/**
 * @brief Perform a linear search of a word in a vector of strings (or dictionnary)
 * @param START begining iterator
 * @param END end eterator
 * @param searchWord word to search
 * @return the iterator "position" of the searched word, end iterator if nothing was found
 */
std::vector<std::string>::iterator
linearSearch(const std::vector<std::string>::iterator &START, const std::vector<std::string>::iterator &END,
             std::string searchWord);

/**
 * @brief Search for a word in a vector using binary search
 * @param DICT vector to search in
 * @param searchWord word to search
 * @return the position of the searched word, string::npos if nothing was found
 */
std::size_t binarySearch(const std::vector<std::string> &DICT, std::string searchWord);

/**
 * @brief Search for a word within a vector using iterators and binary search method
 * @param startIt starting iterator
 * @param endIt ending iterator
 * @param searchWord word to search for
 * @return the iterator "position" of the searched word, end iterator if nothing was found
 */
std::vector<std::string>::iterator
binarySearch(std::vector<std::string>::iterator startIt, std::vector<std::string>::iterator endIt,
             std::string searchWord);

/**
 * @brief Call function for "simple" recursive binary search
 * @param DICT vector to search in
 * @param searchWord word to search
 * @return true if the word was found, otherwise false
 */
size_t
recursiveBinarySearch(const std::vector<std::string> &DICT, std::string searchWord);

/**
 * @brief Search for a word within a specific range of a vector using binary search method recursively
 * @param DICT vector to search in
 * @param WORD to search
 * @param first beginning of range
 * @param last end of range
 * @return true if the word was found, otherwise false
 */
size_t
recursiveBinarySearch(const std::vector<std::string> &DICT, const std::string &WORD, std::size_t first,
                      std::size_t last);

/**
 * @brief Search for a word within a vector using iterators and binary search method recursively
 * @param startIt starting iterator
 * @param endIt ending iterator
 * @param searchWord word to search
 * @return true if the word was found, otherwise false
 */
bool recursiveBinarySearch(std::vector<std::string>::iterator startIt, std::vector<std::string>::iterator endIt,
                           std::string searchWord);


#endif //LABO09_SEARCH_H
