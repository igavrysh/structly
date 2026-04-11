//
//  longest_two_chars_substring.cpp
//  MyCLI
//
//  Created by new on 4/11/26.
//

#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestTwoCharSubstring(std::string s) {
    unordered_map<char, int> map{};
    int res = -1;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
        char ch = s[r];
        while (map.size()>2 && l<=r) {
            char ch_r = s[l++];
            map[ch_r]--;
            if (map[ch_r] == 0) {
                map.erase(ch_r);
            }
        }

        map[ch]++;
        res = max(res, r-l+1);
    }
    return res;
}
