/**
 * Entête : TODO
 */


#include <iostream>
#include <fstream>
#include "read.h"

using namespace std;

std::vector<std::string> readFile(const std::string &fileName) {
  string relativePath = DICT_FILE_LOCATION + OS_TYPE + fileName + ".txt";
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
