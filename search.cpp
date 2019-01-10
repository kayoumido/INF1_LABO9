/**
 * Entête : TODO
 */

#include "search.h"

using namespace std;

vector<string>::iterator
linearSearch(const vector<string>::iterator &START, const vector<string>::iterator &END,
             const string &WORD) {

    for (vector<string>::iterator i = START; i < END; ++i) {
        if (*i == WORD) return i;
    }
    return END;
}

std::size_t dichotomySearch(const std::vector<std::string> &DICT, const std::string &WORD) {

    size_t middle = DICT.size() / 2;

    if (WORD == DICT.at(middle)) return middle;

    size_t start = 0;
    size_t end = middle;
    string middle_word = DICT.at(middle);
    if (WORD > middle_word) {
        start = middle;
        end = DICT.size();
    }

    for (size_t i = start; i < end; ++i) {
        if (WORD == DICT.at(i)) return i;
    }

    return size_t(-1);
}
