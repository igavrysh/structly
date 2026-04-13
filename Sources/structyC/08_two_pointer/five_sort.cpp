//
// Created by new on 4/12/26.
//

#include <vector>
using namespace std;

vector<int>& fiveSort(vector<int> &numbers) {
    int i = 0;
    int j = numbers.size() - 1;
    for (int i = 0; i < numbers.size(); i++) {
        if (i == j) {
            break;
        }
        if (numbers[i] != 5) {
            continue;
        }

        while (numbers[j] == 5 && i < j) {
            j--;
        }

        int tmp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = tmp; // all 5's
    }

    return numbers;
}