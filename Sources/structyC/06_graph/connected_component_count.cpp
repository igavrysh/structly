//
//  connected_component_count.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

void connected_components_r(std::unordered_map<int, std::vector<int>> G,
                            int v,
                            std::unordered_set<int>& visited) {
    for (int next_v : G[v]) {
        if (visited.find(next_v) != visited.end()) {
            return;
        }
        visited.insert(next_v);
        connected_components_r(G, next_v, visited);
    }
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> G) {
    std::unordered_set<int> visited{};
    int counter = 0;
    for (const auto& pair : G) {
        int v = pair.first;
        if (visited.find(v) != visited.end()) {
            continue;
        }
        visited.insert(v);
        connected_components_r(G, v, visited);
        counter++;
    }

    return counter;
}

void run_connectedComponentsCount_test_00() {
    std::unordered_map<int, std::vector<int>> graph {
        { 0, { 8, 1, 5 } },
        { 1, { 0 } },
        { 5, { 0, 8 } },
        { 8, { 0, 5 } },
        { 2, { 3, 4 } },
        { 3, { 2, 4 } },
        { 4, { 3, 2 } }
    };
    int res = connectedComponentsCount(graph); // -> 2
    std::cout << "count: " << res << std::endl;
}

void run_connectedComponentsCount_test_01() {
    std::unordered_map<int, std::vector<int>> graph {
        { 1, { 2 } },
        { 2, { 1, 8 } },
        { 6, { 7 } },
        { 9, { 8 } },
        { 7, { 6, 8 } },
        { 8, { 9, 7, 2 } }
    };
    int res = connectedComponentsCount(graph); // -> 2
    std::cout << "count: " << res << std::endl;
}

int main(int argc, char const *argv[]) {
    run_connectedComponentsCount_test_00();
    run_connectedComponentsCount_test_01();
    return 0;
}
