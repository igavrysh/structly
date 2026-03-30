//
//  largest_component.cpp
//  MyCLI
//
//  Created by new on 3/30/26.
//

#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>

int component_size_bfs(std::unordered_map<int, std::vector<int>>& G,
                       std::unordered_set<int>& visited, int start_v) {
    int size = 0;
    std::queue<int> q{};
    if (visited.find(start_v) == visited.end()) {
        q.push(start_v);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        size++;
        for (int next_v : G[v]) {
            if (visited.find(v) != visited.end()) {
                continue;
            }
            visited.insert(next_v);
            q.push(next_v);
        }
    }

    return size;
}

int largestComponent(std::unordered_map<int, std::vector<int>> G) {
    std::queue<int> q{};
    std::unordered_set<int> visited{};
    int max_size = 0;
    for (const std::pair<const int, std::vector<int>>& p : G) {
        int v = p.first;
        if (visited.find(v) != visited.end()) {
            continue;
        }
        max_size = std::max(max_size, component_size_bfs(G, visited, v));
    }

    return max_size;
}

void largest_component_test_00() {
    std::unordered_map<int, std::vector<int>> graph {
      { 0, {8, 1, 5} },
      { 1, {0} },
      { 5, {0, 8} },
      { 8, {0, 5} },
      { 2, {3, 4} },
      { 3, {2, 4} },
      { 4, {3, 2} }
    };

    int res = largestComponent(graph); // -> 4
    std::cout << res << std::endl;
}