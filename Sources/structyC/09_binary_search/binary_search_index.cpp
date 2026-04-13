//
// Created by new on 4/12/26.
//

#include <vector>
using namespace std;

int binarySearchIndex(vector<int> nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}

int binarySearchIndex_mine(vector<int> nums, int target) {
    int bad = -1;
    int good = nums.size();
    while (good - bad > 1) {
        int mid = bad + (good - bad) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            bad = mid;
        } else {
            good = mid;
        }
    }

    return good;
}
