//
//  breadth_first_values.cpp
//  MyCLI
//
//  Created by new on 3/23/26.
//

#include <string>
#include <vector>
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

void breadth_first_level(std::queue<Node*> lvl, std::vector<std::string> &cache) {
    std::queue<Node*> nxt_lvl;
    while (lvl.size() > 0) {
        Node* node = lvl.front();
        lvl.pop();
        cache.push_back(node->val);
        if (node->left != nullptr) {
            nxt_lvl.push(node->left);
        }
        if (node->right != nullptr) {
            nxt_lvl.push(node->right);
        }
    }
}

std::vector<std::string> breadthFirstValues(Node* root) {
    std::vector<std::string> cache;
    std::queue<Node*> q;
    if (root != nullptr) {
        q.push(root);
    }
    breadth_first_level(q, cache);

    return cache;
}

std::vector<std::string> breadthFirstValues1(Node* root) {
    std::vector<std::string> acc{};
    std::queue<Node*> q{};
    if (root != nullptr) {
        q.push(root);
    }
    while (q.size() > 0) {
        Node* node = q.front();
        q.pop();
        acc.push_back(node->val);
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    return acc;
}
