//
// Created by new on 4/28/26.
//

#include <vector>
using namespace std;

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

void dfs(Node *node, vector<int>& res) {
    if (node == nullptr) {
        return;
    }
    dfs(node->left, res);
    res.push_back(node->val);
    dfs(node->right, res);
}

bool isBinarySearchTree(Node* root) {
    vector<int> res{};
    dfs(root, res);
    for (int i = 1; i < res.size()-1; i++) {
        if (res[i] <= res[i-1]) {
            return false;
        }
    }

    return true;
}

int dfs_logn_space(Node* node, bool is_left, vector<bool>& res) {
    if (res.size() != 0) {
        return -1;
    }

    int leftVal = node->val;
    if (node->left != nullptr) {
        leftVal = dfs_logn_space(node->left, true, res);
        if (node->val <= leftVal) {
            res.push_back(false);
            return -1;
        }
    }
    int rightVal = node->val;
    if (node->right != nullptr) {
        rightVal = dfs_logn_space(node->right, false, res);
        if (node->val > rightVal) {
            res.push_back(false);
            return -1;
        }
    }

    return is_left ? rightVal : leftVal;
}

bool isBinarySearchTree_logn_space(Node* root) {
    vector<bool> res{};
    if (root == nullptr) return true;
    dfs(root, true, res);
    return res.size() == 0;
}
