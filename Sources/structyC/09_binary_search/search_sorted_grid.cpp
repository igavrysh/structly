//
// Created by new on 4/13/26.
//

#include <vector>
using namespace std;

bool searchSortedGrid(vector<vector<int>> grid, int target) {
    const int rows = grid.size();
    const int cols = grid[0].size();

    int lo = 0;
    int hi = rows - 1;
    int found_row = -1;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (grid[m][0] <= target && target <= grid[m][cols - 1]) {
            found_row = m;
            break;
        }

        if (grid[m][cols - 1] < target) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }

    if (found_row == -1) {
        return false;
    }

    lo = 0;
    hi = cols - 1;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (grid[found_row][m] == target) {
            return true;
        }

        if (grid[found_row][m] < target) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }

    return false;
}