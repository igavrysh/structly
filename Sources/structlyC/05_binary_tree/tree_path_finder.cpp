//
//  tree_path_finder.cpp
//  MyCLI
//
//  Created by new on 3/26/26.
//

#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

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

vector<string>* pathFinder(Node* root, string targetVal) {
    if (root == nullptr) {
        return nullptr;
    }

    queue<tuple<Node*, vector<string>*>> q{};
    vector<string>* root_acc = new vector<string>();
    root_acc->push_back(root->val);
    q.push(tuple<Node*, vector<string>*>(root, root_acc));

    vector<string>* res = nullptr;
    while (!q.empty()) {
        tuple<Node*, vector<string>*> ctuple = q.front();
        q.pop();
        Node* node = get<0>(ctuple);
        vector<string>* node_acc = get<1>(ctuple);

        if (node->val == targetVal && res == nullptr) {
            res = get<1>(ctuple);
            continue;
        }

        if (res != nullptr || (node->left == nullptr && node->right == nullptr)) {
            delete node_acc;
            continue;
        }

        if (node->left != nullptr) {
            vector<string>* new_node_acc = new vector<string>(*node_acc);
            new_node_acc->push_back(node->left->val);
            q.push(tuple<Node*, vector<string>*>(node->left, new_node_acc));
        }

        if (node->right != nullptr) {
            vector<string>* new_node_acc = new vector<string>(*node_acc);
            new_node_acc->push_back(node->right->val);
            q.push(tuple<Node*, vector<string>*>(node->right, new_node_acc));
        }
    }

    return res;
}

bool path_finder(Node* node, std::vector<std::string> *acc, std::string targetVal);

std::vector<std::string>* pathFinder(Node* root, std::string targetVal) {
    std::vector<std::string> *acc = new std::vector<std::string>();
    if (!path_finder(root, acc, targetVal)) {
        return nullptr;
    }
    std::reverse(acc->begin(), acc->end());
    return acc;
}

bool path_finder(Node* node, std::vector<std::string> *acc, std::string targetVal) {
    if (node == nullptr) {
        return false;
    }

    if (node->val == targetVal) {
        acc->push_back(node->val);
        return true;
    }

    bool res = path_finder(node->left, acc, targetVal);
    if (res == true) {
        acc->push_back(node->val);
        return true;
    }

    res = path_finder(node->right, acc, targetVal);
    if (res == true) {
        acc->push_back(node->val);
        return true;
    }

    return false;
}

void tree_path_finder_test_00() {
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

    vector<string>* res = pathFinder(&a, "e"); // -> [ "a", "b", "e" ]
    int t = 1;
}

void tree_path_finder_test_07() {
    Node* root = new Node("0");
    Node* curr = root;
    for (int i = 1; i <= 20000; i += 1) {
        curr->right = new Node(std::to_string(i));
        curr = curr->right;
    }

    //      0
    //       \
    //        1
    //         \
    //          2
    //           .
    //            .
    //             .
    //            19999
    //              \
    //              20000

    vector<string>* res = pathFinder(root, "19000"); // -> [0, 1, 2, ..., 18999, 19000]
    int t = 1;
}

// int main(int argc, char const *argv[]) {
//    tree_path_finder_test_07();
   
//    return 0;
// }

