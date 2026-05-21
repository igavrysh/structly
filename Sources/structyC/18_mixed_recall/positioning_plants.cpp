//
// Created by new on 5/7/26.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

namespace mixed_reall_pos_plants {
int positioningPlants(vector<vector<int>> costs) {
    int types = costs[0].size();
    if (types < 2) {
        return -1;
    }
    // max heap of size 2 to store min cost (idx 1) and second to min cost (idx 0) - so that if idx
    // for the type if matches with idx of min cost generating flower on prev row - select other, next to min cost
    // type from prev row
    // tuple 0 - index, 1 - cost
    vector<tuple<int, int>> dp_heap{};
    vector<tuple<int, int>> dp_heap_prev{{0,0},{0,1}};
    for (int i = 0; i < costs.size(); i++) {
        for (int j = 0; j < types; j++) {
            int val = costs[i][j] + (get<1>(dp_heap_prev[1]) != j ? get<0>(dp_heap_prev[1]) : get<0>(dp_heap_prev[0]));
            dp_heap.push_back({val, j});
            push_heap(dp_heap.begin(), dp_heap.end(), less<tuple<int, int>>());
            if (dp_heap.size() > 2) {
                pop_heap(dp_heap.begin(), dp_heap.end(), less<tuple<int, int>>());
                dp_heap.pop_back();
            }
        }
        dp_heap_prev = dp_heap;
        dp_heap = vector<tuple<int, int>>{};
    }
    return get<0>(dp_heap_prev[1]);
}

void test_00() {
    int res = positioningPlants(std::vector<std::vector<int>>{
        {4, 3, 7},
        {6, 1, 9},
        {2, 5, 3}
    }); // -> 7, by doing 4 + 1 + 2.
    bool passed = res == 7;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    int res = positioningPlants(std::vector<std::vector<int>>{
        {12, 14, 5},
        {6, 3, 2}
    }); // -> 8
    bool passed = res == 8;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
}
}

