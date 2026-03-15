//
//  longestString.hpp
//  MyCLI
//
//  Created by new on 3/6/26.
//

#include <string>
#include <limits>
#include <sstream>

std::string longestWord(std::string sentence) {
    std::stringstream ss(sentence);
    int max_len = -1;
    std::string res = "";
    std::string word;
    while (ss >> word) {
        if (word.length() >= res.length()) {
            res = word;
        }
    }
    return res;
}
