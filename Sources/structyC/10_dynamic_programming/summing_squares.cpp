//
// Created by new on 4/15/26.
//

#include <unordered_map>
#include <math.h>
using namespace std;

int summing_squares(int n, unordered_map<int, int>& memo) {
    if (memo.count(n) > 0) {
        return memo[n];
    }

    if (n == 0) {
        return 0;
    }

    int minn = -1;
    int res = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        res = summing_squares(n-i*i, memo);
        if (minn == -1) {
            minn = 1 + res;
        }
        minn = min(minn, 1 + res);
    }

    memo[n] = minn;

    return memo[n];
}

int summingSquares(int n) {
    unordered_map<int, int> memo{};
    return summing_squares(n, memo);
}