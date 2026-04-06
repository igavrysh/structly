//
//  prereqs_possible.h
//  MyCLI
//
//  Created by new on 4/5/26.
//

#include <vector>
#include <tuple>
#include <unordered_set>
#include <unordered_map>

#include <iostream>
using namespace std;

bool dfs_has_cycle(unordered_map<int, unordered_set<int>>& G, unordered_set<int>& visited,
    unordered_set<int>& visiting, int v) {
    if (visiting.count(v) > 0) {
        return true;
    }

    if (visited.count(v) > 0) {
        return false;
    }

    visiting.insert(v);

    for (int neighbor : G[v]) {
        if (dfs_has_cycle(G, visited, visiting, neighbor)) {
            return true;
        }
    }
    visiting.erase(v);
    visited.insert(v);
    return false;
}

bool prereqsPossible(int numCourses, vector<tuple<int, int>> prereqs) {
    unordered_map<int, unordered_set<int>> G{};
    for (tuple<int, int> e : prereqs) {
        int from = get<0>(e);
        int to = get<1>(e);
        if (G.find(from) == G.end()) {
            G[from] = unordered_set<int>{};
        }
        G[from].insert(to);
    }
    unordered_set<int> visited{};
    for (pair<int, unordered_set<int>> p : G) {
        unordered_set<int> visiting{};
        if (dfs_has_cycle(G, visited, visiting, p.first)) {
            return false;
        }
    }
    return true;
}

void prereqsPossible_test_00() {
    int numCourses = 6;
    std::vector<std::tuple<int, int>> prereqs {
      {0, 1},
      {2, 3},
      {0, 2},
      {1, 3},
      {4, 5}
    };
    bool res = prereqsPossible(numCourses, prereqs); // -> 1 (true)
    cout << res << endl;
}

void prereqsPossible_test_01() {
    int numCourses = 6;
    std::vector<std::tuple<int, int>> prereqs {
      {0, 1},
      {2, 3},
      {0, 2},
      {1, 3},
      {4, 5},
      {3, 0}
    };
    bool res = prereqsPossible(numCourses, prereqs); // -> 0 (false)
    cout << res << endl;
}

int main(int argc, char *argv[]) {
    prereqsPossible_test_01();
}


