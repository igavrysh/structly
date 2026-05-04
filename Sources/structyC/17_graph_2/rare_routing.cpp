//
// Created by new on 5/3/26.
//

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool dfs_no_cycles(unordered_map<int, vector<int>> &G, vector<bool> &visited, vector<bool>& path, int v, int parent_v) {
    path[v] = true;
    for (int neigh : G[v]) {
        if (neigh == parent_v) {
            continue;
        }
        if (path[neigh]) {
            return false;
        }
        if (visited[neigh]) {
            continue;
        }
        visited[neigh] = true;
        const bool res = dfs_no_cycles(G, visited, path, neigh, v);
        if (!res) {
            return false;
        }
    }
    path[v] = false;
    return true;
}

bool rareRouting(int n, vector<vector<int>> roads) {
    unordered_map<int, vector<int>> G{};
    for (vector<int> road : roads) {
        int from = road[0];
        int to = road[1];
        G[from].push_back(to);
        G[to].push_back(from);
    }

    vector<bool> visited(n, false);
    vector<bool> path(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        if (i != 0) {
            return false;
        }
        const bool res = dfs_no_cycles(G, visited, path, i, -1);
        if (!res) {
            return false;
        }
    }
    return true;
}

void test_00() {
    bool res = rareRouting(4, std::vector<std::vector<int>> {
      {0, 1},
      {0, 2},
      {0, 3}
    }); // -> 1 (true)
    bool passed = res == true;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    bool res = rareRouting(4, std::vector<std::vector<int>> {
      {0, 1},
      {0, 2},
      {0, 3},
      {3, 2}
    }); // -> 0 (false)
    bool passed = res == false;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
}
