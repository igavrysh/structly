//
//  is_palindrome.cpp
//  MyCLI
//
//  Created by new on 4/6/26.
//

#include <string>

bool isPalindrome(std::string s) {
    int l = 0;
    int r = (int)s.length() -1 ;
    while (l<r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    
    return true;
}
