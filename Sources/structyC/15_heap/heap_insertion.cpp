//
// Created by new on 4/28/26.
//

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
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

    void insert(int val) {
        vec.push_back(val);
        sift_up(vec.size() - 1);
    }


    int parent(int i) {
        return floor((i-1) / 2);
    }

    void sift_up(int i) {
        int p = parent(i);
        while (i != 0) {
            if (vec[p] > vec[i]) {
                int tmp = vec[p];
                vec[p] = vec[i];
                vec[i] = tmp;
            }
            i = p;
            p = parent(i);
        }
    }
};

void test_00() {
    MinHeap heap;
    heap.insert(12);
    heap.insert(13);
    heap.insert(11);
    heap.insert(4);
    heap.insert(20);
    heap.insert(9);
    heap.insert(22);
    heap.insert(14);

    //               4
    //            /    \
    //          11      9
    //         / \    /  \
    //       13  20  12  22
    //      /
    //    14
    //
    //
    // [ 4, 11, 9, 13, 20, 12, 22, 14 ]
    bool passed = heap.vec == vector<int>{4, 11, 9, 13, 20, 12, 22, 14};
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    MinHeap heap;
    heap.insert(12);
    heap.insert(93);
    heap.insert(63);
    heap.insert(16);
    heap.insert(-500);
    heap.insert(21);
    heap.insert(11);
    heap.insert(43);
    heap.insert(-6);
    heap.insert(35);
    heap.insert(15);
    heap.insert(37);
    heap.insert(29);
    heap.insert(-501);
    heap.insert(80);

    //                              -501
    //                      /                \
    //                    -6                -500
    //                 /     \            /       \
    //               12      15          29        11
    //             /  \     /  \       /  \       /  \
    //            93  43   35  16    63   37     21  80
    //
    //
    // [ -501, -6, -500, 12, 15, 29, 11, 93, 43, 35, 16, 63, 37, 21, 80 ]
    bool passed = heap.vec == vector<int>{-501, -6, -500, 12, 15, 29, 11, 93, 43, 35, 16, 63, 37, 21, 80};
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
}

