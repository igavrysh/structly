//
// Created by new on 4/13/26.
//

#include <vector>
using namespace std;

// returns index
int findInRotatedSortedArray_minInRotatedSortedArray(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo < hi) {
        int mid = (hi + lo) / 2;
        if (nums[mid] <= nums[hi]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int findInRotatedSortedArray_binarySearch(vector<int>& nums, int lo, int hi, int target) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return -1;
}

// Find min
int findInRotatedSortedArray(vector<int> nums, int target) {
    const int minIdx = findInRotatedSortedArray_minInRotatedSortedArray(nums);
    const int l_res = findInRotatedSortedArray_binarySearch(nums, 0, minIdx - 1, target);
    if (l_res != -1) {
        return l_res;
    }

    return findInRotatedSortedArray_binarySearch(nums, minIdx, nums.size() - 1, target);
}

// Do find right away, account for jugged array in left or right part split by m, or no jugged part at all
int findInRotatedSortedArray_mine(vector<int> nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (nums[m] == target) {
            return m;
        }
        if (nums[lo] < nums[m]) {
            if (target > nums[m]) {
                lo = m + 1;
            } else if (target >= nums[lo] && target < nums[m]) {
                hi = m - 1;
            } else if (target < nums[lo]) {
                lo = m + 1;
            } else {
                return -1;
            }
        } else if (nums[lo] > nums[m]) {
            if (target >= nums[lo]) {
                hi = m;
            } else if (target <= nums[lo] && target > nums[m]) {
                lo = m + 1;
            } else if (target < nums[m]) {
                hi = m - 1;
            } else {
                return -1;
            }
        } else {
            lo++;
        }
    }

    return -1;
}
