//
// Created by new on 4/14/26.
//

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }

    int i = 1;
    int prev = 1;
    int prev_prev = 0;
    while (i++ < n) {
        int tmp = prev;

        prev = prev + prev_prev;
        prev_prev = tmp;
    }

    return prev;
}

void test_02() {
    int res = fib(2);
    bool passed = res == 1;
    cout << "test_02: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char *argv[]) {
    test_02();
}
