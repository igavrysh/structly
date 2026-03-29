//
//  unorderedSet.h
//  MyCLI
//
//  Created by new on 3/12/26.
//

#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int> a, std::vector<int> b) {
    std::unordered_set<int> set{};
    for (int x : b) {
        set.insert(x);
    }
    std::vector<int> res{};
    for (int x : a) {
        if (set.find(x) != set.end()) {
            res.push_back(x);
        }
    }
    return res;
}
