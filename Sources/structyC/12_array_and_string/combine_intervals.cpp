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

    // cout << "sorted: ";
    // for (auto & interval : intervals) {
    //     cout << "[" << get<0>(interval) << ", " << get<1>(interval) << "], ";
    // }

    int curr_s = get<0>(intervals[0]);
    int curr_e = get<1>(intervals[0]);
    for (auto & interval : intervals) {
        const int s = get<0>(interval);
        const int e = get<1>(interval);
        if (curr_e < s) {
            res.push_back(tuple<int, int>(curr_s, curr_e));
            curr_s = s;
            curr_e = e;
        } else {
            curr_e = max(curr_e, e);
        }
    }

    res.push_back(tuple<int, int>(curr_s, curr_e));

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
    for (auto & interval : res) {
        cout << "[" << get<0>(interval) << ", " << get<1>(interval) << "], ";
    }
}

int main(int argc, char* argv[]) {
    test_00();
}

