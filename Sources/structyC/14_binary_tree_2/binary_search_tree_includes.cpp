//
// Created by new on 4/28/26.
//

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

bool binarySearchTreeIncludes(Node* root, int targetVal) {
    Node* node = root;
    while (node != nullptr) {
        if (node-> val == targetVal) {
            return true;
        }
        if (node->val > targetVal) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}
