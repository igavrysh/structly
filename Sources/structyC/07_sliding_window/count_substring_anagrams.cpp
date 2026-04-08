//
//  count_substring_anagrams.cpp
//  MyCLI
//
//  Created by new on 4/7/26.
//

#include <string>
#include <unordered_map>
using namespace std;

int countSubstringAnagrams(std::string s, std::string anagram) {
    unordered_map<char, int> fqs{};
    int size = 0;
    int non_zero_fqs = 0;
    for (int i = 0; i < anagram.length(); i++) {
        char ch = anagram[i];
        if (fqs.count(ch) == 0) {
            fqs[ch] = 0;
        }
        if (fqs[ch] == 0) {
            non_zero_fqs++;
        }
        fqs[ch]--;
        size--;
    }

    for (int i = 0; i < anagram.length(); i++) {
        char ch = s[i];
        if (fqs.count(ch) == 0) {
            fqs[ch] = 0;
            non_zero_fqs++;

        }

        fqs[ch]++;
        if (fqs[ch] == 0) {
            non_zero_fqs--;
        }
    }
    int count = 0;
    if (non_zero_fqs == 0) {
        count  = 1;
    }

    for (int i = (int)anagram.length(); i < s.length(); i++) {
        char ch = s[i];
        if (fqs.count(ch) == 0) {
            fqs[ch] = 0;
            non_zero_fqs++;
        }

        fqs[ch]++;
        if (fqs[ch] == 0) {
            non_zero_fqs--;
        }

        char ch_to_remove = s[i-anagram.length()];
        fqs[ch]--;
        if (fqs[ch] == 0) {
            non_zero_fqs--;
        }

        if (non_zero_fqs == 0) {
            count++;
        }
    }

    return count;
}
