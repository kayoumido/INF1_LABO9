/**
 * Entête : TODO
 */

#ifndef LABO09_SEARCH_H
#define LABO09_SEARCH_H

#include <cstdio>
#include <vector>
#include <string>

const bool CASE_SENSITIVE = false;

std::size_t linearSearch(const std::vector<std::string>& DICT, std::string word);
std::vector<std::string>::iterator linearSearch(const std::vector<std::string>::iterator& begin, const std::vector<std::string>::iterator& end, const std::string& word);
std::size_t dichotomySearch(const std::vector<std::string>& dict, const std::string& word);
std::vector<std::string>::iterator dichotomySearch(const std::vector<std::string>::iterator& begin, const std::vector<std::string>::iterator& end, const std::string& word);
bool recursiveDichotomySearch(const std::vector<std::string>::iterator& begin, const std::vector<std::string>::iterator& end, const std::string& word);
bool rechercheDichotomiqueRecursive(const std::vector<std::string>& dict, const std::string& word, std::size_t first = 0, std::size_t last = 10); // TODO trouver les vrais valeurs first et last


#endif //LABO09_SEARCH_H
