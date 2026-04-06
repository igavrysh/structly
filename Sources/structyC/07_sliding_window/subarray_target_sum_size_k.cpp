//
//  subarray_target_sum_size_k.cpp
//  MyCLI
//
//  Created by new on 4/5/26.
//

#include <vector>
using namespace std;

int subarrayTargetSumSizeK(std::vector<int> nums, int target, int k) {
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    counter += (sum == target ? 1 : 0);
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i];
        sum -= nums[i-k];
        if (sum == target) {
            counter += 1;
        }
    }

    return counter;
}
