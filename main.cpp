/**
 * Entête : TODO
 */

#include "read.h"
#include "search.h"
#include <iostream>

using namespace std;

// TODO : I'm a debug function dude ! Don't forgot to remove me later (=
void displayDict(const vector<string> &dict) {
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        cout << *it << endl;
    }
}

int main() {

    vector<string> dict = readFile("otan");

    auto foo = linearSearch(dict.begin(), dict.end(), "Papa");
    cout << *foo;

    return 0;
}