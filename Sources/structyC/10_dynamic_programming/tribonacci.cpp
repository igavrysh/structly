//
// Created by new on 4/14/26.
//

#include <unordered_map>
using namespace std;

int tribonacci_helper(int n, unordered_map<int, int>& mem) {
    if (mem.count(n) > 0) {
        return mem[n];
    }

    if (n <= 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    mem[n] = tribonacci_helper(n-1, mem) + tribonacci_helper(n-2, mem) + tribonacci_helper(n-3, mem);

    return mem[n];
}

int tribonacci(int n) {
    unordered_map<int, int> mem{};
    return tribonacci_helper(n, mem);
}

