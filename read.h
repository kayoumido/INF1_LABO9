/**
 * Entête : TODO
 */

#ifndef LABO09_READ_H
#define LABO09_READ_H

#include <string>
#include <vector>

// ../ is used because the executable is found in cmake-build-debug/ (clion)
const std::string DICT_FILE_LOCATION = "../dico/";
const std::string OS_TYPE = "unix/";
const std::string FILE_EXTENSION = ".txt";

std::vector<std::string> readFile(const std::string& fileName);
/**
 * @brief Inverse order of all words in a dictionnary.
 * @param dict The dictionnary as a vector of string that contains words
 */
void inverse(std::vector<std::string>& dict);
void sortAsc(const std::vector<std::string>& dict);

#endif //LABO09_READ_H
