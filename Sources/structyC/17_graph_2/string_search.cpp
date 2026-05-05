//
// Created by new on 5/5/26.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};

bool scan(int i, int j, int k, vector<vector<char>>& grid, string& target, vector<vector<bool>>& visited) {
    if (k == target.size()) {
        return true;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        return false;
    }
    if (grid[i][j] != target[k]) {
        return false;
    }
    visited[i][j] = true;
    for (vector<int> dir : dirs) {
        if (scan(i + dir[0], j + dir[1], k +1, grid, target, visited)) {
            return true;
        }
    }
    visited[i][j] = false;
    return false;
}

bool stringSearch(vector<vector<char>> grid, string target) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == target[0]) {
                if (scan(i, j, 0, grid, target, visited)) {
                    return true;
                }
            }
        }
    }

    return false;
}

void test_00() {
    vector<std::vector<char>> grid {
      {'e', 'y', 'h', 'i', 'j'},
      {'q', 'x', 'e', 'r', 'p'},
      {'r', 'o', 'l', 'l', 'n'},
      {'p', 'r', 'x', 'o', 'h'},
      {'a', 'a', 'm', 'c', 'm'}
    };
    bool res = stringSearch(grid, "hello"); // -> 1 (true)
    bool passed = res == true;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_07() {
    vector<std::vector<char>> grid {
      {'a', 'b', 'a'},
      {'t', 'x', 'x'},
      {'x', 'x', 'x'}
    };
    bool res = stringSearch(grid, "abat"); // -> 1 (true)
    bool passed = res == true;
    cout << "test_07: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_07();
}
