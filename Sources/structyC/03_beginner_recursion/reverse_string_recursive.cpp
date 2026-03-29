//
//  reverse_string_recursive.h
//  MyCLI
//
//  Created by new on 3/14/26.
//

#include <string>

std::string reverseString(std::string s) {
    if (s.size() == 0) {
        return "";
    }
    return reverseString(std::string(s.begin()+1, s.end())) + s[0];
}
