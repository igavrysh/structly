//
// Created by new on 5/7/26.
//

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

string tokenTransform(string s, unordered_map<string, string> tokens) {
    string output;
    int i = 0;
    int j = 1;
    while (i < s.length()) {
        if (s[i] != '$') {
            output += s[i];
            i += 1;
            j = i + 1;
        } else if (s[j] != '$') {
            j += 1;
        } else {
            string key = s.substr(i, j-i+1);
            if (tokens.count(key) == 0) {
                return "";
            }
            s.replace(i, j-i+1, tokens[key]);
            j = i + 1;
        }
    }

    return output;
}

void test_00() {
    std::unordered_map<std::string, std::string> tokens {
      {"$LOCATION$", "$ANIMAL$ park"},
      {"$ANIMAL$", "dog"},
    };
    bool passed = tokenTransform("Walk the $ANIMAL$ in the $LOCATION$!", tokens) == "Walk the dog in the dog park!";
    // -> "Walk the dog in the dog park!"
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    std::unordered_map<std::string, std::string> tokens {
      {"$ADJECTIVE_1$", "quick"},
      {"$ADJECTIVE_2$", "eager"},
      {"$ADVERBS$", "$ADJECTIVE_1$ly and $ADJECTIVE_2$ly"},
      {"$VERB$", "hopped $DIRECTION$"},
      {"$DIRECTION$", "North"},
    };
    bool passed = tokenTransform("the $ADJECTIVE_1$ fox $ADVERBS$ $VERB$ward", tokens) == "the quick fox quickly and eagerly hopped Northward";
    // -> "the quick fox quickly and eagerly hopped Northward"
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

void test_02() {
    std::unordered_map<std::string, std::string> tokens {
      {"$B$", "epicly $C$"},
      {"$A$", "pretty $B$ problem $D$"},
      {"$D$", "we have"},
      {"$C$", "clever"},
    };
    bool passed = tokenTransform("What a $A$ here!", tokens) == "What a pretty epicly clever problem we have here!";
    // -> "What a pretty epicly clever problem we have here!"
    cout << "test_02: " << (passed ? "passed" : "failed") << endl;
}

void test_03() {
    std::unordered_map<std::string, std::string> tokens {
      {"$1$", "a$2$"},
      {"$2$", "b$3$"},
      {"$3$", "c$4$"},
      {"$4$", "d$5$"},
      {"$5$", "e$6$"},
      {"$6$", "f!"},
    };
    bool passed = tokenTransform("$1$ $1$ $1$ $1$ $1$ $1$ $4$ $4$", tokens) == "abcdef! abcdef! abcdef! abcdef! abcdef! abcdef! def! def!";
    // -> "abcdef! abcdef! abcdef! abcdef! abcdef! abcdef! def! def!"
    cout << "test_03: " << (passed ? "passed" : "failed") << endl;
}

void test_04() {
    std::unordered_map<std::string, std::string> tokens {
      {"$0$", "$1$$1$$1$$1$$1$$1$$1$$1$$1$$1$$1$$1$"},
      {"$1$", "$2$$2$$2$$2$$2$$2$$2$$2$$2$"},
      {"$2$", "$3$$3$$3$$3$$3$$3$$3$"},
      {"$3$", "$4$$4$$4$$4$$4$$4$"},
      {"$4$", "$5$$5$$5$$5$$5$"},
      {"$5$", "$6$$6$$6$$6$"},
      {"$6$", "$7$$7$$7$"},
      {"$7$", "$8$$8$"},
      {"$8$", ""},
    };
    bool passed = tokenTransform("z$0$z$0$z$0$z$0$z$0$z$0$z", tokens) == "zzzzzzz";
    // -> "zzzzzzz"
    cout << "test_04: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
    test_02();
    test_03();
    test_04();
}
