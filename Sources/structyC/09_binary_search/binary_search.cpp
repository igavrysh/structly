//
// Created by new on 4/12/26.
//

#include <vector>
#include <math.h>
using namespace std;

int binarySearch(vector<int> numbers, int target) {
    int lo = 0;
    int hi = numbers.size() - 1;
    while (lo <= hi) {
        int midIdx = floor((lo + hi) / 2);
        int midVal = numbers[midIdx];
        if (target < midVal) {
            hi = midIdx - 1;
        } else if (target > midVal) {
            lo = midIdx + 1;
        } else {
            return midIdx;
        }
    }
    return -1;
}


int binarySearch_mine(vector<int> numbers, int target) {
    int good = numbers.size();
    int bad = -1;
    while (good - bad > 1) {
        int m = bad + (good - bad) / 2;
        if (numbers[m] == target) {
            return m;
        }
        if (numbers[m] < target) {
            bad = m;
        } else {
            good = m;
        }
    }

    return -1;
}

