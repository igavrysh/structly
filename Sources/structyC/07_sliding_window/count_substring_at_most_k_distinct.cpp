//
// Created by new on 4/11/26.
//

#include <string>
#include <unordered_map>
using namespace std;

int countSubstringAtMostKDistinct(string s, int k) {
    unordered_map<char, int> m{};
    int l = 0;
    int res = 0;
    for (int r = 0; r < s.length(); r++) {
        char ch_r = s[r];
        if (m.count(ch_r) == 0) {
            m[ch_r] = 0;
        }
        m[ch_r]++;

        while (m.size() > k && l <= r) {
            char ch_l = s[l++];
            m[ch_l]--;
            if (m[ch_l] == 0) {
                m.erase(ch_l);
            }
        }

        res += (r - l + 1);
    }

    return res;
}