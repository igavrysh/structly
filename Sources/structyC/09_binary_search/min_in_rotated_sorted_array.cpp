//
// Created by new on 4/12/26.
//

#include <vector>
#include <iostream>
using namespace std;

int minInRotatedSortedArray(vector<int> nums) {
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
    return nums[lo];
}

void test_00() {
    int res = minInRotatedSortedArray({5,6,7,9,2,3,4,5});
    bool passed = res == 2;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    int res = minInRotatedSortedArray({24,25,30,12,15,16,20,21,23,23});
    bool passed = res == 12;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char *argv[]) {
    test_01();
}
