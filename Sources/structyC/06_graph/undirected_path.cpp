//
//  undirected_path.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
//

#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool undirected_path(std::unordered_map<std::string, std::vector<std::string>> G,
                     std::string v,
                     std::string dst,
                     std::unordered_set<std::string>& visited) {
    if (v == dst) {
        return true;
    }

    for (std::string next_v : G[v]) {
        if (visited.find(next_v) != visited.end()) {
            continue;;
        }

        visited.insert(next_v);
        if (undirected_path(G, next_v, dst, visited)) {
            return true;
        }
    }

    return false;
}

bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges,
                    std::string src,
                    std::string dst) {

    std::unordered_map<std::string, std::vector<std::string>> G{};

    for (std::tuple<std::string, std::string> t : edges) {
        auto [from, to] = t;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    std::unordered_set<std::string> visited{};
    visited.insert(src);

    return undirected_path(G, src, dst, visited);
}
