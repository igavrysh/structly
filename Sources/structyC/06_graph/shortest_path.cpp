//
//  shortest_path.cpp
//  MyCLI
//
//  Created by new on 3/31/26.
//

#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges,
                 std::string nodeA,
                 std::string nodeB) {
    std::unordered_map<std::string, std::unordered_set<std::string>> G{};

    for (std::tuple<std::string, std::string> e : edges) {
        // or
        // auto [from, to] = e;
        auto from = std::get<0>(e);
        auto to = std::get<1>(e);
        if (G.find(from) == G.end()) {
            G[from] = std::unordered_set<std::string>{};
        }
        if (G.find(to) == G.end()) {
            G[to] = std::unordered_set<std::string>{};
        }
        G[from].insert(to);
        G[to].insert(from);
    }

    std::queue<std::string> q{};
    q.push(nodeA);
    std::unordered_set<std::string> visited{};
    visited.insert(nodeA);
    int length = 0;

    while (!q.empty()) {
        auto level = q.size();
        for (auto i=0;i<level;i++) {
            std::string v = q.front();
            q.pop();
            if (v == nodeB) {
                return length;
            }
            for (std::string next_v : G[v]) {
                if (visited.find(next_v) != visited.end()) {
                    continue;
                }
                visited.insert(next_v);
                q.push(next_v);
            }
        }
        length++;
    }
    return -1;
}


