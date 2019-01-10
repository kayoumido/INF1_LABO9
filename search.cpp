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
