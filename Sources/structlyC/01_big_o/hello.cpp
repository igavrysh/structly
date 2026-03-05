//
//  hello.c
//  MyCLI
//
//  Created by new on 3/4/26.
//

#include <iostream>
#include <vector>        
#include <unordered_map>
#include <string>
#include <algorithm>
#include "structlyC.hpp"
#include "hello.hpp"

void run1() {
    int a = 4;
    int sum = a + 10;
    std::cout << "run1: ";
    std::cout << sum << std::endl;
}

void run2() {
    std::cout << "run2: ";
    std::string str = "hello";
    std::cout << str[1] << std::endl;
}

void run3() {
    std::unordered_map<char, int> stuff {
        { 'a', 1 },
        { 'b', 2 },
        { 'c', 3 }
    };
    std::cout << "run3(corresponding value for key b): " << stuff['b'] << std::endl;
}

void run4() {
    std::vector<std::string> colors {"red", "blue", "green", "yellow", "magenta"};
    bool found = std::find(colors.begin(), colors.end(), "green") != colors.end();
    std::cout << "run4: " << found << std::endl;
}

void run5() {
    std::vector<int> vec {5, 9, 2, -6, 12, 20, 30, 24};
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    std::cout << "run5: " << sum << std::endl;
}

void run6() {
    std::vector<std::string> letters {"a", "b", "c", "d", "e", "f"};
    for (int i = 0; i < letters.size(); i += 1) {
        for (int j = 0; j < letters.size(); j += 1) {
            std::cout << letters[i] + "," + letters[j] << std::endl;
        }
    }
}

void function1(int n) {
    std::cout << "function1: ";
    for (int i = 0; i < (n / 2); i += 1) {
        std::cout << i << std::endl;
    }
}

namespace StructlyBridge {

    std::vector<int> function2(int n) {
        std::vector<int> nums;
        for (int i = 1; i < n; i += 1) {
            nums.push_back(i);
        }
        return nums;
    }

    std::vector<int> function3(int n) {
        std::vector<int> nums;
        for (int i = 1; i < n; i += 1) {
            nums.insert(nums.begin(), i);
        }
        // Time: O(N^2)
        // [x, a, b, c, d]
        // [0, 1, 2, 3, 4]
        return nums;
    }

    void function4(std::vector<std::string> letters) {
        for (auto letter1 : letters) {
            for (auto letter2 : letters) {
                std::cout << letter1 + "," + letter2 << std::endl;
            }
        }
        
        for (auto letter : letters) {
            std::cout << letter << std::endl;
        }
    }
}

void run_cpp_logic() {
    std::cout << "Hello from C++ on " <<
        #ifdef __linux__
            "Linux!"
        #else
            "macOS!"
        #endif
        << std::endl;

    int a = 4;
    int sum = a + 10;
    std::cout << "Sum is: " << sum << std::endl;
}
