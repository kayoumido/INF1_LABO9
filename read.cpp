/**
 * Entête : TODO
 */

#include "read.h"
#include <iostream>
#include <fstream>

using namespace std;

std::vector<std::string> readFile(const std::string &fileName) {
  string relativePath = DICT_FILE_LOCATION + OS_TYPE + fileName + FILE_EXTENSION;
  vector<string> content;
  ifstream ifs;

  ifs.open(relativePath);
  // check if the file was opened
  if (!ifs.good()) return content;

  string line;
  // read the file line by line
  while (getline(ifs, line)) {
    if (line.length() > 0) content.push_back(line);
  }
  ifs.close();

  return content;
}


void inverse(vector<string>& dict) {
    for(size_t i = 0; i < dict.size() / 2; ++i) {
        string tmp = dict.at(i);
        // Last - 1 to be in range (size() - 0 = out of range and size() - 0 - 1 = in range)
        dict.at(i) = dict.at(dict.size() - i - 1);
        dict.at(dict.size() - i - 1) = tmp;
    }
}