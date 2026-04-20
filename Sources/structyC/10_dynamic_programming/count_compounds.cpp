#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;

int count_compounds(int i, string& compound, vector<string>& elements, unordered_map<int, int>& memo) {
    if (compound.size() == 0) {
        return 1;
    }

    if (memo.count(i) > 0) {
        return memo[i];
    }

    int res = 0;
    for (string& el : elements) {
        if (compound.find(el) != 0) {
            continue;
        }
        string suffix = compound.substr(el.size());
        res += count_compounds(i+ el.size(), suffix, elements, memo);
    }

    memo[i] = res;

    return res;
}

void to_lowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });
}

int countCompounds(string compound, vector<string> elements) {
    vector<string> lowercased_els{};
    for (string el : elements) {
        to_lowercase(el);
        lowercased_els.push_back(el);
    }
    unordered_map<int, int> memo{};

    int res = count_compounds(0, compound, lowercased_els, memo);

    return res;
}

void test_00() {
    int res = countCompounds("neco", {
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
    });
    bool passed = res == 2;
    cout << "test_00: " << (passed ? "passed" : "failed") << ";res:" << res << endl;
}

void test_01() {
    int res = countCompounds("nerco", {
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
        }); 
    bool passed = res == 0;
    cout << "test_01: " << (passed ? "passed" : "failed") << ";res:" << res << endl;
}

void test_02() {
    int res = countCompounds("sir", {
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
        }); // -> 1
    bool passed = res == 1;
    cout << "test_02: " << (passed ? "passed" : "failed") << ";res:" << res << endl;
}

void test_03() {
    int res = countCompounds("hocli", {
        "C",
        "Cl",
        "I",
        "Ho",
        "Li",
        "La",
        "H",
        "O"
        }); // -> 4
    bool passed = res == 4;
    cout << "test_03: " << (passed ? "passed" : "failed") << ";res:" << res << endl;
}

void test_04() {
    int res = countCompounds("noses", {
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
        }); // -> 0
    bool passed = res == 0;
    cout << "test_04: " << (passed ? "passed" : "failed") << ";res:" << res << endl;
}

void test_06() {
    int res = countCompounds("necoonbeinos", {
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
    }); // -> 4
    bool passed = res == 4;
    cout << "test_06: " << (passed ? "passed" : "failed") << ";res:" << res << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    test_01();
    test_02();
    test_03();
    test_04();
    test_06();

    return 0;
}

