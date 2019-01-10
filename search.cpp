/**
 * Entête : TODO
 */

#include "search.h"

using namespace std;

/**
 * @brief Transform the word in paramerer as a string in lower case
 *
 * @param word The word we want to transform in lower case
 * @return The word in lower case
 */
string strToLower(string word);


size_t linearSearch(const vector<string>& DICT, string searchWord) {
    if(!CASE_SENSITIVE) searchWord = strToLower(searchWord); // searchWord transformation needed if not case sensitive

    size_t foundPos = string::npos;
    for(size_t i = 0; i <= DICT.size() - 1; ++i) {
        // word transformation needed if not case sensitive
        string currentWord = CASE_SENSITIVE ? DICT.at(i) : strToLower(DICT.at(i));
        if(currentWord == searchWord){
            foundPos = i;
            break;
        }
    }
    return foundPos;
}

vector<string>::iterator
linearSearch(const vector<string>::iterator &START, const vector<string>::iterator &END,
             string searchWord) {

    if(!CASE_SENSITIVE) searchWord = strToLower(searchWord); // searchWord transformation needed if not case sensitive

    for (vector<string>::iterator i = START; i < END; ++i) {
        string currentWord = CASE_SENSITIVE ? *i : strToLower(*i);
        if (currentWord == searchWord) return i;
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


string strToLower(string word) {
    string wordLower;
    for(size_t i = 0; i <= word.length() - 1; ++i) {
        wordLower += (char) tolower(word.at(i));
    }
    return wordLower;
}
