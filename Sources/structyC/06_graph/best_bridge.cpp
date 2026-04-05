//
//  best_bridge.cpp
//  MyCLI
//
//  Created by new on 4/5/26.
//

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

bool is_inbound(vector<vector<char>>& grid, int i, int j) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

void explore_island(vector<vector<char>>& grid, int start_i, int start_j,
    vector<vector<bool>>& visited, queue<pair<pair<int,int>,int>>& land_pos) {
    queue<pair<int, int>> q;
    visited[start_i][start_j] = true;
    q.push({start_i, start_j});
    while (q.size() > 0) {
        auto p = q.front();
        q.pop();
        land_pos.push({p, 0});
        int i = p.first;
        int j = p.second;
        for (auto dir : dirs) {
            int next_i = i + dir[0];
            int next_j = j + dir[1];
            if (!is_inbound(grid, next_i, next_j) || visited[next_i][next_j] || grid[next_i][next_j] != 'L') {
                continue;
            }
            visited[next_i][next_j] = true;
            q.push({next_i, next_j});
        }
    }
}

int bestBridge(std::vector<std::vector<char>> grid) {
    const int rows = (int)grid.size();
    const int cols = (int)grid[0].size();
    queue<pair<pair<int,int>,int>> next_q{};
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'L') {
                explore_island(grid, i, j, visited, next_q);
                i = rows;
                break;
            }
        }
    }
    while (!next_q.empty()) {
        pair<pair<int,int>,int> p = next_q.front();
        next_q.pop();
        int i = p.first.first;
        int j = p.first.second;
        int l = p.second;
        if (grid[i][j] == 'L' && l != 0) {
            return l-1;
        }
        for (vector<int> dir : dirs) {
            int next_i = i + dir[0];
            int next_j = j + dir[1];
            if (!is_inbound(grid, next_i, next_j) || visited[next_i][next_j]) {
                continue;
            }
            visited[next_i][next_j] = true;
            next_q.push({{next_i, next_j}, l+1});
        }
    }
    return -1;
}

//
//int main(int argc, char *argv[]) {
//    cout << "running...";
//    std::vector<std::vector<char>> grid {
//          {'W', 'W', 'W', 'L', 'L'},
//          {'L', 'L', 'W', 'W', 'L'},
//          {'L', 'L', 'L', 'W', 'L'},
//          {'W', 'L', 'W', 'W', 'W'},
//          {'W', 'W', 'W', 'W', 'W'},
//          {'W', 'W', 'W', 'W', 'W'}
//    };
//    int res = bestBridge(grid); // -> 1
//    cout << "res:" << res << endl;
//}
