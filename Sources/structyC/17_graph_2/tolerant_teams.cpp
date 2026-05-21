//
// Created by new on 5/3/26.
//

#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

namespace graph_17_2_tol_teams {
bool is_bipartite(string v, bool color, unordered_map<string, vector<string>>& G, unordered_map<string, bool>& coloring) {
    if (coloring.count(v) > 0) {
        return color == coloring[v];
    }
    
    coloring[v] = color;
    
    for (string neigh : G[v]) {
        if (!is_bipartite(neigh, !color, G, coloring)) {
            return false;
        }
    }
    
    return true;
}

bool tolerantTeams(vector<tuple<string, string>> rivalries) {
    unordered_map<string, vector<string>> G{};
    for (tuple<string, string> r : rivalries) {
        string from = get<0>(r);
        string to = get<1>(r);
        G[from].push_back(to);
        G[to].push_back(from);
    }
    unordered_map<string, bool> coloring{};
    for (tuple<string, vector<string>> r : G) {
        string v = get<0>(r);
        if (coloring.count(v) == 0 && !is_bipartite(v, true, G, coloring)) {
            return false;
        }
    }
    return true;
}

void test_00() {
    bool res = tolerantTeams(vector<tuple<string, string>> {
        {"philip", "seb"},
        {"raj", "nader"}
    });
    bool passed = res == true;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    bool res = tolerantTeams(vector<tuple<string, string>> {
        {"philip", "seb"},
        {"raj", "nader"},
        {"raj", "philip"},
        {"seb", "raj"}
    });
    bool passed = res == false;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
}
}
