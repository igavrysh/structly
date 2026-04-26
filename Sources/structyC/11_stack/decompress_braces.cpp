#include <string>
#include <stack>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

string decompressBraces(string str) {
    stack<int> nums;
    stack<vector<char>> strs{};
    nums.push(1);
    strs.push(vector<char>{});
    for (char ch : str) {
        if (isalpha(ch)) {
            strs.top().push_back(ch);
        } else if (isdigit(ch)) {
            nums.push(ch - '0');
            strs.push(vector<char>{});
        } else if (ch == '{') {
            // only signle digit repeats
        } else if (ch == '}') {
            int num = nums.top();
            nums.pop();
            vector<char> curr_str = strs.top();
            strs.pop();
            int original_size = curr_str.size();
            vector<char>& target = strs.top();
            for (int i = 0; i < num; i++) {
                for (int j = 0; j < original_size; j++) {
                    target.push_back(curr_str[j]);
                }
            }
        }
    }
    vector<char> res = strs.top();
    return string(res.begin(), res.end());
}

void test_00() {
    string res = decompressBraces("2{q}3{tu}v");
    bool passed = res == "qqtututuv";
    cout << "test_00: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

void test_04() {
    string res = decompressBraces("2{3{r4{e}r}io}"); 
    bool passed = res == "reeeerreeeerreeeerioreeeerreeeerreeeerio";
    cout << "test_04: " << (passed ? "passed" : "failed") << "; res: " << res << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    test_04();
    return 0;
}
