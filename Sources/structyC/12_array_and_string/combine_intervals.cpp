//
// Created by new on 4/27/26.
//

#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

vector<tuple<int, int>> combineIntervals(vector<tuple<int, int>> intervals) {
    sort(intervals.begin(), intervals.end(), [](tuple<int, int> &a, tuple<int, int> &b) -> bool {
        return get<0>(a) < get<0>(b);
    });

    vector<tuple<int, int>> res{};
    if (intervals.empty()) {
        return res;
    }

    cout << "sorted: ";
    for (auto & interval : intervals) {
        cout << "[" << get<0>(interval) << ", " << get<1>(interval) << "], ";
    }

    int curr_start = get<0>(intervals[0]);
    int curr_end = get<1>(intervals[0]);
    for (auto & interval : intervals) {
        const int start = get<0>(interval);
        const int end = get<1>(interval);
        if (curr_end < start) {
            res.push_back(tuple<int, int>(curr_start, curr_end));
            curr_start = start;
            curr_end = end;
        } else {
            curr_end = max(curr_end, end);
        }
    }

    res.push_back(tuple<int, int>(curr_start, curr_end));

    return res;
}

void test_00() {
    std::vector<std::tuple<int, int>> intervals {
      {1, 4},
      {12, 15},
      {3, 7},
      {8, 13},
    };
    vector<tuple<int, int>> res = combineIntervals(intervals);

    cout << "\nres: ";
    for (auto & interval : intervals) {
        cout << "[" << get<0>(interval) << ", " << get<1>(interval) << "], ";
    }
}

int main(int argc, char* argv[]) {
    test_00();
}

