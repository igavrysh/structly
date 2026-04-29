//
// Created by new on 4/29/26.
//

#include <vector>
#include <cmath>
#include <algorithm>
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
            int minn = min(
                ch1 < vec.size() ? vec[ch1] : vec[i],
                ch2 < vec.size() ? vec[ch2] : vec[i]);
            if (vec[i] <= minn) {
                return;
            } else {
                if (ch1 < vec.size() && minn == vec[ch1]) {
                    int tmp = vec[i];
                    vec[i] = vec[ch1];
                    vec[ch1] = tmp;
                    i = ch1;
                } else {
                    int tmp = vec[i];
                    vec[i] = vec[ch2];
                    vec[ch2] = tmp;
                    i = ch2;
                }
            }
        }
    }
};
