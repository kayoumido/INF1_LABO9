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


size_t linearSearch(const vector<string> &DICT, string searchWord) {
    if (!CASE_SENSITIVE) searchWord = strToLower(searchWord); // searchWord transformation needed if not case sensitive

    size_t foundPos = string::npos;
    for (size_t i = 0; i <= DICT.size() - 1; ++i) {
        // word transformation needed if not case sensitive
        string currentWord = CASE_SENSITIVE ? DICT.at(i) : strToLower(DICT.at(i));
        if (currentWord == searchWord) {
            foundPos = i;
            break;
        }
    }
    return foundPos;
}

vector<string>::iterator
linearSearch(const vector<string>::iterator &START, const vector<string>::iterator &END,
             string searchWord) {

    if (!CASE_SENSITIVE) searchWord = strToLower(searchWord); // searchWord transformation needed if not case sensitive

    for (vector<string>::iterator i = START; i < END; ++i) {
        string currentWord = CASE_SENSITIVE ? *i : strToLower(*i);
        if (currentWord == searchWord) return i;
    }
    return END;
}

size_t dichotomySearch(const vector<string> &DICT, string searchWord) {

    // searchWord transformation needed if not case sensitive
    if (!CASE_SENSITIVE) searchWord = strToLower(searchWord);

    size_t start = 0;
    size_t middle;
    size_t end = DICT.size();

    while (start < end) {
        middle = start + (end - start) / 2;
        // get the current word
        string currentWord = CASE_SENSITIVE ? DICT.at(middle) : strToLower(DICT.at(middle));

        // did we find the word?
        if (searchWord == currentWord) return middle;
        // no, check in which half it is
        if (searchWord > currentWord) {
            start = middle + 1;
        } else {
            end = middle;
        }
    }

    // the word wasn't found
    return string::npos;
}

vector<string>::iterator binarySearch(vector<string>::iterator startIt, vector<string>::iterator endIt, string searchWord) {
    if(!CASE_SENSITIVE) searchWord = strToLower(searchWord); // searchWord transformation needed if not case sensitive

    bool found = false;
    vector<string>::iterator foundIt = endIt;
    long gap = distance(startIt, endIt);

    while(!found && gap >= 1) {
        vector<string>::iterator middleIt = startIt + (gap / 2);

        string currentWord = CASE_SENSITIVE ? *middleIt : strToLower(*middleIt);
        if(currentWord == searchWord) {
            found = true;
            foundIt = middleIt;
        } else {
            if(searchWord < currentWord) {
                endIt = middleIt; // No - 1 because the end iterator is after the last element
            } else {
                startIt = ++middleIt;
            }
        }

        // Calcul the new gap
        gap = distance(startIt, endIt);
    }

    return foundIt;
}

bool recursiveBinarySearch(vector<string>::iterator startIt, vector<string>::iterator endIt, string searchWord) {
    if(!CASE_SENSITIVE) searchWord = strToLower(searchWord); // searchWord transformation needed if not case sensitive

    long gap = distance(startIt, endIt);
    if(gap == 0){
        return false;
    }

    vector<string>::iterator middleIt = startIt + (gap / 2);
    string currentWord = CASE_SENSITIVE ? *middleIt : strToLower(*middleIt);
    if(currentWord == searchWord){
        return true;
    } else {
        if(searchWord < currentWord) {
            endIt = middleIt;
        } else {
            startIt = ++middleIt;
        }
    }

    return recursiveBinarySearch(startIt, endIt, searchWord);
}



string strToLower(string word) {
    string wordLower;
    for (size_t i = 0; i <= word.length() - 1; ++i) {
        wordLower += (char) tolower(word.at(i));
    }
    return wordLower;
}
