//
//  structlyC.h
//  MyCLI
//
//  Created by new on 3/4/26.
//

#pragma once

#ifndef STRUCTLY_C_HPP
#define STRUCTLY_C_HPP

#include <vector>
#include <string>
#include <iostream>

void run_cpp_logic();
void run1();
void run2();
void run3();
void run4();
void run5();
void run6();
void function1(int n);

// These are only visible to other C++ files, not to Swift/C
//std::vector<int> function2(int n);
//std::vector<int> function3(int n);
//void function4(std::vector<std::string> letters);

namespace StructlyBridge {
    std::vector<int> function2(int n);
    std::vector<int> function3(int n);
    void function4(std::vector<std::string> letters);
}

struct CalculatorCpp {
    inline int add(int a, int b) {
        return a + b;
    }
};

#endif /* STRUCTLY_C_HPP */
