//
// Created by new on 5/4/26.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;

namespace graph_17_2_topological_order {
bool postOrderDfs(unordered_map<string, vector<string>>& G, unordered_set<string>& visited, unordered_set<string>& path,
    vector<string>& order, const string& v)
{
    path.insert(v);
    visited.insert(v);
    for (string& neigh: G[v]) {
        if (path.count(neigh) > 0) {
            return false;
        }
        if (visited.count(neigh) > 0) {
            continue;
        }
        bool res = postOrderDfs(G, visited, path, order, neigh);
        if (!res) {
            return false;
        }
    }
    order.push_back(v);
    path.erase(v);
    return true;
}

vector<string> topologicalOrder(unordered_map<string, vector<string>> G) {
    unordered_set<string> visited{};
    vector<string> order{};
    for (tuple<string, vector<string>> tp : G) {
        string v = get<0>(tp);
        if (visited.count(v) > 0) {
            continue;
        }

        unordered_set<string> path{};
        if (!postOrderDfs(G, visited, path, order, v)) {
            return vector<string>{};
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

void test_00() {
    vector<string> res = topologicalOrder(unordered_map<string, vector<string>> {
      { "a", {"f"} },
      { "b", {"d"} },
      { "c", {"a", "f"} },
      { "d", {"e"} },
      { "e", {} },
      { "f", {"b", "e"} },
    }); // -> ["c", "a", "f", "b", "d", "e"]
    cout << "output: ";
    for (const string& str : res) {
        cout << str << ", ";
    }
    cout << endl;
}

void test_my_test() {
    vector<string> res = topologicalOrder(unordered_map<string, vector<string>> {
      { "a", {"b"} },
      { "b", {"c"} },
      { "c", {"a"} },
    }); // -> ["c", "a", "f", "b", "d", "e"]
    cout << "output: ";
    for (const string& str : res) {
        cout << str << ", ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    test_my_test();
    test_00();
}
}
