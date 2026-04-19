//
// Created by new on 4/12/26.
//

#include <string>
#include <iostream>
using namespace std;

string compress(string s) {
    string res = "";
    int i = 0;
    for (int j = 0; j <= s.length(); j++) {
        if (j < s.length() && s[i] == s[j]) {
            continue;
        }

        if (j-i > 1) {
            res.append(to_string(j-i));
        }
        res.push_back(s[i]);
        i = j;
    }

    return res;
}


void compress_test_00() {
    string res = compress("ccaaatsss"); // -> "2c3at3s"
    cout << "res: " << res << endl;
}

int main(int argc, char *argv[]) {
    compress_test_00();
}
