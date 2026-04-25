#include <string>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

string reverseSomeChars(string str, vector<char> chars) {
    unordered_set<char> chars_to_rev{};
    for (char ch : chars) {
        chars_to_rev.insert(ch);
    }
    stack<char> stack{};
    for (char ch : chars) {
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
