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
    string val;
    Node* left;
    Node* right;

    Node(string initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};


Node* buildTreeInPost(vector<string> inorder, vector<string> postorder) {
    if (inorder.size() == 0) {
        return nullptr;
    }

    string val = postorder[postorder.size()-1];
    Node* node = new Node(val);
    auto p = find(inorder.begin(), inorder.end(), val);
    int size_left = p - inorder.begin();
    vector<string> left_in(inorder.begin(), p);
    vector<string> right_in(p+1, inorder.end());
    vector<string> left_post(postorder.begin(), postorder.begin()+size_left);
    vector<string> right_post(postorder.begin()+size_left, postorder.end()-1);
    node->left = buildTreeInPost(left_in, left_post);
    node->right = buildTreeInPost(right_in, right_post);

    return node;
}

Node* build_tree_in_post(int l_in, int r_in, int l_post, int r_post,
    vector<string>& inorder, vector<string>& postorder, unordered_map<string, int>& inorder_m)
{
    if (l_in > r_in || l_post > r_post) {
        return nullptr;
    }
    string node_val = postorder[r_post];
    Node* node = new Node(node_val);
    int idx_node = inorder_m[node_val];
    int left_size = idx_node - l_in;
    int right_size = r_in - idx_node;
    node->left = build_tree_in_post(
        l_in, l_in+left_size-1, l_post, l_post+left_size-1,
        inorder, postorder, inorder_m);
    node->right = build_tree_in_post(
        idx_node+1, r_in, l_post+left_size, r_post-1,
        inorder, postorder, inorder_m);

    return node;
}

Node* buildTreeInPost_o_n_time_space(vector<string> inorder, vector<string> postorder) {
    unordered_map<string, int> inorder_m{};
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
        inorder_m[inorder[i]] = i;
    }
    return build_tree_in_post(0, n-1, 0, n-1,
        inorder, postorder, inorder_m);
}

void test_00() {
    Node* res = buildTreeInPost(
      std::vector<std::string> { "y", "x", "z" },
      std::vector<std::string> { "y", "z", "x" }
    );
    cout << "test_00: " << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
