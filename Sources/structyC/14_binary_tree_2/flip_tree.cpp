//
// Created by new on 4/28/26.
//

#include <string>
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
    std::string val;
    Node* left;
    Node* right;

    Node(string initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

Node* flipTree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    flipTree(root->left);
    flipTree(root->right);
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}

Node* sampleTree() {
    auto a = new Node("a");
    auto b = new Node("b");
    auto c = new Node("c");
    auto d = new Node("d");
    auto e = new Node("e");
    auto f = new Node("f");
    auto g = new Node("g");
    auto h = new Node("h");

    e->left = g;
    e->right = h;
    b->left = d;
    b->right = e;
    c->right = f;
    a->left = b;
    a->right = c;
    //      a
    //    /    \
    //   b      c
    //  / \      \
    // d   e      f
    //    / \
    //    g  h
    return a;
}

void test_00() {
    Node* root = sampleTree();
    string val1 = "d";
    string val2 = "h";
    const string res = lowestCommonAncestor(root, val1, val2);
    bool passed = res == "b";
    cout << "test_00: " << (passed ? "passed" : "failed" ) << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
