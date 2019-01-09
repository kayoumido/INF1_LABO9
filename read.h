/**
 * Entête : TODO
 */

#ifndef LABO09_READ_H
#define LABO09_READ_H

#include <string>
#include <vector>

std::vector<std::string> readFile(const std::string& fileName);
/**
 * @brief Inverse order of all words in a dictionnary.
 * @param dict The dictionnary as a vector of string that contains words
 */
void inverse(std::vector<std::string>& dict);
void sortAsc(const std::vector<std::string>& dict);

#endif //LABO09_READ_H
