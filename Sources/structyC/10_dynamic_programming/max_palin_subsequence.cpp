#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int p_length(int l, int r, string s, vector<vector<int>>& cache) {
    if (l >= r) {
        return r-l+1;
    }
    if (cache[l][r] != 0) {
        return cache[l][r];
    }
    if (s[l] == s[r]) {
        int res = p_length(l+1, r-1, s, cache) + 2;
        cache[l][r] = res;
        return res;
    }

    int res = max(p_length(l+1, r, s, cache), p_length(l, r-1, s, cache));
    
    cache[l][r] = res;

    return res;
}

int maxPalinSubsequence(string s) {
    int len = s.length();
    vector<vector<int>> cache(len, vector<int>(len, 0));
    return p_length(0, len-1, s, cache);
}

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
