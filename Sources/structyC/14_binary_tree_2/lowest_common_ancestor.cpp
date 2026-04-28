//
// Created by new on 4/27/26.
//
#include <string>
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    string val;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    explicit Node(string v) : val(std::move(v)), left(nullptr), right(nullptr) {}
};

Node* dfs(Node *node, string& val1, string& val2) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->val == val1 || node->val == val2) {
        return node;
    }

    Node* l_res = dfs(node->left.get(), val1, val2);
    Node* r_res = dfs(node->right.get(), val1, val2);

    if (l_res != nullptr && r_res != nullptr) {
        return node;
    }

    return l_res != nullptr ? l_res : r_res;
}

string lowestCommonAncestor(Node *node, string& val1, string& val2) {
    return dfs(node, val1, val2)->val;
}

unique_ptr<Node> sampleTree() {
    auto a = make_unique<Node>("a");
    auto b = make_unique<Node>("b");
    auto c = make_unique<Node>("c");
    auto d = make_unique<Node>("d");
    auto e = make_unique<Node>("e");
    auto f = make_unique<Node>("f");
    auto g = make_unique<Node>("g");
    auto h = make_unique<Node>("h");

    e->left = std::move(g);
    e->right = std::move(h);
    b->left = std::move(d);
    b->right = std::move(e);
    c->right = std::move(f);
    a->left = std::move(b);
    a->right = std::move(c);
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
    const unique_ptr<Node> root = sampleTree();
    string val1 = "d";
    string val2 = "h";
    const string res = lowestCommonAncestor(root.get(), val1, val2);
    bool passed = res == "b";
    cout << "test_00: " << (passed ? "passed" : "failed" ) << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
