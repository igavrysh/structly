//
//  binary_tree_warmup.cpp
//  MyCLI
//
//  Created by new on 3/23/26.
//

#include <string>

class Node {
public:
    Node* left;
    Node* right;
    std::string val;

    Node(std::string initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

void run() {
    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");
    Node e("E");
    Node f("F");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
}

/*
 A
 / \
 B  C
 / \   \
 D   E    F
 */

