//
// Created by new on 4/12/26.
//

#include <string>
using namespace std;

bool isSubsequence(std::string string1, std::string string2) {
    int i = 0;
    int j = 0;
    while (i < string1.size() && j < string2.size()) {
        if (string1[i] == string2[j]) {
            i++;
        }
        j++;
    }

    return i == string1.size();
}