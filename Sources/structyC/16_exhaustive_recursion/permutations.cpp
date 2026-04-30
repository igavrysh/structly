//
// Created by new on 4/30/26.
//

#include <vector>
#include <string>
using namespace std;

vector<vector<string>> permutations(vector<string> elements) {
    if (elements.empty()) {
        return vector<vector<string>>{{}};
    }

    vector<vector<string>> res{};
    for (int i = 0; i < elements.size(); i++) {
        vector<string> elWo(elements.begin(), elements.end());
        elWo.erase(elWo.begin() + i);
        vector<vector<string>> r = permutations(elWo);
        for (vector<string>& perm : r) {
            perm.push_back(elements[i]);
            res.push_back(perm);
        }
    }

    return res;
}
