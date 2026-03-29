#include <algorithm>
#include <limits>
#include <iostream>
#include <queue>
#include <tuple>

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

int max_path_sum_i(Node* node);
int max_path_sum_r(Node* root);

int maxPathSum(Node* node) {
    return max_path_sum_i(node);
}

int max_path_sum_i(Node* node) {
    if (node == nullptr) {
        return std::numeric_limits<int>::min();
    }

    if (node->left == nullptr && node->right == nullptr) {
        return node->val;
    }

    int res = std::numeric_limits<int>::min();
    res = std::max(res, max_path_sum_i(node->left));
    res = std::max(res, max_path_sum_i(node->right));

    return node->val + res;
}

int max_path_sum_r(Node* root) {
    std::queue<std::tuple<Node*,int>> q;
    if (root != nullptr) {
        q.push(std::tuple<Node*,int>(root, root->val));
    }
    int res = std::numeric_limits<int>::min();
    while (!q.empty()) {
        auto curr_tuple = q.front();
        q.pop();
        Node* node = std::get<0>(curr_tuple);
        int acc = std::get<1>(curr_tuple);
        if (node->left == nullptr && node->right == nullptr) {
            res = std::max(res, acc);
            continue;
        }

        if (node->left != nullptr) {
            q.push(std::tuple<Node *, int>(node->left, acc+node->left->val));
        }

        if (node->right != nullptr) {
            q.push(std::tuple<Node *, int>(node->right, acc+node->right->val));
        }
    }

    return res;
}

void max_path_sum_test_00() {
    Node a(3);
    Node b(11);
    Node c(4);
    Node d(4);
    Node e(-2);
    Node f(1);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    //       3
    //    /    \
    //   11     4
    //  / \      \
    // 4   -2     1

    int res = maxPathSum(&a); // -> 18
    std::cout<<"res: "<<res<<std::endl;
}

void max_path_sum_test_02() {
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

    //        -1
    //      /   \
    //    -6    -5
    //   /  \     \
    // -3   0    -13
    //     /       \
    //    -1       -2

    int res = maxPathSum(&a);
    std::cout<< "res:" << res;
}

//int main(int argc, char const *argv[]) {
//    max_path_sum_test_00();
//    return 0;
//}

