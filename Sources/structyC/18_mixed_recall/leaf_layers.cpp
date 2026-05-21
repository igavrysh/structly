//
// Created by new on 5/6/26.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace mixed_recall_18 {
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

int dfs(const Node* node, vector<vector<string>>& layers) {
    if (node == nullptr) {
        return -1;
    }
    const int l_size = dfs(node->left, layers);
    const int r_size = dfs(node->right, layers);
    const int maxx = 1 + max(l_size, r_size);
    if (layers.size() == maxx) {
        layers.push_back(vector<string>());
    }
    layers[maxx].push_back(node->val);
    return maxx;
}

vector<vector<string>> leafLayers(Node* root) {
    vector<vector<string>> layers{};
    dfs(root, layers);
    return layers;
}

void test_00() {
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f

    vector<vector<string>> layers = leafLayers(&a); // ->
    // [
    //   ['d', 'e', 'f'],
    //   ['b', 'c'],
    //   ['a']
    // ]
    vector<vector<string>> expected_layers = {
        { "d", "e", "f" },
        { "b", "c" },
        { "a" }
    };
    bool passed = layers == expected_layers;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
}
