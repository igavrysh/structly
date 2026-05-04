//
// Created by new on 5/3/26.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <iostream>
using namespace std;

bool dfs_valid(const string& v, bool curr_color, unordered_map<string, vector<string>>& G, unordered_map<string, bool> &coloring) {
    if (coloring.count(v) > 0) {
        return coloring[v] == curr_color;
    }

    coloring[v] = curr_color;

    for (const string& next_v : G[v]) {
        const bool res = dfs_valid(next_v, !curr_color, G, coloring);
        if (!res) {
            return false;
        }
    }

    return true;
}

bool canColor(unordered_map<string, vector<string>> G) {
    unordered_map<string, bool> coloring{};
    for (tuple<string, vector<string>> t : G) {
        string v = get<0>(t);
        if (coloring.count(v) == 0 && !dfs_valid(v, true, G, coloring)) {
            return false;
        }
    }
    return true;
}

bool color_graph_bfs(string start_v, unordered_map<string, vector<string>>& G, unordered_set<string>& visited, unordered_map<string, int>& color) {
    int clr = 0;
    queue<tuple<string, int>> q{};
    visited.insert(start_v);
    color[start_v] = clr;
    q.push(tuple<string, int>{start_v, clr});
    while (!q.empty()) {
        tuple<string, int> tup = q.front();
        string v = get<0>(tup);
        int color_v = get<1>(tup);
        q.pop();
        int next_color_v = (color_v + 1) % 2;
        for (string neigh : G[v]) {
            if (visited.count(neigh) == 0) {
                visited.insert(neigh);
                color[neigh] = next_color_v;
                q.push({neigh, next_color_v});
            } else {
                if (color[neigh] != next_color_v) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool canColor_bfs(unordered_map<string, vector<string>> G) {
    unordered_map<string, int> color{};
    unordered_set<string> visited{};
    for (tuple<string, vector<string>> t : G) {
        string v = get<0>(t);
        if (visited.count(v) > 0) {
            continue;
        }
        if (!color_graph_bfs(v, G, visited, color)) {
            return false;
        }
    }
    return true;
}

void test_00() {
    unordered_map<string, vector<string>> G = {
        { "x", {"y"} },
        { "y", {"x","z"} },
        { "z", {"y"} }
    };
    bool res = canColor(G);
    bool exp_res = true;
    bool passed = res == exp_res;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    unordered_map<string, vector<string>> G = {
        { "q", {"r", "s"} },
        { "r", {"q", "s"} },
        { "s", {"r", "q"} }
    };
    bool res = canColor(G);
    bool exp_res = false;
    bool passed = res == exp_res;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
