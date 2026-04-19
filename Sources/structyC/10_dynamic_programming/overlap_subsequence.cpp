#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int overlap_subseq(int p1, int p2, string& s1, string& s2, vector<vector<int>>& cache) {
    if (p1 < 0 || p2 < 0) {
        return 0;
    }

    if (cache[p1][p2] != -1) {
        return cache[p1][p2];
    }

    if (s1[p1] == s2[p2]) {
        int res = 1 + overlap_subseq(p1-1, p2-1, s1, s2, cache);
        cache[p1][p2] = res;
        return res;
    }

    int res = max(overlap_subseq(p1-1, p2, s1, s2, cache), overlap_subseq(p1, p2-1, s1, s2, cache));
    cache[p1][p2] = res;
    return res;
}

int overlapSubsequence(string s1, string s2) {
    vector<vector<int>> cache(s1.size(), vector<int>(s2.size(), -1));
    return overlap_subseq(s1.size()-1, s2.size()-1, s1, s2, cache);
}

void test_03() {
    int res = overlapSubsequence("kinfolklivemustache", "bespokekinfolksnackwave");  // -> 11
    bool passed = res == 11;
    cout << "test_01: " << (passed ? "paseed" : "failed") << endl;
}

int main(int argc, char const *argv[]) {
    test_03();
    return 0;
}

