//
// Created by new on 4/14/26.
//

#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int min_change_helper(int amount, vector<int>& coins, unordered_map<int, int>& mem) {
    if (amount == 0) {
        return 0;
    }

    if (amount < 0) {
        return -1;
    }

    if (mem.count(amount) > 0) {
        return mem[amount];
    }

    int minn = -1;
    for (int coin : coins) {
        int res = min_change_helper(amount - coin, coins, mem);
        if (res != -1) {
            if (minn == -1) {
                minn = 1 + res;
            }
            minn = min(minn, 1 + res);
        }
    }

    mem[amount] = minn;

    return minn;
}

int minChange(int amount, vector<int> coins) {
    unordered_map<int, int> mem{};
    return min_change_helper(amount, coins, mem);
}
