//
// Created by new on 5/1/26.
//

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

namespace bt_16_lining_up {
vector<vector<string>> liningUp(vector<string> people, int capacity)
{
    if (capacity > people.size()) {
        return {};
    }
    
    if (capacity == 0) {
        return {{}};
    }
    
    string person = people[0];
    vector<string> people_wo(people.begin() + 1, people.end());
    vector<vector<string>> comb_1 = liningUp(people_wo, capacity);
    vector<vector<string>> comb_2 = liningUp(people_wo, capacity - 1);
    for (vector<string>& comb : comb_2) {
        for (int i = 0; i <= comb.size(); i++) {
            vector<string> to_insert(comb.begin(), comb.end());
            to_insert.insert(to_insert.begin() + i, person);
            comb_1.push_back(to_insert);
        }
    }
    
    return comb_1;
}

void bt(vector<string> acc,
        vector<string> people, vector<vector<string>>& res, int capacity)
{
    if (acc.size() == capacity) {
        res.push_back(acc);
        return;
    }
    
    for (int i = 0; i < people.size(); i++) {
        vector<string> people_wo(people.begin(), people.end());
        people_wo.erase(people_wo.begin() + i);
        acc.push_back(people[i]);
        bt(acc, people_wo, res, capacity);
        acc.pop_back();
    }
}

vector<vector<string>> liningUp_mine(vector<string> people, int capacity) {
    vector<vector<string>> res{};
    bt(vector<string>{}, people, res, capacity);
    return res;
}

void test_01() {
    vector<vector<string>> res = liningUp({"autumn", "anj", "aud"}, 2); // ->
    vector<vector<string>> exp_res = {
        { "autumn", "anj" },
        { "anj", "autumn" },
        { "autumn", "aud" },
        { "aud", "autumn" },
        { "anj", "aud" },
        { "aud", "anj" }
    };
    cout << "test_01: ";
    sort(res.begin(), res.end());
    sort(exp_res.begin(), exp_res.end());
    bool passed = res == exp_res;
    for (vector<string>& res : res) {
        for (string& str : res) {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_01();
}
}
