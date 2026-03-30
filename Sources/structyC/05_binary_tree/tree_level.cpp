//
//  tree_level.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
//

#include <vector>
#include <string>
#include <queue>
#include <tuple>

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

std::vector<std::vector<std::string>> treeLevels1(Node* root) {
    std::vector<std::vector<std::string>> res;
    std::queue<Node*> q;
    if (root != nullptr) {
        q.push(root);
    }
    while (q.size() > 0) {
        auto lvl = q.size();
        std::vector<std::string> current;
        for (int i = 0; i < lvl; i++) {
            Node* node = q.front();
            q.pop();
            current.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        res.push_back(current);
    }

    return res;
}

std::vector<std::vector<std::string>> treeLevels(Node* root) {
    std::vector<std::vector<std::string>> res;
    std::queue<std::tuple<Node*, int>> q;
    if (root != nullptr) {
        q.push(std::tuple<Node*, int>{root, 0});
    }

    while (q.size() > 0) {
        std::vector<std::string> current;
        auto [node, level] = q.front();
        q.pop();
        if (level == res.size()) {
            res.push_back(std::vector<std::string>{node->val});
        } else {
            res[level].push_back(node->val);
        }
        if (node->left != nullptr) {
            q.push(std::tuple<Node*, int>{node->left, level + 1});
        }
        if (node->right != nullptr) {
            q.push(std::tuple<Node*, int>(node->right, level + 1));
        }
    }

    return res;
}
