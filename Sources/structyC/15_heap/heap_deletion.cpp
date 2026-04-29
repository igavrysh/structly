//
// Created by new on 4/29/26.
//

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

class MinHeap {
public:
    vector<int> vec;

    MinHeap() {
        vec = vector<int>();
    }

    int size() {
        return vec.size();
    }

    bool isEmpty() {
        return vec.size() == 0;
    }

    void swap(int idx1, int idx2) {
        int temp = vec[idx1];
        vec[idx1] = vec[idx2];
        vec[idx2] = temp;
    }

    void siftUp(int idx) {
        int currentIdx = idx;
        while (currentIdx > 0) {
            int parentIdx = std::floor((currentIdx - 1) / 2);
            if (vec[currentIdx] < vec[parentIdx]) {
                swap(currentIdx, parentIdx);
                currentIdx = parentIdx;
            } else {
                break;
            }
        }
    }

    void insert(int val) {
        vec.push_back(val);
        siftUp(size() - 1);
    }

    int extractMin() {
        if (size() == 0) {
            return -1;
        }
        if (vec.size() == 1) {
            int minn = vec[0];
            vec.pop_back();
            return minn;
        }
        int minn = vec[0];
        int val = vec[vec.size()-1];
        this->vec.pop_back();
        vec[0] = val;
        sift_down(0);

        return minn;
    }

    void sift_down(int i) {
        while (i < vec.size()) {
            int ch1 = i*2 + 1;
            int ch2 = i*2 + 2;
            int ch1Val = ch1 < vec.size() ? vec[ch1] : vec[i];
            int ch2Val = ch2 < vec.size() ? vec[ch2] : vec[i];
            int minn = min(ch1Val, ch2Val);
            if (vec[i] <= minn) {
                return;
            }

            int swap_idx = i;
            if (minn == ch1Val) {
                swap_idx = ch1;
            } else if (minn == ch2Val) {
                swap_idx = ch2;
            }
            swap(i, swap_idx);
            if (swap_idx == i) {
                break;
            }
            i = swap_idx;
        }
    }
};

void test_00() {
    bool passed = true;
    MinHeap heap;
    heap.insert(12);
    heap.insert(13);
    heap.insert(11);
    heap.insert(4);
    heap.insert(20);
    heap.insert(9);
    heap.insert(22);
    heap.insert(14);
    passed &= heap.extractMin() == 4; // -> 4
    passed &= heap.extractMin() == 9; // -> 9
    passed &= heap.extractMin() == 11; // -> 11
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    bool passed = true;
    MinHeap heap;
    heap.insert(12);
    heap.insert(93);
    heap.insert(63);
    heap.insert(16);
    passed &= heap.extractMin() == 12; // -> 12
    passed &= heap.extractMin() == 16; // -> 16
    heap.insert(-500);
    heap.insert(21);
    heap.insert(11);
    heap.insert(43);
    heap.insert(-6);
    heap.insert(35);
    heap.insert(15);
    passed &= heap.extractMin() == -500; // -> -500
    passed &= heap.extractMin() == -6; // -> -6
    passed &= heap.extractMin() == 11; // -> 11
    passed &= heap.extractMin() == 15; // -> 15
    passed &= heap.extractMin() == 21; // -> 21
    passed &= heap.extractMin() == 35; // -> 35
    passed &= heap.extractMin() == 43; // -> 43
    passed &= heap.extractMin() == 63; // -> 63
    passed &= heap.extractMin() == 93; // -> 93
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
}

