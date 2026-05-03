//
// Created by new on 5/2/26.
//

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> possiblePaths(unordered_map<string, vector<std::string>> graph,
    string src, string dst) {
    if (src == dst) {
        return {{dst}};
    }

    vector<vector<string>> res{};
    for (string& next : graph[src]) {
        vector<vector<string>> paths = possiblePaths(graph, next, dst);
        for (vector<string> path : paths) {
            path.insert(path.begin(), src);
            res.push_back(path);
        }
    }

    return res;
}