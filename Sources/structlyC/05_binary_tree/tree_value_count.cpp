//
//  tree_value_count.cpp
//  MyCLI
//
//  Created by new on 3/27/26.
//

#include <unordered_map>
#include <queue>

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

int treeValueCount(Node* root, int targetVal) {
    int fq = 0;
    std::queue<Node*> q{};
    if (root != nullptr) {
        q.push(root);
    }
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->val == targetVal) {
            fq++;
        }
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    return fq;
}
