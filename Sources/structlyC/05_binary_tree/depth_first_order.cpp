//
//  depth_first_order.cpp
//  MyCLI
//
//  Created by new on 3/23/26.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>

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

std::vector<std::string> depthFirstValues(Node* root) {
    std::vector<std::string> res{};
    if (root == nullptr) {
        return res;
    }

    std::stack<Node*> stack{};
    stack.push(root);
    while (stack.size() > 0) {
        Node* node = stack.top();
        stack.pop();
        res.push_back(node->val);
        if (node->right != nullptr) {
            stack.push(node->right);
        }
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }

    return res;
}


std::vector<std::string> depthFirstValues1(Node* root) {
    if (root == nullptr) {
        return std::vector<std::string>();
    }

    std::vector<std::string> left = depthFirstValues(root->left);
    std::vector<std::string> right = depthFirstValues(root->right);
    left.insert(left.begin(), root->val);
    for (std::vector<std::string>::iterator it = right.begin(); it != right.end(); it++) {
        left.push_back(*it);
    }

    return left;
}

