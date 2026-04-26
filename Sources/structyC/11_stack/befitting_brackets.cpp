#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool befittingBrackets(string str) {
    vector<char> ob = {'{', '(', '[', '}', ')', ']'};
    unordered_set<char> all_brackets(ob.begin(), ob.end());
    unordered_map<char, char> brackets = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
    stack<char> stck{};
    for (char ch : str) {
        if (brackets.count(ch) > 0) {
            stck.push(brackets[ch]);
        } else {
            if (all_brackets.count(ch) == 0) {
                continue;
            }

            if (stck.size() == 0) {
                return false;
            }
            
            char front = stck.top();
            stck.pop();
            if (ch != front) {
                return false;
            }
        }
    }

    return stck.size() == 0;
}
