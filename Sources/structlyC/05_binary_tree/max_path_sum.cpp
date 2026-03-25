#include <algorithm>
#include <limits>
#include <iostream>

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
    if (node->left == nullptr && node->right == nullptr) {
        std::cout << ";node:"<<node->val<<" is a leaf, returning:"<<node->val<<std::endl;
        return node->val;
    }

    int res = std::numeric_limits<int>::min();
    if (node->left != nullptr) {
        res = std::max(res, maxPathSum(node->left));
        std::cout<< ";from left path:" << res;
    }
    
    if (node->right != nullptr) {
        res = std::max(res, maxPathSum(node->right));
        std::cout<< ";from right path:" << res;
    }

    std::cout << ";node:"<<node->val<<" res:" << res<<" val:" <<node->val << ";returning:" << node->val + res <<std::endl;

    return node->val + res;
}

void run() {
    Node a(-1);
    Node b(-6);
    Node c(-5);
    Node d(-3);
    Node e(0);
    Node f(-13);
    Node g(-1);
    Node h(-2);
    
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    f.right = &h;
    int res = maxPathSum(&a);
    std::cout<< "res:" << res;
}

int main(int argc, char const *argv[]) {
    run();
    return 0;
}
