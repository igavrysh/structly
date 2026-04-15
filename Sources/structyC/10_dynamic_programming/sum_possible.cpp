//
// Created by new on 4/14/26.
//

#include <vector>
#include <unordered_map>
using namespace std;

bool sum_possible_helper(int amount, vector<int> numbers, unordered_map<int, bool>& mem) {
    if (mem.count(amount) > 0) {
        return mem[amount];
    }
    if (amount < 0) {
        return false;
    }
    if (amount == 0) {
        return true;
    }

    bool res = false;
    for (int num : numbers) {
        res = sum_possible_helper(amount - num, numbers, mem);
        if (res) {
            break;
        }
    }
    mem[amount] = res;

    return mem[amount];
}

bool sumPossible(int amount, vector<int> numbers) {
    unordered_map<int, bool> mem;
    return sum_possible_helper(amount, numbers, mem);
}
