//
// Created by new on 4/11/26.
//
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
int longestUniqueSubstring(std::string s) {
    unordered_set<char> set{};
    int res = 0;
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
        char ch = s[r];
        while (set.count(ch) > 0 && l <= r) {
            set.erase(s[l++]);
        }
        set.insert(s[r]);
        res = max(res, r - l + 1);
    }

    return res;
}