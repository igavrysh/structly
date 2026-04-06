//
//  max_subarray_product_size_k.cpp
//  MyCLI
//
//  Created by new on 4/5/26.
//

#include <vector>
#include <algorithm>
using namespace std;
double maxSubarrayProductSizeK(std::vector<double> nums, int k) {
    double product = 1.0;
    for (int i = 0; i < k; i++) {
        product *= nums[i];
    }
    double max_product = product;
    for (int i = k; i < nums.size(); i++) {
        product *= nums[i];
        product /= nums[i-k];
        max_product = max(max_product, product);
    }
    return max_product;
}
