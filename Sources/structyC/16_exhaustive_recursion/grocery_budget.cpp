//
// Created by new on 5/1/26.
//

#include <vector>
#include <string>
#include <tuple>
using namespace std;

vector<vector<string>> groceryBudget(vector<tuple<string, int>> groceryList, int budget) {
    if (budget < 0) {
        return {};
    }

    if (groceryList.empty()) {
        return {{}};
    }

    tuple<string, int> current = groceryList[0];
    vector<tuple<string, int>> grocery_list_wo(groceryList.begin() + 1, groceryList.end());
    vector<vector<string>> res = groceryBudget(grocery_list_wo, budget);
    vector<vector<string>> res_with_el = groceryBudget(grocery_list_wo, budget - get<1>(current));
    for (vector<string>& comb : res_with_el) {
        comb.push_back(get<0>(current));
        res.push_back(comb);
    }

    return res;
}