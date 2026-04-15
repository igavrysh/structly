//
// Created by new on 4/14/26.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int fib_helper(int n, unordered_map<int, int>& mem) {
    if (mem.count(n) > 0) {
        return mem[n];
    }

    if (n <= 1) {
        return n;
    }

    mem[n] = fib_helper(n-1, mem) + fib_helper(n-2, mem);

    return mem[n];
}

int fib(int n) {
    unordered_map<int, int> mem;
    return fib_helper(n, mem);
}

void test_02() {
    int res = fib(2);
    bool passed = res == 1;
    cout << "test_02: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char *argv[]) {
    test_02();
}
