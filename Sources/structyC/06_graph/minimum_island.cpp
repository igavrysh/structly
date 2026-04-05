//
//  minimum_island.cpp
//  MyCLI
//
//  Created by new on 4/1/26.
//

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

int explore_dfs(vector<vector<char>>& grid, unordered_set<int>& visited, int i, int j) {
    vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());
    const int idx = i * cols + j;
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != 'L' || visited.count(idx) > 0) {
        return -1;
    }
    visited.insert(idx);
    int counter = 1;
    for (int d = 0; d < dirs.size(); d++) {
        int res = explore_dfs(grid, visited, i + dirs[d][0], j + dirs[d][1]);
        if (res != -1) {
            counter += res;
        }
    }
    return counter;
}

int minimumIsland_dfs(vector<vector<char>> grid) {
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());
    int not_found = rows * cols + 1;
    int min_island = not_found;
    unordered_set<int> visited{};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int res = explore_dfs(grid, visited, i, j);
            if (res != -1) {
                min_island = min(min_island, res);
            }
        }
    }
    return min_island == not_found ? -1 : min_island;
}


// or just use map - that does not require hasher, but only < that is defined on pair (khm for (0,1) < (1,0) based on
// lexi order
struct pair_hash {
    inline size_t operator()(const std::pair<int, int> &v) const {
        return std::hash<int>()(v.first) ^ std::hash<int>()(v.second);
    }
};

int explore_bfs(vector<vector<char>>& grid, unordered_set<pair<int, int>, pair_hash>& visited, int st_i, int st_j) {
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());
    if (st_i < 0 || st_j < 0 || st_i >= rows || st_j >= cols || grid[st_i][st_j] != 'L'
        || visited.count({st_i, st_j}) > 0) {
        return -1;
    }
    const vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    int res = 0;
    queue<pair<int, int>> q{};
    q.push({st_i, st_j});
    visited.insert({st_i, st_j});
    while (q.size() > 0) {
        pair<int, int> p = q.front();
        q.pop();
        res += 1;
        const int i = p.first;
        const int j = p.second;
        for (vector<int> delts : dirs) {
            const int next_i = i + delts[0];
            const int next_j = j + delts[1];
            pair<int, int>  next_p{next_i, next_j};
            if (next_i < 0 || next_j < 0 || next_i >= rows || next_j >= cols || grid[next_i][next_j] != 'L'
                || visited.count(next_p) > 0) {
                continue;
            }
            visited.insert(next_p);
            q.push(next_p);
        }
    }
    return res;
}

int minimumIsland_bfs(vector<vector<char>> grid) {
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());
    int not_found = rows * cols + 1;
    int min_island = not_found;
    unordered_set<pair<int, int>, pair_hash> visited{};
    queue<pair<int, int>> q{};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int res = explore_bfs(grid, visited, i, j);
            if (res != -1) {
                min_island = min(min_island, res);
            }
        }
    }
    return min_island == not_found ? -1 : min_island;
}
