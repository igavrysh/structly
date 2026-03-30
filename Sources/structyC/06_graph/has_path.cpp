//
//  has_path.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

bool has_path(std::unordered_map<std::string, std::vector<std::string>> graph,
              std::string src,
              std::string dst,
              std::unordered_set<std::string>& visited
) {
    if (src == dst) {
        return true;
    }

    for (std::string neighbor : graph[src]) {
        if (visited.find(neighbor) != visited.end()) {
            continue;
        }
        visited.insert(neighbor);
        if (has_path(graph, neighbor, dst, visited)) {
            return true;
        }
    }

    return false;
}

// what about cycles?
bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph,
             std::string src,
             std::string dst
             ) {
    std::unordered_set<std::string> visited{};
    return has_path(graph, src, dst, visited);
}

void run_has_path_in_graph_with_cycle() {
    std::unordered_map<std::string, std::vector<std::string>> graph {
        { "f", {"g", "i"} },
        { "g", {"f"} }
    };

    bool res = hasPath(graph, "f", "i"); // 1 (true)
    std::cout << "path from f to i exists? " << res << std::endl;
    // this function behaves as `main()` for the 'run' command
    // you may sandbox in this function, but should not remove it
}
