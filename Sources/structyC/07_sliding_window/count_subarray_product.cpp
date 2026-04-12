//
// Created by new on 4/11/26.
//

#include <vector>
using namespace std;

int countSubarrayProduct(vector<int> nums, int targetProduct) {
    int counter = 0;
    int l = 0;
    int product = 1;
    for (int r = 0;  r < nums.size(); r++) {
        product *= nums[r];
        while (product >= targetProduct && l<=r) {
            product /= nums[l++];
        }
        counter += (r-l+1);
    }
    return counter;
}
