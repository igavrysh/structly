//
// Created by new on 4/14/26.
//

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int count_paths_helper(int i, int j, vector<vector<char>>& grid, unordered_map<string, int>& memo) {
    string id = to_string(i) + ',' + to_string(j);
    if (memo.count(id) > 0) {
        return memo[id];
    }

    if (i == 0 && j == 0) {
        memo[id] = 1;
        return memo[id];
    }

    if (grid[i][j] == 'X') {
        memo[id] = 0;
        return memo[id];
    }

    int from_up = i-1 >= 0 ? count_paths_helper(i-1, j, grid, memo) : 0;
    int from_left = j-1 >= 0 ? count_paths_helper(i, j-1, grid, memo) : 0;
    memo[id] = from_up + from_left;

    return memo[id];
}

int countPaths(vector<vector<char>> grid) {
    unordered_map<string, int> memo{};
    int rows = grid.size();
    int cols = grid[0].size();
    return count_paths_helper(rows-1, cols-1, grid, memo);
}

int countPaths_mine(vector<vector<char>> grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<int> dp(cols, 0);
    vector<int> dp_prev(cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0 && grid[i][j] == 'O') {
                dp[j] = 1;
                continue;
            }
            if (grid[i][j] == 'O') {
                dp[j] = (j-1 >= 0 ? dp[j-1] : 0) + dp_prev[j];
            } else {
                dp[j] = 0;
            }
        }
        vector<int> tmp = dp;
        dp = dp_prev;
        dp_prev = tmp;
    }

    return dp_prev[cols-1];
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<char>> grid {
        {'O', 'O'},
        {'O', 'O'}
    };
    countPaths(grid);
}

