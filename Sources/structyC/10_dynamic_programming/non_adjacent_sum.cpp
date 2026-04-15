//
// Created by new on 4/15/26.
//

#include <vector>
#include <algorithm>
using namespace std;

int nonAdjacentSum(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = max(i-1 >= 0 ? dp[i-1] : 0, nums[i] + (i-2 >= 0 ? dp[i-2] : 0));
    }

    return max(dp[n-1], dp[n-2]);
}
