//
//  allUnique.h
//  MyCLI
//
//  Created by new on 3/13/26.
//

#include <vector>
#include <string>
#include <unordered_set>

bool allUnique(std::vector<std::string> items) {
    std::unordered_set<std::string> set(items.begin(), items.end());
    return set.size() == items.size();
}
