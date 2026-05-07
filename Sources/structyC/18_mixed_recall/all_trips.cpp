//
// Created by new on 5/6/26.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<vector<string>> dfs(unordered_map<string, vector<string>>& G, string& startStation, string& endStation) {
    if (startStation == endStation) {
        return {{ startStation }};
    }

    vector<vector<string>> res{};
    for (string& neigh : G[startStation]) {
        vector<vector<string>> paths = dfs(G, neigh, endStation);
        for (vector<string> path : paths) {
            path.push_back(startStation);
            res.push_back(path);
        }
    }

    return res;
}

vector<vector<string>> allTrips(vector<tuple<string, string>> routes, string startStation, string endStation) {
    unordered_map<string, vector<string>> G{};
    for (tuple<string, string> r : routes) {
        string from = get<0>(r);
        string to = get<1>(r);
        G[from].push_back(to);
    }

    vector<vector<string>> res = dfs(G, startStation, endStation);
    for (vector<string>& path : res) {
        reverse(path.begin(), path.end());
    }

    return res;
}

void test_00() {
    vector<tuple<string, string>> routes {
      {"brookdale", "denton junction"},
      {"astor place", "brookdale"},
      {"astor place", "cony island"},
      {"astor place", "denton junction"},
      {"cony island", "denton junction"}
    };
    // [
    //   ["astor place", "brookdale", "denton junction"],
    //   ["astor place", "cony island", "denton junction"],
    //   ["astor place", "denton junction"]
    // ]
    vector<vector<string>> res = allTrips(routes, "astor place", "denton junction");
    vector<vector<string>> exp_res = {
        {"astor place", "brookdale", "denton junction"},
        {"astor place", "cony island", "denton junction"},
        {"astor place", "denton junction"}
    };
    sort(res.begin(), res.end());
    sort(exp_res.begin(), exp_res.end());
    bool passed = res == exp_res;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
