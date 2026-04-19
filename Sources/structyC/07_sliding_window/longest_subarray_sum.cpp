//
// Created by new on 4/11/26.
//

#include <vector>
#include <algorithm>
using namespace  std;

int longestSubarraySum(std::vector<int> nums, int targetSum) {
    int sum = 0;
    int l = 0;
    int longest = -1;
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while (sum > targetSum && l <= r) {
            sum -= nums[l];
            l++;
        }
        if (sum == targetSum) {
            longest = max(longest, r-l+1);
        }
    }

    return longest;
}