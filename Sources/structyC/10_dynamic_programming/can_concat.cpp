#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool can_concat(int i, string& str, unordered_set<string>& set, vector<int>& dp) {
    if (i < 0) {
        return true;
    }
    if (dp[i] != -1) {
        return dp[i];
    }

    for (int j = i; j >= 0; j--) {
        string w = str.substr(j, i-j+1);
        if (set.count(w) > 0 && (j-1 == -1 || dp[j-1])) {
            bool res = can_concat(j-1, str, set, dp);
            if (res) {
                dp[i] = res;
                return true;
            }
        }
    }
    dp[i] = false;
    return false;
}

bool canConcat(string str, vector<string> words)
{
    unordered_set<string> set{};
    for (string w : words) {
        set.insert(w);
    }

    vector<int> dp(str.size(), -1);

    return can_concat(str.size()-1, str, set, dp);
}
