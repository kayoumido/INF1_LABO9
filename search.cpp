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


string strToLower(string word) {
    string wordLower;
    for(size_t i = 0; i <= word.length() - 1; ++i) {
        wordLower += (char) tolower(word.at(i));
    }
    return wordLower;
}
