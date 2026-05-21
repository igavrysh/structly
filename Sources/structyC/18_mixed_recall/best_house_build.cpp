//
// Created by new on 5/7/26.
//

#include <vector>
#include <unordered_set>

#include <queue>
#include <iostream>
using namespace std;

namespace mixed_recall_18_best_house_build {
int bestHouseBuild(vector<vector<int>> grid)
{
    int rows = grid.size();
    if (rows == 0) {
        return -1;
    }
    int cols = grid[0].size();
    if (cols == 0) {
        return -1;
    }
    queue<tuple<int,int,int,int>> q{};
    vector<vector<unordered_set<int>>> visited(rows, vector<unordered_set<int>>(cols, unordered_set<int>{}));
    int curr_id = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                q.push({i,j,curr_id, 0});
                visited[i][j].insert(curr_id);
                curr_id++;
            }
        }
    }
    int counter = curr_id;
    vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> total_time(rows, vector<int>(cols, 0));
    int min_distance = -1;
    while (!q.empty()) {
        tuple<int,int,int,int> tpl = q.front();
        q.pop();
        int i = get<0>(tpl), j = get<1>(tpl), id = get<2>(tpl), t = get<3>(tpl);
        for (vector<int> dir : dirs) {
            int next_i = i + dir[0];
            int next_j = j + dir[1];
            if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols) {
                continue;
            }
            if (grid[next_i][next_j] != 0) {
                continue;
            }
            if (visited[next_i][next_j].count(id) > 0) {
                continue;
            }

            total_time[next_i][next_j] += (t+1);

            visited[next_i][next_j].insert(id);
            q.push({next_i, next_j, id, t+1});
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != 0) {
                continue;
            }
            if (visited[i][j].size() != counter) {
                continue;
            }
            if (min_distance == -1) {
                min_distance = total_time[i][j];
            }
            min_distance = min(min_distance, total_time[i][j]);
        }
    }

    return min_distance;
}

void test_00() {
    vector<vector<int>> grid {
      {1,0,0,0,1},
      {0,0,0,0,0},
      {0,0,1,0,0}
    };
    int res = bestHouseBuild(grid); // -> 6
    bool passed = res == 6;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_06() {
    vector<std::vector<int>> grid {
      {1,0},
    };
    int res = bestHouseBuild(grid); // -> 1
    bool passed = res == 1;
    cout << "test_06: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_06();
}
}
