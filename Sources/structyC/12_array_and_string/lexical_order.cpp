//
// Created by new on 4/27/26.
//

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool lexicalOrder(string word1, string word2, string alphabet) {
    unordered_map<char, int> m{};
    for (int i = 0; i < alphabet.length(); i++) {
        m[alphabet[i]] = i;
    }

    for (int i = 0; i < min(word1.length(), word2.length()); i++) {
        int o1 = m[word1[i]];
        int o2 = m[word2[i]];
        if (o1 < o2) {
            return true;
        }

        if (o1 > o2) {
            return false;
        }
    }

    if (word1.size() <= word2.size()) {
        return true;
    }

    return false;
}

void test_03() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    bool res = lexicalOrder("backs", "backdoor", alphabet); // -> 0 (false)
    bool passed = res == false;
    cout << "test_03: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_03();
}


