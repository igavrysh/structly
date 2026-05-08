//
// Created by new on 5/7/26.
//

#include <unordered_map>
#include <string>
using namespace std;

string tokenTransform(string s, unordered_map<string, string> tokens) {
    string output;
    int i = 0;
    int j = 1;
    while (i < s.length()) {
        if (s[i] != '$') {
            output += s[i];
            i += 1;
            j = i + 1;
        } else if (s[j] != '$') {
            j += 1;
        } else {
            string key = s.substr(i, j-i+1);
            if (tokens.count(key) == 0) {
                return "";
            }
            s.replace(i, j-i+1, tokens[key]);
            j = i + 1;
        }
    }

    return output;
}