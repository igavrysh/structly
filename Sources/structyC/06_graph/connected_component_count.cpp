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
        std::cout<<"visiting v:"<<next_v<<std::endl;
        visited.insert(next_v);
        connected_components_r(G, next_v, visited);
    }
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> G) {
    std::unordered_set<int> visited{};
    int counter = 0;
    for (auto [v, value] : G) {
        std::cout<<"newww"<<std::endl;
        if (visited.find(v) != visited.end()) {
            continue;
        }
        std::cout<<"visiting v:"<<v<<std::endl;

        visited.insert(v);
        connected_components_r(G, v, visited);
        counter++;
    }

    return counter;
}

void run_connectedComponentsCount() {
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
    std::cout << "count: " << res;
}
