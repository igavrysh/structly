//
// Created by new on 4/30/26.
//

#include <vector>
#include <string>
using namespace std;

void create_combinations(int i, vector<string>& acc, vector<string>& els, vector<vector<string>>& res, int size) {
    if (acc.size() == size) {
        res.push_back(acc);
        return;
    }

    for (int j = i; j < els.size(); j++) {
        vector<string> next_acc(acc.begin(), acc.end());
        next_acc.push_back(els[j]);
        create_combinations(j+1, next_acc, els, res, size);
    }
}

vector<vector<string>> createCombinations(vector<string> items, int size) {
    vector<vector<string>> res{};
    vector<string> acc{};
    create_combinations(0, acc, items, res, size);;
    return res;
}
