//
// Created by new on 4/13/26.
//

#include <vector>
#include <iostream>
using namespace std;
int findPeak(vector<int> nums) {
    const int n = nums.size();
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
        int m = lo + (hi - lo) / 2;
        if (nums[m] > nums[m+1]) {
            hi = m;
        } else {
            lo = m+1;
        }
    }
    return lo;
}

void test_02() {
    const vector<int> nums = {2,5,7,10,12};

    int output = findPeak(nums);

    bool passed = output == 4;

    cout<< "test_02: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char *argv[]) {
    test_02();
}
