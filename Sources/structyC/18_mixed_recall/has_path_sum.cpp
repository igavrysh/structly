//
// Created by new on 5/7/26.
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

bool hasPathSum(Node* root, int target) {
    if (root == nullptr) {
        return false;
    }

    const int val = target - root->val;

    if (root -> left == nullptr && root -> right == nullptr) {
        return val == 0;
    }

    return hasPathSum(root->left, val) || hasPathSum(root->right, val);
}