#include <string>
#include <vector>
#include <unordered_set>
#include <stack>
#include <iostream>
using namespace std;

string reverseSomeChars(string str, vector<char> chars) {
    unordered_set<char> chars_to_rev(chars.begin(), chars.end());
    stack<char> stack{};
    for (char ch : str) {
        if (chars_to_rev.count(ch) > 0) {
            stack.push(ch);
        }
    }

    vector<char> result;
    for (char ch : str) {
        if (chars_to_rev.count(ch) > 0) {
            result.push_back(stack.top());
            stack.pop();
        } else {
            result.push_back(ch);
        }
    }

    return string(result.begin(), result.end());
}

void test_00() {
    string res = reverseSomeChars("computer", { 'a', 'e', 'i', 'o', 'u' });
    bool passed = res == "cemputor";
    cout << "test_00: " << (passed ? "passed" : "failed") << "; output: " << res << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    return 0;
}

