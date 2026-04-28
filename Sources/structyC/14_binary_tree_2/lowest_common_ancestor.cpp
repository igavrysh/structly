//
// Created by new on 4/28/26.
//


//
// Created by new on 4/27/26.
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

Node* dfs(Node *node, string& val1, string& val2) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->val == val1 || node->val == val2) {
        return node;
    }

    Node* l_res = dfs(node->left, val1, val2);
    Node* r_res = dfs(node->right, val1, val2);

    if (l_res != nullptr && r_res != nullptr) {
        return node;
    }

    return l_res != nullptr ? l_res : r_res;
}

string lowestCommonAncestor(Node *node, string val1, string val2) {
    return dfs(node, val1, val2)->val;
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
