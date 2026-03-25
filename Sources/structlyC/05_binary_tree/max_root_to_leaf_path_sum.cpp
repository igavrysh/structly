//
//  max_root_to_leaf_path_sum.h
//  MyCLI
//
//  Created by new on 3/25/26.
//

#include <algorithm>
#include <limits>

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

int maxPathSum(Node* node) {
    if (node == nullptr) {
        return -std::numeric_limits<int>::infinity();
    }
    return std::max(node->val + maxPathSum(node->left),
                    node->val + maxPathSum(node->right));
}
