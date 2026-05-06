//
// Created by new on 5/5/26.
//

#include <vector>
#include <tuple>
#include <unordered_set>

using namespace std;

int uf_find(int i, vector<int>& p) {
    int id = i;
    while (p[id] != id) {
        id = p[id];
    }
    p[i] = id;
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

tuple<int, int> extraCable(int numComputers, vector<tuple<int, int>> cables) {
    vector<int> p(numComputers, 0);
    vector<int> w(numComputers, 1);
    for (int i = 0; i < numComputers; i++) {
        p[i] = i;
    }
    for (tuple<int, int> c :cables) {
        int v1 = get<0>(c);
        int v2 = get<1>(c);
        int p1 = uf_find(v1, p);
        int p2 = uf_find(v2, p);
        if (p1 == p2) {
            return tuple<int, int>(v1, v2);
        }
        uf_union(v1, v2, p, w);
    }

    return tuple<int, int>(-1, -1);
}