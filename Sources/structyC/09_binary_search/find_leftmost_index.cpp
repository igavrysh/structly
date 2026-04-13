//
// Created by new on 4/12/26.
//

#include <vector>

int findLeftmostIndex(std::vector<int> nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] >= target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo != nums.size() ? lo : -1;
}

int findLeftmostIndex_mine(std::vector<int> nums, int target) {
    int bad = -1;
    int good = nums.size();

    while (good - bad > 1) {
        int mid = bad + (good - bad) / 2;
        if (nums[mid] >= target) {
            good = mid;
        } else {
            bad = mid;
        }
    }

    return good < nums.size() ? good : -1;
}
