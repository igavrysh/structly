//
//  tree_sum.cpp
//  MyCLI
//
//  Created by new on 3/24/26.
//

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

int treeSum1(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->val
        + (root->left != nullptr ? treeSum1(root->left) : 0)
        + (root->right != nullptr ? treeSum1(root->right) : 0);
}
