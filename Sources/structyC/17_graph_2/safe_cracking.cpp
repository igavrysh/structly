//
// Created by new on 5/4/26.
//

#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

namespace graph_17_2_safe_cracking {
string topologicalOrder(unordered_map<int, vector<int>>& G) {
    unordered_map<int, int> incoming{};
    for (tuple<int, vector<int>> tpl : G) {
        int v = get<0>(tpl);
        if (incoming.count(v) == 0) {
            incoming[v] = 0;
        }
        vector<int>& neighs = get<1>(tpl);
        for (int neigh : neighs) {
            incoming[neigh]++;
        }
    }

    vector<int> ready{};
    for (tuple<int, int> tpl : incoming) {
        int v = get<0>(tpl);
        int val_v = get<1>(tpl);
        if (val_v == 0) {
            ready.push_back(v);
        }
    }

    string res{};
    while (!ready.empty()) {
        int v = ready.back();
        res.append(to_string(v));
        ready.pop_back();
        for (int neigh : G[v]) {
            incoming[neigh]--;
            if (incoming[neigh] == 0) {
                ready.push_back(neigh);
            }
        }
    }

    return res;
}

string safeCracking(vector<tuple<int, int>> hints) {
    unordered_map<int, vector<int>> G{};
    for (tuple<int, int> h : hints) {
        int from = get<0>(h);
        int to = get<1>(h);
        G[from].push_back(to);
    }

    return topologicalOrder(G);
}

void test_00() {
    string res = safeCracking(std::vector<std::tuple<int, int>> {
      {7, 1},
      {1, 8},
      {7, 8},
    }); // -> "718"
    bool passed = res == "718";
    cout << "test_00: " << (passed ? "passed" : "failed");
}

int main(int argc, char* argv[]) {
    test_00();
}
}
