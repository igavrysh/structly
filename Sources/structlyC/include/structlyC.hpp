//
//  structlyC.h
//  MyCLI
//
//  Created by new on 3/4/26.
//

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void run_cpp_logic();
void run1();
void run2();
void run3();
void run4();

#ifdef __cplusplus
}
#endif

struct CalculatorCpp {
    inline int add(int a, int b) {
        return a + b;
    }
};
