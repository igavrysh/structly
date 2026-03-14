//
//  sum_of_lengths.h
//  MyCLI
//
//  Created by new on 3/14/26.
//

#include <vector>
#include <string>

int sumOfLengths_helper(int i, int acc, std::vector<std::string> strings) {
    if (i == strings.size()) {
        return acc;
    }
    return sumOfLengths_helper(i+1, acc + strings[i].size(), strings);
}

int sumOfLengths(std::vector<std::string> strings) {
  return sumOfLengths_helper(0, 0, strings);
}
