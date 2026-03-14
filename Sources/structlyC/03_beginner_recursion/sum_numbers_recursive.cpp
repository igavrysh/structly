//
//  sum_numbers_recursive.cpp
//  MyCLI
//
//  Created by new on 3/14/26.
//

#include <vector>

int sumNumbersRecursive(std::vector<int> numbers) {
    if (numbers.size() == 0) {
        return 0;
    }
    return numbers[0] + sumNumbersRecursive(std::vector<int>(numbers.begin()+1, numbers.end()));
}

int sum(int i, int total, std::vector<int> numbers) {
    if (i == numbers.size()) {
        return total;
    }
    return sum(i+1, total + numbers[i], numbers);
}

int sumNumbersRecursive1(std::vector<int> numbers) {
    return sum(0, 0, numbers);
}

