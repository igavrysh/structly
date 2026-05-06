//
// Created by new on 5/6/26.
//

#include <vector>
using namespace std;

vector<int> prefixProduct(vector<int> numbers) {
    for (int i = 1; i < numbers.size(); i++) {
        numbers[i] = numbers[i] * numbers[i-1];
    }
    return numbers;
}