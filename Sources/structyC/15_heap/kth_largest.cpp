//
// Created by new on 4/29/26.
//

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int kthLargest_sort_based(vector<int> numbers, int k) {
    vector<int> sorted = numbers;
    sort(sorted.begin(), sorted.end(), [](int a, int b) { return a > b; });
    return sorted[k-1];
}

int kthLargest(vector<int> numbers, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int num : numbers) {
        heap.push(num);
        if (heap.size() > k) {
            heap.pop();
        }
    }
    if (heap.size() == 0) {
        return -1;
    }
    return heap.top();
}

void test_00() {
    bool passed = kthLargest({9,2,6,6,1,5,8,7}, 3) == 7; // -> 7
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    bool passed = kthLargest({9,2,6,6,1,5,8,7}, 4) == 6; // -> 6
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

void test_05() {
    std::vector<int> numbers = {
        4,5,85,77,47,80,37,42,3,6,62,33,69,68,16,20,83,39,14,58,75,35,72,36,19,18,66,61,41,79,28,43,7,24,40,53,32,12
      };
    bool passed = kthLargest(numbers, 5) == 77; // -> 77
    cout << "test_05: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
    test_05();
}
