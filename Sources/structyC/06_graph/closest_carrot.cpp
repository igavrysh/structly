//
//  closest_carrot.cpp
//  MyCLI
//
//  Created by new on 4/5/26.
//

#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int closestCarrot(std::vector<std::vector<char>> grid, int startRow, int startCol) {
    const int rows = (int)grid.size();
    const int cols = (int)grid[0].size();
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    if (grid[startRow][startCol] == 'X') {
        return -1;
    }
    queue<pair<pair<int, int>, int>> q{};
    unordered_set<string> visited{};
    q.push({{startRow, startCol}, 0});
    visited.insert(to_string(startRow) + ";" + to_string(startCol));
    while (q.size() != 0) {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int i = p.first.first;
        int j = p.first.second;
        int h = p.second;
        if (grid[i][j] == 'C') {
            return h;
        }
        for (vector<int> dir : dirs) {
            int next_i = i + dir[0];
            int next_j = j + dir[1];
            if (next_i < 0 || next_j < 0 || next_i >= rows || next_j >= cols || grid[next_i][next_j] == 'X' || visited.count(to_string(next_i) + ";" + to_string(next_j)) > 0) {
                continue;
            }
            visited.insert(to_string(next_i) + ";" + to_string(next_j));
            q.push({{next_i, next_j}, h+1});
        }
    }
    return -1;
}
