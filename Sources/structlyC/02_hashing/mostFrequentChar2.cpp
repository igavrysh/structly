//
//  mostFrequentChar2.cpp
//  MyCLI
//
//  Created by new on 3/12/26.
//

#include <string>
#include <unordered_map>

char mostFrequentChar2(std::string s) {
    std::unordered_map<char, int> count;
    for (int i=0; i<s.length(); i++) {
        count[s[i]] += 1;
    }
    char best = '\0';
    for (int i=0; i<s.length(); i++) {
        if (best == '\0' || count[best] < count[s[i]]) {
            best = s[i];
        }
    }
    
    return best;
}
