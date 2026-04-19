//
//  has_cycle.cpp
//  MyCLI
//
//  Created by new on 4/5/26.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

bool dfs_has_cycle(unordered_map<char, vector<char>>& graph, unordered_set<char>& visited,
    unordered_set<char>& visiting, char v) {

    if (visiting.count(v) > 0) {
        return true;
    }

    if (visited.count(v) > 0) {
        return false;
    }

    visiting.insert(v);
    for (char neighbor : graph[v]) {
        if (dfs_has_cycle(graph, visited, visiting, neighbor)) {
            return true;
        }
    }
    visiting.erase(v);
    visited.insert(v);

    return false;
}

bool hasCycle(unordered_map<char, vector<char>> graph) {
    unordered_set<char> visiting{};
    unordered_set<char> visited{};
    for (pair<char, vector<char>> p : graph) {
        unordered_set<char> visited{};
        if (dfs_has_cycle(graph, visited, visiting, p.first)) {
            return true;
        }
    }
    return false;
}

void run_hasCycle_test_00() {
    std::unordered_map<char, std::vector<char>> graph {
      { 'a', {'b'} },
      { 'b', {'c'} },
      { 'c', {'a'} }
    };
    bool res = hasCycle(graph); // -> 1 (true)
    cout << "res: " << res << endl;
}

void run_hasCycle_test_01() {
    std::unordered_map<char, std::vector<char>> graph {
      { 'a', {'b', 'c'} },
      { 'b', {'c'} },
      { 'c', {'d'} },
      { 'd', {} }
    };
    bool res = hasCycle(graph); // -> 1 (true)
    cout << "res: " << res << endl;
}

//int main(int argc, char *argv[]) {
//    run_hasCycle_test_01();
//
//}
//
