//
//  anagrams.cpp
//  MyCLI
//
//  Created by new on 3/10/26.
//

#include <iostream>
#include <unordered_map>

bool anagrams(std::string s1, std::string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    std::unordered_map<char, int> fqs;
    int cntr = 0;
    for (char c : s1) {
        fqs[c] += 1;
        cntr++;
    }
    for (char c : s2) {
        if (fqs[c] == 0) {
            return false;
        }
        fqs[c]--;
        cntr--;
    }
    return true;
}


void test_00() {
    bool res = anagrams("restful", "fluster");
    bool exp_res = true;
    bool passed = res == exp_res;
    std::cout << "test_00: " << (passed ? "passed" : "failed") << std::endl;
}

void test_01() {
    bool res = anagrams("cats", "tocs");
    bool exp_res = false;
    bool passed = res == exp_res;
    std::cout << "test_01: " << (passed ? "passed" : "failed") << std::endl;
}

void testAnagrams() {
    test_00();
    test_01();
}
