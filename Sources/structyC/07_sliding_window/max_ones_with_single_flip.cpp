//
// Created by new on 4/11/26.
//

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int maxOnesWithSingleFlip(std::string s) {
    int last_zero = -1;
    int l = 0;
    int longest = 0;
    for (int r = 0; r < s.size(); r++) {
        if (s[r] == '0') {
            l = last_zero + 1;
            last_zero = r;
        }
        longest = max(longest, r-l+1);
    }
    return longest;
}

void test_00() {
    int res = maxOnesWithSingleFlip("10110110");
    bool passed = res == 5;
    cout << "test_00: "<< (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_01() {
    int res = maxOnesWithSingleFlip("011101101111");
    bool passed = res == 7;
    cout << "test_01: "<< (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_02() {
    int res = maxOnesWithSingleFlip("111");
    bool passed = res == 3;
    cout << "test_02: "<< (passed ? "passed" : "failed") << "; res: " << res << endl;
}

int main(int argc, char *argv[]) {
    test_00();
    test_01();
    test_02();
}
