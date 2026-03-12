//
//  pairSum.cpp
//  MyCLI
//
//  Created by new on 3/12/26.
//

#include <array>
#include <vector>
#include <unordered_map>

std::array<int, 2> pairSum(std::vector<int> numbers, int target) {
    std::unordered_map<int, int> m{};
    for (int i=0; i<numbers.size(); i++) {
        int num = numbers[i];
        int find = target - num;
        if (m.find(find) != m.end()) {
            return {m[find], i};
        }
        m[num] = i;
    }
    return {-1,-1};
}
