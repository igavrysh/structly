//
//  leaf_list.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
//

#include <vector>
#include <string>

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

void fill_leaves(Node *node, std::vector<std::string>& leaves) {
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        leaves.push_back(node->val);
        return;
    }

    fill_leaves(node->left, leaves);
    fill_leaves(node->right, leaves);
}

std::vector<std::string> leafList(Node* root) {
    std::vector<std::string> leaves;
    fill_leaves(root, leaves);

    return leaves;
}
