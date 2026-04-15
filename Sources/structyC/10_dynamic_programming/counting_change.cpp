//
// Created by new on 4/15/26.
//

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int counting_сhange_helper(int amount, int start, vector<int>& coins, unordered_map<string, int>& mem) {
    string id = to_string(amount) + ',' + to_string(start);
    if (mem.count(id) > 0) {
        return mem[id];
    }
    if (amount == 0) {
        return 1;
    }
    if (amount < 0) {
        return 0;
    }

    int counter = 0;

    for (int i = start; i < coins.size(); i++) {
        counter += counting_сhange_helper(amount - coins[i], i, coins, mem);
    }

    mem[id] = counter;

    return mem[id];
}

int countingChange(int amount, vector<int> coins) {
    unordered_map<string, int> mem{};
    int res = counting_сhange_helper(amount, 0, coins, mem);
    return res;
}

void test_00() {
    int res = countingChange(4, std::vector<int> {1, 2, 3}); // -> 4
    bool passed = res == 4;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    int res = countingChange(3, std::vector<int> {1, 2, 3}); // -> 4
    bool passed = res == 3;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}


int main(int argc, char *argv[]) {
    test_01();
}
