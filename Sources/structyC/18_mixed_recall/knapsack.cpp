//
// Created by new on 5/7/26.
//

#include <vector>
#include <cmath>
#include <unordered_map>
#include <iostream>
using namespace std;

namespace mixed_recall_18_knapsack {
int dp(vector<int>& values, vector<int>& weights, int weightLimit, int i, unordered_map<string, int>& cache) {
    const string key = to_string(weightLimit) + "-" + to_string(i);
    if (cache.count(key) > 0) {
        return cache[key];
    }
    if (weightLimit <= 0) {
        return 0;
    }

    if (i < 0) {
        return 0;
    }

    int max_value = 0;
    if (weightLimit - weights[i] >= 0) {
        max_value = max(max_value, values[i] + dp(values, weights, weightLimit - weights[i], i-1, cache));
    }

    max_value = max(max_value, dp(values, weights, weightLimit, i-1, cache));
    cache[key] = max_value;

    return max_value;
}

int knapsack(vector<int> values, vector<int> weights, int weightLimit) {
    unordered_map<string, int> cache{};
    return dp(values, weights, weightLimit, values.size()-1, cache);
}

void test_00() {
    int res = knapsack({5, 4, 9}, {6, 1, 15}, 20); // -> 13
    bool passed = res == 13;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
}
