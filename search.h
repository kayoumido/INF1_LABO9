/**
 * Entête : TODO
 */

#ifndef LABO09_SEARCH_H
#define LABO09_SEARCH_H

#include <cstdio>
#include <vector>
#include <string>

const bool CASE_SENSITIVE = false;

std::size_t linearSearch(const std::vector<std::string> &DICT, std::string word);

std::vector<std::string>::iterator
linearSearch(const std::vector<std::string>::iterator &START, const std::vector<std::string>::iterator &END,
             std::string searchWord);

std::size_t binarySearch(const std::vector<std::string> &DICT, std::string searchWord);

std::vector<std::string>::iterator
binarySearch(std::vector<std::string>::iterator startIt, std::vector<std::string>::iterator endIt,
             std::string searchWord);

bool recursiveBinarySearch(std::vector<std::string>::iterator startIt, std::vector<std::string>::iterator endIt,
                           std::string searchWord);

bool
recursiveBinarySearch(const std::vector<std::string> &DICT, std::string searchWord);

bool
recursiveBinarySearch(const std::vector<std::string> &DICT, const std::string &WORD, std::size_t first,
                      std::size_t last);



#endif //LABO09_SEARCH_H
