//
//  island_count.cpp
//  MyCLI
//
//  Created by new on 3/31/26.
//

#include <vector>
#include <queue>
#include <tuple>

void bfs(int start_i, int start_j, char id, std::vector<std::vector<char>>& grid) {
    std::vector<std::vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    auto rows = grid.size();
    auto cols = grid[0].size();
    grid[start_i][start_j] = id;
    std::queue<std::tuple<int, int>> q{};
    q.push({start_i, start_j});
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (std::vector<int> d : dirs) {
            auto next_i = i + d[0];
            auto next_j = j + d[1];
            if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols) {
                continue;
            }
            if (grid[next_i][next_j] != 'L') {
                continue;
            }
            grid[next_i][next_j] = id;
            q.push({next_i, next_j});
        }
    }
}

int islandCount(std::vector<std::vector<char>> grid) {
    auto rows = grid.size();
    auto cols = grid[0].size();
    char id = '0';
    int counter = 0;
    for (auto i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'L') {
                id = id + 1;
                bfs(i, j, id, grid);
                counter++;
            }
        }
    }
    return counter;
}

