//
// Created by new on 5/3/26.
//

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace graph_17_2_knight_attack {
int knightAttack(int n, int kr, int kc, int pr, int pc) {
    vector<vector<int>> offsets = {{-2,-1},{-2, 1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<vector<int>> q{};
    q.push({kr, kc});
    visited[kr][kc] = true;
    int counter = 0;
    while (!q.empty()) {
        int lev = q.size();
        counter++;
        for (int i = 0; i < lev; i++) {
            vector<int> curr = q.front();
            q.pop();
            if (curr[0] == pr && curr[1] == pc) {
                return counter-1;
            }
            for (vector<int> off : offsets) {
                int next_row = curr[0] + off[0];
                int next_col = curr[1] + off[1];
                if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= n) {
                    continue;
                }
                if (visited[next_row][next_col]) { continue; }
                visited[next_row][next_col] = true;
                q.push({next_row, next_col});
            }
        }
    }
    return -1;
}

void test_00() {
    int res = knightAttack(8, 1, 1, 2, 2);
    bool passed = res == 2;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
}
