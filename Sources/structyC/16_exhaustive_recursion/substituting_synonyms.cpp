//
// Created by new on 5/3/26.
//

#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

namespace exh_rec_16_subst_synonyms {
typedef vector<reference_wrapper<const string>> v_s;
typedef vector<vector<reference_wrapper<const string>>> vv_s;

vector<string> split(const string& str) {
    vector<string> res;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        res.push_back(word);
    }
    return res;
}

vv_s bt(int i, vector<string>& strs, unordered_map<string, vector<string>>& synonyms) {
    if (i == strs.size()) {
        return {{}};
    }

    vv_s res = bt(i+1, strs, synonyms);
    vv_s res2{};

    if (synonyms.count(strs[i]) == 0) {
        for (v_s& phrase : res) {
            phrase.push_back(ref(strs[i]));
            res2.push_back(phrase);
        }
    } else {
        for (string& syn : synonyms[strs[i]]) {
            for (v_s phrase : res) {
                phrase.push_back(syn);
                res2.push_back(phrase);
            }
        }
    }

    return res2;
}

string join(const v_s& phrase) {
    ostringstream ss;
    for (int i = 0; i < phrase.size(); i++) {
        ss << phrase[i].get();
        if (i < phrase.size() - 1) {
            ss << " ";
        }
    }

    return ss.str();
}

vector<string> substituteSynonyms(string sentence, unordered_map<string, vector<string>> synonyms) {
    vector<string> strs = split(sentence);
    vv_s res = bt(0, strs, synonyms);
    vector<string> output{};
    for (v_s& phrase : res) {
        reverse(phrase.begin(), phrase.end());
        output.push_back(join(phrase));
    }

    return output;
}

void test_00() {
    string sentence = "follow the yellow brick road";
    unordered_map<std::string, std::vector<std::string>> synonyms {
      { "follow", {"chase", "pursue"} },
      { "yellow", {"gold", "amber", "lemon"} }
    };

    vector<string> res = substituteSynonyms(sentence, synonyms);
    sort(res.begin(), res.end());
    vector<string> exp_res = {
        "chase the gold brick road",
        "chase the amber brick road",
        "chase the lemon brick road",
        "pursue the gold brick road",
        "pursue the amber brick road",
        "pursue the lemon brick road"
    };
    sort(exp_res.begin(), exp_res.end());
    bool passed = res == exp_res;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
}
