//
// Created by new on 4/28/26.
//

#include <vector>
#include <string>
#include <queue>
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

void dfs(int level, Node* node, vector<string>& res) {
    if (node == nullptr) {
        return;
    }
    if (res.size() == level) {
        res.push_back(node->val);
    }
    dfs(level+1, node->left, res);
    dfs(level+1, node->right, res);
}

vector<string> leftyNodes(Node* root) {
    vector<string> res{};
    dfs(0, root, res);
    return res;
}

vector<string> leftyNodes_bfs(Node* root) {
    queue<Node*> q;
    vector<string> res{};
    if (root != nullptr) {
        q.push(root);
    }
    while (!q.empty()) {
        int lvl = q.size();
        res.push_back(q.front()->val);
        for (int i = 0; i < lvl; i++) {
            Node* node = q.front();
            q.pop();
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
    return res;
}
