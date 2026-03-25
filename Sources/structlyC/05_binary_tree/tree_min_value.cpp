//
//  treeminvalue.cpp
//  MyCLI
//
//  Created by new on 3/25/26.
//

#include <algorithm>
#include <cmath>
#include <limits>

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

int treeMinValue(Node* root) {
    if (root == nullptr) {
        return std::numeric_limits<int>::infinity();
    }

    return std::min(std::min(root->val, treeMinValue(root->left)), treeMinValue(root->right));
}
