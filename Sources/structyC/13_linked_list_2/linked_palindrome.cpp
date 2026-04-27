//
// Created by new on 4/27/26.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(const int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

bool linkedPalindrome(Node* head) {
    vector<int> vals{};
    Node* node = head;
    while (node != nullptr) {
        vals.push_back(node->val);
        node = node->next;
    }
    std::vector<int> vals_rev(vals.begin(), vals.end());
    reverse(vals_rev.begin(), vals_rev.end());
    return vals == vals_rev;
}

void test_00() {
    Node a(3);
    Node b(2);
    Node c(7);
    Node d(7);
    Node e(2);
    Node f(3);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    // 3 -> 2 -> 7 -> 7 -> 2 -> 3
    bool res = linkedPalindrome(&a); // 1 (true)
    bool passed = res == true;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
