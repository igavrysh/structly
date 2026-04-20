#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

bool valid_compound(int i, string& compound, vector<string>& elements, unordered_map<int, bool>& memo) {
    if (compound.size() == 0) {
        return true;
    }

    if (memo.count(i) > 0) {
        return memo[i];
    }

    for (string el : elements) {
        if (compound.find(el) != 0) {
            continue;
        }
        string suffix = compound.substr(el.size());
        bool res = valid_compound(i + el.size(), suffix, elements, memo);
        if (res) {
            memo[i] = res;
            return res;
        }
    }

    memo[i] = false;
    return false;
}

bool validCompound(string compound, vector<string> elements) {
    vector<string> lowercased_els{};
    for (string el : elements) {
        transform(el.begin(), el.end(), el.begin(), [](unsigned char c){ return std::tolower(c); });
        lowercased_els.push_back(el);
    }
    unordered_map<int, bool> memo;
    return valid_compound(0, compound, lowercased_els, memo);
}

void test_00() {
    string compund = "neco";
    vector<string> elements{  "Ne",
        "O",
        "Be",
        "I",
        "N",
        "Os",
        "Si",
        "S",
        "Co",
        "C",
        "Ir"};
    bool res = validCompound(compund, elements);
    bool passed = res == true;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    string compound = "nerco";
    vector<string> elements{
        "Ne",
        "O",
        "Be",
        "I",
        "N",
        "Os",
        "Si",
        "S",
        "Co",
        "C",
        "Ir"
    };
    bool res = validCompound(compound, elements);
    bool passed = res == false;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char const *argv[]) {
    test_01();
    return 0;
}
