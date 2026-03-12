//
//  mostFrequentChar.h
//  MyCLI
//
//  Created by new on 3/11/26.
//

#include <iostream>
#include <string>
#include <unordered_map>

char mostFrequentChar(std::string s) {
    std::unordered_map<char, int> fqs;
    int max_fq = 0;

    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        fqs[*it] += 1;
        max_fq = std::max(max_fq, fqs[*it]);
    }
    // for (char ch : s) {}
    // for (char &ch : s) {}
    for (int i = 0; i < s.length(); i++) {
        if (fqs[s[i]] == max_fq) {
            return s[i];
        }
    }
    
    return '\0';
}
