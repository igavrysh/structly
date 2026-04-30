//
// Created by new on 4/29/26.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

void bt(int i, vector<string>& elements, vector<string> acc, vector<vector<string>>& result) {
    if (i >= elements.size()) {
        result.push_back(acc);
        return;
    }

    for (int j = i; j <= elements.size(); j++) {
        bool added = false;
        if (j != elements.size()) {
            acc.push_back(elements[j]);
            added = true;
        }
        bt(j + 1, elements, acc, result);
        if (added) {
            acc.pop_back();
        }
    }
}

vector<vector<string>> subsets(vector<string> elements) {
    vector<vector<string>> res{};
    bt(0, elements, vector<string>{}, res);
    return res;
}

void test_00() {
    vector<vector<string>> res = subsets(vector<string> { "a", "b" }); // ->
    vector<vector<string>> exp_res = vector<vector<string>> {
        {},
        {"b"},
        {"a"},
        {"a", "b"}
    };
    sort(res.begin(), res.end());
    sort(exp_res.begin(), exp_res.end());
    bool passed = res.size() == exp_res.size() && res == exp_res;
    cout << "test_00: " << (passed ? "passed" : "failed");
}

int main(int argc, char* argv[]) {
    test_00();
}

