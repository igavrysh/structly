//
// Created by new on 5/3/26.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace bt_16_parenth_possibl {
vector<string> bt(string str, int i_start) {
    int start = -1;
    int end = -1;
    for (int i = i_start; i < str.length(); i++) {
        if (str[i] == '(') {
            start = i;
        }
        if (str[i] == ')') {
            end = i;
            break;
        }
    }

    if (start == -1) {
        return { str.substr(i_start) };
    }

    string prefix = str.substr(i_start, (start-1)-i_start+1);
    vector<string> res = {};
    vector<string> subres = bt(str, end+1);
    for (int i = start+1; i < end; i++) {
        for (string subres_suffix : subres) {
            res.push_back(prefix + str[i] + subres_suffix);
        }
    }

    return res;
}

vector<string> parentheticalPossibilities(string str) {
    return bt(str, 0);
}

void test_01() {
    vector<string> res = parentheticalPossibilities("(qr)ab(stu)c");
    vector<string> exp_res = {
        "qabsc", "qabtc", "qabuc", "rabsc", "rabtc", "rabuc"
    };
    sort(res.begin(), res.end());
    sort(exp_res.begin(), exp_res.end());
    bool passed = res == exp_res;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_01();
}
}
