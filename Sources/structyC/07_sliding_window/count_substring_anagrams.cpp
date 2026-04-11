//
//  count_substring_anagrams.cpp
//  MyCLI
//
//  Created by new on 4/7/26.
//

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int countSubstringAnagrams(std::string s, std::string anagram) {
    unordered_map<char, int> anagram_fq;
    for (int i = 0; i < anagram.length(); i++) {
        char ch = anagram[i];
        if (anagram_fq.find(ch) == anagram_fq.end()) {
            anagram_fq[ch] = 0;
        }
        anagram_fq[ch]++;
    }

    int curr_matching = 0;
    unordered_map<char, int> curr_fq;
    for (int i = 0; i < anagram.size(); i++) {
        char ch = s[i];
        if (curr_fq.find(ch) == curr_fq.end()) {
            curr_fq[ch] = 0;
        }
        curr_fq[ch]++;
        if (curr_fq[ch] > 0 && anagram_fq[ch] > 0 && curr_fq[ch] <= anagram_fq[ch]) {
            curr_matching++;
        }
    }

    int res = 0;
    if (curr_matching == anagram.length()) {
        res++;
    }

    for (int i = (int)anagram.size(); i < s.length(); i++) {
        char ch = s[i];
        if (curr_fq.find(ch) == curr_fq.end()) {
            curr_fq[ch] = 0;
        }
        curr_fq[ch]++;

        if (curr_fq[ch] > 0 && anagram_fq[ch] > 0 && curr_fq[ch] <= anagram_fq[ch]) {
            curr_matching++;
        }

        char r_ch = s[i-anagram.size()];

        if (anagram_fq[r_ch] > 0 && curr_fq[r_ch] <= anagram_fq[r_ch]) {
            curr_matching--;
        }

        curr_fq[r_ch]--;

        if (curr_matching == anagram.length()) {
            res++;
        }
    }

    return res;
}

void test_00() {
    int res = countSubstringAnagrams("tacoctacabcatt", "cat"); ;
    bool passed = res == 4;
    cout << "test_00: " << passed << "; res: "<< res << endl;
}

int main(int argc, char *argv[]) {
    test_00();
}
