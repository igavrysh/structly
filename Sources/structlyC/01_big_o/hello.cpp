//
//  hello.c
//  MyCLI
//
//  Created by new on 3/4/26.
//

#include <iostream>

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
