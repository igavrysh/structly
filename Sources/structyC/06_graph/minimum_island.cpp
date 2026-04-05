//
//  minimum_island.cpp
//  MyCLI
//
//  Created by new on 4/1/26.
//

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int explore_dfs(vector<vector<char>>& grid, unordered_set<int>& visited, int i, int j) {
    vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());

    int counter = 1;
    for (int d=0; d < dirs.size(); d++) {
        const auto next_i = i + dirs[d][0];
        const auto next_j = j + dirs[d][1];
        if (next_i < 0 || next_j < 0 || next_i >= rows || next_j >= cols) {
            continue;
        }
        if (grid[next_i][next_j] != 'L') {
            continue;
        }
        auto idx = next_i * cols + next_j;
        if (visited.count(idx) > 0) {
            continue;
        }

        visited.insert(idx);
        counter += explore_dfs(grid, visited, next_i, next_j);
    }

    return counter;
}

int minimumIsland(vector<vector<char>> grid) {
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());
    int min_island = rows * cols + 1;
    unordered_set<int> visited{};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int idx = i * cols + j;
            if (grid[i][j] == 'L' && visited.count(idx) == 0) {
                visited.insert(idx);
                min_island = min(min_island, explore_dfs(grid, visited, i, j));
            }
        }
    }
    return min_island == rows * cols + 1 ? -1 : min_island;
}
