//
// Created by new on 4/30/26.
//

#include <vector>
#include <string>
using namespace std;

vector<vector<string>> createCombinations(vector<string> items, int size) {
    if (size == 0) {
        return {{}};
    }
    if (items.empty()) {
        return {};
    }

    string elem = items[0];
    vector<string> itemswo(items.begin() + 1, items.end());
    vector<vector<string>> res = createCombinations(itemswo, size);
    vector<vector<string>> res_size_reduced = createCombinations(itemswo, size-1);
    for (vector<string> str : res_size_reduced) {
        str.push_back(elem);
        res.push_back(str);
    }

    return res;
}

void create_combinations_optimized(int i, vector<string>& acc, vector<string>& els, vector<vector<string>>& res, int size) {
    if (acc.size() == size) {
        res.push_back(acc);
        return;
    }

    for (int j = i; j < els.size(); j++) {
        vector<string> next_acc(acc.begin(), acc.end());
        next_acc.push_back(els[j]);
        create_combinations_optimized(j+1, next_acc, els, res, size);
    }
}

vector<vector<string>> createCombinationsOpt(vector<string> items, int size) {
    vector<vector<string>> res{};
    vector<string> acc{};
    create_combinations_optimized(0, acc, items, res, size);;
    return res;
}
