/**
 * Entête : TODO
 */

#include "read.h"

#include <iostream>

using namespace std;

void inverse(vector<string>& dict) {
    for(size_t i = 0; i < dict.size() / 2; ++i) {
        string tmp = dict.at(i);
        // Last - 1 to be in range (size() - 0 = out of range and size() - 0 - 1 = in range)
        dict.at(i) = dict.at(dict.size() - i - 1);
        dict.at(dict.size() - i - 1) = tmp;
    }
}