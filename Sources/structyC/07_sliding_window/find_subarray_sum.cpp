//
// Created by new on 4/11/26.
//
#include <array>
#include <vector>

std::array<int, 2> findSubarraySum(std::vector<int> nums, int targetSum) {
    int sum = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while (sum > targetSum && l <= r) {
            sum -= nums[l];
            l++;
        }
        if (sum == targetSum) {
            return std::array<int, 2>{l, r};
        }
    }

    return std::array<int, 2>{-1, -1};
}

