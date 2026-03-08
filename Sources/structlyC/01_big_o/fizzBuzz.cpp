//
//  fizzBuzz.hpp
//  MyCLI
//
//  Created by new on 3/7/26.
//

#include <vector>
#include <string>
#include <cassert>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> res(n);
    for (int i=0;i<n;i++) {
        std::string r("");
        if (i%3==0) {
            r.append("fizz");
        }
        if (i%5==0) {
            r.append("buzz");
        }
        if (r.size()==0) {
            r.append(std::to_string(i+1));
        }
        res.push_back(r);
    }
    return res;
}

bool assert_vectors_equal(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    return a == b;
}

void fizzbuzz_test1() {
//    std::vector<std::string> output = fizzBuzz(11);
//    std::vector<std::string> exp_output = {"1","2","fizz","4","buzz","fizz","7","8","fizz","buzz","11"};
//    assert(assert_vectors_equal(exp_output, output)==true);
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
