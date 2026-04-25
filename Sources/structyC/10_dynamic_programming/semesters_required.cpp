#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
using namespace std;

int dfs(int v, unordered_map<int, int>& sems_req, unordered_map<int, unordered_set<int>>& G) {
    if (sems_req[v] != -1) {
        return sems_req[v];
    }
    if (G[v].size() == 0) {
        return 1;
    }

    int max_sems = 0;
    for (int next_v : G[v]) {
        if (sems_req[next_v] != -1) {
            max_sems = max(max_sems, sems_req[next_v]); 
        } else {
            max_sems = max(max_sems, dfs(next_v, sems_req, G)); 
        }
    }

    sems_req[v] = max_sems + 1;

    return sems_req[v];
}

int semestersRequired(int numCourses, vector<tuple<int, int>> prereqs) {
    unordered_map<int, unordered_set<int>> G{};
    unordered_map<int, int> sems_req{};
    for (int v = 0; v < numCourses; v++) {
        G[v] = unordered_set<int>{};
        sems_req[v] = -1;
    }
    for (tuple<int, int> prereq : prereqs) {
        int from = get<0>(prereq);
        int to = get<1>(prereq);
        G[from].insert(to);
    }

    int global_max = 0;
    for (int v = 0; v < numCourses; v++) {
        if (sems_req[v] == -1) {
            global_max = max(global_max, dfs(v, sems_req, G));
        }
    }

    return global_max;
}

void test_00() {
    int numCourses = 6;
    vector<tuple<int, int>> prereqs {
        {1, 2},
        {2, 4},
        {3, 5},
        {0, 5}
    };
    int output = semestersRequired(numCourses, prereqs);
    bool passed = output == 3;
    cout << "test_00: " << (passed ? "PASSED" : "FAILED") << endl;
}

void test_01() {
    int numCourses = 6;
    vector<tuple<int, int>> prereqs {
        {4, 3},
        {3, 2},
        {2, 1},
        {1, 0},
        {5, 2},
        {5, 6}
    };
    int output = semestersRequired(numCourses, prereqs);
    bool passed = output == 5;
    cout << "test_01: " << (passed ? "PASSED" : "FAILED") << endl;
}

void test_02() {
    int numCourses = 5;
    vector<tuple<int, int>> prereqs {
        {1, 0},
        {3, 4},
        {1, 2},
        {3, 2}
    };
    int output = semestersRequired(numCourses, prereqs);
    bool passed = output == 2;
    cout << "test_02: " << (passed ? "PASSED" : "FAILED") << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    test_01();
    test_02();
    return 0;
}
