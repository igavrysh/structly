//
// Created by new on 5/7/26.
//

#include <string>
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

Node* dfs(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return node;
    }

    Node *l_res = dfs(node->left);
    Node *r_res = dfs(node->right);

    Node *res = nullptr;
    if (l_res == nullptr ) {
        res = r_res;
    } else if (r_res == nullptr) {
        node->right = node->left;
        node->left = nullptr;
        res = l_res;
    } else {
        Node *node_right_orig = node->right;
        node->right = node->left;
        node->left = nullptr;
        l_res->right = node_right_orig;
        res = r_res;
    }
    return res;
}

Node* flattenTree(Node* root) {
    dfs(root);
    return root;
}

void test_00() {
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f

   Node *res = flattenTree(&a); // ->
    //      a
    //       \
    //        b
    //         \
    //          d
    //           \
    //            e
    //            \
    //             c
    //              \
    //               f
    cout << "test_00: " << "done" << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
