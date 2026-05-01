//
// Created by new on 4/30/26.
//

//
// Created by new on 4/30/26.
//

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<string>> permutations(vector<string> elements) {
    if (elements.empty()) {
        return {{}};
    }

    string el = elements[0];
    vector<string> elsWoEl(elements.begin() + 1, elements.end());
    vector<vector<string>> perms = permutations(elsWoEl);
    vector<vector<string>> res{};
    for (vector<string> r : perms) {
        for (int i = 0; i <= r.size(); i++) {
            vector<string> new_comb(r.begin(), r.end());
            new_comb.insert(new_comb.begin() + i, el);
            res.push_back(new_comb);
        }
    }
    return res;
}

vector<vector<string>> permutations_sel_val_for_pos(vector<string> elements) {
    if (elements.empty()) {
        return vector<vector<string>>{{}};
    }

    vector<vector<string>> res{};
    for (int i = 0; i < elements.size(); i++) {
        vector<string> elWo(elements.begin(), elements.end());
        elWo.erase(elWo.begin() + i);
        vector<vector<string>> r = permutations_sel_val_for_pos(elWo);
        for (vector<string>& perm : r) {
            perm.push_back(elements[i]);
            res.push_back(perm);
        }
    }

    return res;
}

void sort_2d(vector<vector<string>>& res) {
    for (vector<string>& r : res) {
        sort(r.begin(), r.end());
    }
    sort(res.begin(), res.end());
}

void test_00() {
    vector<vector<string>> res = permutations(vector<string> { "a", "b", "c" });
    sort_2d(res);
    vector<vector<string>> exp_res = {
        { "a", "b", "c" },
        { "b", "a", "c" }, 
        { "b", "c", "a" }, 
        { "a", "c", "b" }, 
        { "c", "a", "b" }, 
        { "c", "b", "a" }
    };
    sort_2d(exp_res);
    bool passed = res == exp_res;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    return 0;
}

