//
// Created by new on 4/28/26.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
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

Node* build_tree_in_pre(int l_in, int r_in, int l_pre, int r_pre,
    vector<string>& inorder, vector<string>& preorder, unordered_map<string, int>& inorder_m)
{
    if (l_in > r_in || l_pre > r_pre) {
        return nullptr;
    }
    const string node_val = preorder[l_pre];
    Node* node = new Node(node_val);
    int idx_node = inorder_m[node_val];
    int left_size = idx_node - l_in;
    node->left = build_tree_in_pre(
        l_in, l_in+left_size-1, l_pre+1, l_pre+1+left_size-1,
        inorder, preorder, inorder_m);
    node->right = build_tree_in_pre(
        idx_node+1, r_in, l_pre+1+left_size, r_pre,
        inorder, preorder, inorder_m);

    return node;
}

Node* buildTreeInPre(vector<string> inorder, vector<string> preorder) {
    unordered_map<string, int> inorder_m{};
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
        inorder_m[inorder[i]] = i;
    }
    return build_tree_in_pre(0, n-1, 0, n-1,
        inorder, preorder, inorder_m);
}

