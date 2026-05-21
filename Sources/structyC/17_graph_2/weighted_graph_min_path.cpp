//
// Created by new on 5/5/26.
//

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

namespace graph_17_2_weigt_graph_min_path {
int dfs(unordered_map<string, unordered_map<string, int>>& G, unordered_set<string>& visited, const string& src,
        const string& dst)
{
    if (src == dst) {
        return 0;
    }
    
    visited.insert(src);
    int minn = -1;
    for (pair<string, int> neigh : G[src]) {
        string to = get<0>(neigh);
        if (visited.count(to) > 0) {
            continue;
        }
        const int cost = get<1>(neigh);
        const int res = dfs(G, visited, to, dst);
        if (res != -1) {
            if (minn == -1) {
                minn = cost + res;
            }
            minn = std::min(minn, cost + res);
        }
    }
    visited.erase(src);
    
    return minn;
}

int weightedGraphMinPath(unordered_map<string, unordered_map<string, int>> G, string src, string dst) {
    unordered_set<string> visited{};
    return dfs(G, visited, src, dst);
}

int weightedGraphMinPath_dijkstra(unordered_map<string, unordered_map<string, int>> G, string src, string dst) {
    priority_queue<tuple<int, string>, vector<tuple<int, string>>, greater<>> pq;
    pq.push(tuple<int, string>(0, src));
    unordered_map<string, int>dist{};
    dist[src] = 0;
    while (!pq.empty()) {
        tuple<int, string> t_v = pq.top();
        pq.pop();
        
        string v = get<1>(t_v);
        int v_cost = get<0>(t_v);
        if (dist.count(dst) > 0 && v_cost > dist[dst]) {
            break;
        }
        
        for (pair<string, int> neigh_info : G[v]) {
            string neigh_v = get<0>(neigh_info);
            int neigh_cost = get<1>(neigh_info);
            if (dist.count(neigh_v) > 0 && dist[neigh_v] < (v_cost + neigh_cost)) {
                continue;
            }
            dist[neigh_v] = v_cost + neigh_cost;
            pq.push(tuple<int, string>(dist[neigh_v], neigh_v));
        }
    }
    
    return dist.count(dst) > 0 ? dist[dst] : -1;
}

void test_00() {
    const unordered_map<string, unordered_map<string, int>> graph {
        {"a", { {"b", 2}, {"d", 9}, {"c", 5} }},
        {"b", { {"a", 2}, {"d", 4}, {"e", 6} }},
        {"c", { {"a", 5}, {"e", 4} }},
        {"d", { {"a", 9}, {"b", 4}, {"e", 1} }},
        {"e", { {"b", 6}, {"c", 4}, {"d", 1} }}
    };
    const int res = weightedGraphMinPath(graph, "a", "e"); // -> 7
    const bool passed = res == 7;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    const unordered_map<string, unordered_map<string, int>> graph {
        {"a", { {"b", 1}, {"c", 1} }},
        {"b", { {"c", 3}, {"a", 1} }},
        {"c", { {"b", 3}, {"d", 1}, {"a", 1} }},
        {"d", { {"c", 1}, {"b", 2} }}
    };
    const int res = weightedGraphMinPath(graph, "a", "d"); // -> 2
    const bool passed = res == 2;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

void test_02() {
    const unordered_map<string, unordered_map<string, int>> graph {
        {"q", { {"r", 5}, {"s", 10} }},
        {"r", { {"q", 5}, {"s", 9}, {"u", 2} }},
        {"s", { {"q", 10}, {"r", 9}, {"t", 1}, {"v", 8} }},
        {"t", { {"s", 1 } }},
        {"u", { {"r", 2}, {"s", 1} }},
        {"v", {}}
    };
    const int res = weightedGraphMinPath(graph, "q", "v"); // -> 16
    const bool passed = res == 16;
    cout << "test_02: " << (passed ? "passed" : "failed") << endl;
}

void test_03() {
    const unordered_map<string, unordered_map<string, int>> graph {
        {"q", { {"r", 5}, {"s", 10} }},
        {"r", { {"q", 5}, {"s", 9}, {"u", 2} }},
        {"s", { {"q", 10}, {"r", 9}, {"t", 1}, {"v", 8} }},
        {"t", { {"s", 1} }},
        {"u", { {"r", 2}, {"s", 1} }},
        {"v", {}}
    };
    const int res = weightedGraphMinPath(graph, "r", "v"); // -> 11
    const bool passed = res == 11;
    cout << "test_03: " << (passed ? "passed" : "failed") << endl;
}

void test_04() {
    const unordered_map<string, unordered_map<string, int>> graph {
        {"x", {{"q", 1}, {"e", 10} }},
        {"b", {{"e", 7}, {"q", 8} }},
        {"q", {{"x", 1}, {"b", 8} }},
        {"e", {{"b", 7}, {"x", 10} }}
    };
    const int res = weightedGraphMinPath(graph, "b", "x"); // -> 9
    const bool passed = res == 9;
    cout << "test_04: " << (passed ? "passed" : "failed") << endl;
}

int main() {
    test_00();
    test_01();
    test_02();
    test_03();
    test_04();
}
}
