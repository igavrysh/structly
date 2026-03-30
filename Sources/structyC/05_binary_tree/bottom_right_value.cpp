//
//  bottom_right_value.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
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

std::string bottomRightValue(Node* root) {
    std::queue<Node*> q;
    if (root != nullptr) {
        q.push(root);
    }
    std::string last;
    while (q.size() > 0) {
        auto lev_size = q.size();
        for (int i = 0; i < lev_size; i++) {
            Node* node = q.front();
            q.pop();
            if (i == lev_size-1) {
                last = node->val;
            }
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    return last;
}
