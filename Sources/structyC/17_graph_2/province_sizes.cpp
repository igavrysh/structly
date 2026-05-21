//
// Created by new on 5/5/26.
//

#include <vector>
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

namespace graph_17_2_province_sizes {

int uf_find(int i, vector<int>& p) {
    int id = i;
    while (p[id] != id) {
        id = p[id];
    }
    return id;
}

void uf_union(int i1, int i2, vector<int>& p, vector<int>& w) {
    int p1 = uf_find(i1, p);
    int p2 = uf_find(i2, p);
    if (p1 == p2) {
        return;
    }
    if (w[p1] >= w[p2]) {
        p[p2] = p1;
        w[p1] += w[p2];
    } else {
        p[p1] = p2;
        w[p2] += w[p1];
    }
}

vector<int> provinceSizes(int n, vector<tuple<int, int>> roads) {
    vector<int> p(n, 0);
    vector<int> w(n, 1);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (tuple<int, int> e: roads) {
        int from = get<0>(e);
        int to = get<1>(e);
        uf_union(to, from, p, w);
    }

    // cout << "p:";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i <<":" <<  p[i] << ", ";
    // }
    // cout << endl;
    // cout << "w:";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i <<":" <<  w[i] << ", ";
    // }
    // cout << endl;

    unordered_set<int> roots{};
    for (int i = 0; i < n; i++) {
        roots.insert(uf_find(i, p));
    }

    vector<int> res{};
    res.reserve(roots.size());
    for (const int root : roots) {
        res.push_back(w[root]);
    }

    return res;
}

void test_00() {
    vector<int> res = provinceSizes(6, {
      {4, 5},
      {1, 0},
      {2, 3},
      {0, 5},
      {5, 1},
      {4, 0}
    }); // -> [4, 2]
    vector<int> exp_res = {4,2};
    sort(res.begin(), res.end());
    sort(exp_res.begin(), exp_res.end());
    bool passed = res == exp_res;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
}
