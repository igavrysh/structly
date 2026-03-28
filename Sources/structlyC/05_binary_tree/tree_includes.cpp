//
//  tree_includes.h
//  MyCLI
//
//  Created by new on 3/24/26.
//

#include <string>
#include <queue>

class Node {
public:
    std::string val;
    Node* left;
    Node* right;
    
    Node(std::string initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

bool treeIncludes(Node* node, std::string targetVal) {
    if (node == nullptr) {
        return false;
    }

    return node->val == targetVal || treeIncludes(node->left, targetVal) || treeIncludes(node->right, targetVal);
}

bool treeIncludes1(Node* root, std::string targetVal) {
    std::queue<Node*> q;
    if (root != nullptr) {
        q.push(root);
    }
    while (q.size() > 0) {
        Node* node = q.front();
        q.pop();
        if (node->val == targetVal) {
            return true;
        }
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }

    return false;
}
