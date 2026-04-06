//
//  has_substring_anagram.cpp
//  MyCLI
//
//  Created by new on 4/6/26.
//

#include <string>
#include <unordered_map>
using namespace std;

bool hasSubstringAnagram(std::string s, std::string anagram) {
    unordered_map<char, int> anagram_fq;
    int non_zero_fqs = 0;
    for (int i = 0; i < anagram.length(); i++) {
        char ch = anagram[i];
        if (anagram_fq.find(ch) == anagram_fq.end()) {
            anagram_fq[ch] = 0;
            non_zero_fqs++;
        }
        anagram_fq[ch]++;
    }
    for (int i = 0; i < anagram.size(); i++) {
        char ch = s[i];
        if (anagram_fq.find(ch) == anagram_fq.end()) {
            anagram_fq[ch] = 0;
            non_zero_fqs++;
        }
        anagram_fq[ch] -= 1;
        if (anagram_fq[ch] == 0) { non_zero_fqs--; }
    }
    if (non_zero_fqs == 0) {
        return true;
    }

    for (int i = (int)anagram.size(); i < s.length(); i++) {
        char ch = s[i];
        if (anagram_fq.find(ch) == anagram_fq.end()) {
            anagram_fq[ch] = 0;
            non_zero_fqs++;
        }

        anagram_fq[ch] -= 1;
        if (anagram_fq[ch] == 0) { non_zero_fqs--; }

        char remove_ch = s[i-anagram.size()];
        anagram_fq[remove_ch] += 1;
        if (anagram_fq[remove_ch] == 0) {
            non_zero_fqs--;
        }

        if (non_zero_fqs == 0) {
            return true;
        }
    }
    return false;
}

