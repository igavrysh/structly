//
//  pairSum2.h
//  MyCLI
//
//  Created by new on 3/12/26.
//

#include <array>
#include <vector>
#include <unordered_map>

std::array<int, 2> pairSum2(std::vector<int> numbers, int target) {
    std::unordered_map<int, int> m{};
    for (int i=0; i<numbers.size(); i++) {
        int num = numbers[i];
        int complement = target - num;
        if (m.find(complement) != m.end()) {
            return std::array<int, 2>{m[complement], i};
        }
        m[num] = i;
    }

    return {-1,-1};
}
