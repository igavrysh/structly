//
//  exclusiveItems.cpp
//  MyCLI
//
//  Created by new on 3/13/26.
//

#include <unordered_set>
#include <vector>

std::vector<int> exclusiveItems(std::vector<int> a, std::vector<int> b) {
    std::unordered_set<int> seta(a.begin(), a.end());
    std::unordered_set<int> setb(b.begin(), b.end());
    std::vector<int> res{};
    for (int x : a) {
        if (setb.count(x) == 0) {
            res.push_back(x);
        }
    }

    for (int x : b) {
        if (seta.count(x) == 0) {
            res.push_back(x);
        }
    }

    return res;
}

std::vector<int> exclusiveItems1(std::vector<int> a, std::vector<int> b) {
    std::unordered_set<int> excl{};
    for (int x : a) {
        excl.insert(x);
    }
    for (int x : b) {
        if (excl.find(x) != excl.end()) {
            excl.erase(x);
        } else {
            excl.insert(x);
        }
    }
    std::vector<int> res{};
    std::copy(excl.begin(), excl.end(), std::back_inserter(res));
    
    return res;
}
