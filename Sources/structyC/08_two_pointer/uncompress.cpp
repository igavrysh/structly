//
//  uncompress.cpp
//  MyCLI
//
//  Created by new on 4/6/26.
//

#include <string>
#include <iostream>
using namespace std;

string uncompress(string s) {
    string res = "";
    char prev_char = '*';
    int code = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        int num = (int)(ch) - (int)'0';
        if (num >= 0 and num <= 9) {
            code = code * 10 + num;
        } else {
            while (code > 0) {
                res.push_back(ch);
                code--;
            }
            code = 0;
        }
    }

    return res;
}
