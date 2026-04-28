//
// Created by new on 4/27/26.
//

#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

Node* add_lists(Node* h1, Node* h2, int carry) {
    if (h1 == nullptr && h2 == nullptr && carry == 0) {
        return nullptr;
    }

    int val = carry;
    if (h1 != nullptr) {
        val += h1->val;
        h1 = h1-> next;
    }
    if (h2 != nullptr) {
        val += h2->val;
        h2 = h2->next;
    }

    Node* node = new Node(val % 10);
    node->next = add_lists(h1, h2, val / 10);
    return node;
}

Node *addLists(Node *head1, Node *head2) {
    return add_lists(head1, head2, 0);
}

Node *addLists_iter(Node *head1, Node *head2) {
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    int carry = 0;
    while (head1 != nullptr || head2 != nullptr || carry != 0) {
        int val = carry;
        if (head1 != nullptr) {
            val += head1->val;
            head1 = head1->next;
        }
        if (head2 != nullptr) {
            val += head2->val;
            head2 = head2->next;
        }
        prev->next = new Node(val % 10);
        prev = prev->next;
        carry = val / 10;
    }

    return dummy->next;
}