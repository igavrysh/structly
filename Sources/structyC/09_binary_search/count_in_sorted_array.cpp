//
// Created by new on 4/12/26.
//

#include <vector>
using namespace std;

int countInSortedArray_findLeftIndex(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (nums[mid] >= target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int countInSortedArray_findRightIndex(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (nums[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return hi;
}

int countInSortedArray(vector<int> nums, int target) {
    const int l = countInSortedArray_findLeftIndex(nums, target);
    const int r = countInSortedArray_findRightIndex(nums, target);

    return r - l + 1;
}
