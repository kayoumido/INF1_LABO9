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

std::vector<std::string>::iterator
linearSearch(const std::vector<std::string>::iterator &START, const std::vector<std::string>::iterator &END,
             std::string searchWord);

std::size_t dichotomySearch(const std::vector<std::string> &DICT, const std::string &WORD);

std::vector<std::string>::iterator
dichotomySearch(const std::vector<std::string>::iterator &START, const std::vector<std::string>::iterator &END,
                const std::string &WORD);

bool
recursiveDichotomySearch(const std::vector<std::string>::iterator &START, const std::vector<std::string>::iterator &END,
                         const std::string &WORD);

bool
rechercheDichotomiqueRecursive(const std::vector<std::string> &DICT, const std::string &WORD, std::size_t first = 0,
                               std::size_t last = 10); // TODO trouver les vrais valeurs first et last


#endif //LABO09_SEARCH_H
