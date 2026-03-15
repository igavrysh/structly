//
//  inserttionWithDupes.cpp
//  MyCLI
//
//  Created by new on 3/13/26.
//

#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::string> intersectionWithDupes(std::vector<std::string> a, std::vector<std::string> b) {
    std::unordered_map<std::string, int> map{};
    for (std::string str : a) {
        map[str]++;
    }

    std::vector<std::string> res{};

    for (std::string str : b) {
        if (map[str] > 0) {
            res.push_back(str);
            map[str]--;
        }
    }

    return res;
}
