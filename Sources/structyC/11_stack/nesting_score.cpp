#include <string>
#include <stack>
#include <iostream>
using namespace std;

/*
[]
stck:
i:0 stck:[0]
i:1 
*/
int nestingScore(string str) {
    stack<int> stck{};
    stck.push(0);
    for (char ch : str) {
        if (ch == '[') {
            stck.push(0);
            continue;
        }
        int top = stck.top();
        stck.pop();
        if (top == 0) {
            stck.top() += 1;
        } else {
            stck.top() += top * 2;
        }
    }
    return stck.top();
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

void test_06() {
    int res = nestingScore("[][[][]][[]]");
    bool passed = res == 7;
    cout << "test_06: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_07() {
    int res = nestingScore("[[[[[[[][]]]]]]][]");
    bool passed = res == 129;
    cout << "test_07: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_08() {
    int res = nestingScore("");
    bool passed = res == 0;
    cout << "test_08: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();
    test_08();
    return 0;
}
