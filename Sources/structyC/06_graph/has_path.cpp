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
#include <stack>
#include <queue>

bool hasPathBfsIter(
    std::unordered_map<std::string, std::vector<std::string> > graph,
    std::string src,
    std::string dst
) {
    std::unordered_set<std::string> visited{};
    std::queue<std::string> to_visit{};
    to_visit.push(src);
    visited.insert(src);
    while (!to_visit.empty()) {
        std::string v = to_visit.front();
        to_visit.pop();
        if (v == dst) {
            return true;
        }
        for (std::string neighbor: graph[v]) {
            if (visited.find(neighbor) != visited.end()) {
                continue;
            }
            visited.insert(neighbor);
            to_visit.push(neighbor);
        }
    }

    return false;
}

bool hasPathDfsIter(std::unordered_map<std::string, std::vector<std::string> > graph,
                    std::string src,
                    std::string dst
) {
    std::unordered_set<std::string> visited{};
    std::stack<std::string> to_visit{};
    to_visit.push(src);
    visited.insert(src);
    while (!to_visit.empty()) {
        std::string v = to_visit.top();
        to_visit.pop();
        if (v == dst) {
            return true;
        }
        for (std::string neighbor: graph[v]) {
            if (visited.find(neighbor) != visited.end()) {
                continue;
            }
            visited.insert(neighbor);
            to_visit.push(neighbor);
        }
    }
    return false;
}

bool has_path(std::unordered_map<std::string, std::vector<std::string>>& graph,
              std::string& src,
              std::string& dst,
              std::unordered_set<std::string> &visited
) {
    if (src == dst) {
        return true;
    }

    for (std::string neighbor: graph[src]) {
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

bool hasPathR(std::unordered_map<std::string, std::vector<std::string>> &graph,
              std::string src,
              std::string dst
) {
    std::unordered_set<std::string> visited{};
    return has_path(graph, src, dst, visited);
}

void run_has_path_in_graph_with_cycle() {
    std::unordered_map<std::string, std::vector<std::string> > graph{
        {"f", {"g", "i"}},
        {"g", {"f"}}
    };

    bool res = hasPathR(graph, "f", "i"); // 1 (true)
    std::cout << "path from f to i exists? " << res << std::endl;
    // this function behaves as `main()` for the 'run' command
    // you may sandbox in this function, but should not remove it
}
