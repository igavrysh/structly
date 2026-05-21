//
// Created by new on 5/7/26.
//

#include <vector>
#include <iostream>
using namespace std;

namespace mixed_recall_18_breaking_boundaries {
int breakingBoundaries(int m, int n, int k, int r, int c) {
    vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, 0)));
    dp[0][r][c] = 1;
    vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    int res = 0;
    for (int l = 0; l < k; l++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (vector<int> dir : dirs) {
                    int next_i = i + dir[0];
                    int next_j = j + dir[1];
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) {
                        continue;
                    }
                    
                    dp[l][i][j] += (l-1>=0 ? dp[l-1][next_i][next_j] : 0);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            res += dp[l][i][0];
            res += dp[l][i][n-1];
        }
        for (int j = 0; j < n; j++) {
            res += dp[l][0][j];
            res += dp[l][m-1][j];
        }
    }
    
    return res;
}

void test_00() {
    int res = breakingBoundaries(3, 4, 2, 0, 0); // -> 4
    bool passed = res == 4;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    int res = breakingBoundaries(2, 2, 2, 1, 1); // -> 6
    bool passed = res == 6;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

void test_02() {
    int res = breakingBoundaries(3, 4, 3, 0, 0); // -> 11
    bool passed = res == 11;
    cout << "test_02: " << (passed ? "passed" : "failed") << endl;
}

void test_03() {
    int res = breakingBoundaries(4, 4, 5, 2, 1); // -> 160
    bool passed = res == 160;
    cout << "test_03: " << (passed ? "passed" : "failed") << endl;
}

void test_04() {
    int res = breakingBoundaries(5, 6, 9, 2, 5); // -> 11635
    bool passed = res == 11635;
    cout << "test_04: " << (passed ? "passed" : "failed") << endl;
}

void test_05() {
    int res = breakingBoundaries(6, 6, 12, 3, 4); // -> 871065
    bool passed = res == 871065;
    cout << "test_05: " << (passed ? "passed" : "failed") << endl;
}

void test_06() {
    int res = breakingBoundaries(6, 6, 15, 3, 4); // -> 40787896
    bool passed = res == 40787896;
    cout << "test_06: " << (passed ? "passed" : "failed") << endl;
}

void test_07() {
    int res = breakingBoundaries(6, 8, 16, 2, 1); // -> 137495089
    bool passed = res == 137495089;
    cout << "test_07: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();
}
}
