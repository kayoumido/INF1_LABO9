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

#endif //LABO09_READ_H
