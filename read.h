/**
 * Entête : TODO
 */

#ifndef LABO09_READ_H
#define LABO09_READ_H

#include <string>
#include <vector>

std::vector<std::string> readFile(const std::string& fileName);
void inverse(const std::vector<std::string>& dict);
void sortAsc(const std::vector<std::string>& dict);

// ../ is used because the executable is found in cmake-build-debug/ (clion)
const std::string DICT_FILE_LOCATION = "../dico/";
const std::string OS_TYPE = "unix/";

#endif //LABO09_READ_H
