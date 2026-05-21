//
// Created by new on 5/6/26.
//

#include <vector>
#include <iostream>
using namespace std;

namespace mixed_recall_18_knightly_number {
static vector<vector<int>> dirs = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};

int knightly_number(int n, int m, int kr, int kc, int pr, int pc, vector<vector<vector<int>>>& combs) {
    if (m < 0) {
        return 0;
    }
    if (combs[kr][kc][m] != -1) {
        return combs[kr][kc][m];
    }
    if (kr == pr && kc == pc && m == 0) {
        return 1;
    }

    int res = 0;
    for (vector<int> dir : dirs) {
        int next_kr = kr + dir[0];
        int next_kc = kc + dir[1];
        if (next_kr < 0 || next_kc < 0 || next_kr >= n || next_kc >= n) {
            continue;
        }

        res += knightly_number(n, m-1, next_kr, next_kc, pr, pc, combs);
    }

    combs[kr][kc][m] = res;

    return res;
}

int knightlyNumber(int n, int m, int kr, int kc, int pr, int pc) {
    vector<vector<vector<int>>> combs(n, vector<vector<int>>(n, vector<int>(m+1, -1)));
    int res =  knightly_number(n, m, kr, kc, pr, pc, combs);
    // for (int k = 0; k < m; k++) {
    //     cout << "k=" << k << endl;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             cout << combs[i][j][k] << ", ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    return res;
}

void test_00() {
    int res = knightlyNumber(8, 2, 4, 4, 5, 5); // -> 2
    bool passed = res == 2;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
}
