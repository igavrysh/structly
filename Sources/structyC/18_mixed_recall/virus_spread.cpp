//
// Created by new on 5/7/26.
//

#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

int virusSpread(vector<vector<int>> grid) {
    queue<tuple<int, int, int>> q{};
    int rows = grid.size();
    int cols = grid[0].size();
    int count_healthy = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0});
            } else if (grid[i][j] == 1) {
                count_healthy++;
            }
        }
    }
    vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    int max_t = 0;
    while (!q.empty()) {
        tuple<int,int,int> p = q.front();
        q.pop();
        int i = get<0>(p), j = get<1>(p), t = get<2>(p);
        max_t = max(max_t, t);
        for (vector<int>& dir : dirs) {
            int next_i = i + dir[0], next_j = j + dir[1];
            if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols) {
                continue;
            }
            if (grid[next_i][next_j] != 1) {
                continue;
            }
            grid[next_i][next_j] = 2;
            count_healthy--;
            q.push({next_i, next_j, t + 1});
        }
    }
    return count_healthy == 0 ? max_t : -1;
}

void test_00() {
    vector<vector<int>> grid {
      {1,1,1},
      {0,1,0},
      {0,1,2}
    };
    int res = virusSpread(grid); // -> 4
    bool passed = res == 4;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
