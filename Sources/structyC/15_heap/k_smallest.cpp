//
// Created by new on 4/29/26.
//

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> kSmallest(vector<int> numbers, int k) {
    vector<int> heap{};
    for (int num : numbers) {
        heap.push_back(num);
        push_heap(heap.begin(), heap.end(), less<int>());
        if (heap.size() > k) {
            pop_heap(heap.begin(), heap.end(), less<int>());
            heap.pop_back();
        }
    }

    sort(heap.begin(), heap.end(), std::less<int>());

    return heap;
}

void test_00() {
    vector<int> res = kSmallest(vector<int>{8, 2, 7, -3, 5, 10}, 3);
    bool passed = res == vector<int>{-3, 2, 5};
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}



