//
//  all_three_paths.h
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

void all_tree_paths(Node *node, std::vector<std::string> curr, std::vector<std::vector<std::string>>* res) {
    if (node == nullptr) {
        return;
    }

    curr.push_back(node->val);

    if (node->left == nullptr && node->right == nullptr) {
        res->push_back(curr);
    }

    if (node->left != nullptr) {
        all_tree_paths(node->left, curr, res);
    }

    if (node->right != nullptr) {
        all_tree_paths(node->right, curr, res);
    }
}

std::vector<std::vector<std::string>> allTreePaths(Node* root) {
    std::vector<std::vector<std::string>> res{};
    all_tree_paths(root, std::vector<std::string>{}, &res);

    return res;
}

