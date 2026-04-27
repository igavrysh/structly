//
// Created by new on 4/27/26.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool lexical_order(string& w1, string& w2, unordered_map<char, int>& m) {

    for (int i = 0; i < min(w1.length(), w2.length()); i++) {
        int o1 = m[w1[i]];
        int o2 = m[w2[i]];
        if (o1 < o2) {
            return true;
        }
        if (o1 > o2) {
            return false;
        }
    }

    return w1.size() <= w2.size();
}

bool detectDictionary(vector<string> dictionary, string alphabet) {
    unordered_map<char, int> m{};
    for (int i = 0; i < alphabet.length(); i++) {
        m[alphabet[i]] = i;
    }
    for (int i = 0; i < dictionary.size()-1; i++) {
        if (!lexical_order(dictionary[i], dictionary[i+1], m)) {
            return false;
        }
    }

    return true;
}

