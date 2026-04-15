//
// Created by new on 4/14/26.
//

#include <vector>
#include <algorithm>
using namespace std;

int maxPathSum(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] += max(i-1 >= 0 ? grid[i-1][j] : 0, j-1>=0 ? grid[i][j-1] : 0);
        }
    }
    return grid[rows-1][cols-1];
}