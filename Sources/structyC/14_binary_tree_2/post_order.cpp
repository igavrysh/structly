//
// Created by new on 4/28/26.
//

#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string val;
    Node* left;
    Node* right;

    Node(string initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

void dfs(Node* node, vector<string>& res) {
    if (node == nullptr) {
        return;
    }
    dfs(node->left, res);
    dfs(node->right, res);
    res.push_back(node->val);
}

vector<string> postOrder(Node* root) {
    vector<string> res;
    dfs(root, res);
    return res;
}
