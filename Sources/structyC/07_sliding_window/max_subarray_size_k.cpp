//
//  max_subarray_size_k.cpp
//  MyCLI
//
//  Created by new on 4/5/26.
//

#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySumSizeK(std::vector<int> nums, int k) {
    int maxx = 0;
    int sum = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        if (r-l+1 == k) {
            if (r==k-1) {
                maxx = sum;
            } else {
                maxx = max(maxx, sum);
            }
            sum -= nums[l];
            l++;
        }
    }

    return maxx;
}