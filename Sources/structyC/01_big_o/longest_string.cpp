//
//  longestString.hpp
//  MyCLI
//
//  Created by new on 3/6/26.
//

#include <string>
#include <limits>
#include <sstream>
using namespace std;

string longestWord(string sentence) {
    stringstream ss(sentence);
    int max_len = -1;
    string res = "";
    string word;
    while (ss >> word) {
        if (word.length() >= res.length()) {
            res = word;
        }
    }

    return res;
}
