//
//  palingrome.cpp
//  MyCLI
//
//  Created by new on 3/14/26.
//

#include <string>

bool is_p(std::string s, int l, int r, bool res) {
    if (!res) {
        return false;
    }
    if (l>=r) {
        return true;
    }
    return is_p(s, l+1, r-1, s[l]==s[r] && res);
}

bool palindrome(std::string s) {
    return is_p(s, 0, (int)s.size()-1, true);
}
