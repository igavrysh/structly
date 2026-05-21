//
// Created by new on 5/5/26.
//

#include <vector>
#include <tuple>
#include <unordered_set>
using namespace std;

namespace graph_17_2_union_find_code_1 {
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

int countComponents(int n, vector<tuple<int, int>> edges) {
    vector<int> p(n, 0);
    vector<int> w(n, 1);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (auto [from, to] : edges) {
        uf_union(to, from, p, w);
    }

    unordered_set<int> roots{};
    for (int i = 0; i < n; i++) {
        roots.insert(uf_find(i, p));
    }

    return roots.size();
}
}


