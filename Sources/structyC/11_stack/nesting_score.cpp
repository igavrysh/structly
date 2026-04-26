#include <string>
#include <stack>
#include <iostream>
using namespace std;

int nestingScore(string str) {
    stack<string> stck{};
    str = "[" + str + "]";
    for (char ch : str) {
        if (ch == '[') {
            stck.push(string(1, ch));
            continue;
        }

        if (stck.top() == "[") {
            stck.pop();
            stck.push("1");
            continue;
        }

        int res = 0;
        while (stck.top() != "[") {
            res += stoi(stck.top());
            stck.pop();
        }
       
        res = res * 2;
        stck.pop();
        stck.push(to_string(res));
    }

    return stoi(stck.top()) / 2;
}

void test_00() {
    int res = nestingScore("[]");
    bool passed = res == 1;
    cout << "test_00: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_01() {
    int res = nestingScore("[][][]");
    bool passed = res == 3;
    cout << "test_01: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_02() {
    int res = nestingScore("[[]]");
    bool passed = res == 2;
    cout << "test_02: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_03() {
    int res = nestingScore("[[][]]");
    bool passed = res == 4;
    cout << "test_03: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_04() {
    int res = nestingScore("[[][][]]");
    bool passed = res == 6;
    cout << "test_04: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_05() {
    int res = nestingScore("[[][]][]");
    bool passed = res == 5;
    cout << "test_05: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    return 0;
}
