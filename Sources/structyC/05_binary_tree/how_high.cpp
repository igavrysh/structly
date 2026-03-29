//
//  how_high.cpp
//  MyCLI
//
//  Created by new on 3/27/26.
//

#include <string>

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

// number of edges
int howHigh(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    }

    return 1 + std::max(howHigh(root->left), howHigh(root->right));
}

