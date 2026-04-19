//
// Created by new on 4/16/26.
//

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

bool array_stepper(int i, vector<int>& numbers, unordered_map<int, bool>& memo) {
    if (memo.count(i) > 0) {
        return memo[i];
    }

    if (i >= numbers.size()-1) {
        return true;
    }

    bool res = false;
    for (int j = 1; j <= numbers[i]; j++) {
        if (array_stepper(i+j, numbers, memo)) {
            res = true;
            break;
        }
    }

    memo[i] = res;
    return res;
}

bool arrayStepper(vector<int> numbers) {
    unordered_map<int, bool> memo{};
    return array_stepper(0, numbers, memo);
}

bool arrayStepper_mine(vector<int> numbers) {
    int maxx = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (maxx < i) {
            return false;
        }

        maxx = max(maxx, i + numbers[i]);
    }

    return true;
}

void test_00() {
    bool res = arrayStepper(std::vector<int> {2, 4, 2, 0, 0, 1});
    bool passed = res == true;
    cout << "test_00: " << passed << endl;
}

int main(int argc, char *argv[]) {
    test_00();
}
