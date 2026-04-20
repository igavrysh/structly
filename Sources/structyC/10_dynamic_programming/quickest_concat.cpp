#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

bool match_word(const int st, const string& s, const string& word) {
    if (st + word.length() > s.length()) {
        return false;
    }
    for (int i = 0; i < word.length(); i++) {
        if (s[st+i] != word[i]) {
            return false;
        }
    }
    return true;
}

void match(int st, string& str, vector<string>& words, vector<int>& memo) {
    for (string& word : words) {
        const int possible_steps = 1 + (st-1 >= 0 ? memo[st-1] : 0);
        if (st + word.length() < memo.size() && memo[st + word.length()] != -1 && memo[st + word.length()-1] <= possible_steps) {
            continue;
        }

        if (match_word(st, str, word)) {
            int eow_idx = st + word.length()-1;
            if (memo[eow_idx] == -1) {
                memo[eow_idx] = 1 + (st-1>=0 ? memo[st-1] : 0);
            }
            memo[eow_idx] = min(memo[eow_idx], 1 + (st-1>=0 ? memo[st-1] : 0));
            if (eow_idx+1 < memo.size()) {
                match(eow_idx+1, str, words, memo);
            }
        }
    }
}

int quickestConcat_1(string str, vector<string> words) {
    int str_len = str.size();
    vector<int> memo(str_len, -1);
    match(0, str, words, memo);
    return memo[str_len-1];
}


int quickest_concat(int i, int str_sz, string& str, vector<string>& words, unordered_map<int, int>& memo) {
    if ((int)str.size() == 0) {
        return 0;
    }

    if (memo.count(i) > 0) {
        return memo[i];
    }

    int quickest = -1;
    for (string& w : words) {
        if (i + w.size() > str_sz) {
            continue;
        }

        if (i + w.length() <= str_sz && quickest != -1) {
            int possible_new_quickest = -1;

            if (i + w.length() == str_sz) {
                possible_new_quickest = 1;
            } else if (i + w.length() < str_sz && memo[i + w.length()] != -1 && memo[i + w.length()] != -2) {
                possible_new_quickest = 1 + memo[i+w.length()];
            }

            if (possible_new_quickest != -1 && quickest <= possible_new_quickest) {
                continue;
            }
        }

        if (str.find(w) != 0) {
            continue;
        }

        string suffix = str.substr(w.size());
        int quickest_sub = quickest_concat(i + (int)w.length(), str_sz, suffix, words, memo);
        if (quickest_sub != -1) {
            if (quickest == -1) {
                quickest = 1 + quickest_sub;
            }
            quickest = min(quickest, 1 + quickest_sub);
        }
    }

    memo[i] = quickest;

    return memo[i];
}

int quickestConcat(string str, vector<string> words) {
    const int str_sz = (int)str.size();
    unordered_map<int, int> memo{};
    quickest_concat(0, str_sz, str, words, memo);
    return memo[0];
}

void test_00() {
    const int res = quickestConcat("caution", vector<string>{"ca", "ion", "caut", "ut"}); // -> 2
    const bool passed = res == 2;
    cout << "test_00: " << (passed ? "PASSED" : "FAILED") << endl;
}

int main(int argc, char *argv[]) {
    test_00();
}
