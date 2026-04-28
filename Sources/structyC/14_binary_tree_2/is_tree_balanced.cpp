//
// Created by new on 4/28/26.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    std::string val;
    Node* left;
    Node* right;

    Node(string initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

int dfs(Node* node, vector<bool>& res) {
    if (node == nullptr) {
        return -1;
    }

    int left = dfs(node->left, res);
    if (!res.empty()) {
        return -1;
    }
    int right = dfs(node->right, res);
    if (!res.empty()) {
        return -1;
    }

    if (abs(left-right) > 1) {
        res.push_back(false);
    }

    return max(left, right) + 1;
}

bool isTreeBalanced(Node* root) {
    vector<bool> res{};
    dfs(root, res);
    return res.empty();
}